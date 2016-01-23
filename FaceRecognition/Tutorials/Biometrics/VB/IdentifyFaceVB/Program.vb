Imports Microsoft.VisualBasic
Imports System
Imports System.IO

Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.Licensing
Imports Neurotec.IO

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [probe image] [one or more gallery images]", Utils.GetAssemblyName())
		Console.WriteLine()
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Biometrics.FaceExtraction,Biometrics.FaceMatching"

		Utils.PrintTutorialHeader(args)

		If args.Length < 2 Then
			Return Usage()
		End If

		Dim extractor As NLExtractor = Nothing
		Dim matcher As NMatcher = Nothing
		Try
			' obtain license
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine("Could not obtain licenses for components: {0}", Components)
				Return -1
			End If

			' create an extractor
			extractor = New NLExtractor()

			' extract probe template
			Dim probeTemplate As NBuffer
			Try
				probeTemplate = ExtractTemplate(extractor, args(0), False)
			Catch ex As IOException
				Console.WriteLine("error reading candidate image {0}: {1}", args(0), ex)
				Return -1
			End Try

			' extract gallery templates
			Dim galleryTemplates(args.Length - 2) As NBuffer
			For i As Integer = 1 To args.Length - 1
				Try
					galleryTemplates(i - 1) = ExtractTemplate(extractor, args(i), False)
				Catch ex As IOException
					Console.WriteLine("error reading reference image {0}: {1}", args(i), ex)
					Return -1
				End Try
			Next i

			' create a matcher
			matcher = New NMatcher()
			' identify face from the image by comparing to each template from arguments
			Console.WriteLine("=== identification started ===")

			matcher.IdentifyStart(probeTemplate)
			Try
				For i As Integer = 1 To args.Length - 1
					Dim score As Integer = matcher.IdentifyNext(galleryTemplates(i - 1))
					Console.WriteLine("template[{0}] scored {1} {2}", i - 1, score, IIf(score > 0, "(Matched)", ""))
				Next i
			Finally
				matcher.IdentifyEnd()
			End Try

			Console.WriteLine("=== identification finished ===")
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

			If extractor IsNot Nothing Then
				extractor.Dispose()
			End If
			If matcher IsNot Nothing Then
				matcher.Dispose()
			End If
		End Try
	End Function

	Private Shared Function ExtractTemplate(ByVal extractor As NLExtractor, ByVal fileName As String, ByVal isProbe As Boolean) As NBuffer
		Dim image As NImage = Nothing
		Dim grayscaleImage As NGrayscaleImage = Nothing
		Dim template As NLTemplate = Nothing

		' Set the template size (recommended for matching medium, for enrolling - large) (optional)
		extractor.TemplateSize = IIf((isProbe), NleTemplateSize.Medium, NleTemplateSize.Large)
		Try
			image = NImage.FromFile(fileName)
			grayscaleImage = image.ToGrayscale()
			Dim detectionDetails As NleDetectionDetails = Nothing
			Dim extractionStatus As NleExtractionStatus
			template = extractor.Extract(grayscaleImage, detectionDetails, extractionStatus)
			If extractionStatus = NleExtractionStatus.TemplateCreated Then
				Return template.Save()
			Else
				Throw New ApplicationException("failed to extract template. extraction status: " & extractionStatus)
			End If
		Finally
			If image IsNot Nothing Then
				image.Dispose()
			End If
			If grayscaleImage IsNot Nothing Then
				grayscaleImage.Dispose()
			End If
			If template IsNot Nothing Then
				template.Dispose()
			End If
		End Try
	End Function
End Class
