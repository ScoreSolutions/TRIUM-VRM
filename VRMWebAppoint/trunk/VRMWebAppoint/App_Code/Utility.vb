Imports System.Data
Namespace Utility
    Public Class ManageFileAndFolder
#Region "ManageFile"
        Public Shared Function FileExists(ByVal FileFullPath As String) _
         As Boolean
            Dim f As New IO.FileInfo(FileFullPath)
            Return f.Exists

        End Function

        Public Shared Function FolderExists(ByVal FolderPath As String) _
       As Boolean
            Dim f As New IO.DirectoryInfo(FolderPath)
            Return f.Exists
        End Function
        Public Shared Sub DeleteFile(ByVal strName As String)
            Dim fi As New System.IO.FileInfo(strName)
            If fi.Exists Then
                fi.Delete()
            End If
        End Sub
#End Region

    End Class

    Public Class UtilityCheckId
#Region "CheckPageQueryString"
        Public Shared Function CheckRowID(ByVal strValue As String, _
     Optional ByVal strDefaultValue As String = "") As String
            If Len(Trim(strValue & "")) = 0 Then
                CheckRowID = strDefaultValue
            Else
                CheckRowID = strValue
            End If

        End Function
        Public Shared Function CheckPage(ByVal strValue As String, _
    Optional ByVal strDefaultValue As String = "") As String
            If Len(Trim(strValue & "")) = 0 Then
                CheckPage = strDefaultValue
            Else
                CheckPage = strValue
            End If

        End Function
#End Region

    End Class

    Public Class Misc


        Public Shared Function ReplaceHTMLTag(ByVal strInputText As String) As String

            Dim strTextWithoutHtml As String

            strTextWithoutHtml = System.Text.RegularExpressions.Regex.Replace(strInputText, "<[^>]*>|<.*$", "")

            Return strTextWithoutHtml

        End Function

        Public Shared Function MatchEval(ByVal match As Match) As String
            If match.Groups(1).Success Then

                Return "<span class=""R"">" & match.ToString() & "</span>"
            End If

            'no match 
            Return ""
        End Function

        Public Shared Function HighlightKeywords(ByVal keywords As String, ByVal text As String) As String
            ' Swap out the ,<space> for pipes and add the braces 
            If Len(keywords) > 0 And Len(text) > 0 Then
                Dim r As New Regex(", ?")
                keywords = "(" & r.Replace(keywords, "|") & ")"

                ' Get ready to replace the keywords 
                r = New Regex(keywords, RegexOptions.Singleline Or RegexOptions.IgnoreCase)

                ' Do the replace 
                Return r.Replace(text, New MatchEvaluator(AddressOf MatchEval))
            Else
                Return text
            End If

        End Function
        Public Shared Function CheckURLPermissionreadonly(ByVal dv As DataView, _
       ByVal strURL As String) As Boolean
            CheckURLPermissionreadonly = False
            Dim DvCheck As New DataView
            DvCheck = dv.ToTable.Copy.DefaultView
            If Not IsNothing(DvCheck) Then
                DvCheck.RowFilter = "REFURL like '%" & strURL & "%'"
                If DvCheck.Count > 0 Then
                    If DvCheck(0)("FlagStatus") > 0 Then
                        CheckURLPermissionreadonly = True
                    End If
                End If
                dv.Dispose()
            End If
            CheckURLPermissionreadonly = False
        End Function




        Public Shared Sub SetPageFooter(ByVal strLanguage As String, _
        ByVal lblTotalPage As Label, _
        ByVal intItemCount As Integer)
            If intItemCount > 0 Then
                If strLanguage.ToLower = "th" Then
                    lblTotalPage.Text = Utility.clsGenMsg.PageCountHeaderTH & " " & intItemCount & " " & Utility.clsGenMsg.PageCountunitTH
                Else
                    lblTotalPage.Text = Utility.clsGenMsg.PageCountHeaderEN & " " & intItemCount & " " & Utility.clsGenMsg.PageCountunitEN
                End If
            Else
                If strLanguage.ToLower = "th" Then
                    lblTotalPage.Text = Utility.clsGenMsg.NotFoundTH
                Else
                    lblTotalPage.Text = Utility.clsGenMsg.NotFoundEN
                End If
            End If
        End Sub

        Public Shared Function GenerateRandomCode() As String
            Dim random As New Random
            Dim s As String = ""
            For i As Integer = 0 To 6
                s = String.Concat(s, random.Next(10).ToString())
            Next
            Return s
        End Function

        Public Shared Sub AddModule(ByVal objPane As Panel, _
                                  ByVal objModule As Control, _
                                  Optional ByVal strAlignment As String = "", _
                                  Optional ByVal strColor As String = "", _
                                  Optional ByVal strBorder As String = "")
            objPane.Controls.Add(objModule)
            objPane.Visible = True
        End Sub

        Public Shared Sub AddModule(ByVal objPane As HtmlTableCell, _
                          ByVal objModule As Control, _
                          Optional ByVal strAlignment As String = "", _
                          Optional ByVal strColor As String = "", _
                          Optional ByVal strBorder As String = "")
            objPane.Controls.Add(objModule)
            objPane.Visible = True
        End Sub
    End Class

    Public Class AddControlHandle
        Public Shared ctrlHTMLTableHide As System.Web.UI.HtmlControls.HtmlTable
        Public Shared Property _ctrlHTMLTableHide() As System.Web.UI.HtmlControls.HtmlTable
            Get
                Return ctrlHTMLTableHide
            End Get
            Set(ByVal value As System.Web.UI.HtmlControls.HtmlTable)
                ctrlHTMLTableHide = value
            End Set
        End Property
        Public Shared Sub AddHandlebtnHide(ByVal objImageButton As ImageButton, _
                                           ByVal objHTMLTable As System.Web.UI.HtmlControls.HtmlTable)
            _ctrlHTMLTableHide = objHTMLTable
            AddHandler objImageButton.Click, AddressOf btnimghide_Click
        End Sub
        Public Shared Sub btnimghide_Click(ByVal sender As Object, ByVal e As System.Web.UI.ImageClickEventArgs)
            If ctrlHTMLTableHide.Style.Item("Display") = "" Then
                sender.ImageUrl = "~/Asset/Icons/ShowSearch.png"
                ctrlHTMLTableHide.Style.Item("Display") = "none"
            Else
                sender.ImageUrl = "~/Asset/Icons/HideSearch.png"
                ctrlHTMLTableHide.Style.Item("Display") = ""
            End If
        End Sub
      
    End Class



