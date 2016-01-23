<%@ WebHandler Language="VB" Class="frmAuthorizeGroupGetGroupData" %>

Imports System
Imports System.Web
Imports System.Data
Imports LinqDB.TABLE
Imports LinqDB.ConnectDB

Public Class frmAuthorizeGroupGetGroupData : Implements IHttpHandler
    
    Public Sub ProcessRequest(ByVal context As HttpContext) Implements IHttpHandler.ProcessRequest
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            strSql.Append(" SELECT	ROW_NUMBER() OVER(ORDER BY id asc) AS no,(case active_status when 'Y' then 'Active' else 'No Active' end) as active_status_desc ,* FROM MS_AUTHORIZEGROUP   ORDER BY GROUP_NAME") 'isnull(ACTIVE_STATUS,'N')='Y'
            dt = SqlDB.ExecuteTable(strSql.ToString)
            Dim strdata As String = clsdtHelper.ConvertDataTableToJson(dt)
            With context
                .Response.ContentType = "application/json"
                .Response.ContentEncoding = Encoding.UTF8
                .Response.Write(strdata)
                .Response.Flush()
            End With
        Catch ex As Exception
            context.Response.ContentType = "application/json"
            context.Response.ContentEncoding = Encoding.UTF8
            context.Response.Write("[]")
        End Try
    End Sub
 
    Public ReadOnly Property IsReusable() As Boolean Implements IHttpHandler.IsReusable
        Get
            Return False
        End Get
    End Property

End Class