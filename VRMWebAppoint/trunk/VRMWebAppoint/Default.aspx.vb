
Partial Class _Default
    Inherits System.Web.UI.Page

    Protected Sub form1_Load(sender As Object, e As EventArgs) Handles form1.Load
        Session.Abandon()
        Response.Redirect("Login.aspx")
    End Sub
End Class
