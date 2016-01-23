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
    'Represents a transaction for MS_MEETING_ROOM table LinqDB.
    '[Create by  on December, 18 2014]
    Public Class MsMeetingRoomLinqDB
        Public sub MsMeetingRoomLinqDB()

        End Sub 
        ' MS_MEETING_ROOM
        Const _tableName As String = "MS_MEETING_ROOM"
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
        Dim _MS_BUILDING_ID As  System.Nullable(Of Long)  = 0
        Dim _ROOM_IMAGE_TYPE As  String  = ""
        Dim _ROOM_IMAGE_NAME As  String  = ""
        Dim _ROOM_IMAGE() As Byte
        Dim _ROOM_NAME As  String  = ""
        Dim _FLOOR As  String  = ""
        Dim _MS_ROOM_TYPE_ID As  System.Nullable(Of Long)  = 0
        Dim _SEAT_QTY As  System.Nullable(Of Long)  = 0
        Dim _ACTIVE_STATUS As  System.Nullable(Of Char)  = "Y"

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
        <Column(Storage:="_MS_BUILDING_ID", DbType:="BigInt")>  _
        Public Property MS_BUILDING_ID() As  System.Nullable(Of Long) 
            Get
                Return _MS_BUILDING_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _MS_BUILDING_ID = value
            End Set
        End Property 
        <Column(Storage:="_ROOM_IMAGE_TYPE", DbType:="VarChar(10)")>  _
        Public Property ROOM_IMAGE_TYPE() As  String 
            Get
                Return _ROOM_IMAGE_TYPE
            End Get
            Set(ByVal value As  String )
               _ROOM_IMAGE_TYPE = value
            End Set
        End Property 
        <Column(Storage:="_ROOM_IMAGE_NAME", DbType:="VarChar(100)")>  _
        Public Property ROOM_IMAGE_NAME() As  String 
            Get
                Return _ROOM_IMAGE_NAME
            End Get
            Set(ByVal value As  String )
               _ROOM_IMAGE_NAME = value
            End Set
        End Property 
        <Column(Storage:="_ROOM_IMAGE", DbType:="IMAGE")>  _
        Public Property ROOM_IMAGE() As  Byte() 
            Get
                Return _ROOM_IMAGE
            End Get
            Set(ByVal value() As Byte)
               _ROOM_IMAGE = value
            End Set
        End Property 
        <Column(Storage:="_ROOM_NAME", DbType:="VarChar(255)")>  _
        Public Property ROOM_NAME() As  String 
            Get
                Return _ROOM_NAME
            End Get
            Set(ByVal value As  String )
               _ROOM_NAME = value
            End Set
        End Property 
        <Column(Storage:="_FLOOR", DbType:="VarChar(50)")>  _
        Public Property FLOOR() As  String 
            Get
                Return _FLOOR
            End Get
            Set(ByVal value As  String )
               _FLOOR = value
            End Set
        End Property 
        <Column(Storage:="_MS_ROOM_TYPE_ID", DbType:="BigInt")>  _
        Public Property MS_ROOM_TYPE_ID() As  System.Nullable(Of Long) 
            Get
                Return _MS_ROOM_TYPE_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _MS_ROOM_TYPE_ID = value
            End Set
        End Property 
        <Column(Storage:="_SEAT_QTY", DbType:="Int")>  _
        Public Property SEAT_QTY() As  System.Nullable(Of Long) 
            Get
                Return _SEAT_QTY
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _SEAT_QTY = value
            End Set
        End Property 
        <Column(Storage:="_ACTIVE_STATUS", DbType:="Char(1)")>  _
        Public Property ACTIVE_STATUS() As  System.Nullable(Of Char) 
            Get
                Return _ACTIVE_STATUS
            End Get
            Set(ByVal value As  System.Nullable(Of Char) )
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
            _MS_BUILDING_ID = 0
            _ROOM_IMAGE_TYPE = ""
            _ROOM_IMAGE_NAME = ""
             _ROOM_IMAGE = Nothing
            _ROOM_NAME = ""
            _FLOOR = ""
            _MS_ROOM_TYPE_ID = 0
            _SEAT_QTY = 0
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


        '/// Returns an indication whether the current data is inserted into MS_MEETING_ROOM table successfully.
        '/// <param name=userID>The current user.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if insert data successfully; otherwise, false.</returns>
        Public Function InsertData(LoginName As String,trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                _ID = DB.GetNextID("ID",tableName, trans)
                _Created_By = LoginName
                _Created_Date = DateTime.Now
                Return doInsert(trans)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is updated to MS_MEETING_ROOM table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_MEETING_ROOM table successfully.
        '/// <returns>true if update data successfully; otherwise, false.</returns>
        Public Function UpdateBySql(Sql As String, trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                Return (DB.ExecuteNonQuery(Sql, trans) > -1)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is deleted from MS_MEETING_ROOM table successfully.
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


        '/// Returns an indication whether the record of MS_MEETING_ROOM by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByPK(cID As Long, trans As SQLTransaction) As Boolean
            Return doChkData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record and Mapping field to Data Class of MS_MEETING_ROOM by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function GetDataByPK(cID As Long, trans As SQLTransaction) As MsMeetingRoomLinqDB
            Return doGetData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record of MS_MEETING_ROOM by specified FLOOR_MS_BUILDING_ID_ROOM_NAME key is retrieved successfully.
        '/// <param name=cFLOOR_MS_BUILDING_ID_ROOM_NAME>The FLOOR_MS_BUILDING_ID_ROOM_NAME key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByFLOOR_MS_BUILDING_ID_ROOM_NAME(cFLOOR As String, cMS_BUILDING_ID As Long, cROOM_NAME As String, trans As SQLTransaction) As Boolean
            Return doChkData("FLOOR = " & DB.SetString(cFLOOR) & " AND MS_BUILDING_ID = " & DB.SetDouble(cMS_BUILDING_ID) & " AND ROOM_NAME = " & DB.SetString(cROOM_NAME), trans)
        End Function

        '/// Returns an duplicate data record of MS_MEETING_ROOM by specified FLOOR_MS_BUILDING_ID_ROOM_NAME key is retrieved successfully.
        '/// <param name=cFLOOR_MS_BUILDING_ID_ROOM_NAME>The FLOOR_MS_BUILDING_ID_ROOM_NAME key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByFLOOR_MS_BUILDING_ID_ROOM_NAME(cFLOOR As String, cMS_BUILDING_ID As Long, cROOM_NAME As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("FLOOR = " & DB.SetString(cFLOOR) & " AND MS_BUILDING_ID = " & DB.SetDouble(cMS_BUILDING_ID) & " AND ROOM_NAME = " & DB.SetString(cROOM_NAME) & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of MS_MEETING_ROOM by specified ROOM_NAME key is retrieved successfully.
        '/// <param name=cROOM_NAME>The ROOM_NAME key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByROOM_NAME(cROOM_NAME As String, trans As SQLTransaction) As Boolean
            Return doChkData("ROOM_NAME = " & DB.SetString(cROOM_NAME) & " ", trans)
        End Function

        '/// Returns an duplicate data record of MS_MEETING_ROOM by specified ROOM_NAME key is retrieved successfully.
        '/// <param name=cROOM_NAME>The ROOM_NAME key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByROOM_NAME(cROOM_NAME As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("ROOM_NAME = " & DB.SetString(cROOM_NAME) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of MS_MEETING_ROOM by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByWhere(whText As String, trans As SQLTransaction) As Boolean
            Return doChkData(whText, trans)
        End Function



        '/// Returns an indication whether the current data is inserted into MS_MEETING_ROOM table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_MEETING_ROOM table successfully.
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


        '/// Returns an indication whether the current data is deleted from MS_MEETING_ROOM table successfully.
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
            Dim cmbParam(13) As SqlParameter
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

            cmbParam(5) = New SqlParameter("@_MS_BUILDING_ID", SqlDbType.BigInt)
            If _MS_BUILDING_ID IsNot Nothing Then 
                cmbParam(5).Value = _MS_BUILDING_ID.Value
            Else
                cmbParam(5).Value = DBNull.value
            End IF

            cmbParam(6) = New SqlParameter("@_ROOM_IMAGE_TYPE", SqlDbType.VarChar)
            If _ROOM_IMAGE_TYPE.Trim <> "" Then 
                cmbParam(6).Value = _ROOM_IMAGE_TYPE
            Else
                cmbParam(6).Value = DBNull.value
            End If

            cmbParam(7) = New SqlParameter("@_ROOM_IMAGE_NAME", SqlDbType.VarChar)
            If _ROOM_IMAGE_NAME.Trim <> "" Then 
                cmbParam(7).Value = _ROOM_IMAGE_NAME
            Else
                cmbParam(7).Value = DBNull.value
            End If

            If _ROOM_IMAGE IsNot Nothing Then 
                cmbParam(8) = New SqlParameter("@_ROOM_IMAGE",SqlDbType.Image, _ROOM_IMAGE.Length)
                cmbParam(8).Value = _ROOM_IMAGE
            Else
                cmbParam(8) = New SqlParameter("@_ROOM_IMAGE", SqlDbType.Image)
                cmbParam(8).Value = DBNull.value
            End If

            cmbParam(9) = New SqlParameter("@_ROOM_NAME", SqlDbType.VarChar)
            If _ROOM_NAME.Trim <> "" Then 
                cmbParam(9).Value = _ROOM_NAME
            Else
                cmbParam(9).Value = DBNull.value
            End If

            cmbParam(10) = New SqlParameter("@_FLOOR", SqlDbType.VarChar)
            If _FLOOR.Trim <> "" Then 
                cmbParam(10).Value = _FLOOR
            Else
                cmbParam(10).Value = DBNull.value
            End If

            cmbParam(11) = New SqlParameter("@_MS_ROOM_TYPE_ID", SqlDbType.BigInt)
            If _MS_ROOM_TYPE_ID IsNot Nothing Then 
                cmbParam(11).Value = _MS_ROOM_TYPE_ID.Value
            Else
                cmbParam(11).Value = DBNull.value
            End IF

            cmbParam(12) = New SqlParameter("@_SEAT_QTY", SqlDbType.Int)
            If _SEAT_QTY IsNot Nothing Then 
                cmbParam(12).Value = _SEAT_QTY.Value
            Else
                cmbParam(12).Value = DBNull.value
            End IF

            cmbParam(13) = New SqlParameter("@_ACTIVE_STATUS", SqlDbType.Char)
            If _ACTIVE_STATUS.Value <> "" Then 
                cmbParam(13).Value = _ACTIVE_STATUS.Value
            Else
                cmbParam(13).Value = DBNull.value
            End IF

            Return cmbParam
        End Function


        '/// Returns an indication whether the record of MS_MEETING_ROOM by specified condition is retrieved successfully.
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
                        If Convert.IsDBNull(Rdr("ms_building_id")) = False Then _ms_building_id = Convert.ToInt64(Rdr("ms_building_id"))
                        If Convert.IsDBNull(Rdr("room_image_type")) = False Then _room_image_type = Rdr("room_image_type").ToString()
                        If Convert.IsDBNull(Rdr("room_image_name")) = False Then _room_image_name = Rdr("room_image_name").ToString()
                        If Convert.IsDBNull(Rdr("room_image")) = False Then _room_image = CType(Rdr("room_image"), Byte())
                        If Convert.IsDBNull(Rdr("room_name")) = False Then _room_name = Rdr("room_name").ToString()
                        If Convert.IsDBNull(Rdr("floor")) = False Then _floor = Rdr("floor").ToString()
                        If Convert.IsDBNull(Rdr("ms_room_type_id")) = False Then _ms_room_type_id = Convert.ToInt64(Rdr("ms_room_type_id"))
                        If Convert.IsDBNull(Rdr("seat_qty")) = False Then _seat_qty = Convert.ToInt32(Rdr("seat_qty"))
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


        '/// Returns an indication whether the record of MS_MEETING_ROOM by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Private Function doGetData(whText As String, trans As SQLTransaction) As MsMeetingRoomLinqDB
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
                        If Convert.IsDBNull(Rdr("ms_building_id")) = False Then _ms_building_id = Convert.ToInt64(Rdr("ms_building_id"))
                        If Convert.IsDBNull(Rdr("room_image_type")) = False Then _room_image_type = Rdr("room_image_type").ToString()
                        If Convert.IsDBNull(Rdr("room_image_name")) = False Then _room_image_name = Rdr("room_image_name").ToString()
                        If Convert.IsDBNull(Rdr("room_image")) = False Then _room_image = CType(Rdr("room_image"), Byte())
                        If Convert.IsDBNull(Rdr("room_name")) = False Then _room_name = Rdr("room_name").ToString()
                        If Convert.IsDBNull(Rdr("floor")) = False Then _floor = Rdr("floor").ToString()
                        If Convert.IsDBNull(Rdr("ms_room_type_id")) = False Then _ms_room_type_id = Convert.ToInt64(Rdr("ms_room_type_id"))
                        If Convert.IsDBNull(Rdr("seat_qty")) = False Then _seat_qty = Convert.ToInt32(Rdr("seat_qty"))
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


        'Get Insert Statement for table MS_MEETING_ROOM
        Private ReadOnly Property SqlInsert() As String 
            Get
                Dim Sql As String=""
                Sql += "INSERT INTO " & tableName  & " (ID, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE, MS_BUILDING_ID, ROOM_IMAGE_TYPE, ROOM_IMAGE_NAME, ROOM_IMAGE, ROOM_NAME, FLOOR, MS_ROOM_TYPE_ID, SEAT_QTY, ACTIVE_STATUS)"
                Sql += " OUTPUT INSERTED.ID, INSERTED.CREATED_BY, INSERTED.CREATED_DATE, INSERTED.UPDATED_BY, INSERTED.UPDATED_DATE, INSERTED.MS_BUILDING_ID, INSERTED.ROOM_IMAGE_TYPE, INSERTED.ROOM_IMAGE_NAME, INSERTED.ROOM_IMAGE, INSERTED.ROOM_NAME, INSERTED.FLOOR, INSERTED.MS_ROOM_TYPE_ID, INSERTED.SEAT_QTY, INSERTED.ACTIVE_STATUS
                Sql += " VALUES("
                sql += "@_ID" & ", "
                sql += "@_CREATED_BY" & ", "
                sql += "@_CREATED_DATE" & ", "
                sql += "@_UPDATED_BY" & ", "
                sql += "@_UPDATED_DATE" & ", "
                sql += "@_MS_BUILDING_ID" & ", "
                sql += "@_ROOM_IMAGE_TYPE" & ", "
                sql += "@_ROOM_IMAGE_NAME" & ", "
                sql += "@_ROOM_IMAGE" & ", "
                sql += "@_ROOM_NAME" & ", "
                sql += "@_FLOOR" & ", "
                sql += "@_MS_ROOM_TYPE_ID" & ", "
                sql += "@_SEAT_QTY" & ", "
                sql += "@_ACTIVE_STATUS"
                sql += ")"
                Return sql
            End Get
        End Property


        'Get update statement form table MS_MEETING_ROOM
        Private ReadOnly Property SqlUpdate() As String
            Get
                Dim Sql As String = ""
                Sql += "UPDATE " & tableName & " SET "
                Sql += "CREATED_BY = " & "@_CREATED_BY" & ", "
                Sql += "CREATED_DATE = " & "@_CREATED_DATE" & ", "
                Sql += "UPDATED_BY = " & "@_UPDATED_BY" & ", "
                Sql += "UPDATED_DATE = " & "@_UPDATED_DATE" & ", "
                Sql += "MS_BUILDING_ID = " & "@_MS_BUILDING_ID" & ", "
                Sql += "ROOM_IMAGE_TYPE = " & "@_ROOM_IMAGE_TYPE" & ", "
                Sql += "ROOM_IMAGE_NAME = " & "@_ROOM_IMAGE_NAME" & ", "
                Sql += "ROOM_IMAGE = " & "@_ROOM_IMAGE" & ", "
                Sql += "ROOM_NAME = " & "@_ROOM_NAME" & ", "
                Sql += "FLOOR = " & "@_FLOOR" & ", "
                Sql += "MS_ROOM_TYPE_ID = " & "@_MS_ROOM_TYPE_ID" & ", "
                Sql += "SEAT_QTY = " & "@_SEAT_QTY" & ", "
                Sql += "ACTIVE_STATUS = " & "@_ACTIVE_STATUS" + ""
                Return Sql
            End Get
        End Property


        'Get Delete Record in table MS_MEETING_ROOM
        Private ReadOnly Property SqlDelete() As String
            Get
                Dim Sql As String = "DELETE FROM " & tableName
                Return Sql
            End Get
        End Property


        'Get Select Statement for table MS_MEETING_ROOM
        Private ReadOnly Property SqlSelect() As String
            Get
                Dim Sql As String = "SELECT ID, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE, MS_BUILDING_ID, ROOM_IMAGE_TYPE, ROOM_IMAGE_NAME, ROOM_IMAGE, ROOM_NAME, FLOOR, MS_ROOM_TYPE_ID, SEAT_QTY, ACTIVE_STATUS FROM " & tableName
                Return Sql
            End Get
        End Property

    End Class
End Namespace
