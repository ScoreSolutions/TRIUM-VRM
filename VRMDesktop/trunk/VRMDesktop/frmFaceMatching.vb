Imports System.IO
Imports Microsoft.Win32
Imports System
Imports System.Diagnostics
Imports System.Runtime.InteropServices
Imports System.Windows.Forms

Public Class frmFaceMatching
    Public PathFile As String = ""
    Private webcam As WebCam
    Public Path As String = ""
    Public FileName As String = ""
    Public IDCardNo As String = ""



    Private Sub frmFaceMatching_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        webcam.Stop()
    End Sub

    Private Sub frmFaceMatching_Load(sender As Object, e As EventArgs) Handles Me.Load


        Try
            webcam = New WebCam()
            webcam.InitializeWebCam(pbPreviewFaceFromCamera)
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

    Private Sub btnCapture_Click(sender As Object, e As EventArgs) Handles btnCapture.Click
        If pbPreviewFaceFromCamera.Image Is Nothing Then
            MessageBox.Show("No Image Capture")
            Exit Sub
        End If



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
            pbPreviewFaceFromCamera.Image.Save(PathFile, System.Drawing.Imaging.ImageFormat.Jpeg)
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

    Private Sub btnSave_Click(sender As Object, e As EventArgs) Handles btnSave.Click
        webcam.Stop()
        Me.DialogResult = Windows.Forms.DialogResult.OK
    End Sub

    Private Sub btnReCapture_Click(sender As Object, e As EventArgs) Handles btnReCapture.Click
        webcam.Start()
        btnCapture.Visible = True
        btnReCapture.Visible = False
        btnSave.Visible = False

        pbPreviewFaceFromCamera.BringToFront()
        Try
            File.SetAttributes(PathFile, FileAttributes.Normal)
            File.Delete(PathFile)
        Catch ex As Exception

        End Try
    End Sub





    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        '    mdlFaceRecognition.StartFaceMatch()
    End Sub
End Class