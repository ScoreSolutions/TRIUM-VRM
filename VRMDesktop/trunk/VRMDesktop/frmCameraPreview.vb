Imports System.IO
Public Class frmCameraPreview
    Private webcam As WebCam

    Public IDCardNo As String = ""
    Dim FileName As String = ""
    Dim Path As String = ""
    Public PathFile As String = ""

    Private Sub frmCameraPreview_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        'Me.DialogResult = Windows.Forms.DialogResult.Cancel
        webcam.Stop()
    End Sub

    Private Sub frmCameraPreview_Load(sender As Object, e As EventArgs) Handles Me.Load
        Try
            webcam = New WebCam()
            webcam.InitializeWebCam(pbCameraPreview)
            webcam.Start()
            webcam.CaptureHeight(480)
            webcam.CaptureWidth(640)

            Path = Application.StartupPath & "\TempCaptureImage\"
            If Directory.Exists(Path) = True Then
                Try
                    Directory.Delete(Path, True)
                Catch ex As Exception

                End Try
            End If
        Catch ex As Exception

        End Try
    End Sub

    Private Sub btnSave_Click(sender As Object, e As EventArgs) Handles btnSave.Click
        webcam.Stop()
        Me.DialogResult = Windows.Forms.DialogResult.OK
    End Sub

    Dim _isCapture As Boolean = False
    Private Sub btnCapture_Click(sender As Object, e As EventArgs) Handles btnCapture.Click
        If pbCameraPreview.Image Is Nothing Then
            MessageBox.Show("No Image Capture")
            Exit Sub
        End If


        _isCapture = True
        btnSave.Visible = True
        btnReCapture.Visible = True
        btnCapture.Visible = False
        webcam.Stop()

        FileName = IDCardNo & ".jpg"

        If Directory.Exists(Path) = False Then
            Directory.CreateDirectory(Path)
        End If

        PathFile = Path & FileName
        If IO.File.Exists(PathFile) = True Then
            Try
                File.SetAttributes(PathFile, FileAttributes.Normal)
                File.Delete(PathFile)
            Catch ex As Exception

            End Try
        End If

        Try
            pbCameraPreview.Image.Save(PathFile, System.Drawing.Imaging.ImageFormat.Jpeg)

            If IO.File.Exists(PathFile) = True Then
                Threading.Thread.Sleep(1000)
                Dim bipimag As New MemoryStream(File.ReadAllBytes(PathFile))
                Dim imag As Image = New Bitmap(bipimag)
                pbDisplay.BackgroundImageLayout = ImageLayout.Stretch
                pbDisplay.Image = imag
                pbDisplay.BringToFront()
                Application.DoEvents()
            End If
        Catch ex As Exception

        End Try
    End Sub

    Private Sub btnReCapture_Click(sender As Object, e As EventArgs) Handles btnReCapture.Click
        webcam.Start()
        btnCapture.Visible = True
        btnReCapture.Visible = False
        btnSave.Visible = False

        pbCameraPreview.BringToFront()
        'pbDisplay.BringToFront()

        Try
            File.SetAttributes(PathFile, FileAttributes.Normal)
            File.Delete(PathFile)
        Catch ex As Exception

        End Try
    End Sub
End Class