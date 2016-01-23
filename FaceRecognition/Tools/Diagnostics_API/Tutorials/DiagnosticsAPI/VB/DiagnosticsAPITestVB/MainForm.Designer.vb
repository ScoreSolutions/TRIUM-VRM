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
		Me.components = New System.ComponentModel.Container()
		Dim resources As New System.ComponentModel.ComponentResourceManager(GetType(MainForm))
		Me.btnGenerate = New System.Windows.Forms.Button()
		Me.btnClose = New System.Windows.Forms.Button()
		Me.label1 = New System.Windows.Forms.Label()
		Me.cbProducts = New System.Windows.Forms.ComboBox()
		Me.textBoxPath = New System.Windows.Forms.TextBox()
		Me.buttonPath = New System.Windows.Forms.Button()
		Me.toolTip1 = New System.Windows.Forms.ToolTip(Me.components)
		Me.folderBrowserDialog = New System.Windows.Forms.FolderBrowserDialog()
		Me.richTextBox1 = New System.Windows.Forms.RichTextBox()
		Me.SuspendLayout()
		' 
		' btnGenerate
		' 
		Me.btnGenerate.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.btnGenerate.Location = New System.Drawing.Point(598, 427)
		Me.btnGenerate.Name = "btnGenerate"
		Me.btnGenerate.Size = New System.Drawing.Size(75, 23)
		Me.btnGenerate.TabIndex = 3
		Me.btnGenerate.Text = "&Generate"
		Me.btnGenerate.UseVisualStyleBackColor = True
		'			Me.btnGenerate.Click += New System.EventHandler(Me.btnGenerate_Click);
		' 
		' btnClose
		' 
		Me.btnClose.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.btnClose.Location = New System.Drawing.Point(679, 427)
		Me.btnClose.Name = "btnClose"
		Me.btnClose.Size = New System.Drawing.Size(75, 23)
		Me.btnClose.TabIndex = 4
		Me.btnClose.Text = "&Close"
		Me.btnClose.UseVisualStyleBackColor = True
		'			Me.btnClose.Click += New System.EventHandler(Me.btnClose_Click);
		' 
		' label1
		' 
		Me.label1.AutoSize = True
		Me.label1.Location = New System.Drawing.Point(9, 9)
		Me.label1.Name = "label1"
		Me.label1.Size = New System.Drawing.Size(47, 13)
		Me.label1.TabIndex = 0
		Me.label1.Text = "Product:"
		' 
		' cbProducts
		' 
		Me.cbProducts.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
		Me.cbProducts.FormattingEnabled = True
		Me.cbProducts.Location = New System.Drawing.Point(62, 6)
		Me.cbProducts.Name = "cbProducts"
		Me.cbProducts.Size = New System.Drawing.Size(121, 21)
		Me.cbProducts.TabIndex = 1
		' 
		' textBoxPath
		' 
		Me.textBoxPath.Anchor = (CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.textBoxPath.Location = New System.Drawing.Point(62, 429)
		Me.textBoxPath.Name = "textBoxPath"
		Me.textBoxPath.Size = New System.Drawing.Size(530, 20)
		Me.textBoxPath.TabIndex = 6
		Me.toolTip1.SetToolTip(Me.textBoxPath, "Folder for methods: GetComLibsAndFPSmmContents, GetRegisteredComponents. Folder t" & "o look in. (if null or empty, then current directory will be used).")
		' 
		' buttonPath
		' 
		Me.buttonPath.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.buttonPath.Image = (CType(resources.GetObject("buttonPath.Image"), System.Drawing.Image))
		Me.buttonPath.Location = New System.Drawing.Point(12, 426)
		Me.buttonPath.Name = "buttonPath"
		Me.buttonPath.Size = New System.Drawing.Size(43, 23)
		Me.buttonPath.TabIndex = 7
		Me.buttonPath.UseVisualStyleBackColor = True
		'			Me.buttonPath.Click += New System.EventHandler(Me.buttonPath_Click);
		' 
		' richTextBox1
		' 
		Me.richTextBox1.Anchor = (CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) Or System.Windows.Forms.AnchorStyles.Left) Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.richTextBox1.Location = New System.Drawing.Point(12, 33)
		Me.richTextBox1.Name = "richTextBox1"
		Me.richTextBox1.ReadOnly = True
		Me.richTextBox1.Size = New System.Drawing.Size(740, 387)
		Me.richTextBox1.TabIndex = 8
		Me.richTextBox1.Text = ""
		' 
		' MainForm
		' 
		Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0F, 13.0F)
		Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
		Me.ClientSize = New System.Drawing.Size(764, 459)
		Me.Controls.Add(Me.richTextBox1)
		Me.Controls.Add(Me.buttonPath)
		Me.Controls.Add(Me.textBoxPath)
		Me.Controls.Add(Me.cbProducts)
		Me.Controls.Add(Me.label1)
		Me.Controls.Add(Me.btnClose)
		Me.Controls.Add(Me.btnGenerate)
		Me.Icon = (CType(resources.GetObject("$this.Icon"), System.Drawing.Icon))
		Me.MinimumSize = New System.Drawing.Size(200, 174)
		Me.Name = "MainForm"
		Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
		Me.Text = "Generate Diagnostic Tutorial"
		'			Me.Load += New System.EventHandler(Me.MainForm_Load);
		Me.ResumeLayout(False)
		Me.PerformLayout()

	End Sub

#End Region

	Private WithEvents btnGenerate As System.Windows.Forms.Button
	Private WithEvents btnClose As System.Windows.Forms.Button
	Private label1 As System.Windows.Forms.Label
	Private cbProducts As System.Windows.Forms.ComboBox
	Private textBoxPath As System.Windows.Forms.TextBox
	Private WithEvents buttonPath As System.Windows.Forms.Button
	Private toolTip1 As System.Windows.Forms.ToolTip
	Private folderBrowserDialog As System.Windows.Forms.FolderBrowserDialog
	Private richTextBox1 As System.Windows.Forms.RichTextBox
End Class


