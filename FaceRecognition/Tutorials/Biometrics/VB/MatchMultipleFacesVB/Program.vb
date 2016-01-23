Imports System
Imports System.Windows.Forms

Imports Neurotec.Licensing

Friend NotInheritable Class Program
	''' <summary>
	''' The main entry point for the application.
	''' </summary>
	Private Sub New()
	End Sub
	<STAThread()> _
	Shared Sub Main()
		Const Components As String = "Biometrics.FaceExtraction,Biometrics.FaceMatching"

		Try
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				MessageBox.Show(String.Format("Could not obtain licenses for components: {0}", Components))
				Return
			End If

			Application.EnableVisualStyles()
			Application.SetCompatibleTextRenderingDefault(False)
			Application.Run(New MainForm())
		Catch ex As Exception
			MessageBox.Show(ex.ToString())
			Return
		Finally
			NLicense.ReleaseComponents(Components)
		End Try
	End Sub
End Class
