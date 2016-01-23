<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmFaceMatching
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmFaceMatching))
        Me.btnCapture = New System.Windows.Forms.Button()
        Me.pbPreviewFaceFromCamera = New System.Windows.Forms.PictureBox()
        Me.pbFaceFromID = New System.Windows.Forms.PictureBox()
        Me.btnSave = New System.Windows.Forms.Button()
        Me.btnReCapture = New System.Windows.Forms.Button()
        Me.pbDisplay = New System.Windows.Forms.PictureBox()
        Me.Button1 = New System.Windows.Forms.Button()
        CType(Me.pbPreviewFaceFromCamera, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbFaceFromID, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbDisplay, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'btnCapture
        '
        Me.btnCapture.BackgroundImage = CType(resources.GetObject("btnCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCapture.Location = New System.Drawing.Point(379, 349)
        Me.btnCapture.Name = "btnCapture"
        Me.btnCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnCapture.TabIndex = 27
        Me.btnCapture.UseVisualStyleBackColor = True
        '
        'pbPreviewFaceFromCamera
        '
        Me.pbPreviewFaceFromCamera.Location = New System.Drawing.Point(255, 45)
        Me.pbPreviewFaceFromCamera.Name = "pbPreviewFaceFromCamera"
        Me.pbPreviewFaceFromCamera.Size = New System.Drawing.Size(398, 298)
        Me.pbPreviewFaceFromCamera.TabIndex = 2
        Me.pbPreviewFaceFromCamera.TabStop = False
        '
        'pbFaceFromID
        '
        Me.pbFaceFromID.Location = New System.Drawing.Point(12, 45)
        Me.pbFaceFromID.Name = "pbFaceFromID"
        Me.pbFaceFromID.Size = New System.Drawing.Size(228, 298)
        Me.pbFaceFromID.TabIndex = 1
        Me.pbFaceFromID.TabStop = False
        '
        'btnSave
        '
        Me.btnSave.BackgroundImage = CType(resources.GetObject("btnSave.BackgroundImage"), System.Drawing.Image)
        Me.btnSave.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSave.Location = New System.Drawing.Point(321, 349)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(111, 39)
        Me.btnSave.TabIndex = 29
        Me.btnSave.UseVisualStyleBackColor = True
        Me.btnSave.Visible = False
        '
        'btnReCapture
        '
        Me.btnReCapture.BackgroundImage = CType(resources.GetObject("btnReCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnReCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnReCapture.Location = New System.Drawing.Point(438, 349)
        Me.btnReCapture.Name = "btnReCapture"
        Me.btnReCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnReCapture.TabIndex = 28
        Me.btnReCapture.UseVisualStyleBackColor = True
        Me.btnReCapture.Visible = False
        '
        'pbDisplay
        '
        Me.pbDisplay.Location = New System.Drawing.Point(255, 45)
        Me.pbDisplay.Name = "pbDisplay"
        Me.pbDisplay.Size = New System.Drawing.Size(398, 298)
        Me.pbDisplay.TabIndex = 30
        Me.pbDisplay.TabStop = False
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(165, 379)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 31
        Me.Button1.Text = "Button1"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'frmFaceMatching
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(669, 435)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.btnCapture)
        Me.Controls.Add(Me.btnSave)
        Me.Controls.Add(Me.btnReCapture)
        Me.Controls.Add(Me.pbPreviewFaceFromCamera)
        Me.Controls.Add(Me.pbFaceFromID)
        Me.Controls.Add(Me.pbDisplay)
        Me.Name = "frmFaceMatching"
        Me.Text = "frmFaceMatching"
        CType(Me.pbPreviewFaceFromCamera, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbFaceFromID, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbDisplay, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents pbFaceFromID As System.Windows.Forms.PictureBox
    Friend WithEvents pbPreviewFaceFromCamera As System.Windows.Forms.PictureBox
    Friend WithEvents btnCapture As System.Windows.Forms.Button
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Friend WithEvents btnReCapture As System.Windows.Forms.Button
    Friend WithEvents pbDisplay As System.Windows.Forms.PictureBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
End Class
