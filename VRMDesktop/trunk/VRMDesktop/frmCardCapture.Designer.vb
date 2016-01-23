<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmCardCapture
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmCardCapture))
        Me.SplitContainer1 = New System.Windows.Forms.SplitContainer()
        Me.btnCardCapture = New System.Windows.Forms.Button()
        Me.btnRecognize = New System.Windows.Forms.Button()
        Me.lblImagePath = New System.Windows.Forms.Label()
        Me.btnLoadZone = New System.Windows.Forms.Button()
        Me.btnSaveZone = New System.Windows.Forms.Button()
        Me.btnClearZone = New System.Windows.Forms.Button()
        Me.btnCardReCapture = New System.Windows.Forms.Button()
        Me.pbCardPreview = New System.Windows.Forms.PictureBox()
        Me.pbCardDisplay = New System.Windows.Forms.PictureBox()
        Me.lblCardTypeID = New System.Windows.Forms.Label()
        Me.lblCardTypeName = New System.Windows.Forms.Label()
        Me.txtLastName = New System.Windows.Forms.TextBox()
        Me.txtFirstName = New System.Windows.Forms.TextBox()
        Me.txtCardID = New System.Windows.Forms.TextBox()
        Me.btnSave = New System.Windows.Forms.Button()
        Me.SplitContainer1.Panel1.SuspendLayout()
        Me.SplitContainer1.Panel2.SuspendLayout()
        Me.SplitContainer1.SuspendLayout()
        CType(Me.pbCardPreview, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbCardDisplay, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'SplitContainer1
        '
        Me.SplitContainer1.BackColor = System.Drawing.Color.Transparent
        Me.SplitContainer1.Location = New System.Drawing.Point(3, 0)
        Me.SplitContainer1.Name = "SplitContainer1"
        '
        'SplitContainer1.Panel1
        '
        Me.SplitContainer1.Panel1.Controls.Add(Me.btnCardCapture)
        Me.SplitContainer1.Panel1.Controls.Add(Me.btnRecognize)
        Me.SplitContainer1.Panel1.Controls.Add(Me.lblImagePath)
        Me.SplitContainer1.Panel1.Controls.Add(Me.btnLoadZone)
        Me.SplitContainer1.Panel1.Controls.Add(Me.btnSaveZone)
        Me.SplitContainer1.Panel1.Controls.Add(Me.btnClearZone)
        Me.SplitContainer1.Panel1.Controls.Add(Me.btnCardReCapture)
        Me.SplitContainer1.Panel1.Controls.Add(Me.pbCardPreview)
        Me.SplitContainer1.Panel1.Controls.Add(Me.pbCardDisplay)
        '
        'SplitContainer1.Panel2
        '
        Me.SplitContainer1.Panel2.Controls.Add(Me.lblCardTypeID)
        Me.SplitContainer1.Panel2.Controls.Add(Me.lblCardTypeName)
        Me.SplitContainer1.Panel2.Controls.Add(Me.txtLastName)
        Me.SplitContainer1.Panel2.Controls.Add(Me.txtFirstName)
        Me.SplitContainer1.Panel2.Controls.Add(Me.txtCardID)
        Me.SplitContainer1.Panel2.Controls.Add(Me.btnSave)
        Me.SplitContainer1.Size = New System.Drawing.Size(803, 456)
        Me.SplitContainer1.SplitterDistance = 450
        Me.SplitContainer1.TabIndex = 38
        '
        'btnCardCapture
        '
        Me.btnCardCapture.BackgroundImage = CType(resources.GetObject("btnCardCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnCardCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCardCapture.Location = New System.Drawing.Point(170, 345)
        Me.btnCardCapture.Name = "btnCardCapture"
        Me.btnCardCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnCardCapture.TabIndex = 30
        Me.btnCardCapture.UseVisualStyleBackColor = True
        '
        'btnRecognize
        '
        Me.btnRecognize.BackgroundImage = CType(resources.GetObject("btnRecognize.BackgroundImage"), System.Drawing.Image)
        Me.btnRecognize.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnRecognize.Location = New System.Drawing.Point(230, 345)
        Me.btnRecognize.Name = "btnRecognize"
        Me.btnRecognize.Size = New System.Drawing.Size(108, 39)
        Me.btnRecognize.TabIndex = 49
        Me.btnRecognize.UseVisualStyleBackColor = True
        Me.btnRecognize.Visible = False
        '
        'lblImagePath
        '
        Me.lblImagePath.AutoSize = True
        Me.lblImagePath.Location = New System.Drawing.Point(143, 377)
        Me.lblImagePath.Name = "lblImagePath"
        Me.lblImagePath.Size = New System.Drawing.Size(0, 13)
        Me.lblImagePath.TabIndex = 51
        Me.lblImagePath.Visible = False
        '
        'btnLoadZone
        '
        Me.btnLoadZone.Location = New System.Drawing.Point(337, 400)
        Me.btnLoadZone.Name = "btnLoadZone"
        Me.btnLoadZone.Size = New System.Drawing.Size(75, 23)
        Me.btnLoadZone.TabIndex = 34
        Me.btnLoadZone.Text = "Load Zone"
        Me.btnLoadZone.UseVisualStyleBackColor = True
        Me.btnLoadZone.Visible = False
        '
        'btnSaveZone
        '
        Me.btnSaveZone.BackgroundImage = CType(resources.GetObject("btnSaveZone.BackgroundImage"), System.Drawing.Image)
        Me.btnSaveZone.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSaveZone.Location = New System.Drawing.Point(133, 390)
        Me.btnSaveZone.Name = "btnSaveZone"
        Me.btnSaveZone.Size = New System.Drawing.Size(91, 33)
        Me.btnSaveZone.TabIndex = 33
        Me.btnSaveZone.UseVisualStyleBackColor = True
        '
        'btnClearZone
        '
        Me.btnClearZone.BackgroundImage = CType(resources.GetObject("btnClearZone.BackgroundImage"), System.Drawing.Image)
        Me.btnClearZone.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnClearZone.Location = New System.Drawing.Point(233, 390)
        Me.btnClearZone.Name = "btnClearZone"
        Me.btnClearZone.Size = New System.Drawing.Size(88, 33)
        Me.btnClearZone.TabIndex = 32
        Me.btnClearZone.UseVisualStyleBackColor = True
        '
        'btnCardReCapture
        '
        Me.btnCardReCapture.BackgroundImage = CType(resources.GetObject("btnCardReCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnCardReCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCardReCapture.Location = New System.Drawing.Point(113, 345)
        Me.btnCardReCapture.Name = "btnCardReCapture"
        Me.btnCardReCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnCardReCapture.TabIndex = 29
        Me.btnCardReCapture.UseVisualStyleBackColor = True
        Me.btnCardReCapture.Visible = False
        '
        'pbCardPreview
        '
        Me.pbCardPreview.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.pbCardPreview.Location = New System.Drawing.Point(28, 30)
        Me.pbCardPreview.Name = "pbCardPreview"
        Me.pbCardPreview.Size = New System.Drawing.Size(408, 290)
        Me.pbCardPreview.TabIndex = 28
        Me.pbCardPreview.TabStop = False
        '
        'pbCardDisplay
        '
        Me.pbCardDisplay.Location = New System.Drawing.Point(28, 30)
        Me.pbCardDisplay.Name = "pbCardDisplay"
        Me.pbCardDisplay.Size = New System.Drawing.Size(408, 290)
        Me.pbCardDisplay.TabIndex = 31
        Me.pbCardDisplay.TabStop = False
        '
        'lblCardTypeID
        '
        Me.lblCardTypeID.AutoSize = True
        Me.lblCardTypeID.Location = New System.Drawing.Point(104, 6)
        Me.lblCardTypeID.Name = "lblCardTypeID"
        Me.lblCardTypeID.Size = New System.Drawing.Size(0, 13)
        Me.lblCardTypeID.TabIndex = 48
        Me.lblCardTypeID.Visible = False
        '
        'lblCardTypeName
        '
        Me.lblCardTypeName.AutoSize = True
        Me.lblCardTypeName.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.lblCardTypeName.Location = New System.Drawing.Point(103, 98)
        Me.lblCardTypeName.Name = "lblCardTypeName"
        Me.lblCardTypeName.Size = New System.Drawing.Size(81, 16)
        Me.lblCardTypeName.TabIndex = 47
        Me.lblCardTypeName.Text = "Card Type"
        '
        'txtLastName
        '
        Me.txtLastName.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtLastName.Location = New System.Drawing.Point(107, 193)
        Me.txtLastName.Name = "txtLastName"
        Me.txtLastName.Size = New System.Drawing.Size(183, 22)
        Me.txtLastName.TabIndex = 45
        '
        'txtFirstName
        '
        Me.txtFirstName.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtFirstName.Location = New System.Drawing.Point(107, 161)
        Me.txtFirstName.Name = "txtFirstName"
        Me.txtFirstName.Size = New System.Drawing.Size(183, 22)
        Me.txtFirstName.TabIndex = 43
        '
        'txtCardID
        '
        Me.txtCardID.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtCardID.Location = New System.Drawing.Point(106, 129)
        Me.txtCardID.Name = "txtCardID"
        Me.txtCardID.Size = New System.Drawing.Size(183, 22)
        Me.txtCardID.TabIndex = 41
        '
        'btnSave
        '
        Me.btnSave.BackgroundImage = CType(resources.GetObject("btnSave.BackgroundImage"), System.Drawing.Image)
        Me.btnSave.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSave.Location = New System.Drawing.Point(106, 235)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(111, 39)
        Me.btnSave.TabIndex = 38
        Me.btnSave.UseVisualStyleBackColor = True
        Me.btnSave.Visible = False
        '
        'frmCardCapture
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.ClientSize = New System.Drawing.Size(809, 460)
        Me.Controls.Add(Me.SplitContainer1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Name = "frmCardCapture"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
        Me.Text = "Card Capture"
        Me.SplitContainer1.Panel1.ResumeLayout(False)
        Me.SplitContainer1.Panel1.PerformLayout()
        Me.SplitContainer1.Panel2.ResumeLayout(False)
        Me.SplitContainer1.Panel2.PerformLayout()
        Me.SplitContainer1.ResumeLayout(False)
        CType(Me.pbCardPreview, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbCardDisplay, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents SplitContainer1 As System.Windows.Forms.SplitContainer
    Friend WithEvents btnCardCapture As System.Windows.Forms.Button
    Friend WithEvents btnCardReCapture As System.Windows.Forms.Button
    Friend WithEvents pbCardPreview As System.Windows.Forms.PictureBox
    Friend WithEvents pbCardDisplay As System.Windows.Forms.PictureBox
    Friend WithEvents lblCardTypeID As System.Windows.Forms.Label
    Friend WithEvents lblCardTypeName As System.Windows.Forms.Label
    Friend WithEvents txtLastName As System.Windows.Forms.TextBox
    Friend WithEvents txtFirstName As System.Windows.Forms.TextBox
    Friend WithEvents txtCardID As System.Windows.Forms.TextBox
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Friend WithEvents btnRecognize As System.Windows.Forms.Button
    Friend WithEvents btnClearZone As System.Windows.Forms.Button
    Friend WithEvents btnSaveZone As System.Windows.Forms.Button
    Friend WithEvents btnLoadZone As System.Windows.Forms.Button
    Friend WithEvents lblImagePath As System.Windows.Forms.Label
End Class
