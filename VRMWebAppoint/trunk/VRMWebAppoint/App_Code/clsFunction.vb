Imports LinqDB.ConnectDB
Imports LinqDB.TABLE
Imports System.Data
Imports System.IO
Imports Microsoft.VisualBasic

Public Class clsFunction
#Region "Master"
#Region "Building"
    Public Function LoadActiveBuliding() As DataTable
        Try
            Dim dt As DataTable
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
            'If dt.Rows.Count > 0 Then
            '    strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'Else
            '    strdata = "[]"
            'End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try

    End Function


#End Region

#Region "Room"
    Public Function LoadActiveRoom(filter As String) As DataTable
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
            strSql.Append(" where r.active_status ='Y' ")
            If filter <> "" Then
                strSql.Append(filter)
            End If

            strSql.Append(" order by r.room_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)
            'If dt.Rows.Count > 0 Then
            '    strdata = clsdtHelper.ConvertDataTableToJson(dt)
            'Else
            '    strdata = "[]"
            'End If
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try

    End Function

    Public Function LoadRoomByBuilding(buildingid As String) As DataTable
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
            strSql.Append(" where r.active_status ='Y' ")
            strSql.Append(" and ms_building_id ='" & buildingid & "'")
            strSql.Append(" order by r.room_name")
            dt = SqlDB.ExecuteTable(strSql.ToString)

            Return dt
        Catch ex As Exception
            Return Nothing
        End Try

    End Function
#End Region

#Region "RommType"
    Public Function LoadActiveRoomType(filter As String) As DataTable
        Try
            Dim dt As DataTable
            'Dim strSql As New StringBuilder
            'strSql.Append(" select ")
            'strSql.Append(" ROW_NUMBER() OVER(ORDER BY r.id asc) AS no")
            'strSql.Append(" ,r.id")
            'strSql.Append(" ,(case when isnull(r.active_status ,'N') = 'N' then 'No Active' else 'Active' end )  active_status_desc")
            'strSql.Append(" ,r.room_name")
            'strSql.Append(" ,'' as room_desc")
            'strSql.Append(" ,r.floor")
            'strSql.Append(" ,b.building_name")
            'strSql.Append(" , '' option_name")
            'strSql.Append(" ,seat_qty")
            'strSql.Append(" ,rt.room_type_name")
            'strSql.Append(" from ms_meeting_room r")
            'strSql.Append(" inner join ms_building b")
            'strSql.Append(" on r.ms_building_id = b.id")
            'strSql.Append(" inner join ms_room_type rt")
            'strSql.Append(" on r.ms_room_type_id = rt.id")
            'strSql.Append(" where r.active_status ='Y' ")
            'If filter <> "" Then
            '    strSql.Append(filter)
            'End If


            'strSql.Append(" order by r.room_name")
            'dt = SqlDB.ExecuteTable(strSql.ToString)

            Return dt
        Catch ex As Exception
            Return Nothing
        End Try

    End Function


#End Region

#End Region

#Region "Report"

    Function getdataforbookingdialy(buildingid As String, roomid As String, datefrom As String, dateto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = " select reserve_date,use_date,TSB.purpose,ms_meeting_room_id,ms_user_id_booking "
            strSql &= ",TSBV.id_cardno,visitor_name,visitor_company_name"
            strSql &= ",MSP.prefix_eng +' ' + name_eng +' ' + surname_eng as userbooking"
            strSql &= ",MSR.room_name,MSB.building_name,ms_building_id"
            strSql &= "from TS_PREBOOKING TSB "
            strSql &= "inner join TS_PREBOOKING_VISITOR TSBV on TSB.id = TSBV.ts_prebooking_id"
            strSql &= "inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= "inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= "inner join MS_ROOM_TYPE MSRT on MSR.ms_room_type_id=MSRT.id"
            strSql &= "inner join MS_USER MSU on TSB.ms_user_id_booking = MSU.id"
            strSql &= "inner join MS_PREFIX MSP ON MSU.ms_prefix_id = MSP.id where 1 = 1 "

            If buildingid <> "" Then
                strSql &= " and ms_building_id ='" & buildingid & "'"
            End If

            If roomid <> "" Then
                strSql &= " and ms_meeting_room_id ='" & roomid & "'"
            End If

            If datefrom <> "" And dateto <> "" Then
                strSql &= " and convert(varchar(10),use_date,103) between '' and ''"
            End If

            dt = SqlDB.ExecuteTable(strSql)
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

    Function getdataforbookingmonthly(buildingid As String, roomid As String, yearfrom As String, yearto As String, monthfrom As String, monthto As String) As DataTable
        Try
            Dim dt As DataTable
            Dim strSql As String
            strSql = " select reserve_date,use_date,TSB.purpose,ms_meeting_room_id,ms_user_id_booking "
            strSql &= ",TSBV.id_cardno,visitor_name,visitor_company_name"
            strSql &= ",MSP.prefix_eng +' ' + name_eng +' ' + surname_eng as userbooking"
            strSql &= ",MSR.room_name,MSB.building_name,ms_building_id"
            strSql &= "from TS_PREBOOKING TSB "
            strSql &= "inner join TS_PREBOOKING_VISITOR TSBV on TSB.id = TSBV.ts_prebooking_id"
            strSql &= "inner join MS_MEETING_ROOM MSR on TSB.ms_meeting_room_id = MSR.id"
            strSql &= "inner join MS_BUILDING MSB on MSR.ms_building_id = MSB.id"
            strSql &= "inner join MS_ROOM_TYPE MSRT on MSR.ms_room_type_id=MSRT.id"
            strSql &= "inner join MS_USER MSU on TSB.ms_user_id_booking = MSU.id"
            strSql &= "inner join MS_PREFIX MSP ON MSU.ms_prefix_id = MSP.id where 1 = 1 "

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

            dt = SqlDB.ExecuteTable(strSql)
            Return dt
        Catch ex As Exception
            Return Nothing
        End Try
    End Function

#End Region

#Region "Date&Time"
    Function GetMonthEng() As DataTable
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
        Return dt
    End Function

    Function GetYear(numberofyear As Integer) As DataTable
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
        Return dt
    End Function
#End Region



End Class
