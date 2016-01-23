Imports System.IO
Imports System.Data
Imports System.Drawing
Imports OfficeOpenXml
Imports System.Globalization

Partial Class frmReport_Booking_Daily
    Inherits System.Web.UI.Page

    '    Protected Sub Page_Load(sender As Object, e As EventArgs) Handles Me.Load
    '        'If Not IsPostBack Then
    '        '    SetBuildingDdl()
    '        '    cbBuilding_ServerChange(sender, e)
    '        'End If
    '    End Sub

    '    'Protected Sub btnSearch_ServerClick(sender As Object, e As EventArgs) Handles btnSearch.ServerClick
    '    '    Dim dt As New DataTable
    '    '    dt = GetDataForBookingDialy()
    '    '    RenderReportByDate(dt)
    '    '    ScriptManager.RegisterStartupScript(Me, Me.GetType, Guid.NewGuid.ToString, "$('.chzn-select').chosen();", True)
    '    '    ScriptManager.RegisterStartupScript(Me, Me.GetType, Guid.NewGuid.ToString, " $('.date-picker').datepicker().next().on(ace.click_event, function () { $(this).prev().focus();});", True)
    '    'End Sub

    '    'Protected Sub btnClear_ServerClick(sender As Object, e As EventArgs) Handles btnClear.ServerClick
    '    '    ' lblMessage.Visible = False
    '    '    'cbBuilding.SelectedIndex = 0
    '    '    'cbRoom.SelectedIndex = 0
    '    '    ' datefrom.Value = ""
    '    '    ' dateto.Value = ""
    '    '    ScriptManager.RegisterStartupScript(Me, Me.GetType, Guid.NewGuid.ToString, "$('.chzn-select').chosen();", True)
    '    '    ScriptManager.RegisterStartupScript(Me, Me.GetType, Guid.NewGuid.ToString, " $('.date-picker').datepicker().next().on(ace.click_event, function () { $(this).prev().focus();});", True)
    '    'End Sub
    '    Protected Sub btnExport_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnExport.ServerClick
    '        ExportToExcel()
    '    End Sub

    '    'Protected Sub cbBuilding_ServerChange(sender As Object, e As EventArgs) Handles cbBuilding.ServerChange
    '    '    'Dim building As String = cbBuilding.Value
    '    '    'SetRoomDdl(building)
    '    'End Sub


    '#Region "Sub&Function"
    '    Sub SetRoomDdl(building As String)
    '        'Dim cls As New clsFunction
    '        'Dim dt As New DataTable
    '        'dt = cls.LoadRoomByBuilding(building)
    '        'If dt.Rows.Count > 0 Then
    '        '    cbRoom.DataTextField = "room_name"
    '        '    cbRoom.DataValueField = "id"
    '        '    cbRoom.DataSource = dt
    '        '    cbRoom.DataBind()

    '        '    cbRoom.Items.Insert(0, New ListItem("Choose a Room ...", ""))
    '        'Else
    '        '    cbRoom.DataTextField = "room_name"
    '        '    cbRoom.DataValueField = "id"
    '        '    cbRoom.Items.Insert(0, New ListItem("Choose a Room ...", ""))
    '        'End If
    '    End Sub

    '    Sub SetBuildingDdl()
    '        Dim cls As New clsFunction
    '        Dim dt As New DataTable
    '        dt = cls.LoadActiveBuliding
    '        'If dt.Rows.Count > 0 Then
    '        '    cbBuilding.DataTextField = "building_name"
    '        '    cbBuilding.DataValueField = "id"
    '        '    cbBuilding.DataSource = dt
    '        '    cbBuilding.DataBind()
    '        '    cbBuilding.Items.Insert(0, New ListItem("Choose a Building...", ""))
    '        'Else
    '        '    cbBuilding.DataTextField = "building_name"
    '        '    cbBuilding.DataValueField = "id"
    '        '    cbBuilding.Items.Insert(0, New ListItem("Choose a Building...", ""))
    '        'End If
    '    End Sub

    '    Sub ExportToExcel()
    '        Dim countCriteria As Integer = 1
    '        Using ep As New ExcelPackage
    '            Dim ws As ExcelWorksheet = ep.Workbook.Worksheets.Add("BookingDailyReport")
    '            ws.Cells("A" & countCriteria & "").Value = "use_date"
    '            ws.Cells("B" & countCriteria & "").Value = "reserve_date"
    '            ws.Cells("C" & countCriteria & "").Value = "room_name"
    '            ws.Cells("D" & countCriteria & "").Value = "building_name"
    '            ws.Cells("E" & countCriteria & "").Value = "purpose"
    '            ws.Cells("F" & countCriteria & "").Value = "id_cardno"
    '            ws.Cells("G" & countCriteria & "").Value = "visitor_name"
    '            ws.Cells("H" & countCriteria & "").Value = "visitor_company_name"
    '            ws.Cells("I" & countCriteria & "").Value = "userbooking"

    '            ' //Format the header 
    '            Using RowHeader As ExcelRange = ws.Cells("A" & countCriteria & ":I" & countCriteria & "")
    '                RowHeader.Style.Font.Bold = True
    '                RowHeader.Style.Fill.PatternType = Style.ExcelFillStyle.Solid
    '                RowHeader.Style.Fill.BackgroundColor.SetColor(Color.YellowGreen)
    '                RowHeader.Style.HorizontalAlignment = Style.ExcelHorizontalAlignment.Center
    '                RowHeader.Style.Font.Color.SetColor(Color.White)
    '            End Using
    '            '## End Header ##

    '            Dim dt As New DataTable
    '            dt = GetDataForBookingDialy()
    '            For i As Integer = 0 To dt.Rows.Count - 1
    '                countCriteria += 1
    '                ws.Cells("A" & countCriteria & "").Value = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("th-TH"))
    '                ws.Cells("B" & countCriteria & "").Value = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("th-TH"))
    '                ws.Cells("C" & countCriteria & "").Value = dt.Rows(i)("room_name").ToString
    '                ws.Cells("D" & countCriteria & "").Value = dt.Rows(i)("building_name").ToString
    '                ws.Cells("E" & countCriteria & "").Value = dt.Rows(i)("purpose").ToString
    '                ws.Cells("F" & countCriteria & "").Value = dt.Rows(i)("id_cardno").ToString
    '                ws.Cells("G" & countCriteria & "").Value = dt.Rows(i)("visitor_name").ToString
    '                ws.Cells("H" & countCriteria & "").Value = dt.Rows(i)("visitor_company_name").ToString
    '                ws.Cells("I" & countCriteria & "").Value = dt.Rows(i)("userbooking").ToString              
    '            Next

    '            Using RowContent As ExcelRange = ws.Cells("A" & countCriteria & ":O" & countCriteria)
    '                'RowContent.Style.Border.Top.Style = Style.ExcelBorderStyle.Thin
    '                'RowContent.Style.Border.Bottom.Style = Style.ExcelBorderStyle.Thin
    '                'RowContent.Style.Border.Left.Style = Style.ExcelBorderStyle.Thin
    '                'RowContent.Style.Border.Right.Style = Style.ExcelBorderStyle.Thin
    '                'RowContent.AutoFitColumns()
    '            End Using

    '            ws.Cells("A0:I" & countCriteria).AutoFitColumns()

    '            '//Write it back to the client
    '            Response.ContentType = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"
    '            Response.AddHeader("content-disposition", "attachment;  filename=" & DateTime.Now.ToString("yyyyMMddhhmmssfff") & ".xlsx")
    '            Response.BinaryWrite(ep.GetAsByteArray())
    '            Response.End()
    '            Response.Flush()

    '        End Using
    '    End Sub

    '    Function GetDataForBookingDialy() As DataTable
    '        'Dim building As String = cbBuilding.Value
    '        'Dim room As String = cbRoom.Value
    '        Dim strdatefrom As String = "" 'datefrom.Value
    '        Dim strdateto As String = "" 'dateto.Value
    '        Dim dt As New DataTable
    '        Dim cls As New clsFunction
    '        dt = cls.getdataforbookingdialy("", "", strdatefrom, strdateto)

    '        Return dt
    '    End Function

    '    Private Sub RenderReportByDate(ByVal dt As DataTable)
    '        btnExport.Visible = False
    '        If dt.Rows.Count > 0 Then
    '            btnExport.Visible = True

    '            Dim ret As New StringBuilder
    '            ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

    '            '### Header Colums Start ######
    '            Dim strHeader As String() = { _
    '                                        "use_date", _
    '                                        "reserve_date", _
    '                                        "room_name", _
    '                                        "building_name", _
    '                                        "purpose", _
    '                                        "id_cardno", _
    '                                        "visitor_name", _
    '                                        "visitor_company_name", _
    '                                        "userbooking"}
    '            ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
    '            For intHeader As Integer = 0 To strHeader.Count - 1
    '                ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
    '            Next
    '            ret.Append("    </tr>")
    '            '### Header Colums End ######


    '            '### Detail Colums Start ######
    '            For i As Integer = 0 To dt.Rows.Count - 1
    '                Dim use_date As String = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
    '                Dim reserve_date As String = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
    '                Dim room_name As String = dt.Rows(i)("room_name").ToString
    '                Dim building_name As String = dt.Rows(i)("building_name").ToString
    '                Dim purpose As String = dt.Rows(i)("purpose").ToString
    '                Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
    '                Dim visitor_name As String = dt.Rows(i)("visitor_name").ToString
    '                Dim visitor_company_name As String = dt.Rows(i)("visitor_company_name").ToString
    '                Dim userbooking As String = dt.Rows(i)("userbooking").ToString

    '                ret.Append("    <tr style='background: #E4E4E4;'>")
    '                ret.Append("        <td align='center' >" & use_date & "</td>")
    '                ret.Append("        <td align='center' >" & reserve_date & "</td>")
    '                ret.Append("        <td align='left' >" & room_name & "</td>")
    '                ret.Append("        <td align='left' >" & building_name & "</td>")
    '                ret.Append("        <td align='left' >" & purpose & "</td>")
    '                ret.Append("        <td align='left' >" & id_cardno & "</td>")
    '                ret.Append("        <td align='left' >" & visitor_name & "</td>")
    '                ret.Append("        <td align='left' >" & visitor_company_name & "</td>")
    '                ret.Append("        <td align='left' >" & userbooking & "</td>")
    '                ret.Append("    </tr>")
    '            Next
    '            '### Detail Colums End ######

    '            ret.Append("</table>")
    '            ' lblReportDesc.Text = ret.ToString
    '            ret = Nothing
    '        End If

    '        'If lblReportDesc.Text.Trim = "" Then
    '        '    'lblMessage.Visible = True
    '        'Else
    '        '    'lblMessage.Visible = False
    '        'End If
    '    End Sub
    '#End Region







End Class
