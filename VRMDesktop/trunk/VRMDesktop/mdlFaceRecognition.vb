Imports System.IO
Imports System.Runtime.InteropServices


Module mdlFaceRecognition

    Public Function StartFormFaceRecognition(PathFile As String, txtID As String) As Image
        Dim ret As Image

        Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
        Try
            ini.Section = "FaceRecognition"
            Dim SurveillanceSamplePath As String = ini.ReadString("SurveillanceSamplePath")

            Try
                If File.Exists(SurveillanceSamplePath & "\IsBlacklist.txt") = True Then
                    File.SetAttributes(SurveillanceSamplePath & "\IsBlacklist.txt", IO.FileAttributes.Normal)
                    File.Delete(SurveillanceSamplePath & "\IsBlacklist.txt")
                End If
            Catch ex As Exception

            End Try

            Try
                If File.Exists(SurveillanceSamplePath & "\" & txtID & ".jpg") = True Then
                    File.SetAttributes(SurveillanceSamplePath & "\" & txtID & ".jpg", FileAttributes.Normal)
                    File.Delete(SurveillanceSamplePath & "\" & txtID & ".jpg")
                End If
            Catch ex As Exception

            End Try
            WritePathImageFile(SurveillanceSamplePath, PathFile)

            Dim p As New Process
            p.StartInfo.FileName = SurveillanceSamplePath & "VRMFaceDetector.exe"
            p.StartInfo.WindowStyle = ProcessWindowStyle.Maximized
            p.Start()
            p.WaitForExit()

            If File.Exists(SurveillanceSamplePath & "\" & txtID & ".jpg") = True Then
                If Directory.Exists(Application.StartupPath & "\TempCaptureImage\") = False Then
                    Directory.CreateDirectory(Application.StartupPath & "\TempCaptureImage\")
                End If

                File.Copy(SurveillanceSamplePath & "\" & txtID & ".jpg", Application.StartupPath & "\TempCaptureImage\" & txtID & ".jpg")
                File.SetAttributes(SurveillanceSamplePath & "\" & txtID & ".jpg", FileAttributes.Normal)
                File.Delete(SurveillanceSamplePath & "\" & txtID & ".jpg")
            End If

            If IO.File.Exists(SurveillanceSamplePath & "\IsBlacklist.txt") = True Then
                ret = Image.FromFile(IO.File.ReadAllText(SurveillanceSamplePath & "\IsBlacklist.txt"))
            End If
            'Return Textfile Data
        Catch ex As Exception

        End Try
        ini = Nothing

        Return ret
    End Function

    Private Sub WritePathImageFile(SurveillanceSamplePath As String, PathFile As String)
        Try
            Dim txtFile As New IO.StreamWriter(SurveillanceSamplePath & "/PathImageFile.txt", False, System.Text.Encoding.UTF8, PathFile.Length)
            With txtFile
                .Write(PathFile)
                .Close()
            End With
        Catch ex As Exception

        End Try
    End Sub

    Public Sub WriteIDFile(SurveillanceSamplePath As String, PathFile As String)
        Try
            Dim txtFile As New IO.StreamWriter(SurveillanceSamplePath & "/ID.txt", False, System.Text.Encoding.UTF8, PathFile.Length)
            With txtFile
                .Write(PathFile)
                .Close()
            End With
        Catch ex As Exception

        End Try
    End Sub

    Public Sub WriteCntFile(SurveillanceSamplePath As String, PathFile As String)
        Try
            Dim txtFile As New IO.StreamWriter(SurveillanceSamplePath & "/cnt.txt", False, System.Text.Encoding.UTF8, PathFile.Length)
            With txtFile
                .Write(PathFile)
                .Close()
            End With
        Catch ex As Exception

        End Try
    End Sub
End Module
