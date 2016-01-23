<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmCameraPreview
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmCameraPreview))
        Me.pbCameraPreview = New System.Windows.Forms.PictureBox()
        Me.btnSave = New System.Windows.Forms.Button()
        Me.btnReCapture = New System.Windows.Forms.Button()
        Me.btnCapture = New System.Windows.Forms.Button()
        Me.pbDisplay = New System.Windows.Forms.PictureBox()
        CType(Me.pbCameraPreview, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbDisplay, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'pbCameraPreview
        '
        Me.pbCameraPreview.Location = New System.Drawing.Point(12, 12)
        Me.pbCameraPreview.Name = "pbCameraPreview"
        Me.pbCameraPreview.Size = New System.Drawing.Size(640, 480)
        Me.pbCameraPreview.TabIndex = 0
        Me.pbCameraPreview.TabStop = False
        '
        'btnSave
        '
        Me.btnSave.BackgroundImage = CType(resources.GetObject("btnSave.BackgroundImage"), System.Drawing.Image)
        Me.btnSave.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnSave.Location = New System.Drawing.Point(222, 502)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(111, 39)
        Me.btnSave.TabIndex = 25
        Me.btnSave.UseVisualStyleBackColor = True
        Me.btnSave.Visible = False
        '
        'btnReCapture
        '
        Me.btnReCapture.BackgroundImage = CType(resources.GetObject("btnReCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnReCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnReCapture.Location = New System.Drawing.Point(339, 502)
        Me.btnReCapture.Name = "btnReCapture"
        Me.btnReCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnReCapture.TabIndex = 24
        Me.btnReCapture.UseVisualStyleBackColor = True
        Me.btnReCapture.Visible = False
        '
        'btnCapture
        '
        Me.btnCapture.BackgroundImage = CType(resources.GetObject("btnCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCapture.Location = New System.Drawing.Point(277, 502)
        Me.btnCapture.Name = "btnCapture"
        Me.btnCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnCapture.TabIndex = 26
        Me.btnCapture.UseVisualStyleBackColor = True
        '
        'pbDisplay
        '
        Me.pbDisplay.Location = New System.Drawing.Point(12, 12)
        Me.pbDisplay.Name = "pbDisplay"
        Me.pbDisplay.Size = New System.Drawing.Size(640, 480)
        Me.pbDisplay.TabIndex = 27
        Me.pbDisplay.TabStop = False
        '
        'frmCameraPreview
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(662, 556)
        Me.Controls.Add(Me.btnCapture)
        Me.Controls.Add(Me.btnSave)
        Me.Controls.Add(Me.btnReCapture)
        Me.Controls.Add(Me.pbCameraPreview)
        Me.Controls.Add(Me.pbDisplay)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Name = "frmCameraPreview"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
        Me.Text = "Change ID Picture"
        CType(Me.pbCameraPreview, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbDisplay, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents pbCameraPreview As System.Windows.Forms.PictureBox
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Friend WithEvents btnReCapture As System.Windows.Forms.Button
    Friend WithEvents btnCapture As System.Windows.Forms.Button
    Friend WithEvents pbDisplay As System.Windows.Forms.PictureBox
End Class
