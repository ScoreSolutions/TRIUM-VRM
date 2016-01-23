<%@ WebHandler Language="VB" Class="frmReport_Visitor_Monthly" %>

Imports System
Imports System.Web
Imports System.IO
Imports System.Data
Imports System.Drawing
Imports OfficeOpenXml
Imports System.Globalization

Public Class frmReport_Visitor_Monthly : Implements IHttpHandler
    
    Public Sub ProcessRequest(ByVal context As HttpContext) Implements IHttpHandler.ProcessRequest
       
        Dim url As String = context.Request.RawUrl
        Dim strTemp As String() = url.Split("&")
        Dim buildingid, roomid, yearfrom, yearto, monthfrom, monthto As String
        For i As Integer = 0 To strTemp.Length - 1
            Dim strTemp2 As String() = strTemp(i).Split("=")
            Select Case i
                Case 0
                    buildingid = strTemp2(1) & ""
                Case 1
                    roomid = strTemp2(1) & ""
                Case 2
                    yearfrom = strTemp2(1) & ""
                Case 3
                    yearto = strTemp2(1) & ""
                Case 4
                    monthfrom = strTemp2(1) & ""
                Case 5
                    monthto = strTemp2(1) & ""
            End Select
        Next
        
        Dim countCriteria As Integer = 1
        Using ep As New ExcelPackage
            Dim ws As ExcelWorksheet = ep.Workbook.Worksheets.Add("VisitorMonthlyReport")
            ws.Cells("A" & countCriteria & "").Value = "id_cardno"
            ws.Cells("B" & countCriteria & "").Value = "name"
            ws.Cells("C" & countCriteria & "").Value = "staff_name"
            ws.Cells("D" & countCriteria & "").Value = "place"
            ws.Cells("E" & countCriteria & "").Value = "purpose"
            ws.Cells("F" & countCriteria & "").Value = "in_date"
            ws.Cells("G" & countCriteria & "").Value = "out_date"
                                                
            ' //Format the header 
            Using RowHeader As ExcelRange = ws.Cells("A" & countCriteria & ":G" & countCriteria & "")
                RowHeader.Style.Font.Bold = True
                RowHeader.Style.Fill.PatternType = Style.ExcelFillStyle.Solid
                RowHeader.Style.Fill.BackgroundColor.SetColor(Color.YellowGreen)
                RowHeader.Style.HorizontalAlignment = Style.ExcelHorizontalAlignment.Center
                RowHeader.Style.Font.Color.SetColor(Color.White)
            End Using
            '## End Header ##

            Dim webs As New WebService
            Dim dt As New DataTable
            dt = webs.GetdataforVisitorMonthly(buildingid, roomid, yearfrom, yearto, monthfrom, monthto)
            For i As Integer = 0 To dt.Rows.Count - 1
                countCriteria += 1
                ws.Cells("A" & countCriteria & "").Value = dt.Rows(i)("id_cardno").ToString
                ws.Cells("B" & countCriteria & "").Value = dt.Rows(i)("name").ToString
                ws.Cells("C" & countCriteria & "").Value = dt.Rows(i)("staff_name").ToString
                ws.Cells("D" & countCriteria & "").Value = dt.Rows(i)("place").ToString
                ws.Cells("E" & countCriteria & "").Value = dt.Rows(i)("purpose").ToString
                ws.Cells("F" & countCriteria & "").Value = Convert.ToDateTime(dt.Rows(i)("in_date")).ToString("dd/MM/yyyy", New CultureInfo("th-TH"))
                ws.Cells("G" & countCriteria & "").Value = Convert.ToDateTime(dt.Rows(i)("out_date")).ToString("dd/MM/yyyy", New CultureInfo("th-TH"))
            Next

            Using RowContent As ExcelRange = ws.Cells("A" & countCriteria & ":G" & countCriteria)
                'RowContent.Style.Border.Top.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Bottom.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Left.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Right.Style = Style.ExcelBorderStyle.Thin
                'RowContent.AutoFitColumns()
            End Using

            ws.Cells("A0:G" & countCriteria).AutoFitColumns()

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