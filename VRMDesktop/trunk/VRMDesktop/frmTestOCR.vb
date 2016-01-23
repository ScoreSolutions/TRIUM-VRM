Imports System.IO
Public Class frmTestOCR
    Private webcam As WebCam
    Dim Path As String = ""
    Dim PathFile As String = ""

    Private Sub frmTestOCR_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        webcam.Stop()
    End Sub

    Private Sub frmTestOCR_Shown(sender As Object, e As EventArgs) Handles Me.Shown
        pbCameraPreview.Image = Image.FromFile(Application.StartupPath & "\TempOCRPath\25571202112013137.JPG")
        pbCameraPreview.BackgroundImageLayout = ImageLayout.Stretch

        'Try
        '    webcam = New WebCam()
        '    webcam.InitializeWebCam(pbCameraPreview)
        '    webcam.Start()
        '    webcam.CaptureWidth(320)
        '    webcam.CaptureHeight(240)

        '    Path = Application.StartupPath & "\TempOCRPath\"
        '    If Directory.Exists(Path) = True Then
        '        Try
        '            Directory.Delete(Path, True)
        '        Catch ex As Exception

        '        End Try
        '    End If
        'Catch ex As Exception

        'End Try
    End Sub

    Private Sub btnCapture_Click(sender As Object, e As EventArgs) Handles btnCapture.Click
        'Dim ocr As New clsOCR
        'Dim ret As String = ocr.OCRZoneProcess(Application.StartupPath & "\TempOCRPath\25571202112013137.JPG", 118, 42, 14, 70) '188 56
        'lblDriveLicenseID.Text = ret


        pbCameraPreview.Image = Image.FromFile("D:\MyProject\TRIUM-VRM\VRMDesktop\trunk\VRMDesktop\bin\Debug\TempOCRFile\3410101141069.jpg")

        'If pbCameraPreview.Image Is Nothing Then
        '    MessageBox.Show("No Image Capture")
        '    Exit Sub
        'End If

        'webcam.Stop()

        'Dim FileName As String = DateTime.Now.ToString("yyyyMMddhhmmssfff") & ".JPG"
        'Dim PathFile As String = Path & FileName
        'Try
        '    If Directory.Exists(Path) = False Then
        '        Directory.CreateDirectory(Path)
        '    End If

        '    pbCameraPreview.Image.Save(PathFile, System.Drawing.Imaging.ImageFormat.Jpeg)

        '    If IO.File.Exists(PathFile) = True Then
        '        Threading.Thread.Sleep(1000)
        '        pbDisplay.BackgroundImageLayout = ImageLayout.Stretch
        '        pbDisplay.Image = Image.FromFile(PathFile)
        '        pbDisplay.BringToFront()
        '        Application.DoEvents()
        '    End If
        'Catch ex As Exception

        'End Try
    End Sub

    Private Sub pbCameraPreview_Click(sender As Object, e As EventArgs) Handles pbCameraPreview.Click

    End Sub

    Private Sub pbCameraPreview_MouseDown(sender As Object, e As MouseEventArgs) Handles pbCameraPreview.MouseDown
        Label1.Text = e.X & "," & e.Y
    End Sub
End Class