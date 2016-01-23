Imports LinqDB.TABLE
Imports System.Data

Partial Class frmCompletRoom
    Inherits System.Web.UI.Page

    Protected Sub Page_Load(sender As Object, e As EventArgs) Handles Me.Load

        'Dim clsTbPrebookingLinqDB As New TbPrebookingLinqDB
        'With clsTbPrebookingLinqDB
        '    Dim dt As DataTable = .GetDataList("UserId='" & Page.Request.QueryString("id") & "'", "", Nothing)
        '    If dt.Rows.Count > 0 Then
        '        lblLine1.Text = "Customer :" & dt.Rows(0)("customer_name") & ""
        '        lblLine3.Text = "Meeting Date :" & dt.Rows(0)("meeting_date") & ""
        '        lblline4.Text = "Meeting Time :" & dt.Rows(0)("meeting_time") & "" & IIf(dt.Rows(0)("meeting_time_end") = "", "", " to " & dt.Rows(0)("meeting_time_end"))
        '        lblLine2.Text = "Purpose :" & dt.Rows(0)("purpose") & ""
        '        lblline5.Text = "Location :" & dt.Rows(0)("location") & ""
        '    End If
        'End With



    End Sub


End Class
