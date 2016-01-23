Imports System.Data.OleDb
Imports System.Data
Imports System.IO

Public Class frmLog
    Dim objConn As New OleDbConnection("Provider=microsoft.Jet.oledb.4.0;Data Source=" & Application.StartupPath & "\VRM.mdb;Jet OLEDB:Database Password=1qaz@WSX;")

    Private Sub frmLog_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Try
            If objConn.State = ConnectionState.Closed Then objConn.Open()
            Dim strSql As String = String.Empty
            strSql = "Select * From TB_Log Order By In_date asc"
            Dim objAdapter As New OleDbDataAdapter(strSql, objConn)
            Dim Ds As New DataSet
            objAdapter.Fill(Ds, "Log")
            dgvLog.DataSource = Ds.Tables("Log")

        Catch ex As Exception

        End Try
    End Sub

    Private Sub btnSearch_Click(sender As Object, e As EventArgs) Handles btnSearch.Click
        Dim dt As New DataTable
        dt.Columns.Add("visitor_name")
        dt.Columns.Add("employee_name")
        dt.Columns.Add("place")
        dt.Columns.Add("visite_date")
        dt.Columns.Add("purpose")

        Dim dr As DataRow = dt.NewRow
        dr("visitor_name") = "อัครวัฒน์ พุทธจันทร์"
        dr("employee_name") = "จตุพล มุริจัน"
        dr("place") = "Meeting Room 1 Floor 5 Building 2"
        dr("visite_date") = "01/11/2014"
        dr("purpose") = "Agenda Project VRM Planing"
        dt.Rows.Add(dr)

        dr = dt.NewRow
        dr("visitor_name") = "อัครวัฒน์ พุทธจันทร์"
        dr("employee_name") = "จตุพล มุริจัน"
        dr("place") = "Meeting Room 1 Floor 5 Building 2"
        dr("visite_date") = "01/11/2014"
        dr("purpose") = "Agenda Project VRM Planing"
        dt.Rows.Add(dr)

        dr = dt.NewRow
        dr("visitor_name") = "อัครวัฒน์ พุทธจันทร์"
        dr("employee_name") = "จตุพล มุริจัน"
        dr("place") = "Meeting Room 1 Floor 5 Building 2"
        dr("visite_date") = "01/11/2014"
        dr("purpose") = "Agenda Project VRM Planing"
        dt.Rows.Add(dr)

        dr = dt.NewRow
        dr("visitor_name") = "อัครวัฒน์ พุทธจันทร์"
        dr("employee_name") = "จตุพล มุริจัน"
        dr("place") = "Meeting Room 1 Floor 5 Building 2"
        dr("visite_date") = "01/11/2014"
        dr("purpose") = "Agenda Project VRM Planing"
        dt.Rows.Add(dr)

        dr = dt.NewRow
        dr("visitor_name") = "อัครวัฒน์ พุทธจันทร์"
        dr("employee_name") = "จตุพล มุริจัน"
        dr("place") = "Meeting Room 1 Floor 5 Building 2"
        dr("visite_date") = "01/11/2014"
        dr("purpose") = "Agenda Project VRM Planing"
        dt.Rows.Add(dr)


        If dt.Rows.Count > 0 Then
            dgvLog.DataSource = dt
        End If
    End Sub

    Private Sub pbSetting_Click(sender As Object, e As EventArgs) Handles pbSetting.Click
        Me.Close()
        frmSetting.Show()
    End Sub

    Private Sub pbRegistration_Click(sender As Object, e As EventArgs) Handles pbRegistration.Click
        Me.Close()
        frmRegister.Show()
    End Sub

    Private Sub pbReport_Click(sender As Object, e As EventArgs) Handles pbReport.Click
        Me.Close()
        frmReportList.Show()
    End Sub
End Class