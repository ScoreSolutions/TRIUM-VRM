<%@ WebHandler Language="VB" Class="frmBlackList" %>

Imports System
Imports System.Web
Imports System.Data
Imports LinqDB.TABLE


Public Class frmBlackList : Implements IHttpHandler
    
    Public Sub ProcessRequest(ByVal context As HttpContext) Implements IHttpHandler.ProcessRequest
        Try
            
            Dim clsTsVisitorLinqDB As New TsVisitorLinqDB
            Dim sql As String
            
            sql = " select ROW_NUMBER() OVER(ORDER BY V.id asc) AS No,V.ID_CardNo as CardNo,V.ID"
            sql += " ,First_name_th + ' ' + Last_Name_TH as FullName_TH"
            sql += " ,First_name_EN + ' ' + Last_Name_EN as FullName_EN"
            sql += " ,V.Address  "
            sql += " ,(select case "
            sql += " when isnull(V.ID_CardNo,'') =  ''  then ''"
            sql += " else 'checked' end) "
            sql += " as IsBlacklist"
            sql += " ,(select case "
            sql += " when isnull(V.ID_CardNo,'') =  ''  then 'false'"
            sql += " else 'true' end) "
            sql += " as BlaklistStatus"
            sql += " from TS_VISITOR V"
            sql += " LEFT JOIN TS_Blacklist B"
            sql += " ON V.id = B.tb_visitor_id Order by V.ID_CardNo"
            Dim dt As DataTable = clsTsVisitorLinqDB.GetListBySql(sql, Nothing)
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