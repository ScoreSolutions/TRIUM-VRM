Imports Microsoft.VisualBasic
Imports System
Imports System.Windows.Forms
Imports Neurotec.Biometrics
Imports Neurotec.Samples.Code

Namespace Forms
	Partial Public Class WatchListForm
		Inherits Form
		Public Sub New()
			InitializeComponent()
		End Sub

#Region "Public properties"

		Public Property FaceRecords() As FaceRecordCollection
			Get
				Return CType(bindingSource.DataSource, FaceRecordCollection)
			End Get
			Set(ByVal value As FaceRecordCollection)
				bindingSource.DataSource = value
			End Set
		End Property

#End Region

#Region "Private methods"

		Private Sub bindingSource_CurrentChanged(ByVal sender As Object, ByVal e As EventArgs) Handles bindingSource.CurrentChanged
			If bindingSource.Current Is Nothing Then
				MainForm.ReplaceImage(nlView, Nothing)
				tslTemplateId.Text = String.Empty
			Else
				Dim faceRecord As FaceRecord = CType(bindingSource.Current, FaceRecord)
				MainForm.ReplaceImage(nlView, FaceRecords.GetImageById(faceRecord.Id))
				nlView.DetectionDetails = New NleDetectionDetails() {faceRecord.Details}
				tslTemplateId.Text = faceRecord.FaceId
			End If
		End Sub

#End Region
	End Class
End Namespace
