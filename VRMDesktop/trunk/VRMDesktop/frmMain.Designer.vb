<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMain
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmMain))
        Me.btnRegis = New System.Windows.Forms.Button
        Me.btnHelp = New System.Windows.Forms.Button
        Me.btnAbout = New System.Windows.Forms.Button
        Me.btnSetting = New System.Windows.Forms.Button
        Me.btnLog = New System.Windows.Forms.Button
        Me.btnReport = New System.Windows.Forms.Button
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.SuspendLayout()
        '
        'btnRegis
        '
        Me.btnRegis.BackgroundImage = CType(resources.GetObject("btnRegis.BackgroundImage"), System.Drawing.Image)
        Me.btnRegis.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnRegis.Location = New System.Drawing.Point(25, 101)
        Me.btnRegis.Name = "btnRegis"
        Me.btnRegis.Size = New System.Drawing.Size(278, 47)
        Me.btnRegis.TabIndex = 57
        Me.btnRegis.UseVisualStyleBackColor = True
        '
        'btnHelp
        '
        Me.btnHelp.BackgroundImage = CType(resources.GetObject("btnHelp.BackgroundImage"), System.Drawing.Image)
        Me.btnHelp.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnHelp.Location = New System.Drawing.Point(868, 100)
        Me.btnHelp.Name = "btnHelp"
        Me.btnHelp.Size = New System.Drawing.Size(126, 44)
        Me.btnHelp.TabIndex = 56
        Me.btnHelp.UseVisualStyleBackColor = True
        '
        'btnAbout
        '
        Me.btnAbout.BackgroundImage = CType(resources.GetObject("btnAbout.BackgroundImage"), System.Drawing.Image)
        Me.btnAbout.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnAbout.Location = New System.Drawing.Point(727, 100)
        Me.btnAbout.Name = "btnAbout"
        Me.btnAbout.Size = New System.Drawing.Size(126, 44)
        Me.btnAbout.TabIndex = 55
        Me.btnAbout.UseVisualStyleBackColor = True
        '
        'btnSetting
        '
        Me.btnSetting.BackgroundImage = CType(resources.GetObject("btnSetting.BackgroundImage"), System.Drawing.Image)
        Me.btnSetting.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSetting.Location = New System.Drawing.Point(588, 101)
        Me.btnSetting.Name = "btnSetting"
        Me.btnSetting.Size = New System.Drawing.Size(126, 44)
        Me.btnSetting.TabIndex = 54
        Me.btnSetting.UseVisualStyleBackColor = True
        '
        'btnLog
        '
        Me.btnLog.BackgroundImage = CType(resources.GetObject("btnLog.BackgroundImage"), System.Drawing.Image)
        Me.btnLog.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnLog.Location = New System.Drawing.Point(449, 101)
        Me.btnLog.Name = "btnLog"
        Me.btnLog.Size = New System.Drawing.Size(126, 44)
        Me.btnLog.TabIndex = 53
        Me.btnLog.UseVisualStyleBackColor = True
        '
        'btnReport
        '
        Me.btnReport.BackgroundImage = CType(resources.GetObject("btnReport.BackgroundImage"), System.Drawing.Image)
        Me.btnReport.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnReport.Location = New System.Drawing.Point(312, 101)
        Me.btnReport.Name = "btnReport"
        Me.btnReport.Size = New System.Drawing.Size(126, 44)
        Me.btnReport.TabIndex = 52
        Me.btnReport.UseVisualStyleBackColor = True
        '
        'Panel1
        '
        Me.Panel1.Location = New System.Drawing.Point(25, 154)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(969, 584)
        Me.Panel1.TabIndex = 58
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1024, 768)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.btnRegis)
        Me.Controls.Add(Me.btnHelp)
        Me.Controls.Add(Me.btnAbout)
        Me.Controls.Add(Me.btnSetting)
        Me.Controls.Add(Me.btnLog)
        Me.Controls.Add(Me.btnReport)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "frmMain"
        Me.Text = "frmMain"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents btnRegis As System.Windows.Forms.Button
    Friend WithEvents btnHelp As System.Windows.Forms.Button
    Friend WithEvents btnAbout As System.Windows.Forms.Button
    Friend WithEvents btnSetting As System.Windows.Forms.Button
    Friend WithEvents btnLog As System.Windows.Forms.Button
    Friend WithEvents btnReport As System.Windows.Forms.Button
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
End Class
