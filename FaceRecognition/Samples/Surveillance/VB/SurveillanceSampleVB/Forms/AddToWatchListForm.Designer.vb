Imports Microsoft.VisualBasic
Imports System
Namespace Forms
	Partial Public Class AddToWatchListForm
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
			Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(AddToWatchListForm))
			Me.nlView = New Neurotec.Biometrics.Gui.NLView
			Me.textBoxSubjectId = New System.Windows.Forms.TextBox
			Me.buttonOK = New System.Windows.Forms.Button
			Me.buttonCancel = New System.Windows.Forms.Button
			Me.labelSubjectId = New System.Windows.Forms.Label
			Me.SuspendLayout()
			'
			'nlView
			'
			Me.nlView.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
						Or System.Windows.Forms.AnchorStyles.Left) _
						Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
			Me.nlView.AutoScroll = True
			Me.nlView.AutoScrollMinSize = New System.Drawing.Size(1, 1)
			Me.nlView.DetectionDetails = Nothing
			Me.nlView.FaceIds = Nothing
			Me.nlView.Image = Nothing
			Me.nlView.Location = New System.Drawing.Point(12, 12)
			Me.nlView.Name = "nlView"
			Me.nlView.Size = New System.Drawing.Size(628, 387)
			Me.nlView.TabIndex = 0
			'
			'textBoxSubjectId
			'
			Me.textBoxSubjectId.Anchor = CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) _
						Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
			Me.textBoxSubjectId.Location = New System.Drawing.Point(196, 405)
			Me.textBoxSubjectId.Name = "textBoxSubjectId"
			Me.textBoxSubjectId.Size = New System.Drawing.Size(444, 20)
			Me.textBoxSubjectId.TabIndex = 1
			'
			'buttonOK
			'
			Me.buttonOK.Anchor = CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
			Me.buttonOK.DialogResult = System.Windows.Forms.DialogResult.OK
			Me.buttonOK.Location = New System.Drawing.Point(484, 431)
			Me.buttonOK.Name = "buttonOK"
			Me.buttonOK.Size = New System.Drawing.Size(75, 23)
			Me.buttonOK.TabIndex = 2
			Me.buttonOK.Text = "&OK"
			Me.buttonOK.UseVisualStyleBackColor = True
			'
			'buttonCancel
			'
			Me.buttonCancel.Anchor = CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles)
			Me.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel
			Me.buttonCancel.Location = New System.Drawing.Point(565, 431)
			Me.buttonCancel.Name = "buttonCancel"
			Me.buttonCancel.Size = New System.Drawing.Size(75, 23)
			Me.buttonCancel.TabIndex = 3
			Me.buttonCancel.Text = "&Cancel"
			Me.buttonCancel.UseVisualStyleBackColor = True
			'
			'labelSubjectId
			'
			Me.labelSubjectId.Anchor = CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles)
			Me.labelSubjectId.AutoSize = True
			Me.labelSubjectId.Location = New System.Drawing.Point(12, 408)
			Me.labelSubjectId.Name = "labelSubjectId"
			Me.labelSubjectId.Size = New System.Drawing.Size(178, 13)
			Me.labelSubjectId.TabIndex = 4
			Me.labelSubjectId.Text = "Enter subject id for the located face:"
			'
			'AddToWatchListForm
			'
			Me.AcceptButton = Me.buttonOK
			Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
			Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
			Me.CancelButton = Me.buttonCancel
			Me.ClientSize = New System.Drawing.Size(652, 466)
			Me.Controls.Add(Me.labelSubjectId)
			Me.Controls.Add(Me.buttonCancel)
			Me.Controls.Add(Me.buttonOK)
			Me.Controls.Add(Me.textBoxSubjectId)
			Me.Controls.Add(Me.nlView)
			Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
			Me.Name = "AddToWatchListForm"
			Me.Text = "Add To Watch List"
			Me.ResumeLayout(False)
			Me.PerformLayout()

		End Sub

#End Region

		Private nlView As Neurotec.Biometrics.Gui.NLView
		Private textBoxSubjectId As System.Windows.Forms.TextBox
		Private buttonOK As System.Windows.Forms.Button
		Private buttonCancel As System.Windows.Forms.Button
		Private labelSubjectId As System.Windows.Forms.Label
	End Class
End Namespace