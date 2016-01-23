Imports System.Web
Imports System.Web.Services
Imports System.Web.Services.Protocols
Imports LinqDB.ConnectDB
Imports LinqDB.TABLE
Imports System.Data
Imports System.IO
Imports System.Globalization

' To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line.
<System.Web.Script.Services.ScriptService()> _
<WebService(Namespace:="http://tempuri.org/")> _
<WebServiceBinding(ConformsTo:=WsiProfiles.BasicProfile1_1)> _
<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Public Class WebService
    Inherits System.Web.Services.WebService

#Region "Action Table Demo"

    <WebMethod()> _
    Public Function LoadPerson(ByVal RowID As Integer) As Boolean
        Return True
    End Function

    <WebMethod()> _
    Public Function DeleteDemo(ByVal RowID As String) As Boolean
        Try

            Return True
        Catch ex As Exception
            Return False
        End Try
    End Function

#End Region

#Region "Booking"

    <WebMethod()> _
    Public Function SaveBooking(id As String _
                                 , startdate As DateTime _
                                 , enddate As DateTime _
                                 , starttime As String _
                                 , endtime As String _
                                 , room_id As String _
                                 , purpose As String _
                                 , strvisitor As Object _
                                 , active_status As String _
                                 , userid As String) As String

        Try

            'Dim tempstartdate As Date = Date.ParseExact(startdate, "dd/MM/yyyy",
            '           System.Globalization.DateTimeFormatInfo.InvariantInfo)
            'Dim tempenddate As Date = Date.ParseExact(enddate, "dd/MM/yyyy",
            '     System.Globalization.DateTimeFormatInfo.InvariantInfo)
            Dim tempstartdate As Date = startdate
            Dim tempenddate As Date = enddate

            'Dim tempdatetest As Date = Date.Now
            'Dim jsonString As String = strvisitor
            'Dim dtJson As DataTable = clsdtHelper.ConvertJSONToDataTable(jsonString)

            Dim strtempid As String
            Dim ret As Boolean = True
            Dim trans As New TransactionDB


            Dim clsTsPrebookingLinqDB As New TsPrebookingLinqDB

            Dim strSQl As String = ""
            Dim strtemp As String() = startdate.ToString("dd/MM/yyyy").Split("/")
            Dim strday As String = strtemp(0)
            Dim strmonth As String = strtemp(1)
            Dim stryear As String = Val(strtemp(2)) - 543

            Dim dtcheck As DataTable
            Dim strfulldayfrom As String = stryear & "-" & strmonth & "-" & strday & " " & starttime
            Dim strfulldayto As String = stryear & "-" & strmonth & "-" & strday & " " & endtime
            strSQl = "select pb.id from ts_prebooking pb "
            strSQl &= " where id <> " & id & " "
            strSQl &= " and convert(varchar,pb.start_contract_date,103) ='" & startdate & "' "
            strSQl &= " and convert(datetime, '" & strfulldayfrom & "') between pb.start_contract_date and pb.end_contract_date"
            strSQl &= " or convert(datetime, '" & strfulldayto & "') between pb.start_contract_date and pb.end_contract_date"

            With clsTsPrebookingLinqDB
                dtcheck = .GetListBySql(strSQl, trans.Trans)
                If dtcheck.Rows.Count > 0 Then
                    Return "-1" 'data duplicate
                End If
            End With

     
            clsTsPrebookingLinqDB = New TsPrebookingLinqDB
            With clsTsPrebookingLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = False Then
                    .MS_USER_ID_BOOKING = userid
                    .MS_MEETING_ROOM_ID = room_id
                    .PURPOSE = purpose
                    .RESERVE_DATE = Date.Now
                    ' .USE_DATE = tempdatetest
                    .START_CONTRACT_DATE = tempstartdate
                    .END_CONTRACT_DATE = tempenddate
                    .START_CONTRACT_TIME = starttime
                    '  .START_TIME = tempdatetest
                    ' .END_TIME = tempdatetest
                    .END_CONTRACT_TIME = endtime
                    .IS_CONTRACT = "N"
                    .ACTIVE_STATUS = active_status
                    ret = .InsertData(id, trans.Trans)
                Else
                    .MS_USER_ID_BOOKING = userid
                    .MS_MEETING_ROOM_ID = room_id
                    .PURPOSE = purpose
                    .RESERVE_DATE = Date.Now
                    ' .USE_DATE = tempdatetest
                    .START_CONTRACT_DATE = tempstartdate
                    .END_CONTRACT_DATE = tempenddate
                    .START_CONTRACT_TIME = starttime
                    '  .START_TIME = tempdatetest
                    ' .END_TIME = tempdatetest
                    .END_CONTRACT_TIME = endtime
                    .IS_CONTRACT = "N"
                    .ACTIVE_STATUS = active_status
                    ret = .UpdateByPK(id, trans.Trans)
                End If

                strtempid = .ID

            End With


            'dtJson.Rows.RemoveAt(dtJson.Rows.Count - 1)
            'dtJson.AcceptChanges()

            'Dim dttemp As DataTable
            'Dim clsTsPrebookingVisitorLinqDB As New TsPrebookingVisitorLinqDB

            'ret = SqlDB.ExecuteNonQuery("DELETE TS_PREBOOKING_VISITOR WHERE TS_PREBOOKING_ID=" & strtempid)

            'For i As Integer = 0 To dtJson.Rows.Count - 1
            '    clsTsPrebookingVisitorLinqDB = New TsPrebookingVisitorLinqDB
            '    With clsTsPrebookingVisitorLinqDB
            '        dttemp = .GetDataList("id_cardno=" & dtJson(i)("id_cardno") & " and ts_prebooking_id=" & strtempid, "", trans.Trans)
            '        If dttemp.Rows.Count > 0 Then
            '            .GetDataByPK(dttemp(0)("id"), trans.Trans)
            '            .ID_CARDNO = dtJson(i)("id_cardno")
            '            .TS_PREBOOKING_ID = strtempid
            '            .VISITOR_NAME = dtJson(i)("visitor_name")
            '            .VISITOR_COMPANY_NAME = dtJson(i)("visitor_company_name")
            '            ret = .UpdateByPK(userid, trans.Trans)
            '        Else
            '            .ID_CARDNO = dtJson(i)("id_cardno")
            '            .TS_PREBOOKING_ID = strtempid
            '            .VISITOR_NAME = dtJson(i)("visitor_name")
            '            .VISITOR_COMPANY_NAME = dtJson(i)("visitor_company_name")
            '            ret = .InsertData(userid, trans.Trans)
            '        End If
            '    End With
            'Next

            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If
            Return strtempid
        Catch ex As Exception
            Return "0"
        End Try
        'Try
        '    Dim ret As Boolean = True
        '    Dim trans As New TransactionDB
        'Dim clsTsPrebookingLinqDB As New TsPrebookingLinqDB
        'With clsTsPrebookingLinqDB
        '    .MS_USER_ID_BOOKING = id
        '    .MS_MEETING_ROOM_ID = section_id
        '    .PURPOSE = purpose
        '    .RESERVE_DATE = Date.Now
        '    .USE_DATE = start_date
        '    .START_TIME = start_date
        '    .END_TIME = end_date
        '    ret = .InsertData(id, trans.Trans)
        'End With

        'If ret = True Then
        '    trans.CommitTransaction()
        'Else
        '    trans.RollbackTransaction()
        'End If
        'Return ret
        'Catch ex As Exception
        '    Return False
        'End Try
    End Function

    <WebMethod()> _
    Public Function SaveBookingFromEdit(id As String _
                                 , startdate As String _
                                 , enddate As String _
                                 , starttime As String _
                                 , endtime As String _
                                 , room_id As String _
                                 , purpose As String _
                                 , strvisitor As Object _
                                 , active_status As String _
                                 , userid As String) As String
        Try

            Dim tempstartdate As Date = Date.ParseExact(startdate, "dd/MM/yyyy",
                       System.Globalization.DateTimeFormatInfo.InvariantInfo)
            Dim tempenddate As Date = Date.ParseExact(enddate, "dd/MM/yyyy",
                 System.Globalization.DateTimeFormatInfo.InvariantInfo)

            Dim tempdatetest As Date = Date.Now
            Dim jsonString As String = strvisitor
            Dim dtJson As DataTable = clsdtHelper.ConvertJSONToDataTable(jsonString)

            Dim strtempid As String
            Dim ret As Boolean = True
            Dim trans As New TransactionDB
            Dim clsTsPrebookingLinqDB As New TsPrebookingLinqDB

            Dim strSQl As String = ""
            Dim strtemp As String() = startdate.Split("/")
            Dim strday As String = strtemp(0)
            Dim strmonth As String = strtemp(1)
            Dim stryear As String = strtemp(2)

            Dim dtcheck As DataTable
            Dim strfulldayfrom As String = stryear & "-" & strmonth & "-" & strday & " " & starttime
            Dim strfulldayto As String = stryear & "-" & strmonth & "-" & strday & " " & endtime
            strSQl = "select pb.id from ts_prebooking pb "
            strSQl &= " where id <> " & id & " "
            strSQl &= " and convert(varchar,pb.start_contract_date,103) ='" & startdate & "' "
            strSQl &= " and convert(datetime, '" & strfulldayfrom & "') between pb.start_contract_date and pb.end_contract_date"
            strSQl &= " or convert(datetime, '" & strfulldayto & "') between pb.start_contract_date and pb.end_contract_date"

            With clsTsPrebookingLinqDB
                dtcheck = .GetListBySql(strSQl, trans.Trans)
                If dtcheck.Rows.Count > 0 Then
                    Return "-1" 'data duplicate
                End If
            End With

            clsTsPrebookingLinqDB = New TsPrebookingLinqDB

            With clsTsPrebookingLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = False Then
                    .MS_USER_ID_BOOKING = userid
                    .MS_MEETING_ROOM_ID = room_id
                    .PURPOSE = purpose
                    .RESERVE_DATE = Date.Now
                    ' .USE_DATE = tempdatetest
                    .START_CONTRACT_DATE = tempstartdate
                    .END_CONTRACT_DATE = tempenddate
                    .START_CONTRACT_TIME = starttime
                    '  .START_TIME = tempdatetest
                    ' .END_TIME = tempdatetest
                    .END_CONTRACT_TIME = endtime
                    .IS_CONTRACT = "N"
                    .ACTIVE_STATUS = active_status
                    ret = .InsertData(id, trans.Trans)
                Else
                    .MS_USER_ID_BOOKING = userid
                    .MS_MEETING_ROOM_ID = room_id
                    .PURPOSE = purpose
                    .RESERVE_DATE = Date.Now
                    ' .USE_DATE = tempdatetest
                    .START_CONTRACT_DATE = tempstartdate
                    .END_CONTRACT_DATE = tempenddate
                    .START_CONTRACT_TIME = starttime
                    '  .START_TIME = tempdatetest
                    ' .END_TIME = tempdatetest
                    .END_CONTRACT_TIME = endtime
                    .IS_CONTRACT = "N"
                    .ACTIVE_STATUS = active_status
                    ret = .UpdateByPK(id, trans.Trans)
                End If

                strtempid = .ID

            End With


            'dtJson.Rows.RemoveAt(dtJson.Rows.Count - 1)
            'dtJson.AcceptChanges()

            'Dim dttemp As DataTable
            'Dim clsTsPrebookingVisitorLinqDB As New TsPrebookingVisitorLinqDB

            'ret = SqlDB.ExecuteNonQuery("DELETE TS_PREBOOKING_VISITOR WHERE TS_PREBOOKING_ID=" & strtempid)

            'For i As Integer = 0 To dtJson.Rows.Count - 1
            '    clsTsPrebookingVisitorLinqDB = New TsPrebookingVisitorLinqDB
            '    With clsTsPrebookingVisitorLinqDB
            '        dttemp = .GetDataList("id_cardno=" & dtJson(i)("id_cardno") & " and ts_prebooking_id=" & strtempid, "", trans.Trans)
            '        If dttemp.Rows.Count > 0 Then
            '            .GetDataByPK(dttemp(0)("id"), trans.Trans)
            '            .ID_CARDNO = dtJson(i)("id_cardno")
            '            .TS_PREBOOKING_ID = strtempid
            '            .VISITOR_NAME = dtJson(i)("visitor_name")
            '            .VISITOR_COMPANY_NAME = dtJson(i)("visitor_company_name")
            '            ret = .UpdateByPK(userid, trans.Trans)
            '        Else
            '            .ID_CARDNO = dtJson(i)("id_cardno")
            '            .TS_PREBOOKING_ID = strtempid
            '            .VISITOR_NAME = dtJson(i)("visitor_name")
            '            .VISITOR_COMPANY_NAME = dtJson(i)("visitor_company_name")
            '            ret = .InsertData(userid, trans.Trans)
            '        End If
            '    End With
            'Next

            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If
            Return strtempid
        Catch ex As Exception
            Return "0"
        End Try
    End Function

    <WebMethod()> _
    Public Function LoadRoombyContition(attendantfrom As String, _
                                        attendantto As String, _
                                        building_id As String, _
                                        roomtype_id As String, _
                                        stroption_id As String) As String
        Try

            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select r.*")
            strSql.Append(" from ms_meeting_room r")
            strSql.Append(" where r.active_status='Y'")
            If attendantfrom <> "0" Then
                strSql.Append(" and r.seat_qty >=" & attendantfrom)
            End If
            If building_id <> "" Then
                strSql.Append(" and r.ms_building_id=" & building_id)
            End If
            If roomtype_id <> "" Then
                strSql.Append(" and r.ms_room_type_id=" & roomtype_id)
            End If
            If stroption_id <> "" Then
                strSql.Append(" and r.id in(select ms_meeting_room_id from ms_meeting_room_property_item where ms_room_property_id in (" & stroption_id & "))")
            End If
            strSql.Append(" order by r.room_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                Dim strimagebasesrc, strimagebasesrcconvert As String
                Dim dtdetail As New DataTable
                dtdetail.Columns.Add("key")
                dtdetail.Columns.Add("label")
                '  dtdetail.Columns.Add("imagesrc")
                Dim drdetail As DataRow
                For i As Integer = 0 To dt.Rows.Count - 1
                    'Base64 string   convert byte to base64string
                    strimagebasesrc = ""
                    If dt.Rows(i)("room_image_type") & "" <> "" Then
                        strimagebasesrcconvert = "data:image/" & dt.Rows(i)("room_image_type") & ";base64," & Convert.ToBase64String(dt.Rows(i)("room_image"))
                        strimagebasesrc = "<div class='row-fluid'><div class='span12'><img src='" & strimagebasesrcconvert & "' height='180px' width='100%' /></div></div>"
                        strimagebasesrc &= "<div class='row-fluid'><div class='span12'><strong>" & dt.Rows(i)("room_name") & "</strong></div></div>"

                    Else
                        strimagebasesrc = "<div class='row-fluid'><div class='span12'><img src='images/No_image.gif' height='180px' width='100%' /></div></div>"
                        strimagebasesrc &= "<div class='row-fluid'><div class='span12'><strong>" & dt.Rows(i)("room_name") & "</strong></div></div>"

                    End If
                    drdetail = dtdetail.NewRow
                    drdetail("key") = dt.Rows(i)("id")
                    drdetail("label") = strimagebasesrc
                    dtdetail.Rows.Add(drdetail)
                Next
                strdata = clsdtHelper.ConvertDataTableToJson(dtdetail)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadBookingBlockbyContition(strdate As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            strSql.Append(" select")
            strSql.Append(" pb.ms_meeting_room_id as id")
            strSql.Append(" ,day(pb.start_contract_date) as sday")
            strSql.Append(" ,month(pb.start_contract_date) as smonth")
            strSql.Append(" ,year(pb.start_contract_date) as syear")
            strSql.Append(" ,day(pb.end_contract_date) as eday")
            strSql.Append(" ,month(pb.end_contract_date) as emonth")
            strSql.Append(" ,year(pb.end_contract_date) as eyear")
            strSql.Append(" ,cast(left(pb.start_contract_time,2) as int ) as sh")
            strSql.Append(" ,cast(right(pb.start_contract_time,2) as int )as sminute")
            strSql.Append(" ,cast(left(pb.end_contract_time,2) as int ) as eh")
            strSql.Append(" ,cast(right(pb.end_contract_time,2) as int )as eminute")
            strSql.Append(" from ts_prebooking pb ")
            strSql.Append(" where is_contract='N' and convert(varchar(10),pb.start_contract_date,103) ='" & strdate & "'")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            Return clsdtHelper.ConvertDataTableToJson(dt)
        Catch ex As Exception
            Return "[]"
        End Try

    End Function
#End Region

#Region "Authen"
    <WebMethod()> _
    Public Function SaveAuthorizeGroup(strId As String, groupid As String, userid As String) As Boolean
        Try
            Dim trans As New TransactionDB
            Dim ret As Boolean = False
            'Delete Old Data
            ret = SqlDB.ExecuteNonQuery("DELETE FROM TS_AUTHORIZEGROUP_MENU WHERE ID_MS_AUTHORIZEGROUP=" & groupid)

            Dim dtgetallscreen As DataTable = SqlDB.ExecuteTable("select id from ms_screen where id in(" & strId & ")	union select id from ms_screen where id in (select rowid_rootmenu from ms_screen where id in(" & strId & "))")

            'Insert New Data
            Dim clsTsAuthorizegroupMenuLinqDB As New TsAuthorizegroupMenuLinqDB
            '  Dim strTemp() As String = strId.Split(",")
            For i As Integer = 0 To dtgetallscreen.Rows.Count - 1
                If dtgetallscreen.Rows(i)("id") <> 0 Then
                    clsTsAuthorizegroupMenuLinqDB = New TsAuthorizegroupMenuLinqDB
                    With clsTsAuthorizegroupMenuLinqDB
                        .ID_MS_AUTHORIZEGROUP = groupid
                        .ID_MS_SCREEN = dtgetallscreen.Rows(i)("id")
                        ret = .InsertData(userid, trans.Trans)
                        If ret = False Then
                            Exit For
                        End If
                    End With

                    'clsTsAuthorizegroupMenuLinqDB = New TsAuthorizegroupMenuLinqDB
                    'Dim strSQl As New StringBuilder
                    'Dim dtcheck As DataTable
                    'strSQl.Append(" select count(am.id) from ts_authorizegroup_menu am ")
                    'strSQl.Append(" where am.id_ms_authorizegroup =" & groupid)
                    'strSQl.Append(" and am.id_ms_screen in ( ")
                    'strSQl.Append(" select rowid_rootmenu from ms_screen where id =" & strTemp(i) & " ) ")
                    ''dtcheck = clsTsAuthorizegroupMenuLinqDB.GetListBySql(strSQl.ToString, trans.Trans)
                    'dtcheck = SqlDB.ExecuteTable(strSQl.ToString)
                    'If dtcheck.Rows.Count = 0 Then

                    '    'clsTsAuthorizegroupMenuLinqDB = New TsAuthorizegroupMenuLinqDB
                    '    Dim strSQl2 As New StringBuilder
                    '    Dim dtcheck2 As DataTable
                    '    strSQl2.Append(" select rowid_rootmenu from ms_screen where id =" & strTemp(i))
                    '    ' dtcheck2 = clsTsAuthorizegroupMenuLinqDB.GetListBySql(strSQl.ToString, trans.Trans)
                    '    dtcheck2 = SqlDB.ExecuteTable(strSQl2.ToString)
                    '    If dtcheck2.Rows.Count > 0 Then
                    '        clsTsAuthorizegroupMenuLinqDB = New TsAuthorizegroupMenuLinqDB
                    '        With clsTsAuthorizegroupMenuLinqDB
                    '            .ID_MS_AUTHORIZEGROUP = groupid
                    '            .ID_MS_SCREEN = dtcheck2.Rows(0)("rowid_rootmenu") & ""
                    '            ret = .InsertData(userid, trans.Trans)
                    '            If ret = False Then
                    '                Exit For
                    '            End If
                    '        End With
                    '    End If


                    'End If


                End If
            Next

            If ret = False Then
                trans.RollbackTransaction()
            Else
                trans.CommitTransaction()
            End If

            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveGroup(id As String, group_name As String, group_desc As String, userid As String, active As String) As String
        Try
            Dim trans As New TransactionDB
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable
            Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            With clsMsAuthorizegroupLinqDB
                dt = .GetDataList("group_name='" & group_name.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With

            clsMsAuthorizegroupLinqDB = New MsAuthorizegroupLinqDB
            With clsMsAuthorizegroupLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = True Then
                    .GROUP_NAME = group_name
                    .GROUP_DESC = group_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .UpdateByPK(userid, trans.Trans)
                Else
                    .GROUP_NAME = group_name
                    .GROUP_DESC = group_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .InsertData(userid, trans.Trans)
                End If
            End With
            clsMsAuthorizegroupLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveGroupUser(id As String, groupid As String, userid As String) As String
        Try
            Dim trans As New TransactionDB
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable
            Dim clsTsAuthorizegroupUserLinqDB As New TsAuthorizegroupUserLinqDB
            With clsTsAuthorizegroupUserLinqDB
                dt = .GetDataList("id_ms_authorizegroup=" & groupid & " and id_ms_user " & userid, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With

            clsTsAuthorizegroupUserLinqDB = New TsAuthorizegroupUserLinqDB

            With clsTsAuthorizegroupUserLinqDB
                .ID_MS_USER = id
                .ID_MS_AUTHORIZEGROUP = groupid
                ret = .InsertData(userid, trans.Trans)
            End With
            clsTsAuthorizegroupUserLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteGroup(id As String) As Boolean
        Try
            'Dim trans As New TransactionDB
            Dim ret As Boolean = False
            'Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            'With clsMsAuthorizegroupLinqDB
            '    ret = .DeleteByPK(id, trans.Trans)
            'End With
            'clsMsAuthorizegroupLinqDB = Nothing
            ret = SqlDB.ExecuteNonQuery("DELETE FROM TS_AUTHORIZEGROUP_USER WHERE ID_MS_AUTHORIZEGROUP=" & id & ";DELETE FROM TS_AUTHORIZEGROUP_MENU WHERE ID_MS_AUTHORIZEGROUP=" & id & ";DELETE FROM MS_AUTHORIZEGROUP WHERE ID=" & id)
            'If ret = True Then
            '    trans.CommitTransaction()
            'Else
            '    trans.RollbackTransaction()
            'End If

            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteGroupUser(id As String) As Boolean
        Try
            'Dim trans As New TransactionDB
            Dim ret As Boolean = False
            'Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            'With clsMsAuthorizegroupLinqDB
            '    ret = .DeleteByPK(id, trans.Trans)
            'End With
            'clsMsAuthorizegroupLinqDB = Nothing
            ret = SqlDB.ExecuteNonQuery("DELETE FROM TS_AUTHORIZEGROUP_USER WHERE ID=" & id)
            'If ret = True Then
            '    trans.CommitTransaction()
            'Else
            '    trans.RollbackTransaction()
            'End If

            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadAuthorizeGroup(groupid As String) As String
        Try
            'Dim ret As String = ""
            'Dim trans As New TransactionDB
            'Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            'With clsMsAuthorizegroupLinqDB
            '    .GetDataByPK(groupid, trans.Trans)
            '    If .HaveData = True Then
            '        ret = .GROUP_NAME & "," & .GROUP_DESC & "," & .ACTIVE_STATUS
            '    End If
            'End With
            'clsMsAuthorizegroupLinqDB = Nothing
            'trans.CommitTransaction()
            'Return ret
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable("SELECT * FROM MS_AUTHORIZEGROUP WHERE ID=" & groupid)
            Return clsdtHelper.ConvertDataTableToJson(dt)
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function GetAuthorizeGroupMap(groupid As String) As String
        Try
            Dim dt As DataTable
            Dim ret As String = ""
            Dim trans As New TransactionDB
            Dim clsTsAuthorizegroupMenuLinqDB As New TsAuthorizegroupMenuLinqDB
            With clsTsAuthorizegroupMenuLinqDB
                dt = .GetDataList("id_ms_authorizegroup=" & groupid, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    For i As Integer = 0 To dt.Rows.Count - 1
                        If i = 0 Then
                            ret = dt.Rows(i)("id_ms_screen")
                        Else
                            ret &= "," & dt.Rows(i)("id_ms_screen")
                        End If
                    Next
                End If
            End With
            clsTsAuthorizegroupMenuLinqDB = Nothing
            trans.CommitTransaction()
            Return ret
        Catch ex As Exception
            Return ""
        End Try

    End Function

    <WebMethod()> _
    Public Function CheckAuthorizeGroupScreenByUser(userid As String, screenid As String) As Boolean
        Try
            Dim dt As DataTable
            Dim ret As String = ""
            Dim trans As New TransactionDB
            Dim clsTsAuthorizegroupMenuLinqDB As New TsAuthorizegroupMenuLinqDB
            Dim strSQL As New StringBuilder
            strSQL.Append(" Select u.username")
            strSQL.Append(" ,au.id_ms_authorizegroup")
            strSQL.Append(" ,am.id_ms_screen from ms_user u")
            strSQL.Append(" inner join ts_authorizegroup_user au")
            strSQL.Append(" on u.id=au.id_ms_user")
            strSQL.Append(" inner join ts_authorizegroup_menu am")
            strSQL.Append(" on au.id_ms_authorizegroup= am.id_ms_authorizegroup")
            strSQL.Append(" where u.id = " & userid & " And am.id_ms_screen = " & screenid)
            With clsTsAuthorizegroupMenuLinqDB
                dt = .GetListBySql(strSQL.ToString, trans.Trans)
                If dt.Rows.Count > 0 Then
                    Return True
                Else
                    Return False
                End If
            End With
            clsTsAuthorizegroupMenuLinqDB = Nothing
        Catch ex As Exception
            Return False
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadAuthorizeGroupMap(groupid As String) As String
        Try
            Dim dtMenu As DataTable
            Dim dvMainMenu, dvMinorMenu, dvSubMenu, dvSubSubMenu As DataView
            Dim strDefaultImageCssName As String = "icon-folder-close"
            Dim strID, strScreenName, strImageCssName, strGroupSelect As String
            Dim intRowID As Long

            Dim dt As DataTable
            Dim strSql As New StringBuilder
            strSql.Append(" SELECT	Screen.Id,")
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
            strSql.Append("(select COUNT(Id) from MS_Screen where (RowID_RootMenu=Screen.Id or RowID_ParentMenu=Screen.Id  or  RowID_SubParentMenu  =Screen.Id ) ) as LevelCheck,")
            strSql.Append(" (case when isnull(menu.id_ms_screen ,0) = 0 then 0 else 1 end )  IsMap")
            strSql.Append(" FROM MS_Screen Screen")
            strSql.Append(" LEFT JOIN MS_Module Module")
            strSql.Append(" ON Module.Id = Screen.ms_module_id")
            strSql.Append(" LEFT JOIN MS_SubModule SubModule")
            strSql.Append(" ON SubModule.Id = Screen.ms_submodule_id")
            strSql.Append(" LEFT JOIN TS_Authorizegroup_menu menu")
            strSql.Append(" ON menu.id_ms_screen = Screen.id  and  menu.id_ms_authorizegroup =" & groupid)
            strSql.Append(" where isnull(isnotuse,0) = 0 ")
            strSql.Append(" Order by Screen.Sequence ")

            dt = SqlDB.ExecuteTable(strSql.ToString)

            Dim strComma As String = ","

            Dim strMenu As New StringBuilder
            dtMenu = dt.Copy
            dvMainMenu = dtMenu.Copy.DefaultView
            dvMainMenu.RowFilter = "RowId_RootMenu = 0"
            dvMainMenu.Sort = "Sequence"
            strMenu.Append("[")

            For i As Integer = 0 To dvMainMenu.Count - 1
                Select Case dvMainMenu(i)("LevelCheck") & ""
                    Case 0 'กรณีมี Root เดียว
                        'Level 1
                        strScreenName = dvMainMenu(i)("ScreenName") & ""
                        strID = dvMainMenu(i)("Id")
                        strImageCssName = "<i class='" & dvMainMenu(i)("ImageURL") & "'> </i> "
                        strGroupSelect = IIf(dvMainMenu(i)("IsMap") = 1, "true", "false")
                        strMenu.Append(IIf(strMenu.Length > 0 And i > 0, strComma, "") & "{""title"": """ & strImageCssName & strScreenName & """, ""key"": """ & strID & """ ,""icon"":false,""select"":" & strGroupSelect & "}")

                    Case Else 'กรณีมีหลาย Root 
                        'Level 1
                        strScreenName = dvMainMenu(i)("ScreenName") & ""
                        strID = dvMainMenu(i)("Id") ' IIf(dvMainMenu(i)("RowID_RootMenu") = 0, 0, dvMainMenu(i)("Id"))
                        strImageCssName = "<i class='" & dvMainMenu(i)("ImageURL") & "'> </i> "
                        strGroupSelect = IIf(dvMainMenu(i)("IsMap") = 1, "true", "false")



                        strMenu.Append(IIf(i > 0, strComma, "") & "{""title"": """ & strImageCssName & strScreenName & """, ""key"": """ & strID & """, ""expand"": true,""icon"":false,""select"":" & strGroupSelect & "")
                        'Level 2
                        dvMinorMenu = dtMenu.Copy.DefaultView
                        dvMinorMenu.RowFilter = "RowId_ParentMenu = 0  AND RowId_RootMenu = " & dvMainMenu(i)("Id")
                        dvMinorMenu.Sort = "Sequence"
                        If dvMinorMenu.Count > 0 Then
                            strMenu.Append(strComma & """children"": [")
                            For j As Integer = 0 To dvMinorMenu.Count - 1 'Level 2
                                intRowID = dvMinorMenu(j)("id")
                                strScreenName = dvMinorMenu(j)("ScreenName") & ""
                                strID = dvMinorMenu(j)("Id") 'IIf(dvMinorMenu(j)("RowID_RootMenu") = 0, 0, dvMinorMenu(j)("Id"))
                                strImageCssName = "<i class='" & dvMinorMenu(j)("ImageURL") & "'> </i> "  'dvMinorMenu(j)("ImageURL") & ""
                                strGroupSelect = IIf(dvMinorMenu(j)("IsMap") = 1, "true", "false")

                                dvSubMenu = dtMenu.Copy.DefaultView
                                dvSubMenu.RowFilter = "RowId_SubParentMenu=0 AND RowId_RootMenu = " & dvMinorMenu(j)("RowId_RootMenu") & " AND RowId_ParentMenu = " & intRowID
                                dvSubMenu.Sort = "Sequence"

                                strMenu.Append(IIf(j > 0, strComma, "") & "{""title"": """ & strImageCssName & strScreenName & """, ""key"": """ & strID & """ ,""expand"": true,""icon"":false,""select"":" & strGroupSelect & "")
                                If dvSubMenu.Count > 0 Then


                                    strMenu.Append(strComma & """children"": [")

                                    For k As Integer = 0 To dvSubMenu.Count - 1   ' Level 3

                                        intRowID = dvSubMenu(k)("Id")
                                        strScreenName = dvSubMenu(k)("ScreenName") & ""
                                        strID = dvSubMenu(k)("Id") 'IIf(dvSubMenu(k)("RowID_RootMenu") = 0, 0, dvSubMenu(k)("Id"))
                                        strImageCssName = "<i class='" & dvSubMenu(k)("ImageURL") & "'> </i> "
                                        strGroupSelect = IIf(dvSubMenu(k)("IsMap") = 1, "true", "false")

                                        dvSubSubMenu = dtMenu.Copy.DefaultView
                                        dvSubSubMenu.RowFilter = "RowId_RootMenu = " & dvSubMenu(k)("RowId_RootMenu") & " AND RowId_ParentMenu=" & dvSubMenu(k)("RowId_ParentMenu") & "  AND RowId_SubParentMenu = " & intRowID
                                        dvSubSubMenu.Sort = "Sequence"
                                        strMenu.Append(IIf(j > 0, strComma, "") & "{""title"": """ & strImageCssName & strScreenName & """, ""key"": """ & strID & """ ,""expand"": true,""icon"":false,""select"":" & strGroupSelect & "")

                                        If dvSubSubMenu.Count > 0 Then
                                            strMenu.Append(strComma & """children"": [")
                                            For L As Integer = 0 To dvSubSubMenu.Count - 1 ' Level 4
                                                strScreenName = dvSubSubMenu(L)("ScreenName") & ""
                                                strID = dvSubSubMenu(L)("Id") ' IIf(dvSubSubMenu(L)("RowID_RootMenu") = 0, 0, dvSubSubMenu(L)("Id"))
                                                strImageCssName = "<i class='" & dvMinorMenu(j)("ImageURL") & "'> </i> "
                                                strGroupSelect = IIf(dvSubSubMenu(L)("IsMap") = 1, "true", "false")

                                                strMenu.Append(IIf(L = 0, "", ",") & "{""title"": """ & strImageCssName & strScreenName & """, ""key"": """ & strID & """,""icon"":false,""select"":" & strGroupSelect & "}")

                                            Next
                                            strMenu.Append("]")
                                            strMenu.Append("}")

                                        Else
                                            strMenu.Append("}")
                                        End If

                                    Next
                                    strMenu.Append("]")
                                    strMenu.Append("}")

                                Else
                                    strMenu.Append("}")

                                End If


                            Next
                            strMenu.Append("]")
                        Else
                            strMenu.Append("}")
                        End If
                        strMenu.Append("}")
                End Select
            Next
            strMenu.Append("]")




            Dim strdata As String = strMenu.ToString
            Return strdata
        Catch ex As Exception
            Return ""
        End Try

    End Function
#End Region

#Region "User"
    <WebMethod()> _
    Public Function GetUserMapAuthorizeGroup(groupid As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY u.id asc) AS no")
            strSql.Append(" ,au.id")
            strSql.Append(" ,isnull(p.prefix_eng,'') + u.name_eng + ' ' + u.surname_eng as fullname_eng")
            strSql.Append(" ,isnull(p.prefix_thai,'') + u.name_thai + ' ' + u.surname_thai as fullname_thai")
            strSql.Append(" from  ms_user  u")
            strSql.Append(" inner join ms_prefix p")
            strSql.Append(" on u.ms_prefix_id = p.id")
            strSql.Append(" inner join ts_authorizegroup_user au")
            strSql.Append(" on au.id_ms_user = u.id")
            strSql.Append(" where u.active_status='Y' and au.id_ms_authorizegroup=" & groupid)
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function GetNotUserMapAuthorizeGroup(name As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" isnull(p.prefix_eng,'') + u.name_eng + ' ' + u.surname_eng as label")
            strSql.Append(" ,u.id")
            strSql.Append(" ,isnull(p.prefix_eng,'') + u.name_eng + ' ' + u.surname_eng as fullname_eng")
            strSql.Append(" ,isnull(p.prefix_thai,'') + u.name_thai + ' ' + u.surname_thai as fullname_thai")
            strSql.Append(" from  ms_user  u")
            strSql.Append(" inner join ms_prefix p")
            strSql.Append(" on u.ms_prefix_id = p.id")
            strSql.Append(" where u.active_status='Y'  and u.id not in(select id_ms_user from ts_authorizegroup_user) and (isnull(p.prefix_eng,'') + u.name_eng + ' ' + u.surname_eng) like '%" & name & "%'")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadUserAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY u.id asc) AS no")
            strSql.Append(" ,u.id")
            strSql.Append(" ,(case when isnull(u.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,u.name_thai")
            strSql.Append(" ,u.name_eng")
            strSql.Append(" ,u.surname_thai")
            strSql.Append(" ,u.surname_eng")
            strSql.Append(" ,u.ms_prefix_id")
            strSql.Append(" ,u.ms_department_id")
            strSql.Append(" ,u.ms_position_id")
            strSql.Append(" ,pf.prefix_eng")
            strSql.Append(" ,d.department_name")
            strSql.Append(" ,p.position_name")
            strSql.Append(" ,isnull(pf.prefix_eng,'') + u.name_eng + ' ' + u.surname_eng as fullname")
            strSql.Append(" ,u.employee_code")
            strSql.Append(" from ms_user u")
            strSql.Append(" inner join ms_prefix pf")
            strSql.Append(" on pf.id = u.ms_prefix_id")
            strSql.Append(" inner join ms_department d")
            strSql.Append(" on d.id = u.ms_department_id")
            strSql.Append(" inner join ms_position p")
            strSql.Append(" on p.id = u.ms_position_id")
            strSql.Append(" order by u.name_thai")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function GetUserById(id As String) As String
        Try
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable("SELECT * FROM MS_USER WHERE ID=" & id)
            If dt.Rows.Count <> 0 Then
                Dim dtreturn As New DataTable
                Dim drreturn As DataRow

                dtreturn.Columns.Add("id")
                dtreturn.Columns.Add("ms_prefix_id")
                dtreturn.Columns.Add("employee_code")
                dtreturn.Columns.Add("name_thai")
                dtreturn.Columns.Add("name_eng")
                dtreturn.Columns.Add("surname_thai")
                dtreturn.Columns.Add("surname_eng")
                dtreturn.Columns.Add("ms_department_id")
                dtreturn.Columns.Add("ms_position_id")
                dtreturn.Columns.Add("active_status")
                dtreturn.Columns.Add("username")
                dtreturn.Columns.Add("password")

                drreturn = dtreturn.NewRow()
                drreturn("id") = dt.Rows(0)("id") & ""
                drreturn("ms_prefix_id") = dt.Rows(0)("ms_prefix_id") & ""
                drreturn("employee_code") = dt.Rows(0)("employee_code") & ""
                drreturn("name_thai") = dt.Rows(0)("name_thai") & ""
                drreturn("name_eng") = dt.Rows(0)("name_eng") & ""
                drreturn("surname_thai") = dt.Rows(0)("surname_thai") & ""
                drreturn("surname_eng") = dt.Rows(0)("surname_eng") & ""
                drreturn("ms_department_id") = dt.Rows(0)("ms_department_id") & ""
                drreturn("ms_position_id") = dt.Rows(0)("ms_position_id") & ""
                drreturn("active_status") = dt.Rows(0)("active_status") & ""
                drreturn("username") = dt.Rows(0)("username") & ""
                drreturn("password") = SqlDB.DeCripPwd(dt.Rows(0)("passwd") & "")
                dtreturn.Rows.Add(drreturn)

                Return clsdtHelper.ConvertDataTableToJson(dtreturn)
            Else
                Return "[]"
            End If

            ' Return ret
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveUser(id As String _
                             , ms_prefix_id As String _
                             , employee_code As String _
                             , name_thai As String _
                             , name_eng As String _
                             , surname_thai As String _
                             , surname_eng As String _
                             , ms_department_id As String _
                             , ms_position_id As String _
                             , username As String _
                             , password As String _
                             , strimagebase64 As String _
                             , strimagename As String _
                             , strimagepath As String _
                             , userid As String _
                             , active As String) As String
        Try
            Dim trans As New TransactionDB
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable
            Dim clsMsUserLinqDB As New MsUserLinqDB
            With clsMsUserLinqDB
                dt = .GetDataList("name_eng='" & name_eng.Trim & "' and surname_eng='" & surname_eng.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With
            clsMsUserLinqDB = Nothing

            clsMsUserLinqDB = New MsUserLinqDB
            With clsMsUserLinqDB
                dt = .GetDataList("employee_code='" & employee_code.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicateemployee_code
                    Return retStatus
                End If
            End With
            clsMsUserLinqDB = Nothing


            clsMsUserLinqDB = New MsUserLinqDB
            With clsMsUserLinqDB
                dt = .GetDataList("username='" & username.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicateUsername
                    Return retStatus
                End If
            End With
            clsMsUserLinqDB = Nothing



            clsMsUserLinqDB = New MsUserLinqDB
            With clsMsUserLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = True Then
                    .EMPLOYEE_CODE = employee_code
                    .MS_PREFIX_ID = ms_prefix_id
                    .NAME_ENG = name_eng
                    .NAME_THAI = name_thai
                    .SURNAME_ENG = surname_eng
                    .SURNAME_THAI = surname_thai
                    .MS_DEPARTMENT_ID = ms_department_id
                    .MS_POSITION_ID = ms_position_id
                    .USERNAME = username
                    .PASSWD = SqlDB.EnCripPwd(password)
                    .ACTIVE_STATUS = active
                    ret = .UpdateByPK(userid, trans.Trans)
                Else
                    .EMPLOYEE_CODE = employee_code
                    .MS_PREFIX_ID = ms_prefix_id
                    .NAME_ENG = name_eng
                    .NAME_THAI = name_thai
                    .SURNAME_ENG = surname_eng
                    .SURNAME_THAI = surname_thai
                    .MS_DEPARTMENT_ID = ms_department_id
                    .MS_POSITION_ID = ms_position_id
                    .USERNAME = username
                    .PASSWD = SqlDB.EnCripPwd(password)
                    .ACTIVE_STATUS = active
                    ret = .InsertData(userid, trans.Trans)
                End If
            End With
            clsMsUserLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteUser(id As String) As Boolean
        Try
            Dim ret As Boolean = False
            ret = SqlDB.ExecuteNonQuery("DELETE FROM MS_USER WHERE ID=" & id)
            Return ret
        Catch ex As Exception
            Return False
        End Try
    End Function

#End Region

#Region "Master"

#Region "Building"
    <WebMethod()> _
    Public Function LoadBulidingAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY b.id asc) AS no")
            strSql.Append(" ,b.id")
            strSql.Append(" ,(case when isnull(b.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,b.building_name")
            strSql.Append(" ,b.building_desc")
            strSql.Append(" from ms_building b")
            strSql.Append(" order by b.building_name")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadActiveBuliding() As String
        Try
            Dim dt As DataTable
            Dim strdata As String
            Dim strSql As New StringBuilder
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY b.id asc) AS no")
            strSql.Append(" ,b.id")
            strSql.Append(" ,(case when isnull(b.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,b.building_name")
            strSql.Append(" ,b.building_desc")
            strSql.Append(" from ms_building b")
            strSql.Append(" where b.active_status ='Y'")
            strSql.Append(" order by b.building_name")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return Nothing
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadBulidingBy(room_id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY b.id asc) AS no")
            strSql.Append(" ,b.id")
            strSql.Append(" ,(case when isnull(b.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,b.building_name")
            strSql.Append(" ,b.building_desc")
            strSql.Append(" , (case  when isnull(mr.ms_building_id,'')='' then '' else 'selected' end) selected")
            strSql.Append(" from ms_building b")
            strSql.Append(" left join ms_meeting_room mr")
            strSql.Append(" on b.id = mr.ms_building_id and mr.id = " & Val(room_id))
            strSql.Append(" where isnull(b.active_status ,'N')='Y' ")
            strSql.Append(" order by b.building_name")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function GetBulidingById(id As String) As String
        Try
            'Dim ret As String = ""
            'Dim trans As New TransactionDB
            'Dim clsMsBuildingLinqDB As New MsBuildingLinqDB
            'With clsMsBuildingLinqDB
            '    .GetDataByPK(id, trans.Trans)
            '    If .HaveData = True Then
            '        ret = .BUILDING_NAME & "," & .BUILDING_DESC & "," & .ACTIVE_STATUS
            '    End If
            'End With
            'clsMsBuildingLinqDB = Nothing
            'trans.CommitTransaction()
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable("SELECT * FROM MS_BUILDING WHERE ID=" & id)

            'z clsdtHelper.ConvertDataTableToJson(dt)
            'clsMsAuthorizegroupLinqDB = Nothing
            'trans.CommitTransaction()
            Return clsdtHelper.ConvertDataTableToJson(dt)
            ' Return ret
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveBuilding(id As String, building_name As String, building_desc As String, userid As String, active As String) As String
        Try
            Dim trans As New TransactionDB
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable
            Dim clsMsBuildingLinqDB As New MsBuildingLinqDB
            With clsMsBuildingLinqDB
                dt = .GetDataList("building_name='" & building_name.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With

            clsMsBuildingLinqDB = New MsBuildingLinqDB
            With clsMsBuildingLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = True Then
                    .BUILDING_NAME = building_name
                    .BUILDING_DESC = building_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .UpdateByPK(userid, trans.Trans)
                Else
                    .BUILDING_NAME = building_name
                    .BUILDING_DESC = building_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .InsertData(userid, trans.Trans)
                End If
            End With
            clsMsBuildingLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteBuilding(id As String) As Boolean
        Try
            'Dim trans As New TransactionDB
            Dim ret As Boolean = False
            'Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            'With clsMsAuthorizegroupLinqDB
            '    ret = .DeleteByPK(id, trans.Trans)
            'End With
            'clsMsAuthorizegroupLinqDB = Nothing
            ret = SqlDB.ExecuteNonQuery("DELETE FROM MS_BUILDING WHERE ID=" & id)
            'If ret = True Then
            '    trans.CommitTransaction()
            'Else
            '    trans.RollbackTransaction()
            'End If

            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function
#End Region

#Region "Department"
    <WebMethod()> _
    Public Function LoadDepartment() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY b.id asc) AS no")
            strSql.Append(" ,b.id")
            strSql.Append(" ,(case when isnull(b.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,b.department_name")
            strSql.Append(" ,'' as department_desc")
            strSql.Append(" from ms_department b")
            strSql.Append(" order by b.department_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try
    End Function

    <WebMethod()> _
    Public Function LoadActiveDepartment() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY b.id asc) AS no")
            strSql.Append(" ,b.id")
            strSql.Append(" ,(case when isnull(b.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,b.department_name")
            strSql.Append(" ,'' as department_desc")
            strSql.Append(" from ms_department b")
            strSql.Append(" where b.active_status='Y'")
            strSql.Append(" order by b.department_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try
    End Function

    <WebMethod()> _
    Public Function LoadDepartmentBy(user_id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY d.id asc) AS no")
            strSql.Append(" ,d.id")
            strSql.Append(" ,(case when isnull(d.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,d.department_name")
            strSql.Append(" ,'' as department_desc")
            strSql.Append(" , (case  when isnull(u.ms_department_id,'')='' then '' else 'selected' end) selected")
            strSql.Append(" from ms_department d")
            strSql.Append(" left join ms_user u")
            strSql.Append(" on d.id = u.ms_department_id and u.id = " & Val(user_id))
            strSql.Append(" where isnull(d.active_status ,'N')='Y' ")
            strSql.Append(" order by d.department_name")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try
    End Function


    <WebMethod()> _
    Public Function GetDepartmentById(id As String) As String
        Try
            'Dim ret As String = ""
            'Dim trans As New TransactionDB
            'Dim clsMsdepartmentLinqDB As New MsdepartmentLinqDB
            'With clsMsdepartmentLinqDB
            '    .GetDataByPK(id, trans.Trans)
            '    If .HaveData = True Then
            '        ret = .department_NAME & "," & .department_DESC & "," & .ACTIVE_STATUS
            '    End If
            'End With
            'clsMsdepartmentLinqDB = Nothing
            'trans.CommitTransaction()
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable("SELECT * FROM MS_DEPARTMENT WHERE ID=" & id)

            'z clsdtHelper.ConvertDataTableToJson(dt)
            'clsMsAuthorizegroupLinqDB = Nothing
            'trans.CommitTransaction()
            Return clsdtHelper.ConvertDataTableToJson(dt)
            ' Return ret
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveDepartment(id As String, department_name As String, department_desc As String, userid As String, active As String) As String
        Try
            Dim trans As New TransactionDB
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable
            Dim clsMsdepartmentLinqDB As New MsDepartmentLinqDB
            With clsMsdepartmentLinqDB
                dt = .GetDataList("department_name='" & department_name.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With

            clsMsdepartmentLinqDB = New MsDepartmentLinqDB
            With clsMsdepartmentLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = True Then
                    .DEPARTMENT_NAME = department_name
                    ' .department_DESC = department_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .UpdateByPK(userid, trans.Trans)
                Else
                    .DEPARTMENT_NAME = department_name
                    '.department_DESC = department_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .InsertData(userid, trans.Trans)
                End If
            End With
            clsMsdepartmentLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteDepartment(id As String) As Boolean
        Try
            'Dim trans As New TransactionDB
            Dim ret As Boolean = False
            'Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            'With clsMsAuthorizegroupLinqDB
            '    ret = .DeleteByPK(id, trans.Trans)
            'End With
            'clsMsAuthorizegroupLinqDB = Nothing
            ret = SqlDB.ExecuteNonQuery("DELETE FROM MS_DEPARTMENT WHERE ID=" & id)
            'If ret = True Then
            '    trans.CommitTransaction()
            'Else
            '    trans.RollbackTransaction()
            'End If

            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function
#End Region

#Region "Position"
    <WebMethod()> _
    Public Function LoadPosition() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY p.id asc) AS no")
            strSql.Append(" ,p.id")
            strSql.Append(" ,(case when isnull(p.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,p.position_name")
            strSql.Append(" ,'' as position_desc")
            strSql.Append(" from ms_position p")
            strSql.Append(" order by p.position_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadPositionBy(user_id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY p.id asc) AS no")
            strSql.Append(" ,p.id")
            strSql.Append(" ,(case when isnull(p.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,p.position_name")
            strSql.Append(" ,'' as position_desc")
            strSql.Append(" , (case  when isnull(u.ms_position_id,'')='' then '' else 'selected' end) selected")
            strSql.Append(" from ms_position p")
            strSql.Append(" left join ms_user u")
            strSql.Append(" on p.id = u.ms_position_id and u.id = " & Val(user_id))
            strSql.Append(" where isnull(p.active_status ,'N')='Y' ")
            strSql.Append(" order by p.position_name")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try
    End Function

    <WebMethod()> _
    Public Function GetPositionById(id As String) As String
        Try
            'Dim ret As String = ""
            'Dim trans As New TransactionDB
            'Dim clsMspositionLinqDB As New MspositionLinqDB
            'With clsMspositionLinqDB
            '    .GetDataByPK(id, trans.Trans)
            '    If .HaveData = True Then
            '        ret = .position_NAME & "," & .position_DESC & "," & .ACTIVE_STATUS
            '    End If
            'End With
            'clsMspositionLinqDB = Nothing
            'trans.CommitTransaction()
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable("SELECT * FROM MS_POSITION WHERE ID=" & id)

            'z clsdtHelper.ConvertDataTableToJson(dt)
            'clsMsAuthorizegroupLinqDB = Nothing
            'trans.CommitTransaction()
            Return clsdtHelper.ConvertDataTableToJson(dt)
            ' Return ret
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function SavePosition(id As String, position_name As String, position_desc As String, userid As String, active As String) As String
        Try
            Dim trans As New TransactionDB
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable
            Dim clsMspositionLinqDB As New MsPositionLinqDB
            With clsMspositionLinqDB
                dt = .GetDataList("position_name='" & position_name.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With

            clsMspositionLinqDB = New MsPositionLinqDB
            With clsMspositionLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = True Then
                    .POSITION_NAME = position_name
                    ' .position_DESC = position_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .UpdateByPK(userid, trans.Trans)
                Else
                    .POSITION_NAME = position_name
                    '.position_DESC = position_desc
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .InsertData(userid, trans.Trans)
                End If
            End With
            clsMspositionLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function DeletePosition(id As String) As Boolean
        Try
            'Dim trans As New TransactionDB
            Dim ret As Boolean = False
            'Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            'With clsMsAuthorizegroupLinqDB
            '    ret = .DeleteByPK(id, trans.Trans)
            'End With
            'clsMsAuthorizegroupLinqDB = Nothing
            ret = SqlDB.ExecuteNonQuery("DELETE FROM MS_POSITION WHERE ID=" & id)
            'If ret = True Then
            '    trans.CommitTransaction()
            'Else
            '    trans.RollbackTransaction()
            'End If

            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function
#End Region

#Region "Room"
    <WebMethod()> _
    Public Function LoadRoomByBuildingId(id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            strSql.Append(" ,r.id")
            strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,r.room_name")
            strSql.Append(" ,'' as room_desc")
            strSql.Append(" ,r.floor")
            strSql.Append(" ,b.building_name")
            strSql.Append(" , '' option_name")
            strSql.Append(" ,seat_qty")
            strSql.Append(" ,rt.room_type_name")
            strSql.Append(" from ms_meeting_room r")
            strSql.Append(" inner join ms_building b")
            strSql.Append(" on r.ms_building_id = b.id")
            strSql.Append(" inner join ms_room_type rt")
            strSql.Append(" on r.ms_room_type_id = rt.id")
            strSql.Append(" where r.active_status ='Y'")
            If id <> "" Then
                strSql.Append(" and b.id=" & id)
            End If

            strSql.Append(" order by r.room_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                Return clsdtHelper.ConvertDataTableToJson(dt)
            Else
                Return "[]"
            End If
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadBuildingByRoomId(id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            If id <> "" Then
                strSql.Append("select table1.* from (select distinct")
                strSql.Append(" b.id")
                strSql.Append(" ,b.building_name")
                strSql.Append(" from ms_meeting_room r")
                strSql.Append(" inner join ms_building b")
                strSql.Append(" on r.ms_building_id = b.id")
                strSql.Append(" where r.active_status ='Y'")
                strSql.Append(" and r.id=" & id)
                strSql.Append(" ) as table1 order by table1.building_name")
                dt = SqlDB.ExecuteTable(strSql.ToString)
            Else
                strSql.Append(" select ")
                strSql.Append(" b.id")
                strSql.Append(" ,b.building_name")
                strSql.Append(" ,b.building_desc")
                strSql.Append(" from ms_building b")
                strSql.Append(" where b.active_status ='Y'")
                strSql.Append(" order by b.building_name")
                dt = SqlDB.ExecuteTable(strSql.ToString)
            End If


            If dt.Rows.Count > 0 Then
                Return clsdtHelper.ConvertDataTableToJson(dt)
            Else
                Return "[]"
            End If
        Catch ex As Exception
            Return "[]"
        End Try

    End Function



    <WebMethod()> _
    Public Function LoadActiveRoom() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            strSql.Append(" ,r.id")
            strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,r.room_name")
            strSql.Append(" ,'' as room_desc")
            strSql.Append(" ,r.floor")
            strSql.Append(" ,b.building_name")
            strSql.Append(" , '' option_name")
            strSql.Append(" ,seat_qty")
            strSql.Append(" ,rt.room_type_name")
            strSql.Append(" from ms_meeting_room r")
            strSql.Append(" inner join ms_building b")
            strSql.Append(" on r.ms_building_id = b.id")
            strSql.Append(" inner join ms_room_type rt")
            strSql.Append(" on r.ms_room_type_id = rt.id where  isnull(r.active_status ,'N') = 'Y'")
            strSql.Append(" order by r.room_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadRoom() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            strSql.Append(" ,r.id")
            strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,r.room_name")
            strSql.Append(" ,'' as room_desc")
            strSql.Append(" ,r.floor")
            strSql.Append(" ,b.building_name")
            strSql.Append(" , '' option_name")
            strSql.Append(" ,seat_qty")
            strSql.Append(" ,rt.room_type_name")
            strSql.Append(" from ms_meeting_room r")
            strSql.Append(" inner join ms_building b")
            strSql.Append(" on r.ms_building_id = b.id")
            strSql.Append(" inner join ms_room_type rt")
            strSql.Append(" on r.ms_room_type_id = rt.id")
            strSql.Append(" order by r.room_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadActiveRoom(filter As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            strSql.Append(" ,r.id")
            strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,r.room_name")
            strSql.Append(" ,'' as room_desc")
            strSql.Append(" ,r.floor")
            strSql.Append(" ,b.building_name")
            strSql.Append(" , '' option_name")
            strSql.Append(" ,seat_qty")
            strSql.Append(" ,rt.room_type_name")
            strSql.Append(" from ms_meeting_room r")
            strSql.Append(" inner join ms_building b")
            strSql.Append(" on r.ms_building_id = b.id")
            strSql.Append(" inner join ms_room_type rt")
            strSql.Append(" on r.ms_room_type_id = rt.id")
            strSql.Append(" where r.active_status ='Y' ")
            If filter <> "" Then
                strSql.Append(filter)
            End If

            strSql.Append(" order by r.room_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return Nothing
        End Try

    End Function

    <WebMethod()> _
    Public Function GetRoomById(id As String) As String
        Try
            'Dim ret As String = ""
            'Dim trans As New TransactionDB
            'Dim clsMsRoomLinqDB As New MsRoomLinqDB
            'With clsMsRoomLinqDB
            '    .GetDataByPK(id, trans.Trans)
            '    If .HaveData = True Then
            '        ret = .Room_NAME & "," & .Room_DESC & "," & .ACTIVE_STATUS
            '    End If
            'End With
            'clsMsRoomLinqDB = Nothing
            'trans.CommitTransaction()
            Dim dt As DataTable
            Dim strSQl As New StringBuilder
            strSQl.Append(" SELECT R.*,B.building_name,RT.room_type_name,[dbo].[GetRoomProperty](R.id) as stroption ")
            strSQl.Append(" FROM MS_MEETING_ROOM  R ")
            strSQl.Append(" LEFT JOIN MS_BUILDING B ")
            strSQl.Append(" ON R.ms_building_id = B.id ")
            strSQl.Append(" LEFT JOIN MS_ROOM_TYPE RT ")
            strSQl.Append(" ON R.ms_room_type_id = RT.id")
            strSQl.Append(" WHERE R.ID=" & id)
            dt = SqlDB.ExecuteTable(strSQl.ToString)
            If dt.Rows.Count <> 0 Then
                Dim dtreturn As New DataTable
                Dim drreturn As DataRow

                dtreturn.Columns.Add("id")
                dtreturn.Columns.Add("ms_room_type_id")
                dtreturn.Columns.Add("ms_building_id")
                dtreturn.Columns.Add("building_name")
                dtreturn.Columns.Add("room_type_name")
                dtreturn.Columns.Add("stroption")
                dtreturn.Columns.Add("floor")
                dtreturn.Columns.Add("room_name")
                dtreturn.Columns.Add("attendance")
                dtreturn.Columns.Add("active_status")
                dtreturn.Columns.Add("room_image_type")
                dtreturn.Columns.Add("room_image_name")
                dtreturn.Columns.Add("room_image_path")
                dtreturn.Columns.Add("room_image")
                dtreturn.Columns.Add("room_image_base64")


                'Base64 string   convert byte to base64string
                Dim strimagebase64 As String = ""
                Dim strimagebasesrc As String = ""
                If dt.Rows(0)("room_image_type") & "" <> "" Then
                    strimagebasesrc = "data:image/" & dt.Rows(0)("room_image_type") & ";base64," & Convert.ToBase64String(dt.Rows(0)("room_image"))
                    strimagebase64 = Convert.ToBase64String(dt.Rows(0)("room_image"))
                End If


                drreturn = dtreturn.NewRow()
                drreturn("id") = dt.Rows(0)("id") & ""
                drreturn("ms_room_type_id") = dt.Rows(0)("ms_room_type_id") & ""
                drreturn("ms_building_id") = dt.Rows(0)("ms_building_id") & ""
                drreturn("floor") = dt.Rows(0)("floor") & ""
                drreturn("building_name") = dt.Rows(0)("building_name") & ""
                drreturn("room_type_name") = dt.Rows(0)("room_type_name") & ""
                drreturn("stroption") = dt.Rows(0)("stroption") & ""
                drreturn("room_name") = dt.Rows(0)("room_name") & ""
                drreturn("attendance") = dt.Rows(0)("seat_qty") & ""
                drreturn("active_status") = dt.Rows(0)("active_status") & ""
                drreturn("room_image_type") = dt.Rows(0)("room_image_type") & ""
                drreturn("room_image_name") = dt.Rows(0)("room_image_name") & ""
                Dim strpart As String = HttpContext.Current.Request.MapPath("~/Upload/Room/" & id & "/" & dt.Rows(0)("room_image_name") & "." & dt.Rows(0)("room_image_type"))
                drreturn("room_image_path") = strpart
                drreturn("room_image") = strimagebasesrc
                drreturn("room_image_base64") = strimagebase64
                dtreturn.Rows.Add(drreturn)

                Return clsdtHelper.ConvertDataTableToJson(dtreturn)
            Else
                Return "[]"
            End If

            ' Return ret
        Catch ex As Exception
            Return "[]"
        End Try

    End Function


    <WebMethod()> _
    Public Function SaveRoom(id As String, _
                             room_name As String, _
                             ms_room_type_id As String, _
                             attendance As String, _
                             ms_building_id As String, _
                             floor As String, _
                             stroption_id As String, _
                             strimagebase64 As String, _
                             strimagename As String, _
                             strimagepath As String, _
                             userid As String, _
                             active As String) As String
        Try


            Dim bytes As Byte()
            If strimagebase64 <> "" Then
                'Byte  convert base64string to byte
                bytes = Convert.FromBase64String(strimagebase64)
                ''Base64 string   convert byte to base64string
                ' Dim strimagebase64 As String = Convert.ToBase64String(bytes)
            Else
                bytes = Convert.FromBase64String("")
            End If



            Dim trans As New TransactionDB

            Dim strImagetype As String = ""
            Dim strTempOption As String = "0," & stroption_id
            Dim strOptionSplitId As String() = strTempOption.Split(",")
            Dim strRoomID As String

            Dim strimagenametem As String()
            If strimagename <> "" Then
                strimagenametem = strimagename.Split(".")
                strimagename = strimagenametem(0)
                strImagetype = strimagenametem(1)
            End If
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable

            Dim clsMsMeetingRoomPropertyItemLinqDB As New MsMeetingRoomPropertyItemLinqDB

            Dim clsMsMeetingRoomLinqDB As New MsMeetingRoomLinqDB
            With clsMsMeetingRoomLinqDB
                dt = .GetDataList("room_name='" & room_name.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With

            clsMsMeetingRoomLinqDB = New MsMeetingRoomLinqDB
            With clsMsMeetingRoomLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = True Then
                    .ROOM_NAME = room_name
                    .MS_ROOM_TYPE_ID = ms_room_type_id
                    .MS_BUILDING_ID = ms_building_id
                    .FLOOR = floor
                    .SEAT_QTY = attendance
                    .ROOM_IMAGE = bytes
                    .ROOM_IMAGE_TYPE = strImagetype
                    .ROOM_IMAGE_NAME = strimagename
                    .ACTIVE_STATUS = active
                    ret = .UpdateByPK(userid, trans.Trans)
                Else
                    .ROOM_NAME = room_name
                    .MS_ROOM_TYPE_ID = ms_room_type_id
                    .MS_BUILDING_ID = ms_building_id
                    .FLOOR = floor
                    .SEAT_QTY = attendance
                    .ROOM_IMAGE = bytes
                    .ROOM_IMAGE_TYPE = strImagetype
                    .ROOM_IMAGE_NAME = strimagename
                    .ACTIVE_STATUS = active
                    ret = .InsertData(userid, trans.Trans)
                End If

                strRoomID = .ID
            End With

            If ret Then
                ret = SqlDB.ExecuteNonQuery("DELETE FROM MS_MEETING_ROOM_PROPERTY_ITEM WHERE ms_meeting_room_id=" & strRoomID)


                For i As Integer = 0 To strOptionSplitId.Length - 1
                    If Val(strOptionSplitId(i)) <> 0 Then
                        clsMsMeetingRoomPropertyItemLinqDB = New MsMeetingRoomPropertyItemLinqDB
                        With clsMsMeetingRoomPropertyItemLinqDB
                            .MS_MEETING_ROOM_ID = strRoomID
                            .MS_ROOM_PROPERTY_ID = strOptionSplitId(i)
                            ret = .InsertData(userid, trans.Trans)
                        End With

                    End If
                Next

                clsMsMeetingRoomPropertyItemLinqDB = Nothing

                'Dim strpart As String = HttpContext.Current.Request.MapPath("~\Upload\Room\" & strRoomID)

                'If (Not System.IO.Directory.Exists(strpart)) Then
                '    System.IO.Directory.CreateDirectory(strpart)
                'End If
                'If strimagename <> "" Then
                '    My.Computer.FileSystem.CopyFile(
                '    strimagepath,
                '    strpart & "\" & strimagename)
                'End If


            End If


            clsMsMeetingRoomLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteRoom(id As String) As Boolean
        Try
            'Dim trans As New TransactionDB
            Dim ret As Boolean = False
            'Dim clsMsAuthorizegroupLinqDB As New MsAuthorizegroupLinqDB
            'With clsMsAuthorizegroupLinqDB
            '    ret = .DeleteByPK(id, trans.Trans)
            'End With
            'clsMsAuthorizegroupLinqDB = Nothing
            ret = SqlDB.ExecuteNonQuery("DELETE FROM MS_MEETING_ROOM_PROPERTY_ITEM WHERE MS_MEETING_ROOM_ID=" & id & ";DELETE FROM MS_MEETING_ROOM WHERE ID=" & id)
            'If ret = True Then
            '    trans.CommitTransaction()
            'Else
            '    trans.RollbackTransaction()
            'End If

            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function
#End Region

#Region "Room Type"

    <WebMethod()> _
    Public Function LoadRoomTypeAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            strSql.Append(" ,r.id")
            strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,r.room_type_name")
            strSql.Append(" ,'' as room_type_desc")
            strSql.Append(" from ms_room_type r")
            strSql.Append(" order by r.room_type_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadActiveRoomType() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            strSql.Append(" ,r.id")
            strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,r.room_type_name")
            strSql.Append(" ,'' as room_type_desc")
            strSql.Append(" from ms_room_type r")
            strSql.Append(" where active_status ='Y'")
            strSql.Append(" order by r.room_type_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadRoomTypeBy(room_id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            strSql.Append(" ,r.id")
            strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,r.room_type_name")
            strSql.Append(" ,'' as room_type_desc")
            strSql.Append(" , (case  when isnull(mr.ms_room_type_id,'')='' then '' else 'selected' end) selected")
            strSql.Append(" from ms_room_type r")
            strSql.Append(" left join ms_meeting_room mr")
            strSql.Append(" on r.id = mr.ms_room_type_id and mr.id = " & Val(room_id))
            strSql.Append(" order by r.room_type_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function
#End Region

#Region "Optopn"

    <WebMethod()> _
    Public Function LoadOptionAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY p.id asc) AS no")
            strSql.Append(" ,p.id")
            strSql.Append(" ,(case when isnull(p.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,p.property_name")
            strSql.Append(" ,'' property_desc")
            strSql.Append(" from ms_room_property p")
            strSql.Append(" order by p.property_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadOptionBy(room_id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY p.id asc) AS no")
            strSql.Append(" ,p.id")
            strSql.Append(" ,(case when isnull(p.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,p.property_name")
            strSql.Append(" ,'' property_desc")
            strSql.Append(" , (case  when isnull(rp.ms_meeting_room_id,'')='' then '' else 'selected' end) selected")
            strSql.Append(" from ms_room_property p")
            strSql.Append(" left join ms_meeting_room_property_item rp")
            strSql.Append(" on p.id=rp.ms_room_property_id and ms_meeting_room_id = " & Val(room_id))
            strSql.Append(" where isnull(p.active_status ,'N')='Y' ")
            strSql.Append(" order by p.property_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function


    <WebMethod()> _
    Public Function LoadOptionById_ToString(room_id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY p.id asc) AS no")
            strSql.Append(" ,p.id")
            strSql.Append(" ,(case when isnull(p.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,p.property_name")
            strSql.Append(" ,'' property_desc")
            strSql.Append(" , (case  when isnull(rp.ms_meeting_room_id,'')='' then '' else 'selected' end) selected")
            strSql.Append(" from ms_room_property p")
            strSql.Append(" left join ms_meeting_room_property_item rp")
            strSql.Append(" on p.id=rp.ms_room_property_id and ms_meeting_room_id = " & Val(room_id))
            strSql.Append(" where isnull(p.active_status ,'N')='Y' ")
            strSql.Append(" order by p.property_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            Dim colums As Integer = 2
            Dim columsindex As Integer = 0
            Dim strTag As New StringBuilder
            Dim rows As Integer = Math.Floor(dt.Rows.Count / colums)
            For i As Integer = 1 To rows
                strTag.Append("<div class=""row-fluid"">")
                strTag.Append("<div class=""span12"">")
                For j As Integer = columsindex To colums
                    If columsindex <= dt.Rows.Count - 1 Then
                        strTag.Append("<label class=""inline"">")
                        strTag.Append("<input name=""option"" type=""checkbox"" value=" + dt.Rows(j)("id").ToString + "/>")
                        strTag.Append("<span class=""lbl"">" + dt.Rows(j)("property_name") + "</span>")
                        strTag.Append("</label>&nbsp;")
                    End If
                Next
                strTag.Append("</div>")
                strTag.Append("</div>")
                columsindex += colums + 1
                colums += colums + 1
            Next
            'For i As Integer = 0 To dt.Rows.Count - 1
            '    If i <= 3 Then

            '    End If
            '    If i = 0 Or i Mod 4 Then
            '        strTag.Append("<div class=""row-fluid"">")
            '        strTag.Append("<div class=""span12"">")
            '        For j As Integer = columsindex To colums - 1
            '            strTag.Append("<label class=""inline"">")
            '            strTag.Append("<input name=""option"" type=""checkbox"" value=" + dt.Rows(j)("id") + "/>")
            '            strTag.Append("<span class=""lbl"">" + dt.Rows(j)("property_name") + "</span>")
            '            strTag.Append("</label>&nbsp;")
            '        Next
            '        strTag.Append("</div>")
            '        strTag.Append("</div>")

            '        columsindex = columsindex + 1
            '    End If

            'Next


  
            Return strTag.ToString
        Catch ex As Exception
            Return ""
        End Try

    End Function


    <WebMethod()> _
    Public Function GetOptionById(id As String) As String
        Try
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable("SELECT * FROM MS_ROOM_PROPERTY WHERE ID=" & id)
            Return clsdtHelper.ConvertDataTableToJson(dt)

        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveOption(id As String, property_name As String, property_desc As String, userid As String, active As String) As String
        Try
            Dim trans As New TransactionDB
            Dim retStatus As String = False
            Dim ret As Boolean = False
            Dim dt As DataTable
            Dim clsMsRoomPropertyLinqDB As New MsRoomPropertyLinqDB
            With clsMsRoomPropertyLinqDB
                dt = .GetDataList("property_name='" & property_name.Trim & "' and id <>" & id, "", trans.Trans)
                If dt.Rows.Count > 0 Then
                    retStatus = Utility.DefaultStringStatusReturn.duplicate
                    Return retStatus
                End If
            End With

            clsMsRoomPropertyLinqDB = New MsRoomPropertyLinqDB
            With clsMsRoomPropertyLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = True Then
                    .PROPERTY_NAME = property_name
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .UpdateByPK(userid, trans.Trans)
                Else
                    .PROPERTY_NAME = property_name
                    .ACTIVE_STATUS = IIf(active = 0, "N", "Y")
                    ret = .InsertData(userid, trans.Trans)
                End If
            End With
            clsMsRoomPropertyLinqDB = Nothing
            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If

            If ret = True Then
                retStatus = Utility.DefaultStringStatusReturn.complete
            Else
                retStatus = Utility.DefaultStringStatusReturn.fail
            End If

            Return retStatus
        Catch ex As Exception
            Return Utility.DefaultStringStatusReturn.fail
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteOption(id As String) As Boolean
        Try
            Dim ret As Boolean = False
            ret = SqlDB.ExecuteNonQuery("DELETE FROM MS_ROOM_PROPERTY WHERE ID=" & id)
            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function
#End Region

#Region "Prefix"
    <WebMethod()> _
    Public Function LoadPrefixAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY pf.id asc) AS no")
            strSql.Append(" ,pf.id")
            strSql.Append(" ,(case when isnull(pf.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,pf.prefix_thai")
            strSql.Append(" ,pf.prefix_eng")
            strSql.Append(" from ms_prefix pf")
            strSql.Append(" order by pf.prefix_eng")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadPrefixBy(user_id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY pf.id asc) AS no")
            strSql.Append(" ,pf.id")
            strSql.Append(" ,(case when isnull(pf.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            strSql.Append(" ,pf.prefix_thai")
            strSql.Append(" ,pf.prefix_eng")
            strSql.Append(" , (case  when isnull(u.ms_prefix_id,'')='' then '' else 'selected' end) selected")
            strSql.Append(" from ms_prefix pf")
            strSql.Append(" left join ms_user u")
            strSql.Append(" on pf.id = u.ms_prefix_id and u.id = " & Val(user_id))
            strSql.Append(" where isnull(pf.active_status ,'N')='Y' ")
            strSql.Append(" order by pf.prefix_eng")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function
#End Region
#End Region

#Region "Visitor"
#Region "Blacklist"
    <WebMethod()> _
    Public Function LoadActivityByVisitor(id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select top 5")
            strSql.Append(" ts.id")
            strSql.Append(" ,r.room_name")
            strSql.Append(" ,dbo.GetDurationDate(convert(varchar(10),ts.end_time,101)) as duration")
            strSql.Append(" from ts_prebooking ts")
            strSql.Append(" inner join ts_prebooking_visitor tsv")
            strSql.Append(" on ts.id = tsv.ts_prebooking_id")
            strSql.Append(" inner join ms_meeting_room r")
            strSql.Append(" on ts.ms_meeting_room_id = r.id")
            strSql.Append(" inner join ts_visitor v")
            strSql.Append(" on v.id_cardno =tsv.id_cardno")
            strSql.Append(" where v.id=" & id)
            strSql.Append(" order by ts.end_time desc")
            dt = SqlDB.ExecuteTable(strSql.ToString)

            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                'Dim dtdetail As New DataTable
                'dtdetail.Columns.Add("id")
                'dtdetail.Columns.Add("room_name")
                'dtdetail.Columns.Add("duration")
                'Dim drdetail As DataRow

                'drdetail = dtdetail.NewRow
                'drdetail("id") = 1
                'drdetail("room_name") = "Room1"
                'drdetail("duration") = " 1 day ago"
                'dtdetail.Rows.Add(drdetail)

                'drdetail = dtdetail.NewRow
                'drdetail("id") = 2
                'drdetail("room_name") = "Room2"
                'drdetail("duration") = " 99 day ago"
                'dtdetail.Rows.Add(drdetail)

                'strdata = clsdtHelper.ConvertDataTableToJson(dtdetail)
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadActivityDetailByVisitor(id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ts.id")
            strSql.Append(" ,b.building_name ")
            strSql.Append(" ,r.floor ")
            strSql.Append(" ,r.room_name ")
            strSql.Append(" ,ts.purpose ")
            strSql.Append(" ,convert(varchar(10),ts.start_time,108) + ' to ' + convert(varchar(10), ts.end_time,108) as strtime ")
            strSql.Append(" ,convert(varchar(10),ts.start_time,103) + ' ' + convert(varchar(10),ts.start_time,108) + ' to ' + convert(varchar(10),ts.end_time,108)   as strdate ")
            strSql.Append(" ,dbo.GetDurationDate(convert(varchar(10),ts.end_time,101)) as duration ")
            strSql.Append(" from ts_prebooking ts ")
            strSql.Append(" inner join ms_meeting_room r ")
            strSql.Append(" on ts.ms_meeting_room_id = r.id ")
            strSql.Append(" inner join ms_building b ")
            strSql.Append(" on r.ms_building_id = b.id ")
            strSql.Append(" where ts.id=" & id)
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                Dim dtdetail As New DataTable
                dtdetail.Columns.Add("id")
                dtdetail.Columns.Add("building_name")
                dtdetail.Columns.Add("floor")
                dtdetail.Columns.Add("room_name")
                dtdetail.Columns.Add("purpose")
                dtdetail.Columns.Add("strtime")
                dtdetail.Columns.Add("strdate")
                Dim drdetail As DataRow

                drdetail = dtdetail.NewRow
                drdetail("id") = 1
                drdetail("building_name") = "building_name"
                drdetail("floor") = "floor"
                drdetail("room_name") = "room_name"
                drdetail("purpose") = "purpose purpose purpose purpose purpose purpose purpose purpose purpose purpose purpose purpose purpose purpose"
                drdetail("strtime") = "strtime"
                drdetail("strdate") = "strdate"
                dtdetail.Rows.Add(drdetail)

                strdata = clsdtHelper.ConvertDataTableToJson(dtdetail)
                'strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function


    <WebMethod()> _
    Public Function LoadBlackListAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append("select ROW_NUMBER() OVER(ORDER BY V.First_name_EN ) AS no,V.ID_CardNo as cardno,V.id")
            strSql.Append(" ,First_name_th + ' ' + Last_Name_TH as fullname_thai")
            strSql.Append(" ,First_name_EN + ' ' + Last_Name_EN as fullname_eng")
            strSql.Append(" ,V.address  ")
            strSql.Append(" ,B.blacklist_reason as season")
            strSql.Append(" from ts_visitor V")
            strSql.Append(" inner join ts_blacklist B")
            strSql.Append(" ON V.id = B.tb_visitor_id ")
            strSql.Append(" Where B.is_blacklist='Y'")
            strSql.Append(" Order by V.First_name_EN")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadVisitorAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ROW_NUMBER() OVER(ORDER BY V.First_name_EN ) AS no,V.ID_CardNo as cardno,V.id")
            strSql.Append("  ,First_name_th + ' ' + Last_Name_TH as fullname_thai")
            strSql.Append("  ,First_name_EN + ' ' + Last_Name_EN as fullname_eng")
            strSql.Append("  ,V.address  ")
            strSql.Append("  from TS_VISITOR V")
            strSql.Append(" left join ts_blacklist B")
            strSql.Append(" ON V.id = B.tb_visitor_id ")
            strSql.Append(" Where isnull(B.is_blacklist,'N')='N'")
            strSql.Append("  order by V.First_name_EN")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            If dt.Rows.Count > 0 Then
                strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Else
                strdata = "[]"
            End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveBlackList(ByVal strID As Object, userid As String) As Boolean
        Try

            Dim ret As Boolean = True
            Dim trans As New TransactionDB
            Dim clsTsBlacklistLinqDB As New TsBlacklistLinqDB
            Dim strTempID As Array = CType(strID, Array) 'Convert object to array
            Dim strTempSeason() As String
            Dim dtcheck As DataTable
            Dim id As String = "0"
            If strTempID.Length > 0 Then
                For i As Integer = 0 To strTempID.Length - 1
                    strTempSeason = strTempID(i).Split("#")
                    If strTempSeason.Length = 2 Then

                        clsTsBlacklistLinqDB = New TsBlacklistLinqDB
                        With clsTsBlacklistLinqDB
                            dtcheck = .GetDataList("TB_VISITOR_ID=" & strTempSeason(0), "", trans.Trans)
                        End With
                        clsTsBlacklistLinqDB = Nothing

                        If dtcheck.Rows.Count <> 0 Then
                            id = dtcheck.Rows(0)("id")
                        End If

                        clsTsBlacklistLinqDB = New TsBlacklistLinqDB
                        With clsTsBlacklistLinqDB
                            .GetDataByPK(id, trans.Trans)
                            If .HaveData = False Then
                                .BLACKLIST_DATE = Date.Now
                                .BLACKLIST_REASON = strTempSeason(1)
                                .TB_VISITOR_ID = strTempSeason(0)
                                .IS_BLACKLIST = "Y"
                                ret = .InsertData(userid, trans.Trans)
                            Else
                                .BLACKLIST_DATE = Date.Now
                                .BLACKLIST_REASON = strTempSeason(1)
                                .TB_VISITOR_ID = strTempSeason(0)
                                .IS_BLACKLIST = "Y"
                                ret = .UpdateByPK(userid, trans.Trans)
                            End If
                        End With
                        clsTsBlacklistLinqDB = Nothing

                    End If
                Next

            End If

            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If


            Return True

        Catch ex As Exception
            Return False
        End Try
    End Function

    <WebMethod()> _
    Public Function DeleteBlackList(id As String, userid As String) As Boolean
        Try
            Dim ret As Boolean = False

            ret = SqlDB.ExecuteNonQuery("UPDATE TS_BLACKLIST SET IS_BLACKLIST='N', updated_by='" & userid & "',updated_date=GETDATE()   WHERE TB_VISITOR_ID=" & id)
            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteVisitor(id As String) As Boolean
        Try
            Dim ret As Boolean = False
            Dim str As New StringBuilder
            str.Append("delete from ts_blacklist_enroll where  ts_blacklist_id in ( select id from ts_blacklist where tb_visitor_id = " & id & ");")
            str.Append("delete from ts_blacklist where tb_visitor_id = " & id & ";")
            str.Append("delete from ts_visitor where id = " & id & ";")
            'ret = SqlDB.ExecuteNonQuery("DELETE TS_VISITOR   WHERE ID=" & id)
            ret = SqlDB.ExecuteNonQuery(str.ToString)
            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function

    <WebMethod()> _
    Public Function UpdateReason(id As String, reason As String, userid As String) As Boolean
        Try
            Dim ret As Boolean = False
            ret = SqlDB.ExecuteNonQuery("UPDATE TS_BLACKLIST SET blacklist_reason='" & reason & "',updated_by='" & userid & "',updated_date=GETDATE()  WHERE TB_VISITOR_ID=" & id)
            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function

    <WebMethod()> _
    Public Function GetBlackListBy(id As String) As String
        Try
            Dim ret As Boolean = False
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable("SELECT * FROM TS_BLACKLIST WHERE TB_VISITOR_ID=" & id)
            If dt.Rows.Count > 0 Then
                Return clsdtHelper.ConvertDataTableToJson(dt)
            Else
                Return "[]"
            End If

        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function GetVisitorDetailById(id As String) As String
        Try

            Dim dt As DataTable
            Dim strSQl As New StringBuilder
            strSQl.Append(" select ROW_NUMBER() OVER(ORDER BY U.id asc) AS no,U.id")
            strSQl.Append(" ,First_name_th + ' ' + Last_Name_TH as fullname_thai")
            strSQl.Append(" ,First_name_EN + ' ' + Last_Name_EN as fullname_eng")
            strSQl.Append(" ,U.address")
            strSQl.Append(" ,U.id_cardno")
            strSQl.Append(" ,convert(varchar(10),U.birthdate,103) as birthdate")
            strSQl.Append(" ,convert(varchar(10),U.issuedate,103) as issuedate")
            strSQl.Append(" ,convert(varchar(10),U.expdate,103) as expdate")
            strSQl.Append(" ,U.id_picture")
            strSQl.Append(" ,B.blacklist_reason as reason ")
            strSQl.Append(" ,isnull(B.is_blacklist,'N') as is_blacklist")
            strSQl.Append(" from ts_visitor U")
            strSQl.Append(" LEFT JOIN ts_blacklist B")
            strSQl.Append(" on U.id= B.tb_visitor_id  where u.id = " & id & " Order by U.First_Name_EN")
            dt = SqlDB.ExecuteTable(strSQl.ToString)
            If dt.Rows.Count <> 0 Then
                Dim dtreturn As New DataTable
                Dim drreturn As DataRow
                dtreturn.Columns.Add("id")
                dtreturn.Columns.Add("fullname_thai")
                dtreturn.Columns.Add("fullname_eng")
                dtreturn.Columns.Add("address")
                dtreturn.Columns.Add("id_cardno")
                dtreturn.Columns.Add("birthdate")
                dtreturn.Columns.Add("issuedate")
                dtreturn.Columns.Add("expdate")
                dtreturn.Columns.Add("id_picture")
                dtreturn.Columns.Add("reason")
                dtreturn.Columns.Add("is_blacklist")

                'Base64 string   convert byte to base64string
                Dim strimagebase64 As String = ""
                If Not IsDBNull(dt.Rows(0)("id_picture")) Then
                    strimagebase64 = Convert.ToBase64String(dt.Rows(0)("id_picture"))
                End If


                drreturn = dtreturn.NewRow()
                drreturn("id") = dt.Rows(0)("id") & ""
                drreturn("fullname_thai") = dt.Rows(0)("fullname_thai") & ""
                drreturn("fullname_eng") = dt.Rows(0)("fullname_eng") & ""
                drreturn("address") = dt.Rows(0)("address") & ""
                drreturn("id_cardno") = dt.Rows(0)("id_cardno") & ""
                drreturn("birthdate") = dt.Rows(0)("birthdate") & ""
                drreturn("issuedate") = dt.Rows(0)("issuedate") & ""
                drreturn("expdate") = dt.Rows(0)("expdate") & ""
                drreturn("id_picture") = strimagebase64
                drreturn("reason") = dt.Rows(0)("reason") & ""
                drreturn("is_blacklist") = dt.Rows(0)("is_blacklist") & ""
                dtreturn.Rows.Add(drreturn)

                Return clsdtHelper.ConvertDataTableToJson(dtreturn)
            Else
                Return "[]"
            End If

            ' Return ret
        Catch ex As Exception
            Return "[]"
        End Try

    End Function


    <WebMethod()> _
    Public Function InsertOrUpdateReason(tb_visitor_id As String, reason As String, is_blacklist As String, userid As String) As Boolean
        Try
            Dim ret As Boolean = False
            If is_blacklist = "N" Then
                ret = SqlDB.ExecuteNonQuery("UPDATE TS_BLACKLIST SET is_blacklist='N', blacklist_reason='',updated_by='" & userid & "',updated_date=GETDATE()  WHERE tb_visitor_id=" & tb_visitor_id)
            ElseIf is_blacklist = "Y" Then
                Dim trans As New TransactionDB
                Dim id As String = "0"
                Dim dtcheck As DataTable
                Dim clsTsBlacklistLinqDB As New TsBlacklistLinqDB
                With clsTsBlacklistLinqDB
                    dtcheck = .GetDataList("TB_VISITOR_ID=" & tb_visitor_id, "", trans.Trans)
                End With
                clsTsBlacklistLinqDB = Nothing

                If dtcheck.Rows.Count <> 0 Then
                    id = dtcheck.Rows(0)("id")
                End If

                clsTsBlacklistLinqDB = New TsBlacklistLinqDB
                With clsTsBlacklistLinqDB
                    .GetDataByPK(id, trans.Trans)
                    If .HaveData = False Then
                        .BLACKLIST_DATE = Date.Now
                        .BLACKLIST_REASON = reason
                        .TB_VISITOR_ID = tb_visitor_id
                        .IS_BLACKLIST = "Y"
                        ret = .InsertData(userid, trans.Trans)
                    Else
                        .BLACKLIST_DATE = Date.Now
                        .BLACKLIST_REASON = reason
                        .TB_VISITOR_ID = tb_visitor_id
                        .IS_BLACKLIST = "Y"
                        ret = .UpdateByPK(userid, trans.Trans)
                    End If
                End With
                clsTsBlacklistLinqDB = Nothing

                If ret = True Then
                    trans.CommitTransaction()
                Else
                    trans.RollbackTransaction()
                End If

            End If
            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function

#End Region

#Region "Contract"
    <WebMethod()> _
    Public Function LoadVisitorByContract(id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY pv.visitor_name ) AS no")
            strSql.Append(" ,id")
            strSql.Append(" ,id_cardno")
            strSql.Append(" ,visitor_name")
            strSql.Append(" ,visitor_company_name")
            strSql.Append(" from ts_prebooking_visitor pv")
            strSql.Append(" where ts_prebooking_id = " & id)
            strSql.Append(" order by  pv.visitor_name ")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'If dt.Rows.Count > 0 Then
            '    strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'Else
            '    strdata = "[]"
            'End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadContractAll() As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY p.start_time ) AS no ")
            strSql.Append(" ,p.id ")
            strSql.Append(" ,b.building_name ")
            strSql.Append(" ,mr.room_name ")
            strSql.Append(" ,mr.floor ")
            strSql.Append(" ,p.purpose ")
            strSql.Append(" ,convert(varchar(10),start_time,103) as  meetingdate ")
            strSql.Append(" ,left(convert(varchar,start_time,108),5) + '-' + left(convert(varchar,end_time,108),5)  as  meetingtime ")
            strSql.Append(" ,convert(varchar,start_contract_date,103) + '-' + convert(varchar,end_contract_date,103)  as  meetingcontractdate ")
            strSql.Append(" ,start_contract_time + '-' + end_contract_time  as  meetingcontracttime ")
            strSql.Append(" from ts_prebooking p ")
            strSql.Append(" left join ms_meeting_room mr ")
            strSql.Append(" on p.ms_meeting_room_id = mr.id ")
            strSql.Append(" left join ms_building b ")
            strSql.Append(" on mr.ms_building_id= b.id ")
            strSql.Append(" where p.is_contract ='Y' ")
            strSql.Append(" order by start_time desc ")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'If dt.Rows.Count > 0 Then
            '    strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'Else
            '    strdata = "[]"
            'End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadBookingBy(strcontition As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" ROW_NUMBER() OVER(ORDER BY p.start_time ) AS no ")
            strSql.Append(" ,p.id ")
            strSql.Append(" ,b.building_name ")
            strSql.Append(" ,mr.room_name ")
            strSql.Append(" ,mr.floor ")
            strSql.Append(" ,p.purpose ")
            strSql.Append(" ,convert(varchar(10),start_time,103) as  meetingdate ")
            strSql.Append(" ,left(convert(varchar,start_time,108),5) + '-' + left(convert(varchar,end_time,108),5)  as  meetingtime ")
            strSql.Append(" ,convert(varchar,start_contract_date,103) as  meetingcontractdate ")
            strSql.Append(" ,start_contract_time + '-' + end_contract_time  as  meetingcontracttime ")
            strSql.Append(" from ts_prebooking p ")
            strSql.Append(" left join ms_meeting_room mr ")
            strSql.Append(" on p.ms_meeting_room_id = mr.id ")
            strSql.Append(" left join ms_building b ")
            strSql.Append(" on mr.ms_building_id= b.id ")
            strSql.Append(" where p.is_contract ='N' ")
            If strcontition <> "" Then
                strSql.Append(" " & strcontition)
            End If
            strSql.Append(" order by start_time desc ")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'If dt.Rows.Count > 0 Then
            '    strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'Else
            '    strdata = "[]"
            'End If
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function SaveContract(id As String _
                                 , startdate As String _
                                 , enddate As String _
                                 , starttime As String _
                                 , endtime As String _
                                 , room_id As String _
                                 , purpose As String _
                                 , strvisitor As Object _
                                 , active_status As String _
                                 , userid As String) As Boolean
        Try

            Dim tempstartdate As Date = Date.ParseExact(startdate, "dd/MM/yyyy",
                       System.Globalization.DateTimeFormatInfo.InvariantInfo)
            Dim tempenddate As Date = Date.ParseExact(enddate, "dd/MM/yyyy",
                 System.Globalization.DateTimeFormatInfo.InvariantInfo)

            Dim tempdatetest As Date = Date.Now
            Dim jsonString As String = strvisitor
            Dim dtJson As DataTable = clsdtHelper.ConvertJSONToDataTable(jsonString)

            Dim strtempid As String
            Dim ret As Boolean = True
            Dim trans As New TransactionDB

            Dim clsTsPrebookingLinqDB As New TsPrebookingLinqDB

            With clsTsPrebookingLinqDB
                .GetDataByPK(id, trans.Trans)
                If .HaveData = False Then
                    .MS_USER_ID_BOOKING = userid
                    .MS_MEETING_ROOM_ID = room_id
                    .PURPOSE = purpose
                    .RESERVE_DATE = Date.Now
                    ' .USE_DATE = tempdatetest
                    .START_CONTRACT_DATE = tempstartdate
                    .END_CONTRACT_DATE = tempenddate
                    .START_CONTRACT_TIME = starttime
                    '  .START_TIME = tempdatetest
                    ' .END_TIME = tempdatetest
                    .END_CONTRACT_TIME = endtime
                    .IS_CONTRACT = "Y"
                    .ACTIVE_STATUS = active_status
                    ret = .InsertData(id, trans.Trans)
                Else
                    .MS_USER_ID_BOOKING = userid
                    .MS_MEETING_ROOM_ID = room_id
                    .PURPOSE = purpose
                    .RESERVE_DATE = Date.Now
                    ' .USE_DATE = tempdatetest
                    .START_CONTRACT_DATE = tempstartdate
                    .END_CONTRACT_DATE = tempenddate
                    .START_CONTRACT_TIME = starttime
                    '  .START_TIME = tempdatetest
                    ' .END_TIME = tempdatetest
                    .END_CONTRACT_TIME = endtime
                    .IS_CONTRACT = "Y"
                    .ACTIVE_STATUS = active_status
                    ret = .UpdateByPK(id, trans.Trans)
                End If

                strtempid = .ID

            End With


            dtJson.Rows.RemoveAt(dtJson.Rows.Count - 1)
            dtJson.AcceptChanges()

            Dim dttemp As DataTable
            Dim clsTsPrebookingVisitorLinqDB As New TsPrebookingVisitorLinqDB

            ret = SqlDB.ExecuteNonQuery("DELETE TS_PREBOOKING_VISITOR WHERE TS_PREBOOKING_ID=" & strtempid)

            For i As Integer = 0 To dtJson.Rows.Count - 1
                clsTsPrebookingVisitorLinqDB = New TsPrebookingVisitorLinqDB
                With clsTsPrebookingVisitorLinqDB
                    dttemp = .GetDataList("id_cardno=" & dtJson(i)("id_cardno") & " and ts_prebooking_id=" & strtempid, "", trans.Trans)
                    If dttemp.Rows.Count > 0 Then
                        .GetDataByPK(dttemp(0)("id"), trans.Trans)
                        .ID_CARDNO = dtJson(i)("id_cardno")
                        .TS_PREBOOKING_ID = strtempid
                        .VISITOR_NAME = dtJson(i)("visitor_name")
                        .VISITOR_COMPANY_NAME = dtJson(i)("visitor_company_name")
                        ret = .UpdateByPK(userid, trans.Trans)
                    Else
                        .ID_CARDNO = dtJson(i)("id_cardno")
                        .TS_PREBOOKING_ID = strtempid
                        .VISITOR_NAME = dtJson(i)("visitor_name")
                        .VISITOR_COMPANY_NAME = dtJson(i)("visitor_company_name")
                        ret = .InsertData(userid, trans.Trans)
                    End If
                End With
            Next

            If ret = True Then
                trans.CommitTransaction()
            Else
                trans.RollbackTransaction()
            End If
            Return ret
        Catch ex As Exception
            Return False
        End Try
    End Function

    <WebMethod()> _
    Public Function GetContractById(id As String) As String
        Try
            Dim strSql As New StringBuilder
            strSql.Append(" select ")
            strSql.Append(" pb.id ")
            strSql.Append(" ,convert(varchar,pb.start_time,103) as start_date ")
            strSql.Append(" ,convert(varchar,pb.end_time,103) as end_date ")
            strSql.Append(" ,left(convert(varchar,pb.start_time,108),5) as start_time ")
            strSql.Append(" ,left(convert(varchar,pb.end_time,108),5) as end_time ")
            strSql.Append(" ,convert(varchar,pb.start_contract_date,103) as start_contract_date ")
            strSql.Append(" ,convert(varchar,pb.end_contract_date,103) as end_contract_date ")
            strSql.Append(" ,pb.start_contract_time ")
            strSql.Append(" ,pb.end_contract_time ")
            strSql.Append(" ,pb.ms_meeting_room_id ")
            strSql.Append(" ,mr.ms_building_id ")
            strSql.Append(" ,pb.purpose ")
            strSql.Append(" ,mr.room_name ")
            strSql.Append(" ,b.building_name ")
            strSql.Append(" ,pb.active_status ")
            strSql.Append(" from ts_prebooking pb ")
            strSql.Append(" inner join ms_meeting_room mr ")
            strSql.Append(" on mr.id= pb.ms_meeting_room_id ")
            strSql.Append(" left join ms_building b ")
            strSql.Append(" on b.id= mr.ms_building_id ")
            strSql.Append(" where pb.id=" & id)
            Dim dt As DataTable
            dt = SqlDB.ExecuteTable(strSql.ToString)
            Return clsdtHelper.ConvertDataTableToJson(dt)
            ' Return ret
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadBuildingByValue(id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" b.id ")
            strSql.Append(" ,(case when isnull(b.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc ")
            strSql.Append(" ,b.building_name ")
            strSql.Append(" ,'' building_desc ")
            strSql.Append(" , (case  when b.id <> " & id & " then '' else 'selected' end) selected ")
            strSql.Append(" from ms_building b ")
            strSql.Append(" order by building_name ")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function LoadRoomByValue(id As String) As String
        Try
            Dim dt As DataTable
            Dim strSql As New StringBuilder
            Dim strdata As String
            strSql.Append(" select ")
            strSql.Append(" mr.id ")
            strSql.Append(" ,(case when isnull(mr.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc ")
            strSql.Append(" ,mr.room_name ")
            strSql.Append(" ,'' room_desc ")
            strSql.Append(" , (case  when mr.id <> " & id & " then '' else 'selected' end) selected ")
            strSql.Append(" from ms_meeting_room mr ")
            strSql.Append(" order by mr.room_name ")

            dt = SqlDB.ExecuteTable(strSql.ToString)
            strdata = clsdtHelper.ConvertDataTableToJson(dt)
            Return strdata
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Public Function DeleteContract(id As String) As Boolean
        Try
            Dim ret As Boolean = False
            Dim str As New StringBuilder
            str.Append("delete from ts_prebooking_visitor where ts_prebooking_id = " & id & ";")
            str.Append("delete from ts_prebooking where id = " & id & ";")
            ret = SqlDB.ExecuteNonQuery(str.ToString)
            Return ret
        Catch ex As Exception
            Return False
        End Try

    End Function
#End Region
#End Region

#Region "Report"

    <WebMethod()> _
    Public Function GetdataforBookingDialy(buildingid As String, roomid As String, datefrom As String, dateto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = " select reserve_date,use_date,TSB.purpose,ms_meeting_room_id,ms_user_id_booking "
            strSql &= " ,TSBV.id_cardno,visitor_name,visitor_company_name"
            strSql &= " ,MSP.prefix_eng +' ' + name_eng +' ' + surname_eng as userbooking"
            strSql &= " ,MSR.room_name,MSB.building_name,ms_building_id"
            strSql &= " from TS_PREBOOKING TSB "
            strSql &= " inner join TS_PREBOOKING_VISITOR TSBV on TSB.id = TSBV.ts_prebooking_id"
            strSql &= " inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= " inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= " inner join MS_ROOM_TYPE MSRT on MSR.ms_room_type_id=MSRT.id"
            strSql &= " inner join MS_USER MSU on TSB.ms_user_id_booking = MSU.id"
            strSql &= " inner join MS_PREFIX MSP ON MSU.ms_prefix_id = MSP.id where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and ms_building_id ='" & buildingid & "'"
            End If

            If roomid <> "" Then
                strSql &= " and ms_meeting_room_id ='" & roomid & "'"
            End If

            If datefrom <> "" And dateto <> "" Then
                strSql &= " and convert(varchar(10),use_date,103) between '" & datefrom & "' and '" & dateto & "'"
            End If

            strSql &= " order by reserve_date desc"

            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("reserve_date") = "12/12/2014"
                dr("use_date") = "12/12/2014"
                dr("purpose") = "xxxx"
                dr("ms_meeting_room_id") = "1"
                dr("ms_user_id_booking") = "1"
                dr("id_cardno") = "1331000014254"
                dr("visitor_name") = "nongnuch"
                dr("visitor_company_name") = "score"
                dr("userbooking") = "xxx"
                dr("room_name") = "xxx"
                dr("building_name") = "xxx"
                dr("ms_building_id") = "1"
                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    <WebMethod()> _
    Public Function RenderBookingDialy(buildingid As String, roomid As String, datefrom As String, dateto As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforBookingDialy(buildingid, roomid, datefrom, dateto)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "use_date", _
                                            "reserve_date", _
                                            "room_name", _
                                            "building_name", _
                                            "purpose", _
                                            "id_cardno", _
                                            "visitor_name", _
                                            "visitor_company_name", _
                                            "userbooking"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1
                    Dim use_date As String = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim reserve_date As String = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim room_name As String = dt.Rows(i)("room_name").ToString
                    Dim building_name As String = dt.Rows(i)("building_name").ToString
                    Dim purpose As String = dt.Rows(i)("purpose").ToString
                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim visitor_name As String = dt.Rows(i)("visitor_name").ToString
                    Dim visitor_company_name As String = dt.Rows(i)("visitor_company_name").ToString
                    Dim userbooking As String = dt.Rows(i)("userbooking").ToString

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='center' >" & use_date & "</td>")
                    ret.Append("        <td align='center' >" & reserve_date & "</td>")
                    ret.Append("        <td align='left' >" & room_name & "</td>")
                    ret.Append("        <td align='left' >" & building_name & "</td>")
                    ret.Append("        <td align='left' >" & purpose & "</td>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & visitor_name & "</td>")
                    ret.Append("        <td align='left' >" & visitor_company_name & "</td>")
                    ret.Append("        <td align='left' >" & userbooking & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

    <WebMethod()> _
    Public Function GetdataforBookingMonthly(buildingid As String, roomid As String, yearfrom As String, yearto As String, monthfrom As String, monthto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = "  select reserve_date,use_date,TSB.purpose,ms_meeting_room_id,ms_user_id_booking "
            strSql &= " ,TSBV.id_cardno,visitor_name,visitor_company_name"
            strSql &= " ,MSP.prefix_eng +' ' + name_eng +' ' + surname_eng as userbooking"
            strSql &= " ,MSR.room_name,MSB.building_name,ms_building_id"
            strSql &= " from TS_PREBOOKING TSB "
            strSql &= " inner join TS_PREBOOKING_VISITOR TSBV on TSB.id = TSBV.ts_prebooking_id"
            strSql &= " inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= " inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= " inner join MS_ROOM_TYPE MSRT on MSR.ms_room_type_id=MSRT.id"
            strSql &= " inner join MS_USER MSU on TSB.ms_user_id_booking = MSU.id"
            strSql &= " inner join MS_PREFIX MSP ON MSU.ms_prefix_id = MSP.id where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and ms_building_id ='" & buildingid & "'"
            End If

            If roomid <> "" Then
                strSql &= " and ms_meeting_room_id ='" & roomid & "'"
            End If

            If yearfrom <> "" And yearto <> "" And monthfrom <> "" And monthto <> "" Then
                monthfrom = monthfrom.PadLeft(2, "0")
                monthto = monthto.PadLeft(2, "0")
                strSql &= " and convert(varchar(6),use_date,112) between '" & yearfrom & monthfrom & "' and '" & yearto & monthto & "'"
            End If
            strSql &= " order by reserve_date desc"

            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("use_date") = "12/12/2014"
                dr("reserve_date") = "12/12/2014"
                dr("purpose") = "xxxx"
                dr("ms_meeting_room_id") = "1"
                dr("ms_user_id_booking") = "1"
                dr("id_cardno") = "1331000014254"
                dr("visitor_name") = "nongnuch"
                dr("visitor_company_name") = "score"
                dr("userbooking") = "xxx"
                dr("room_name") = "xxx"
                dr("building_name") = "xxx"
                dr("ms_building_id") = "1"
                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    <WebMethod()> _
    Public Function RenderBookingMonthly(buildingid As String, roomid As String, yearfrom As String, yearto As String, monthfrom As String, monthto As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforBookingMonthly(buildingid, roomid, yearfrom, yearto, monthfrom, monthto)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "use_date", _
                                            "reserve_date", _
                                            "room_name", _
                                            "building_name", _
                                            "purpose", _
                                            "id_cardno", _
                                            "visitor_name", _
                                            "visitor_company_name", _
                                            "userbooking"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1
                    Dim use_date As String = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim reserve_date As String = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim room_name As String = dt.Rows(i)("room_name").ToString
                    Dim building_name As String = dt.Rows(i)("building_name").ToString
                    Dim purpose As String = dt.Rows(i)("purpose").ToString
                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim visitor_name As String = dt.Rows(i)("visitor_name").ToString
                    Dim visitor_company_name As String = dt.Rows(i)("visitor_company_name").ToString
                    Dim userbooking As String = dt.Rows(i)("userbooking").ToString

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='center' >" & use_date & "</td>")
                    ret.Append("        <td align='center' >" & reserve_date & "</td>")
                    ret.Append("        <td align='left' >" & room_name & "</td>")
                    ret.Append("        <td align='left' >" & building_name & "</td>")
                    ret.Append("        <td align='left' >" & purpose & "</td>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & visitor_name & "</td>")
                    ret.Append("        <td align='left' >" & visitor_company_name & "</td>")
                    ret.Append("        <td align='left' >" & userbooking & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

    <WebMethod()> _
    Public Function GetdataforBookingDepartment(buildingid As String, roomid As String, department As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = "  select reserve_date,use_date,TSB.purpose,ms_meeting_room_id,ms_user_id_booking "
            strSql &= " ,TSBV.id_cardno,visitor_name,visitor_company_name"
            strSql &= " ,MSP.prefix_eng +' ' + name_eng +' ' + surname_eng as userbooking"
            strSql &= " ,MSR.room_name,MSB.building_name,ms_building_id,MSU.ms_department_id,MSD.department_name"
            strSql &= " from TS_PREBOOKING TSB "
            strSql &= " inner join TS_PREBOOKING_VISITOR TSBV on TSB.id = TSBV.ts_prebooking_id"
            strSql &= " inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= " inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= " inner join MS_ROOM_TYPE MSRT on MSR.ms_room_type_id=MSRT.id"
            strSql &= " inner join MS_USER MSU on TSB.ms_user_id_booking = MSU.id"
            strSql &= " inner join MS_PREFIX MSP ON MSU.ms_prefix_id = MSP.id "
            strSql &= " inner join MS_DEPARTMENT MSD on MSU.ms_department_id =MSD.id"
            strSql &= " where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and ms_building_id ='" & buildingid & "'"
            End If

            If roomid <> "" Then
                strSql &= " and ms_meeting_room_id ='" & roomid & "'"
            End If

            If department <> "" Then
                strSql &= " and MSU.ms_department_id ='" & department & "'"
            End If
            strSql &= " order by reserve_date desc,department_name asc"

            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("use_date") = "12/12/2014"
                dr("reserve_date") = "12/12/2014"
                dr("department_name") = "xxxx"
                dr("purpose") = "xxxx"
                dr("ms_meeting_room_id") = "1"
                dr("ms_user_id_booking") = "1"
                dr("id_cardno") = "1331000014254"
                dr("visitor_name") = "nongnuch"
                dr("visitor_company_name") = "score"
                dr("userbooking") = "xxx"
                dr("room_name") = "xxx"
                dr("building_name") = "xxx"
                dr("ms_building_id") = "1"
                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    <WebMethod()> _
    Public Function RenderBookingDepartment(buildingid As String, roomid As String, department As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforBookingDepartment(buildingid, roomid, department)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "use_date", _
                                            "reserve_date", _
                                            "department", _
                                            "room_name", _
                                            "building_name", _
                                            "purpose", _
                                            "id_cardno", _
                                            "visitor_name", _
                                            "visitor_company_name", _
                                            "userbooking"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1
                    Dim use_date As String = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim reserve_date As String = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim room_name As String = dt.Rows(i)("room_name").ToString
                    Dim building_name As String = dt.Rows(i)("building_name").ToString
                    Dim purpose As String = dt.Rows(i)("purpose").ToString
                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim visitor_name As String = dt.Rows(i)("visitor_name").ToString
                    Dim visitor_company_name As String = dt.Rows(i)("visitor_company_name").ToString
                    Dim userbooking As String = dt.Rows(i)("userbooking").ToString
                    Dim departmentname As String = dt.Rows(i)("department_name").ToString

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='center' >" & use_date & "</td>")
                    ret.Append("        <td align='center' >" & reserve_date & "</td>")
                    ret.Append("        <td align='left' >" & departmentname & "</td>")
                    ret.Append("        <td align='left' >" & room_name & "</td>")
                    ret.Append("        <td align='left' >" & building_name & "</td>")
                    ret.Append("        <td align='left' >" & purpose & "</td>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & visitor_name & "</td>")
                    ret.Append("        <td align='left' >" & visitor_company_name & "</td>")
                    ret.Append("        <td align='left' >" & userbooking & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

    <WebMethod()> _
    Public Function GetdataforBookingRoomType(buildingid As String, roomtype As String, datefrom As String, dateto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = "  select reserve_date,use_date,TSB.purpose,ms_meeting_room_id,ms_user_id_booking "
            strSql &= " ,TSBV.id_cardno,visitor_name,visitor_company_name"
            strSql &= " ,MSP.prefix_eng +' ' + name_eng +' ' + surname_eng as userbooking"
            strSql &= " ,MSR.room_name,MSB.building_name,ms_building_id"
            strSql &= " from TS_PREBOOKING TSB "
            strSql &= " inner join TS_PREBOOKING_VISITOR TSBV on TSB.id = TSBV.ts_prebooking_id"
            strSql &= " inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= " inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= " inner join MS_ROOM_TYPE MSRT on MSR.ms_room_type_id=MSRT.id"
            strSql &= " inner join MS_USER MSU on TSB.ms_user_id_booking = MSU.id"
            strSql &= " inner join MS_PREFIX MSP ON MSU.ms_prefix_id = MSP.id where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and ms_building_id ='" & buildingid & "'"
            End If

            If roomtype <> "" Then
                strSql &= " and ms_room_type_id ='" & roomtype & "'"
            End If

            If datefrom <> "" And dateto <> "" Then
                strSql &= " and convert(varchar(10),use_date,103) between '" & datefrom & "' and '" & dateto & "'"
            End If
            strSql &= " order by reserve_date desc"
            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("reserve_date") = "12/12/2014"
                dr("use_date") = "12/12/2014"
                dr("purpose") = "xxxx"
                dr("ms_meeting_room_id") = "1"
                dr("ms_user_id_booking") = "1"
                dr("id_cardno") = "1331000014254"
                dr("visitor_name") = "nongnuch"
                dr("visitor_company_name") = "score"
                dr("userbooking") = "xxx"
                dr("room_name") = "xxx"
                dr("building_name") = "xxx"
                dr("ms_building_id") = "1"
                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    <WebMethod()> _
    Public Function RenderBookingRoomType(buildingid As String, roomtype As String, datefrom As String, dateto As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforBookingRoomType(buildingid, roomtype, datefrom, dateto)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "use_date", _
                                            "reserve_date", _
                                            "room_name", _
                                            "building_name", _
                                            "purpose", _
                                            "id_cardno", _
                                            "visitor_name", _
                                            "visitor_company_name", _
                                            "userbooking"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1
                    Dim use_date As String = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim reserve_date As String = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim room_name As String = dt.Rows(i)("room_name").ToString
                    Dim building_name As String = dt.Rows(i)("building_name").ToString
                    Dim purpose As String = dt.Rows(i)("purpose").ToString
                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim visitor_name As String = dt.Rows(i)("visitor_name").ToString
                    Dim visitor_company_name As String = dt.Rows(i)("visitor_company_name").ToString
                    Dim userbooking As String = dt.Rows(i)("userbooking").ToString

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='center' >" & use_date & "</td>")
                    ret.Append("        <td align='center' >" & reserve_date & "</td>")
                    ret.Append("        <td align='left' >" & room_name & "</td>")
                    ret.Append("        <td align='left' >" & building_name & "</td>")
                    ret.Append("        <td align='left' >" & purpose & "</td>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & visitor_name & "</td>")
                    ret.Append("        <td align='left' >" & visitor_company_name & "</td>")
                    ret.Append("        <td align='left' >" & userbooking & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

    <WebMethod()> _
    Public Function GetdataforBookingPersonal(buildingid As String, roomid As String, personal As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = "  select reserve_date,use_date,TSB.purpose,ms_meeting_room_id,ms_user_id_booking "
            strSql &= " ,TSBV.id_cardno,visitor_name,visitor_company_name"
            strSql &= " ,MSP.prefix_eng +' ' + name_eng +' ' + surname_eng as userbooking"
            strSql &= " ,MSR.room_name,MSB.building_name,ms_building_id,MSU.ms_department_id,MSD.department_name"
            strSql &= " from TS_PREBOOKING TSB "
            strSql &= " inner join TS_PREBOOKING_VISITOR TSBV on TSB.id = TSBV.ts_prebooking_id"
            strSql &= " inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= " inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= " inner join MS_ROOM_TYPE MSRT on MSR.ms_room_type_id=MSRT.id"
            strSql &= " inner join MS_USER MSU on TSB.ms_user_id_booking = MSU.id"
            strSql &= " inner join MS_PREFIX MSP ON MSU.ms_prefix_id = MSP.id "
            strSql &= " inner join MS_DEPARTMENT MSD on MSU.ms_department_id =MSD.id"
            strSql &= " where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and ms_building_id ='" & buildingid & "'"
            End If

            If roomid <> "" Then
                strSql &= " and ms_meeting_room_id ='" & roomid & "'"
            End If

            If personal <> "" Then
                strSql &= " and (name_eng Like '%" & personal & "%' or surname_eng Like '%" & personal & "%' or name_thai Like '%" & personal & "%' or surname_thai Like '%" & personal & "%')"
            End If
            strSql &= " order by reserve_date desc,name_eng,surname_eng"

            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("use_date") = "12/12/2014"
                dr("reserve_date") = "12/12/2014"
                dr("department_name") = "xxxx"
                dr("purpose") = "xxxx"
                dr("ms_meeting_room_id") = "1"
                dr("ms_user_id_booking") = "1"
                dr("id_cardno") = "1331000014254"
                dr("visitor_name") = "nongnuch"
                dr("visitor_company_name") = "score"
                dr("userbooking") = "xxx"
                dr("room_name") = "xxx"
                dr("building_name") = "xxx"
                dr("ms_building_id") = "1"
                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    <WebMethod()> _
    Public Function RenderBookingPersonal(buildingid As String, roomid As String, personal As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforBookingDepartment(buildingid, roomid, personal)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "use_date", _
                                            "reserve_date", _
                                            "department", _
                                            "room_name", _
                                            "building_name", _
                                            "purpose", _
                                            "id_cardno", _
                                            "visitor_name", _
                                            "visitor_company_name", _
                                            "userbooking"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1
                    Dim use_date As String = Convert.ToDateTime(dt.Rows(i)("use_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim reserve_date As String = Convert.ToDateTime(dt.Rows(i)("reserve_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim room_name As String = dt.Rows(i)("room_name").ToString
                    Dim building_name As String = dt.Rows(i)("building_name").ToString
                    Dim purpose As String = dt.Rows(i)("purpose").ToString
                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim visitor_name As String = dt.Rows(i)("visitor_name").ToString
                    Dim visitor_company_name As String = dt.Rows(i)("visitor_company_name").ToString
                    Dim userbooking As String = dt.Rows(i)("userbooking").ToString
                    Dim departmentname As String = dt.Rows(i)("department_name").ToString

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='center' >" & use_date & "</td>")
                    ret.Append("        <td align='center' >" & reserve_date & "</td>")
                    ret.Append("        <td align='left' >" & departmentname & "</td>")
                    ret.Append("        <td align='left' >" & room_name & "</td>")
                    ret.Append("        <td align='left' >" & building_name & "</td>")
                    ret.Append("        <td align='left' >" & purpose & "</td>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & visitor_name & "</td>")
                    ret.Append("        <td align='left' >" & visitor_company_name & "</td>")
                    ret.Append("        <td align='left' >" & userbooking & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

    <WebMethod()> _
    Public Function GetdataforVisitorDaily(buildingid As String, roomid As String, datefrom As String, dateto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = "  select id_cardno,First_Name_EN + ' ' + Last_Name_EN as name,staff_name,"
            strSql &= " place,TSV.purpose,in_date,out_date from TS_VISITOR TSV "
            strSql &= " inner Join TS_PREBOOKING TSB on TSV.ts_prebooking_id =TSB.id"
            strSql &= " inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= " inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= " where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and  MSR.ms_building_id ='" & buildingid & "'"
            End If

            If roomid <> "" Then
                strSql &= " and ms_meeting_room_id ='" & roomid & "'"
            End If

            If datefrom <> "" And dateto <> "" Then
                strSql &= " and convert(varchar(10),in_date,103) between '" & datefrom & "' and '" & dateto & "'"
            End If

            strSql &= " order by id_cardno,First_Name_TH,Last_Name_TH"

            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("id_cardno") = "1331000014254"
                dr("name") = "12/12/2014"
                dr("staff_name") = "nongnuch"
                dr("place") = "xx"
                dr("purpose") = "xx"
                dr("in_date") = "12/12/2014"
                dr("out_date") = "12/12/2014"
                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    <WebMethod()> _
    Public Function RenderVisitorDaily(buildingid As String, roomid As String, datefrom As String, dateto As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforVisitorDaily(buildingid, roomid, datefrom, dateto)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "id_cardno", _
                                            "name", _
                                            "staff_name", _
                                            "place", _
                                            "purpose", _
                                            "in_date", _
                                            "out_date"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1

                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim name As String = dt.Rows(i)("name").ToString
                    Dim staff_name As String = dt.Rows(i)("staff_name").ToString
                    Dim place As String = dt.Rows(i)("place").ToString
                    Dim purpose As String = dt.Rows(i)("purpose").ToString
                    Dim in_date As String = Convert.ToDateTime(dt.Rows(i)("in_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim out_date As String = Convert.ToDateTime(dt.Rows(i)("out_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & name & "</td>")
                    ret.Append("        <td align='left' >" & staff_name & "</td>")
                    ret.Append("        <td align='left' >" & place & "</td>")
                    ret.Append("        <td align='left' >" & purpose & "</td>")
                    ret.Append("        <td align='center' >" & in_date & "</td>")
                    ret.Append("        <td align='center' >" & out_date & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

    <WebMethod()> _
    Public Function GetdataforVisitorMonthly(buildingid As String, roomid As String, yearfrom As String, yearto As String, monthfrom As String, monthto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = "  select id_cardno,First_Name_EN + ' ' + Last_Name_EN as name,staff_name,"
            strSql &= " place,TSV.purpose,in_date,out_date from TS_VISITOR TSV "
            strSql &= " inner Join TS_PREBOOKING TSB on TSV.ts_prebooking_id =TSB.id"
            strSql &= " inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= " inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= " where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and  MSR.ms_building_id ='" & buildingid & "'"
            End If

            If roomid <> "" Then
                strSql &= " and ms_meeting_room_id ='" & roomid & "'"
            End If

            If yearfrom <> "" And yearto <> "" And monthfrom <> "" And monthto <> "" Then
                monthfrom = monthfrom.PadLeft(2, "0")
                monthto = monthto.PadLeft(2, "0")
                strSql &= " and convert(varchar(6),in_date,112) between '" & yearfrom & monthfrom & "' and '" & yearto & monthto & "'"
            End If

            strSql &= " order by id_cardno,First_Name_TH,Last_Name_TH"

            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("id_cardno") = "1331000014254"
                dr("name") = "12/12/2014"
                dr("staff_name") = "nongnuch"
                dr("place") = "xx"
                dr("purpose") = "xx"
                dr("in_date") = "12/12/2014"
                dr("out_date") = "12/12/2014"
                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try

    End Function

    <WebMethod()> _
    Public Function RenderVisitorMonthly(buildingid As String, roomid As String, yearfrom As String, yearto As String, monthfrom As String, monthto As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforVisitorMonthly(buildingid, roomid, yearfrom, yearto, monthfrom, monthto)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "id_cardno", _
                                            "name", _
                                            "staff_name", _
                                            "place", _
                                            "purpose", _
                                            "in_date", _
                                            "out_date"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1

                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim name As String = dt.Rows(i)("name").ToString
                    Dim staff_name As String = dt.Rows(i)("staff_name").ToString
                    Dim place As String = dt.Rows(i)("place").ToString
                    Dim purpose As String = dt.Rows(i)("purpose").ToString
                    Dim in_date As String = Convert.ToDateTime(dt.Rows(i)("in_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))
                    Dim out_date As String = Convert.ToDateTime(dt.Rows(i)("out_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & name & "</td>")
                    ret.Append("        <td align='left' >" & staff_name & "</td>")
                    ret.Append("        <td align='left' >" & place & "</td>")
                    ret.Append("        <td align='left' >" & purpose & "</td>")
                    ret.Append("        <td align='center' >" & in_date & "</td>")
                    ret.Append("        <td align='center' >" & out_date & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

    <WebMethod()> _
    Public Function GetdataforBlacklistDialy(name As String, reason As String, datefrom As String, dateto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = "  select blacklist_date,blacklist_reason,id_cardno,First_Name_EN + ' ' + Last_Name_EN as name,address from TS_BLACKLIST TSB"
            strSql &= " inner join TS_VISITOR TSV on TSB.tb_visitor_id = TSV.id where 1 = 1 "

            If name <> "" Then
                strSql &= " and (First_Name_EN Like'%" & name & "%' or Last_Name_EN Like'%" & name & "%' or First_Name_TH Like'%" & name & "%' or Last_Name_TH Like'%" & name & "%') "
            End If

            If reason <> "" Then
                strSql &= " and blacklist_reason Like '%" & reason & "%'"
            End If

            If datefrom <> "" And dateto <> "" Then
                strSql &= " and convert(varchar(10),blacklist_date,103) between '" & datefrom & "' and '" & dateto & "'"
            End If
            strSql &= " order by blacklist_date desc,id_cardno,First_Name_EN, Last_Name_EN"
            dt = SqlDB.ExecuteTable(strSql)
            If dt.Rows.Count = 0 Then
                Dim dr As DataRow
                dr = dt.NewRow
                dr("blacklist_date") = "12/12/2014"
                dr("blacklist_reason") = "xxxx"
                dr("id_cardno") = "1331000014254"
                dr("name") = "nongnuch"
                dr("address") = "xxxxx"

                dt.Rows.Add(dr)
            End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    <WebMethod()> _
    Public Function RenderBlacklistDialy(name As String, reason As String, datefrom As String, dateto As String) As String
        Try
            Dim dt As New DataTable
            dt = GetdataforBlacklistDialy(name, reason, datefrom, dateto)
            If dt.Rows.Count > 0 Then

                Dim ret As New StringBuilder
                ret.Append("<table width=""1000px"" border='1' cellpadding='0' cellspacing='0' class='mGrid' >")

                '### Header Colums Start ######
                Dim strHeader As String() = { _
                                            "blacklist_date", _
                                            "blacklist_reason", _
                                            "id_cardno", _
                                            "name", _
                                            "address"}
                ret.Append("    <tr style='background: yellowgreen repeat-x top;font-weight: bold;' >")
                For intHeader As Integer = 0 To strHeader.Count - 1
                    ret.Append("        <td  align='center' style='color: #ffffff;' >" & strHeader(intHeader) & "</td>")
                Next
                ret.Append("    </tr>")
                '### Header Colums End ######


                '### Detail Colums Start ######
                For i As Integer = 0 To dt.Rows.Count - 1

                    Dim id_cardno As String = dt.Rows(i)("id_cardno").ToString
                    Dim displayname As String = dt.Rows(i)("name").ToString
                    Dim blacklist_reason As String = dt.Rows(i)("blacklist_reason").ToString
                    Dim address As String = dt.Rows(i)("address").ToString
                    Dim blacklist_date As String = Convert.ToDateTime(dt.Rows(i)("blacklist_date")).ToString("dd/MM/yyyy", New CultureInfo("en-US"))

                    ret.Append("    <tr style='background: #E4E4E4;'>")
                    ret.Append("        <td align='left' >" & blacklist_date & "</td>")
                    ret.Append("        <td align='left' >" & blacklist_reason & "</td>")
                    ret.Append("        <td align='left' >" & id_cardno & "</td>")
                    ret.Append("        <td align='left' >" & displayname & "</td>")
                    ret.Append("        <td align='left' >" & address & "</td>")
                    ret.Append("    </tr>")
                Next
                '### Detail Colums End ######

                ret.Append("</table>")
                Return ret.ToString
            Else

                Return ""
            End If
        Catch ex As Exception
            Return ""
        End Try
    End Function

#End Region

#Region "Other"

    <WebMethod()> _
    Function GetMonthEng() As String

        Try
            Dim dt As New DataTable
            dt.Columns.Add("id")
            dt.Columns.Add("month")

            Dim dr As DataRow
            For i As Integer = 1 To 12
                dr = dt.NewRow
                dr("id") = i

                Dim month As String = ""
                Select Case i
                    Case 1
                        month = "January"
                    Case 2
                        month = "February"
                    Case 3
                        month = "March"
                    Case 4
                        month = "April"
                    Case 5
                        month = "May"
                    Case 6
                        month = "June"
                    Case 7
                        month = "July"
                    Case 8
                        month = "August"
                    Case 9
                        month = "September"
                    Case 10
                        month = "October"
                    Case 11
                        month = "November"
                    Case 12
                        month = "December"
                End Select

                dr("month") = month
                dt.Rows.Add(dr)
            Next

            If dt.Rows.Count > 0 Then
                Return clsdtHelper.ConvertDataTableToJson(dt)
            Else
                Return "[]"
            End If
        Catch ex As Exception
            Return "[]"
        End Try

    End Function

    <WebMethod()> _
    Function GetYear(numberofyear As Integer) As String
        Try
            Dim dt As New DataTable
            dt.Columns.Add("id")
            dt.Columns.Add("year")

            Dim dr As DataRow
            For i As Integer = 0 To numberofyear - 1
                dr = dt.NewRow
                dr("id") = Today.Year - i
                dr("year") = Today.Year - i
                dt.Rows.Add(dr)
            Next
            If dt.Rows.Count > 0 Then
                Return clsdtHelper.ConvertDataTableToJson(dt)
            Else
                Return "[]"
            End If
        Catch ex As Exception
            Return "[]"
        End Try

    End Function
#End Region


End Class