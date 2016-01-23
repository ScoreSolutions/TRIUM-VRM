Imports System.IO
Public Class frmCardCapture
    Private webcam As WebCam

    Dim CardFileName As String = ""
    Dim Path As String = ""
    Dim PathFile As String = ""


    'OCR Parameter 
    Dim Inited As Boolean = False
    Dim gr As Graphics
    Dim NoEvents As Boolean
    Dim Frame As Rectangle
    Dim bmp As Image
    Dim Dwn As Boolean


    Private Sub frmCameraPreview_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        'Me.DialogResult = Windows.Forms.DialogResult.Cancel
        webcam.Stop()
    End Sub

    Private Sub frmCardCapture_Load(sender As Object, e As EventArgs) Handles Me.Load
        Try
            webcam = New WebCam()
            webcam.InitializeWebCam(pbCardPreview)
            webcam.Start()
            webcam.CaptureHeight(pbCardDisplay.Height)
            webcam.CaptureWidth(pbCardDisplay.Width)
            lblImagePath.Text = ""

            Path = Application.StartupPath & "\TempCaptureImage\"
            If Directory.Exists(Path) = True Then
                Try
                    Directory.Delete(Path, True)
                Catch ex As Exception

                End Try
            End If
        Catch ex As Exception

        End Try

        SetOCRObject()
    End Sub

    Private Sub btnSave_Click(sender As Object, e As EventArgs) Handles btnSave.Click
        webcam.Stop()
        pbCardPreview.BringToFront()
        pbCardPreview.Image = Nothing
        Me.DialogResult = Windows.Forms.DialogResult.OK
    End Sub


    Private Sub btnCardCapture_Click(sender As Object, e As EventArgs) Handles btnCardCapture.Click
        If pbCardPreview.Image Is Nothing Then
            MessageBox.Show("No Image Capture")
            Exit Sub
        End If


        btnSave.Visible = True
        btnCardReCapture.Visible = True
        btnRecognize.Visible = True
        btnCardCapture.Visible = False
        webcam.Stop()

        CardFileName = "Card_" & lblCardTypeID.Text & ".jpg"
        If Directory.Exists(Path) = False Then
            Directory.CreateDirectory(Path)
        End If

        PathFile = Path & CardFileName
        If IO.File.Exists(PathFile) = True Then
            Try
                File.SetAttributes(PathFile, FileAttributes.Normal)
                File.Delete(PathFile)
            Catch ex As Exception

            End Try
        End If

        Try
            pbCardPreview.Image.Save(PathFile, System.Drawing.Imaging.ImageFormat.Jpeg)

            If IO.File.Exists(PathFile) = True Then
                Threading.Thread.Sleep(1000)
                lblImagePath.Text = PathFile
                Dim bipimag As New MemoryStream(File.ReadAllBytes(PathFile))
                Dim imag As Image = New Bitmap(bipimag)
                pbCardDisplay.Image = imag
                pbCardDisplay.BackgroundImageLayout = ImageLayout.Stretch
                pbCardDisplay.BringToFront()
                Application.DoEvents()
            End If
        Catch ex As Exception

        End Try
        SetOCRImage()

        btnRecognize_Click(Nothing, Nothing)
    End Sub

    Private Sub btnReCapture_Click(sender As Object, e As EventArgs) Handles btnCardReCapture.Click
        webcam.Start()
        btnCardCapture.Visible = True
        btnCardReCapture.Visible = False
        btnRecognize.Visible = False
        btnSave.Visible = False

        pbCardPreview.BringToFront()
        'pbDisplay.BringToFront()

        Try
            File.SetAttributes(PathFile, FileAttributes.Normal)
            File.Delete(PathFile)
        Catch ex As Exception

        End Try
    End Sub

