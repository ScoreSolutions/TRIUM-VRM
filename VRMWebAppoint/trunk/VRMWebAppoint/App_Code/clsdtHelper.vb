Imports System.Data

Public Class clsdtHelper
    Inherits System.Web.UI.Page

    '---------------------- Convert DataTable To Json ----------------------

#Region "Convert DataTable To Json"
    Public Shared Function ConvertDataTableToJson(ByVal dt As DataTable) As String
        Dim serializer As System.Web.Script.Serialization.JavaScriptSerializer = New System.Web.Script.Serialization.JavaScriptSerializer()
        serializer.MaxJsonLength = Int32.MaxValue
        Dim rows As New List(Of Dictionary(Of String, Object))
        Dim row As Dictionary(Of String, Object)
        For Each dr As DataRow In dt.Rows
            row = New Dictionary(Of String, Object)
            For Each col As DataColumn In dt.Columns
                row.Add(col.ColumnName, dr(col))
            Next
            rows.Add(row)
        Next
        Return serializer.Serialize(rows)
    End Function
#End Region

#Region "Convert DataTable To Json"
    Public Shared Function ConvertDataTableToJson(ByVal ds As DataSet) As String
        Dim serializer As System.Web.Script.Serialization.JavaScriptSerializer = New System.Web.Script.Serialization.JavaScriptSerializer()
        Dim dict As New Dictionary(Of String, Object)
        For Each dt As DataTable In ds.Tables
            Dim arr(dt.Rows.Count) As Object
            For i As Integer = 0 To dt.Rows.Count - 1
                arr(i) = dt.Rows(i).ItemArray
            Next
            dict.Add(dt.TableName, arr)
        Next
        Return serializer.Serialize(dict)
    End Function
#End Region

#Region "Convert DataTable To HTML"
    Public Shared Function ConvertDataTableToHTML(ByVal dt As DataTable, IsEdit As Boolean, Optional ByVal datatablename As String = "datatable") As String
        Dim strTD_edit As String = ""
        If IsEdit = True Then
            dt.Columns.Add("Edit")
            For Each dr As DataRow In dt.Rows
                dr("Edit") = "<i class=""fa fa-edit""></i>"
            Next
            strTD_edit = " width=""50px"" align=""center"""
        End If
        'fa fa-edit

        Dim strData As New StringBuilder

        strData.Append("<table class=""table table-bordered table-striped table-hover table-heading table-datatable"" id=" & datatablename & ">")

        'Header
        strData.Append("<thead>")
        strData.Append("<tr>")
        For Each col As DataColumn In dt.Columns
            strData.Append("<th>" & col.ColumnName)
            strData.Append("</th>")
        Next
        strData.Append("</tr>")
        strData.Append("</thead>")
        ' End Header
        'Detail
        strData.Append("<tbody>")
        For Each dr As DataRow In dt.Rows
            strData.Append("<tr>")
            For Each col As DataColumn In dt.Columns
                If col.ColumnName = "Edit" Then
                    strData.Append("<td " & strTD_edit & ">" & dr(col.ColumnName))
                    strData.Append("</td>")
                Else
                    strData.Append("<td>" & dr(col.ColumnName))
                    strData.Append("</td>")
                End If

            Next
            strData.Append("</tr>")
        Next
        ' End Detail
        strData.Append("</tbody>")




        strData.Append("</table>")

        Return strData.ToString

    End Function
#End Region

#Region "Convert Json To Datatable"
    Public Shared Function ConvertJSONToDataTable(jsonString As String) As DataTable
        Dim dt As New DataTable
        'strip out bad characters
        Dim jsonParts As String() = jsonString.Replace("[", "").Replace("]", "").Split("},{")

        'hold column names
        Dim dtColumns As New List(Of String)

        'get columns
        For Each jp As String In jsonParts
            'only loop thru once to get column names
            Dim propData As String() = jp.Replace("{", "").Replace("}", "").Split(New Char() {","}, StringSplitOptions.RemoveEmptyEntries)
            For Each rowData As String In propData
                Try
                    Dim idx As Integer = rowData.IndexOf(":")
                    Dim n As String = rowData.Substring(0, idx - 1)
                    Dim v As String = rowData.Substring(idx + 1)
                    If Not dtColumns.Contains(n) Then
                        dtColumns.Add(n.Replace("""", ""))
                    End If
                Catch ex As Exception
                    Throw New Exception(String.Format("Error Parsing Column Name : {0}", rowData))
                End Try

            Next
            Exit For
        Next

        'build dt
        For Each c As String In dtColumns
            dt.Columns.Add(c)
        Next
        'get table data
        For Each jp As String In jsonParts
            Dim propData As String() = jp.Replace("{", "").Replace("}", "").Split(New Char() {","}, StringSplitOptions.RemoveEmptyEntries)
            Dim nr As DataRow = dt.NewRow
            For Each rowData As String In propData
                Try
                    Dim idx As Integer = rowData.IndexOf(":")
                    Dim n As String = rowData.Substring(0, idx - 1).Replace("""", "")
                    Dim v As String = rowData.Substring(idx + 1).Replace("""", "")
                    nr(n) = v
                Catch ex As Exception
                    Continue For
                End Try

            Next
            dt.Rows.Add(nr)
        Next
        Return dt
    End Function
#End Region

End Class


