<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmRegister
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmRegister))
        Me.txtPurpose = New System.Windows.Forms.TextBox()
        Me.txtTime = New System.Windows.Forms.TextBox()
        Me.txtPlace = New System.Windows.Forms.TextBox()
        Me.txtMifareID = New System.Windows.Forms.TextBox()
        Me.txtExpDate = New System.Windows.Forms.TextBox()
        Me.txtAddress = New System.Windows.Forms.TextBox()
        Me.txtIssueDate = New System.Windows.Forms.TextBox()
        Me.txtBirthDate = New System.Windows.Forms.TextBox()
        Me.txtLName_EN = New System.Windows.Forms.TextBox()
        Me.txtLName_TH = New System.Windows.Forms.TextBox()
        Me.txtFName_EN = New System.Windows.Forms.TextBox()
        Me.txtFName_TH = New System.Windows.Forms.TextBox()
        Me.txtCardID = New System.Windows.Forms.TextBox()
        Me.btnBlacklist = New System.Windows.Forms.Button()
        Me.btnCancel = New System.Windows.Forms.Button()
        Me.btnSave = New System.Windows.Forms.Button()
        Me.pcCapture = New System.Windows.Forms.PictureBox()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.pbClose = New System.Windows.Forms.PictureBox()
        Me.btnSetting = New System.Windows.Forms.Button()
        Me.TimerMifare = New System.Windows.Forms.Timer(Me.components)
        Me.lblImagePath = New System.Windows.Forms.Label()
        Me.cmbUserName = New System.Windows.Forms.ComboBox()
        Me.btnTakePhoto = New System.Windows.Forms.Button()
        Me.TimerBlacklist = New System.Windows.Forms.Timer(Me.components)
        Me.pnlCardTypeOther = New System.Windows.Forms.Panel()
        Me.txtCardBarcode = New System.Windows.Forms.TextBox()
        Me.lblCardTypeName = New System.Windows.Forms.Label()
        Me.txtCardLastName = New System.Windows.Forms.TextBox()
        Me.txtCardFirstName = New System.Windows.Forms.TextBox()
        Me.cmbCardType = New System.Windows.Forms.ComboBox()
        Me.chkNoAppointment = New System.Windows.Forms.CheckBox()
        Me.txtUserName = New System.Windows.Forms.TextBox()
        Me.btnReturn = New System.Windows.Forms.Button()
        Me.SerialBarcodeReader = New System.IO.Ports.SerialPort(Me.components)
        Me.pbCardPreview = New System.Windows.Forms.PictureBox()
        Me.btnCardCapture = New System.Windows.Forms.Button()
        Me.lblCardTypeID = New System.Windows.Forms.Label()
        CType(Me.pcCapture, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbClose, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.pnlCardTypeOther.SuspendLayout()
        CType(Me.pbCardPreview, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'txtPurpose
        '
        Me.txtPurpose.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtPurpose.Location = New System.Drawing.Point(321, 616)
        Me.txtPurpose.Multiline = True
        Me.txtPurpose.Name = "txtPurpose"
        Me.txtPurpose.Size = New System.Drawing.Size(350, 49)
        Me.txtPurpose.TabIndex = 14
        '
        'txtTime
        '
        Me.txtTime.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtTime.Location = New System.Drawing.Point(778, 594)
        Me.txtTime.Name = "txtTime"
        Me.txtTime.Size = New System.Drawing.Size(176, 26)
        Me.txtTime.TabIndex = 13
        '
        'txtPlace
        '
        Me.txtPlace.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtPlace.Location = New System.Drawing.Point(778, 538)
        Me.txtPlace.Name = "txtPlace"
        Me.txtPlace.Size = New System.Drawing.Size(179, 26)
        Me.txtPlace.TabIndex = 12
        '
        'txtMifareID
        '
        Me.txtMifareID.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtMifareID.Location = New System.Drawing.Point(637, 429)
        Me.txtMifareID.Name = "txtMifareID"
        Me.txtMifareID.Size = New System.Drawing.Size(250, 26)
        Me.txtMifareID.TabIndex = 10
        '
        'txtExpDate
        '
        Me.txtExpDate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtExpDate.Location = New System.Drawing.Point(740, 353)
        Me.txtExpDate.Name = "txtExpDate"
        Me.txtExpDate.Size = New System.Drawing.Size(176, 26)
        Me.txtExpDate.TabIndex = 9
        '
        'txtAddress
        '
        Me.txtAddress.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtAddress.Location = New System.Drawing.Point(403, 353)
        Me.txtAddress.Multiline = True
        Me.txtAddress.Name = "txtAddress"
        Me.txtAddress.Size = New System.Drawing.Size(195, 76)
        Me.txtAddress.TabIndex = 8
        '
        'txtIssueDate
        '
        Me.txtIssueDate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtIssueDate.Location = New System.Drawing.Point(740, 291)
        Me.txtIssueDate.Name = "txtIssueDate"
        Me.txtIssueDate.Size = New System.Drawing.Size(176, 26)
        Me.txtIssueDate.TabIndex = 7
        '
        'txtBirthDate
        '
        Me.txtBirthDate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtBirthDate.Location = New System.Drawing.Point(403, 291)
        Me.txtBirthDate.Name = "txtBirthDate"
        Me.txtBirthDate.Size = New System.Drawing.Size(195, 26)
        Me.txtBirthDate.TabIndex = 6
        '
        'txtLName_EN
        '
        Me.txtLName_EN.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtLName_EN.Location = New System.Drawing.Point(740, 215)
        Me.txtLName_EN.Name = "txtLName_EN"
        Me.txtLName_EN.Size = New System.Drawing.Size(179, 26)
        Me.txtLName_EN.TabIndex = 5
        '
        'txtLName_TH
        '
        Me.txtLName_TH.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtLName_TH.Location = New System.Drawing.Point(740, 244)
        Me.txtLName_TH.Name = "txtLName_TH"
        Me.txtLName_TH.Size = New System.Drawing.Size(179, 26)
        Me.txtLName_TH.TabIndex = 3
        '
        'txtFName_EN
        '
        Me.txtFName_EN.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtFName_EN.Location = New System.Drawing.Point(403, 215)
        Me.txtFName_EN.Name = "txtFName_EN"
        Me.txtFName_EN.Size = New System.Drawing.Size(195, 26)
        Me.txtFName_EN.TabIndex = 4
        '
        'txtFName_TH
        '
        Me.txtFName_TH.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtFName_TH.Location = New System.Drawing.Point(403, 244)
        Me.txtFName_TH.Name = "txtFName_TH"
        Me.txtFName_TH.Size = New System.Drawing.Size(195, 26)
        Me.txtFName_TH.TabIndex = 2
        '
        'txtCardID
        '
        Me.txtCardID.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtCardID.Location = New System.Drawing.Point(615, 153)
        Me.txtCardID.Name = "txtCardID"
        Me.txtCardID.Size = New System.Drawing.Size(232, 26)
        Me.txtCardID.TabIndex = 1
        '
        'btnBlacklist
        '
        Me.btnBlacklist.BackgroundImage = CType(resources.GetObject("btnBlacklist.BackgroundImage"), System.Drawing.Image)
        Me.btnBlacklist.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnBlacklist.Location = New System.Drawing.Point(51, 582)
        Me.btnBlacklist.Name = "btnBlacklist"
        Me.btnBlacklist.Size = New System.Drawing.Size(229, 39)
        Me.btnBlacklist.TabIndex = 21
        Me.btnBlacklist.UseVisualStyleBackColor = True
        '
        'btnCancel
        '
        Me.btnCancel.BackgroundImage = CType(resources.GetObject("btnCancel.BackgroundImage"), System.Drawing.Image)
        Me.btnCancel.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCancel.Location = New System.Drawing.Point(168, 541)
        Me.btnCancel.Name = "btnCancel"
        Me.btnCancel.Size = New System.Drawing.Size(111, 39)
        Me.btnCancel.TabIndex = 20
        Me.btnCancel.UseVisualStyleBackColor = True
        '
        'btnSave
        '
        Me.btnSave.BackgroundImage = CType(resources.GetObject("btnSave.BackgroundImage"), System.Drawing.Image)
        Me.btnSave.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSave.Location = New System.Drawing.Point(51, 541)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(111, 39)
        Me.btnSave.TabIndex = 23
        Me.btnSave.UseVisualStyleBackColor = True
        '
        'pcCapture
        '
        Me.pcCapture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.pcCapture.Location = New System.Drawing.Point(51, 183)
        Me.pcCapture.Name = "pcCapture"
        Me.pcCapture.Size = New System.Drawing.Size(228, 298)
        Me.pcCapture.TabIndex = 0
        Me.pcCapture.TabStop = False
        '
        'SerialPort1
        '
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 50
        '
        'pbClose
        '
        Me.pbClose.BackColor = System.Drawing.Color.Transparent
        Me.pbClose.Location = New System.Drawing.Point(967, 2)
        Me.pbClose.Name = "pbClose"
        Me.pbClose.Size = New System.Drawing.Size(40, 37)
        Me.pbClose.TabIndex = 24
        Me.pbClose.TabStop = False
        '
        'btnSetting
        '
        Me.btnSetting.BackgroundImage = Global.VRM.My.Resources.Resources.Untitled_4
        Me.btnSetting.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSetting.Location = New System.Drawing.Point(703, 0)
        Me.btnSetting.Name = "btnSetting"
        Me.btnSetting.Size = New System.Drawing.Size(111, 39)
        Me.btnSetting.TabIndex = 25
        Me.btnSetting.UseVisualStyleBackColor = True
        '
        'TimerMifare
        '
        Me.TimerMifare.Enabled = True
        Me.TimerMifare.Interval = 500
        '
        'lblImagePath
        '
        Me.lblImagePath.AutoSize = True
        Me.lblImagePath.Location = New System.Drawing.Point(48, 522)
        Me.lblImagePath.Name = "lblImagePath"
        Me.lblImagePath.Size = New System.Drawing.Size(0, 13)
        Me.lblImagePath.TabIndex = 26
        Me.lblImagePath.Visible = False
        '
        'cmbUserName
        '
        Me.cmbUserName.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbUserName.FormattingEnabled = True
        Me.cmbUserName.Location = New System.Drawing.Point(462, 543)
        Me.cmbUserName.Name = "cmbUserName"
        Me.cmbUserName.Size = New System.Drawing.Size(209, 21)
        Me.cmbUserName.TabIndex = 29
        '
        'btnTakePhoto
        '
        Me.btnTakePhoto.BackgroundImage = CType(resources.GetObject("btnTakePhoto.BackgroundImage"), System.Drawing.Image)
        Me.btnTakePhoto.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnTakePhoto.Location = New System.Drawing.Point(108, 487)
        Me.btnTakePhoto.Name = "btnTakePhoto"
        Me.btnTakePhoto.Size = New System.Drawing.Size(111, 39)
        Me.btnTakePhoto.TabIndex = 30
        Me.btnTakePhoto.UseVisualStyleBackColor = True
        '
        'TimerBlacklist
        '
        Me.TimerBlacklist.Enabled = True
        Me.TimerBlacklist.Interval = 2000
        '
        'pnlCardTypeOther
        '
        Me.pnlCardTypeOther.BackgroundImage = CType(resources.GetObject("pnlCardTypeOther.BackgroundImage"), System.Drawing.Image)
        Me.pnlCardTypeOther.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.pnlCardTypeOther.Controls.Add(Me.lblCardTypeID)
        Me.pnlCardTypeOther.Controls.Add(Me.txtCardBarcode)
        Me.pnlCardTypeOther.Controls.Add(Me.btnCardCapture)
        Me.pnlCardTypeOther.Controls.Add(Me.pbCardPreview)
        Me.pnlCardTypeOther.Controls.Add(Me.lblCardTypeName)
        Me.pnlCardTypeOther.Controls.Add(Me.txtCardFirstName)
        Me.pnlCardTypeOther.Controls.Add(Me.txtCardLastName)
        Me.pnlCardTypeOther.Location = New System.Drawing.Point(302, 183)
        Me.pnlCardTypeOther.Name = "pnlCardTypeOther"
        Me.pnlCardTypeOther.Size = New System.Drawing.Size(655, 288)
        Me.pnlCardTypeOther.TabIndex = 31
        Me.pnlCardTypeOther.Visible = False
        '
        'txtCardBarcode
        '
        Me.txtCardBarcode.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtCardBarcode.Location = New System.Drawing.Point(437, 217)
        Me.txtCardBarcode.Name = "txtCardBarcode"
        Me.txtCardBarcode.Size = New System.Drawing.Size(203, 26)
        Me.txtCardBarcode.TabIndex = 50
        '
        'lblCardTypeName
        '
        Me.lblCardTypeName.AutoSize = True
        Me.lblCardTypeName.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.lblCardTypeName.Location = New System.Drawing.Point(431, 71)
        Me.lblCardTypeName.Name = "lblCardTypeName"
        Me.lblCardTypeName.Size = New System.Drawing.Size(81, 20)
        Me.lblCardTypeName.TabIndex = 47
        Me.lblCardTypeName.Text = "Card Type"
        '
        'txtCardLastName
        '
        Me.txtCardLastName.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtCardLastName.Location = New System.Drawing.Point(437, 169)
        Me.txtCardLastName.Name = "txtCardLastName"
        Me.txtCardLastName.Size = New System.Drawing.Size(203, 26)
        Me.txtCardLastName.TabIndex = 45
        '
        'txtCardFirstName
        '
        Me.txtCardFirstName.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtCardFirstName.Location = New System.Drawing.Point(437, 118)
        Me.txtCardFirstName.Name = "txtCardFirstName"
        Me.txtCardFirstName.Size = New System.Drawing.Size(203, 26)
        Me.txtCardFirstName.TabIndex = 43
        '
        'cmbCardType
        '
        Me.cmbCardType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbCardType.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.cmbCardType.FormattingEnabled = True
        Me.cmbCardType.Location = New System.Drawing.Point(670, 98)
        Me.cmbCardType.Name = "cmbCardType"
        Me.cmbCardType.Size = New System.Drawing.Size(195, 28)
        Me.cmbCardType.TabIndex = 32
        '
        'chkNoAppointment
        '
        Me.chkNoAppointment.AutoSize = True
        Me.chkNoAppointment.BackColor = System.Drawing.Color.Transparent
        Me.chkNoAppointment.Enabled = False
        Me.chkNoAppointment.Location = New System.Drawing.Point(462, 520)
        Me.chkNoAppointment.Name = "chkNoAppointment"
        Me.chkNoAppointment.Size = New System.Drawing.Size(102, 17)
        Me.chkNoAppointment.TabIndex = 34
        Me.chkNoAppointment.Text = "No Appointment"
        Me.chkNoAppointment.UseVisualStyleBackColor = False
        '
        'txtUserName
        '
        Me.txtUserName.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtUserName.Location = New System.Drawing.Point(462, 543)
        Me.txtUserName.Name = "txtUserName"
        Me.txtUserName.Size = New System.Drawing.Size(209, 26)
        Me.txtUserName.TabIndex = 35
        Me.txtUserName.Visible = False
        '
        'btnReturn
        '
        Me.btnReturn.BackgroundImage = CType(resources.GetObject("btnReturn.BackgroundImage"), System.Drawing.Image)
        Me.btnReturn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnReturn.Location = New System.Drawing.Point(575, 2)
        Me.btnReturn.Name = "btnReturn"
        Me.btnReturn.Size = New System.Drawing.Size(111, 39)
        Me.btnReturn.TabIndex = 36
        Me.btnReturn.UseVisualStyleBackColor = True
        '
        'SerialBarcodeReader
        '
        Me.SerialBarcodeReader.Handshake = System.IO.Ports.Handshake.XOnXOff
        Me.SerialBarcodeReader.PortName = "COM9"
        '
        'pbCardPreview
        '
        Me.pbCardPreview.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.pbCardPreview.Location = New System.Drawing.Point(0, 3)
        Me.pbCardPreview.Name = "pbCardPreview"
        Me.pbCardPreview.Size = New System.Drawing.Size(324, 240)
        Me.pbCardPreview.TabIndex = 28
        Me.pbCardPreview.TabStop = False
        '
        'btnCardCapture
        '
        Me.btnCardCapture.BackgroundImage = CType(resources.GetObject("btnCardCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnCardCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCardCapture.Location = New System.Drawing.Point(103, 246)
        Me.btnCardCapture.Name = "btnCardCapture"
        Me.btnCardCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnCardCapture.TabIndex = 30
        Me.btnCardCapture.UseVisualStyleBackColor = True
        '
        'lblCardTypeID
        '
        Me.lblCardTypeID.AutoSize = True
        Me.lblCardTypeID.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.lblCardTypeID.Location = New System.Drawing.Point(413, 38)
        Me.lblCardTypeID.Name = "lblCardTypeID"
        Me.lblCardTypeID.Size = New System.Drawing.Size(0, 20)
        Me.lblCardTypeID.TabIndex = 51
        Me.lblCardTypeID.Visible = False
        '
        'frmRegister
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.ClientSize = New System.Drawing.Size(1008, 729)
        Me.Controls.Add(Me.btnReturn)
        Me.Controls.Add(Me.txtUserName)
        Me.Controls.Add(Me.chkNoAppointment)
        Me.Controls.Add(Me.cmbCardType)
        Me.Controls.Add(Me.pnlCardTypeOther)
        Me.Controls.Add(Me.btnTakePhoto)
        Me.Controls.Add(Me.cmbUserName)
        Me.Controls.Add(Me.lblImagePath)
        Me.Controls.Add(Me.btnSetting)
        Me.Controls.Add(Me.pbClose)
        Me.Controls.Add(Me.txtPlace)
        Me.Controls.Add(Me.txtTime)
        Me.Controls.Add(Me.txtPurpose)
        Me.Controls.Add(Me.txtMifareID)
        Me.Controls.Add(Me.txtAddress)
        Me.Controls.Add(Me.txtExpDate)
        Me.Controls.Add(Me.txtIssueDate)
        Me.Controls.Add(Me.pcCapture)
        Me.Controls.Add(Me.txtBirthDate)
        Me.Controls.Add(Me.btnSave)
        Me.Controls.Add(Me.txtLName_EN)
        Me.Controls.Add(Me.btnCancel)
        Me.Controls.Add(Me.txtLName_TH)
        Me.Controls.Add(Me.btnBlacklist)
        Me.Controls.Add(Me.txtFName_EN)
        Me.Controls.Add(Me.txtCardID)
        Me.Controls.Add(Me.txtFName_TH)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "frmRegister"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Registration"
        CType(Me.pcCapture, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbClose, System.ComponentModel.ISupportInitialize).EndInit()
        Me.pnlCardTypeOther.ResumeLayout(False)
        Me.pnlCardTypeOther.PerformLayout()
        CType(Me.pbCardPreview, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnBlacklist As System.Windows.Forms.Button
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Friend WithEvents pcCapture As System.Windows.Forms.PictureBox
    Friend WithEvents txtExpDate As System.Windows.Forms.TextBox
    Friend WithEvents txtAddress As System.Windows.Forms.TextBox
    Friend WithEvents txtIssueDate As System.Windows.Forms.TextBox
    Friend WithEvents txtBirthDate As System.Windows.Forms.TextBox
    Friend WithEvents txtLName_EN As System.Windows.Forms.TextBox
    Friend WithEvents txtLName_TH As System.Windows.Forms.TextBox
    Friend WithEvents txtFName_EN As System.Windows.Forms.TextBox
    Friend WithEvents txtFName_TH As System.Windows.Forms.TextBox
    Friend WithEvents txtCardID As System.Windows.Forms.TextBox
    Friend WithEvents txtPurpose As System.Windows.Forms.TextBox
    Friend WithEvents txtTime As System.Windows.Forms.TextBox
    Friend WithEvents txtPlace As System.Windows.Forms.TextBox
    Friend WithEvents txtMifareID As System.Windows.Forms.TextBox
    Friend WithEvents SerialPort1 As System.IO.Ports.SerialPort
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents pbClose As System.Windows.Forms.PictureBox
    Friend WithEvents btnSetting As System.Windows.Forms.Button
    Friend WithEvents TimerMifare As System.Windows.Forms.Timer
    Friend WithEvents lblImagePath As System.Windows.Forms.Label
    Friend WithEvents cmbUserName As System.Windows.Forms.ComboBox
    Friend WithEvents btnTakePhoto As System.Windows.Forms.Button
    Friend WithEvents TimerBlacklist As System.Windows.Forms.Timer
    Public WithEvents btnCancel As System.Windows.Forms.Button
    Friend WithEvents pnlCardTypeOther As System.Windows.Forms.Panel
    Friend WithEvents cmbCardType As System.Windows.Forms.ComboBox
    Friend WithEvents lblCardTypeName As System.Windows.Forms.Label
    Friend WithEvents txtCardLastName As System.Windows.Forms.TextBox
    Friend WithEvents txtCardFirstName As System.Windows.Forms.TextBox
    Friend WithEvents chkNoAppointment As System.Windows.Forms.CheckBox
    Friend WithEvents txtUserName As System.Windows.Forms.TextBox
    Friend WithEvents txtCardBarcode As System.Windows.Forms.TextBox
    Friend WithEvents btnReturn As System.Windows.Forms.Button
    Friend WithEvents SerialBarcodeReader As System.IO.Ports.SerialPort
    Friend WithEvents btnCardCapture As System.Windows.Forms.Button
    Friend WithEvents pbCardPreview As System.Windows.Forms.PictureBox
    Friend WithEvents lblCardTypeID As System.Windows.Forms.Label

End Class