#Region "GenerateScript"
    Public Class GenerateScript

        Public Shared Sub Msg(ByVal Page As Object, ByVal Massage As String, _
         Optional ByVal strScript As String = "")
            If Len(strScript) > 0 Then
                strScript = "window.location.href='" & strScript & "';"
            End If
            Page.ClientScript.RegisterClientScriptBlock(Page.GetType, "Onload", "<script>alert('" & Massage & "');" & strScript & "</script>", False)
        End Sub
        Public Shared Sub GenScript(ByVal Page As Object, Optional ByVal strScript As String = "")
            Page.ClientScript.RegisterClientScriptBlock(Page.GetType, "Onload", "<script>" & strScript & "</script>", False)
        End Sub
        Public Shared Sub GenScriptAjax(ByVal Page As Object, Optional ByVal strScript As String = "")
            ScriptManager.RegisterClientScriptBlock(Page, Page.GetType, "Onload", "<script>" & strScript & "</script>", False)
        End Sub
        Public Shared Sub MsgRefresh(ByVal Page As Object, ByVal Massage As String, ByVal PageRefresh As String)
            ScriptManager.RegisterClientScriptBlock(Page, Page.GetType, "Onload", "<script>alert('" & Massage & "');self.opener.location='" & PageRefresh & "';window.close();</script>", False)
        End Sub
        Public Shared Sub MsgAjax(ByVal Page As Object, ByVal Massage As String, _
           Optional ByVal strScript As String = "")
            If Len(strScript) > 0 Then
                strScript = "window.location.href='" & strScript & "';"
            End If
            ScriptManager.RegisterClientScriptBlock(Page, Page.GetType, "Onload", "<script>alert('" & Massage & "');" & strScript & "</script>", False)
        End Sub

        Public Shared Sub WindowClose(ByVal Page As Object, ByVal RefreshOpener As Boolean)
            Dim strScript As String = ""
            If RefreshOpener Then
                strScript = "self.opener.location = self.opener.location;"
            End If
            ScriptManager.RegisterClientScriptBlock(Page, Page.GetType, "closerefresh", strScript & "window.close();", True)
        End Sub

        Public Shared Sub MsgAjaxWithScript(ByVal Page As Object, ByVal Massage As String, _
              Optional ByVal strScript As String = "")
            ScriptManager.RegisterClientScriptBlock(Page, Page.GetType, "Onload", "<script>alert('" & Massage & "');" & strScript & "</script>", False)
        End Sub
        Public Shared Sub MsgAjaxCloseRadWindow(ByVal Page As Object, _
                                                Optional ByVal Massage As String = "", _
                                                Optional ByVal StrScript As String = "")
            If Len(Massage) > 0 Then
                Massage = "alert('" & Massage & "');"
            End If
            ScriptManager.RegisterClientScriptBlock(Page, Page.GetType, "Onload", "<script>" & Massage & "  if (window.radWindow) oWindow = window.radWindow; else if (window.frameElement.radWindow) oWindow = window.frameElement.radWindow;oWindow.close();</script>", False)
        End Sub

        Public Shared Function genTagFlash(ByVal strFileName As String, ByVal intwidth As Integer, ByVal intheight As Integer) As String
            Dim sbgenTagFlash1 As StringBuilder = New StringBuilder()
            sbgenTagFlash1.Append("<object classid=""clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"" " & vbCrLf)
            sbgenTagFlash1.Append("codebase=""http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=7,0,19,0"" width=""" & intwidth & """ height=""" & intheight & """>" & vbCrLf)
            sbgenTagFlash1.Append("<param name=""movie"" value=""" & strFileName & """ >" & vbCrLf)
            sbgenTagFlash1.Append("<param name=""wmode"" value=""opaque"" />" & vbCrLf)
            sbgenTagFlash1.Append("<param name=""wmode"" value=""Transparent"" />" & vbCrLf)
            sbgenTagFlash1.Append("<param name=""quality"" value=""high"">" & vbCrLf)
            sbgenTagFlash1.Append("<embed src=""" & strFileName & """ wmode=""opaque"" wmode=""Transparent"" quality=""high"" " & vbCrLf)
            sbgenTagFlash1.Append("pluginspage=""http://www.macromedia.com/go/getflashplayer"" type=""application/x-shockwave-flash"" " & vbCrLf)
            sbgenTagFlash1.Append("width=""" & intwidth & """ height=""" & intheight & """></embed></object>" & vbCrLf)
            Return sbgenTagFlash1.ToString
        End Function

#Region "InfoBar"

        Public Shared Sub InfoBar(ByVal Page As Object, ByVal Massage As String, _
                                 Optional ByVal infoType As String = "1", _
                                 Optional ByVal strScript As String = "")

            Dim strInfoBarScript As String = ""
            Dim strInfoIcon As String = ""

            If Len(strScript) > 0 Then
                strScript = "window.location.href='" & strScript & "';"
            End If
            Select Case infoType
                Case "1" '=== Infomations
                    strInfoIcon = "information.png"
                Case "2" '=== Warning / Exclamination
                    strInfoIcon = "exclamation.png"
                Case "3" '=== Error
                    strInfoIcon = "error.png"
                Case "4"
                    strInfoIcon = "help.png"
                Case Else
                    strInfoIcon = "information.png"
            End Select
            strInfoBarScript = "bar = new infoBar({text: '" & Massage & "'});" & _
                   "bar.setIcon('" & Page.ResolveUrl("~/js/InfoIcon/" & strInfoIcon).ToString.Replace(".png", "") & "'); " & _
                   "bar.showAutoHide(125); "

            Page.ClientScript.RegisterClientScriptBlock(Page, Page.GetType, "Onload", "<script>" & strInfoBarScript & strScript & "</script>", False)


        End Sub


        Public Shared Sub InfoBarAjax(ByVal Page As Object, ByVal Massage As String, _
                                      Optional ByVal infoType As String = "1", _
                                      Optional ByVal strScript As String = "")
            Dim strInfoBarScript As String = ""
            Dim strInfoIcon As String = ""

            If Len(strScript) > 0 Then
                strScript = "window.location.href='" & strScript & "';"
            End If

            Select Case infoType
                Case "1" '=== Infomations
                    strInfoIcon = "information.png"
                Case "2" '=== Warning / Exclamination
                    strInfoIcon = "exclamation.png"
                Case "3" '=== Error
                    strInfoIcon = "error.png"
                Case "4"
                    strInfoIcon = "help.png"
                Case Else
                    strInfoIcon = "information.png"
            End Select
            strInfoBarScript = "bar = new infoBar({text: '" & Massage & "'});" & _
                             "bar.setIcon('" & Page.ResolveUrl("~/js/InfoIcon/" & strInfoIcon).ToString.Replace(".png", "") & "'); " & _
                             "bar.showAutoHide(125); "

            ScriptManager.RegisterClientScriptBlock(Page, Page.GetType, "Onload", "<script>" & strInfoBarScript & strScript & "</script>", False)
        End Sub


#End Region

    End Class
#End Region

#Region "cls Gen Msg"
    Public Class clsGenMsg
        Public Shared Function GenMsgAccessDenide() As String
            Return "�س������Է�����ҹ���ǹ��� !"
        End Function

        Public Shared Function GenMsgAddCompleted() As String
            Return "�������������º��������"
        End Function
        Public Shared Function GenMsgConfirmSave() As String
            Return "��س��׹�ѹ��úѹ�֡������"
        End Function
        Public Shared Function GenMsgConfirmDelete() As String
            Return "��س��׹�ѹ���ź������"
        End Function

        Public Shared Function GenMsgConfirmReset() As String
            Return "��س��׹�ѹ���������Ѻ����"
        End Function

        Public Shared Function GenMsgConfirmClear() As String
            Return "��س��׹�ѹ��������������"
        End Function

        Public Shared Function GenMsgConfirmCancel() As String
            Return "��س��׹�ѹ���¡��ԡ������"
        End Function

        Public Shared Function GenMsgCancelCompleted() As String
            Return "¡��ԡ���º��������"
        End Function
        Public Shared Function GenMsgCancelFailed() As String
            Return "¡��ԡ�Դ��Ҵ"
        End Function


        Public Shared Function GenMsgCopyCompleted() As String
            Return "�Ѵ�͡���������º��������"
        End Function

        Public Shared Function GenMsgCopyFalied() As String
            Return "�Ѵ�͡�����żԴ��Ҵ"
        End Function

        Public Shared Function GenMsgAddFalied() As String
            Return "���������żԴ��Ҵ"
        End Function

        Public Shared Function GenMsgDeleteCompleted() As String
            Return "ź���������º��������"
        End Function

        Public Shared Function GenMsgDeleteFalied() As String
            Return "ź�����żԴ��Ҵ"
        End Function

        Public Shared Function GenMsgUpdateCompleted() As String
            Return "��䢢��������º��������"
        End Function

        Public Shared Function GenMsgUpdateFalied() As String
            Return "��䢢����żԴ��Ҵ"
        End Function

        Public Shared Function GenMsgDeleteToday() As String
            Return "�س��ͧ���ź�����Ţͧ�ѹ������������ ?"
        End Function
        Public Shared Function GenMsgDuplicate() As String
            Return " �����ū�� "
        End Function
        Public Shared Function GenMsgSelectDay() As String
            Return "��س����͡�ѹ����ͧ��äѴ�͡������ !"
        End Function

        Public Shared Function GenMsgSaveComplete() As String
            Return "�ѹ�֡���������º��������"
        End Function

        Public Shared Function GenMsgSaveFail() As String
            Return "�ѹ�֡�����żԴ��Ҵ"
        End Function

        Public Shared Function GenMsgSaveCompleted() As String
            Return "�ѹ�֡���������º��������"
        End Function

        Public Shared Function DataExist() As String
            Return "�������ū��"
        End Function
        Public Shared Function GenMsgSendMailCompleted() As String
            Return "���������º��������"
        End Function

        Public Shared Function GenMsgSendMailFalied() As String
            Return "������Դ��Ҵ"
        End Function

        Public Shared Function GenMsgValidFormatInputFile() As String
            Return "��س����͡�Ҿ����� ��Դ jpg, jpeg, gif, png, doc ���� pdf ��ҹ�� "
        End Function

        Public Shared Function GenMsgException() As String
            Return " �Դ��ͼԴ��Ҵ "
        End Function

        Public Shared Function GenMsgNotDelete() As String
            Return "�������öź��������"
        End Function

        Public Shared Function GenMsgSelectRow() As String
            Return "��س����͡�Ǣ��������ҧ���� 1 ��¡�� !"
        End Function

        Public Shared Function PageCountHeaderTH() As String
            Return "������"
        End Function
        Public Shared Function PageCountHeaderEN() As String
            Return "All "
        End Function

        Public Shared Function PageCountunitTH() As String
            Return "��¡��"
        End Function
        Public Shared Function PageCountunitEN() As String
            Return "Items "
        End Function

        Public Shared Function NotFoundTH() As String
            Return "��辺������ "
        End Function
        Public Shared Function NotFoundEN() As String
            Return "Not Found! "
        End Function
        Public Shared Function GenMsgIsUseNotDelete() As String
            Return "�������öź�����������ͧ�ҡ�բ����Ŷ١���¡��ҹ����"
        End Function
        Public Shared Function GenMsgDateBetween() As String
            Return "�ѹ���������鹵�ͧ���¡����ѹ����ش��á�ä���"
        End Function


#Region "About Operator"
        Public Shared Function GenMsgValidMoreThanAndEqual() As String
            Return " ����ҡ����������ҡѺ "
        End Function

        Public Shared Function GenMsgValidLessThanAndEqual() As String
            Return " ��ù��¡���������ҡѺ "
        End Function

        Public Shared Function GenMsgValidMoreThan() As String
            Return " ����ҡ���� "
        End Function

        Public Shared Function GenMsgValidLessThan() As String
            Return " ��ù��¡��� "
        End Function
#End Region

#Region "About Personal & Setup"
        Public Shared Function GenMsgValidUsernameExists() As String
            Return "�����ͼ������"
        End Function

        Public Shared Function GenMsgValidCodeExists() As String
            Return "�����ʫ��"
        End Function

        Public Shared Function GenMsgValidEmpNoExists() As String
            Return "�����ʾ�ѡ�ҹ���"
        End Function

        Public Shared Function GenMsgValidDocNoExists() As String
            Return "���Ţ����͡��ë��"
        End Function

        Public Shared Function GenMsgValidDateConflict() As String
            Return "��ǧ�ѹ����ѭ������äҺ����ǡѹ"
        End Function

        Public Shared Function GenMsgValidateResignExits() As String
            Return "��ѡ�ҹ��������͡����"
        End Function
#End Region

#Region "About Recruiment"
        Public Shared Function GenMsgValidTranferEmployee() As String
            Return "�ӹǹ������Ѻ��ҷӧҹ������ҡ���Ҩӹǹ�ѵ�ҷ���ͧ���"
        End Function

        Public Shared Function GenMsgValidTranferOnlyPassInterview() As String
            Return "�Ѻ��ҷӧҹ��੾�м�����ҹ��������ɳ���ҹ��"
        End Function

        Public Shared Function GenMsgValidMaxPersonalRate() As String
            Return "�ӹǹ�ѵ�ҷ���ͧ����Թ�ѵ�ҡ��ѧ"
        End Function

        Public Shared Function GenMsgValidPersonalRateNotExist() As String
            Return "����ա�ͺ�ѵ�ҡ��ѧ������͡"
        End Function
#End Region

#Region "About NewsLetter"
        Public Shared Function GenMsgValidGroupNameExists() As String
            Return "�����͡�������"
        End Function

        Public Shared Function GenMsgValidSubjectExists() As String
            Return "����Ǣ�͢�����ë��"
        End Function
#End Region


    End Class
#End Region

#Region "DefaultString"
    Public Class DefaultString
        'Constant For Used Default In All Ddl For Organization
        Public Shared cs_DefaultTextDdl As String = "-- Select --"
        Public Shared cs_DefaultTextDdlTH As String = "-- ���͡ --"
        Public Shared cs_DefaultTextDdlTH2 As String = "-- ������ --"
        Public Shared cs_DefaultValueDdl As String = "0"
        Public Shared cs_DefaultValueDdlStr As String = ""
    End Class
#End Region
#Region "DefaultString Return"
    Public Class DefaultStringStatusReturn
        Public Shared complete As String = "YES" '�ѡ�֡�����
        Public Shared fail As String = "NO" '�ѡ�֡��������
        Public Shared duplicate As String = "DUPLICATE" '�����ū��
        Public Shared duplicateUsername As String = "DUPLICATEUSERNAME" '�����ū��
        Public Shared duplicateemployee_code As String = "DUPLICATEEMPLOYEECODE" '�����ū��
    End Class
#End Region
    Public Class ImportantDay
        Public Shared ppSpecialDay As Integer = 0
        Public Shared Property SpecialDay() As Integer
            Get
                Return ppSpecialDay
            End Get
            Set(ByVal value As Integer)
                ppSpecialDay = value
            End Set
        End Property
    End Class

#Region "Image"
    Public Class ImageFunction
        Public Shared Function UnicodeStringToBytes(
    ByVal str As String) As Byte()

            Return System.Text.Encoding.Unicode.GetBytes(str)
        End Function
    End Class
#End Region

#Region "DateFunction"
    Public Class DateFunction

        Public Shared Function GetDateFromText(ByVal strTextDate As String, ByVal strDateFormat As String) As Date
            Try
                Dim c As New Globalization.CultureInfo("en-US")
                c.DateTimeFormat.LongDatePattern = strDateFormat
                GetDateFromText = DateAdd(DateInterval.Year, -543, Date.ParseExact(strTextDate, "D", c))
            Catch ex As Exception
            End Try
        End Function

        Public Shared Function GetDateFromText2(ByVal strTextDate As String, ByVal strDateFormat As String) As String
            Try
                Dim c As New Globalization.CultureInfo("en-US")
                c.DateTimeFormat.LongDatePattern = strDateFormat
                GetDateFromText2 = Format(DateAdd(DateInterval.Year, -543, Date.ParseExact(strTextDate, "D", c)), "yyyyMMdd")
            Catch ex As Exception
            End Try
        End Function

        Public Shared Function GetDateFromTextTH(ByVal strTextDate As String, ByVal strDateFormat As String) As Date
            Try
                Dim c As New Globalization.CultureInfo("th-TH")
                c.DateTimeFormat.LongDatePattern = strDateFormat
                GetDateFromTextTH = DateAdd(DateInterval.Year, +543, Date.ParseExact(strTextDate, "D", c))
            Catch ex As Exception
            End Try
        End Function



        Public Shared Function ConvertDateToShow(ByVal DateTime As Date) As String
            ' DateTime = DateAdd(DateInterval.Year, 543, DateTime)
            ConvertDateToShow = DateTime.ToString("MM/dd/yyyy", System.Globalization.CultureInfo.CreateSpecificCulture("en").DateTimeFormat)
        End Function

        Public Shared Function ConvertDateToShow2(ByVal DateTime As Date) As String
            'DateTime = DateAdd(DateInterval.Year, 543, DateTime)
            ConvertDateToShow2 = DateTime.ToString("dd MMM yyyy", System.Globalization.CultureInfo.CreateSpecificCulture("th").DateTimeFormat)
        End Function
        Public Shared Function ChangeTextDateToNumber(ByVal strValue As String) As String
            ChangeTextDateToNumber = ""
            Select Case strValue
                Case "Jan", "January"
                    ChangeTextDateToNumber = "01"
                Case "Feb", "February"
                    ChangeTextDateToNumber = "02"
                Case "Mar", "March"
                    ChangeTextDateToNumber = "03"
                Case "Apr", "April"
                    ChangeTextDateToNumber = "04"
                Case "May", "May"
                    ChangeTextDateToNumber = "05"
                Case "Jun", "June"
                    ChangeTextDateToNumber = "06"
                Case "Jul", "July"
                    ChangeTextDateToNumber = "07"
                Case "Aug", "August"
                    ChangeTextDateToNumber = "08"
                Case "Sep", "September"
                    ChangeTextDateToNumber = "09"
                Case "Oct", "October"
                    ChangeTextDateToNumber = "10"
                Case "Nov", "November"
                    ChangeTextDateToNumber = "11"
                Case "Dec", "December"
                    ChangeTextDateToNumber = "12"
            End Select
        End Function
        Public Shared Function ChangeNumberToTextDateFullThai(ByVal strValue As String) As String
            ChangeNumberToTextDateFullThai = ""
            Select Case CInt(strValue)
                Case "1"
                    ChangeNumberToTextDateFullThai = "���Ҥ�"
                Case "2"
                    ChangeNumberToTextDateFullThai = "����Ҿѹ��"
                Case "3"
                    ChangeNumberToTextDateFullThai = "�չҤ�"
                Case "4"
                    ChangeNumberToTextDateFullThai = "����¹"
                Case "5"
                    ChangeNumberToTextDateFullThai = "����Ҥ�"
                Case "6"
                    ChangeNumberToTextDateFullThai = "�Զع�¹"
                Case "7"
                    ChangeNumberToTextDateFullThai = "�á�Ҥ�"
                Case "8"
                    ChangeNumberToTextDateFullThai = "�ԧ�Ҥ�"
                Case "9"
                    ChangeNumberToTextDateFullThai = "�ѹ��¹"
                Case "10"
                    ChangeNumberToTextDateFullThai = "���Ҥ�"
                Case "11"
                    ChangeNumberToTextDateFullThai = "��Ȩԡ�¹"
                Case "12"
                    ChangeNumberToTextDateFullThai = "�ѹ�Ҥ�"
            End Select
        End Function
        Public Shared Function ChangeNumberToTextDateFull(ByVal strValue As String) As String
            ChangeNumberToTextDateFull = ""
            Select Case CInt(strValue)
                Case "1"
                    ChangeNumberToTextDateFull = "January"
                Case "2"
                    ChangeNumberToTextDateFull = "February"
                Case "3"
                    ChangeNumberToTextDateFull = "March"
                Case "4"
                    ChangeNumberToTextDateFull = "April"
                Case "5"
                    ChangeNumberToTextDateFull = "May"
                Case "6"
                    ChangeNumberToTextDateFull = "June"
                Case "7"
                    ChangeNumberToTextDateFull = "July"
                Case "8"
                    ChangeNumberToTextDateFull = "August"
                Case "9"
                    ChangeNumberToTextDateFull = "September"
                Case "10"
                    ChangeNumberToTextDateFull = "October"
                Case "11"
                    ChangeNumberToTextDateFull = "November"
                Case "12"
                    ChangeNumberToTextDateFull = "December"
            End Select
        End Function
        Public Shared Function ChangeNumberToTextDate(ByVal strValue As String) As String
            ChangeNumberToTextDate = ""
            Select Case CInt(strValue)
                Case "1"
                    ChangeNumberToTextDate = "Jan"
                Case "2"
                    ChangeNumberToTextDate = "Feb"
                Case "3"
                    ChangeNumberToTextDate = "Mar"
                Case "4"
                    ChangeNumberToTextDate = "Apr"
                Case "5"
                    ChangeNumberToTextDate = "May"
                Case "6"
                    ChangeNumberToTextDate = "Jun"
                Case "7"
                    ChangeNumberToTextDate = "Jul"
                Case "8"
                    ChangeNumberToTextDate = "Aug"
                Case "9"
                    ChangeNumberToTextDate = "Sep"
                Case "10"
                    ChangeNumberToTextDate = "Oct"
                Case "11"
                    ChangeNumberToTextDate = "Nov"
                Case "12"
                    ChangeNumberToTextDate = "Dec"
            End Select
        End Function
    End Class
#End Region
End Namespace
