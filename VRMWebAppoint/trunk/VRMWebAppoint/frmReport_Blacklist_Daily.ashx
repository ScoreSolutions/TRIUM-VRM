<%@ WebHandler Language="VB" Class="frmReport_Blacklist_Daily" %>

Imports System
Imports System.Web
Imports System.IO
Imports System.Data
Imports System.Drawing
Imports OfficeOpenXml
Imports System.Globalization
Public Class frmReport_Blacklist_Daily : Implements IHttpHandler
    
    Public Sub ProcessRequest(ByVal context As HttpContext) Implements IHttpHandler.ProcessRequest
        Dim url As String = context.Request.RawUrl
        Dim strTemp As String() = url.Split("&")
        Dim name, reason, datefrom, dateto As String
        For i As Integer = 0 To strTemp.Length - 1
            Dim strTemp2 As String() = strTemp(i).Split("=")
            Select Case i
                Case 0
                    name = strTemp2(1) & ""
                Case 1
                    reason = strTemp2(1) & ""
                Case 2
                    datefrom = strTemp2(1) & ""
                Case 3
                    dateto = strTemp2(1) & ""
            End Select
        Next
        
        Dim countCriteria As Integer = 1
        Using ep As New ExcelPackage
            Dim ws As ExcelWorksheet = ep.Workbook.Worksheets.Add("BlacklistDialyReport")
            ws.Cells("A" & countCriteria & "").Value = "blacklist_date"
            ws.Cells("B" & countCriteria & "").Value = "blacklist_reason"
            ws.Cells("C" & countCriteria & "").Value = "id_cardno"
            ws.Cells("D" & countCriteria & "").Value = "name"
            ws.Cells("E" & countCriteria & "").Value = "address"
                                                
            ' //Format the header 
            Using RowHeader As ExcelRange = ws.Cells("A" & countCriteria & ":E" & countCriteria & "")
                RowHeader.Style.Font.Bold = True
                RowHeader.Style.Fill.PatternType = Style.ExcelFillStyle.Solid
                RowHeader.Style.Fill.BackgroundColor.SetColor(Color.YellowGreen)
                RowHeader.Style.HorizontalAlignment = Style.ExcelHorizontalAlignment.Center
                RowHeader.Style.Font.Color.SetColor(Color.White)
            End Using
            '## End Header ##

            Dim webs As New WebService
            Dim dt As New DataTable
            dt = webs.GetdataforBlacklistDialy(name, reason, datefrom, dateto)
            For i As Integer = 0 To dt.Rows.Count - 1
                countCriteria += 1
                ws.Cells("A" & countCriteria & "").Value = Convert.ToDateTime(dt.Rows(i)("blacklist_date")).ToString("dd/MM/yyyy", New CultureInfo("th-TH"))
                ws.Cells("B" & countCriteria & "").Value = dt.Rows(i)("blacklist_reason").ToString
                ws.Cells("C" & countCriteria & "").Value = dt.Rows(i)("id_cardno").ToString
                ws.Cells("D" & countCriteria & "").Value = dt.Rows(i)("name").ToString
                ws.Cells("E" & countCriteria & "").Value = dt.Rows(i)("address").ToString
            Next
            Using RowContent As ExcelRange = ws.Cells("A" & countCriteria & ":E" & countCriteria)
                'RowContent.Style.Border.Top.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Bottom.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Left.Style = Style.ExcelBorderStyle.Thin
                'RowContent.Style.Border.Right.Style = Style.ExcelBorderStyle.Thin
                'RowContent.AutoFitColumns()
            End Using

            ws.Cells("A0:E" & countCriteria).AutoFitColumns()

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