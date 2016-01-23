<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmReportList
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmReportList))
        Me.pbSetting = New System.Windows.Forms.PictureBox()
        Me.pbRegistration = New System.Windows.Forms.PictureBox()
        Me.pbLog = New System.Windows.Forms.PictureBox()
        Me.lblTop10VisitorReportByEmployee = New System.Windows.Forms.LinkLabel()
        Me.VisitorReportByMeetingRoom = New System.Windows.Forms.LinkLabel()
        Me.BlacklistReport = New System.Windows.Forms.LinkLabel()
        Me.lblTotalVisitorReport = New System.Windows.Forms.LinkLabel()
        CType(Me.pbSetting, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbRegistration, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbLog, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'pbSetting
        '
        Me.pbSetting.BackColor = System.Drawing.Color.Transparent
        Me.pbSetting.Location = New System.Drawing.Point(676, 17)
        Me.pbSetting.Name = "pbSetting"
        Me.pbSetting.Size = New System.Drawing.Size(104, 45)
        Me.pbSetting.TabIndex = 65
        Me.pbSetting.TabStop = False
        '
        'pbRegistration
        '
        Me.pbRegistration.BackColor = System.Drawing.Color.Transparent
        Me.pbRegistration.Location = New System.Drawing.Point(465, 78)
        Me.pbRegistration.Name = "pbRegistration"
        Me.pbRegistration.Size = New System.Drawing.Size(209, 45)
        Me.pbRegistration.TabIndex = 64
        Me.pbRegistration.TabStop = False
        '
        'pbLog
        '
        Me.pbLog.BackColor = System.Drawing.Color.Transparent
        Me.pbLog.Location = New System.Drawing.Point(570, 17)
        Me.pbLog.Name = "pbLog"
        Me.pbLog.Size = New System.Drawing.Size(104, 45)
        Me.pbLog.TabIndex = 66
        Me.pbLog.TabStop = False
        '
        'lblTop10VisitorReportByEmployee
        '
        Me.lblTop10VisitorReportByEmployee.AutoSize = True
        Me.lblTop10VisitorReportByEmployee.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.lblTop10VisitorReportByEmployee.Location = New System.Drawing.Point(138, 248)
        Me.lblTop10VisitorReportByEmployee.Name = "lblTop10VisitorReportByEmployee"
        Me.lblTop10VisitorReportByEmployee.Size = New System.Drawing.Size(451, 24)
        Me.lblTop10VisitorReportByEmployee.TabIndex = 67
        Me.lblTop10VisitorReportByEmployee.TabStop = True
        Me.lblTop10VisitorReportByEmployee.Text = "Top 10 Visitor Registration Report by Employee"
        '
        'VisitorReportByMeetingRoom
        '
        Me.VisitorReportByMeetingRoom.AutoSize = True
        Me.VisitorReportByMeetingRoom.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.VisitorReportByMeetingRoom.Location = New System.Drawing.Point(138, 306)
        Me.VisitorReportByMeetingRoom.Name = "VisitorReportByMeetingRoom"
        Me.VisitorReportByMeetingRoom.Size = New System.Drawing.Size(422, 24)
        Me.VisitorReportByMeetingRoom.TabIndex = 68
        Me.VisitorReportByMeetingRoom.TabStop = True
        Me.VisitorReportByMeetingRoom.Text = "Visitor Registration Report by Meeting Room"
        '
        'BlacklistReport
        '
        Me.BlacklistReport.AutoSize = True
        Me.BlacklistReport.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.BlacklistReport.Location = New System.Drawing.Point(138, 370)
        Me.BlacklistReport.Name = "BlacklistReport"
        Me.BlacklistReport.Size = New System.Drawing.Size(153, 24)
        Me.BlacklistReport.TabIndex = 69
        Me.BlacklistReport.TabStop = True
        Me.BlacklistReport.Text = "Blacklist Report"
        '
        'lblTotalVisitorReport
        '
        Me.lblTotalVisitorReport.AutoSize = True
        Me.lblTotalVisitorReport.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.lblTotalVisitorReport.Location = New System.Drawing.Point(138, 187)
        Me.lblTotalVisitorReport.Name = "lblTotalVisitorReport"
        Me.lblTotalVisitorReport.Size = New System.Drawing.Size(304, 24)
        Me.lblTotalVisitorReport.TabIndex = 70
        Me.lblTotalVisitorReport.TabStop = True
        Me.lblTotalVisitorReport.Text = "Total Visitor Registration Report"
        '
        'frmReportList
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.ClientSize = New System.Drawing.Size(1008, 729)
        Me.Controls.Add(Me.lblTotalVisitorReport)
        Me.Controls.Add(Me.BlacklistReport)
        Me.Controls.Add(Me.VisitorReportByMeetingRoom)
        Me.Controls.Add(Me.lblTop10VisitorReportByEmployee)
        Me.Controls.Add(Me.pbLog)
        Me.Controls.Add(Me.pbSetting)
        Me.Controls.Add(Me.pbRegistration)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "frmReportList"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "frmReportList"
        CType(Me.pbSetting, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbRegistration, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbLog, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents pbSetting As System.Windows.Forms.PictureBox
    Friend WithEvents pbRegistration As System.Windows.Forms.PictureBox
    Friend WithEvents pbLog As System.Windows.Forms.PictureBox
    Friend WithEvents lblTop10VisitorReportByEmployee As System.Windows.Forms.LinkLabel
    Friend WithEvents VisitorReportByMeetingRoom As System.Windows.Forms.LinkLabel
    Friend WithEvents BlacklistReport As System.Windows.Forms.LinkLabel
    Friend WithEvents lblTotalVisitorReport As System.Windows.Forms.LinkLabel
End Class
