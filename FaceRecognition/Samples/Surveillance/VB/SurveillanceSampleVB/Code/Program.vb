Imports System
Imports System.Windows.Forms
Imports Neurotec.Samples.Forms
Imports Neurotec.Licensing
Imports Microsoft.VisualBasic

Namespace Code
    Friend NotInheritable Class Program
        ''' <summary>
        ''' The main entry point for the application.
        ''' </summary>
        Private Sub New()
        End Sub
        <STAThread()> _
         Shared Sub Main()
            Const Components As String = "Surveillance"

            Try
                If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
                    MessageBox.Show(String.Format("Could not obtain licenses for any of components: {0}", Components))
                    Return
                End If
            Catch ex As Exception
                Dim message As String = String.Format("Failed to obtain licenses for components." & Constants.vbLf & "Error message: {0}", ex.Message)
                If TypeOf ex Is System.IO.IOException Then
                    message &= Constants.vbLf & "(Probably licensing service is not running. Use Activation Wizard to figure it out.)"
                End If
                MessageBox.Show(message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                Return
            End Try

            Try
                Application.EnableVisualStyles()
                Application.SetCompatibleTextRenderingDefault(False)
                Application.Run(New Forms.MainForm())
            Catch ex As Exception
                MessageBox.Show(String.Format("Unhandled exception. Details: {0}", ex), "Surveillance Sample", MessageBoxButtons.OK, MessageBoxIcon.Error)
            Finally
                NLicense.ReleaseComponents(Components)
            End Try
        End Sub
    End Class
End Namespace
