Imports Microsoft.VisualBasic
Imports System

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
		Dim resources As New System.ComponentModel.ComponentResourceManager(GetType(MainForm))
		Me.splitContainer1 = New System.Windows.Forms.SplitContainer()
		Me.toolStrip1 = New System.Windows.Forms.ToolStrip()
		Me.tsbOpenReference = New System.Windows.Forms.ToolStripButton()
		Me.tsbOpenMultifaceImage = New System.Windows.Forms.ToolStripButton()
		Me.label1 = New System.Windows.Forms.Label()
		Me.label2 = New System.Windows.Forms.Label()
		Me.nlViewReference = New Neurotec.Biometrics.Gui.NLView()
		Me.nlViewMultiFace = New Neurotec.Biometrics.Gui.NLView()
		Me.openImageFileDlg = New System.Windows.Forms.OpenFileDialog()
		Me.splitContainer1.Panel1.SuspendLayout()
		Me.splitContainer1.Panel2.SuspendLayout()
		Me.splitContainer1.SuspendLayout()
		Me.toolStrip1.SuspendLayout()
		Me.SuspendLayout()
		' 
		' splitContainer1
		' 
		Me.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill
		Me.splitContainer1.Location = New System.Drawing.Point(0, 25)
		Me.splitContainer1.Name = "splitContainer1"
		' 
		' splitContainer1.Panel1
		' 
		Me.splitContainer1.Panel1.Controls.Add(Me.nlViewReference)
		Me.splitContainer1.Panel1.Controls.Add(Me.label1)
		' 
		' splitContainer1.Panel2
		' 
		Me.splitContainer1.Panel2.Controls.Add(Me.nlViewMultiFace)
		Me.splitContainer1.Panel2.Controls.Add(Me.label2)
		Me.splitContainer1.Size = New System.Drawing.Size(615, 367)
		Me.splitContainer1.SplitterDistance = 276
		Me.splitContainer1.TabIndex = 0
		' 
		' toolStrip1
		' 
		Me.toolStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsbOpenReference, Me.tsbOpenMultifaceImage})
		Me.toolStrip1.Location = New System.Drawing.Point(0, 0)
		Me.toolStrip1.Name = "toolStrip1"
		Me.toolStrip1.Size = New System.Drawing.Size(615, 25)
		Me.toolStrip1.TabIndex = 1
		Me.toolStrip1.Text = "toolStrip1"
		' 
		' tsbOpenReference
		' 
		Me.tsbOpenReference.Image = My.Resources.openHS
		Me.tsbOpenReference.ImageTransparentColor = System.Drawing.Color.Magenta
		Me.tsbOpenReference.Name = "tsbOpenReference"
		Me.tsbOpenReference.Size = New System.Drawing.Size(151, 22)
		Me.tsbOpenReference.Text = "Open Reference Image..."
		'			Me.tsbOpenReference.Click += New System.EventHandler(Me.tsbOpenReference_Click);
		' 
		' tsbOpenMultifaceImage
		' 
		Me.tsbOpenMultifaceImage.Image = My.Resources.openHS
		Me.tsbOpenMultifaceImage.ImageTransparentColor = System.Drawing.Color.Magenta
		Me.tsbOpenMultifaceImage.Name = "tsbOpenMultifaceImage"
		Me.tsbOpenMultifaceImage.Size = New System.Drawing.Size(144, 22)
		Me.tsbOpenMultifaceImage.Text = "Open Multiface Image..."
		'			Me.tsbOpenMultifaceImage.Click += New System.EventHandler(Me.tsbOpenMultifaceImage_Click);
		' 
		' label1
		' 
		Me.label1.BackColor = System.Drawing.SystemColors.ActiveCaption
		Me.label1.Dock = System.Windows.Forms.DockStyle.Top
		Me.label1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText
		Me.label1.Location = New System.Drawing.Point(0, 0)
		Me.label1.Name = "label1"
		Me.label1.Size = New System.Drawing.Size(276, 20)
		Me.label1.TabIndex = 0
		Me.label1.Text = "Reference Image"
		Me.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
		' 
		' label2
		' 
		Me.label2.BackColor = System.Drawing.SystemColors.ActiveCaption
		Me.label2.Dock = System.Windows.Forms.DockStyle.Top
		Me.label2.ForeColor = System.Drawing.SystemColors.ActiveCaptionText
		Me.label2.Location = New System.Drawing.Point(0, 0)
		Me.label2.Name = "label2"
		Me.label2.Size = New System.Drawing.Size(335, 20)
		Me.label2.TabIndex = 1
		Me.label2.Text = "Multiple Face Image"
		Me.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
		' 
		' nlViewReference
		' 
		Me.nlViewReference.AllowPanning = True
		Me.nlViewReference.AutoScroll = True
		Me.nlViewReference.Dock = System.Windows.Forms.DockStyle.Fill
		Me.nlViewReference.Image = Nothing
		Me.nlViewReference.Location = New System.Drawing.Point(0, 20)
		Me.nlViewReference.Name = "nlViewReference"
		Me.nlViewReference.Size = New System.Drawing.Size(276, 347)
		Me.nlViewReference.TabIndex = 1
		Me.nlViewReference.Zoom = 1.0F
		' 
		' nlViewMultiFace
		' 
		Me.nlViewMultiFace.AllowPanning = True
		Me.nlViewMultiFace.AutoScroll = True
		Me.nlViewMultiFace.AutoScrollMinSize = New System.Drawing.Size(1, 1)
		Me.nlViewMultiFace.Dock = System.Windows.Forms.DockStyle.Fill
		Me.nlViewMultiFace.FaceIds = Nothing
		Me.nlViewMultiFace.Image = Nothing
		Me.nlViewMultiFace.Location = New System.Drawing.Point(0, 20)
		Me.nlViewMultiFace.Name = "nlViewMultiFace"
		Me.nlViewMultiFace.Size = New System.Drawing.Size(335, 347)
		Me.nlViewMultiFace.TabIndex = 2
		Me.nlViewMultiFace.Zoom = 1.0F
		' 
		' openImageFileDlg
		' 
		Me.openImageFileDlg.Title = "Open Face Image"
		' 
		' MainForm
		' 
		Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0F, 13.0F)
		Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
		Me.ClientSize = New System.Drawing.Size(615, 392)
		Me.Controls.Add(Me.splitContainer1)
		Me.Controls.Add(Me.toolStrip1)
		Me.Icon = (CType(resources.GetObject("$this.Icon"), System.Drawing.Icon))
		Me.Name = "MainForm"
		Me.Text = "Multiple Face Matching Tutorial"
		'			Me.Load += New System.EventHandler(Me.MainForm_Load);
		'			Me.FormClosed += New System.Windows.Forms.FormClosedEventHandler(Me.MainForm_FormClosed);
		Me.splitContainer1.Panel1.ResumeLayout(False)
		Me.splitContainer1.Panel2.ResumeLayout(False)
		Me.splitContainer1.ResumeLayout(False)
		Me.toolStrip1.ResumeLayout(False)
		Me.toolStrip1.PerformLayout()
		Me.ResumeLayout(False)
		Me.PerformLayout()

	End Sub

#End Region

	Private splitContainer1 As System.Windows.Forms.SplitContainer
	Private toolStrip1 As System.Windows.Forms.ToolStrip
	Private WithEvents tsbOpenReference As System.Windows.Forms.ToolStripButton
	Private WithEvents tsbOpenMultifaceImage As System.Windows.Forms.ToolStripButton
	Private label1 As System.Windows.Forms.Label
	Private label2 As System.Windows.Forms.Label
	Private nlViewReference As Neurotec.Biometrics.Gui.NLView
	Private nlViewMultiFace As Neurotec.Biometrics.Gui.NLView
	Private openImageFileDlg As System.Windows.Forms.OpenFileDialog
End Class
