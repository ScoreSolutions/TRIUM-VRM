Imports System
Imports System.Collections.Generic
Imports System.Windows.Forms
Imports System.Drawing

Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.IO

Partial Public Class MainForm
	Inherits Form
	Private _extractor As NLExtractor
	Private _matcher As NMatcher
	Private _referenceTemplate As NBuffer
	Private _multipleTemplates() As NBuffer

	Public Sub New()
		InitializeComponent()
	End Sub

	Private Function ExtractMultipleFaces(ByVal image As NImage, <System.Runtime.InteropServices.Out()> ByRef multipleDetectionDetails() As NleDetectionDetails) As NLTemplate()
		multipleDetectionDetails = Nothing
		Try
			' convert image to grayscale
			Using grayscale As NGrayscaleImage = image.ToGrayscale()
				Dim faces() As NleFace = _extractor.DetectFaces(grayscale)

				Dim templates As New List(Of NLTemplate)()
				Dim detectionDetailList As New List(Of NleDetectionDetails)()
				For i As Integer = 0 To faces.Length - 1
					Dim face As NleFace = faces(i)
					Dim detectionDetails As NleDetectionDetails = _extractor.DetectFacialFeatures(grayscale, face)
					Dim extractionStatus As NleExtractionStatus
					Dim template As NLTemplate = _extractor.ExtractUsingDetails(grayscale, detectionDetails, extractionStatus)
					If extractionStatus = NleExtractionStatus.TemplateCreated Then
						templates.Add(template)
						detectionDetailList.Add(detectionDetails)
					End If
				Next i

				If templates.Count > 0 Then
					multipleDetectionDetails = detectionDetailList.ToArray()
					Return templates.ToArray()
				End If
				Return Nothing
			End Using
		Catch
			Return Nothing
		End Try
	End Function

	Private Sub MatchMultipleFaces()
		Dim results(_multipleTemplates.Length - 1) As String
		_matcher.IdentifyStart(_referenceTemplate)
		Try
			For i As Integer = 0 To _multipleTemplates.Length - 1
				Dim score As Integer = _matcher.IdentifyNext(_multipleTemplates(i))
				If score > 0 Then
					results(i) = String.Format("score: {0} (match)", score)
				Else
					results(i) = String.Format("score: {0}", score)
				End If
			Next i
		Finally
			_matcher.IdentifyEnd()
		End Try

		nlViewMultiFace.FaceIds = results
	End Sub

	Private Sub TsbOpenReferenceClick(ByVal sender As Object, ByVal e As EventArgs) Handles tsbOpenReference.Click
		openImageFileDlg.Filter = NImages.GetOpenFileFilterString(True, True)
		openImageFileDlg.Title = "Open Reference Image"
		If openImageFileDlg.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
			Dim image As NImage
			Try
				image = NImage.FromFile(openImageFileDlg.FileName)
			Catch ex As Exception
				MessageBox.Show(String.Format("Failed to load image file {0}: {1}", openImageFileDlg.FileName, ex))
				Return
			End Try

			Try
				Dim detectionDetails() As NleDetectionDetails = Nothing
				' Set template size (for matching medium is recommended) (optional)
				_extractor.TemplateSize = NleTemplateSize.Medium
				Dim templates() As NLTemplate = ExtractMultipleFaces(image, detectionDetails)
				If templates IsNot Nothing Then
					_referenceTemplate = templates(0).Save()
					Dim oldImage As Bitmap = nlViewReference.Image
					nlViewReference.Image = image.ToBitmap()
					If oldImage IsNot Nothing Then
						oldImage.Dispose()
					End If
					nlViewReference.DetectionDetails = New Object() {detectionDetails(0)}

					If _referenceTemplate IsNot Nothing AndAlso _multipleTemplates IsNot Nothing Then
						MatchMultipleFaces()
					End If
				Else
					MessageBox.Show("Could not extract template from reference image.")
				End If
			Catch ex As Exception
				MessageBox.Show(String.Format("An unexpected error has occured: {0}", ex))
			End Try
		End If
	End Sub

	Private Sub TsbOpenMultifaceImageClick(ByVal sender As Object, ByVal e As EventArgs) Handles tsbOpenMultifaceImage.Click
		openImageFileDlg.Filter = NImages.GetOpenFileFilterString(True, True)
		openImageFileDlg.Title = "Open Reference Image"
		If openImageFileDlg.ShowDialog() <> System.Windows.Forms.DialogResult.OK Then
			Return
		End If
		Dim image As NImage
		Try
			image = NImage.FromFile(openImageFileDlg.FileName)
		Catch ex As Exception
			MessageBox.Show(String.Format("Failed to load image file {0}: {1}", openImageFileDlg.FileName, ex))
			Return
		End Try

		Try
			Dim detectionDetails() As NleDetectionDetails = Nothing
			' Set template size (for enrolling large is recomended) (optional)
			_extractor.TemplateSize = NleTemplateSize.Large
			Dim templates() As NLTemplate = ExtractMultipleFaces(image, detectionDetails)
			If templates IsNot Nothing Then
				_multipleTemplates = New NBuffer(templates.Length - 1) {}
				For i As Integer = 0 To templates.Length - 1
					_multipleTemplates(i) = templates(i).Save()
				Next i
				Dim oldImage As Bitmap = nlViewMultiFace.Image
				nlViewMultiFace.Image = image.ToBitmap()
				If oldImage IsNot Nothing Then
					oldImage.Dispose()
				End If
				nlViewMultiFace.DetectionDetails = detectionDetails

				If _referenceTemplate IsNot Nothing Then
					MatchMultipleFaces()
				End If
			Else
				MessageBox.Show("Could not extract template from reference image.")
			End If
		Catch ex As Exception
			MessageBox.Show(String.Format("An unexpected error has occured: {0}", ex))
		End Try
	End Sub

	Private Sub MainFormLoad(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Load
		Try
			_extractor = New NLExtractor()
			_matcher = New NMatcher()
		Catch ex As Exception
			MessageBox.Show(String.Format("An unexpected error has occured: {0}", ex))
		End Try
	End Sub

	Private Sub MainFormFormClosed(ByVal sender As Object, ByVal e As FormClosedEventArgs) Handles MyBase.FormClosed
		If _extractor IsNot Nothing Then
			_extractor.Dispose()
			_extractor = Nothing
		End If
		If _matcher IsNot Nothing Then
			_matcher.Dispose()
			_matcher = Nothing
		End If
	End Sub
End Class
