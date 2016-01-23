<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmSetting
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmSetting))
        Me.SaveFileDialog1 = New System.Windows.Forms.SaveFileDialog()
        Me.pbRegistration = New System.Windows.Forms.PictureBox()
        Me.cmbIDCardBaudRate = New System.Windows.Forms.ComboBox()
        Me.cbIDCardComport = New System.Windows.Forms.ComboBox()
        Me.cmbBarcodeBaudRate = New System.Windows.Forms.ComboBox()
        Me.cmbBarcodeComport = New System.Windows.Forms.ComboBox()
        Me.cmbFaceCaptureCamera = New System.Windows.Forms.ComboBox()
        Me.btnSave = New System.Windows.Forms.Button()
        Me.btnCancel = New System.Windows.Forms.Button()
        CType(Me.pbRegistration, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'pbRegistration
        '
        Me.pbRegistration.BackColor = System.Drawing.Color.Transparent
        Me.pbRegistration.BackgroundImage = Global.VRM.My.Resources.Resources.Untitled_1
        Me.pbRegistration.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom
        Me.pbRegistration.Location = New System.Drawing.Point(477, 62)
        Me.pbRegistration.Name = "pbRegistration"
        Me.pbRegistration.Size = New System.Drawing.Size(239, 60)
        Me.pbRegistration.TabIndex = 9
        Me.pbRegistration.TabStop = False
        '
        'cmbIDCardBaudRate
        '
        Me.cmbIDCardBaudRate.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbIDCardBaudRate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.cmbIDCardBaudRate.FormattingEnabled = True
        Me.cmbIDCardBaudRate.Location = New System.Drawing.Point(247, 324)
        Me.cmbIDCardBaudRate.Name = "cmbIDCardBaudRate"
        Me.cmbIDCardBaudRate.Size = New System.Drawing.Size(237, 28)
        Me.cmbIDCardBaudRate.TabIndex = 3
        '
        'cbIDCardComport
        '
        Me.cbIDCardComport.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cbIDCardComport.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.cbIDCardComport.FormattingEnabled = True
        Me.cbIDCardComport.Location = New System.Drawing.Point(247, 258)
        Me.cbIDCardComport.Name = "cbIDCardComport"
        Me.cbIDCardComport.Size = New System.Drawing.Size(237, 28)
        Me.cbIDCardComport.TabIndex = 1
        '
        'cmbBarcodeBaudRate
        '
        Me.cmbBarcodeBaudRate.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbBarcodeBaudRate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.cmbBarcodeBaudRate.FormattingEnabled = True
        Me.cmbBarcodeBaudRate.Location = New System.Drawing.Point(674, 324)
        Me.cmbBarcodeBaudRate.Name = "cmbBarcodeBaudRate"
        Me.cmbBarcodeBaudRate.Size = New System.Drawing.Size(233, 28)
        Me.cmbBarcodeBaudRate.TabIndex = 3
        '
        'cmbBarcodeComport
        '
        Me.cmbBarcodeComport.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbBarcodeComport.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.cmbBarcodeComport.FormattingEnabled = True
        Me.cmbBarcodeComport.Location = New System.Drawing.Point(674, 258)
        Me.cmbBarcodeComport.Name = "cmbBarcodeComport"
        Me.cmbBarcodeComport.Size = New System.Drawing.Size(233, 28)
        Me.cmbBarcodeComport.TabIndex = 1
        '
        'cmbFaceCaptureCamera
        '
        Me.cmbFaceCaptureCamera.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbFaceCaptureCamera.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.cmbFaceCaptureCamera.FormattingEnabled = True
        Me.cmbFaceCaptureCamera.Location = New System.Drawing.Point(131, 553)
        Me.cmbFaceCaptureCamera.Name = "cmbFaceCaptureCamera"
        Me.cmbFaceCaptureCamera.Size = New System.Drawing.Size(353, 28)
        Me.cmbFaceCaptureCamera.TabIndex = 1
        '
        'btnSave
        '
        Me.btnSave.BackgroundImage = CType(resources.GetObject("btnSave.BackgroundImage"), System.Drawing.Image)
        Me.btnSave.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSave.Location = New System.Drawing.Point(573, 474)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(143, 56)
        Me.btnSave.TabIndex = 25
        Me.btnSave.UseVisualStyleBackColor = True
        '
        'btnCancel
        '
        Me.btnCancel.BackgroundImage = CType(resources.GetObject("btnCancel.BackgroundImage"), System.Drawing.Image)
        Me.btnCancel.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCancel.Location = New System.Drawing.Point(733, 474)
        Me.btnCancel.Name = "btnCancel"
        Me.btnCancel.Size = New System.Drawing.Size(143, 56)
        Me.btnCancel.TabIndex = 24
        Me.btnCancel.UseVisualStyleBackColor = True
        '
        'frmSetting
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.CausesValidation = False
        Me.ClientSize = New System.Drawing.Size(1008, 729)
        Me.ControlBox = False
        Me.Controls.Add(Me.cmbBarcodeBaudRate)
        Me.Controls.Add(Me.cmbIDCardBaudRate)
        Me.Controls.Add(Me.cmbFaceCaptureCamera)
        Me.Controls.Add(Me.cmbBarcodeComport)
        Me.Controls.Add(Me.btnSave)
        Me.Controls.Add(Me.cbIDCardComport)
        Me.Controls.Add(Me.btnCancel)
        Me.Controls.Add(Me.pbRegistration)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "frmSetting"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "frmSetting"
        CType(Me.pbRegistration, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents SaveFileDialog1 As System.Windows.Forms.SaveFileDialog
    Friend WithEvents pbRegistration As System.Windows.Forms.PictureBox
    Friend WithEvents cbIDCardComport As System.Windows.Forms.ComboBox
    Friend WithEvents cmbIDCardBaudRate As System.Windows.Forms.ComboBox
    Friend WithEvents cmbBarcodeBaudRate As System.Windows.Forms.ComboBox
    Friend WithEvents cmbBarcodeComport As System.Windows.Forms.ComboBox
    Friend WithEvents cmbFaceCaptureCamera As System.Windows.Forms.ComboBox
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Public WithEvents btnCancel As System.Windows.Forms.Button
End Class
