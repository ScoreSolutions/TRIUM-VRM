<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmLog
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
        Dim DataGridViewCellStyle1 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmLog))
        Me.dgvLog = New System.Windows.Forms.DataGridView()
        Me.colVisitorName = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.colEmployee = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.colPlace = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.colDate = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.colPurpose = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.txtSearchEmployee = New System.Windows.Forms.TextBox()
        Me.txtSearchVisitor = New System.Windows.Forms.TextBox()
        Me.DateTimePicker1 = New System.Windows.Forms.DateTimePicker()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.DateTimePicker2 = New System.Windows.Forms.DateTimePicker()
        Me.btnSearch = New System.Windows.Forms.Button()
        Me.pbSetting = New System.Windows.Forms.PictureBox()
        Me.pbRegistration = New System.Windows.Forms.PictureBox()
        Me.pbReport = New System.Windows.Forms.PictureBox()
        CType(Me.dgvLog, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbSetting, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbRegistration, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbReport, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'dgvLog
        '
        Me.dgvLog.AllowUserToAddRows = False
        Me.dgvLog.AllowUserToOrderColumns = True
        Me.dgvLog.AllowUserToResizeColumns = False
        Me.dgvLog.AllowUserToResizeRows = False
        DataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control
        DataGridViewCellStyle1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        DataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText
        DataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight
        DataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText
        DataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.[True]
        Me.dgvLog.ColumnHeadersDefaultCellStyle = DataGridViewCellStyle1
        Me.dgvLog.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.dgvLog.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.colVisitorName, Me.colEmployee, Me.colPlace, Me.colDate, Me.colPurpose})
        Me.dgvLog.Location = New System.Drawing.Point(57, 249)
        Me.dgvLog.Name = "dgvLog"
        Me.dgvLog.RowHeadersVisible = False
        Me.dgvLog.Size = New System.Drawing.Size(894, 448)
        Me.dgvLog.TabIndex = 52
        '
        'colVisitorName
        '
        Me.colVisitorName.DataPropertyName = "visitor_name"
        Me.colVisitorName.HeaderText = "Visitor Name"
        Me.colVisitorName.Name = "colVisitorName"
        Me.colVisitorName.Width = 150
        '
        'colEmployee
        '
        Me.colEmployee.DataPropertyName = "employee_name"
        Me.colEmployee.HeaderText = "Employee Name"
        Me.colEmployee.Name = "colEmployee"
        Me.colEmployee.Width = 150
        '
        'colPlace
        '
        Me.colPlace.DataPropertyName = "place"
        Me.colPlace.HeaderText = "Place"
        Me.colPlace.Name = "colPlace"
        Me.colPlace.Width = 250
        '
        'colDate
        '
        Me.colDate.DataPropertyName = "visite_date"
        Me.colDate.HeaderText = "Date"
        Me.colDate.Name = "colDate"
        '
        'colPurpose
        '
        Me.colPurpose.DataPropertyName = "purpose"
        Me.colPurpose.HeaderText = "Purpose"
        Me.colPurpose.Name = "colPurpose"
        Me.colPurpose.Width = 200
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label1.Location = New System.Drawing.Point(306, 150)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(87, 20)
        Me.Label1.TabIndex = 53
        Me.Label1.Text = "Employee"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label2.Location = New System.Drawing.Point(306, 181)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(60, 20)
        Me.Label2.TabIndex = 54
        Me.Label2.Text = "Visitor"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label3.Location = New System.Drawing.Point(306, 213)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(48, 20)
        Me.Label3.TabIndex = 55
        Me.Label3.Text = "Date"
        '
        'txtSearchEmployee
        '
        Me.txtSearchEmployee.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtSearchEmployee.Location = New System.Drawing.Point(424, 147)
        Me.txtSearchEmployee.Name = "txtSearchEmployee"
        Me.txtSearchEmployee.Size = New System.Drawing.Size(281, 26)
        Me.txtSearchEmployee.TabIndex = 56
        '
        'txtSearchVisitor
        '
        Me.txtSearchVisitor.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtSearchVisitor.Location = New System.Drawing.Point(424, 178)
        Me.txtSearchVisitor.Name = "txtSearchVisitor"
        Me.txtSearchVisitor.Size = New System.Drawing.Size(281, 26)
        Me.txtSearchVisitor.TabIndex = 57
        '
        'DateTimePicker1
        '
        Me.DateTimePicker1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.DateTimePicker1.Format = System.Windows.Forms.DateTimePickerFormat.[Short]
        Me.DateTimePicker1.Location = New System.Drawing.Point(424, 212)
        Me.DateTimePicker1.Name = "DateTimePicker1"
        Me.DateTimePicker1.Size = New System.Drawing.Size(124, 26)
        Me.DateTimePicker1.TabIndex = 58
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label4.Location = New System.Drawing.Point(551, 215)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(25, 20)
        Me.Label4.TabIndex = 59
        Me.Label4.Text = "to"
        '
        'DateTimePicker2
        '
        Me.DateTimePicker2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.DateTimePicker2.Format = System.Windows.Forms.DateTimePickerFormat.[Short]
        Me.DateTimePicker2.Location = New System.Drawing.Point(581, 213)
        Me.DateTimePicker2.Name = "DateTimePicker2"
        Me.DateTimePicker2.Size = New System.Drawing.Size(124, 26)
        Me.DateTimePicker2.TabIndex = 60
        '
        'btnSearch
        '
        Me.btnSearch.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.btnSearch.Location = New System.Drawing.Point(721, 150)
        Me.btnSearch.Name = "btnSearch"
        Me.btnSearch.Size = New System.Drawing.Size(93, 83)
        Me.btnSearch.TabIndex = 61
        Me.btnSearch.Text = "Search"
        Me.btnSearch.UseVisualStyleBackColor = True
        '
        'pbSetting
        '
        Me.pbSetting.BackColor = System.Drawing.Color.Transparent
        Me.pbSetting.Location = New System.Drawing.Point(677, 18)
        Me.pbSetting.Name = "pbSetting"
        Me.pbSetting.Size = New System.Drawing.Size(104, 45)
        Me.pbSetting.TabIndex = 63
        Me.pbSetting.TabStop = False
        '
        'pbRegistration
        '
        Me.pbRegistration.BackColor = System.Drawing.Color.Transparent
        Me.pbRegistration.Location = New System.Drawing.Point(466, 79)
        Me.pbRegistration.Name = "pbRegistration"
        Me.pbRegistration.Size = New System.Drawing.Size(209, 45)
        Me.pbRegistration.TabIndex = 62
        Me.pbRegistration.TabStop = False
        '
        'pbReport
        '
        Me.pbReport.BackColor = System.Drawing.Color.Transparent
        Me.pbReport.Location = New System.Drawing.Point(464, 18)
        Me.pbReport.Name = "pbReport"
        Me.pbReport.Size = New System.Drawing.Size(104, 45)
        Me.pbReport.TabIndex = 64
        Me.pbReport.TabStop = False
        '
        'frmLog
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.ClientSize = New System.Drawing.Size(1008, 729)
        Me.Controls.Add(Me.pbReport)
        Me.Controls.Add(Me.pbSetting)
        Me.Controls.Add(Me.pbRegistration)
        Me.Controls.Add(Me.btnSearch)
        Me.Controls.Add(Me.DateTimePicker2)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.DateTimePicker1)
        Me.Controls.Add(Me.txtSearchVisitor)
        Me.Controls.Add(Me.txtSearchEmployee)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.dgvLog)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "frmLog"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "frmLog"
        CType(Me.dgvLog, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbSetting, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbRegistration, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbReport, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents dgvLog As System.Windows.Forms.DataGridView
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents txtSearchEmployee As System.Windows.Forms.TextBox
    Friend WithEvents txtSearchVisitor As System.Windows.Forms.TextBox
    Friend WithEvents DateTimePicker1 As System.Windows.Forms.DateTimePicker
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents DateTimePicker2 As System.Windows.Forms.DateTimePicker
    Friend WithEvents btnSearch As System.Windows.Forms.Button
    Friend WithEvents colVisitorName As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents colEmployee As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents colPlace As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents colDate As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents colPurpose As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents pbSetting As System.Windows.Forms.PictureBox
    Friend WithEvents pbRegistration As System.Windows.Forms.PictureBox
    Friend WithEvents pbReport As System.Windows.Forms.PictureBox
End Class
