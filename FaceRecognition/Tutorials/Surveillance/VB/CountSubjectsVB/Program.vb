Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.Text
Imports System.Threading

Imports Neurotec.Licensing
Imports Neurotec.Surveillance
Imports Neurotec.Biometrics
Imports Neurotec.Devices

''' <summary>
''' This tutorial demonstrates how to perform automatic enrollment.
''' At first there are no templates in the internal database,
''' however as subjects pass through the field of view of the camera
''' Surveillance library enrolls each of them so that new templates are ready to
''' be added to the internal database.
''' In this tutorial we add new templates only if subject was not already known 
''' to the system enabling us to count the number of unique subjects and total
''' subjects passed through the field of view of the camera.
''' This tutorial either waits for 3 minutes to elapse or 7 subjects to pass.
''' </summary>
Friend Class Program
	Private Shared handle As New AutoResetEvent(False)
	Private Shared surveillance As NSurveillance = Nothing
	Private Shared templateIds As New List(Of String)()
	Private Shared templates As New List(Of Byte())()
	Private Shared subjectCount As Integer = 0
	Private Const TimeStampFormat = "yyyy-MM-dd HH:mm:ss"

	Shared Sub usage()
		Console.WriteLine("usage:")
		Console.WriteLine(Constants.vbTab & "{0} [time in minutes]", Utils.GetAssemblyName())
		Console.WriteLine()
	End Sub

	Shared Sub Main(ByVal args() As String)
		Utils.PrintTutorialHeader(args)

		If args.Length < 1 Then
			usage()
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

			Console.WriteLine("found cameras:")
			For Each device As NDevice In surveillance.DeviceManager.Devices
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

			Console.WriteLine("{0} faces passed, {1} different subjects were identified.", subjectCount, templateIds.Count)
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
		Console.WriteLine("[{0}] [{1}] subject appeared", details.TimeStamp.ToString(TimeStampFormat), details.TraceIndex)
	End Sub

	Private Shared Sub surveillance_SubjectTrack(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
		Dim details As NSurveillanceEventDetails = e.EventDetails
		Console.Write("[{0}] [{1}] subject tracked", details.TimeStamp.ToString(TimeStampFormat), details.TraceIndex)
		Dim matches As NSurveillanceEventDetails.BestMatchCollection = details.BestMatches
		If matches.Count = 0 Then
			Console.WriteLine()
		Else
			Console.WriteLine(", best match with template id = {0} collected score = {1}", matches(0).TemplateId, matches(0).Score)
		End If
	End Sub

	Private Shared Sub surveillance_SubjectDisappeared(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
		Dim details As NSurveillanceEventDetails = e.EventDetails
		Console.Write("[{0}] [{1}] subject disappeared", details.TimeStamp.ToString(TimeStampFormat), details.TraceIndex)
		Dim matches As NSurveillanceEventDetails.BestMatchCollection = details.BestMatches
		If matches.Count = 0 Then
			Dim template As NLTemplate = details.GetSubjectTemplate()
			If template IsNot Nothing Then
				Dim templateId As String = String.Format("SubjectNo{0:d3}", templateIds.Count)
				templateIds.Add(templateId)
				templates.Add(template.Save().ToArray())
				surveillance.AddTemplate(templates(templates.Count - 1), templateId)
				Console.WriteLine(", new subject ""{0}"" was added to the database", templateId)
			Else
				Console.WriteLine(", but face template was not generated")
			End If
		Else
			Console.WriteLine(", best matches (score, template id):")
			For i As Integer = 0 To matches.Count - 1
				Console.WriteLine(Constants.vbTab & "{0}. {1} {2}", i, matches(i).Score, matches(i).TemplateId)
			Next i
		End If
		subjectCount += 1
	End Sub
End Class
