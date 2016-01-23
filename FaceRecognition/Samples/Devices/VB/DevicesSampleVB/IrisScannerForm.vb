Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.Text
Imports Neurotec.Biometrics
Imports Neurotec.Devices
Imports Neurotec.Images

Partial Public Class IrisScannerForm
	Inherits BiometricDeviceForm
#Region "Private fields"

	Private _position As NEPosition
	Private _missingPositions() As NEPosition

#End Region

#Region "Public constructor"

	Public Sub New()
		InitializeComponent()
		OnDeviceChanged()
	End Sub

#End Region

#Region "Private methods"

	Private Overloads Function OnImage(ByVal image As NImage, ByVal status As NBiometricStatus, ByVal objects As IList(Of NEAttributes), ByVal isFinal As Boolean) As Boolean
		Dim sb As New StringBuilder()
		sb.Append(status)
		For Each obj As NEAttributes In objects
			sb.AppendLine()
			sb.AppendFormat(Constants.vbTab & "{0}: {1} (Position: {2})", obj.Position, obj.Status, obj.BoundingRect)
		Next obj
		Return OnImage(image, sb.ToString(), (IIf(status <> NBiometricStatus.None, status, NBiometricStatus.Ok)).ToString(), isFinal)
	End Function

#End Region

#Region "Protected methods"

	Protected Overrides Function IsValidDeviceType(ByVal value As Type) As Boolean
		Return MyBase.IsValidDeviceType(value) AndAlso GetType(NIrisScanner).IsAssignableFrom(value)
	End Function

	Protected Overrides Sub OnCapture()
		Dim irisScanner As NIrisScanner = CType(Device, NIrisScanner)
		AddHandler irisScanner.Preview, AddressOf Device_Preview
		Try
			Dim status As NBiometricStatus
			Dim attributes() As NEAttributes = Nothing
			Using image As NImage = (CType(Device, NIrisScanner)).Capture(_position, _missingPositions, Automatic, Timeout, status, attributes)
				OnImage(image, status, attributes, True)
			End Using
		Finally
			RemoveHandler irisScanner.Preview, AddressOf Device_Preview
		End Try
	End Sub

	Protected Overrides Sub OnWriteScanParameters(ByVal writer As System.Xml.XmlWriter)
		MyBase.OnWriteScanParameters(writer)
		WriteParameter(writer, "Position", Position)
		If MissingPositions IsNot Nothing Then
			For Each position As NEPosition In MissingPositions
				WriteParameter(writer, "Missing", position)
			Next position
		End If
	End Sub

#End Region

#Region "Public properties"

	Public Property Position() As NEPosition
		Get
			Return _position
		End Get
		Set(ByVal value As NEPosition)
			If _position <> value Then
				CheckIsBusy()
				_position = value
			End If
		End Set
	End Property

	Public Property MissingPositions() As NEPosition()
		Get
			Return _missingPositions
		End Get
		Set(ByVal value As NEPosition())
			If _missingPositions IsNot value Then
				CheckIsBusy()
				_missingPositions = value
			End If
		End Set
	End Property

#End Region

#Region "Private form events"

	Private Sub Device_Preview(ByVal sender As Object, ByVal e As NIrisScannerPreviewEventArgs)
		Dim force As Boolean = OnImage(e.Image, e.Status, e.Objects, False)
		If (Not Automatic) Then
			e.Status = CType(IIf(force, NBiometricStatus.Ok, NBiometricStatus.BadObject), NBiometricStatus)
		End If
	End Sub

#End Region
End Class
