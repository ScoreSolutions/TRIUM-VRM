Public Class frmPreviewNoEntry

    Private Sub frmPreviewNoEntry_FormClosed(sender As Object, e As FormClosedEventArgs) Handles Me.FormClosed
        frmRegister.btnCancel_Click(New Object, New EventArgs)
    End Sub
End Class