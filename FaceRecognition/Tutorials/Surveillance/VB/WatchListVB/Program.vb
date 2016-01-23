Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.Threading

Imports Neurotec.Devices
Imports Neurotec.Surveillance
Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.Licensing

Friend Class Program
	Private Shared handle As New AutoResetEvent(False)
	Private Shared surveillance As NSurveillance = Nothing
	Private Shared templateIds As New List(Of String)()
	Private Shared templates As New List(Of Byte())()
	Private Const TimeStampFormat = "yyyy-MM-dd HH:mm:ss"

	Shared Sub usage()
		Console.WriteLine("usage:")
		Console.WriteLine(Constants.vbTab & "{0} [time in minutes] [one or more watch-list images]", Utils.GetAssemblyName())
		Console.WriteLine()
	End Sub

	Shared Sub Main(ByVal args() As String)
		Utils.PrintTutorialHeader(args)

		If args.Length < 2 Then
			usage
			Return
		End If

		Dim components As String = "Surveillance"

		Try
			If (Not NLicense.ObtainComponents("/local", 5000, components)) Then
				Console.WriteLine(String.Format("Could not obtain licenses for components: {0}", components))
				Return
			End If

			Dim timeInMinutes As Integer = Integer.Parse(args(0))

			Console.WriteLine("initializing Surveillance.. ")
			surveillance = New NSurveillance()
			Console.WriteLine("done")

			Dim extractor As New NLExtractor()
			For i As Integer = 1 To args.Length - 1
				Console.Write("loading image ""{0}"".. ", args(i))
				Dim image As NImage = NImage.FromFile(args(i))
				Console.WriteLine("done")

				Dim grayscale As NGrayscaleImage = image.ToGrayscale()
				Dim detectionDetails As NleDetectionDetails = Nothing
				Dim extractionStatus As NleExtractionStatus
				Console.Write("creating template.. ")
				' set template size to large for enrolling (optional)
				extractor.TemplateSize = NleTemplateSize.Large
				Dim template As NLTemplate = extractor.Extract(grayscale, detectionDetails, extractionStatus)
				If extractionStatus = NleExtractionStatus.TemplateCreated Then
					Console.WriteLine("ok")
					templates.Add(template.Save().ToArray())
					templateIds.Add(args(i))
					Console.Write("adding template to the surveillance watch list.. ")
					surveillance.AddTemplate(templates(templates.Count - 1), templateIds(templateIds.Count - 1))
					Console.WriteLine("done")
				Else
					Console.WriteLine("failed (extractionStatus = {0}", extractionStatus)
				End If
				image.Dispose()
				grayscale.Dispose()
			Next i

			Console.WriteLine("found cameras:")
			For Each device As NCamera In surveillance.DeviceManager.Devices
				Console.WriteLine(Constants.vbTab & "{0}", device.DisplayName)
			Next device
			Console.Write("choose a camera index from the list above: ")
			Dim index As Integer = Integer.Parse(Console.ReadLine())

			Dim cam As NCamera = CType(surveillance.DeviceManager.Devices(index), NCamera)
			Console.Write("adding camera to surveillance.. ")
			surveillance.Sources.Add(cam)
			Console.WriteLine("done")

			Console.Write("setting callbacks.. ")
			AddHandler surveillance.SubjectAppeared, AddressOf surveillance_SubjectAppeared
			AddHandler surveillance.SubjectTrack, AddressOf surveillance_SubjectTrack
			AddHandler surveillance.SubjectDisappeared, AddressOf surveillance_SubjectDisappeared
			Console.WriteLine("done")

			Console.Write("starting Surveillance for {0} minutes.. ", timeInMinutes)
			surveillance.Start()
			Console.WriteLine("done")

			handle.WaitOne(timeInMinutes * 60000, False)

			Console.Write("stopping Surveillance.. ")
			surveillance.Stop()
			Console.WriteLine("done")
		Catch ex As Exception
			Console.WriteLine(ex)
		Finally
			NLicense.ReleaseComponents(components)
			If surveillance IsNot Nothing Then
				surveillance.Dispose()
				surveillance = Nothing
			End If
		End Try
	End Sub

	Private Shared Sub surveillance_SubjectAppeared(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
		Dim details As NSurveillanceEventDetails = e.EventDetails
		Console.WriteLine("[{0}] [{1}] Subject appeared", details.TimeStamp.ToString(TimeStampFormat), details.TraceIndex)
	End Sub

	Private Shared Sub surveillance_SubjectTrack(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
		Dim details As NSurveillanceEventDetails = e.EventDetails
		Console.Write("[{0}] [{1}] Subject tracked", details.TimeStamp.ToString(TimeStampFormat), details.TraceIndex)
		Dim matches As NSurveillanceEventDetails.BestMatchCollection = details.BestMatches
		If matches.Count = 0 Then
			Console.WriteLine()
		Else
			Console.WriteLine(", best match with template id = {0} collected score = {1}", matches(0).TemplateId, matches(0).Score)
		End If
	End Sub

	Private Shared Sub surveillance_SubjectDisappeared(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
		Dim details As NSurveillanceEventDetails = e.EventDetails
		Console.Write("[{0}] [{1}] Subject disappeared", details.TimeStamp.ToString(TimeStampFormat), details.TraceIndex)
		Dim matches As NSurveillanceEventDetails.BestMatchCollection = details.BestMatches
		If matches.Count = 0 Then
			Console.WriteLine(", subject not found in the watch list")
		Else
			Console.WriteLine(", subject found in the watch list, best matches (score, template id):")
			For i As Integer = 0 To matches.Count - 1
				Console.WriteLine(Constants.vbTab & "{0}. {1} {2}", i, matches(i).Score, matches(i).TemplateId)
			Next i
		End If
	End Sub
End Class
