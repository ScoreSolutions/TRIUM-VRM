<%@ WebHandler Language="VB" Class="frmAuthorizeGroupGetUser" %>

Imports System
Imports System.Web
Imports System.Data
Imports LinqDB.TABLE
Imports LinqDB.ConnectDB

Public Class frmAuthorizeGroupGetUser : Implements IHttpHandler
    
      Public Sub ProcessRequest(ByVal context As HttpContext) Implements IHttpHandler.ProcessRequest
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            strSql.Append(" select ")
            strSql.Append(" isnull(p.prefix_eng,'') + u.name_eng + ' ' + u.surname_eng as label")
            strSql.Append(" ,u.id")
            strSql.Append(" ,isnull(p.prefix_eng,'') + u.name_eng + ' ' + u.surname_eng as fullname_eng")
            strSql.Append(" ,isnull(p.prefix_thai,'') + u.name_thai + ' ' + u.surname_thai as fullname_thai")
            strSql.Append(" from  ms_user  u")
            strSql.Append(" inner join ms_prefix p")
            strSql.Append(" on u.id_prefix = p.id")
            strSql.Append(" where u.active_status='Y'  and u.id not in(select id_ms_user from ts_authorizegroup_user) ")
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