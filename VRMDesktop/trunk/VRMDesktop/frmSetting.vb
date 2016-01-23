Imports VRM.Org.Mentalis.Files

Public Class frmSetting
    Dim ini As New IniReader(Application.StartupPath & "\Config.ini")
    'Public Structure Settings
    '    Dim strPathCamera As String
    '    Dim strPathImageCard As String
    '    Dim strStartTime As String
    '    Dim strEndTime As String
    '    Dim strComport As String
    '    Dim strBaudRate As String
    '    Dim intTimeBlacklist As Integer
    'End Structure

    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)

    End Sub

    Private Sub frmSetting_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        SetDefaultSetting()
    End Sub

    Private Sub SetDefaultSetting()
        Try
            'Dim settings As New Settings
            'ini.Section = "Setting"
            'settings.strPathCamera = (ini.ReadString("PathCamera"))
            'settings.strPathImageCard = (ini.ReadString("PathImageCard"))
            'settings.strStartTime = (ini.ReadString("StartTime"))
            'settings.strEndTime = (ini.ReadString("EndTime"))
            'settings.strComport = (ini.ReadString("Comport"))
            'settings.strBaudRate = (ini.ReadString("BaudRate"))
            'settings.intTimeBlacklist = (ini.ReadString("TimeBlackList"))


            ini.Section = "IDCardReader"
            SetComportList(cbIDCardComport, ini.ReadString("IDCardComPort"))
            SetCompartBaudRateList(cmbIDCardBaudRate, ini.ReadString("IDCardBaudRate"))

            ini.Section = "BarcodeReader"
            SetComportList(cmbBarcodeComport, ini.ReadString("BarcodeComport"))
            SetCompartBaudRateList(cmbBarcodeBaudRate, ini.ReadString("BarcodeBaudRate"))


            Dim wc As New WebCam_Capture.WebCamCapture
            Dim dt As DataTable = wc.LoadDeviceList()
            If dt.Rows.Count > 0 Then
                Dim fDt As New DataTable
                fDt = dt.Copy

                cmbFaceCaptureCamera.DisplayMember = "CameraName"
                cmbFaceCaptureCamera.ValueMember = "CameraName"
                cmbFaceCaptureCamera.DataSource = fDt

                ini.Section = "FaceRecognition"
                Dim CameraName As String = ini.ReadString("Camera")
                If CameraName.Trim <> "" Then
                    cmbFaceCaptureCamera.SelectedValue = CameraName
                End If

                'Dim cDt As New DataTable
                'cDt = dt.Copy
                'cmbCardCaptureCamera.DisplayMember = "CameraName"
                'cmbCardCaptureCamera.ValueMember = "id"
                'cmbCardCaptureCamera.DataSource = cDt
            End If
            wc = Nothing
            dt.Dispose()
        Catch ex As Exception

        End Try
    End Sub

    Private Sub SetComportList(cmbComport As ComboBox, DefaultValue As String)
        cmbComport.Items.Clear()

        For i As Integer = 1 To 15
            cmbComport.Items.Add("COM" & i)
        Next

        cmbComport.SelectedItem = DefaultValue
    End Sub
    Private Sub SetCompartBaudRateList(cmbBaudRate As ComboBox, DefaultValue As String)
        cmbBaudRate.Items.Clear()

        cmbBaudRate.Items.Add("300")
        cmbBaudRate.Items.Add("600")
        cmbBaudRate.Items.Add("1200")
        cmbBaudRate.Items.Add("1800")
        cmbBaudRate.Items.Add("2400")
        cmbBaudRate.Items.Add("4800")
        cmbBaudRate.Items.Add("7200")
        cmbBaudRate.Items.Add("9600")
        cmbBaudRate.Items.Add("14400")
        cmbBaudRate.Items.Add("19200")
        cmbBaudRate.Items.Add("38400")
        cmbBaudRate.Items.Add("57600")
        cmbBaudRate.Items.Add("115200")
        cmbBaudRate.Items.Add("230400")
        cmbBaudRate.Items.Add("460800")
        cmbBaudRate.Items.Add("921600")

        cmbBaudRate.SelectedItem = DefaultValue
    End Sub

    Private Sub pbRegistration_Click(sender As Object, e As EventArgs) Handles pbRegistration.Click
        Me.Close()
        frmRegister.Show()
    End Sub


    Private Sub btnSave_Click(sender As Object, e As EventArgs) Handles btnSave.Click
        Try
            ini.Section = "IDCardReader"
            ini.Write("IDCardComPort", cbIDCardComport.SelectedItem)
            ini.Write("IDCardBaudRate", cmbIDCardBaudRate.SelectedItem)

            ini.Section = "BarcodeReader"
            ini.Write("BarcodeComport", cmbBarcodeComport.SelectedItem)
            ini.Write("BarcodeBaudRate", cmbBarcodeBaudRate.SelectedItem)

            ini.Section = "FaceRecognition"
            ini.Write("Camera", cmbFaceCaptureCamera.SelectedValue)

            MessageBox.Show("Save Data Complete", "Save Data Complete", MessageBoxButtons.OK, MessageBoxIcon.Information)
        Catch ex As Exception

        End Try
        


    End Sub

    Private Sub btnCancel_Click(sender As Object, e As EventArgs) Handles btnCancel.Click
        SetDefaultSetting()
    End Sub
End Class