#Region "Card OCR"
    Private Sub SetOCRObject()
        CfgObj = 0
        OcrObj = 0
        ImgObj = 0

        'it is a good idea to create NSOCR instance here instead of creting it in the same line with "NsOCR" definition
        'this way we can handle possible errors if NSOCR is not installed
        Try
            NsOCR = New NSOCRLib.NSOCRClass
        Catch exc As Exception
            Dim cr = Chr(13) + Chr(10)
            Dim msg As String = "Cannot create NSOCR COM object instance. Possible reasons:" + cr + " - NSOCR.dll is missed." + cr + " - NSOCR.dll was not registered with Regsvr32." + cr + " - NSOCR.dll is x32 but this application is x64." + cr
            msg = msg + cr + " Exception message:" + cr + cr + exc.Message
            System.Windows.Forms.MessageBox.Show(msg)
            Close()
            Exit Sub
        End Try

        Inited = True 'NSOCR instance created successfully

        Dim val As String = ""
        NsOCR.Engine_GetVersion(val)
        Text = Text + " [ NSOCR version: " + val + " ] "

        NsOCR.Engine_Initialize()
        NsOCR.Cfg_Create(CfgObj)
        NsOCR.Ocr_Create(CfgObj, OcrObj)
        NsOCR.Img_Create(OcrObj, ImgObj)
        NsOCR.Scan_Create(CfgObj, ScanObj)

        NsOCR.Cfg_LoadOptions(CfgObj, "Config.dat") 'load options, if path not specified, current folder and folder with NSOCR.dll will be checked

        'bkRecognize.Enabled = False
        gr = pbCardDisplay.CreateGraphics()

        NoEvents = True
        'cbScale.SelectedIndex = 0
        NoEvents = False
        'bkSave.Enabled = False

        ''copy some settings to GUI
        'If NsOCR.Cfg_GetOption(CfgObj, TNSOCR.BT_DEFAULT, "ImgAlizer/AutoScale", val) < TNSOCR.ERROR_FIRST Then
        '    cbScale.Enabled = (val = "1")
        'End If
    End Sub

    Private Sub SetOCRImage()
        NsOCR.Cfg_SetOption(CfgObj, TNSOCR.BT_DEFAULT, "ImgAlizer/AutoScale", "1")
        NsOCR.Cfg_SetOption(CfgObj, TNSOCR.BT_DEFAULT, "ImgAlizer/ScaleFactor", "1.0") 'default scale if cannot detect it automatically

        Dim res As Integer

        'It is possible to load image from file, from memory or from bitmap data in memory, demostrate all ways
        Dim LoadMode As Integer = 0   '0 - from file; 1 - from memory; 2 - from memory bitmap; 3 - from PictureBox 

        If LoadMode = 0 Then 'load image to OCR engline from image file
            res = NsOCR.Img_LoadFile(ImgObj, PathFile)
        Else
            If LoadMode = 1 Then 'load image to OCR engline from image in memory
                Dim FileArray As Array = System.IO.File.ReadAllBytes(PathFile)
                res = NsOCR.Img_LoadFromMemory(ImgObj, FileArray, FileArray.Length)
            Else
                If LoadMode = 2 Then 'load image to OCR engine from memory bitmap
                    Dim myBmp As New Bitmap(PathFile) 'Note .NET "Bitmap" class understands only few image formats like BMP, JPG
                    ' Lock the bitmap's bits.
                    Dim bmpData As System.Drawing.Imaging.BitmapData = myBmp.LockBits(New Rectangle(0, 0, myBmp.Width, myBmp.Height), System.Drawing.Imaging.ImageLockMode.ReadOnly, System.Drawing.Imaging.PixelFormat.Format24bppRgb)

                    ' Get the address of the first line.
                    Dim ptr As IntPtr = bmpData.Scan0

                    ' Declare an array to hold the bytes of the bitmap.
                    Dim bytes As Integer = Math.Abs(bmpData.Stride) * myBmp.Height
                    Dim rgbValues() As Byte
                    ReDim rgbValues(bytes)

                    ' Copy the RGB values into the array.
                    System.Runtime.InteropServices.Marshal.Copy(ptr, rgbValues, 0, bytes)

                    ' Unlock the bits.
                    myBmp.UnlockBits(bmpData)

                    'convert to Array type
                    Dim BytesArray As Array = rgbValues

                    'load image to OCR engine
                    res = NsOCR.Img_LoadBmpData(ImgObj, BytesArray, myBmp.Width, myBmp.Height, TNSOCR.BMP_24BIT)
                Else 'load image from PictureBox
                    Dim data As Byte()
                    Dim ms As New IO.MemoryStream()
                    Dim bmp As New Bitmap(PathFile)
                    pbCardDisplay.Image = bmp
                    pbCardDisplay.Image.Save(ms, Drawing.Imaging.ImageFormat.Png)
                    data = ms.ToArray()
                    res = NsOCR.Img_LoadFromMemory(ImgObj, data, data.Length)
                End If
            End If

        End If
        '//////////////////////////

        If res > TNSOCR.ERROR_FIRST Then
            If res = TNSOCR.ERROR_CANNOTLOADGS Then 'cannot load GhostScript to support PDF
                Dim s As String = "GhostSript library is needed to support PDF files. Just download and install it with default settings. Do you want to download GhostScript now?"
                If System.Windows.Forms.MessageBox.Show(s, "", MessageBoxButtons.YesNo, MessageBoxIcon.Question) <> System.Windows.Forms.DialogResult.Yes Then Exit Sub
                OpenURL("http://www.nicomsoft.com/files/ocr/ghostscript.htm")
            Else
                ShowError("Img_LoadFile", res)
            End If
            Exit Sub
        End If

        DoImageLoaded()

        btnLoadZone_Click(Nothing, Nothing)
    End Sub


    Public Sub DoImageLoaded()
        Dim res As Integer

        'check if image has multiple page and ask user if he wants process and save all pages automatically
        res = NsOCR.Img_GetPageCount(ImgObj)
        If res > TNSOCR.ERROR_FIRST Then
            ShowError("Img_GetPageCount", res)
            Exit Sub
        End If
        If res > 1 Then
            If System.Windows.Forms.MessageBox.Show("Image contains multiple pages (" + res.ToString() + "). Do you want to process and save all pages automatically?", "", MessageBoxButtons.YesNo, MessageBoxIcon.Question) = System.Windows.Forms.DialogResult.Yes Then
                'ProcessEntireDocument()
                'bkRecognize.Enabled = False
                'Exit Sub
            End If
        End If


        'now apply image scaling, binarize image, deskew etc,
        'everything except OCR itself
        res = NsOCR.Img_OCR(ImgObj, TNSOCR.OCRSTEP_FIRST, TNSOCR.OCRSTEP_ZONING - 1, TNSOCR.OCRFLAG_NONE)
        If res > TNSOCR.ERROR_FIRST Then
            ShowError("Img_OCR", res)
        End If

        'edPage.Text = "1"
        'lbPages.Text = "of " + NsOCR.Img_GetPageCount(ImgObj).ToString()
        'bkSave.Enabled = False

        Frame.X = 0
        Frame.Y = 0
        Frame.Width = 0
        Frame.Height = 0
        AdjustDocScale()

        'bkRecognize.Enabled = True
        'tbText.Text = ""
        'bkLoadBlocks.Enabled = True
        'bkSaveBlocks.Enabled = True
        'bkClearBlocks.Enabled = True
        'bkDetectBlocks.Enabled = True
    End Sub

    Private Function IsImgLoaded() As Boolean
        Dim w, h As Integer
        IsImgLoaded = False
        If NsOCR.Img_GetSize(ImgObj, w, h) > TNSOCR.ERROR_FIRST Then Exit Function
        IsImgLoaded = (w > 0) And (h > 0)
    End Function

    Private Sub AdjustDocScale()
        If Not IsImgLoaded() Then Exit Sub
        Dim ww, hh As Integer

        Dim r As Rectangle
        r = SplitContainer1.Bounds

        ww = SplitContainer1.SplitterDistance - 15
        hh = r.Height - 45

        If (ww <= 0) Or (hh <= 0) Then
            Exit Sub
        End If
        bmp = New Bitmap(ww, hh, gr)
        Dim gr2 As Graphics = Graphics.FromImage(bmp)
        Dim dc As IntPtr = gr2.GetHdc()
        NsOCR.Img_DrawToDC(ImgObj, dc, 0, 0, ww, hh, TNSOCR.DRAW_NORMAL)

        'If cbBin.Checked Then
        '    NsOCR.Img_DrawToDC(ImgObj, dc, 0, 0, ww, hh, TNSOCR.DRAW_BINARY)
        'Else
        '    NsOCR.Img_DrawToDC(ImgObj, dc, 0, 0, ww, hh, TNSOCR.DRAW_NORMAL)
        'End If
        gr2.ReleaseHdc(dc)

        ShowImage()
    End Sub

    Private Function GetCurDocScale() As Double
        If Not IsImgLoaded() Then
            GetCurDocScale = 1.0
            Exit Function
        End If

        Dim r As Rectangle
        r = splitContainer1.Bounds
        Dim w, h, ww, hh As Integer
        w = splitContainer1.SplitterDistance - 15
        h = r.Height - 45

        NsOCR.Img_GetSize(ImgObj, ww, hh)
        Dim kX, kY, k As Double
        kX = w / ww
        kY = h / hh

        If kX > kY Then k = kY Else k = kX

        GetCurDocScale = k
    End Function

    Private Sub ShowImage()
        If Not IsImgLoaded() Then Exit Sub
        Dim k As Double = GetCurDocScale()
        Dim r As Rectangle = New Rectangle()
        Dim col As Color
        Dim w As Integer = bmp.Width
        Dim h As Integer = bmp.Height
        Dim bmp2 As Bitmap = New Bitmap(w, h, gr)
        Dim graphic As Graphics = Graphics.FromImage(bmp2)
        graphic.DrawImage(bmp, 0, 0)

        'If cbPixLines.Checked Then
        '    DrawPixLines(graphic)
        'End If

        Dim i, BlkObj, Xpos, Ypos, Width, Height As Integer
        Dim pen As Pen = New Pen(Color.Green)
        Dim cnt As Integer = NsOCR.Img_GetBlockCnt(ImgObj)

        For i = 0 To cnt - 1
            NsOCR.Img_GetBlock(ImgObj, i, BlkObj)
            NsOCR.Blk_GetRect(BlkObj, Xpos, Ypos, Width, Height)
            r.X = (k * Xpos)
            r.Y = (k * Ypos)
            r.Width = (k * Width)
            r.Height = (k * Height)

            col = System.Drawing.Color.Red
            Select Case NsOCR.Blk_GetType(BlkObj)
                Case TNSOCR.BT_OCRTEXT
                    col = System.Drawing.Color.Green
                Case TNSOCR.BT_OCRDIGIT
                    col = System.Drawing.Color.Lime
                Case TNSOCR.BT_ICRDIGIT
                    col = System.Drawing.Color.Blue
                Case TNSOCR.BT_BARCODE
                    col = System.Drawing.Color.Navy
                Case TNSOCR.BT_PICTURE
                    col = System.Drawing.Color.Aqua
                Case TNSOCR.BT_CLEAR
                    col = System.Drawing.Color.Gray
                Case TNSOCR.BT_ZONING
                    col = System.Drawing.Color.Black
                Case TNSOCR.BT_TABLE
                    col = System.Drawing.Color.Olive
            End Select

            pen.Width = 2
            pen.Color = col
            graphic.DrawRectangle(pen, r)

            Dim fnt As System.Drawing.Font = New Font("Arial", 8)
            Dim br As System.Drawing.Brush = New SolidBrush(Color.Lime)
            Dim pnt As System.Drawing.PointF = New PointF(r.X, r.Y)
            r.Width = 12
            r.Height = 14
            graphic.FillRectangle(br, r)
            br = New SolidBrush(Color.Black)
            graphic.DrawString(i.ToString(), fnt, br, pnt)
        Next i

        'user is creating new block, draw its frame
        If Dwn Then
            r.X = (k * Frame.Left)
            r.Y = (k * Frame.Top)
            r.Width = (k * Frame.Width)
            r.Height = (k * Frame.Height)


            w = bmp2.Width
            h = bmp2.Height

            If r.Width >= w Then r.Width = w - 1
            If r.Height >= h Then r.Height = h - 1

            Dim pn As Pen = New Pen(System.Drawing.Color.Red)
            graphic.DrawRectangle(pn, r)
        End If

        pbCardDisplay.Image = bmp2
        pbCardDisplay.BringToFront()
        GC.Collect()
    End Sub

    Public Sub ShowError(ByVal api As String, ByVal err As Integer)
        Dim s As String
        s = api + " Error #" + Hex(err)
        MsgBox(s)
    End Sub
    Private Sub OpenURL(ByVal url As String)
        System.Diagnostics.Process.Start(url)
    End Sub


    Private Sub pbCardDisplay_MouseDown(sender As Object, e As MouseEventArgs) Handles pbCardDisplay.MouseDown
        Dim w, h As Integer
        NsOCR.Img_GetSize(ImgObj, w, h)

        Dwn = True
        Dim k As Double = GetCurDocScale()
        Frame.X = (1 / k * e.X)
        If Frame.X < 0 Then Frame.X = 0
        If Frame.X > w Then Frame.X = w
        Frame.Y = (1 / k * e.Y)
        If Frame.Y < 0 Then Frame.Y = 0
        If Frame.Y > h Then Frame.Y = h

        Frame.Width = 0
        Frame.Height = 0

        ShowImage()
    End Sub

    Private Sub pbCardDisplay_MouseMove(sender As Object, e As MouseEventArgs) Handles pbCardDisplay.MouseMove
        GC.Collect()
        If Not Dwn Then Exit Sub

        If Not IsImgLoaded() Then Exit Sub

        Dim w, h As Integer
        NsOCR.Img_GetSize(ImgObj, w, h)

        Dim k As Double = GetCurDocScale()
        Frame.Width = (1 / k * e.X) - Frame.Left + 1
        If Frame.Width < 0 Then Frame.Width = 0
        If Frame.Width > w Then Frame.Width = w

        Frame.Height = (1 / k * e.Y) - Frame.Top + 1
        If Frame.Height < 0 Then Frame.Height = 0
        If Frame.Height > h Then Frame.Height = h

        ShowImage()
    End Sub

    Private Sub pbCardDisplay_MouseUp(sender As Object, e As MouseEventArgs) Handles pbCardDisplay.MouseUp
        Dim BlkObj, w, h, res As Integer
        If Not Dwn Then Exit Sub
        Dwn = False

        If Not IsImgLoaded() Then Exit Sub

        NsOCR.Img_GetSize(ImgObj, w, h)
        If Frame.Right >= w Then Frame.Width = w - Frame.Left - 1
        If Frame.Bottom >= h Then Frame.Height = h - Frame.Top - 1

        w = Frame.Right - Frame.Left + 1
        h = Frame.Bottom - Frame.Top + 1
        If (w < 8) Or (h < 8) Then
            ShowImage()
            Exit Sub
        End If

        res = NsOCR.Img_AddBlock(ImgObj, Frame.Left, Frame.Top, w, h, BlkObj)


        If res > TNSOCR.ERROR_FIRST Then
            ShowError("Img_AddBlock", res)
            Exit Sub
        End If

        'detect text block inversion
        NsOCR.Blk_Inversion(BlkObj, TNSOCR.BLK_INVERSE_DETECT)

        'detect text block rotation
        NsOCR.Blk_Rotation(BlkObj, TNSOCR.BLK_ROTATE_DETECT)

        ShowImage()
    End Sub

    Private Sub pbCardDisplay_SizeChanged(sender As Object, e As EventArgs) Handles pbCardDisplay.SizeChanged
        If Not NoEvents Then
            Exit Sub
        End If
    End Sub

    Private Sub btnRecognize_Click(sender As Object, e As EventArgs) Handles btnRecognize.Click
        If Not IsImgLoaded() Then
            MessageBox.Show("Image not loaded!")
            Exit Sub
        End If

        Me.Refresh()

        Dim res As Integer
        Dim InSameThread As Integer

        'InSameThread = False 'perform OCR in non-blocking mode
        InSameThread = True 'uncomment to perform OCR from this thread (GUI will be freezed)

        'perform OCR itself
        If InSameThread Then
            res = NsOCR.Img_OCR(ImgObj, TNSOCR.OCRSTEP_ZONING, TNSOCR.OCRSTEP_LAST, TNSOCR.OCRFLAG_NONE)
        Else
            'do it in non-blocking mode and then wait for result
            res = NsOCR.Img_OCR(ImgObj, TNSOCR.OCRSTEP_ZONING, TNSOCR.OCRSTEP_LAST, TNSOCR.OCRFLAG_THREAD)
            If res > TNSOCR.ERROR_FIRST Then
                ShowError("Ocr_OcrImg(1)", res)
                Exit Sub
            End If


            'fmWait.mode = 0
            'fmWait.fmMain = Me
            'fmWait.ShowDialog()
            'res = fmWait.res
        End If

        'lbWait.Visible = False
        'bkRecognize.Enabled = True
        'bkSave.Enabled = True

        If res > TNSOCR.ERROR_FIRST Then
            If res = TNSOCR.ERROR_OPERATIONCANCELLED Then
                MsgBox("Operation was cancelled.")
            Else
                ShowError("Img_OCR", res)
                Exit Sub
            End If
        End If


        '////	

        'cbBin_CheckedChanged(sender, e) 'repaint img (binarized image could change)
        ShowText()
    End Sub


    Private Sub ShowText()
        Dim txt As String = ""
        Dim flags As Integer
        flags = TNSOCR.FMT_EDITCOPY
        'If cbExactCopy.Checked Then
        '    flags = TNSOCR.FMT_EXACTCOPY
        'Else : flags = TNSOCR.FMT_EDITCOPY
        'End If

        NsOCR.Img_GetImgText(ImgObj, txt, flags)

        'demonstrates how to get text of each block(zone)
        'Dim s As String
        'txt = ""
        'Dim i, cnt, BlkObj As Integer
        'Dim Size, Style As Integer

        'cnt = NsOCR.Img_GetBlockCnt(ImgObj)
        'For i = 0 To cnt - 1
        'NsOCR.Img_GetBlock(ImgObj, i, BlkObj)
        's = ""
        'NsOCR.Blk_GetText(BlkObj, s, flags)
        'txt = txt + s + " -NEXT BLOCK- "
        'Size = NsOCR.Blk_GetWordFontSize(BlkObj, 0, 0) 'also get size and style of first block word
        'Style = NsOCR.Blk_GetWordFontStyle(BlkObj, 0, 0)
        'Next i

        'TextBox1.Text = txt

        If txt.Trim <> "" Then
            Dim Fld() As String = Split(txt, Chr(13))
            If Fld.Length = 2 Then
                txtCardID.Text = Fld(0).Replace(" ", "")

                Dim FullName() As String = Split(Fld(1), " ")
                If FullName.Length = 3 Then
                    txtFirstName.Text = FullName(0) & " " & FullName(1)
                    txtLastName.Text = FullName(2)
                End If
            End If
        End If
    End Sub
