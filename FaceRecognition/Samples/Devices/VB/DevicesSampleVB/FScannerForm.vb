Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.Text
Imports Neurotec.Biometrics
Imports Neurotec.Devices
Imports Neurotec.Images
Imports Neurotec

Partial Public Class FScannerForm
	Inherits BiometricDeviceForm
#Region "Private fields"

	Private _impressionType As NFImpressionType
	Private _position As NFPosition
	Private _missingPositions() As NFPosition

#End Region

#Region "Public constructor"

	Public Sub New()
		InitializeComponent()
		OnDeviceChanged()
	End Sub

#End Region

#Region "Private methods"

	Private Overloads Function OnImage(ByVal image As NImage, ByVal status As NBiometricStatus, ByVal objects As IList(Of NFAttributes), ByVal isFinal As Boolean) As Boolean
		Dim sb As New StringBuilder()
		sb.Append(status)
		For Each obj As NFAttributes In objects
			sb.AppendLine()
			sb.AppendFormat(Constants.vbTab & "{0}: {1}", obj.Position, obj.Status)
		Next obj
		Return OnImage(image, sb.ToString(), (IIf(status <> NBiometricStatus.None, status, NBiometricStatus.Ok)).ToString(), isFinal)
	End Function

#End Region

#Region "Protected methods"

	Protected Overrides Function IsValidDeviceType(ByVal value As Type) As Boolean
		Return MyBase.IsValidDeviceType(value) AndAlso GetType(NFScanner).IsAssignableFrom(value)
	End Function

	Protected Overrides Sub OnCapture()
		Dim fScanner As NFScanner = CType(Device, NFScanner)
		AddHandler fScanner.Preview, AddressOf Device_Preview
		Try
			Dim status As NBiometricStatus
			Dim attributes() As NFAttributes = Nothing
			Using image As NImage = (CType(Device, NFScanner)).Capture(_impressionType, _position, _missingPositions, Automatic, Timeout, status, attributes)
				OnImage(image, status, attributes, True)
			End Using
		Finally
			RemoveHandler fScanner.Preview, AddressOf Device_Preview
		End Try
	End Sub

	Protected Overrides Sub OnWriteScanParameters(ByVal writer As System.Xml.XmlWriter)
		MyBase.OnWriteScanParameters(writer)
		WriteParameter(writer, "ImpressionType", ImpressionType)
		WriteParameter(writer, "Position", Position)
		If MissingPositions IsNot Nothing Then
			For Each position As NFPosition In MissingPositions
				WriteParameter(writer, "Missing", position)
			Next position
		End If
	End Sub

#End Region

#Region "Public properties"

	Public Property ImpressionType() As NFImpressionType
		Get
			Return _impressionType
		End Get
		Set(ByVal value As NFImpressionType)
			If _impressionType <> value Then
				CheckIsBusy()
				_impressionType = value
			End If
		End Set
	End Property

	Public Property Position() As NFPosition
		Get
			Return _position
		End Get
		Set(ByVal value As NFPosition)
			If _position <> value Then
				CheckIsBusy()
				_position = value
			End If
		End Set
	End Property

	Public Property MissingPositions() As NFPosition()
		Get
			Return _missingPositions
		End Get
		Set(ByVal value As NFPosition())
			If _missingPositions IsNot value Then
				CheckIsBusy()
				_missingPositions = value
			End If
		End Set
	End Property

#End Region

#Region "Private form events"

	Private Sub Device_Preview(ByVal sender As Object, ByVal e As NFScannerPreviewEventArgs)
		Dim force As Boolean = OnImage(e.Image, e.Status, e.Objects, False)
		If (Not Automatic) Then
			e.Status = CType(IIf(force, NBiometricStatus.Ok, NBiometricStatus.BadObject), NBiometricStatus)
		End If
	End Sub

#End Region
End Class
