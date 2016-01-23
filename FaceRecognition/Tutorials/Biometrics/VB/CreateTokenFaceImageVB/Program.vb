Imports Microsoft.VisualBasic
Imports System
Imports System.Drawing

Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.Biometrics.Tools
Imports Neurotec.Licensing

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [FaceImage] [CreateTokenFaceImage]", Utils.GetAssemblyName())
		Console.WriteLine()
		Console.WriteLine(vbTab & "[FaceImage] - an image containing frontal face.")
		Console.WriteLine(vbTab & "[CreateTokenFaceImage] - filename of created token face image.")
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Biometrics.FaceDetection,Biometrics.FaceSegmentation,Biometrics.FaceQualityAssessment"

		Utils.PrintTutorialHeader(args)

		If args.Length < 2 Then
			Return Usage()
		End If

		Try
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine("Could not obtain licenses for components: {0}", Components)
				Return -1
			End If

			Dim image As NImage = NImage.FromFile(args(0))
			Dim extractor As New NLExtractor()
			Dim grayscale As NGrayscaleImage = image.ToGrayscale()
			Dim face As NleFace
			Dim detected As Boolean = extractor.DetectFace(grayscale, face)
			If (Not detected) Then
				Console.WriteLine("could not create token image, no face detected.")
				Return -1
			End If

			Dim details As NleDetectionDetails = extractor.DetectFacialFeatures(grayscale, face)
			Using ntfi As New Ntfi()
				Using token As NImage = ntfi.CreateTokenFaceImage(image, New Point(details.RightEyeCenter.X, details.RightEyeCenter.Y), New Point(details.LeftEyeCenter.X, details.LeftEyeCenter.Y))
					token.Save(args(1))
					Console.WriteLine("token face image successfully saved to ""{0}"".", args(1))

					Dim ntfiAttributes As NtfiAttributes = Nothing
					Dim quality As Double = ntfi.TestTokenFaceImage(token, ntfiAttributes)
					Console.WriteLine("global token face image quality score = {0:f3}. Tested attributes details:", quality)
					Console.WriteLine(vbTab & "sharpness score = {0:f3}", ntfiAttributes.Sharpness)
					Console.WriteLine(vbTab & "background uniformity score = {0:f3}", ntfiAttributes.BackgroundUniformity)
					Console.WriteLine(vbTab & "grayscale density score = {0:f3}", ntfiAttributes.GrayscaleDensity)
				End Using
			End Using

			image.Dispose()
			extractor.Dispose()
			grayscale.Dispose()

			Return 0
		Catch ex As Exception
			Console.WriteLine(ex)
			Dim neurotecException As INeurotecException = TryCast(ex, INeurotecException)
			If neurotecException IsNot Nothing Then
				Return neurotecException.Code
			End If
			Return -1
		Finally
			NLicense.ReleaseComponents(Components)
		End Try
	End Function
End Class
