Imports System
Imports System.IO
Imports System.Linq
Imports System.Text
Imports System.Collections.Generic
Imports WebCam_Capture

'Design by Pongsakorn Poosankam
Class WebCam
    Private webcam As WebCamCapture
    Private _FrameImage As System.Windows.Forms.PictureBox
    Private FrameNumber As Integer = 30

    Public Sub InitializeWebCam(ByRef ImageControl As System.Windows.Forms.PictureBox)
        webcam = New WebCamCapture()
        webcam.FrameNumber = CULng((0))
        webcam.TimeToCapture_milliseconds = FrameNumber
        AddHandler webcam.ImageCaptured, AddressOf webcam_ImageCaptured
        _FrameImage = ImageControl
    End Sub


    Public Sub CaptureWidth(ByVal Width As Integer)
        webcam.CaptureWidth = Width
    End Sub

    Public Sub CaptureHeight(ByVal Height As Integer)
        webcam.CaptureHeight = Height
    End Sub

    Private Sub webcam_ImageCaptured(ByVal source As Object, ByVal e As WebcamEventArgs)
        Try
            _FrameImage.Image = e.WebCamImage
            '_FrameImage.Image.Save("D:\TemeImage.jpg")
            'Application.DoEvents()
        Catch ex As Exception

        End Try
    End Sub

    Public Sub Start()
        webcam.TimeToCapture_milliseconds = FrameNumber
        webcam.Start()
    End Sub

    Public Sub [Stop]()
        webcam.[Stop]()
    End Sub

    Public Sub [Continue]()
        ' change the capture time frame
        webcam.TimeToCapture_milliseconds = FrameNumber

        ' resume the video capture from the stop
        webcam.Start()
    End Sub

    'Public Sub ResolutionSetting()
    '    webcam.Config()
    'End Sub

    'Public Sub AdvanceSetting()
    '    webcam.Config2()
    'End Sub

    Public ReadOnly Property GetImage As Image
        Get
            Return _FrameImage.Image.Clone
        End Get
    End Property

    Public ReadOnly Property LoadDevideList As DataTable
        Get
            webcam = New WebCamCapture()
            Return webcam.LoadDeviceList()
        End Get
    End Property

End Class

