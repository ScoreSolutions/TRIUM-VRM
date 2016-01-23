Imports System.Data.SqlClient
Imports System.Data
Imports System.IO
Imports VRM.Register
Imports VRM.My.Resources
Imports System.Globalization
Imports System.Threading
Imports System.Text
Imports Engine.Common
Imports LinqDB.ConnectDB

Public Class frmRegister

    'Dim objConn As New OleDbConnection("Provider=microsoft.Jet.oledb.4.0;Data Source=" & Application.StartupPath & "\VRM.mdb;Jet OLEDB:Database Password=1qaz@WSX;")
    'Dim objConn As SqlConnection = SqlDB.GetConnection
    Dim imgFace As Image
    Dim _CaptureEnable As String = "N"
    Dim LengthBuffer As Integer = 255
    Dim LoopRec As Integer = 0
    Public enUsCulture As CultureInfo = CultureInfo.GetCultureInfo("en-US")
    Public TextCom As String = ""
    Public TextGPS As String = ""
    Public TextID As String = ""
    Public TextSend As String = ""
    Public FlagGPS As Boolean = False
    Public FLAG_UPDATE As Boolean = False

    Public locations As String = ""
    Public filename As String = ""
    Public stationName As String = ""
    Public stationIpAddress As String = ""
    Public threadSamplingGPS As Thread = Nothing
    Public Comport As String = ""
    Public WebserviceLink As String = ""
    Dim TmpCntBlacklist As Integer = 0

    Public recieve As Byte() = New Byte(255) {}
    Public DataID As Byte() = New Byte(255) {}
    Public DataGPS As Byte() = New Byte(255) {}
    Public BuffComPort As Byte() = New Byte(9999) {}
    Public DataCom As String() = New String(8) {}
    Public DataThai As String() = New String(8) {}
    Public BuffCom As String = ""
    Public DataReceive As New StringBuilder

    Public buffer As Integer = 0
    Public Length As Integer = 0
    Public BuffLength As Integer = 0

    Public FlagEnd As Boolean = False
    Public FlagSum As Boolean = False
    Public CheckSum As Byte = &H0
    Public DataSum As Byte = &H0
    Public LengthGPS As Integer = 0
    Public LengthSum As Integer = 0
    Public TimeOut As Integer



    Private Delegate Sub myDelegateOne(ByVal data As String)
    Private myUpdateBoxThaiID As myDelegateOne
    Private myUpdateBoxSex As myDelegateOne
    Private myUpdateBoxNameThai As myDelegateOne
    Private myUpdateBoxNameEnglish As myDelegateOne
    Private myUpdateBoxDateOfBirth As myDelegateOne
    Private myUpdateBoxAddress As myDelegateOne
    Private myUpdateBoxIssueDate As myDelegateOne
    Private myUpdateBoxIssuePlace As myDelegateOne
    Private myUpdateBoxNumber As myDelegateOne
    Private myUpdateBoxMifare As myDelegateOne
    Private myUpdateBoxCustomerName As myDelegateOne
    Private myUpdateBoxLocation As myDelegateOne
    Private myUpdateBoxReason As myDelegateOne
    Private myUpdateBoxTime As myDelegateOne

    Private Sub frmRegister_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        DisableSerialBarcodeReader()
        DisconnectComportSerialBarcodeReader()
    End Sub

    Private Sub frmRegister_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        If SqlDB.ChkConnection() = False Then
            MsgBox("Connect Database Fail!!")
            System.Environment.Exit(0)
        End If

        myUpdateBoxThaiID = AddressOf WriteBoxThaiID
        myUpdateBoxSex = AddressOf WriteBoxSex
        myUpdateBoxNameThai = AddressOf WriteBoxNameThai
        myUpdateBoxNameEnglish = AddressOf WriteBoxNameEnglish
        myUpdateBoxDateOfBirth = AddressOf WriteBoxDateOfBirth
        myUpdateBoxAddress = AddressOf WriteBoxAddress
        myUpdateBoxIssueDate = AddressOf WriteBoxIssueDate
        myUpdateBoxIssuePlace = AddressOf WriteBoxIssuePlace
        myUpdateBoxNumber = AddressOf WriteBoxNumber
        myUpdateBoxMifare = AddressOf WriteBoxMifare
        myUpdateBoxCustomerName = AddressOf WriteBoxCustomerName
        myUpdateBoxLocation = AddressOf WriteBoxLocation
        myUpdateBoxReason = AddressOf WriteBoxReason
        myUpdateBoxTime = AddressOf WriteBoxTime

        Try
            LoopRec = 0
            SetCardType()
            ClearData()
            OpenIDCardSerialPort()
        Catch ex As Exception

        End Try

        txtCardID.Focus()
        txtCardID.Select()
        ClientIP = GetIPAddress()
    End Sub

    Private Sub OpenIDCardSerialPort()
        If Not SerialPort1.IsOpen Then
            Try
                Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
                ini.Section = "IDCardReader"
                SerialPort1.PortName = ini.ReadString("IDCardComPort")
                SerialPort1.BaudRate = ini.ReadString("IDCardBaudRate")
                SerialPort1.Open()
                'buttonConnect.Text = "DISCONNECT"
                SerialPort1.DiscardInBuffer()
            Catch ex As Exception

            End Try
        Else
            SerialPort1.Close()
            'buttonConnect.Text = "CONNECT"
        End If

    End Sub

    Private Sub SetCardType()
        Dim dt As New DataTable
        dt = FunctionENG.GetDataTable("select id, card_name from ms_card_type where active_status='Y' order by id")
        If dt.Rows.Count > 0 Then
            cmbCardType.DisplayMember = "card_name"
            cmbCardType.ValueMember = "id"
            cmbCardType.DataSource = dt
        End If
    End Sub

    Public Sub btnCancel_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCancel.Click
        ClearData()
    End Sub

    Sub ClearData()
        txtAddress.Text = ""
        txtBirthDate.Text = ""
        txtCardID.Text = ""
        txtExpDate.Text = ""
        txtFName_EN.Text = ""
        txtFName_TH.Text = ""
        txtIssueDate.Text = ""
        txtLName_EN.Text = ""
        txtLName_TH.Text = ""
        txtMifareID.Text = ""
        pcCapture.Image = Nothing
        txtTime.Text = ""
        txtCardID.Focus()
        txtCardID.Select()
        lblImagePath.Text = ""
        cmbUserName.DataSource = Nothing
        txtPlace.Text = ""
        txtPurpose.Text = ""
        txtTime.Text = ""

        lblCardTypeName.Text = ""
        lblCardTypeID.Text = "1"
        txtCardFirstName.Text = ""
        txtCardLastName.Text = ""
        pbCardPreview.Image = Nothing
        pnlCardTypeOther.Visible = False

        cmbCardType.SelectedValue = "1"
        cmbCardType_SelectionChangeCommitted(Nothing, Nothing)

        chkNoAppointment.Checked = False
        txtUserName.Text = ""
        txtUserName.Visible = False
    End Sub

    Private Function SetStrDate(DateIn As String) As Date
        'แปลง Format วันที่จาก dd/mm/yyyy (ปี พ.ศ.) ให้อยู่ในรูป yyyy-MM-dd เพื่อทำการ Insert ลง DB
        Dim ret As New Date()
        If DateIn.Length = 10 Then
            Dim tmpDate() As String = Split(DateIn, "/")
            Dim yy As Integer = Convert.ToInt32(tmpDate(2)) - 543
            Dim mm As Integer = tmpDate(1)
            Dim dd As Integer = tmpDate(0)

            ret = New Date(yy, mm, dd)
        Else
            ret = New Date(1, 1, 1)
        End If

        Return ret
    End Function

    Private Function SaveVisitor() As Long
        Dim ret As Long = 0

        Try
            Dim lnq As New LinqDB.TABLE.TsVisitorLinqDB
            lnq.ID_CARDNO = txtCardID.Text.Trim
            lnq.MS_CARD_TYPE_ID = cmbCardType.SelectedValue
            If cmbCardType.SelectedValue = "1" Then
                'กรณีอ่านข้อมูลจากบัตรประชาชน
                lnq.FIRST_NAME_TH = txtFName_TH.Text.Trim
                lnq.LAST_NAME_TH = txtLName_TH.Text.Trim
                lnq.FIRST_NAME_EN = txtFName_EN.Text.Trim
                lnq.LAST_NAME_EN = txtLName_EN.Text.Trim
                lnq.BIRTHDATE = SetStrDate(txtBirthDate.Text)
                lnq.ISSUEDATE = SetStrDate(txtIssueDate.Text)
                lnq.ADDRESS = txtAddress.Text
                lnq.EXPDATE = SetStrDate(txtExpDate.Text)
                lnq.MIFARE_ID = txtMifareID.Text
            Else
                'กรณีใช้บัตรอื่นๆ
                lnq.FIRST_NAME_EN = txtCardFirstName.Text.Trim
                lnq.LAST_NAME_EN = txtCardLastName.Text.Trim
                lnq.CARD_PICTURE = SqlDB.SetImage(pbCardPreview.Image)
            End If

            If chkNoAppointment.Checked = True Then
                lnq.IS_APPOINTMENT = "N"
                lnq.STAFF_NAME = txtUserName.Text.Trim
            Else
                lnq.IS_APPOINTMENT = "Y"
                lnq.MS_USER_ID = cmbUserName.SelectedValue
            End If

            lnq.PLACE = txtPlace.Text
            lnq.PURPOSE = txtPurpose.Text
            lnq.IN_DATE = DateTime.Now
            lnq.ID_PICTURE = SqlDB.SetImage(pcCapture.Image)

            Dim trans As New TransactionDB
            If lnq.InsertData(UserName, trans.Trans) = True Then
                trans.CommitTransaction()
                ret = lnq.ID
                'If File.Exists(lblImagePath.Text) = True Then
                '    Try
                '        File.SetAttributes(lblImagePath.Text, FileAttributes.Normal)
                '        File.Delete(lblImagePath.Text)
                '    Catch ex As Exception

                '    End Try
                'End If
            Else
                trans.RollbackTransaction()
                ret = 0
                MessageBox.Show(lnq.ErrorMessage, "Error")
            End If
        Catch ex As Exception
            ret = 0
            MessageBox.Show(ex.Message & vbCrLf & ex.StackTrace, "Exception")
        End Try

        Return ret
    End Function

    Private Function SaveValidate() As Boolean
        If txtCardID.Text.Trim = "" Then
            MessageBox.Show("Please input Identification Number", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            txtCardID.Focus()
            Return False
        End If

        If cmbCardType.SelectedValue = "1" Then
            If txtFName_EN.Text.Trim = "" Then
                MessageBox.Show("Please input First Name", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtFName_EN.Focus()
                Return False
            End If
            If txtLName_EN.Text.Trim = "" Then
                MessageBox.Show("Please input Last Name", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtLName_EN.Focus()
                Return False
            End If

            If txtMifareID.Text.Trim = "" Then
                MessageBox.Show("Please input Barcode", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtMifareID.Focus()
                Return False
            End If
            If cmbUserName.SelectedValue = "0" Then
                MessageBox.Show("Please select name of people want to meet", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                cmbUserName.Focus()
                Return False
            End If
        Else
            If txtCardFirstName.Text.Trim = "" Then
                MessageBox.Show("Please input First Name", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtCardFirstName.Focus()
                Return False
            End If
            If txtCardLastName.Text.Trim = "" Then
                MessageBox.Show("Please input Last Name", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtCardLastName.Focus()
                Return False
            End If

            If txtCardBarcode.Text.Trim = "" Then
                MessageBox.Show("Please input Barcode", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtCardBarcode.Focus()
                Return False
            End If
            If txtUserName.Text.Trim = "" Then
                MessageBox.Show("Please input name of people want to meet", "Validate", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                txtUserName.Focus()
                Return False
            End If
        End If
        Return True
    End Function

    Private Sub btnSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSave.Click
        If SaveValidate() = False Then
            Exit Sub
        End If

        If MsgBox("ต้องการบันทึกรายการ ใช่หรือไม่!!", MsgBoxStyle.YesNo) = MsgBoxResult.Yes Then

            If SaveVisitor() > 0 Then
                ClearData()
                txtTime.Text = ""
                txtCardID.Focus()
                txtCardID.Select()


            End If
        End If

    End Sub


    'Private Sub btnLog_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    Dim frm2 As New frmLog
    '    frm2.MdiParent = Me
    '    frm2.Show()
    'End Sub

    Private Sub btnBlacklist_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnBlacklist.Click
        Try
            Dim VisitorID As Long = SaveVisitor()
            If VisitorID > 0 Then
                Dim lnq As New LinqDB.TABLE.TsBlacklistLinqDB
                lnq.TB_VISITOR_ID = VisitorID
                lnq.BLACKLIST_DATE = DateTime.Now
                lnq.BLACKLIST_REASON = "Blacklist"
                lnq.IS_BLACKLIST = "Y"

                Dim trans As New LinqDB.ConnectDB.TransactionDB
                If lnq.InsertData(UserName, trans.Trans) = True Then
                    trans.CommitTransaction()

                    MessageBox.Show("Send data to blacklist complete")
                    'มี TimerBlacklist คอยกวดไฟล์ไปเก็บไว้ที่ Path Blacklist อยู่แล้ว ตรงนี้เลยไม่จำเป็นต้องทำ
                    'Try
                    '    Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
                    '    ini.Section = "FaceRecognition"
                    '    Dim BlackListPath As String = ini.ReadString("SurveillanceSamplePath") & "TempBlackList\"
                    '    If Directory.Exists(BlackListPath) = False Then
                    '        Directory.CreateDirectory(BlackListPath)
                    '    End If

                    '    pcCapture.Image.Save(BlackListPath & txtCardID.Text & " .jpg", System.Drawing.Imaging.ImageFormat.Jpeg)

                    'Catch ex As Exception
                    '    trans.RollbackTransaction()

                    '    MessageBox.Show("Exception : btnBlacklist_Click " & ex.Message & vbCrLf & ex.StackTrace)
                    'End Try
                Else
                    trans.RollbackTransaction()
                    MessageBox.Show("btnBlacklist_Click :" & lnq.ErrorMessage)
                End If
                lnq = Nothing
            End If

            'Dim strsql As String = ""
            'strsql = "Insert Into TB_Blacklist (ID_CardNo,Create_Date,Create_By,id_picture) Values ('" & _
            '         txtCardID.Text & "',getdate(),'Admin',@ID_PICTURE)"
            'Dim objCmd As New SqlCommand(strsql, SqlDB.GetConnection)
            'If File.Exists(lblImagePath.Text) = True Then
            '    Dim ImgFile() As Byte = File.ReadAllBytes(lblImagePath.Text)
            '    Dim p As New SqlParameter("@ID_PICTURE", SqlDbType.Image, ImgFile.Length)
            '    p.Value = ImgFile
            '    objCmd.Parameters.Add(p)
            'ElseIf pcCapture.Image IsNot Nothing Then
            '    Dim imageConverter As New ImageConverter()
            '    Dim ImgFile() As Byte = DirectCast(imageConverter.ConvertTo(pcCapture.Image, GetType(Byte())), Byte())
            '    Dim p As New SqlParameter("@ID_PICTURE", SqlDbType.Image, ImgFile.Length)
            '    p.Value = ImgFile
            '    objCmd.Parameters.Add(p)
            'End If
            'If objCmd.ExecuteNonQuery() > 0 Then
            '    KeepLog(txtCardID.Text, txtLocation.Text, txtReason.Text, cmbCustName.SelectedText, "BlackList")
            'End If

            'Try
            '    Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
            '    Dim BlackListPath As String = ini.ReadString("SurveillanceSamplePath") & "\TempBlackList\"
            '    If Directory.Exists(BlackListPath) = False Then
            '        Directory.CreateDirectory(BlackListPath)
            '    End If

            '    pcCapture.Image.Save(BlackListPath & txtCardID.Text & " .jpg", System.Drawing.Imaging.ImageFormat.Jpeg)
            'Catch ex As Exception

            'End Try

            'MessageBox.Show("Send data to blacklist complete")

        Catch ex As Exception

        End Try
    End Sub

    'Private Sub SaveImageCapture(ByVal BillingNo As String)
    '    If _CaptureEnable = "Y" Then
    '        Try
    '            'Dim ConfigINI As New KioskPayment.Org.Mentalis.Files.IniReader(Application.StartupPath & "\KioskPayment.ini")
    '            'ConfigINI.Section = "CaptureImage"
    '            '======= บันทึกรูปภาพแบบปกติ =====
    '            Dim FileName As String = "Temp.jpg"
    '            Dim Path As String = GetCapturePath()
    '            Dim Path1 As String = Path & FileName
    '            pcCapture.Image.Save(Path1, System.Drawing.Imaging.ImageFormat.Jpeg)
    '            '======= บันทึกรูปภาพแบบปกติ =====

    '            '======= save convert to 300 dpi =====
    '            Dim path2 As String = GetCapturePath()
    '            Dim Resolution As String = "300"
    '            path2 = path2 & BillingNo & ".jpg"
    '            Using bitmap As Bitmap = DirectCast(Image.FromFile(Path1), Bitmap)
    '                Using newBitmap As New Bitmap(bitmap)
    '                    newBitmap.SetResolution(Resolution, Resolution)
    '                    newBitmap.Save(path2, System.Drawing.Imaging.ImageFormat.Jpeg)

    '                    imgFace = newBitmap
    '                End Using
    '            End Using

    '            If File.Exists(Path1) Then
    '                File.SetAttributes(Path1, FileAttributes.Normal)
    '                File.Delete(Path1)
    '            End If
    '            '======= save convert to 300 dpi =====
    '        Catch ex As Exception

    '        End Try
    '    End If
    'End Sub

    'Private ReadOnly Property GetCapturePath() As String
    '    Get
    '        Dim p As String = Application.StartupPath & "\CaptureImages\"
    '        If Directory.Exists(p) = False Then
    '            Directory.CreateDirectory(p)
    '        End If
    '        Return p
    '    End Get
    'End Property

    'Private ReadOnly Property GetCaptureBackupPath() As String
    '    Get
    '        Dim p As String = GetCapturePath & "Backup\"
    '        If Directory.Exists(p) = False Then
    '            Directory.CreateDirectory(p)
    '        End If
    '        Return p
    '    End Get
    'End Property

    Private Sub pcCapture_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles pcCapture.Click
        btnTakePhoto_Click(sender, e)
    End Sub

#Region "ID Card Reader"
    Private Sub WriteBoxThaiID(ByVal msg As String)
        txtCardID.Text = msg
    End Sub
    '===================================================================================================
    '         * Write text Sex 
    '         *===================================================================================================

    Private Sub WriteBoxSex(ByVal msg As String)
        'txt.Text = msg
    End Sub
    '===================================================================================================
    '         * Write text box Name Thai 
    '         *===================================================================================================

    Private Sub WriteBoxNameThai(ByVal msg As String)
        If msg = "" Then
            txtFName_TH.Text = ""
            txtLName_TH.Text = ""
        Else
            txtFName_TH.Text = msg.Split(" ")(0) & " " & msg.Split(" ")(1)
            txtLName_TH.Text = msg.Split(" ")(3)
        End If

    End Sub
    '===================================================================================================
    '         * Write text box Name English 
    '         *===================================================================================================

    Private Sub WriteBoxNameEnglish(ByVal msg As String)
        If msg = "" Then
            txtFName_EN.Text = ""
            txtLName_EN.Text = ""
        Else
            If msg.Split(" ").Length = 4 Then
                txtFName_EN.Text = msg.Split(" ")(0) & " " & msg.Split(" ")(1)
                txtLName_EN.Text = msg.Split(" ")(3)
            End If
        End If

    End Sub
    '===================================================================================================
    '         * Write text box Name English 
    '         *===================================================================================================

    Private Sub WriteBoxDateOfBirth(ByVal msg As String)
        txtBirthDate.Text = msg
    End Sub
    '===================================================================================================
    '         * Write text box Name English 
    '         *===================================================================================================

    Private Sub WriteBoxAddress(ByVal msg As String)
        txtAddress.Text = msg
    End Sub
    '===================================================================================================
    '         * Write text box Name English 
    '         *===================================================================================================

    Private Sub WriteBoxIssueDate(ByVal msg As String)
        If msg = "" Then
            txtIssueDate.Text = ""
            txtExpDate.Text = ""
        Else
            Dim TmpMsg() As String = Split(msg, Chr(13))
            If TmpMsg(0).Split("-").Length = 2 Then
                txtIssueDate.Text = TmpMsg(0).Split("-")(0)
                txtExpDate.Text = TmpMsg(0).Split("-")(1)
            End If
        End If
    End Sub
    '===================================================================================================
    '         * Write text box Name English 
    '         *===================================================================================================

    Private Sub WriteBoxIssuePlace(ByVal msg As String)
        'txt.Text = msg
    End Sub
    '===================================================================================================
    '         * Write text box Number 
    '         *===================================================================================================

    Private Sub WriteBoxNumber(ByVal msg As String)
        'textBoxNumber.Text = msg
    End Sub

    Private Sub WriteBoxMifare(msg As String)
        txtMifareID.Text = msg
    End Sub

    Private Sub WriteBoxCustomerName(msg As String)
        If msg = "" Then
            Dim dtC As New DataTable
            dtC = FunctionENG.GetDataTable("select id, customer_name from tb_prebooking")
            If dtC.Rows.Count > 0 Then
                Dim dr As DataRow = dtC.NewRow
                dr("id") = 0
                dr("customer_name") = "-----Select-----"
                dtC.Rows.InsertAt(dr, 0)


                cmbUserName.ValueMember = "id"
                cmbUserName.DisplayMember = "customer_name"
                cmbUserName.DataSource = dtC
            End If
            'dtC.Dispose()
        Else
            cmbUserName.DataSource = Nothing
        End If
    End Sub
    Private Sub WriteBoxLocation(msg As String)
        txtPlace.Text = msg
    End Sub
    Private Sub WriteBoxReason(msg As String)
        txtPurpose.Text = msg
    End Sub
    Private Sub WriteBoxTime(msg As String)
        txtTime.Text = msg
    End Sub

    Private Sub SerialPort1_DataReceived(ByVal sender As Object, ByVal e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        If SerialPort1.IsOpen Then
            Dim Len As Integer = SerialPort1.BytesToRead
            TimeOut = 1
            If Len >= 10000 Then
                Len = 0
            End If
            If BuffLength >= 10000 Then
                ' Check length data for limit  
                ' Initial Buffer length 
                BuffLength = 0
            End If
            SerialPort1.Read(BuffComPort, BuffLength, Len)
            BuffLength += Len
            If BuffLength >= 1 Then
                If Chr(BuffComPort(BuffLength - 1)) = Chr(13) AndAlso LoopRec < 9 Then

                    BuffCom = Encoding.GetEncoding(&H36A).GetString(BuffComPort, 0, BuffLength)
                    BuffLength = 0
                    SerialPort1.DiscardInBuffer()

                    If BuffCom = "REMOVE" & vbCr Then
                        LoopRec = 0
                        Me.Invoke(myUpdateBoxThaiID, "")
                        Me.Invoke(myUpdateBoxSex, "")
                        Me.Invoke(myUpdateBoxNameThai, "")
                        Me.Invoke(myUpdateBoxNameEnglish, "")
                        Me.Invoke(myUpdateBoxDateOfBirth, "")
                        Me.Invoke(myUpdateBoxAddress, "")
                        Me.Invoke(myUpdateBoxIssueDate, "")
                        Me.Invoke(myUpdateBoxIssuePlace, "")
                        Me.Invoke(myUpdateBoxNumber, "")
                        Me.Invoke(myUpdateBoxMifare, "")
                        pcCapture.Image = Nothing
                        Me.Invoke(myUpdateBoxCustomerName, "1")
                        Me.Invoke(myUpdateBoxLocation, "")
                        Me.Invoke(myUpdateBoxReason, "")
                        Me.Invoke(myUpdateBoxTime, "")


                        txtPlace.Text = ""
                        txtPurpose.Text = ""
                        txtTime.Text = ""

                    Else
                        'Try
                        '    Select Case LoopRec
                        '        Case 0
                        '            Me.Invoke(myUpdateBoxThaiID, BuffCom)
                        '        Case 1
                        '            Me.Invoke(myUpdateBoxSex, BuffCom)
                        '        Case 2
                        '            Me.Invoke(myUpdateBoxNameThai, BuffCom)
                        '        Case 3
                        '            Me.Invoke(myUpdateBoxNameEnglish, BuffCom)
                        '        Case 4
                        '            Me.Invoke(myUpdateBoxDateOfBirth, BuffCom)
                        '        Case 5
                        '            Me.Invoke(myUpdateBoxAddress, BuffCom)
                        '        Case 6
                        '            Me.Invoke(myUpdateBoxIssueDate, BuffCom)
                        '        Case 7
                        '            Me.Invoke(myUpdateBoxIssuePlace, BuffCom)
                        '        Case 8
                        '            Me.Invoke(myUpdateBoxNumber, BuffCom)
                        '    End Select
                        'Catch ex As Exception

                        'End Try

                        'DataCom(LoopRec) = BuffCom
                        DataReceive.Append(BuffCom)
                        LoopRec += 1
                    End If
                ElseIf Chr(BuffComPort(BuffLength - 1)) = Chr(13) AndAlso BuffLength >= 5120 AndAlso LoopRec = 9 Then
                    Dim TmpData As String = DataReceive.ToString
                    If TmpData.Trim <> "" Then
                        Dim TempReceive() As String = Split(TmpData, Chr(13))
                        If TempReceive.Length = 10 Then
                            Me.Invoke(myUpdateBoxThaiID, TempReceive(0))
                            Me.Invoke(myUpdateBoxSex, TempReceive(1))
                            Me.Invoke(myUpdateBoxNameThai, TempReceive(2))
                            Me.Invoke(myUpdateBoxNameEnglish, TempReceive(3))
                            Me.Invoke(myUpdateBoxDateOfBirth, TempReceive(4))
                            Me.Invoke(myUpdateBoxAddress, TempReceive(5))
                            Me.Invoke(myUpdateBoxIssueDate, TempReceive(6))
                            Me.Invoke(myUpdateBoxIssuePlace, TempReceive(7))
                            Me.Invoke(myUpdateBoxNumber, TempReceive(8))
                            Me.Invoke(myUpdateBoxCustomerName, "")
                        End If
                    End If

                    pcCapture.Image = FunctionENG.ConvertByteToImage(BuffComPort)
                    pcCapture.SizeMode = PictureBoxSizeMode.StretchImage
                    Application.DoEvents()

                    SerialPort1.DiscardInBuffer()
                    BuffLength = 0
                    LoopRec = 0
                    DataReceive.Remove(0, DataReceive.Length)

                    If txtCardID.Text.Trim = 13 Then
                        GetDescriptionData(txtCardID.Text.Trim)
                        CheckIsBlackList(txtCardID.Text.Trim)
                    End If
                End If
            End If
        End If
    End Sub
#End Region

#Region "Blacklist"


    Private Sub CheckIsBlackList(IdCardNo As String)
        Dim ret As Boolean = False
        If IdCardNo.Trim <> "" Then
            Dim sql As String = "select top 1 id from TB_Blacklist where ID_CardNo = '" & IdCardNo & "'"
            Dim dt As New DataTable
            dt = FunctionENG.GetDataTable(sql)
            If dt.Rows.Count > 0 Then
                ret = True
            End If
            dt.Dispose()
        End If

        If ret = True Then
            Dim frm As New frmPreviewNoEntry
            frm.pcCapture.Image = pcCapture.Image
            frm.pcCapture.SizeMode = PictureBoxSizeMode.StretchImage
            frm.lblName.Text = txtFName_EN.Text & " " & txtLName_EN.Text
            frm.StartPosition = FormStartPosition.CenterParent
            frm.ShowDialog()
        End If
    End Sub

    Private Sub CheckIsBlackList(CurrentPicture As Image)
        Dim frm As New frmPreviewNoEntry
        frm.pcCapture.Image = CurrentPicture
        frm.pcCapture.SizeMode = PictureBoxSizeMode.StretchImage
        frm.lblName.Text = txtFName_EN.Text & " " & txtLName_EN.Text
        frm.StartPosition = FormStartPosition.CenterParent
        frm.ShowDialog()
    End Sub
#End Region

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        If TimeOut <> 0 Then
            TimeOut += 1
            If TimeOut >= 5 Then
                If SerialPort1.IsOpen Then
                    BuffLength = 0
                    TimeOut = 0
                    LoopRec = 0
                End If
            End If
        End If
    End Sub

    Private Sub pbClose_Click(sender As Object, e As EventArgs) Handles pbClose.Click
        Application.Exit()
    End Sub

    Private Sub btnSetting_Click(sender As Object, e As EventArgs) Handles btnSetting.Click
        frmSetting.Show()
        Me.Hide()
    End Sub

    Private Sub TimerMifare_Tick(sender As Object, e As EventArgs) Handles TimerMifare.Tick
        If txtMifareID.Text.Trim = "" Then
            TimerMifare.Enabled = False
            Try
                Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
                ini.Section = "MifareReader"
                Dim port As Int16 = Convert.ToInt16(Replace(ini.ReadString("MifareComport"), "COM", ""))
                Dim bund As Int16 = Convert.ToInt16(ini.ReadString("MifareBaudRate"))

                Dim mCtl As New MifareControl
                If mCtl.Connect(port, bund) = True Then
                    Dim act As MifareControl.ActivityStatus
                    act = mCtl.SelectTag
                    If act.Available = True Then
                        txtMifareID.Text = act.Result
                    End If
                End If
                mCtl = Nothing
                ini = Nothing
            Catch ex As Exception

            End Try
            TimerMifare.Enabled = True
        End If
    End Sub

    

    Private Sub btnTakePhoto_Click(sender As Object, e As EventArgs) Handles btnTakePhoto.Click
        Try
            'คลิกปุ่มถ่ายรูป
            If txtCardID.Text.Length > 10 Then
                Dim Path As String = Application.StartupPath & "\TempCaptureImage\"
                If Directory.Exists(Path) = False Then
                    Directory.CreateDirectory(Path)
                End If

                Dim FileName As String = txtCardID.Text.Trim & ".jpg"
                Dim PathFile As String = Path & FileName
                If IO.File.Exists(PathFile) = True Then
                    Try
                        File.SetAttributes(PathFile, FileAttributes.Normal)
                        File.Delete(PathFile)

                    Catch ex As Exception

                    End Try
                End If

                Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
                Dim IDPath As String = ini.ReadString("FaceRecognition", "SurveillanceSamplePath")
                mdlFaceRecognition.WriteIDFile(IDPath, txtCardID.Text.Trim)

                Try
                    Dim imgBlackList As Image
                    pcCapture.Image = Nothing
                    imgBlackList = mdlFaceRecognition.StartFormFaceRecognition(PathFile, txtCardID.Text.Trim)
                    If imgBlackList IsNot Nothing Then
                        CheckIsBlackList(imgBlackList)
                    End If
                    If File.Exists(Path & FileName) = True Then
                        lblImagePath.Text = Path & FileName
                        Dim bipimag As New MemoryStream(File.ReadAllBytes(lblImagePath.Text))
                        Dim imag As Image = New Bitmap(bipimag)
                        pcCapture.Image = imag
                        pcCapture.SizeMode = PictureBoxSizeMode.StretchImage
                        Application.DoEvents()
                    End If
                Catch ex As Exception

                End Try
            End If

        Catch ex As Exception

        End Try
    End Sub

    Private Sub TimerBlacklist_Tick(sender As Object, e As EventArgs) Handles TimerBlacklist.Tick
        TimerBlacklist.Enabled = False

        Dim sql As String = "select v.ID_CardNo, bl.id ts_blacklist_id,v.id_picture, be.client_ip "
        sql += " from ts_blacklist bl"
        sql += " inner join ts_visitor v on v.id=bl.tb_visitor_id "
        sql += " left join ts_blacklist_enroll be on bl.id=be.ts_blacklist_id"
        sql += " where  be.id is null "
        sql += " and isnull(be.client_ip,'" & ClientIP & "')='" & ClientIP & "'"
        Dim dt As New DataTable
        dt = FunctionENG.GetDataTable(sql)

        If dt.Rows.Count > 0 Then
            For Each dr As DataRow In dt.Rows
                If Convert.IsDBNull(dr("id_picture")) = False Then
                    Try
                        Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
                        Dim TempEnrollImagePath As String = ini.ReadString("FaceRecognition", "SurveillanceSamplePath") & "TempEnrollImage\"
                        If Directory.Exists(TempEnrollImagePath) = False Then
                            Directory.CreateDirectory(TempEnrollImagePath)
                        End If
                        ini = Nothing

                        Dim lb() As Byte = dr("id_picture")
                        Dim lstr As New System.IO.MemoryStream(lb)

                        Dim img As Image = Image.FromStream(lstr)
                        img.Save(TempEnrollImagePath & dr("ID_CardNo").ToString.Trim & " .jpg", System.Drawing.Imaging.ImageFormat.Jpeg)

                        Dim lnq As New LinqDB.TABLE.TsBlacklistEnrollLinqDB
                        lnq.TS_BLACKLIST_ID = Convert.ToInt64(dr("ts_blacklist_id"))
                        lnq.CLIENT_IP = ClientIP
                        lnq.BLACKLIST_PATH = TempEnrollImagePath & dr("ID_CardNo").ToString.Trim & " .jpg"

                        Dim trans As New LinqDB.ConnectDB.TransactionDB
                        If lnq.InsertData(UserName, trans.Trans) = True Then
                            trans.CommitTransaction()
                        Else
                            trans.RollbackTransaction()
                        End If
                    Catch ex As Exception

                    End Try
                End If
            Next
        End If
        dt.Dispose()

        Try
            Dim sql2 As String = "select COUNT(id) as cnt From Ts_Blacklist where is_blacklist='Y'"
            Dim dtable As New DataTable
            dtable = FunctionENG.GetDataTable(sql2)
            If dtable.Rows.Count > 0 Then
                If TmpCntBlacklist <> dtable.Rows(0).Item(0).ToString() Then
                    Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
                    Dim PathCnt As String = ini.ReadString("FaceRecognition", "SurveillanceSamplePath")
                    WriteCntFile(PathCnt, dtable.Rows(0).Item(0).ToString())
                    TmpCntBlacklist = dtable.Rows(0).Item(0).ToString()
                End If
            End If
            dtable.Dispose()
        Catch ex As Exception

        End Try

        TimerBlacklist.Enabled = True
    End Sub

    Private Sub cmbCardType_SelectionChangeCommitted(sender As Object, e As EventArgs) Handles cmbCardType.SelectionChangeCommitted
        If cmbCardType.SelectedValue = "1" Then
            pnlCardTypeOther.Visible = False
            OpenIDCardSerialPort()
        Else
            pnlCardTypeOther.Visible = True
            lblCardTypeName.Text = cmbCardType.Text
            SerialPort1.Close()
        End If
        _CardType = cmbCardType.SelectedValue
    End Sub

    Private Sub btnCardCapture_Click(sender As Object, e As EventArgs) Handles btnCardCapture.Click
        pbCardPreview.Image = Nothing

        Dim frm As New frmCardCapture
        frm.lblCardTypeID.Text = cmbCardType.SelectedValue
        frm.lblCardTypeName.Text = cmbCardType.Text
        If frm.ShowDialog = Windows.Forms.DialogResult.OK Then
            txtCardID.Text = frm.txtCardID.Text
            txtCardFirstName.Text = frm.txtFirstName.Text
            txtCardLastName.Text = frm.txtLastName.Text
            pbCardPreview.Image = Image.FromFile(frm.lblImagePath.Text)
            pbCardPreview.SizeMode = PictureBoxSizeMode.StretchImage

            If txtCardID.Text.Length >= 10 Then
                GetDescriptionData(txtCardID.Text.Trim)

                CheckIsBlackList(txtCardID.Text)
            End If
        End If
    End Sub

    Private Sub GetDescriptionData(vCardID As String)
        Try
            Dim sql As String = "select u.id, isnull(u.name_eng,u.name_thai) staff_name,"
            sql += " mr.room_name, p.purpose, "
            sql += " convert(varchar(5),p.start_time,114) + '-' + convert(varchar(5),p.end_time,114) app_time"
            sql += " from TS_PREBOOKING p"
            sql += " inner join MS_USER u on u.id=p.ms_user_id_booking"
            sql += " inner join TS_PREBOOKING_VISITOR pv on p.id= pv.ts_prebooking_id"
            sql += " inner join MS_MEETING_ROOM mr on mr.id=p.ms_meeting_room_id"
            sql += " where DATEDIFF(day,p.use_date,getdate())=0"
            sql += " and pv.id_cardno='" & vCardID & "'"
            Dim dt As New DataTable
            dt = FunctionENG.GetDataTable(sql)
            If dt.Rows.Count > 0 Then
                Dim uDt As New DataTable
                uDt.Columns.Add("id")
                uDt.Columns.Add("staff_name")

                If dt.Rows.Count = 1 Then
                    Dim dr As DataRow = dt.Rows(0)
                    txtPlace.Text = dr("room_name")
                    txtPurpose.Text = dr("purpose")
                    txtTime.Text = dr("app_time")
                End If

                For Each dr As DataRow In dt.Rows
                    Dim uDr As DataRow = uDt.NewRow
                    uDr("id") = dr("id")
                    uDr("staff_name") = dr("staff_name")
                    uDt.Rows.Add(uDr)
                Next
                If uDt.Rows.Count > 1 Then
                    Dim uDr As DataRow = uDt.NewRow
                    uDr("id") = 0
                    uDr("staff_name") = "------Select-----"
                    uDt.Rows.InsertAt(uDr, 0)
                End If

                cmbUserName.DisplayMember = "staff_name"
                cmbUserName.ValueMember = "id"
                cmbUserName.DataSource = uDt
                chkNoAppointment.Checked = False
                txtUserName.Visible = False
            Else
                chkNoAppointment.Checked = True
                txtUserName.Visible = True
            End If
            dt.Dispose()
        Catch ex As Exception

        End Try
    End Sub

    Private Sub cmbUserName_SelectionChangeCommitted(sender As Object, e As EventArgs) Handles cmbUserName.SelectionChangeCommitted
        If cmbUserName.SelectedValue <> "0" Then
            Try
                Dim sql As String = "select u.id, isnull(u.name_eng,u.name_thai) staff_name,"
                sql += " mr.room_name, p.purpose, "
                sql += " convert(varchar(5),p.start_time,114) + '-' + convert(varchar(5),p.end_time,114) app_time"
                sql += " from TS_PREBOOKING p"
                sql += " inner join MS_USER u on u.id=p.ms_user_id_booking"
                sql += " inner join TS_PREBOOKING_VISITOR pv on p.id= pv.ts_prebooking_id"
                sql += " inner join MS_MEETING_ROOM mr on mr.id=p.ms_meeting_room_id"
                sql += " where DATEDIFF(day,p.use_date,getdate())=0"
                sql += " and u.id='" & cmbUserName.SelectedValue & "'"
                sql += " and pv.id_cardno='" & txtCardID.Text.Trim & "'"

                Dim dt As New DataTable
                dt = FunctionENG.GetDataTable(sql)
                If dt.Rows.Count > 0 Then
                    Dim dr As DataRow = dt.Rows(0)
                    txtPlace.Text = dr("room_name")
                    txtPurpose.Text = dr("purpose")
                    txtTime.Text = dr("app_time")
                End If
                dt.Dispose()
            Catch ex As Exception

            End Try
        End If
    End Sub

    Private Sub txtCardID_KeyPress(sender As Object, e As KeyPressEventArgs) Handles txtCardID.KeyPress
        If e.KeyChar() = Chr(13) Then
            GetDescriptionData(txtCardID.Text.Trim)
        End If
    End Sub

    Private Sub btnReturn_Click(sender As Object, e As EventArgs) Handles btnReturn.Click
        Me.Hide()
        frmReturnCard.Show()
    End Sub

    Private Sub frmRegister_VisibleChanged(sender As Object, e As EventArgs) Handles Me.VisibleChanged
        If Me.Visible = True Then
            If ConnectComportSerialBarcodeReader() = True Then
                EnableSerialBarcodeReader()
            End If
        Else
            DisableSerialBarcodeReader()
            DisconnectComportSerialBarcodeReader()
        End If
    End Sub

#Region "Serial Port Barcode Reader"
    Dim _msg As String
    Dim data As String

    Private Function ConnectComportSerialBarcodeReader() As Boolean
        Dim ret As Boolean = False
        Try
            Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
            ini.Section = "BarcodeReader"
            SerialBarcodeReader.PortName = ini.ReadString("BarcodeComport")
            SerialBarcodeReader.BaudRate = ini.ReadString("BarcodeBaudRate")

            If Not SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Open()
            ret = True

            ini = Nothing
        Catch ex As Exception
            ret = False
            'MessageBox.Show("Exception : ConnectComportSerialBarcodeReader :" & ex.Message & ex.StackTrace)
        End Try
        Return ret
    End Function
    Private Function DisconnectComportSerialBarcodeReader() As Boolean
        Try
            If SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Close()
            Return True
        Catch ex As Exception
            Return False
        End Try
    End Function

    Private Sub EnableSerialBarcodeReader()
        Try
            If Not SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Open()
            Dim bb(1) As Byte
            bb(0) = &HA0
            SerialBarcodeReader.Write(bb, 0, 1)
        Catch ex As Exception
            'MessageBox.Show("Exception : EnableSerialBarcodeReader :" & ex.Message & ex.StackTrace)
        End Try
        
    End Sub

    Private Sub DisableSerialBarcodeReader()
        Try
            If Not SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Open()
            Dim bb(1) As Byte
            bb(0) = &H55
            SerialBarcodeReader.Write(bb, 0, 1)
        Catch ex As Exception

        End Try
    End Sub

    Private Sub SerialBarcodeReader_DataReceived(sender As Object, e As Ports.SerialDataReceivedEventArgs) Handles SerialBarcodeReader.DataReceived
        'determine the mode the user selected (binary/string)

        'user chose binary
        'retrieve number of bytes in the buffer
        Dim bytes As Integer = SerialBarcodeReader.BytesToRead
        'create a byte array to hold the awaiting data
        Dim comBuffer As Byte() = New Byte(bytes - 1) {}
        'read the data and store it
        SerialBarcodeReader.Read(comBuffer, 0, bytes)
        Data = Encoding.ASCII.GetString(comBuffer)

        'display the data to the user
        _msg = ByteToHex(comBuffer) + "" + Environment.NewLine + ""
        DisplayData(ByteToHex(comBuffer) + "" + Environment.NewLine + "")
    End Sub

    Private Function ByteToHex(ByVal comByte As Byte()) As String
        'create a new StringBuilder object
        Dim builder As New StringBuilder(comByte.Length * 3)
        'loop through each byte in the array
        For Each data As Byte In comByte
            builder.Append(Convert.ToString(data, 16).PadLeft(2, "0"c).PadRight(3, " "c))
            'convert the byte to a string and add to the stringbuilder
        Next
        'return the converted value
        Return builder.ToString().ToUpper()
    End Function

    Dim _CardType As String = "1"

    Private Sub DoDisplay(ByVal sender As Object, ByVal e As EventArgs)
        If _CardType = "1" Then
            txtMifareID.SelectedText = String.Empty
            txtMifareID.Text = Replace(data, "*", "")
            txtMifareID.ScrollToCaret()
        Else
            txtCardBarcode.SelectedText = String.Empty
            txtCardBarcode.Text = Replace(data, "*", "")
            txtCardBarcode.ScrollToCaret()
        End If
       
        'If txtMifareID.Text <> "" Then CheckBarcode() Else txtMifareID.Text = ""
    End Sub
    Private Sub DisplayData(ByVal msg As String)
        Try
            If _CardType = "1" Then
                txtMifareID.Invoke(New EventHandler(AddressOf DoDisplay))
            Else
                txtCardBarcode.Invoke(New EventHandler(AddressOf DoDisplay))
            End If
        Catch ex As Exception

        End Try
    End Sub
#End Region



End Class
