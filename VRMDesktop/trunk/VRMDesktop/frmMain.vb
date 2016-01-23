Public Class frmMain

    Private Sub btnLog_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnLog.Click
        Dim formToShow As New frmLog
        formToShow.TopLevel = False
        formToShow.WindowState = FormWindowState.Maximized
        formToShow.FormBorderStyle = Windows.Forms.FormBorderStyle.None
        formToShow.Visible = True
        Me.Panel1.Controls.Add(formToShow)
    End Sub
End Class