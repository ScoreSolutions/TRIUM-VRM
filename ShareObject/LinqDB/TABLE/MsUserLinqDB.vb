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
    'Represents a transaction for MS_USER table LinqDB.
    '[Create by  on December, 22 2014]
    Public Class MsUserLinqDB
        Public sub MsUserLinqDB()

        End Sub 
        ' MS_USER
        Const _tableName As String = "MS_USER"
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
        Dim _EMPLOYEE_CODE As String = ""
        Dim _MS_PREFIX_ID As  System.Nullable(Of Long)  = 0
        Dim _NAME_THAI As  String  = ""
        Dim _NAME_ENG As  String  = ""
        Dim _SURNAME_THAI As  String  = ""
        Dim _SURNAME_ENG As  String  = ""
        Dim _MS_DEPARTMENT_ID As Long = 0
        Dim _MS_POSITION_ID As Long = 0
        Dim _USERNAME As String = ""
        Dim _PASSWD As String = ""
        Dim _ENFORCE_PASSWORD_EXPIRATION As Char = "Y"
        Dim _PASSWORD_EXPIRY_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _FOURCE_CHANGE_PASSWORD As Char = "Y"
        Dim _ACTIVE_STATUS As Char = "Y"
        Dim _CREATED_BY As String = ""
        Dim _CREATED_DATE As DateTime = New DateTime(1,1,1)
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
        <Column(Storage:="_EMPLOYEE_CODE", DbType:="VarChar(50) NOT NULL ",CanBeNull:=false)>  _
        Public Property EMPLOYEE_CODE() As String
            Get
                Return _EMPLOYEE_CODE
            End Get
            Set(ByVal value As String)
               _EMPLOYEE_CODE = value
            End Set
        End Property 
        <Column(Storage:="_MS_PREFIX_ID", DbType:="Int")>  _
        Public Property MS_PREFIX_ID() As  System.Nullable(Of Long) 
            Get
                Return _MS_PREFIX_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _MS_PREFIX_ID = value
            End Set
        End Property 
        <Column(Storage:="_NAME_THAI", DbType:="VarChar(255)")>  _
        Public Property NAME_THAI() As  String 
            Get
                Return _NAME_THAI
            End Get
            Set(ByVal value As  String )
               _NAME_THAI = value
            End Set
        End Property 
        <Column(Storage:="_NAME_ENG", DbType:="VarChar(255)")>  _
        Public Property NAME_ENG() As  String 
            Get
                Return _NAME_ENG
            End Get
            Set(ByVal value As  String )
               _NAME_ENG = value
            End Set
        End Property 
        <Column(Storage:="_SURNAME_THAI", DbType:="VarChar(255)")>  _
        Public Property SURNAME_THAI() As  String 
            Get
                Return _SURNAME_THAI
            End Get
            Set(ByVal value As  String )
               _SURNAME_THAI = value
            End Set
        End Property 
        <Column(Storage:="_SURNAME_ENG", DbType:="VarChar(255)")>  _
        Public Property SURNAME_ENG() As  String 
            Get
                Return _SURNAME_ENG
            End Get
            Set(ByVal value As  String )
               _SURNAME_ENG = value
            End Set
        End Property 
        <Column(Storage:="_MS_DEPARTMENT_ID", DbType:="BigInt NOT NULL ",CanBeNull:=false)>  _
        Public Property MS_DEPARTMENT_ID() As Long
            Get
                Return _MS_DEPARTMENT_ID
            End Get
            Set(ByVal value As Long)
               _MS_DEPARTMENT_ID = value
            End Set
        End Property 
        <Column(Storage:="_MS_POSITION_ID", DbType:="BigInt NOT NULL ",CanBeNull:=false)>  _
        Public Property MS_POSITION_ID() As Long
            Get
                Return _MS_POSITION_ID
            End Get
            Set(ByVal value As Long)
               _MS_POSITION_ID = value
            End Set
        End Property 
        <Column(Storage:="_USERNAME", DbType:="VarChar(50) NOT NULL ",CanBeNull:=false)>  _
        Public Property USERNAME() As String
            Get
                Return _USERNAME
            End Get
            Set(ByVal value As String)
               _USERNAME = value
            End Set
        End Property 
        <Column(Storage:="_PASSWD", DbType:="VarChar(255) NOT NULL ",CanBeNull:=false)>  _
        Public Property PASSWD() As String
            Get
                Return _PASSWD
            End Get
            Set(ByVal value As String)
               _PASSWD = value
            End Set
        End Property 
        <Column(Storage:="_ENFORCE_PASSWORD_EXPIRATION", DbType:="Char(1) NOT NULL ",CanBeNull:=false)>  _
        Public Property ENFORCE_PASSWORD_EXPIRATION() As Char
            Get
                Return _ENFORCE_PASSWORD_EXPIRATION
            End Get
            Set(ByVal value As Char)
               _ENFORCE_PASSWORD_EXPIRATION = value
            End Set
        End Property 
        <Column(Storage:="_PASSWORD_EXPIRY_DATE", DbType:="DateTime")>  _
        Public Property PASSWORD_EXPIRY_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _PASSWORD_EXPIRY_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _PASSWORD_EXPIRY_DATE = value
            End Set
        End Property 
        <Column(Storage:="_FOURCE_CHANGE_PASSWORD", DbType:="Char(1) NOT NULL ",CanBeNull:=false)>  _
        Public Property FOURCE_CHANGE_PASSWORD() As Char
            Get
                Return _FOURCE_CHANGE_PASSWORD
            End Get
            Set(ByVal value As Char)
               _FOURCE_CHANGE_PASSWORD = value
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


        'Clear All Data
        Private Sub ClearData()
            _ID = 0
            _EMPLOYEE_CODE = ""
            _MS_PREFIX_ID = 0
            _NAME_THAI = ""
            _NAME_ENG = ""
            _SURNAME_THAI = ""
            _SURNAME_ENG = ""
            _MS_DEPARTMENT_ID = 0
            _MS_POSITION_ID = 0
            _USERNAME = ""
            _PASSWD = ""
            _ENFORCE_PASSWORD_EXPIRATION = ""
            _PASSWORD_EXPIRY_DATE = New DateTime(1,1,1)
            _FOURCE_CHANGE_PASSWORD = ""
            _ACTIVE_STATUS = ""
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


        '/// Returns an indication whether the current data is inserted into MS_USER table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_USER table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_USER table successfully.
        '/// <returns>true if update data successfully; otherwise, false.</returns>
        Public Function UpdateBySql(Sql As String, trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                Return (DB.ExecuteNonQuery(Sql, trans) > -1)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is deleted from MS_USER table successfully.
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


        '/// Returns an indication whether the record of MS_USER by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByPK(cID As Long, trans As SQLTransaction) As Boolean
            Return doChkData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record and Mapping field to Data Class of MS_USER by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function GetDataByPK(cID As Long, trans As SQLTransaction) As MsUserLinqDB
            Return doGetData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record of MS_USER by specified USERNAME key is retrieved successfully.
        '/// <param name=cUSERNAME>The USERNAME key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByUSERNAME(cUSERNAME As String, trans As SQLTransaction) As Boolean
            Return doChkData("USERNAME = " & DB.SetString(cUSERNAME) & " ", trans)
        End Function

        '/// Returns an duplicate data record of MS_USER by specified USERNAME key is retrieved successfully.
        '/// <param name=cUSERNAME>The USERNAME key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByUSERNAME(cUSERNAME As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("USERNAME = " & DB.SetString(cUSERNAME) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of MS_USER by specified EMPLOYEE_CODE key is retrieved successfully.
        '/// <param name=cEMPLOYEE_CODE>The EMPLOYEE_CODE key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByEMPLOYEE_CODE(cEMPLOYEE_CODE As String, trans As SQLTransaction) As Boolean
            Return doChkData("EMPLOYEE_CODE = " & DB.SetString(cEMPLOYEE_CODE) & " ", trans)
        End Function

        '/// Returns an duplicate data record of MS_USER by specified EMPLOYEE_CODE key is retrieved successfully.
        '/// <param name=cEMPLOYEE_CODE>The EMPLOYEE_CODE key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByEMPLOYEE_CODE(cEMPLOYEE_CODE As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("EMPLOYEE_CODE = " & DB.SetString(cEMPLOYEE_CODE) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of MS_USER by specified NAME_THAI key is retrieved successfully.
        '/// <param name=cNAME_THAI>The NAME_THAI key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByNAME_THAI(cNAME_THAI As String, trans As SQLTransaction) As Boolean
            Return doChkData("NAME_THAI = " & DB.SetString(cNAME_THAI) & " ", trans)
        End Function

        '/// Returns an duplicate data record of MS_USER by specified NAME_THAI key is retrieved successfully.
        '/// <param name=cNAME_THAI>The NAME_THAI key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByNAME_THAI(cNAME_THAI As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("NAME_THAI = " & DB.SetString(cNAME_THAI) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of MS_USER by specified NAME_ENG key is retrieved successfully.
        '/// <param name=cNAME_ENG>The NAME_ENG key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByNAME_ENG(cNAME_ENG As String, trans As SQLTransaction) As Boolean
            Return doChkData("NAME_ENG = " & DB.SetString(cNAME_ENG) & " ", trans)
        End Function

        '/// Returns an duplicate data record of MS_USER by specified NAME_ENG key is retrieved successfully.
        '/// <param name=cNAME_ENG>The NAME_ENG key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByNAME_ENG(cNAME_ENG As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("NAME_ENG = " & DB.SetString(cNAME_ENG) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of MS_USER by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByWhere(whText As String, trans As SQLTransaction) As Boolean
            Return doChkData(whText, trans)
        End Function



        '/// Returns an indication whether the current data is inserted into MS_USER table successfully.
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


        '/// Returns an indication whether the current data is updated to MS_USER table successfully.
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


        '/// Returns an indication whether the current data is deleted from MS_USER table successfully.
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

            cmbParam(1) = New SqlParameter("@_EMPLOYEE_CODE", SqlDbType.VarChar)
            cmbParam(1).Value = _EMPLOYEE_CODE

            cmbParam(2) = New SqlParameter("@_MS_PREFIX_ID", SqlDbType.Int)
            If _MS_PREFIX_ID IsNot Nothing Then 
                cmbParam(2).Value = _MS_PREFIX_ID.Value
            Else
                cmbParam(2).Value = DBNull.value
            End IF

            cmbParam(3) = New SqlParameter("@_NAME_THAI", SqlDbType.VarChar)
            If _NAME_THAI.Trim <> "" Then 
                cmbParam(3).Value = _NAME_THAI
            Else
                cmbParam(3).Value = DBNull.value
            End If

            cmbParam(4) = New SqlParameter("@_NAME_ENG", SqlDbType.VarChar)
            If _NAME_ENG.Trim <> "" Then 
                cmbParam(4).Value = _NAME_ENG
            Else
                cmbParam(4).Value = DBNull.value
            End If

            cmbParam(5) = New SqlParameter("@_SURNAME_THAI", SqlDbType.VarChar)
            If _SURNAME_THAI.Trim <> "" Then 
                cmbParam(5).Value = _SURNAME_THAI
            Else
                cmbParam(5).Value = DBNull.value
            End If

            cmbParam(6) = New SqlParameter("@_SURNAME_ENG", SqlDbType.VarChar)
            If _SURNAME_ENG.Trim <> "" Then 
                cmbParam(6).Value = _SURNAME_ENG
            Else
                cmbParam(6).Value = DBNull.value
            End If

            cmbParam(7) = New SqlParameter("@_MS_DEPARTMENT_ID", SqlDbType.BigInt)
            cmbParam(7).Value = _MS_DEPARTMENT_ID

            cmbParam(8) = New SqlParameter("@_MS_POSITION_ID", SqlDbType.BigInt)
            cmbParam(8).Value = _MS_POSITION_ID

            cmbParam(9) = New SqlParameter("@_USERNAME", SqlDbType.VarChar)
            cmbParam(9).Value = _USERNAME

            cmbParam(10) = New SqlParameter("@_PASSWD", SqlDbType.VarChar)
            cmbParam(10).Value = _PASSWD

            cmbParam(11) = New SqlParameter("@_ENFORCE_PASSWORD_EXPIRATION", SqlDbType.Char)
            cmbParam(11).Value = _ENFORCE_PASSWORD_EXPIRATION

            cmbParam(12) = New SqlParameter("@_PASSWORD_EXPIRY_DATE", SqlDbType.DateTime)
            If _PASSWORD_EXPIRY_DATE.Value.Year > 1 Then 
                cmbParam(12).Value = _PASSWORD_EXPIRY_DATE.Value
            Else
                cmbParam(12).Value = DBNull.value
            End If

            cmbParam(13) = New SqlParameter("@_FOURCE_CHANGE_PASSWORD", SqlDbType.Char)
            cmbParam(13).Value = _FOURCE_CHANGE_PASSWORD

            cmbParam(14) = New SqlParameter("@_ACTIVE_STATUS", SqlDbType.Char)
            cmbParam(14).Value = _ACTIVE_STATUS

            cmbParam(15) = New SqlParameter("@_CREATED_BY", SqlDbType.VarChar)
            cmbParam(15).Value = _CREATED_BY

            cmbParam(16) = New SqlParameter("@_CREATED_DATE", SqlDbType.DateTime)
            cmbParam(16).Value = _CREATED_DATE

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


        '/// Returns an indication whether the record of MS_USER by specified condition is retrieved successfully.
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
                        If Convert.IsDBNull(Rdr("employee_code")) = False Then _employee_code = Rdr("employee_code").ToString()
                        If Convert.IsDBNull(Rdr("ms_prefix_id")) = False Then _ms_prefix_id = Convert.ToInt32(Rdr("ms_prefix_id"))
                        If Convert.IsDBNull(Rdr("name_thai")) = False Then _name_thai = Rdr("name_thai").ToString()
                        If Convert.IsDBNull(Rdr("name_eng")) = False Then _name_eng = Rdr("name_eng").ToString()
                        If Convert.IsDBNull(Rdr("surname_thai")) = False Then _surname_thai = Rdr("surname_thai").ToString()
                        If Convert.IsDBNull(Rdr("surname_eng")) = False Then _surname_eng = Rdr("surname_eng").ToString()
                        If Convert.IsDBNull(Rdr("ms_department_id")) = False Then _ms_department_id = Convert.ToInt64(Rdr("ms_department_id"))
                        If Convert.IsDBNull(Rdr("ms_position_id")) = False Then _ms_position_id = Convert.ToInt64(Rdr("ms_position_id"))
                        If Convert.IsDBNull(Rdr("username")) = False Then _username = Rdr("username").ToString()
                        If Convert.IsDBNull(Rdr("passwd")) = False Then _passwd = Rdr("passwd").ToString()
                        If Convert.IsDBNull(Rdr("enforce_password_expiration")) = False Then _enforce_password_expiration = Rdr("enforce_password_expiration").ToString()
                        If Convert.IsDBNull(Rdr("password_expiry_date")) = False Then _password_expiry_date = Convert.ToDateTime(Rdr("password_expiry_date"))
                        If Convert.IsDBNull(Rdr("fource_change_password")) = False Then _fource_change_password = Rdr("fource_change_password").ToString()
                        If Convert.IsDBNull(Rdr("active_status")) = False Then _active_status = Rdr("active_status").ToString()
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


        '/// Returns an indication whether the record of MS_USER by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Private Function doGetData(whText As String, trans As SQLTransaction) As MsUserLinqDB
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
                        If Convert.IsDBNull(Rdr("employee_code")) = False Then _employee_code = Rdr("employee_code").ToString()
                        If Convert.IsDBNull(Rdr("ms_prefix_id")) = False Then _ms_prefix_id = Convert.ToInt32(Rdr("ms_prefix_id"))
                        If Convert.IsDBNull(Rdr("name_thai")) = False Then _name_thai = Rdr("name_thai").ToString()
                        If Convert.IsDBNull(Rdr("name_eng")) = False Then _name_eng = Rdr("name_eng").ToString()
                        If Convert.IsDBNull(Rdr("surname_thai")) = False Then _surname_thai = Rdr("surname_thai").ToString()
                        If Convert.IsDBNull(Rdr("surname_eng")) = False Then _surname_eng = Rdr("surname_eng").ToString()
                        If Convert.IsDBNull(Rdr("ms_department_id")) = False Then _ms_department_id = Convert.ToInt64(Rdr("ms_department_id"))
                        If Convert.IsDBNull(Rdr("ms_position_id")) = False Then _ms_position_id = Convert.ToInt64(Rdr("ms_position_id"))
                        If Convert.IsDBNull(Rdr("username")) = False Then _username = Rdr("username").ToString()
                        If Convert.IsDBNull(Rdr("passwd")) = False Then _passwd = Rdr("passwd").ToString()
                        If Convert.IsDBNull(Rdr("enforce_password_expiration")) = False Then _enforce_password_expiration = Rdr("enforce_password_expiration").ToString()
                        If Convert.IsDBNull(Rdr("password_expiry_date")) = False Then _password_expiry_date = Convert.ToDateTime(Rdr("password_expiry_date"))
                        If Convert.IsDBNull(Rdr("fource_change_password")) = False Then _fource_change_password = Rdr("fource_change_password").ToString()
                        If Convert.IsDBNull(Rdr("active_status")) = False Then _active_status = Rdr("active_status").ToString()
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


        'Get Insert Statement for table MS_USER
        Private ReadOnly Property SqlInsert() As String 
            Get
                Dim Sql As String=""
                Sql += "INSERT INTO " & tableName  & " (EMPLOYEE_CODE, MS_PREFIX_ID, NAME_THAI, NAME_ENG, SURNAME_THAI, SURNAME_ENG, MS_DEPARTMENT_ID, MS_POSITION_ID, USERNAME, PASSWD, ENFORCE_PASSWORD_EXPIRATION, PASSWORD_EXPIRY_DATE, FOURCE_CHANGE_PASSWORD, ACTIVE_STATUS, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE)"
                Sql += " OUTPUT INSERTED.ID, INSERTED.EMPLOYEE_CODE, INSERTED.MS_PREFIX_ID, INSERTED.NAME_THAI, INSERTED.NAME_ENG, INSERTED.SURNAME_THAI, INSERTED.SURNAME_ENG, INSERTED.MS_DEPARTMENT_ID, INSERTED.MS_POSITION_ID, INSERTED.USERNAME, INSERTED.PASSWD, INSERTED.ENFORCE_PASSWORD_EXPIRATION, INSERTED.PASSWORD_EXPIRY_DATE, INSERTED.FOURCE_CHANGE_PASSWORD, INSERTED.ACTIVE_STATUS, INSERTED.CREATED_BY, INSERTED.CREATED_DATE, INSERTED.UPDATED_BY, INSERTED.UPDATED_DATE
                Sql += " VALUES("
                sql += "@_EMPLOYEE_CODE" & ", "
                sql += "@_MS_PREFIX_ID" & ", "
                sql += "@_NAME_THAI" & ", "
                sql += "@_NAME_ENG" & ", "
                sql += "@_SURNAME_THAI" & ", "
                sql += "@_SURNAME_ENG" & ", "
                sql += "@_MS_DEPARTMENT_ID" & ", "
                sql += "@_MS_POSITION_ID" & ", "
                sql += "@_USERNAME" & ", "
                sql += "@_PASSWD" & ", "
                sql += "@_ENFORCE_PASSWORD_EXPIRATION" & ", "
                sql += "@_PASSWORD_EXPIRY_DATE" & ", "
                sql += "@_FOURCE_CHANGE_PASSWORD" & ", "
                sql += "@_ACTIVE_STATUS" & ", "
                sql += "@_CREATED_BY" & ", "
                sql += "@_CREATED_DATE" & ", "
                sql += "@_UPDATED_BY" & ", "
                sql += "@_UPDATED_DATE"
                sql += ")"
                Return sql
            End Get
        End Property


        'Get update statement form table MS_USER
        Private ReadOnly Property SqlUpdate() As String
            Get
                Dim Sql As String = ""
                Sql += "UPDATE " & tableName & " SET "
                Sql += "EMPLOYEE_CODE = " & "@_EMPLOYEE_CODE" & ", "
                Sql += "MS_PREFIX_ID = " & "@_MS_PREFIX_ID" & ", "
                Sql += "NAME_THAI = " & "@_NAME_THAI" & ", "
                Sql += "NAME_ENG = " & "@_NAME_ENG" & ", "
                Sql += "SURNAME_THAI = " & "@_SURNAME_THAI" & ", "
                Sql += "SURNAME_ENG = " & "@_SURNAME_ENG" & ", "
                Sql += "MS_DEPARTMENT_ID = " & "@_MS_DEPARTMENT_ID" & ", "
                Sql += "MS_POSITION_ID = " & "@_MS_POSITION_ID" & ", "
                Sql += "USERNAME = " & "@_USERNAME" & ", "
                Sql += "PASSWD = " & "@_PASSWD" & ", "
                Sql += "ENFORCE_PASSWORD_EXPIRATION = " & "@_ENFORCE_PASSWORD_EXPIRATION" & ", "
                Sql += "PASSWORD_EXPIRY_DATE = " & "@_PASSWORD_EXPIRY_DATE" & ", "
                Sql += "FOURCE_CHANGE_PASSWORD = " & "@_FOURCE_CHANGE_PASSWORD" & ", "
                Sql += "ACTIVE_STATUS = " & "@_ACTIVE_STATUS" & ", "
                Sql += "CREATED_BY = " & "@_CREATED_BY" & ", "
                Sql += "CREATED_DATE = " & "@_CREATED_DATE" & ", "
                Sql += "UPDATED_BY = " & "@_UPDATED_BY" & ", "
                Sql += "UPDATED_DATE = " & "@_UPDATED_DATE" + ""
                Return Sql
            End Get
        End Property


        'Get Delete Record in table MS_USER
        Private ReadOnly Property SqlDelete() As String
            Get
                Dim Sql As String = "DELETE FROM " & tableName
                Return Sql
            End Get
        End Property


        'Get Select Statement for table MS_USER
        Private ReadOnly Property SqlSelect() As String
            Get
                Dim Sql As String = "SELECT ID, EMPLOYEE_CODE, MS_PREFIX_ID, NAME_THAI, NAME_ENG, SURNAME_THAI, SURNAME_ENG, MS_DEPARTMENT_ID, MS_POSITION_ID, USERNAME, PASSWD, ENFORCE_PASSWORD_EXPIRATION, PASSWORD_EXPIRY_DATE, FOURCE_CHANGE_PASSWORD, ACTIVE_STATUS, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE FROM " & tableName
                Return Sql
            End Get
        End Property

    End Class
End Namespace
