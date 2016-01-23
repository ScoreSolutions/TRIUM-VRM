Imports Neurotec.Licensing
Imports Microsoft.VisualBasic
Imports System

Imports Neurotec.Images
Imports Neurotec.Devices

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [frameCount]", Utils.GetAssemblyName())
		Console.WriteLine()
		Console.WriteLine(vbTab & "frameCount - number of frames to capture from each camera to current directory.")
		Console.WriteLine()

		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Devices.Cameras"

		Utils.PrintTutorialHeader(args)

		If args.Length < 1 Then
			Return Usage()
		End If

		Try
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine(String.Format("Could not obtain licenses for components: {0}", Components))
				Return -1
			End If
			Dim frameCount As Integer = Integer.Parse(args(0))

			If frameCount = 0 Then
				Console.WriteLine("no frames will be captured as frame count is not specified")
			End If

			Dim deviceManager As New NDeviceManager(NDeviceType.Camera, True, False)
			Console.WriteLine("device manager created. found cameras: {0}", deviceManager.Devices.Count)

			For Each camera As NCamera In deviceManager.Devices
				Console.Write("found camera {0}", camera.DisplayName)

				camera.StartCapturing()

				If frameCount > 0 Then
					Console.Write(", capturing")
					For i As Integer = 0 To frameCount - 1
						Dim filename As String = String.Format("{0}_{1:d4}.jpg", camera.DisplayName, i)
						Using image As NImage = camera.GetFrame()
							image.Save(filename)
						End Using
						Console.Write(".")
					Next i
					Console.Write(" done")
					Console.WriteLine()
				End If
				camera.StopCapturing()
			Next camera
			Console.WriteLine("done")
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