#End Region
    

    Private Sub btnClearZone_Click(sender As Object, e As EventArgs) Handles btnClearZone.Click
        NsOCR.Img_DeleteAllBlocks(ImgObj)
        ShowImage()
    End Sub

    Private Sub btnSaveZone_Click(sender As Object, e As EventArgs) Handles btnSaveZone.Click
        Dim lnq As New LinqDB.TABLE.MsCardTypeLinqDB
        lnq.GetDataByPK(lblCardTypeID.Text, Nothing)
        If lnq.ID > 0 Then
            Dim FileName As String = Application.StartupPath & lnq.OCR_ZONE_PATH
            Dim res As Integer = NsOCR.Img_SaveBlocks(ImgObj, FileName)
            If res > TNSOCR.ERROR_FIRST Then
                ShowError("btnSaveZone_Click", res)
            End If
        End If
        lnq = Nothing
    End Sub

    Private Sub btnLoadZone_Click(sender As Object, e As EventArgs) Handles btnLoadZone.Click
        NsOCR.Img_DeleteAllBlocks(ImgObj) 'note: Img_LoadBlocks does not remove existing blocks, so remove them here

        Dim lnq As New LinqDB.TABLE.MsCardTypeLinqDB
        lnq.GetDataByPK(lblCardTypeID.Text, Nothing)
        If lnq.ID > 0 Then
            Dim FileName As String = Application.StartupPath & lnq.OCR_ZONE_PATH
            If File.Exists(FileName) = True Then
                Dim res As Integer = NsOCR.Img_LoadBlocks(ImgObj, FileName)
                If res > TNSOCR.ERROR_FIRST Then
                    ShowError("Img_LoadBlocks", res)
                    Exit Sub
                End If
                ShowImage()
            End If
        End If
        lnq = Nothing
    End Sub
End Class