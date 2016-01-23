Imports System.Data
Imports System.Text
Imports LinqDB.TABLE
Imports Engine.Common

Public Class frmReturnCard

    Private Sub btnRegister_Click(sender As Object, e As EventArgs) Handles btnRegister.Click
        DisableSerialBarcodeReader()
        DisconnectComportSerialBarcodeReader()

        frmRegister.Show()
        Me.Close()
    End Sub

    Private Sub txtBarcode_KeyPress(sender As Object, e As KeyPressEventArgs) Handles txtBarcode.KeyPress
        If e.KeyChar = Chr(13) Then
            FilData(txtBarcode.Text.Trim)
        End If
    End Sub

    Private Sub FilData(vBarcode As String)
        Dim sql As String = " select v.id,ct.card_name, v.First_Name_EN, v.Last_Name_EN,"
        sql += " v.BirthDate, v.IssueDate, v.expdate, v.Address, v.id_picture"
        sql += " from TS_VISITOR v"
        sql += " inner join MS_CARD_TYPE ct on ct.id=v.ms_card_type_id"
        sql += " where v.Mifare_ID='" & vBarcode & "' "

        Dim dt As New DataTable
        Dim lnq As New TsVisitorLinqDB
        dt = lnq.GetListBySql(sql, Nothing)

        If dt.Rows.Count > 0 Then
            Dim dr As DataRow = dt.Rows(0)
            lblVisitorID.Text = dr("id")
            If Convert.IsDBNull(dr("card_name")) = False Then txtCardTypeName.Text = dr("card_name")
            If Convert.IsDBNull(dr("First_Name_EN")) = False Then txtFName_EN.Text = dr("First_Name_EN")
            If Convert.IsDBNull(dr("Last_Name_EN")) = False Then txtLName_EN.Text = dr("Last_Name_EN")
            If Convert.IsDBNull(dr("BirthDate")) = False Then txtBirthDate.Text = Convert.ToDateTime(dr("BirthDate")).ToString("dd/MM/yyyy", New Globalization.CultureInfo("en-US"))
            If Convert.IsDBNull(dr("IssueDate")) = False Then txtIssueDate.Text = Convert.ToDateTime(dr("IssueDate")).ToString("dd/MM/yyyy", New Globalization.CultureInfo("en-US"))
            If Convert.IsDBNull(dr("expdate")) = False Then txtExpDate.Text = Convert.ToDateTime(dr("expdate")).ToString("dd/MM/yyyy", New Globalization.CultureInfo("en-US"))
            If Convert.IsDBNull(dr("Address")) = False Then txtAddress.Text = dr("Address")
            If Convert.IsDBNull(dr("id_picture")) = False Then
                pcPicture.Image = FunctionENG.ConvertByteToImage(dr("id_picture"))
                pcPicture.SizeMode = PictureBoxSizeMode.StretchImage
            End If
        Else
            MessageBox.Show("Data not found", "Data not found", MessageBoxButtons.OK)
            txtBarcode.Focus()
        End If
        dt.Dispose()
        lnq = Nothing

    End Sub

