Imports Microsoft.VisualBasic
Imports System
Namespace Forms
	Partial Public Class DeviceForm
		Inherits System.Windows.Forms.Form
		Private WithEvents btnOk As System.Windows.Forms.Button
		Private btnCancel As System.Windows.Forms.Button
		Private Name2 As System.Windows.Forms.ColumnHeader
		Private columnHeader1 As System.Windows.Forms.ColumnHeader
		Private WithEvents lvDevicesList As System.Windows.Forms.ListView

		Private components As System.ComponentModel.Container = Nothing
		Private lblVideoFormat As System.Windows.Forms.Label
		Private cbVideoFormat As System.Windows.Forms.ComboBox

		Protected Overrides Overloads Sub Dispose(ByVal disposing As Boolean)
			If disposing Then
				If components IsNot Nothing Then
					components.Dispose()
				End If
			End If
			MyBase.Dispose(disposing)
		End Sub

		Private Sub InitializeComponent()
            Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(DeviceForm))
            Me.lvDevicesList = New System.Windows.Forms.ListView
            Me.columnHeader1 = New System.Windows.Forms.ColumnHeader
            Me.Name2 = New System.Windows.Forms.ColumnHeader
            Me.btnOk = New System.Windows.Forms.Button
            Me.btnCancel = New System.Windows.Forms.Button
            Me.lblVideoFormat = New System.Windows.Forms.Label
            Me.cbVideoFormat = New System.Windows.Forms.ComboBox
            Me.toolStrip1 = New System.Windows.Forms.ToolStrip
            Me.tsbConnect = New System.Windows.Forms.ToolStripButton
            Me.tsbDisconnect = New System.Windows.Forms.ToolStripButton
            Me.toolStrip1.SuspendLayout()
            Me.SuspendLayout()
            '
            'lvDevicesList
            '
            Me.lvDevicesList.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                        Or System.Windows.Forms.AnchorStyles.Left) _
                        Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.lvDevicesList.Columns.AddRange(New System.Windows.Forms.ColumnHeader() {Me.columnHeader1})
            Me.lvDevicesList.Location = New System.Drawing.Point(3, 28)
            Me.lvDevicesList.MultiSelect = False
            Me.lvDevicesList.Name = "lvDevicesList"
            Me.lvDevicesList.Size = New System.Drawing.Size(417, 154)
            Me.lvDevicesList.TabIndex = 0
            Me.lvDevicesList.UseCompatibleStateImageBehavior = False
            Me.lvDevicesList.View = System.Windows.Forms.View.Details
            '
            'columnHeader1
            '
            Me.columnHeader1.Text = "Name"
            Me.columnHeader1.Width = 403
            '
            'Name2
            '
            Me.Name2.Width = 400
            '
            'btnOk
            '
            Me.btnOk.Anchor = CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnOk.Location = New System.Drawing.Point(264, 215)
            Me.btnOk.Name = "btnOk"
            Me.btnOk.Size = New System.Drawing.Size(75, 23)
            Me.btnOk.TabIndex = 3
            Me.btnOk.Text = "&OK"
            '
            'btnCancel
            '
            Me.btnCancel.Anchor = CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel
            Me.btnCancel.Location = New System.Drawing.Point(345, 215)
            Me.btnCancel.Name = "btnCancel"
            Me.btnCancel.Size = New System.Drawing.Size(75, 23)
            Me.btnCancel.TabIndex = 4
            Me.btnCancel.Text = "&Cancel"
            '
            'lblVideoFormat
            '
            Me.lblVideoFormat.Anchor = CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles)
            Me.lblVideoFormat.AutoSize = True
            Me.lblVideoFormat.Location = New System.Drawing.Point(12, 191)
            Me.lblVideoFormat.Name = "lblVideoFormat"
            Me.lblVideoFormat.Size = New System.Drawing.Size(69, 13)
            Me.lblVideoFormat.TabIndex = 1
            Me.lblVideoFormat.Text = "Video format:"
            Me.lblVideoFormat.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
            '
            'cbVideoFormat
            '
            Me.cbVideoFormat.Anchor = CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) _
                        Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.cbVideoFormat.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
            Me.cbVideoFormat.FormattingEnabled = True
            Me.cbVideoFormat.Location = New System.Drawing.Point(96, 188)
            Me.cbVideoFormat.Name = "cbVideoFormat"
            Me.cbVideoFormat.Size = New System.Drawing.Size(324, 21)
            Me.cbVideoFormat.TabIndex = 2
            '
            'toolStrip1
            '
            Me.toolStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsbConnect, Me.tsbDisconnect})
            Me.toolStrip1.Location = New System.Drawing.Point(0, 0)
            Me.toolStrip1.Name = "toolStrip1"
            Me.toolStrip1.Size = New System.Drawing.Size(424, 25)
            Me.toolStrip1.TabIndex = 7
            Me.toolStrip1.Text = "toolStrip1"
            '
            'tsbConnect
            '
            Me.tsbConnect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text
            Me.tsbConnect.Image = CType(resources.GetObject("tsbConnect.Image"), System.Drawing.Image)
            Me.tsbConnect.ImageTransparentColor = System.Drawing.Color.Magenta
            Me.tsbConnect.Name = "tsbConnect"
            Me.tsbConnect.Size = New System.Drawing.Size(65, 22)
            Me.tsbConnect.Text = "Co&nnect .."
            '
            'tsbDisconnect
            '
            Me.tsbDisconnect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text
            Me.tsbDisconnect.Image = CType(resources.GetObject("tsbDisconnect.Image"), System.Drawing.Image)
            Me.tsbDisconnect.ImageTransparentColor = System.Drawing.Color.Magenta
            Me.tsbDisconnect.Name = "tsbDisconnect"
            Me.tsbDisconnect.Size = New System.Drawing.Size(70, 22)
            Me.tsbDisconnect.Text = "&Disconnect"
            '
            'DeviceForm
            '
            Me.AcceptButton = Me.btnOk
            Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
            Me.CancelButton = Me.btnCancel
            Me.ClientSize = New System.Drawing.Size(424, 250)
            Me.Controls.Add(Me.toolStrip1)
            Me.Controls.Add(Me.btnOk)
            Me.Controls.Add(Me.lvDevicesList)
            Me.Controls.Add(Me.btnCancel)
            Me.Controls.Add(Me.cbVideoFormat)
            Me.Controls.Add(Me.lblVideoFormat)
            Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
            Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
            Me.MaximizeBox = False
            Me.MinimizeBox = False
            Me.Name = "DeviceForm"
            Me.Opacity = 0
            Me.ShowInTaskbar = False
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
            Me.Text = "Choose Device"
            Me.toolStrip1.ResumeLayout(False)
            Me.toolStrip1.PerformLayout()
            Me.ResumeLayout(False)
            Me.PerformLayout()

        End Sub
		Private toolStrip1 As System.Windows.Forms.ToolStrip
		Private WithEvents tsbConnect As System.Windows.Forms.ToolStripButton
		Private WithEvents tsbDisconnect As System.Windows.Forms.ToolStripButton
	End Class
End Namespace
