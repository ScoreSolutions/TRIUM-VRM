Imports System.Data
Imports LinqDB.ConnectDB

Partial Class Controls_ucLeftMainMenu
    Inherits System.Web.UI.UserControl

#Region "Declare Class & Variable"
    Private dtMenu As DataTable
    Private dvMainMenu, dvMinorMenu, dvSubMenu, dvSubSubMenu As DataView
    Private strDefaultImageCssName As String = "icon-folder-close"
    Private strNavigateURL, strScreenName, strImageCssName, strLinkExternal As String
    Private intRowID As Long
    Protected strside_accordion As String
#End Region

#Region "Declare Property"


    Private ReadOnly Property ppRowIDMenu() As Integer
        Get
            Return Val(Request.Params("RowIDMenu") & "")
        End Get
    End Property
#End Region

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        RenderMenu()
    End Sub

#Region "Render Menu"
    Private Sub RenderMenu() 'เมนูรองรับมากสุด 4 level
        Try

            Dim strSql As New StringBuilder
            strSql.Append(" SELECT	Screen.ID,")
            strSql.Append(" Screen.ms_module_id RowID_M_Module,")
            strSql.Append(" Screen.ms_submodule_id RowID_M_SubModule,")
            strSql.Append(" isnull(Module.ModuleName,'') ModuleName,")
            strSql.Append(" isnull(SubModule.Name,'') SubModuleName,")
            strSql.Append(" isnull(Screen.RowID_RootMenu,0)RowID_RootMenu,")
            strSql.Append(" isnull(Screen.RowID_ParentMenu,0)RowID_ParentMenu,")
            strSql.Append(" isnull(Screen.RowID_SubParentMenu,0)RowID_SubParentMenu,")
            strSql.Append(" Screen.Sequence,")
            strSql.Append(" Screen.ScreenName,")
            strSql.Append(" Screen.ScreenID,")
            strSql.Append(" isnull(Screen.IsMenu,0) IsMenu,")
            strSql.Append(" Screen.NavigateURL,")
            strSql.Append(" Screen.Remark,")
            strSql.Append(" Screen.ImageURL,")
            strSql.Append("(select COUNT(ID) from MS_Screen where (RowID_RootMenu=Screen.ID or RowID_ParentMenu=Screen.ID  or  RowID_SubParentMenu  =Screen.ID ) ) as LevelCheck")
            strSql.Append(" FROM MS_Screen Screen")
            strSql.Append(" LEFT JOIN MS_Module Module")
            strSql.Append(" ON Module.ID = Screen.ms_module_id")
            strSql.Append(" LEFT JOIN MS_SubModule SubModule")
            strSql.Append(" ON SubModule.ID = Screen.ms_submodule_id where isnull(isnotuse,0) = 0 ")
            strSql.Append(" and Screen.ID in (select distinct id_ms_screen from TS_AUTHORIZEGROUP_MENU where id_ms_authorizegroup in")
            strSql.Append(" (select id_ms_authorizegroup from TS_AUTHORIZEGROUP_USER where id_ms_user='" & Session("userid") & "')) ")
            strSql.Append(" order by Screen.Sequence ")

            dtMenu = SqlDB.ExecuteTable(strSql.ToString)

            ''Make Data
            'Dim dt As New DataTable
            'Dim dr As DataRow

            'dt.Columns.Add("ID")
            'dt.Columns.Add("RowId_RootMenu")
            'dt.Columns.Add("Sequence")
            'dt.Columns.Add("LevelCheck")
            'dt.Columns.Add("ScreenName")
            'dt.Columns.Add("NavigateUrl")
            'dt.Columns.Add("ImageURL")
            'dt.Columns.Add("RowId_ParentMenu")
            'dt.Columns.Add("RowId_SubParentMenu")

            'dr = dt.NewRow
            'dr("ID") = 1
            'dr("RowId_RootMenu") = 0
            'dr("Sequence") = 1
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Booking"
            'dr("NavigateUrl") = "frmRequestRoom.aspx"
            'dr("ImageURL") = "icon-time"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)


            'dr = dt.NewRow
            'dr("ID") = 2
            'dr("RowId_RootMenu") = 0
            'dr("Sequence") = 3
            'dr("LevelCheck") = 1
            'dr("ScreenName") = "Setting"
            'dr("NavigateUrl") = ""
            'dr("ImageURL") = "icon-lock"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 3
            'dr("RowId_RootMenu") = 2
            'dr("Sequence") = 1
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Black List"
            'dr("NavigateUrl") = "frmBlackList.aspx"
            'dr("ImageURL") = "icon-lock"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)



            'dr = dt.NewRow
            'dr("ID") = 4
            'dr("RowId_RootMenu") = 0
            'dr("Sequence") = 2
            'dr("LevelCheck") = 1
            'dr("ScreenName") = "Report"
            'dr("NavigateUrl") = ""
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 5
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 1
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Booking meeting room report by daily"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 6
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 2
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Booking meeting room report by monthly"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 7
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 3
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Booking meeting room Report by room type"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 8
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 4
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Blacklist 'list name report"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 9
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 5
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Visitor report by daily"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 10
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 6
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Visitor report by monthly"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 11
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 7
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Booking meeting room by department"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)

            'dr = dt.NewRow
            'dr("ID") = 12
            'dr("RowId_RootMenu") = 4
            'dr("Sequence") = 7
            'dr("LevelCheck") = 0
            'dr("ScreenName") = "Booking meeting room by personal"
            'dr("NavigateUrl") = "#"
            'dr("ImageURL") = "icon-book"
            'dr("RowId_ParentMenu") = 0
            'dr("RowId_SubParentMenu") = 0
            'dt.Rows.Add(dr)



            'dt.AcceptChanges()

            Dim strMenu As New StringBuilder
            'dtMenu = dt.Copy
            dvMainMenu = dtMenu.Copy.DefaultView
            dvMainMenu.RowFilter = "RowId_RootMenu = 0"
            dvMainMenu.Sort = "Sequence"
            strMenu.Append("<ul class=""nav nav-list"">")

            For i As Integer = 0 To dvMainMenu.Count - 1

                Select Case dvMainMenu(i)("LevelCheck") & ""
                    Case 0 'กรณีมี Root เดียว
                        'Level 1
                        strScreenName = dvMainMenu(i)("ScreenName") & ""
                        strNavigateURL = dvMainMenu(i)("NavigateUrl") & "?RowIDMenu=" & dvMainMenu(i)("id")
                        strImageCssName = dvMainMenu(i)("ImageURL") & ""

                        strMenu.Append("<li " & IIf(dvMainMenu(i)("ID") = ppRowIDMenu, "class=""active""", "") & " >")
                        strMenu.Append("<a href=" & IIf(strNavigateURL <> "", strNavigateURL, "#") & " >")
                        strMenu.Append("<i class=" & strImageCssName & "></i>")
                        strMenu.Append("<span class=""menu-text"">" & strScreenName & " </span>")
                        strMenu.Append("</a>")
                        strMenu.Append("</li>")
                    Case Else 'กรณีมีหลาย Root 
                        'Level 1
                        strScreenName = dvMainMenu(i)("ScreenName") & ""
                        strNavigateURL = dvMainMenu(i)("NavigateUrl") & "?RowIDMenu=" & dvMainMenu(i)("ID")
                        strImageCssName = dvMainMenu(i)("ImageURL") & ""

                        strMenu.Append("<li " & IIf(dvMainMenu(i)("ID") = ppRowIDMenu, "class=""active""", "") & " >")
                        ' strMenu.Append("<li>")
                        strMenu.Append("<a href=""#"" class=""dropdown-toggle"">")
                        strMenu.Append("<i class=" & strImageCssName & "></i>")
                        strMenu.Append("<span class=""menu-text"">" & strScreenName & " </span>")
                        strMenu.Append("<b class=""arrow icon-angle-down""></b>")
                        strMenu.Append("</a>")
                        'Level 2
                        dvMinorMenu = dtMenu.Copy.DefaultView
                        dvMinorMenu.RowFilter = "RowId_ParentMenu = 0  AND RowId_RootMenu = " & dvMainMenu(i)("Id")
                        dvMinorMenu.Sort = "Sequence"
                        If dvMinorMenu.Count > 0 Then
                            strMenu.Append("<ul class=""submenu"">")
                            For j As Integer = 0 To dvMinorMenu.Count - 1 'Level 2
                                intRowID = dvMinorMenu(j)("ID")
                                strScreenName = dvMinorMenu(j)("ScreenName") & ""
                                strNavigateURL = dvMinorMenu(j)("NavigateUrl") & "?RowIDMenu=" & dvMainMenu(i)("ID")
                                strImageCssName = dvMinorMenu(j)("ImageURL") & ""

                                dvSubMenu = dtMenu.Copy.DefaultView
                                dvSubMenu.RowFilter = "RowId_SubParentMenu=0 AND RowId_RootMenu = " & dvMinorMenu(j)("RowId_RootMenu") & " AND RowId_ParentMenu = " & intRowID
                                dvSubMenu.Sort = "Sequence"
                                If dvSubMenu.Count > 0 Then


                                    strMenu.Append("<li>")
                                    strMenu.Append("<a href=""#"" class=""dropdown-toggle"">")
                                    strMenu.Append("<i class=""icon-double-angle-right""></i>")
                                    strMenu.Append(strScreenName)
                                    strMenu.Append("<b class=""arrow icon-angle-down""></b>")
                                    strMenu.Append("</a>")
                                    strMenu.Append("<ul class=""submenu"">")
                                    For k As Integer = 0 To dvSubMenu.Count - 1   ' Level 3

                                        intRowID = dvSubMenu(k)("ID")
                                        strScreenName = dvSubMenu(k)("ScreenName") & ""
                                        strNavigateURL = dvSubMenu(k)("NavigateUrl") & "?RowIDMenu=" & dvMainMenu(i)("ID")
                                        strImageCssName = dvSubMenu(k)("ImageURL") & ""
                                        dvSubSubMenu = dtMenu.Copy.DefaultView
                                        dvSubSubMenu.RowFilter = "RowId_RootMenu = " & dvSubMenu(k)("RowId_RootMenu") & " AND RowId_ParentMenu=" & dvSubMenu(k)("RowId_ParentMenu") & "  AND RowId_SubParentMenu = " & intRowID
                                        dvSubSubMenu.Sort = "Sequence"
                                        If dvSubSubMenu.Count > 0 Then
                                            strMenu.Append("<li>")
                                            strMenu.Append("<a href=""#"" class=""dropdown-toggle"">")
                                            strMenu.Append("<i class=" & strImageCssName & "></i>")
                                            strMenu.Append(strScreenName)
                                            strMenu.Append("<b class=""arrow icon-angle-down""></b>")
                                            strMenu.Append("</a>")
                                            strMenu.Append("<ul class=""submenu"">")
                                            For L As Integer = 0 To dvSubSubMenu.Count - 1 ' Level 4
                                                strScreenName = dvSubSubMenu(L)("ScreenName") & ""
                                                strNavigateURL = dvSubSubMenu(L)("NavigateUrl") & "?RowIDMenu=" & dvMainMenu(i)("ID")
                                                strImageCssName = dvSubSubMenu(L)("ImageURL") & ""

                                                ' strMenu.Append("<li " & IIf(dvSubSubMenu(L)("ID") = ppRowIDMenu, "class=""active""", "") & " >")
                                                strMenu.Append("<li>")
                                                strMenu.Append("<a href=" & IIf(strNavigateURL <> "", strNavigateURL, "#") & " >")
                                                strMenu.Append("<i class=" & strImageCssName & "></i>")
                                                strMenu.Append(strScreenName)
                                                strMenu.Append("</a>")
                                                strMenu.Append("</li>")

                                            Next
                                            strMenu.Append("</ul>")
                                            strMenu.Append("</li>")
                                        Else
                                            ' strMenu.Append("<li " & IIf(dvSubMenu(k)("ID") = ppRowIDMenu, "class=""active""", "") & " >")
                                            strMenu.Append("<li>")
                                            strMenu.Append("<a href=" & IIf(strNavigateURL <> "", strNavigateURL, "#") & " >")
                                            strMenu.Append("<i class=" & strImageCssName & "></i>")
                                            strMenu.Append(strScreenName)
                                            strMenu.Append("</a>")
                                            strMenu.Append("</li>")
                                        End If


                                    Next
                                    strMenu.Append("</ul>")
                                    strMenu.Append("</li>")

                                Else

                                    strMenu.Append("<li " & IIf(dvMinorMenu(j)("ID") = ppRowIDMenu, "class=""active""", "") & " >")
                                    strMenu.Append("<a href=" & IIf(strNavigateURL <> "", strNavigateURL, "#") & " >")
                                    strMenu.Append("<i class=" & strImageCssName & "></i>")
                                    strMenu.Append(strScreenName)
                                    strMenu.Append("</a>")
                                    strMenu.Append("</li>")
                                End If


                            Next
                            strMenu.Append("</ul>")
                        End If
                        strMenu.Append("</li>")
                End Select
            Next
            strMenu.Append("</ul>")

            strside_accordion = strMenu.ToString
        Catch ex As Exception
            ex.Message.ToString()
        End Try
    End Sub
#End Region



#Region "Get Datatable Menu"

#End Region

End Class
