<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmReturnCard
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmReturnCard))
        Me.btnRegister = New System.Windows.Forms.Button()
        Me.pcPicture = New System.Windows.Forms.PictureBox()
        Me.txtAddress = New System.Windows.Forms.TextBox()
        Me.txtExpDate = New System.Windows.Forms.TextBox()
        Me.txtIssueDate = New System.Windows.Forms.TextBox()
        Me.txtBirthDate = New System.Windows.Forms.TextBox()
        Me.txtLName_EN = New System.Windows.Forms.TextBox()
        Me.txtFName_EN = New System.Windows.Forms.TextBox()
        Me.txtBarcode = New System.Windows.Forms.TextBox()
        Me.txtCardTypeName = New System.Windows.Forms.TextBox()
        Me.btnSave = New System.Windows.Forms.Button()
        Me.btnCancel = New System.Windows.Forms.Button()
        Me.lblVisitorID = New System.Windows.Forms.Label()
        Me.SerialBarcodeReader = New System.IO.Ports.SerialPort(Me.components)
        CType(Me.pcPicture, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'btnRegister
        '
        Me.btnRegister.BackgroundImage = Global.VRM.My.Resources.Resources.Untitled_1
        Me.btnRegister.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnRegister.Location = New System.Drawing.Point(469, 82)
        Me.btnRegister.Name = "btnRegister"
        Me.btnRegister.Size = New System.Drawing.Size(209, 45)
        Me.btnRegister.TabIndex = 37
        Me.btnRegister.UseVisualStyleBackColor = True
        '
        'pcPicture
        '
        Me.pcPicture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.pcPicture.Location = New System.Drawing.Point(51, 183)
        Me.pcPicture.Name = "pcPicture"
        Me.pcPicture.Size = New System.Drawing.Size(228, 298)
        Me.pcPicture.TabIndex = 38
        Me.pcPicture.TabStop = False
        '
        'txtAddress
        '
        Me.txtAddress.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.txtAddress.Enabled = False
        Me.txtAddress.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtAddress.Location = New System.Drawing.Point(419, 425)
        Me.txtAddress.Multiline = True
        Me.txtAddress.Name = "txtAddress"
        Me.txtAddress.Size = New System.Drawing.Size(516, 76)
        Me.txtAddress.TabIndex = 47
        '
        'txtExpDate
        '
        Me.txtExpDate.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.txtExpDate.Enabled = False
        Me.txtExpDate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtExpDate.Location = New System.Drawing.Point(749, 373)
        Me.txtExpDate.Name = "txtExpDate"
        Me.txtExpDate.Size = New System.Drawing.Size(179, 26)
        Me.txtExpDate.TabIndex = 48
        '
        'txtIssueDate
        '
        Me.txtIssueDate.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.txtIssueDate.Enabled = False
        Me.txtIssueDate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtIssueDate.Location = New System.Drawing.Point(419, 373)
        Me.txtIssueDate.Name = "txtIssueDate"
        Me.txtIssueDate.Size = New System.Drawing.Size(195, 26)
        Me.txtIssueDate.TabIndex = 46
        '
        'txtBirthDate
        '
        Me.txtBirthDate.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.txtBirthDate.Enabled = False
        Me.txtBirthDate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtBirthDate.Location = New System.Drawing.Point(419, 326)
        Me.txtBirthDate.Name = "txtBirthDate"
        Me.txtBirthDate.Size = New System.Drawing.Size(195, 26)
        Me.txtBirthDate.TabIndex = 45
        '
        'txtLName_EN
        '
        Me.txtLName_EN.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.txtLName_EN.Enabled = False
        Me.txtLName_EN.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtLName_EN.Location = New System.Drawing.Point(749, 277)
        Me.txtLName_EN.Name = "txtLName_EN"
        Me.txtLName_EN.Size = New System.Drawing.Size(179, 26)
        Me.txtLName_EN.TabIndex = 44
        '
        'txtFName_EN
        '
        Me.txtFName_EN.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.txtFName_EN.Enabled = False
        Me.txtFName_EN.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtFName_EN.Location = New System.Drawing.Point(419, 277)
        Me.txtFName_EN.Name = "txtFName_EN"
        Me.txtFName_EN.Size = New System.Drawing.Size(195, 26)
        Me.txtFName_EN.TabIndex = 43
        '
        'txtBarcode
        '
        Me.txtBarcode.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtBarcode.Location = New System.Drawing.Point(419, 179)
        Me.txtBarcode.Name = "txtBarcode"
        Me.txtBarcode.Size = New System.Drawing.Size(195, 26)
        Me.txtBarcode.TabIndex = 55
        '
        'txtCardTypeName
        '
        Me.txtCardTypeName.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.txtCardTypeName.Enabled = False
        Me.txtCardTypeName.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtCardTypeName.Location = New System.Drawing.Point(419, 228)
        Me.txtCardTypeName.Name = "txtCardTypeName"
        Me.txtCardTypeName.Size = New System.Drawing.Size(195, 26)
        Me.txtCardTypeName.TabIndex = 56
        '
        'btnSave
        '
        Me.btnSave.BackgroundImage = CType(resources.GetObject("btnSave.BackgroundImage"), System.Drawing.Image)
        Me.btnSave.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSave.Location = New System.Drawing.Point(419, 530)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(111, 39)
        Me.btnSave.TabIndex = 59
        Me.btnSave.UseVisualStyleBackColor = True
        '
        'btnCancel
        '
        Me.btnCancel.BackgroundImage = CType(resources.GetObject("btnCancel.BackgroundImage"), System.Drawing.Image)
        Me.btnCancel.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCancel.Location = New System.Drawing.Point(536, 530)
        Me.btnCancel.Name = "btnCancel"
        Me.btnCancel.Size = New System.Drawing.Size(111, 39)
        Me.btnCancel.TabIndex = 58
        Me.btnCancel.UseVisualStyleBackColor = True
        '
        'lblVisitorID
        '
        Me.lblVisitorID.AutoSize = True
        Me.lblVisitorID.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.lblVisitorID.Location = New System.Drawing.Point(415, 156)
        Me.lblVisitorID.Name = "lblVisitorID"
        Me.lblVisitorID.Size = New System.Drawing.Size(19, 20)
        Me.lblVisitorID.TabIndex = 60
        Me.lblVisitorID.Text = "0"
        Me.lblVisitorID.Visible = False
        '
        'SerialBarcodeReader
        '
        '
        'frmReturnCard
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.ClientSize = New System.Drawing.Size(1008, 729)
        Me.Controls.Add(Me.lblVisitorID)
        Me.Controls.Add(Me.btnSave)
        Me.Controls.Add(Me.btnCancel)
        Me.Controls.Add(Me.txtCardTypeName)
        Me.Controls.Add(Me.txtBarcode)
        Me.Controls.Add(Me.txtAddress)
        Me.Controls.Add(Me.txtExpDate)
        Me.Controls.Add(Me.txtIssueDate)
        Me.Controls.Add(Me.txtBirthDate)
        Me.Controls.Add(Me.txtLName_EN)
        Me.Controls.Add(Me.txtFName_EN)
        Me.Controls.Add(Me.pcPicture)
        Me.Controls.Add(Me.btnRegister)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "frmReturnCard"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "frmReturnCard"
        CType(Me.pcPicture, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnRegister As System.Windows.Forms.Button
    Friend WithEvents pcPicture As System.Windows.Forms.PictureBox
    Friend WithEvents txtAddress As System.Windows.Forms.TextBox
    Friend WithEvents txtExpDate As System.Windows.Forms.TextBox
    Friend WithEvents txtIssueDate As System.Windows.Forms.TextBox
    Friend WithEvents txtBirthDate As System.Windows.Forms.TextBox
    Friend WithEvents txtLName_EN As System.Windows.Forms.TextBox
    Friend WithEvents txtFName_EN As System.Windows.Forms.TextBox
    Friend WithEvents txtBarcode As System.Windows.Forms.TextBox
    Friend WithEvents txtCardTypeName As System.Windows.Forms.TextBox
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Public WithEvents btnCancel As System.Windows.Forms.Button
    Friend WithEvents lblVisitorID As System.Windows.Forms.Label
    Friend WithEvents SerialBarcodeReader As System.IO.Ports.SerialPort
End Class
