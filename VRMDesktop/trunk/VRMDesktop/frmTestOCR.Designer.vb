<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmTestOCR
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmTestOCR))
        Me.pbCameraPreview = New System.Windows.Forms.PictureBox()
        Me.btnCapture = New System.Windows.Forms.Button()
        Me.lblDriveLicenseID = New System.Windows.Forms.Label()
        Me.pbDisplay = New System.Windows.Forms.PictureBox()
        Me.Label1 = New System.Windows.Forms.Label()
        CType(Me.pbCameraPreview, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbDisplay, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'pbCameraPreview
        '
        Me.pbCameraPreview.Location = New System.Drawing.Point(3, 12)
        Me.pbCameraPreview.Name = "pbCameraPreview"
        Me.pbCameraPreview.Size = New System.Drawing.Size(320, 240)
        Me.pbCameraPreview.TabIndex = 1
        Me.pbCameraPreview.TabStop = False
        '
        'btnCapture
        '
        Me.btnCapture.BackgroundImage = CType(resources.GetObject("btnCapture.BackgroundImage"), System.Drawing.Image)
        Me.btnCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch
        Me.btnCapture.Location = New System.Drawing.Point(92, 258)
        Me.btnCapture.Name = "btnCapture"
        Me.btnCapture.Size = New System.Drawing.Size(111, 39)
        Me.btnCapture.TabIndex = 27
        Me.btnCapture.UseVisualStyleBackColor = True
        '
        'lblDriveLicenseID
        '
        Me.lblDriveLicenseID.AutoSize = True
        Me.lblDriveLicenseID.Location = New System.Drawing.Point(415, 13)
        Me.lblDriveLicenseID.Name = "lblDriveLicenseID"
        Me.lblDriveLicenseID.Size = New System.Drawing.Size(0, 13)
        Me.lblDriveLicenseID.TabIndex = 28
        '
        'pbDisplay
        '
        Me.pbDisplay.Location = New System.Drawing.Point(2, 12)
        Me.pbDisplay.Name = "pbDisplay"
        Me.pbDisplay.Size = New System.Drawing.Size(320, 240)
        Me.pbDisplay.TabIndex = 29
        Me.pbDisplay.TabStop = False
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(375, 219)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(39, 13)
        Me.Label1.TabIndex = 30
        Me.Label1.Text = "Label1"
        '
        'frmTestOCR
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(815, 364)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.lblDriveLicenseID)
        Me.Controls.Add(Me.btnCapture)
        Me.Controls.Add(Me.pbCameraPreview)
        Me.Controls.Add(Me.pbDisplay)
        Me.Name = "frmTestOCR"
        Me.Text = "frmTestOCR"
        CType(Me.pbCameraPreview, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbDisplay, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents pbCameraPreview As System.Windows.Forms.PictureBox
    Friend WithEvents btnCapture As System.Windows.Forms.Button
    Friend WithEvents lblDriveLicenseID As System.Windows.Forms.Label
    Friend WithEvents pbDisplay As System.Windows.Forms.PictureBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
End Class