#Region "Serial Port Barcode Reader"
    Dim _msg As String
    Dim data As String

    Private Function ConnectComportSerialBarcodeReader() As Boolean
        Dim ret As Boolean = False
        Try
            Dim ini As New Org.Mentalis.Files.IniReader(Application.StartupPath & "\Config.ini")
            ini.Section = "BarcodeReader"
            SerialBarcodeReader.PortName = ini.ReadString("BarcodeComport")
            SerialBarcodeReader.BaudRate = ini.ReadString("BarcodeBaudRate")

            If Not SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Open()
            ret = True

            ini = Nothing
        Catch ex As Exception
            ret = False
        End Try
        Return ret
    End Function
    Private Function DisconnectComportSerialBarcodeReader() As Boolean
        Try
            If SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Close()
            Return True
        Catch ex As Exception
            Return False
        End Try
    End Function

    Private Sub EnableSerialBarcodeReader()
        Try
            If Not SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Open()
            Dim bb(1) As Byte
            bb(0) = &HA0
            SerialBarcodeReader.Write(bb, 0, 1)
        Catch ex As Exception

        End Try
    End Sub

    Private Sub DisableSerialBarcodeReader()
        Try
            If Not SerialBarcodeReader.IsOpen Then SerialBarcodeReader.Open()
            Dim bb(1) As Byte
            bb(0) = &H55
            SerialBarcodeReader.Write(bb, 0, 1)

        Catch ex As Exception

        End Try
    End Sub

    Private Sub SerialBarcodeReader_DataReceived(sender As Object, e As IO.Ports.SerialDataReceivedEventArgs) Handles SerialBarcodeReader.DataReceived
        'determine the mode the user selected (binary/string)

        'user chose binary
        'retrieve number of bytes in the buffer
        Dim bytes As Integer = SerialBarcodeReader.BytesToRead
        'create a byte array to hold the awaiting data
        Dim comBuffer As Byte() = New Byte(bytes - 1) {}
        'read the data and store it
        SerialBarcodeReader.Read(comBuffer, 0, bytes)
        data = Encoding.ASCII.GetString(comBuffer)

        'display the data to the user
        _msg = ByteToHex(comBuffer) + "" + Environment.NewLine + ""
        DisplayData(ByteToHex(comBuffer) + "" + Environment.NewLine + "")
    End Sub

    Private Function ByteToHex(ByVal comByte As Byte()) As String
        'create a new StringBuilder object
        Dim builder As New StringBuilder(comByte.Length * 3)
        'loop through each byte in the array
        For Each data As Byte In comByte
            builder.Append(Convert.ToString(data, 16).PadLeft(2, "0"c).PadRight(3, " "c))
            'convert the byte to a string and add to the stringbuilder
        Next
        'return the converted value
        Return builder.ToString().ToUpper()
    End Function

    Private Sub DoDisplay(ByVal sender As Object, ByVal e As EventArgs)
        txtBarcode.SelectedText = String.Empty
        txtBarcode.Text = Replace(data, "*", "")
        txtBarcode.ScrollToCaret()
        'If txtMifareID.Text <> "" Then CheckBarcode() Else txtMifareID.Text = ""
        If txtBarcode.Text.Trim <> "" Then
            FilData(txtBarcode.Text.Trim)
        End If
    End Sub
    Private Sub DisplayData(ByVal msg As String)
        Try
            txtBarcode.Invoke(New EventHandler(AddressOf DoDisplay))
        Catch ex As Exception

        End Try
    End Sub
#End Region

    Private Sub frmReturnCard_Shown(sender As Object, e As EventArgs) Handles Me.Shown
        If ConnectComportSerialBarcodeReader() = True Then
            EnableSerialBarcodeReader()
        End If
    End Sub

    Private Sub btnSave_Click(sender As Object, e As EventArgs) Handles btnSave.Click
        Try
            If lblVisitorID.Text <> "0" Then
                Dim lnq As New TsVisitorLinqDB
                lnq.GetDataByPK(lblVisitorID.Text, Nothing)
                If lnq.ID > 0 Then
                    lnq.OUT_DATE = DateTime.Now

                    Dim trans As New LinqDB.ConnectDB.TransactionDB
                    If lnq.UpdateByPK(UserName, trans.Trans) = True Then
                        trans.CommitTransaction()
                        MessageBox.Show("Save Complete", "Message", MessageBoxButtons.OK, MessageBoxIcon.Information)
                        ClearData()
                    Else
                        trans.RollbackTransaction()
                        MessageBox.Show(lnq.ErrorMessage, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                    End If
                    lnq = Nothing
                End If
            Else
                MessageBox.Show("Data not found", "Data not found", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
                txtBarcode.Focus()
            End If
        Catch ex As Exception

        End Try
    End Sub

    Private Sub btnCancel_Click(sender As Object, e As EventArgs) Handles btnCancel.Click
        ClearData()
    End Sub

    Private Sub ClearData()
        lblVisitorID.Text = "0"
        txtBarcode.Text = ""
        txtCardTypeName.Text = ""
        txtFName_EN.Text = ""
        txtLName_EN.Text = ""
        txtBirthDate.Text = ""
        txtIssueDate.Text = ""
        txtExpDate.Text = ""
        txtAddress.Text = ""
        pcPicture.Image = Nothing
    End Sub
End Class