Imports System.Drawing
Imports System.Windows.Forms
Imports Neurotec.Biometrics
Imports Neurotec.Samples.Code

Namespace Forms
	Partial Public Class AddToWatchListForm
		Inherits Form
#Region "Public constructor"

		Public Sub New()
			InitializeComponent()
			nlView.FaceRectangleColor = Color.GreenYellow
		End Sub

#End Region

#Region "Public methods"

		Public Overloads Function ShowDialog(ByVal si As SubjectInfo) As DialogResult
			nlView.Image = si.Image.ToBitmap()
			nlView.DetectionDetails = New NleDetectionDetails() {si.DetectionDetails}
			textBoxSubjectId.Text = String.Format("Subject{0:d3}", si.Index)
			Return MyBase.ShowDialog()
		End Function

#End Region

#Region "Public properties"

		Public Property SubjectId() As String
			Get
				Return textBoxSubjectId.Text
			End Get
			Set(ByVal value As String)
				textBoxSubjectId.Text = value
			End Set
		End Property

#End Region
	End Class
End Namespace
