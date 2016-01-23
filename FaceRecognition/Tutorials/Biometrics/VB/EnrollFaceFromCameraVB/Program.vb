Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.IO
Imports Neurotec.Biometrics
Imports Neurotec.Devices
Imports Neurotec.Images
Imports Neurotec.Licensing

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [image] [template]", Utils.GetAssemblyName())
		Console.WriteLine()
		Console.WriteLine(vbTab & "[image]  - image filename to store face image.")
		Console.WriteLine(vbTab & "[template] - filename to store face template.")
		Console.WriteLine()
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Biometrics.FaceExtraction,Devices.Cameras"

		Utils.PrintTutorialHeader(args)

		If args.Length < 2 Then
			Return Usage()
		End If

		Try
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine(String.Format("Could not obtain licenses for components: {0}", Components))
				Return -1
			End If

			Dim i As Integer
			Dim devMan As New NDeviceManager(NDeviceType.Camera, True, False)
			Dim count As Integer = devMan.Devices.Count

			If count > 0 Then
				Console.WriteLine("found {0} cameras", count)
			Else
				Console.WriteLine("no cameras found, exiting ..." & vbLf)
				Return -1
			End If

			If count > 1 Then
				Console.WriteLine("Please select camera from the list: ")
			End If
			For i = 0 To count - 1
				Dim device As NDevice = devMan.Devices(i)
				Console.WriteLine("{0}) {1}", i + 1, device.DisplayName)
			Next i

			If count > 1 Then
				Console.Write("Please enter camera index: ")
				Dim line As String = Console.ReadLine()
				If line Is Nothing Then
					Throw New ApplicationException("Nothing read from standard input")
				End If
				i = Integer.Parse(line)
				If i > count OrElse i < 1 Then
					Console.WriteLine("Incorrect index provided, exiting ...")
					Return -1
				End If
			End If
			i -= 1

			Dim camera As NCamera = CType(devMan.Devices(i), NCamera)
			Dim extractor As New NLExtractor()
			Dim template As NLTemplate
			Dim frames As New List(Of NImage)()
			Dim image As NImage
			Dim grayscaleImage As NGrayscaleImage
			Dim extractionStarted As Boolean = False

			extractor.TemplateSize = NleTemplateSize.Large

			Console.WriteLine("Capturing from {0}. Please turn camera to face.", camera.DisplayName)
			camera.StartCapturing()

			Do
				image = camera.GetFrame()
				Dim baseFrameIndex As Integer
				If image Is Nothing Then
					Console.WriteLine("Camera unplugged. Exiting")
					If extractionStarted Then
						Dim extrStatus As NleExtractionStatus
						Dim details As NleDetectionDetails = Nothing
						extractor.ExtractEnd(baseFrameIndex, details, extrStatus)
					End If
					Return -1
				End If
				grayscaleImage = image.ToGrayscale()
				If (Not extractionStarted) Then
					Dim face As NleFace
					Dim detected As Boolean = extractor.DetectFace(grayscaleImage, face)
					If detected Then
						extractionStarted = True
						extractor.ExtractStart()
					End If
					image.Dispose()
				Else
					Dim details As NleDetectionDetails = Nothing
					Dim status As NleExtractionStatus = extractor.ExtractNext(grayscaleImage, details)

					frames.Add(image)
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

					If status <> NleExtractionStatus.None Then
						template = extractor.ExtractEnd(baseFrameIndex, details, status)
						If status = NleExtractionStatus.TemplateCreated Then
							Console.WriteLine("Template created")
							frames(baseFrameIndex).Save(args(0))
							frames.Clear()
							Console.WriteLine("Image saved to {0}", args(0))
							File.WriteAllBytes(args(1), template.Save().ToArray())
							Console.WriteLine("Template saved to {0}", args(1))
						Else
							Console.WriteLine("Extraction failed: {0}", status)
						End If
						Exit Do
					End If
				End If
				grayscaleImage.Dispose()
			Loop
			camera.StopCapturing()

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
