<%@ WebHandler Language="VB" Class="frmReport_Booking_Personel" %>

Imports System
Imports System.Web
Imports System.IO
Imports System.Data
Imports System.Drawing
Imports OfficeOpenXml
Imports System.Globalization

Public Class frmReport_Booking_Personel : Implements IHttpHandler
    
    Public Sub ProcessRequest(ByVal context As HttpContext) Implements IHttpHandler.ProcessRequest
        Dim url As String = context.Request.RawUrl
        Dim strTemp As String() = url.Split("&")
        Dim buildingid, roomid, personal As String
        For i As Integer = 0 To strTemp.Length - 1
            Dim strTemp2 As String() = strTemp(i).Split("=")
            Select Case i
                Case 0
                    buildingid = strTemp2(1) & ""
                Case 1
                    roomid = strTemp2(1) & ""
                Case 2
                    personal = strTemp2(1) & ""
               
            End Select
        Next
        
        Dim countCriteria As Integer = 1
        Using ep As New ExcelPackage
            Dim ws As ExcelWorksheet = ep.Workbook.Worksheets.Add("BookingPersonalReport")
            ws.Cells("A" & countCriteria & "").Value = "use_date"
            ws.Cells("B" & countCriteria & "").Value = "reserve_date"
            ws.Cells("C" & countCriteria & "").Value = "department"
            ws.Cells("D" & countCriteria & "").Value = "room_name"
            ws.Cells("E" & countCriteria & "").Value = "building_name"
            ws.Cells("F" & countCriteria & "").Value = "purpose"
            ws.Cells("G" & countCriteria & "").Value = "id_cardno"
            ws.Cells("H" & countCriteria & "").Value = "visitor_name"
            ws.Cells("I" & countCriteria & "").Value = "visitor_company_name"
            ws.Cells("J" & countCriteria & "").Value = "userbooking"
                                                
            ' //Format the header 
            Using RowHeader As ExcelRange = ws.Cells("A" & countCriteria & ":J" & countCriteria & "")
                RowHeader.Style.Font.Bold = True
                RowHeader.Style.Fill.PatternType = Style.ExcelFillStyle.Solid
                RowHeader.Style.Fill.BackgroundColor.SetColor(Color.YellowGreen)
                RowHeader.Style.HorizontalAlignment = Style.ExcelHorizontalAlignment.Center
                RowHeader.Style.Font.Color.SetColor(Color.White)
            End Using
            '## End Header ##

            Dim webs As New WebService
            Dim dt As New DataTable
            dt = webs.GetdataforBookingPersonal(buildingid, roomid, personal)
            For i As Integer = 0 To dt.Rows.Count - 1
                countCriteria += 1
                ws.Cells("A" & countCriteria & "").Value = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("th-TH"))
                ws.Cells("B" & countCriteria & "").Value = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("th-TH"))
                ws.Cells("C" & countCriteria & "").Value = dt.Rows(i)("department_name").ToString
                ws.Cells("D" & countCriteria & "").Value = dt.Rows(i)("room_name").ToString
                ws.Cells("E" & countCriteria & "").Value = dt.Rows(i)("building_name").ToString
                ws.Cells("F" & countCriteria & "").Value = dt.Rows(i)("purpose").ToString
                ws.Cells("G" & countCriteria & "").Value = dt.Rows(i)("id_cardno").ToString
                ws.Cells("H" & countCriteria & "").Value = dt.Rows(i)("visitor_name").ToString
                ws.Cells("I" & countCriteria & "").Value = dt.Rows(i)("visitor_company_name").ToString
                ws.Cells("J" & countCriteria & "").Value = dt.Rows(i)("userbooking").ToString
            Next

            Using RowContent As ExcelRange = ws.Cells("A" & countCriteria & ":O" & countCriteria)
                'RowContent.Style.Border.Top.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Bottom.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Left.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Right.Style = Style.ExcelBorderStyle.Thin
                'RowContent.AutoFitColumns()
            End Using

            ws.Cells("A0:J" & countCriteria).AutoFitColumns()

            '//Write it back to the client
            context.Response.ContentType = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"
            context.Response.AddHeader("content-disposition", "attachment;  filename=" & DateTime.Now.ToString("yyyyMMddhhmmssfff") & ".xlsx")
            context.Response.BinaryWrite(ep.GetAsByteArray())
            context.Response.End()
            context.Response.Flush()
        End Using
            
    End Sub
 
    Public ReadOnly Property IsReusable() As Boolean Implements IHttpHandler.IsReusable
        Get
            Return False
        End Get
    End Property

End Class