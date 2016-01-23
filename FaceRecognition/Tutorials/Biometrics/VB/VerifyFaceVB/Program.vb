Imports Microsoft.VisualBasic
Imports System
Imports System.IO

Imports Neurotec.Images
Imports Neurotec.Biometrics
Imports Neurotec.Licensing
Imports Neurotec.IO

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [reference image] [candidate image]", Utils.GetAssemblyName())
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
			' Obtain license.
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine("Could not obtain licenses for components: {0}", Components)
				Return -1
			End If

			' create an extractor
			extractor = New NLExtractor()

			' Extract reference template
			Dim referenceTemplate As NBuffer
			Try
				referenceTemplate = ExtractTemplate(extractor, args(0), False)
			Catch ex As IOException
				Console.WriteLine("error reading input file {0}: {1}", args(0), ex)
				Return -1
			End Try

			' Extract candidate template
			Dim candidateTemplate As NBuffer
			Try
				candidateTemplate = ExtractTemplate(extractor, args(1), False)
			Catch ex As IOException
				Console.WriteLine("error reading input file {0}: {1}", args(1), ex)
				Return -1
			End Try

			' create a matcher
			matcher = New NMatcher()
			' perform verification
			Dim score As Integer = matcher.Verify(referenceTemplate, candidateTemplate)
			Console.Write("image scored {0}, verification.. ", score)
			If score > 0 Then
				Console.WriteLine("succeeded")
			Else
				Console.WriteLine("failed")
			End If

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
