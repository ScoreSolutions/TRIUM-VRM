Imports Microsoft.VisualBasic
Imports System
Imports System.IO

Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.Licensing

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [input image] [output template]", Utils.GetAssemblyName())
		Console.WriteLine()
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Biometrics.FaceExtraction"

		Utils.PrintTutorialHeader(args)

		If args.Length < 2 Then
			Return Usage()
		End If

		Dim image As NImage = Nothing
		Dim grayscaleImage As NGrayscaleImage = Nothing
		Dim extractor As NLExtractor = Nothing
		Dim template As NLTemplate = Nothing
		Try
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine("Could not obtain licenses for components: {0}", Components)
				Return -1
			End If

			' Read face image from file.
			image = NImage.FromFile(args(0))

			' Convert image to grayscale
			grayscaleImage = image.ToGrayscale()

			' Create an extractor
			extractor = New NLExtractor()

			' Set extractor template size (recommended, for enroll to database, is large) (optional)
			extractor.TemplateSize = NleTemplateSize.Large

			' Detect all faces features
			extractor.DetectAllFeaturePoints = True

			' Extract a face template from the image
			Dim details As NleDetectionDetails = Nothing
			Dim extractionStatus As NleExtractionStatus
			template = extractor.Extract(grayscaleImage, details, extractionStatus)
			If details.FaceAvailable Then
				Console.WriteLine("found face:")
				Console.WriteLine(vbTab & "location = ({0}, {1}), width = {2}, height = {3}, confidence = {4}", details.Face.Rectangle.X, details.Face.Rectangle.Y, details.Face.Rectangle.Width, details.Face.Rectangle.Height, details.Face.Confidence)
			End If
			If details.RightEyeCenter.Confidence > 0 OrElse details.LeftEyeCenter.Confidence > 0 Then
				Console.WriteLine(vbTab & "found eyes:")
				If details.RightEyeCenter.Confidence > 0 Then
					Console.WriteLine(vbTab + vbTab & "Right: location = ({0}, {1}), confidence = {2}", details.RightEyeCenter.X, details.RightEyeCenter.Y, details.RightEyeCenter.Confidence)
				End If
				If details.LeftEyeCenter.Confidence > 0 Then
					Console.WriteLine(vbTab + vbTab & "Left: location = ({0}, {1}), confidence = {2}", details.LeftEyeCenter.X, details.LeftEyeCenter.Y, details.LeftEyeCenter.Confidence)
				End If
			End If
			If details.NoseTip.Confidence > 0 Then
				Console.WriteLine(vbTab & "found nose:")
				Console.WriteLine(vbTab + vbTab & "location = ({0}, {1}), confidence = {2}", details.NoseTip.X, details.NoseTip.Y, details.NoseTip.Confidence)
			End If
			If details.MouthCenter.Confidence > 0 Then
				Console.WriteLine(vbTab & "found mouth:")
				Console.WriteLine(vbTab + vbTab & "location = ({0}, {1}), confidence = {2}", details.MouthCenter.X, details.MouthCenter.Y, details.MouthCenter.Confidence)
			End If

			If extractionStatus <> NleExtractionStatus.TemplateCreated Then
				Console.WriteLine("face template extraction failed!")
				Return -1
			End If

			' save compressed template to file
			File.WriteAllBytes(args(1), template.Save().ToArray())
			Console.WriteLine("template saved successfully")

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
			If template IsNot Nothing Then
				template.Dispose()
			End If
			If extractor IsNot Nothing Then
				extractor.Dispose()
			End If
			If grayscaleImage IsNot Nothing Then
				grayscaleImage.Dispose()
			End If
			If image IsNot Nothing Then
				image.Dispose()
			End If
		End Try
	End Function
End Class
