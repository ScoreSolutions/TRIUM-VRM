Imports System

Imports Neurotec.Biometrics
Imports Neurotec.Images

Namespace Code
	Public Class SubjectInfo
		Implements IDisposable
#Region "Private fields"

		Private _index As Integer
		Private _image As NImage
		Private _detectionDetails As NleDetectionDetails
		Private _template As NLTemplate
		Private _sourceIndex As Integer

#End Region

#Region "Public properties"

		Public Property Index() As Integer
			Get
				Return _index
			End Get
			Set(ByVal value As Integer)
				_index = value
			End Set
		End Property

		Public Property Image() As NImage
			Get
				Return _image
			End Get
			Set(ByVal value As NImage)
				_image = value
			End Set
		End Property

		Public Property DetectionDetails() As NleDetectionDetails
			Get
				Return _detectionDetails
			End Get
			Set(ByVal value As NleDetectionDetails)
				_detectionDetails = value
			End Set
		End Property

		Public Property Template() As NLTemplate
			Get
				Return _template
			End Get
			Set(ByVal value As NLTemplate)
				_template = value
			End Set
		End Property

		Public Property SourceIndex() As Integer
			Get
				Return _sourceIndex
			End Get
			Set(ByVal value As Integer)
				_sourceIndex = value
			End Set
		End Property
#End Region

#Region "Public constructor"

		Public Sub New(ByVal index As Integer, ByVal sourceIndex As Integer)
			Me._index = index
			Me._image = Nothing
			Me._template = Nothing
			Me._sourceIndex = sourceIndex
		End Sub

#End Region

#Region "IDisposable Members"

		Public Sub Dispose() Implements IDisposable.Dispose
			If _image IsNot Nothing Then
				_image.Dispose()
				_image = Nothing
			End If
			If _template IsNot Nothing Then
				_template.Dispose()
				_template = Nothing
			End If
		End Sub

#End Region
	End Class
End Namespace
