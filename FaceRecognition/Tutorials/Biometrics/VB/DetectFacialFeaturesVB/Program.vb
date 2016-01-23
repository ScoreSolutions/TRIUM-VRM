Imports Microsoft.VisualBasic
Imports System
Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.Licensing

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [image]", Utils.GetAssemblyName())
		Console.WriteLine()
		Console.WriteLine(vbTab & "[image] - filename of image.")
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Biometrics.FaceDetection,Biometrics.FaceExtraction"

		Utils.PrintTutorialHeader(args)

		If args.Length < 1 Then
			Return Usage()
		End If

		Try
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine("Could not obtain licenses for components: {0}", Components)
				Return -1
			End If

			Dim grayscale As NGrayscaleImage
			Using image As NImage = NImage.FromFile(args(0))
				grayscale = image.ToGrayscale()
			End Using

			Using extractor As NLExtractor = New NLExtractor()
				extractor.DetectAllFeaturePoints = True
				extractor.DetectBaseFeaturePoints = True
				extractor.DetectExpression = True
				extractor.DetectBlink = True
				extractor.DetectMouthOpen = True
				extractor.DetectGlasses = True
				extractor.DetectDarkGlasses = True
				extractor.DetectGender = True
				extractor.TemplateSize = NleTemplateSize.Small

				Dim faces As NleFace() = extractor.DetectFaces(grayscale)
				Console.WriteLine("found faces:")
				For Each face As NleFace In faces
					Console.WriteLine(vbTab & "location = ({0}, {1}), width = {2}, height = {3}, confidence = {4}", face.Rectangle.X, face.Rectangle.Y, face.Rectangle.Width, face.Rectangle.Height, face.Confidence)

					Dim features As NleDetectionDetails = extractor.DetectFacialFeatures(grayscale, face)
					PrintNleFeaturePoint("LeftEyeCenter", features.LeftEyeCenter)
					PrintNleFeaturePoint("RightEyeCenter", features.RightEyeCenter)
					PrintNleFeaturePoint("MouthCenter", features.MouthCenter)
					PrintNleFeaturePoint("NoseTip", features.NoseTip)

					Console.WriteLine()
					For Each featurePoint As NLFeaturePoint In features.Points
						PrintBaseFeaturePoint(featurePoint)
					Next featurePoint

					Dim status As NleExtractionStatus
					' gender, expression and other properties only detected during extraction
					Dim template As NLTemplate = extractor.ExtractUsingDetails(grayscale, features, status)
					If template IsNot Nothing Then
						template.Dispose()
					End If
					Console.WriteLine()
					Console.WriteLine(Constants.vbTab + Constants.vbTab & "Extraction status: {0}", status)
					If features.GenderConfidence = 255 Then
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Gender not detected")
					Else
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Gender: {0}, Confidence: {1}", features.Gender, features.GenderConfidence)
					End If
					If features.ExpressionConfidence = 255 Then
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Expression not detected")
					Else
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Expression: {0}, Confidence: {1}", features.Expression, features.ExpressionConfidence)
					End If
					If features.BlinkConfidence = 255 Then
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Blink not detected")
					Else
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Blink: {0}, Confidence: {1}", (features.Properties And NLProperties.Blink) = NLProperties.Blink, features.BlinkConfidence)
					End If
					If features.MouthOpenConfidence = 255 Then
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Mouth open not detected")
					Else
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Mouth open: {0}, Confidence: {1}", (features.Properties And NLProperties.MouthOpen) = NLProperties.MouthOpen, features.MouthOpenConfidence)
					End If
					If features.GlassesConfidence = 255 Then
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Glasses not detected")
					Else
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Glasses: {0}, Confidence: {1}", (features.Properties And NLProperties.Glasses) = NLProperties.Glasses, features.GlassesConfidence)
					End If
					If features.DarkGlassesConfidence = 255 Then
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Dark glasses not detected")
					Else
						Console.WriteLine(Constants.vbTab + Constants.vbTab & "Dark glasses: {0}, Confidence: {1}", (features.Properties And NLProperties.DarkGlasses) = NLProperties.DarkGlasses, features.DarkGlassesConfidence)
					End If
				Next face
			End Using

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

	Private Shared Sub PrintNleFeaturePoint(ByVal name As String, ByVal point As NLFeaturePoint)
		If point.Confidence = 0 Then
			Console.WriteLine(vbTab & vbTab & "{0} feature unavailable. confidence: 0", name)
			Return
		End If
		Console.WriteLine(vbTab & vbTab & "{0} feature found. X: {1}, Y: {2}, confidence: {3}", name, point.X, point.Y, point.Confidence)
	End Sub

	Private Shared Sub PrintBaseFeaturePoint(ByVal point As NLFeaturePoint)
		If point.Confidence = 0 Then
			Console.WriteLine(Constants.vbTab + Constants.vbTab & "Base feature point unavailable. confidence: 0")
			Return
		End If
		Console.WriteLine(Constants.vbTab + Constants.vbTab & "Base feature point found. X: {0}, Y: {1}, confidence: {2}, Code: {3}", point.X, point.Y, point.Confidence, point.Code)
	End Sub

End Class
