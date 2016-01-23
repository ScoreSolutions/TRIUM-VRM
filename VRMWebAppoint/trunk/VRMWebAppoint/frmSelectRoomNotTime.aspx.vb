Imports LinqDB.ConnectDB
Imports LinqDB.TABLE

Partial Class frmSelectRoomNotTime
    Inherits System.Web.UI.Page
    Protected Sub Page_Load(sender As Object, e As EventArgs) Handles Me.Load
        If Not IsPostBack Then
            Session("IsRunScript") = False
        End If
    End Sub

    Protected Sub btnSearch_ServerClick(sender As Object, e As EventArgs) Handles btnSearch.ServerClick

        If Session("IsRunScript") = False Then
            'Try



            '    Dim ret As Boolean = True
            '    Dim trans As New TransactionDB
            '    Dim clsTbPrebookingLinqDB As New TbPrebookingLinqDB
            '    With clsTbPrebookingLinqDB
            '        .CUSTOMER_NAME = "Mr. Somchi Meedee"
            '        .PURPOSE = Session("purpose") & ""
            '        .MEETING_DATE = txtDate.Value
            '        .MEETING_TIME = timepicker1.Value
            '        .USERID = Val(Session("id") & "")
            '        .LOCATION = GetBuilding(Session("building") & "") & " " & GetRoom(cbRoom.Value)
            '        ret = .InsertData("", trans.Trans)
            '    End With

            '    If ret = True Then
            '        trans.CommitTransaction()
            '        '  Response.Redirect("frmCompletRoom.aspx?id=" & Val(Session("id") & ""))

            '        Dim csname1 As String = "onclick"
            '        Dim csname2 As String = "ButtonClickScript"
            '        Dim cstype As Type = Me.GetType()
            '        Dim cs As ClientScriptManager = Page.ClientScript
            '        Dim cstext1 As String = "NextPage(" & Val(Session("id") & "") & ");"
            '        cs.RegisterStartupScript(cstype, csname1, cstext1, True)
            '        Session("IsRunScript") = True
            '    Else
            '        trans.RollbackTransaction()
            '    End If

            'Catch ex As Exception
            '    Response.Redirect("frmSelectRoomNotTime.aspx")
            'End Try


        End If
    End Sub

    Private Function GetBuilding(id As String) As String
        Return "Building " & id
    End Function
    Private Function GetRoom(id As String) As String
        Return "Metting Room " & id
    End Function

End Class
