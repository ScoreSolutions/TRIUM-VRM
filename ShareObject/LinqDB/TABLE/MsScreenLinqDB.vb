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
    'Represents a transaction for MS_SCREEN table LinqDB.
    '[Create by  on December, 9 2014]
    Public Class MsScreenLinqDB
        Public sub MsScreenLinqDB()

        End Sub 
        ' MS_SCREEN
        Const _tableName As String = "MS_SCREEN"
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
        Dim _MS_MODULE_ID As  System.Nullable(Of Long)  = 0
        Dim _MS_SUBMODULE_ID As  System.Nullable(Of Long)  = 0
        Dim _ROWID_ROOTMENU As  System.Nullable(Of Long)  = 0
        Dim _ROWID_PARENTMENU As  System.Nullable(Of Long)  = 0
        Dim _ROWID_SUBPARENTMENU As  System.Nullable(Of Long)  = 0
        Dim _SCREENID As  String  = ""
        Dim _SEQUENCE As  String  = ""
        Dim _SCREENNAME As  String  = ""
        Dim _NAVIGATEURL As  String  = ""
        Dim _REMARK As  String  = ""
        Dim _ISMENU As  System.Nullable(Of Char)  = ""
        Dim _ISNOTUSE As  System.Nullable(Of Char)  = ""
        Dim _NOTUSEDATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _IMAGEURL As  String  = ""
        Dim _CREATED_BY As  String  = ""
        Dim _CREATED_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _UPDATED_BY As  String  = ""
        Dim _UPDATED_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)

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
        <Column(Storage:="_MS_MODULE_ID", DbType:="BigInt")>  _
        Public Property MS_MODULE_ID() As  System.Nullable(Of Long) 
            Get
                Return _MS_MODULE_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _MS_MODULE_ID = value
            End Set
        End Property 
        <Column(Storage:="_MS_SUBMODULE_ID", DbType:="BigInt")>  _
        Public Property MS_SUBMODULE_ID() As  System.Nullable(Of Long) 
            Get
                Return _MS_SUBMODULE_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _MS_SUBMODULE_ID = value
            End Set
        End Property 
        <Column(Storage:="_ROWID_ROOTMENU", DbType:="BigInt")>  _
        Public Property ROWID_ROOTMENU() As  System.Nullable(Of Long) 
            Get
                Return _ROWID_ROOTMENU
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _ROWID_ROOTMENU = value
            End Set
        End Property 
        <Column(Storage:="_ROWID_PARENTMENU", DbType:="BigInt")>  _
        Public Property ROWID_PARENTMENU() As  System.Nullable(Of Long) 
            Get
                Return _ROWID_PARENTMENU
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _ROWID_PARENTMENU = value
            End Set
        End Property 
        <Column(Storage:="_ROWID_SUBPARENTMENU", DbType:="BigInt")>  _
        Public Property ROWID_SUBPARENTMENU() As  System.Nullable(Of Long) 
            Get
                Return _ROWID_SUBPARENTMENU
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _ROWID_SUBPARENTMENU = value
            End Set
        End Property 
        <Column(Storage:="_SCREENID", DbType:="VarChar(255)")>  _
        Public Property SCREENID() As  String 
            Get
                Return _SCREENID
            End Get
            Set(ByVal value As  String )
               _SCREENID = value
            End Set
        End Property 
        <Column(Storage:="_SEQUENCE", DbType:="VarChar(50)")>  _
        Public Property SEQUENCE() As  String 
            Get
                Return _SEQUENCE
            End Get
            Set(ByVal value As  String )
               _SEQUENCE = value
            End Set
        End Property 
        <Column(Storage:="_SCREENNAME", DbType:="VarChar(255)")>  _
        Public Property SCREENNAME() As  String 
            Get
                Return _SCREENNAME
            End Get
            Set(ByVal value As  String )
               _SCREENNAME = value
            End Set
        End Property 
        <Column(Storage:="_NAVIGATEURL", DbType:="VarChar(255)")>  _
        Public Property NAVIGATEURL() As  String 
            Get
                Return _NAVIGATEURL
            End Get
            Set(ByVal value As  String )
               _NAVIGATEURL = value
            End Set
        End Property 
        <Column(Storage:="_REMARK", DbType:="VarChar(255)")>  _
        Public Property REMARK() As  String 
            Get
                Return _REMARK
            End Get
            Set(ByVal value As  String )
               _REMARK = value
            End Set
        End Property 
        <Column(Storage:="_ISMENU", DbType:="Char(1)")>  _
        Public Property ISMENU() As  System.Nullable(Of Char) 
            Get
                Return _ISMENU
            End Get
            Set(ByVal value As  System.Nullable(Of Char) )
               _ISMENU = value
            End Set
        End Property 
        <Column(Storage:="_ISNOTUSE", DbType:="Char(1)")>  _
        Public Property ISNOTUSE() As  System.Nullable(Of Char) 
            Get
                Return _ISNOTUSE
            End Get
            Set(ByVal value As  System.Nullable(Of Char) )
               _ISNOTUSE = value
            End Set
        End Property 
        <Column(Storage:="_NOTUSEDATE", DbType:="DateTime")>  _
        Public Property NOTUSEDATE() As  System.Nullable(Of DateTime) 
            Get
                Return _NOTUSEDATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _NOTUSEDATE = value
            End Set
        End Property 
        <Column(Storage:="_IMAGEURL", DbType:="VarChar(255)")>  _
        Public Property IMAGEURL() As  String 
            Get
                Return _IMAGEURL
            End Get
            Set(ByVal value As  String )
               _IMAGEURL = value
            End Set
        End Property 
        <Column(Storage:="_CREATED_BY", DbType:="VarChar(100)")>  _
        Public Property CREATED_BY() As  String 
            Get
                Return _CREATED_BY
            End Get
            Set(ByVal value As  String )
               _CREATED_BY = value
            End Set
        End Property 
        <Column(Storage:="_CREATED_DATE", DbType:="DateTime")>  _
        Public Property CREATED_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _CREATED_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
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


        'Clear All Data
        Private Sub ClearData()
            _ID = 0
            _MS_MODULE_ID = 0
            _MS_SUBMODULE_ID = 0
            _ROWID_ROOTMENU = 0
            _ROWID_PARENTMENU = 0
            _ROWID_SUBPARENTMENU = 0
            _SCREENID = ""
            _SEQUENCE = ""
            _SCREENNAME = ""
            _NAVIGATEURL = ""
            _REMARK = ""
            _ISMENU = ""
            _ISNOTUSE = ""
            _NOTUSEDATE = New DateTime(1,1,1)
            _IMAGEURL = ""
            _CREATED_BY = ""
            _CREATED_DATE = New DateTime(1,1,1)
            _UPDATED_BY = ""
            _UPDATED_DATE = New DateTime(1,1,1)
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


        '/// Returns an indication whether the current data is inserted into MS_SCREEN table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_SCREEN table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_SCREEN table successfully.
        '/// <returns>true if update data successfully; otherwise, false.</returns>
        Public Function UpdateBySql(Sql As String, trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                Return (DB.ExecuteNonQuery(Sql, trans) > -1)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is deleted from MS_SCREEN table successfully.
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


        '/// Returns an indication whether the record of MS_SCREEN by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByPK(cID As Long, trans As SQLTransaction) As Boolean
            Return doChkData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record and Mapping field to Data Class of MS_SCREEN by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function GetDataByPK(cID As Long, trans As SQLTransaction) As MsScreenLinqDB
            Return doGetData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record of MS_SCREEN by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByWhere(whText As String, trans As SQLTransaction) As Boolean
            Return doChkData(whText, trans)
        End Function



        '/// Returns an indication whether the current data is inserted into MS_SCREEN table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_SCREEN table successfully.
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


        '/// Returns an indication whether the current data is deleted from MS_SCREEN table successfully.
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

            cmbParam(1) = New SqlParameter("@_MS_MODULE_ID", SqlDbType.BigInt)
            If _MS_MODULE_ID IsNot Nothing Then 
                cmbParam(1).Value = _MS_MODULE_ID.Value
            Else
                cmbParam(1).Value = DBNull.value
            End IF

            cmbParam(2) = New SqlParameter("@_MS_SUBMODULE_ID", SqlDbType.BigInt)
            If _MS_SUBMODULE_ID IsNot Nothing Then 
                cmbParam(2).Value = _MS_SUBMODULE_ID.Value
            Else
                cmbParam(2).Value = DBNull.value
            End IF

            cmbParam(3) = New SqlParameter("@_ROWID_ROOTMENU", SqlDbType.BigInt)
            If _ROWID_ROOTMENU IsNot Nothing Then 
                cmbParam(3).Value = _ROWID_ROOTMENU.Value
            Else
                cmbParam(3).Value = DBNull.value
            End IF

            cmbParam(4) = New SqlParameter("@_ROWID_PARENTMENU", SqlDbType.BigInt)
            If _ROWID_PARENTMENU IsNot Nothing Then 
                cmbParam(4).Value = _ROWID_PARENTMENU.Value
            Else
                cmbParam(4).Value = DBNull.value
            End IF

            cmbParam(5) = New SqlParameter("@_ROWID_SUBPARENTMENU", SqlDbType.BigInt)
            If _ROWID_SUBPARENTMENU IsNot Nothing Then 
                cmbParam(5).Value = _ROWID_SUBPARENTMENU.Value
            Else
                cmbParam(5).Value = DBNull.value
            End IF

            cmbParam(6) = New SqlParameter("@_SCREENID", SqlDbType.VarChar)
            If _SCREENID.Trim <> "" Then 
                cmbParam(6).Value = _SCREENID
            Else
                cmbParam(6).Value = DBNull.value
            End If

            cmbParam(7) = New SqlParameter("@_SEQUENCE", SqlDbType.VarChar)
            If _SEQUENCE.Trim <> "" Then 
                cmbParam(7).Value = _SEQUENCE
            Else
                cmbParam(7).Value = DBNull.value
            End If

            cmbParam(8) = New SqlParameter("@_SCREENNAME", SqlDbType.VarChar)
            If _SCREENNAME.Trim <> "" Then 
                cmbParam(8).Value = _SCREENNAME
            Else
                cmbParam(8).Value = DBNull.value
            End If

            cmbParam(9) = New SqlParameter("@_NAVIGATEURL", SqlDbType.VarChar)
            If _NAVIGATEURL.Trim <> "" Then 
                cmbParam(9).Value = _NAVIGATEURL
            Else
                cmbParam(9).Value = DBNull.value
            End If

            cmbParam(10) = New SqlParameter("@_REMARK", SqlDbType.VarChar)
            If _REMARK.Trim <> "" Then 
                cmbParam(10).Value = _REMARK
            Else
                cmbParam(10).Value = DBNull.value
            End If

            cmbParam(11) = New SqlParameter("@_ISMENU", SqlDbType.Char)
            If _ISMENU.Value <> "" Then 
                cmbParam(11).Value = _ISMENU.Value
            Else
                cmbParam(11).Value = DBNull.value
            End IF

            cmbParam(12) = New SqlParameter("@_ISNOTUSE", SqlDbType.Char)
            If _ISNOTUSE.Value <> "" Then 
                cmbParam(12).Value = _ISNOTUSE.Value
            Else
                cmbParam(12).Value = DBNull.value
            End IF

            cmbParam(13) = New SqlParameter("@_NOTUSEDATE", SqlDbType.DateTime)
            If _NOTUSEDATE.Value.Year > 1 Then 
                cmbParam(13).Value = _NOTUSEDATE.Value
            Else
                cmbParam(13).Value = DBNull.value
            End If

            cmbParam(14) = New SqlParameter("@_IMAGEURL", SqlDbType.VarChar)
            If _IMAGEURL.Trim <> "" Then 
                cmbParam(14).Value = _IMAGEURL
            Else
                cmbParam(14).Value = DBNull.value
            End If

            cmbParam(15) = New SqlParameter("@_CREATED_BY", SqlDbType.VarChar)
            If _CREATED_BY.Trim <> "" Then 
                cmbParam(15).Value = _CREATED_BY
            Else
                cmbParam(15).Value = DBNull.value
            End If

            cmbParam(16) = New SqlParameter("@_CREATED_DATE", SqlDbType.DateTime)
            If _CREATED_DATE.Value.Year > 1 Then 
                cmbParam(16).Value = _CREATED_DATE.Value
            Else
                cmbParam(16).Value = DBNull.value
            End If

            cmbParam(17) = New SqlParameter("@_UPDATED_BY", SqlDbType.VarChar)
            If _UPDATED_BY.Trim <> "" Then 
                cmbParam(17).Value = _UPDATED_BY
            Else
                cmbParam(17).Value = DBNull.value
            End If

            cmbParam(18) = New SqlParameter("@_UPDATED_DATE", SqlDbType.DateTime)
            If _UPDATED_DATE.Value.Year > 1 Then 
                cmbParam(18).Value = _UPDATED_DATE.Value
            Else
                cmbParam(18).Value = DBNull.value
            End If

            Return cmbParam
        End Function


        '/// Returns an indication whether the record of MS_SCREEN by specified condition is retrieved successfully.
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
                        If Convert.IsDBNull(Rdr("ms_module_id")) = False Then _ms_module_id = Convert.ToInt64(Rdr("ms_module_id"))
                        If Convert.IsDBNull(Rdr("ms_submodule_id")) = False Then _ms_submodule_id = Convert.ToInt64(Rdr("ms_submodule_id"))
                        If Convert.IsDBNull(Rdr("rowid_rootmenu")) = False Then _rowid_rootmenu = Convert.ToInt64(Rdr("rowid_rootmenu"))
                        If Convert.IsDBNull(Rdr("rowid_parentmenu")) = False Then _rowid_parentmenu = Convert.ToInt64(Rdr("rowid_parentmenu"))
                        If Convert.IsDBNull(Rdr("rowid_subparentmenu")) = False Then _rowid_subparentmenu = Convert.ToInt64(Rdr("rowid_subparentmenu"))
                        If Convert.IsDBNull(Rdr("screenid")) = False Then _screenid = Rdr("screenid").ToString()
                        If Convert.IsDBNull(Rdr("sequence")) = False Then _sequence = Rdr("sequence").ToString()
                        If Convert.IsDBNull(Rdr("screenname")) = False Then _screenname = Rdr("screenname").ToString()
                        If Convert.IsDBNull(Rdr("navigateurl")) = False Then _navigateurl = Rdr("navigateurl").ToString()
                        If Convert.IsDBNull(Rdr("remark")) = False Then _remark = Rdr("remark").ToString()
                        If Convert.IsDBNull(Rdr("ismenu")) = False Then _ismenu = Rdr("ismenu").ToString()
                        If Convert.IsDBNull(Rdr("isnotuse")) = False Then _isnotuse = Rdr("isnotuse").ToString()
                        If Convert.IsDBNull(Rdr("notusedate")) = False Then _notusedate = Convert.ToDateTime(Rdr("notusedate"))
                        If Convert.IsDBNull(Rdr("imageurl")) = False Then _imageurl = Rdr("imageurl").ToString()
                        If Convert.IsDBNull(Rdr("created_by")) = False Then _created_by = Rdr("created_by").ToString()
                        If Convert.IsDBNull(Rdr("created_date")) = False Then _created_date = Convert.ToDateTime(Rdr("created_date"))
                        If Convert.IsDBNull(Rdr("updated_by")) = False Then _updated_by = Rdr("updated_by").ToString()
                        If Convert.IsDBNull(Rdr("updated_date")) = False Then _updated_date = Convert.ToDateTime(Rdr("updated_date"))
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


        '/// Returns an indication whether the record of MS_SCREEN by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Private Function doGetData(whText As String, trans As SQLTransaction) As MsScreenLinqDB
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
                        If Convert.IsDBNull(Rdr("ms_module_id")) = False Then _ms_module_id = Convert.ToInt64(Rdr("ms_module_id"))
                        If Convert.IsDBNull(Rdr("ms_submodule_id")) = False Then _ms_submodule_id = Convert.ToInt64(Rdr("ms_submodule_id"))
                        If Convert.IsDBNull(Rdr("rowid_rootmenu")) = False Then _rowid_rootmenu = Convert.ToInt64(Rdr("rowid_rootmenu"))
                        If Convert.IsDBNull(Rdr("rowid_parentmenu")) = False Then _rowid_parentmenu = Convert.ToInt64(Rdr("rowid_parentmenu"))
                        If Convert.IsDBNull(Rdr("rowid_subparentmenu")) = False Then _rowid_subparentmenu = Convert.ToInt64(Rdr("rowid_subparentmenu"))
                        If Convert.IsDBNull(Rdr("screenid")) = False Then _screenid = Rdr("screenid").ToString()
                        If Convert.IsDBNull(Rdr("sequence")) = False Then _sequence = Rdr("sequence").ToString()
                        If Convert.IsDBNull(Rdr("screenname")) = False Then _screenname = Rdr("screenname").ToString()
                        If Convert.IsDBNull(Rdr("navigateurl")) = False Then _navigateurl = Rdr("navigateurl").ToString()
                        If Convert.IsDBNull(Rdr("remark")) = False Then _remark = Rdr("remark").ToString()
                        If Convert.IsDBNull(Rdr("ismenu")) = False Then _ismenu = Rdr("ismenu").ToString()
                        If Convert.IsDBNull(Rdr("isnotuse")) = False Then _isnotuse = Rdr("isnotuse").ToString()
                        If Convert.IsDBNull(Rdr("notusedate")) = False Then _notusedate = Convert.ToDateTime(Rdr("notusedate"))
                        If Convert.IsDBNull(Rdr("imageurl")) = False Then _imageurl = Rdr("imageurl").ToString()
                        If Convert.IsDBNull(Rdr("created_by")) = False Then _created_by = Rdr("created_by").ToString()
                        If Convert.IsDBNull(Rdr("created_date")) = False Then _created_date = Convert.ToDateTime(Rdr("created_date"))
                        If Convert.IsDBNull(Rdr("updated_by")) = False Then _updated_by = Rdr("updated_by").ToString()
                        If Convert.IsDBNull(Rdr("updated_date")) = False Then _updated_date = Convert.ToDateTime(Rdr("updated_date"))
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


        'Get Insert Statement for table MS_SCREEN
        Private ReadOnly Property SqlInsert() As String 
            Get
                Dim Sql As String=""
                Sql += "INSERT INTO " & tableName  & " (ID, MS_MODULE_ID, MS_SUBMODULE_ID, ROWID_ROOTMENU, ROWID_PARENTMENU, ROWID_SUBPARENTMENU, SCREENID, SEQUENCE, SCREENNAME, NAVIGATEURL, REMARK, ISMENU, ISNOTUSE, NOTUSEDATE, IMAGEURL, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE)"
                Sql += " OUTPUT INSERTED.ID, INSERTED.MS_MODULE_ID, INSERTED.MS_SUBMODULE_ID, INSERTED.ROWID_ROOTMENU, INSERTED.ROWID_PARENTMENU, INSERTED.ROWID_SUBPARENTMENU, INSERTED.SCREENID, INSERTED.SEQUENCE, INSERTED.SCREENNAME, INSERTED.NAVIGATEURL, INSERTED.REMARK, INSERTED.ISMENU, INSERTED.ISNOTUSE, INSERTED.NOTUSEDATE, INSERTED.IMAGEURL, INSERTED.CREATED_BY, INSERTED.CREATED_DATE, INSERTED.UPDATED_BY, INSERTED.UPDATED_DATE
                Sql += " VALUES("
                sql += "@_ID" & ", "
                sql += "@_MS_MODULE_ID" & ", "
                sql += "@_MS_SUBMODULE_ID" & ", "
                sql += "@_ROWID_ROOTMENU" & ", "
                sql += "@_ROWID_PARENTMENU" & ", "
                sql += "@_ROWID_SUBPARENTMENU" & ", "
                sql += "@_SCREENID" & ", "
                sql += "@_SEQUENCE" & ", "
                sql += "@_SCREENNAME" & ", "
                sql += "@_NAVIGATEURL" & ", "
                sql += "@_REMARK" & ", "
                sql += "@_ISMENU" & ", "
                sql += "@_ISNOTUSE" & ", "
                sql += "@_NOTUSEDATE" & ", "
                sql += "@_IMAGEURL" & ", "
                sql += "@_CREATED_BY" & ", "
                sql += "@_CREATED_DATE" & ", "
                sql += "@_UPDATED_BY" & ", "
                sql += "@_UPDATED_DATE"
                sql += ")"
                Return sql
            End Get
        End Property


        'Get update statement form table MS_SCREEN
        Private ReadOnly Property SqlUpdate() As String
            Get
                Dim Sql As String = ""
                Sql += "UPDATE " & tableName & " SET "
                Sql += "MS_MODULE_ID = " & "@_MS_MODULE_ID" & ", "
                Sql += "MS_SUBMODULE_ID = " & "@_MS_SUBMODULE_ID" & ", "
                Sql += "ROWID_ROOTMENU = " & "@_ROWID_ROOTMENU" & ", "
                Sql += "ROWID_PARENTMENU = " & "@_ROWID_PARENTMENU" & ", "
                Sql += "ROWID_SUBPARENTMENU = " & "@_ROWID_SUBPARENTMENU" & ", "
                Sql += "SCREENID = " & "@_SCREENID" & ", "
                Sql += "SEQUENCE = " & "@_SEQUENCE" & ", "
                Sql += "SCREENNAME = " & "@_SCREENNAME" & ", "
                Sql += "NAVIGATEURL = " & "@_NAVIGATEURL" & ", "
                Sql += "REMARK = " & "@_REMARK" & ", "
                Sql += "ISMENU = " & "@_ISMENU" & ", "
                Sql += "ISNOTUSE = " & "@_ISNOTUSE" & ", "
                Sql += "NOTUSEDATE = " & "@_NOTUSEDATE" & ", "
                Sql += "IMAGEURL = " & "@_IMAGEURL" & ", "
                Sql += "CREATED_BY = " & "@_CREATED_BY" & ", "
                Sql += "CREATED_DATE = " & "@_CREATED_DATE" & ", "
                Sql += "UPDATED_BY = " & "@_UPDATED_BY" & ", "
                Sql += "UPDATED_DATE = " & "@_UPDATED_DATE" + ""
                Return Sql
            End Get
        End Property


        'Get Delete Record in table MS_SCREEN
        Private ReadOnly Property SqlDelete() As String
            Get
                Dim Sql As String = "DELETE FROM " & tableName
                Return Sql
            End Get
        End Property


        'Get Select Statement for table MS_SCREEN
        Private ReadOnly Property SqlSelect() As String
            Get
                Dim Sql As String = "SELECT ID, MS_MODULE_ID, MS_SUBMODULE_ID, ROWID_ROOTMENU, ROWID_PARENTMENU, ROWID_SUBPARENTMENU, SCREENID, SEQUENCE, SCREENNAME, NAVIGATEURL, REMARK, ISMENU, ISNOTUSE, NOTUSEDATE, IMAGEURL, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE FROM " & tableName
                Return Sql
            End Get
        End Property

    End Class
End Namespace
