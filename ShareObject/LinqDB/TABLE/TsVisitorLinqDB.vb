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
    'Represents a transaction for TS_VISITOR table LinqDB.
    '[Create by  on January, 6 2015]
    Public Class TsVisitorLinqDB
        Public sub TsVisitorLinqDB()

        End Sub 
        ' TS_VISITOR
        Const _tableName As String = "TS_VISITOR"
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
        Dim _ID_CARDNO As  String  = ""
        Dim _FIRST_NAME_TH As  String  = ""
        Dim _LAST_NAME_TH As  String  = ""
        Dim _FIRST_NAME_EN As  String  = ""
        Dim _LAST_NAME_EN As  String  = ""
        Dim _BIRTHDATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _ISSUEDATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _ADDRESS As  String  = ""
        Dim _EXPDATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _MIFARE_ID As  String  = ""
        Dim _IS_APPOINTMENT As Char = "Y"
        Dim _STAFF_NAME As  String  = ""
        Dim _MS_USER_ID As  System.Nullable(Of Long)  = 0
        Dim _PLACE As  String  = ""
        Dim _PURPOSE As  String  = ""
        Dim _MS_CARD_TYPE_ID As  System.Nullable(Of Long)  = 0
        Dim _ID_PICTURE() As Byte
        Dim _CARD_PICTURE() As Byte
        Dim _IN_DATE As DateTime = New DateTime(1,1,1)
        Dim _OUT_DATE As  System.Nullable(Of DateTime)  = New DateTime(1,1,1)
        Dim _TS_PREBOOKING_ID As  System.Nullable(Of Long)  = 0

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
        <Column(Storage:="_ID_CARDNO", DbType:="VarChar(13)")>  _
        Public Property ID_CARDNO() As  String 
            Get
                Return _ID_CARDNO
            End Get
            Set(ByVal value As  String )
               _ID_CARDNO = value
            End Set
        End Property 
        <Column(Storage:="_FIRST_NAME_TH", DbType:="VarChar(100)")>  _
        Public Property FIRST_NAME_TH() As  String 
            Get
                Return _FIRST_NAME_TH
            End Get
            Set(ByVal value As  String )
               _FIRST_NAME_TH = value
            End Set
        End Property 
        <Column(Storage:="_LAST_NAME_TH", DbType:="VarChar(100)")>  _
        Public Property LAST_NAME_TH() As  String 
            Get
                Return _LAST_NAME_TH
            End Get
            Set(ByVal value As  String )
               _LAST_NAME_TH = value
            End Set
        End Property 
        <Column(Storage:="_FIRST_NAME_EN", DbType:="VarChar(100)")>  _
        Public Property FIRST_NAME_EN() As  String 
            Get
                Return _FIRST_NAME_EN
            End Get
            Set(ByVal value As  String )
               _FIRST_NAME_EN = value
            End Set
        End Property 
        <Column(Storage:="_LAST_NAME_EN", DbType:="VarChar(100)")>  _
        Public Property LAST_NAME_EN() As  String 
            Get
                Return _LAST_NAME_EN
            End Get
            Set(ByVal value As  String )
               _LAST_NAME_EN = value
            End Set
        End Property 
        <Column(Storage:="_BIRTHDATE", DbType:="DateTime")>  _
        Public Property BIRTHDATE() As  System.Nullable(Of DateTime) 
            Get
                Return _BIRTHDATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _BIRTHDATE = value
            End Set
        End Property 
        <Column(Storage:="_ISSUEDATE", DbType:="DateTime")>  _
        Public Property ISSUEDATE() As  System.Nullable(Of DateTime) 
            Get
                Return _ISSUEDATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _ISSUEDATE = value
            End Set
        End Property 
        <Column(Storage:="_ADDRESS", DbType:="VarChar(500)")>  _
        Public Property ADDRESS() As  String 
            Get
                Return _ADDRESS
            End Get
            Set(ByVal value As  String )
               _ADDRESS = value
            End Set
        End Property 
        <Column(Storage:="_EXPDATE", DbType:="DateTime")>  _
        Public Property EXPDATE() As  System.Nullable(Of DateTime) 
            Get
                Return _EXPDATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _EXPDATE = value
            End Set
        End Property 
        <Column(Storage:="_MIFARE_ID", DbType:="VarChar(100)")>  _
        Public Property MIFARE_ID() As  String 
            Get
                Return _MIFARE_ID
            End Get
            Set(ByVal value As  String )
               _MIFARE_ID = value
            End Set
        End Property 
        <Column(Storage:="_IS_APPOINTMENT", DbType:="Char(1) NOT NULL ",CanBeNull:=false)>  _
        Public Property IS_APPOINTMENT() As Char
            Get
                Return _IS_APPOINTMENT
            End Get
            Set(ByVal value As Char)
               _IS_APPOINTMENT = value
            End Set
        End Property 
        <Column(Storage:="_STAFF_NAME", DbType:="VarChar(255)")>  _
        Public Property STAFF_NAME() As  String 
            Get
                Return _STAFF_NAME
            End Get
            Set(ByVal value As  String )
               _STAFF_NAME = value
            End Set
        End Property 
        <Column(Storage:="_MS_USER_ID", DbType:="BigInt")>  _
        Public Property MS_USER_ID() As  System.Nullable(Of Long) 
            Get
                Return _MS_USER_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _MS_USER_ID = value
            End Set
        End Property 
        <Column(Storage:="_PLACE", DbType:="VarChar(255)")>  _
        Public Property PLACE() As  String 
            Get
                Return _PLACE
            End Get
            Set(ByVal value As  String )
               _PLACE = value
            End Set
        End Property 
        <Column(Storage:="_PURPOSE", DbType:="VarChar(255)")>  _
        Public Property PURPOSE() As  String 
            Get
                Return _PURPOSE
            End Get
            Set(ByVal value As  String )
               _PURPOSE = value
            End Set
        End Property 
        <Column(Storage:="_MS_CARD_TYPE_ID", DbType:="BigInt")>  _
        Public Property MS_CARD_TYPE_ID() As  System.Nullable(Of Long) 
            Get
                Return _MS_CARD_TYPE_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _MS_CARD_TYPE_ID = value
            End Set
        End Property 
        <Column(Storage:="_ID_PICTURE", DbType:="IMAGE")>  _
        Public Property ID_PICTURE() As  Byte() 
            Get
                Return _ID_PICTURE
            End Get
            Set(ByVal value() As Byte)
               _ID_PICTURE = value
            End Set
        End Property 
        <Column(Storage:="_CARD_PICTURE", DbType:="IMAGE")>  _
        Public Property CARD_PICTURE() As  Byte() 
            Get
                Return _CARD_PICTURE
            End Get
            Set(ByVal value() As Byte)
               _CARD_PICTURE = value
            End Set
        End Property 
        <Column(Storage:="_IN_DATE", DbType:="DateTime NOT NULL ",CanBeNull:=false)>  _
        Public Property IN_DATE() As DateTime
            Get
                Return _IN_DATE
            End Get
            Set(ByVal value As DateTime)
               _IN_DATE = value
            End Set
        End Property 
        <Column(Storage:="_OUT_DATE", DbType:="DateTime")>  _
        Public Property OUT_DATE() As  System.Nullable(Of DateTime) 
            Get
                Return _OUT_DATE
            End Get
            Set(ByVal value As  System.Nullable(Of DateTime) )
               _OUT_DATE = value
            End Set
        End Property 
        <Column(Storage:="_TS_PREBOOKING_ID", DbType:="BigInt")>  _
        Public Property TS_PREBOOKING_ID() As  System.Nullable(Of Long) 
            Get
                Return _TS_PREBOOKING_ID
            End Get
            Set(ByVal value As  System.Nullable(Of Long) )
               _TS_PREBOOKING_ID = value
            End Set
        End Property 


        'Clear All Data
        Private Sub ClearData()
            _ID = 0
            _CREATED_BY = ""
            _CREATED_DATE = New DateTime(1,1,1)
            _UPDATED_BY = ""
            _UPDATED_DATE = New DateTime(1,1,1)
            _ID_CARDNO = ""
            _FIRST_NAME_TH = ""
            _LAST_NAME_TH = ""
            _FIRST_NAME_EN = ""
            _LAST_NAME_EN = ""
            _BIRTHDATE = New DateTime(1,1,1)
            _ISSUEDATE = New DateTime(1,1,1)
            _ADDRESS = ""
            _EXPDATE = New DateTime(1,1,1)
            _MIFARE_ID = ""
            _IS_APPOINTMENT = ""
            _STAFF_NAME = ""
            _MS_USER_ID = 0
            _PLACE = ""
            _PURPOSE = ""
            _MS_CARD_TYPE_ID = 0
             _ID_PICTURE = Nothing
             _CARD_PICTURE = Nothing
            _IN_DATE = New DateTime(1,1,1)
            _OUT_DATE = New DateTime(1,1,1)
            _TS_PREBOOKING_ID = 0
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


        '/// Returns an indication whether the current data is inserted into TS_VISITOR table successfully.
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


        '/// Returns an indication whether the current data is updated to TS_VISITOR table successfully.
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


        '/// Returns an indication whether the current data is updated to TS_VISITOR table successfully.
        '/// <returns>true if update data successfully; otherwise, false.</returns>
        Public Function UpdateBySql(Sql As String, trans As SQLTransaction) As Boolean
            If trans IsNot Nothing Then 
                Return (DB.ExecuteNonQuery(Sql, trans) > -1)
            Else 
                _error = "Transaction Is not null"
                Return False
            End If 
        End Function


        '/// Returns an indication whether the current data is deleted from TS_VISITOR table successfully.
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


        '/// Returns an indication whether the record of TS_VISITOR by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByPK(cID As Long, trans As SQLTransaction) As Boolean
            Return doChkData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record and Mapping field to Data Class of TS_VISITOR by specified id key is retrieved successfully.
        '/// <param name=cid>The id key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function GetDataByPK(cID As Long, trans As SQLTransaction) As TsVisitorLinqDB
            Return doGetData("ID = " & DB.SetDouble(cID), trans)
        End Function


        '/// Returns an indication whether the record of TS_VISITOR by specified ID_CARDNO key is retrieved successfully.
        '/// <param name=cID_CARDNO>The ID_CARDNO key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByID_CARDNO(cID_CARDNO As String, trans As SQLTransaction) As Boolean
            Return doChkData("ID_CARDNO = " & DB.SetString(cID_CARDNO) & " ", trans)
        End Function

        '/// Returns an duplicate data record of TS_VISITOR by specified ID_CARDNO key is retrieved successfully.
        '/// <param name=cID_CARDNO>The ID_CARDNO key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByID_CARDNO(cID_CARDNO As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("ID_CARDNO = " & DB.SetString(cID_CARDNO) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of TS_VISITOR by specified MS_USER_ID key is retrieved successfully.
        '/// <param name=cMS_USER_ID>The MS_USER_ID key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByMS_USER_ID(cMS_USER_ID As Long, trans As SQLTransaction) As Boolean
            Return doChkData("MS_USER_ID = " & DB.SetDouble(cMS_USER_ID) & " ", trans)
        End Function

        '/// Returns an duplicate data record of TS_VISITOR by specified MS_USER_ID key is retrieved successfully.
        '/// <param name=cMS_USER_ID>The MS_USER_ID key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByMS_USER_ID(cMS_USER_ID As Long, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("MS_USER_ID = " & DB.SetDouble(cMS_USER_ID) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of TS_VISITOR by specified MIFARE_ID key is retrieved successfully.
        '/// <param name=cMIFARE_ID>The MIFARE_ID key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByMIFARE_ID(cMIFARE_ID As String, trans As SQLTransaction) As Boolean
            Return doChkData("MIFARE_ID = " & DB.SetString(cMIFARE_ID) & " ", trans)
        End Function

        '/// Returns an duplicate data record of TS_VISITOR by specified MIFARE_ID key is retrieved successfully.
        '/// <param name=cMIFARE_ID>The MIFARE_ID key.</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDuplicateByMIFARE_ID(cMIFARE_ID As String, cid As Long, trans As SQLTransaction) As Boolean
            Return doChkData("MIFARE_ID = " & DB.SetString(cMIFARE_ID) & " " & " And id <> " & DB.SetDouble(cid) & " ", trans)
        End Function


        '/// Returns an indication whether the record of TS_VISITOR by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Public Function ChkDataByWhere(whText As String, trans As SQLTransaction) As Boolean
            Return doChkData(whText, trans)
        End Function



        '/// Returns an indication whether the current data is inserted into TS_VISITOR table successfully.
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


        '/// Returns an indication whether the current data is updated to TS_VISITOR table successfully.
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


        '/// Returns an indication whether the current data is deleted from TS_VISITOR table successfully.
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
            Dim cmbParam(25) As SqlParameter
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

            cmbParam(5) = New SqlParameter("@_ID_CARDNO", SqlDbType.VarChar)
            If _ID_CARDNO.Trim <> "" Then 
                cmbParam(5).Value = _ID_CARDNO
            Else
                cmbParam(5).Value = DBNull.value
            End If

            cmbParam(6) = New SqlParameter("@_FIRST_NAME_TH", SqlDbType.VarChar)
            If _FIRST_NAME_TH.Trim <> "" Then 
                cmbParam(6).Value = _FIRST_NAME_TH
            Else
                cmbParam(6).Value = DBNull.value
            End If

            cmbParam(7) = New SqlParameter("@_LAST_NAME_TH", SqlDbType.VarChar)
            If _LAST_NAME_TH.Trim <> "" Then 
                cmbParam(7).Value = _LAST_NAME_TH
            Else
                cmbParam(7).Value = DBNull.value
            End If

            cmbParam(8) = New SqlParameter("@_FIRST_NAME_EN", SqlDbType.VarChar)
            If _FIRST_NAME_EN.Trim <> "" Then 
                cmbParam(8).Value = _FIRST_NAME_EN
            Else
                cmbParam(8).Value = DBNull.value
            End If

            cmbParam(9) = New SqlParameter("@_LAST_NAME_EN", SqlDbType.VarChar)
            If _LAST_NAME_EN.Trim <> "" Then 
                cmbParam(9).Value = _LAST_NAME_EN
            Else
                cmbParam(9).Value = DBNull.value
            End If

            cmbParam(10) = New SqlParameter("@_BIRTHDATE", SqlDbType.DateTime)
            If _BIRTHDATE.Value.Year > 1 Then 
                cmbParam(10).Value = _BIRTHDATE.Value
            Else
                cmbParam(10).Value = DBNull.value
            End If

            cmbParam(11) = New SqlParameter("@_ISSUEDATE", SqlDbType.DateTime)
            If _ISSUEDATE.Value.Year > 1 Then 
                cmbParam(11).Value = _ISSUEDATE.Value
            Else
                cmbParam(11).Value = DBNull.value
            End If

            cmbParam(12) = New SqlParameter("@_ADDRESS", SqlDbType.VarChar)
            If _ADDRESS.Trim <> "" Then 
                cmbParam(12).Value = _ADDRESS
            Else
                cmbParam(12).Value = DBNull.value
            End If

            cmbParam(13) = New SqlParameter("@_EXPDATE", SqlDbType.DateTime)
            If _EXPDATE.Value.Year > 1 Then 
                cmbParam(13).Value = _EXPDATE.Value
            Else
                cmbParam(13).Value = DBNull.value
            End If

            cmbParam(14) = New SqlParameter("@_MIFARE_ID", SqlDbType.VarChar)
            If _MIFARE_ID.Trim <> "" Then 
                cmbParam(14).Value = _MIFARE_ID
            Else
                cmbParam(14).Value = DBNull.value
            End If

            cmbParam(15) = New SqlParameter("@_IS_APPOINTMENT", SqlDbType.Char)
            cmbParam(15).Value = _IS_APPOINTMENT

            cmbParam(16) = New SqlParameter("@_STAFF_NAME", SqlDbType.VarChar)
            If _STAFF_NAME.Trim <> "" Then 
                cmbParam(16).Value = _STAFF_NAME
            Else
                cmbParam(16).Value = DBNull.value
            End If

            cmbParam(17) = New SqlParameter("@_MS_USER_ID", SqlDbType.BigInt)
            If _MS_USER_ID IsNot Nothing Then 
                cmbParam(17).Value = _MS_USER_ID.Value
            Else
                cmbParam(17).Value = DBNull.value
            End IF

            cmbParam(18) = New SqlParameter("@_PLACE", SqlDbType.VarChar)
            If _PLACE.Trim <> "" Then 
                cmbParam(18).Value = _PLACE
            Else
                cmbParam(18).Value = DBNull.value
            End If

            cmbParam(19) = New SqlParameter("@_PURPOSE", SqlDbType.VarChar)
            If _PURPOSE.Trim <> "" Then 
                cmbParam(19).Value = _PURPOSE
            Else
                cmbParam(19).Value = DBNull.value
            End If

            cmbParam(20) = New SqlParameter("@_MS_CARD_TYPE_ID", SqlDbType.BigInt)
            If _MS_CARD_TYPE_ID IsNot Nothing Then 
                cmbParam(20).Value = _MS_CARD_TYPE_ID.Value
            Else
                cmbParam(20).Value = DBNull.value
            End IF

            If _ID_PICTURE IsNot Nothing Then 
                cmbParam(21) = New SqlParameter("@_ID_PICTURE",SqlDbType.Image, _ID_PICTURE.Length)
                cmbParam(21).Value = _ID_PICTURE
            Else
                cmbParam(21) = New SqlParameter("@_ID_PICTURE", SqlDbType.Image)
                cmbParam(21).Value = DBNull.value
            End If

            If _CARD_PICTURE IsNot Nothing Then 
                cmbParam(22) = New SqlParameter("@_CARD_PICTURE",SqlDbType.Image, _CARD_PICTURE.Length)
                cmbParam(22).Value = _CARD_PICTURE
            Else
                cmbParam(22) = New SqlParameter("@_CARD_PICTURE", SqlDbType.Image)
                cmbParam(22).Value = DBNull.value
            End If

            cmbParam(23) = New SqlParameter("@_IN_DATE", SqlDbType.DateTime)
            cmbParam(23).Value = _IN_DATE

            cmbParam(24) = New SqlParameter("@_OUT_DATE", SqlDbType.DateTime)
            If _OUT_DATE.Value.Year > 1 Then 
                cmbParam(24).Value = _OUT_DATE.Value
            Else
                cmbParam(24).Value = DBNull.value
            End If

            cmbParam(25) = New SqlParameter("@_TS_PREBOOKING_ID", SqlDbType.BigInt)
            If _TS_PREBOOKING_ID IsNot Nothing Then 
                cmbParam(25).Value = _TS_PREBOOKING_ID.Value
            Else
                cmbParam(25).Value = DBNull.value
            End IF

            Return cmbParam
        End Function


        '/// Returns an indication whether the record of TS_VISITOR by specified condition is retrieved successfully.
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
                        If Convert.IsDBNull(Rdr("id_cardno")) = False Then _id_cardno = Rdr("id_cardno").ToString()
                        If Convert.IsDBNull(Rdr("First_Name_TH")) = False Then _First_Name_TH = Rdr("First_Name_TH").ToString()
                        If Convert.IsDBNull(Rdr("Last_Name_TH")) = False Then _Last_Name_TH = Rdr("Last_Name_TH").ToString()
                        If Convert.IsDBNull(Rdr("First_Name_EN")) = False Then _First_Name_EN = Rdr("First_Name_EN").ToString()
                        If Convert.IsDBNull(Rdr("Last_Name_EN")) = False Then _Last_Name_EN = Rdr("Last_Name_EN").ToString()
                        If Convert.IsDBNull(Rdr("BirthDate")) = False Then _BirthDate = Convert.ToDateTime(Rdr("BirthDate"))
                        If Convert.IsDBNull(Rdr("IssueDate")) = False Then _IssueDate = Convert.ToDateTime(Rdr("IssueDate"))
                        If Convert.IsDBNull(Rdr("Address")) = False Then _Address = Rdr("Address").ToString()
                        If Convert.IsDBNull(Rdr("expdate")) = False Then _expdate = Convert.ToDateTime(Rdr("expdate"))
                        If Convert.IsDBNull(Rdr("Mifare_ID")) = False Then _Mifare_ID = Rdr("Mifare_ID").ToString()
                        If Convert.IsDBNull(Rdr("is_appointment")) = False Then _is_appointment = Rdr("is_appointment").ToString()
                        If Convert.IsDBNull(Rdr("staff_name")) = False Then _staff_name = Rdr("staff_name").ToString()
                        If Convert.IsDBNull(Rdr("ms_user_id")) = False Then _ms_user_id = Convert.ToInt64(Rdr("ms_user_id"))
                        If Convert.IsDBNull(Rdr("place")) = False Then _place = Rdr("place").ToString()
                        If Convert.IsDBNull(Rdr("purpose")) = False Then _purpose = Rdr("purpose").ToString()
                        If Convert.IsDBNull(Rdr("ms_card_type_id")) = False Then _ms_card_type_id = Convert.ToInt64(Rdr("ms_card_type_id"))
                        If Convert.IsDBNull(Rdr("id_picture")) = False Then _id_picture = CType(Rdr("id_picture"), Byte())
                        If Convert.IsDBNull(Rdr("card_picture")) = False Then _card_picture = CType(Rdr("card_picture"), Byte())
                        If Convert.IsDBNull(Rdr("in_date")) = False Then _in_date = Convert.ToDateTime(Rdr("in_date"))
                        If Convert.IsDBNull(Rdr("out_date")) = False Then _out_date = Convert.ToDateTime(Rdr("out_date"))
                        If Convert.IsDBNull(Rdr("ts_prebooking_id")) = False Then _ts_prebooking_id = Convert.ToInt64(Rdr("ts_prebooking_id"))
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


        '/// Returns an indication whether the record of TS_VISITOR by specified condition is retrieved successfully.
        '/// <param name=whText>The condition specify the deleting record(s).</param>
        '/// <param name=trans>The System.Data.SQLClient.SQLTransaction used by this System.Data.SQLClient.SQLCommand.</param>
        '/// <returns>true if data is retrieved successfully; otherwise, false.</returns>
        Private Function doGetData(whText As String, trans As SQLTransaction) As TsVisitorLinqDB
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
                        If Convert.IsDBNull(Rdr("id_cardno")) = False Then _id_cardno = Rdr("id_cardno").ToString()
                        If Convert.IsDBNull(Rdr("First_Name_TH")) = False Then _First_Name_TH = Rdr("First_Name_TH").ToString()
                        If Convert.IsDBNull(Rdr("Last_Name_TH")) = False Then _Last_Name_TH = Rdr("Last_Name_TH").ToString()
                        If Convert.IsDBNull(Rdr("First_Name_EN")) = False Then _First_Name_EN = Rdr("First_Name_EN").ToString()
                        If Convert.IsDBNull(Rdr("Last_Name_EN")) = False Then _Last_Name_EN = Rdr("Last_Name_EN").ToString()
                        If Convert.IsDBNull(Rdr("BirthDate")) = False Then _BirthDate = Convert.ToDateTime(Rdr("BirthDate"))
                        If Convert.IsDBNull(Rdr("IssueDate")) = False Then _IssueDate = Convert.ToDateTime(Rdr("IssueDate"))
                        If Convert.IsDBNull(Rdr("Address")) = False Then _Address = Rdr("Address").ToString()
                        If Convert.IsDBNull(Rdr("expdate")) = False Then _expdate = Convert.ToDateTime(Rdr("expdate"))
                        If Convert.IsDBNull(Rdr("Mifare_ID")) = False Then _Mifare_ID = Rdr("Mifare_ID").ToString()
                        If Convert.IsDBNull(Rdr("is_appointment")) = False Then _is_appointment = Rdr("is_appointment").ToString()
                        If Convert.IsDBNull(Rdr("staff_name")) = False Then _staff_name = Rdr("staff_name").ToString()
                        If Convert.IsDBNull(Rdr("ms_user_id")) = False Then _ms_user_id = Convert.ToInt64(Rdr("ms_user_id"))
                        If Convert.IsDBNull(Rdr("place")) = False Then _place = Rdr("place").ToString()
                        If Convert.IsDBNull(Rdr("purpose")) = False Then _purpose = Rdr("purpose").ToString()
                        If Convert.IsDBNull(Rdr("ms_card_type_id")) = False Then _ms_card_type_id = Convert.ToInt64(Rdr("ms_card_type_id"))
                        If Convert.IsDBNull(Rdr("id_picture")) = False Then _id_picture = CType(Rdr("id_picture"), Byte())
                        If Convert.IsDBNull(Rdr("card_picture")) = False Then _card_picture = CType(Rdr("card_picture"), Byte())
                        If Convert.IsDBNull(Rdr("in_date")) = False Then _in_date = Convert.ToDateTime(Rdr("in_date"))
                        If Convert.IsDBNull(Rdr("out_date")) = False Then _out_date = Convert.ToDateTime(Rdr("out_date"))
                        If Convert.IsDBNull(Rdr("ts_prebooking_id")) = False Then _ts_prebooking_id = Convert.ToInt64(Rdr("ts_prebooking_id"))
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


        'Get Insert Statement for table TS_VISITOR
        Private ReadOnly Property SqlInsert() As String 
            Get
                Dim Sql As String=""
                Sql += "INSERT INTO " & tableName  & " (CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE, ID_CARDNO, FIRST_NAME_TH, LAST_NAME_TH, FIRST_NAME_EN, LAST_NAME_EN, BIRTHDATE, ISSUEDATE, ADDRESS, EXPDATE, MIFARE_ID, IS_APPOINTMENT, STAFF_NAME, MS_USER_ID, PLACE, PURPOSE, MS_CARD_TYPE_ID, ID_PICTURE, CARD_PICTURE, IN_DATE, OUT_DATE, TS_PREBOOKING_ID)"
                Sql += " OUTPUT INSERTED.ID, INSERTED.CREATED_BY, INSERTED.CREATED_DATE, INSERTED.UPDATED_BY, INSERTED.UPDATED_DATE, INSERTED.ID_CARDNO, INSERTED.FIRST_NAME_TH, INSERTED.LAST_NAME_TH, INSERTED.FIRST_NAME_EN, INSERTED.LAST_NAME_EN, INSERTED.BIRTHDATE, INSERTED.ISSUEDATE, INSERTED.ADDRESS, INSERTED.EXPDATE, INSERTED.MIFARE_ID, INSERTED.IS_APPOINTMENT, INSERTED.STAFF_NAME, INSERTED.MS_USER_ID, INSERTED.PLACE, INSERTED.PURPOSE, INSERTED.MS_CARD_TYPE_ID, INSERTED.ID_PICTURE, INSERTED.CARD_PICTURE, INSERTED.IN_DATE, INSERTED.OUT_DATE, INSERTED.TS_PREBOOKING_ID
                Sql += " VALUES("
                sql += "@_CREATED_BY" & ", "
                sql += "@_CREATED_DATE" & ", "
                sql += "@_UPDATED_BY" & ", "
                sql += "@_UPDATED_DATE" & ", "
                sql += "@_ID_CARDNO" & ", "
                sql += "@_FIRST_NAME_TH" & ", "
                sql += "@_LAST_NAME_TH" & ", "
                sql += "@_FIRST_NAME_EN" & ", "
                sql += "@_LAST_NAME_EN" & ", "
                sql += "@_BIRTHDATE" & ", "
                sql += "@_ISSUEDATE" & ", "
                sql += "@_ADDRESS" & ", "
                sql += "@_EXPDATE" & ", "
                sql += "@_MIFARE_ID" & ", "
                sql += "@_IS_APPOINTMENT" & ", "
                sql += "@_STAFF_NAME" & ", "
                sql += "@_MS_USER_ID" & ", "
                sql += "@_PLACE" & ", "
                sql += "@_PURPOSE" & ", "
                sql += "@_MS_CARD_TYPE_ID" & ", "
                sql += "@_ID_PICTURE" & ", "
                sql += "@_CARD_PICTURE" & ", "
                sql += "@_IN_DATE" & ", "
                sql += "@_OUT_DATE" & ", "
                sql += "@_TS_PREBOOKING_ID"
                sql += ")"
                Return sql
            End Get
        End Property


        'Get update statement form table TS_VISITOR
        Private ReadOnly Property SqlUpdate() As String
            Get
                Dim Sql As String = ""
                Sql += "UPDATE " & tableName & " SET "
                Sql += "CREATED_BY = " & "@_CREATED_BY" & ", "
                Sql += "CREATED_DATE = " & "@_CREATED_DATE" & ", "
                Sql += "UPDATED_BY = " & "@_UPDATED_BY" & ", "
                Sql += "UPDATED_DATE = " & "@_UPDATED_DATE" & ", "
                Sql += "ID_CARDNO = " & "@_ID_CARDNO" & ", "
                Sql += "FIRST_NAME_TH = " & "@_FIRST_NAME_TH" & ", "
                Sql += "LAST_NAME_TH = " & "@_LAST_NAME_TH" & ", "
                Sql += "FIRST_NAME_EN = " & "@_FIRST_NAME_EN" & ", "
                Sql += "LAST_NAME_EN = " & "@_LAST_NAME_EN" & ", "
                Sql += "BIRTHDATE = " & "@_BIRTHDATE" & ", "
                Sql += "ISSUEDATE = " & "@_ISSUEDATE" & ", "
                Sql += "ADDRESS = " & "@_ADDRESS" & ", "
                Sql += "EXPDATE = " & "@_EXPDATE" & ", "
                Sql += "MIFARE_ID = " & "@_MIFARE_ID" & ", "
                Sql += "IS_APPOINTMENT = " & "@_IS_APPOINTMENT" & ", "
                Sql += "STAFF_NAME = " & "@_STAFF_NAME" & ", "
                Sql += "MS_USER_ID = " & "@_MS_USER_ID" & ", "
                Sql += "PLACE = " & "@_PLACE" & ", "
                Sql += "PURPOSE = " & "@_PURPOSE" & ", "
                Sql += "MS_CARD_TYPE_ID = " & "@_MS_CARD_TYPE_ID" & ", "
                Sql += "ID_PICTURE = " & "@_ID_PICTURE" & ", "
                Sql += "CARD_PICTURE = " & "@_CARD_PICTURE" & ", "
                Sql += "IN_DATE = " & "@_IN_DATE" & ", "
                Sql += "OUT_DATE = " & "@_OUT_DATE" & ", "
                Sql += "TS_PREBOOKING_ID = " & "@_TS_PREBOOKING_ID" + ""
                Return Sql
            End Get
        End Property


        'Get Delete Record in table TS_VISITOR
        Private ReadOnly Property SqlDelete() As String
            Get
                Dim Sql As String = "DELETE FROM " & tableName
                Return Sql
            End Get
        End Property


        'Get Select Statement for table TS_VISITOR
        Private ReadOnly Property SqlSelect() As String
            Get
                Dim Sql As String = "SELECT ID, CREATED_BY, CREATED_DATE, UPDATED_BY, UPDATED_DATE, ID_CARDNO, FIRST_NAME_TH, LAST_NAME_TH, FIRST_NAME_EN, LAST_NAME_EN, BIRTHDATE, ISSUEDATE, ADDRESS, EXPDATE, MIFARE_ID, IS_APPOINTMENT, STAFF_NAME, MS_USER_ID, PLACE, PURPOSE, MS_CARD_TYPE_ID, ID_PICTURE, CARD_PICTURE, IN_DATE, OUT_DATE, TS_PREBOOKING_ID FROM " & tableName
                Return Sql
            End Get
        End Property

    End Class
End Namespace
