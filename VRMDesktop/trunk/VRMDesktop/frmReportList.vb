Public Class frmReportList

    Private Sub pbSetting_Click(sender As Object, e As EventArgs) Handles pbSetting.Click
        Me.Close()
        frmSetting.Show()
    End Sub

    Private Sub pbRegistration_Click(sender As Object, e As EventArgs) Handles pbRegistration.Click
        Me.Close()
        frmRegister.Show()
    End Sub

    Private Sub pbLog_Click(sender As Object, e As EventArgs) Handles pbLog.Click
        Me.Close()
        frmLog.Show()
    End Sub

    Private Sub lblTotalVisitorReport_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles lblTotalVisitorReport.LinkClicked
        Process.Start(Application.StartupPath & "\SampleReport\TotalVisitorReport.pdf")
    End Sub

    Private Sub lblTop10VisitorReportByEmployee_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles lblTop10VisitorReportByEmployee.LinkClicked
        Process.Start(Application.StartupPath & "\SampleReport\Top10VisitorRegistrationReportbyEmployee.pdf")
    End Sub

    Private Sub VisitorReportByMeetingRoom_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles VisitorReportByMeetingRoom.LinkClicked
        Process.Start(Application.StartupPath & "\SampleReport\VisitorRegistrationReportbyMeetingRoom.pdf")
    End Sub

    Private Sub BlacklistReport_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles BlacklistReport.LinkClicked
        Process.Start(Application.StartupPath & "\SampleReport\BacklistReport.pdf")
    End Sub
End Class