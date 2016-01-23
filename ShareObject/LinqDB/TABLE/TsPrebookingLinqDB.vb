Imports System
Imports System.Data 
Imports System.Data.SQLClient
Imports System.Data.Linq 
Imports System.Data.Linq.Mapping 
Imports System.Linq 
Imports System.Linq.Expressions 
Imports DB = LinqDB.ConnectDB.SQLDB
Imports LinqDB.ConnectDB

Namespace TABLE
    'Represents a transaction for TS_PREBOOKING table LinqDB.
    '[Create by  on January, 14 2015]
    Public Class TsPrebookingLinqDB
        Public sub TsPrebookingLinqDB()

        End Sub 
        ' TS_PREBOOKING
        Const _tableName As String = "TS_PREBOOKING"
        Dim _deletedRow As Int16 = 0

        'Set Common Property
        Dim _error As String = ""
        Dim _information As String = ""
        Dim _haveData As Boolean = False

        Public ReadOnly Property TableName As String
            Get
                Return _tableName
            End Get
        End Property
        Public ReadOnly Property ErrorMessage As String
            Get
                Return _error
            End Get
        End Property
        Public ReadOnly Property InfoMessage As String
            Get
                Return _information
            End Get
        End Property
        Public ReadOnly Property HaveData As Boolean
            Get
                Return _haveData
            End Get
        End Property


        'Generate Field List
        Dim _ID As Long = 0
        Dim _CREATED_BY As String = ""
        Dim _CREATED_DATE As DateTime = New DateTime(1,1,1)
        Dim _UPDATED_BY As  String  = ""
        Dim _UPDATED_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _RESERVE_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _USE_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _PURPOSE As String = ""
        Dim _MS_MEETING_ROOM_ID As Long = 0
        Dim _START_TIME As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _END_TIME As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _MS_USER_ID_BOOKING As Long = 0
        Dim _ATTENDEES As Long = 0
        Dim _IS_CONTRACT As  System.Nullable(Of Char)  = "N"
        Dim _START_CONTRACT_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _END_CONTRACT_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _START_CONTRACT_TIME As  String  = ""
        Dim _END_CONTRACT_TIME As  String  = ""
        Dim _ACTIVE_STATUS As Char = "Y"

        'Generate Field Property 
        <Column(Storage:="_ID", DbType:="BigInt NOT NULL ",CanBeNull:=false)>  _
        Public Property ID() As Long
            Get
                Return _ID
            End Get
            Set(ByVal value As Long)
               _ID = value
            End Set
        End Property 
        <Column(Storage:="_CREATED_BY", DbType:="VarChar(100) NOT NULL ",CanBeNull:=false)>  _
        Public Property CREATED_BY() As String
            Get
                Return _CREATED_BY
            End Get
            Set(ByVal value As String)
               _CREATED_BY = value
            End Set
        End Property 
        <Column(Storage:="_CREATED_DATE", DbType:="DateTime NOT NULL ",CanBeNull:=false)>  _
        Public Property CREATED_DATE() As DateTime
            Get
                Return _CREATED_DATE
            End Get
            Set(ByVal value As DateTime)
               _CREATED_DATE = value
            End Set
        End Property 
        <Column(Storage:="_UPDATED_BY", DbType:="VarChar(100)")>  _
        Public Property UPDATED_BY() As  String 
            Get
                Return _UPDATED_BY
            End Get
            Set(ByVal value As  String )
               _UPDATED_BY = value
            End Set
        End Property 
        <Column(Storage:="_UPDATED_DATE", DbType:="DateTime")>  _
        Public Property UPDATED_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _UPDATED_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _UPDATED_DATE = value
            End Set
        End Property 
        <Column(Storage:="_RESERVE_DATE", DbType:="DateTime")>  _
        Public Property RESERVE_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _RESERVE_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _RESERVE_DATE = value
            End Set
        End Property 
        <Column(Storage:="_USE_DATE", DbType:="DateTime")>  _
        Public Property USE_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _USE_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _USE_DATE = value
            End Set
        End Property 
        <Column(Storage:="_PURPOSE", DbType:="VarChar(255) NOT NULL ",CanBeNull:=false)>  _
        Public Property PURPOSE() As String
            Get
                Return _PURPOSE
            End Get
            Set(ByVal value As String)
               _PURPOSE = value
            End Set
        End Property 
        <Column(Storage:="_MS_MEETING_ROOM_ID", DbType:="BigInt NOT NULL ",CanBeNull:=false)>  _
        Public Property MS_MEETING_ROOM_ID() As Long
            Get
                Return _MS_MEETING_ROOM_ID
            End Get
            Set(ByVal value As Long)
               _MS_MEETING_ROOM_ID = value
            End Set
        End Property 
        <Column(Storage:="_START_TIME", DbType:="DateTime")>  _
        Public Property START_TIME() As  System.Nullable(Of DateTime) 
            Get
                Return _START_TIME
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _START_TIME = value
            End Set
        End Property 
        <Column(Storage:="_END_TIME", DbType:="DateTime")>  _
        Public Property END_TIME() As  System.Nullable(Of DateTime) 
            Get
                Return _END_TIME
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _END_TIME = value
            End Set
        End Property 
        <Column(Storage:="_MS_USER_ID_BOOKING", DbType:="BigInt NOT NULL ",CanBeNull:=false)>  _
        Public Property MS_USER_ID_BOOKING() As Long
            Get
                Return _MS_USER_ID_BOOKING
            End Get
            Set(ByVal value As Long)
               _MS_USER_ID_BOOKING = value
            End Set
        End Property 
        <Column(Storage:="_ATTENDEES", DbType:="Int NOT NULL ",CanBeNull:=false)>  _
        Public Property ATTENDEES() As Long
            Get
                Return _ATTENDEES
            End Get
            Set(ByVal value As Long)
               _ATTENDEES = value
            End Set
        End Property 
        <Column(Storage:="_IS_CONTRACT", DbType:="Char(1)")>  _
        Public Property IS_CONTRACT() As  System.Nullable(Of Char) 
            Get
                Return _IS_CONTRACT
            End Get
            Set(ByVal value As  System.Nullable(Of Char) )
               _IS_CONTRACT = value
            End Set
        End Property 
        <Column(Storage:="_START_CONTRACT_DATE", DbType:="DateTime")>  _
        Public Property START_CONTRACT_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _START_CONTRACT_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _START_CONTRACT_DATE = value
            End Set
        End Property 
        <Column(Storage:="_END_CONTRACT_DATE", DbType:="DateTime")>  _
        Public Property END_CONTRACT_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _END_CONTRACT_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _END_CONTRACT_DATE = value
            End Set
        End Property 
        <Column(Storage:="_START_CONTRACT_TIME", DbType:="VarChar(5)")>  _
        Public Property START_CONTRACT_TIME() As  String 
            Get
                Return _START_CONTRACT_TIME
            End Get
            Set(ByVal value As  String )
               _START_CONTRACT_TIME = value
            End Set
        End Property 
        <Column(Storage:="_END_CONTRACT_TIME", DbType:="VarChar(5)")>  _
        Public Property END_CONTRACT_TIME() As  String 
            Get
                Return _END_CONTRACT_TIME
            End Get
            Set(ByVal value As  String )
               _END_CONTRACT_TIME = value
            End Set
        End Property 
        <Column(Storage:="_ACTIVE_STATUS", DbType:="Char(1) NOT NULL ",CanBeNull:=false)>  _
        Public Property ACTIVE_STATUS() As Char
            Get
                Return _ACTIVE_STATUS
            End Get
            Set(ByVal value As Char)
               _ACTIVE_STATUS = value
            End Set
        End Property 


        'Clear All Data
        Private Sub ClearData()
            _ID = 0
            _CREATED_BY = ""
            _CREATED_DATE = New DateTime(1,1,1)
            _UPDATED_BY = ""
            _UPDATED_DATE = New DateTime(1,1,1)
            _RESERVE_DATE = New DateTime(1,1,1)
            _USE_DATE = New DateTime(1,1,1)
            _PURPOSE = ""
            _MS_MEETING_ROOM_ID = 0
            _START_TIME = New DateTime(1,1,1)
            _END_TIME = New DateTime(1,1,1)
            _MS_USER_ID_BOOKING = 0
            _ATTENDEES = 0
            _IS_CONTRACT = ""
            _START_CONTRACT_DATE = New DateTime(1,1,1)
            _END_CONTRACT_DATE = New DateTime(1,1,1)
            _START_CONTRACT_TIME = ""
            _END_CONTRACT_TIME = ""
            _ACTIVE_STATUS = ""
        End Sub

       'Define Public Method 
        'Execute the select statement with the specified condition and return a System.Data.DataTable.
        '/// <param name=whereClause>The condition for execute select statement.</param>
        '/// <param name=orderBy>The fields for sort data.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>The System.Data.DataTable object for specified condition.</returns>
        Public Function GetDataList(whClause As String, orderBy As String, trans As SQLTransaction) As DataTable
            Return DB.ExecuteTable(SqlSelect & IIf(whClause = "", "", " WHERE " & whClause) & IIF(orderBy = "", "", " ORDER BY  " & orderBy), trans)
        End Function


        'Execute the select statement with the specified condition and return a System.Data.DataTable.
        '/// <param name=whereClause>The condition for execute select statement.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>The System.Data.DataTable object for specified condition.</returns>
        Public Function GetListBySql(Sql As String, trans As SQLTransaction) As DataTable
            Return DB.ExecuteTable(Sql, trans)
        End Function


        '/// Returns an indication whether the current data is inserted into TS_PREBOOKING table successfully.
        '/// <param name=userID>The current user.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if insert data successfully; otherwise, false.</returns>
        Public Function InsertData(LoginName As String,trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                _Created_By = LoginName
                _Created_Date = DateTime.Now
                Return doInsert(trans)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is updated to TS_PREBOOKING table successfully.
        '/// <param name=userID>The current user.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if update data successfully; otherwise, false.</returns>
        Public Function UpdateByPK(LoginName As String,trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                _Updated_By = LoginName
                _Updated_Date = DateTime.Now
                Return doUpdate("ID = " & DB.SetDouble(_ID), trans)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is updated to TS_PREBOOKING table successfully.
        '/// <returns>true if update data successfully; otherwise, false.</returns>
        Public Function UpdateBySql(Sql As String, trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                Return (DB.ExecuteNonQuery(Sql, trans) > -1)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is deleted from TS_PREBOOKING table successfully.
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if delete data successfully; otherwise, false.</returns>
        Public Function DeleteByPK(cID As Long, trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                Return doDelete("ID = " & DB.SetDouble(cID), trans)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the record of TS_PREBOOKING by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByPK(cID As Long, trans As SQLTransaction) As Boolean
            Return doChkData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record and Mapping field to Data Class of TS_PREBOOKING by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function GetDataByPK(cID As Long, trans As SQLTransaction) As TsPrebookingLinqDB
            Return doGetData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record of TS_PREBOOKING by specified MS_MEETING_ROOM_ID key is retrieved successfully.
        '/// <param name=cMS_MEETING_ROOM_ID>The MS_MEETING_ROOM_ID key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByMS_MEETING_ROOM_ID(cMS_MEETING_ROOM_ID As Long, trans As SQLTransaction) As Boolean
            Return doChkData("MS_MEETING_ROOM_ID = " & DB.SetDouble(cMS_MEETING_ROOM_ID) & " ", trans)
        End Function

        '/// Returns an duplicate data record of TS_PREBOOKING by specified MS_MEETING_ROOM_ID key is retrieved successfully.
        '/// <param name=cMS_MEETING_ROOM_ID>The MS_MEETING_ROOM_ID key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByMS_MEETING_ROOM_ID(cMS_MEETING_ROOM_ID As Long, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("MS_MEETING_ROOM_ID = " & DB.SetDouble(cMS_MEETING_ROOM_ID) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of TS_PREBOOKING by specified MS_USER_ID_BOOKING key is retrieved successfully.
        '/// <param name=cMS_USER_ID_BOOKING>The MS_USER_ID_BOOKING key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByMS_USER_ID_BOOKING(cMS_USER_ID_BOOKING As Long, trans As SQLTransaction) As Boolean
            Return doChkData("MS_USER_ID_BOOKING = " & DB.SetDouble(cMS_USER_ID_BOOKING) & " ", trans)
        End Function

        '/// Returns an duplicate data record of TS_PREBOOKING by specified MS_USER_ID_BOOKING key is retrieved successfully.
        '/// <param name=cMS_USER_ID_BOOKING>The MS_USER_ID_BOOKING key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByMS_USER_ID_BOOKING(cMS_USER_ID_BOOKING As Long, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("MS_USER_ID_BOOKING = " & DB.SetDouble(cMS_USER_ID_BOOKING) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of TS_PREBOOKING by specified USE_DATE key is retrieved successfully.
        '/// <param name=cUSE_DATE>The USE_DATE key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByUSE_DATE(cUSE_DATE As DateTime, trans As SQLTransaction) As Boolean
            Return doChkData("USE_DATE = " & DB.SetDateTime(cUSE_DATE) & " ", trans)
        End Function

        '/// Returns an duplicate data record of TS_PREBOOKING by specified USE_DATE key is retrieved successfully.
        '/// <param name=cUSE_DATE>The USE_DATE key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByUSE_DATE(cUSE_DATE As DateTime, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("USE_DATE = " & DB.SetDateTime(cUSE_DATE) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of TS_PREBOOKING by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByWhere(whText As String, trans As SQLTransaction) As Boolean
            Return doChkData(whText, trans)
        End Function



        '/// Returns an indication whether the current data is inserted into TS_PREBOOKING table successfully.
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if insert data successfully; otherwise, false.</returns>
        Private Function doInsert(trans As SQLTransaction) As Boolean
            Dim ret As Boolean = True
            If _haveData = False Then
                Try
                    Dim dt as DataTable = DB.ExecuteTable(SqlInsert, trans, SetParameterData())
                    If dt.Rows.Count = 0 Then
                        _error = DB.ErrorMessage
                        ret = False
                    Else
                        _ID = dt.Rows(0)("ID")
                        _haveData = True
                        ret = True
                    End If
                    _information = MessageResources.MSGIN001
                Catch ex As ApplicationException
                    ret = false
                    _error = ex.Message & "ApplicationException :" & ex.ToString() & "### SQL:" & SqlInsert
                Catch ex As Exception
                    ret = False
                    _error = MessageResources.MSGEC101 & " Exception :" & ex.ToString() & "### SQL: " & SqlInsert
                End Try
            Else
                ret = False
                _error = MessageResources.MSGEN002 & "### SQL: " & SqlInsert
            End If

            Return ret
        End Function


        '/// Returns an indication whether the current data is updated to TS_PREBOOKING table successfully.
        '/// <param name=whText>The condition specify the updating record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if update data successfully; otherwise, false.</returns>
        Private Function doUpdate(whText As String, trans As SQLTransaction) As Boolean
            Dim ret As Boolean = True
            Dim tmpWhere As String = " Where " & whText
            If _haveData = True Then
                If whText.Trim() <> ""
                    Try
                        ret = DB.ExecuteNonQuery(SqlUpdate & tmpWhere, trans, SetParameterData())
                        If ret = False Then
                            _error = DB.ErrorMessage
                        End If
                        _information = MessageResources.MSGIU001
                    Catch ex As ApplicationException
                        ret = False
                        _error = ex.Message & "ApplicationException :" & ex.ToString() & "### SQL:" & SqlUpdate & tmpWhere
                    Catch ex As Exception
                        ret = False
                        _error = MessageResources.MSGEC102 & " Exception :" & ex.ToString() & "### SQL: " & SqlUpdate & tmpWhere
                    End Try
                Else
                    ret = False
                    _error = MessageResources.MSGEU003 & "### SQL: " & SqlUpdate & tmpWhere
                End If
            Else
                ret = True
            End If

            Return ret
        End Function


        '/// Returns an indication whether the current data is deleted from TS_PREBOOKING table successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if delete data successfully; otherwise, false.</returns>
        Private Function doDelete(whText As String, trans As SQLTransaction) As Boolean
            Dim ret As Boolean = True
            Dim tmpWhere As String = " Where " & whText
            If doChkData(whText, trans) = True Then
                If whText.Trim() <> ""
                    Try
                        ret = (DB.ExecuteNonQuery(SqlDelete & tmpWhere, trans) > -1)
                        If ret = False Then
                            _error = MessageResources.MSGED001
                        End If
                        _information = MessageResources.MSGID001
                    Catch ex As ApplicationException
                        ret = False
                        _error = ex.Message & "ApplicationException :" & ex.ToString() & "### SQL:" & SqlDelete & tmpWhere
                    Catch ex As Exception
                        ret = False
                        _error = MessageResources.MSGEC103 & " Exception :" & ex.ToString() & "### SQL: " & SqlDelete & tmpWhere
                    End Try
                Else
                    ret = False
                    _error = MessageResources.MSGED003 & "### SQL: " & SqlDelete & tmpWhere
                End If
            Else
                ret = True
            End If

            Return ret
        End Function

        Private Function SetParameterData() As SqlParameter()
            Dim cmbParam(18) As SqlParameter
            cmbParam(0) = New SqlParameter("@_ID", SqlDbType.BigInt)
            cmbParam(0).Value = _ID

            cmbParam(1) = New SqlParameter("@_CREATED_BY", SqlDbType.VarChar)
            cmbParam(1).Value = _CREATED_BY

            cmbParam(2) = New SqlParameter("@_CREATED_DATE", SqlDbType.DateTime)
            cmbParam(2).Value = _CREATED_DATE

            cmbParam(3) = New SqlParameter("@_UPDATED_BY", SqlDbType.VarChar)
            If _UPDATED_BY.Trim <> "" Then 
                cmbParam(3).Value = _UPDATED_BY
            Else
                cmbParam(3).Value = DBNull.value
            End If

            cmbParam(4) = New SqlParameter("@_UPDATED_DATE", SqlDbType.DateTime)
            If _UPDATED_DATE.Value.Year > 1 Then 
                cmbParam(4).Value = _UPDATED_DATE.Value
            Else
                cmbParam(4).Value = DBNull.value
            End If

            cmbParam(5) = New SqlParameter("@_RESERVE_DATE", SqlDbType.DateTime)
            If _RESERVE_DATE.Value.Year > 1 Then 
                cmbParam(5).Value = _RESERVE_DATE.Value
            Else
                cmbParam(5).Value = DBNull.value
            End If

            cmbParam(6) = New SqlParameter("@_USE_DATE", SqlDbType.DateTime)
            If _USE_DATE.Value.Year > 1 Then 
                cmbParam(6).Value = _USE_DATE.Value
            Else
                cmbParam(6).Value = DBNull.value
            End If

            cmbParam(7) = New SqlParameter("@_PURPOSE", SqlDbType.VarChar)
            cmbParam(7).Value = _PURPOSE

            cmbParam(8) = New SqlParameter("@_MS_MEETING_ROOM_ID", SqlDbType.BigInt)
            cmbParam(8).Value = _MS_MEETING_ROOM_ID

            cmbParam(9) = New SqlParameter("@_START_TIME", SqlDbType.DateTime)
            If _START_TIME.Value.Year > 1 Then 
                cmbParam(9).Value = _START_TIME.Value
            Else
                cmbParam(9).Value = DBNull.value
            End If

            cmbParam(10) = New SqlParameter("@_END_TIME", SqlDbType.DateTime)
            If _END_TIME.Value.Year > 1 Then 
                cmbParam(10).Value = _END_TIME.Value
            Else
                cmbParam(10).Value = DBNull.value
            End If

            cmbParam(11) = New SqlParameter("@_MS_USER_ID_BOOKING", SqlDbType.BigInt)
            cmbParam(11).Value = _MS_USER_ID_BOOKING

            cmbParam(12) = New SqlParameter("@_ATTENDEES", SqlDbType.Int)
            cmbParam(12).Value = _ATTENDEES

            cmbParam(13) = New SqlParameter("@_IS_CONTRACT", SqlDbType.Char)
            If _IS_CONTRACT.Value <> "" Then 
                cmbParam(13).Value = _IS_CONTRACT.Value
            Else
                cmbParam(13).Value = DBNull.value
            End IF

            cmbParam(14) = New SqlParameter("@_START_CONTRACT_DATE", SqlDbType.DateTime)
            If _START_CONTRACT_DATE.Value.Year > 1 Then 
                cmbParam(14).Value = _START_CONTRACT_DATE.Value
            Else
                cmbParam(14).Value = DBNull.value
            End If

            cmbParam(15) = New SqlParameter("@_END_CONTRACT_DATE", SqlDbType.DateTime)
            If _END_CONTRACT_DATE.Value.Year > 1 Then 
                cmbParam(15).Value = _END_CONTRACT_DATE.Value
            Else
                cmbParam(15).Value = DBNull.value
            End If

            cmbParam(16) = New SqlParameter("@_START_CONTRACT_TIME", SqlDbType.VarChar)
            If _START_CONTRACT_TIME.Trim <> "" Then 
                cmbParam(16).Value = _START_CONTRACT_TIME
            Else
                cmbParam(16).Value = DBNull.value
            End If

            cmbParam(17) = New SqlParameter("@_END_CONTRACT_TIME", SqlDbType.VarChar)
            If _END_CONTRACT_TIME.Trim <> "" Then 
                cmbParam(17).Value = _END_CONTRACT_TIME
            Else
                cmbParam(17).Value = DBNull.value
            End If

            cmbParam(18) = New SqlParameter("@_ACTIVE_STATUS", SqlDbType.Char)
            cmbParam(18).Value = _ACTIVE_STATUS

            Return cmbParam
        End Function


        '/// Returns an indication whether the record of TS_PREBOOKING by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Private Function doChkData(whText As String, trans As SQLTransaction) As Boolean
            Dim ret As Boolean = True
            Dim tmpWhere As String = " WHERE " & whText
            ClearData()
            _haveData  = False
            If whText.Trim() <> "" Then
                Dim Rdr As SQLDataReader
                Try
                    Rdr = DB.ExecuteReader(SqlSelect() & tmpWhere, trans)
                    If Rdr.Read() Then
                        _haveData = True
                        If Convert.IsDBNull(Rdr("id")) = False Then _id = Convert.ToInt64(Rdr("id"))
                        If Convert.IsDBNull(Rdr("created_by")) = False Then _created_by = Rdr("created_by").ToString()
                        If Convert.IsDBNull(Rdr("created_date")) = False Then _created_date = Convert.ToDateTime(Rdr("created_date"))
                        If Convert.IsDBNull(Rdr("updated_by")) = False Then _updated_by = Rdr("updated_by").ToString()
                        If Convert.IsDBNull(Rdr("updated_date")) = False Then _updated_date = Convert.ToDateTime(Rdr("updated_date"))
                        If Convert.IsDBNull(Rdr("reserve_date")) = False Then _reserve_date = Convert.ToDateTime(Rdr("reserve_date"))
                        If Convert.IsDBNull(Rdr("use_date")) = False Then _use_date = Convert.ToDateTime(Rdr("use_date"))
                        If Convert.IsDBNull(Rdr("purpose")) = False Then _purpose = Rdr("purpose").ToString()
                        If Convert.IsDBNull(Rdr("ms_meeting_room_id")) = False Then _ms_meeting_room_id = Convert.ToInt64(Rdr("ms_meeting_room_id"))
                        If Convert.IsDBNull(Rdr("start_time")) = False Then _start_time = Convert.ToDateTime(Rdr("start_time"))
                        If Convert.IsDBNull(Rdr("end_time")) = False Then _end_time = Convert.ToDateTime(Rdr("end_time"))
                        If Convert.IsDBNull(Rdr("ms_user_id_booking")) = False Then _ms_user_id_booking = Convert.ToInt64(Rdr("ms_user_id_booking"))
                        If Convert.IsDBNull(Rdr("attendees")) = False Then _attendees = Convert.ToInt32(Rdr("attendees"))
                        If Convert.IsDBNull(Rdr("is_contract")) = False Then _is_contract = Rdr("is_contract").ToString()
                        If Convert.IsDBNull(Rdr("start_contract_date")) = False Then _start_contract_date = Convert.ToDateTime(Rdr("start_contract_date"))
                        If Convert.IsDBNull(Rdr("end_contract_date")) = False Then _end_contract_date = Convert.ToDateTime(Rdr("end_contract_date"))
                        If Convert.IsDBNull(Rdr("start_contract_time")) = False Then _start_contract_time = Rdr("start_contract_time").ToString()
                        If Convert.IsDBNull(Rdr("end_contract_time")) = False Then _end_contract_time = Rdr("end_contract_time").ToString()
                        If Convert.IsDBNull(Rdr("active_status")) = False Then _active_status = Rdr("active_status").ToString()
                    Else
                        ret = False
                        _error = MessageResources.MSGEV002
                    End If

                    Rdr.Close()
                Catch ex As Exception
                    ex.ToString()
                    ret = False
                    _error = MessageResources.MSGEC104 & " #### " & ex.ToString()
                End Try
            Else
                ret = False
                _error = MessageResources.MSGEV001
            End If

            Return ret
        End Function


        '/// Returns an indication whether the record of TS_PREBOOKING by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Private Function doGetData(whText As String, trans As SQLTransaction) As TsPrebookingLinqDB
            ClearData()
            _haveData  = False
            If whText.Trim() <> "" Then
                Dim tmpWhere As String = " WHERE " & whText
                Dim Rdr As SQLDataReader
                Try
                    Rdr = DB.ExecuteReader(SqlSelect() & tmpWhere, trans)
                    If Rdr.Read() Then
                        _haveData = True
                        If Convert.IsDBNull(Rdr("id")) = False Then _id = Convert.ToInt64(Rdr("id"))
                        If Convert.IsDBNull(Rdr("created_by")) = False Then _created_by = Rdr("created_by").ToString()
                        If Convert.IsDBNull(Rdr("created_date")) = False Then _created_date = Convert.ToDateTime(Rdr("created_date"))
                        If Convert.IsDBNull(Rdr("updated_by")) = False Then _updated_by = Rdr("updated_by").ToString()
                        If Convert.IsDBNull(Rdr("updated_date")) = False Then _updated_date = Convert.ToDateTime(Rdr("updated_date"))
                        If Convert.IsDBNull(Rdr("reserve_date")) = False Then _reserve_date = Convert.ToDateTime(Rdr("reserve_date"))
                        If Convert.IsDBNull(Rdr("use_date")) = False Then _use_date = Convert.ToDateTime(Rdr("use_date"))
                        If Convert.IsDBNull(Rdr("purpose")) = False Then _purpose = Rdr("purpose").ToString()
                        If Convert.IsDBNull(Rdr("ms_meeting_room_id")) = False Then _ms_meeting_room_id = Convert.ToInt64(Rdr("ms_meeting_room_id"))
                        If Convert.IsDBNull(Rdr("start_time")) = False Then _start_time = Convert.ToDateTime(Rdr("start_time"))
                        If Convert.IsDBNull(Rdr("end_time")) = False Then _end_time = Convert.ToDateTime(Rdr("end_time"))
                        If Convert.IsDBNull(Rdr("ms_user_id_booking")) = False Then _ms_user_id_booking = Convert.ToInt64(Rdr("ms_user_id_booking"))
                        If Convert.IsDBNull(Rdr("attendees")) = False Then _attendees = Convert.ToInt32(Rdr("attendees"))
                        If Convert.IsDBNull(Rdr("is_contract")) = False Then _is_contract = Rdr("is_contract").ToString()
                        If Convert.IsDBNull(Rdr("start_contract_date")) = False Then _start_contract_date = Convert.ToDateTime(Rdr("start_contract_date"))
                        If Convert.IsDBNull(Rdr("end_contract_date")) = False Then _end_contract_date = Convert.ToDateTime(Rdr("end_contract_date"))
                        If Convert.IsDBNull(Rdr("start_contract_time")) = False Then _start_contract_time = Rdr("start_contract_time").ToString()
                        If Convert.IsDBNull(Rdr("end_contract_time")) = False Then _end_contract_time = Rdr("end_contract_time").ToString()
                        If Convert.IsDBNull(Rdr("active_status")) = False Then _active_status = Rdr("active_status").ToString()
                    Else
                        _error = MessageResources.MSGEV002
                    End If

                    Rdr.Close()
                Catch ex As Exception
                    ex.ToString()
                    _error = MessageResources.MSGEC104 & " #### " & ex.ToString()
                End Try
            Else
                _error = MessageResources.MSGEV001
            End If
            Return Me
        End Function



        ' SQL Statements


        'Get Insert Statement for table TS_PREBOOKING
        Private ReadOnly Property SqlInsert() As String 
            Get
                Dim Sql As String=""
                Sql += "INSERT INTO " & tableName  & " (CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE, RESERVE_DATE, USE_DATE, PURPOSE, MS_MEETING_ROOM_ID, START_TIME, END_TIME, MS_USER_ID_BOOKING, ATTENDEES, IS_CONTRACT, START_CONTRACT_DATE, END_CONTRACT_DATE, START_CONTRACT_TIME, END_CONTRACT_TIME, ACTIVE_STATUS)"
                Sql += " OUTPUT INSERTED.ID, INSERTED.CREATED_BY, INSERTED.CREATED_DATE, INSERTED.UPDATED_BY, INSERTED.UPDATED_DATE, INSERTED.RESERVE_DATE, INSERTED.USE_DATE, INSERTED.PURPOSE, INSERTED.MS_MEETING_ROOM_ID, INSERTED.START_TIME, INSERTED.END_TIME, INSERTED.MS_USER_ID_BOOKING, INSERTED.ATTENDEES, INSERTED.IS_CONTRACT, INSERTED.START_CONTRACT_DATE, INSERTED.END_CONTRACT_DATE, INSERTED.START_CONTRACT_TIME, INSERTED.END_CONTRACT_TIME, INSERTED.ACTIVE_STATUS
                Sql += " VALUES("
                sql += "@_CREATED_BY" & ", "
                sql += "@_CREATED_DATE" & ", "
                sql += "@_UPDATED_BY" & ", "
                sql += "@_UPDATED_DATE" & ", "
                sql += "@_RESERVE_DATE" & ", "
                sql += "@_USE_DATE" & ", "
                sql += "@_PURPOSE" & ", "
                sql += "@_MS_MEETING_ROOM_ID" & ", "
                sql += "@_START_TIME" & ", "
                sql += "@_END_TIME" & ", "
                sql += "@_MS_USER_ID_BOOKING" & ", "
                sql += "@_ATTENDEES" & ", "
                sql += "@_IS_CONTRACT" & ", "
                sql += "@_START_CONTRACT_DATE" & ", "
                sql += "@_END_CONTRACT_DATE" & ", "
                sql += "@_START_CONTRACT_TIME" & ", "
                sql += "@_END_CONTRACT_TIME" & ", "
                sql += "@_ACTIVE_STATUS"
                sql += ")"
                Return sql
            End Get
        End Property


        'Get update statement form table TS_PREBOOKING
        Private ReadOnly Property SqlUpdate() As String
            Get
                Dim Sql As String = ""
                Sql += "UPDATE " & tableName & " SET "
                Sql += "CREATED_BY = " & "@_CREATED_BY" & ", "
                Sql += "CREATED_DATE = " & "@_CREATED_DATE" & ", "
                Sql += "UPDATED_BY = " & "@_UPDATED_BY" & ", "
                Sql += "UPDATED_DATE = " & "@_UPDATED_DATE" & ", "
                Sql += "RESERVE_DATE = " & "@_RESERVE_DATE" & ", "
                Sql += "USE_DATE = " & "@_USE_DATE" & ", "
                Sql += "PURPOSE = " & "@_PURPOSE" & ", "
                Sql += "MS_MEETING_ROOM_ID = " & "@_MS_MEETING_ROOM_ID" & ", "
                Sql += "START_TIME = " & "@_START_TIME" & ", "
                Sql += "END_TIME = " & "@_END_TIME" & ", "
                Sql += "MS_USER_ID_BOOKING = " & "@_MS_USER_ID_BOOKING" & ", "
                Sql += "ATTENDEES = " & "@_ATTENDEES" & ", "
                Sql += "IS_CONTRACT = " & "@_IS_CONTRACT" & ", "
                Sql += "START_CONTRACT_DATE = " & "@_START_CONTRACT_DATE" & ", "
                Sql += "END_CONTRACT_DATE = " & "@_END_CONTRACT_DATE" & ", "
                Sql += "START_CONTRACT_TIME = " & "@_START_CONTRACT_TIME" & ", "
                Sql += "END_CONTRACT_TIME = " & "@_END_CONTRACT_TIME" & ", "
                Sql += "ACTIVE_STATUS = " & "@_ACTIVE_STATUS" + ""
                Return Sql
            End Get
        End Property


        'Get Delete Record in table TS_PREBOOKING
        Private ReadOnly Property SqlDelete() As String
            Get
                Dim Sql As String = "DELETE FROM " & tableName
                Return Sql
            End Get
        End Property


        'Get Select Statement for table TS_PREBOOKING
        Private ReadOnly Property SqlSelect() As String
            Get
                Dim Sql As String = "SELECT ID, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE, RESERVE_DATE, USE_DATE, PURPOSE, MS_MEETING_ROOM_ID, START_TIME, END_TIME, MS_USER_ID_BOOKING, ATTENDEES, IS_CONTRACT, START_CONTRACT_DATE, END_CONTRACT_DATE, START_CONTRACT_TIME, END_CONTRACT_TIME, ACTIVE_STATUS FROM " & tableName
                Return Sql
            End Get
        End Property

    End Class
End Namespace
