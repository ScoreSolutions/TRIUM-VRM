Imports Microsoft.VisualBasic
Imports System

Namespace Forms
	Partial Public Class MainForm
		''' <summary>
		''' Required designer variable.
		''' </summary>
		Private components As System.ComponentModel.IContainer = Nothing

		''' <summary>
		''' Clean up any resources being used.
		''' </summary>
		''' <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		Protected Overrides Sub Dispose(ByVal disposing As Boolean)
			If disposing AndAlso (components IsNot Nothing) Then
				components.Dispose()
			End If
			MyBase.Dispose(disposing)
		End Sub

#Region "Windows Form Designer generated code"

		''' <summary>
		''' Required method for Designer support - do not modify
		''' the contents of this method with the code editor.
		''' </summary>
		Private Sub InitializeComponent()
            Me.components = New System.ComponentModel.Container
            Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(MainForm))
            Me.toolTip1 = New System.Windows.Forms.ToolTip(Me.components)
            Me.label1 = New System.Windows.Forms.Label
            Me.openFileDialog = New System.Windows.Forms.OpenFileDialog
            Me.folderBrowserDialog = New System.Windows.Forms.FolderBrowserDialog
            Me.TimerEnrollImage = New System.Windows.Forms.Timer(Me.components)
            Me.mainMnuStrip = New System.Windows.Forms.MenuStrip
            Me.fileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.chooseDeviceToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.startSurveillanceToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.stopSurveillanceToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.toolStripSeparator3 = New System.Windows.Forms.ToolStripSeparator
            Me.enrollFromImagesToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.enrollFromDirectoryToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.toolStripSeparator2 = New System.Windows.Forms.ToolStripSeparator
            Me.exitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.toolsToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.settingsToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.toolStripSeparator1 = New System.Windows.Forms.ToolStripSeparator
            Me.watchListToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.clearWatchListToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.helpToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.aboutToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.treeView = New System.Windows.Forms.TreeView
            Me.contextMnuStrip = New System.Windows.Forms.ContextMenuStrip(Me.components)
            Me.zoomToFitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.zoomTo50ToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.zoom100ToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.zoom200ToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.removeToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
            Me.buttonAddToWatchList = New System.Windows.Forms.Button
            Me.cmbTakePhoto = New System.Windows.Forms.Button
            Me.btnClearBlackList = New System.Windows.Forms.Button
            Me.nlViews = New Neurotec.Samples.Forms.ViewsSizer
            Me.mainMnuStrip.SuspendLayout()
            Me.contextMnuStrip.SuspendLayout()
            Me.SuspendLayout()
            '
            'toolTip1
            '
            Me.toolTip1.AutoPopDelay = 5000
            Me.toolTip1.InitialDelay = 500
            Me.toolTip1.IsBalloon = True
            Me.toolTip1.ReshowDelay = 100
            Me.toolTip1.ToolTipIcon = System.Windows.Forms.ToolTipIcon.Info
            '
            'label1
            '
            Me.label1.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.label1.AutoSize = True
            Me.label1.Location = New System.Drawing.Point(-23, 8)
            Me.label1.Name = "label1"
            Me.label1.Size = New System.Drawing.Size(13, 13)
            Me.label1.TabIndex = 8
            Me.label1.Text = "?"
            Me.toolTip1.SetToolTip(Me.label1, "Regular font - active tracked face" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "Bold - subject has disappeared" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "Gray - subjec" & _
                    "t cannot be added to database")
            Me.label1.Visible = False
            '
            'openFileDialog
            '
            Me.openFileDialog.Filter = "All files|*.*"
            Me.openFileDialog.Multiselect = True
            Me.openFileDialog.Title = "Select image(s)"
            '
            'folderBrowserDialog
            '
            Me.folderBrowserDialog.ShowNewFolderButton = False
            '
            'TimerEnrollImage
            '
            Me.TimerEnrollImage.Enabled = True
            Me.TimerEnrollImage.Interval = 1000
            '
            'mainMnuStrip
            '
            Me.mainMnuStrip.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.fileToolStripMenuItem, Me.toolsToolStripMenuItem, Me.helpToolStripMenuItem})
            Me.mainMnuStrip.Location = New System.Drawing.Point(0, 0)
            Me.mainMnuStrip.Name = "mainMnuStrip"
            Me.mainMnuStrip.Size = New System.Drawing.Size(650, 24)
            Me.mainMnuStrip.TabIndex = 6
            Me.mainMnuStrip.Text = "Main"
            Me.mainMnuStrip.Visible = False
            '
            'fileToolStripMenuItem
            '
            Me.fileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.chooseDeviceToolStripMenuItem, Me.startSurveillanceToolStripMenuItem, Me.stopSurveillanceToolStripMenuItem, Me.toolStripSeparator3, Me.enrollFromImagesToolStripMenuItem, Me.enrollFromDirectoryToolStripMenuItem, Me.toolStripSeparator2, Me.exitToolStripMenuItem})
            Me.fileToolStripMenuItem.Name = "fileToolStripMenuItem"
            Me.fileToolStripMenuItem.Size = New System.Drawing.Size(37, 20)
            Me.fileToolStripMenuItem.Text = "&File"
            '
            'chooseDeviceToolStripMenuItem
            '
            Me.chooseDeviceToolStripMenuItem.Name = "chooseDeviceToolStripMenuItem"
            Me.chooseDeviceToolStripMenuItem.Size = New System.Drawing.Size(186, 22)
            Me.chooseDeviceToolStripMenuItem.Text = "&Add Device..."
            '
            'startSurveillanceToolStripMenuItem
            '
            Me.startSurveillanceToolStripMenuItem.Enabled = False
            Me.startSurveillanceToolStripMenuItem.Name = "startSurveillanceToolStripMenuItem"
            Me.startSurveillanceToolStripMenuItem.Size = New System.Drawing.Size(186, 22)
            Me.startSurveillanceToolStripMenuItem.Text = "&Start surveillance"
            '
            'stopSurveillanceToolStripMenuItem
            '
            Me.stopSurveillanceToolStripMenuItem.Enabled = False
            Me.stopSurveillanceToolStripMenuItem.Name = "stopSurveillanceToolStripMenuItem"
            Me.stopSurveillanceToolStripMenuItem.Size = New System.Drawing.Size(186, 22)
            Me.stopSurveillanceToolStripMenuItem.Text = "S&top surveillance"
            '
            'toolStripSeparator3
            '
            Me.toolStripSeparator3.Name = "toolStripSeparator3"
            Me.toolStripSeparator3.Size = New System.Drawing.Size(183, 6)
            '
            'enrollFromImagesToolStripMenuItem
            '
            Me.enrollFromImagesToolStripMenuItem.Name = "enrollFromImagesToolStripMenuItem"
            Me.enrollFromImagesToolStripMenuItem.Size = New System.Drawing.Size(186, 22)
            Me.enrollFromImagesToolStripMenuItem.Text = "&Enroll From Image(s)"
            '
            'enrollFromDirectoryToolStripMenuItem
            '
            Me.enrollFromDirectoryToolStripMenuItem.Name = "enrollFromDirectoryToolStripMenuItem"
            Me.enrollFromDirectoryToolStripMenuItem.Size = New System.Drawing.Size(186, 22)
            Me.enrollFromDirectoryToolStripMenuItem.Text = "Enroll From &Directory"
            '
            'toolStripSeparator2
            '
            Me.toolStripSeparator2.Name = "toolStripSeparator2"
            Me.toolStripSeparator2.Size = New System.Drawing.Size(183, 6)
            '
            'exitToolStripMenuItem
            '
            Me.exitToolStripMenuItem.Name = "exitToolStripMenuItem"
            Me.exitToolStripMenuItem.ShortcutKeys = CType((System.Windows.Forms.Keys.Alt Or System.Windows.Forms.Keys.F4), System.Windows.Forms.Keys)
            Me.exitToolStripMenuItem.Size = New System.Drawing.Size(186, 22)
            Me.exitToolStripMenuItem.Text = "E&xit"
            '
            'toolsToolStripMenuItem
            '
            Me.toolsToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.settingsToolStripMenuItem, Me.toolStripSeparator1, Me.watchListToolStripMenuItem, Me.clearWatchListToolStripMenuItem})
            Me.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem"
            Me.toolsToolStripMenuItem.Size = New System.Drawing.Size(48, 20)
            Me.toolsToolStripMenuItem.Text = "&Tools"
            '
            'settingsToolStripMenuItem
            '
            Me.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem"
            Me.settingsToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.settingsToolStripMenuItem.Text = "&Settings..."
            '
            'toolStripSeparator1
            '
            Me.toolStripSeparator1.Name = "toolStripSeparator1"
            Me.toolStripSeparator1.Size = New System.Drawing.Size(156, 6)
            '
            'watchListToolStripMenuItem
            '
            Me.watchListToolStripMenuItem.Name = "watchListToolStripMenuItem"
            Me.watchListToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.watchListToolStripMenuItem.Text = "&Watch List..."
            '
            'clearWatchListToolStripMenuItem
            '
            Me.clearWatchListToolStripMenuItem.Name = "clearWatchListToolStripMenuItem"
            Me.clearWatchListToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.clearWatchListToolStripMenuItem.Text = "&Clear Watch List"
            '
            'helpToolStripMenuItem
            '
            Me.helpToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.aboutToolStripMenuItem})
            Me.helpToolStripMenuItem.Name = "helpToolStripMenuItem"
            Me.helpToolStripMenuItem.Size = New System.Drawing.Size(44, 20)
            Me.helpToolStripMenuItem.Text = "&Help"
            '
            'aboutToolStripMenuItem
            '
            Me.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem"
            Me.aboutToolStripMenuItem.Size = New System.Drawing.Size(107, 22)
            Me.aboutToolStripMenuItem.Text = "&About"
            '
            'treeView
            '
            Me.treeView.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                        Or System.Windows.Forms.AnchorStyles.Left) _
                        Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.treeView.Location = New System.Drawing.Point(371, 25)
            Me.treeView.Name = "treeView"
            Me.treeView.Size = New System.Drawing.Size(137, 429)
            Me.treeView.TabIndex = 7
            Me.treeView.Visible = False
            '
            'contextMnuStrip
            '
            Me.contextMnuStrip.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.zoomToFitToolStripMenuItem, Me.zoomTo50ToolStripMenuItem, Me.zoom100ToolStripMenuItem, Me.zoom200ToolStripMenuItem, Me.removeToolStripMenuItem})
            Me.contextMnuStrip.Name = "contextMenuStrip"
            Me.contextMnuStrip.Size = New System.Drawing.Size(160, 114)
            '
            'zoomToFitToolStripMenuItem
            '
            Me.zoomToFitToolStripMenuItem.Name = "zoomToFitToolStripMenuItem"
            Me.zoomToFitToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.zoomToFitToolStripMenuItem.Text = "Zoom to Fit"
            '
            'zoomTo50ToolStripMenuItem
            '
            Me.zoomTo50ToolStripMenuItem.Name = "zoomTo50ToolStripMenuItem"
            Me.zoomTo50ToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.zoomTo50ToolStripMenuItem.Text = "Zoom 50%"
            '
            'zoom100ToolStripMenuItem
            '
            Me.zoom100ToolStripMenuItem.Name = "zoom100ToolStripMenuItem"
            Me.zoom100ToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.zoom100ToolStripMenuItem.Text = "Zoom 100%"
            '
            'zoom200ToolStripMenuItem
            '
            Me.zoom200ToolStripMenuItem.Name = "zoom200ToolStripMenuItem"
            Me.zoom200ToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.zoom200ToolStripMenuItem.Text = "Zoom 200%"
            '
            'removeToolStripMenuItem
            '
            Me.removeToolStripMenuItem.Name = "removeToolStripMenuItem"
            Me.removeToolStripMenuItem.Size = New System.Drawing.Size(159, 22)
            Me.removeToolStripMenuItem.Text = "Remove camera"
            '
            'buttonAddToWatchList
            '
            Me.buttonAddToWatchList.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                        Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.buttonAddToWatchList.Enabled = False
            Me.buttonAddToWatchList.Location = New System.Drawing.Point(3, 3)
            Me.buttonAddToWatchList.Name = "buttonAddToWatchList"
            Me.buttonAddToWatchList.Size = New System.Drawing.Size(87, 23)
            Me.buttonAddToWatchList.TabIndex = 5
            Me.buttonAddToWatchList.Text = "add template from selected node to watch list"
            Me.buttonAddToWatchList.UseVisualStyleBackColor = True
            Me.buttonAddToWatchList.Visible = False
            '
            'cmbTakePhoto
            '
            Me.cmbTakePhoto.BackgroundImage = CType(resources.GetObject("cmbTakePhoto.BackgroundImage"), System.Drawing.Image)
            Me.cmbTakePhoto.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
            Me.cmbTakePhoto.Location = New System.Drawing.Point(270, 446)
            Me.cmbTakePhoto.Name = "cmbTakePhoto"
            Me.cmbTakePhoto.Size = New System.Drawing.Size(111, 39)
            Me.cmbTakePhoto.TabIndex = 31
            Me.cmbTakePhoto.UseVisualStyleBackColor = True
            '
            'btnClearBlackList
            '
            Me.btnClearBlackList.Location = New System.Drawing.Point(478, 206)
            Me.btnClearBlackList.Name = "btnClearBlackList"
            Me.btnClearBlackList.Size = New System.Drawing.Size(93, 23)
            Me.btnClearBlackList.TabIndex = 32
            Me.btnClearBlackList.Text = "Clear BlackList"
            Me.btnClearBlackList.UseVisualStyleBackColor = True
            Me.btnClearBlackList.Visible = False
            '
            'nlViews
            '
            Me.nlViews.Dock = System.Windows.Forms.DockStyle.Fill
            Me.nlViews.Location = New System.Drawing.Point(0, 0)
            Me.nlViews.Name = "nlViews"
            Me.nlViews.Size = New System.Drawing.Size(650, 485)
            Me.nlViews.TabIndex = 4
            '
            'MainForm
            '
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.AutoSize = True
            Me.ClientSize = New System.Drawing.Size(650, 485)
            Me.ControlBox = False
            Me.Controls.Add(Me.btnClearBlackList)
            Me.Controls.Add(Me.mainMnuStrip)
            Me.Controls.Add(Me.label1)
            Me.Controls.Add(Me.buttonAddToWatchList)
            Me.Controls.Add(Me.cmbTakePhoto)
            Me.Controls.Add(Me.nlViews)
            Me.Controls.Add(Me.treeView)
            Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
            Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
            Me.MaximizeBox = False
            Me.MinimizeBox = False
            Me.Name = "MainForm"
            Me.Opacity = 0
            Me.ShowIcon = False
            Me.ShowInTaskbar = False
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
            Me.Text = "VRM FaceDetector"
            Me.mainMnuStrip.ResumeLayout(False)
            Me.mainMnuStrip.PerformLayout()
            Me.contextMnuStrip.ResumeLayout(False)
            Me.ResumeLayout(False)
            Me.PerformLayout()

        End Sub

#End Region

        Private toolTip1 As System.Windows.Forms.ToolTip
        Private openFileDialog As System.Windows.Forms.OpenFileDialog
        Private folderBrowserDialog As System.Windows.Forms.FolderBrowserDialog
        Friend WithEvents TimerEnrollImage As System.Windows.Forms.Timer
        Private WithEvents mainMnuStrip As System.Windows.Forms.MenuStrip
        Private WithEvents fileToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents chooseDeviceToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents startSurveillanceToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents stopSurveillanceToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents toolStripSeparator3 As System.Windows.Forms.ToolStripSeparator
        Private WithEvents enrollFromImagesToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents enrollFromDirectoryToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents toolStripSeparator2 As System.Windows.Forms.ToolStripSeparator
        Private WithEvents exitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents toolsToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents settingsToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents toolStripSeparator1 As System.Windows.Forms.ToolStripSeparator
        Private WithEvents watchListToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents clearWatchListToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents helpToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents aboutToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents label1 As System.Windows.Forms.Label
        Private WithEvents treeView As System.Windows.Forms.TreeView
        Private WithEvents contextMnuStrip As System.Windows.Forms.ContextMenuStrip
        Private WithEvents zoomToFitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents zoomTo50ToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents zoom100ToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents zoom200ToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents removeToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
        Private WithEvents buttonAddToWatchList As System.Windows.Forms.Button
        Friend WithEvents cmbTakePhoto As System.Windows.Forms.Button
        Private WithEvents nlViews As Neurotec.Samples.Forms.ViewsSizer
        Friend WithEvents btnClearBlackList As System.Windows.Forms.Button
    End Class
End Namespace
