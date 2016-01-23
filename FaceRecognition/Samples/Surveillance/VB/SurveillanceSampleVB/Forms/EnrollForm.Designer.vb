Imports Microsoft.VisualBasic
Imports System
Namespace Forms
	Partial Public Class EnrollForm
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
            Me.btnAction = New System.Windows.Forms.Button
            Me.rtbLog = New System.Windows.Forms.RichTextBox
            Me.backgroundWorker = New System.ComponentModel.BackgroundWorker
            Me.SuspendLayout()
            '
            'btnAction
            '
            Me.btnAction.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.btnAction.Location = New System.Drawing.Point(355, 186)
            Me.btnAction.Name = "btnAction"
            Me.btnAction.Size = New System.Drawing.Size(75, 23)
            Me.btnAction.TabIndex = 0
            Me.btnAction.Text = "Stop"
            Me.btnAction.UseVisualStyleBackColor = True
            '
            'rtbLog
            '
            Me.rtbLog.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                        Or System.Windows.Forms.AnchorStyles.Left) _
                        Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.rtbLog.Location = New System.Drawing.Point(1, 2)
            Me.rtbLog.Name = "rtbLog"
            Me.rtbLog.ReadOnly = True
            Me.rtbLog.Size = New System.Drawing.Size(429, 178)
            Me.rtbLog.TabIndex = 1
            Me.rtbLog.Text = ""
            '
            'backgroundWorker
            '
            Me.backgroundWorker.WorkerSupportsCancellation = True
            '
            'EnrollForm
            '
            Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
            Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
            Me.ClientSize = New System.Drawing.Size(431, 211)
            Me.Controls.Add(Me.rtbLog)
            Me.Controls.Add(Me.btnAction)
            Me.MinimizeBox = False
            Me.Name = "EnrollForm"
            Me.Opacity = 0
            Me.ShowIcon = False
            Me.Text = "Enroll from images"
            Me.ResumeLayout(False)

        End Sub

#End Region

		Private WithEvents btnAction As System.Windows.Forms.Button
		Private rtbLog As System.Windows.Forms.RichTextBox
		Private WithEvents backgroundWorker As System.ComponentModel.BackgroundWorker
	End Class
End Namespace