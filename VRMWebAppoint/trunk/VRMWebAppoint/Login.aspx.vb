Imports LinqDB.ConnectDB
Imports LinqDB.TABLE
Imports System.Data
Imports System.IO

Partial Class Login
    Inherits System.Web.UI.Page

    Protected Sub Login_Click(Source As Object, E As EventArgs)
        If txtUsername.Value = "" Then
            lblshowvalid.InnerText = "Please enter your username"
            'ScriptManager.RegisterStartupScript(Me, Me.GetType, Guid.NewGuid().ToString(), "alert('Please enter your username.');", True)
            Exit Sub
        End If
        If txtPassword.Value = "" Then
            lblshowvalid.InnerText = "Please enter your password"
            'ScriptManager.RegisterStartupScript(Me, Me.GetType, Guid.NewGuid().ToString(), "alert('Please enter your password.');", True)
            Exit Sub
        End If

        Dim dt As New DataTable
        dt = GetDataLogin(txtUsername.Value, txtPassword.Value)
        If dt.Rows.Count > 0 Then
            Session("fullname") = dt.Rows(0)("fullname") & ""
            Session("username") = dt.Rows(0)("username") & ""
            Session("userid") = dt.Rows(0)("id") & ""
            Session("password") = txtPassword.Value 'SqlDB.DeCripPwd(dt.Rows(0)("passwd") & "")

            Response.Redirect("frmMain.aspx")
        Else
            lblshowvalid.InnerText = "User not found!"
            'ScriptManager.RegisterStartupScript(Me, Me.GetType, Guid.NewGuid().ToString(), "onAlert('User not found!');", False)
        End If
    End Sub

    Function GetDataLogin(username As String, password As String) As DataTable
        Try
            Dim EnCripPW As String = SqlDB.EnCripPwd(password)
            Dim dt As DataTable
            Dim strSql As String
            strSql = " select MSU.id,prefix_eng + ' ' + name_eng + ' ' + surname_eng as fullname,username,passwd "
            strSql &= " from MS_USER MSU inner join MS_PREFIX MSP on MSU.ms_prefix_id = MSP.id "
            strSql &= " where username='" & username & "' and passwd='" & EnCripPW & "' and MSU.active_status='Y' "
            dt = SqlDB.ExecuteTable(strSql)
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    Protected Sub Page_Load(sender As Object, e As EventArgs) Handles Me.Load
        Session.Remove("fullname")
        Session.Remove("username")
        Session.Remove("userid")
        Session.Remove("password")
    End Sub
End Class
