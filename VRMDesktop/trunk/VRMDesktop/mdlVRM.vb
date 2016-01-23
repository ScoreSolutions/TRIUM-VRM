Module mdlVRM
    Public UserID As Long = 1
    Public UserName As String = "admin"
    Public ClientIP As String = ""
    Public LoginHistoryID As Long = 0

    Public Function GetIPAddress() As String
        Dim oAddr As System.Net.IPAddress
        Dim sAddr As String
        With System.Net.Dns.GetHostByName(System.Net.Dns.GetHostName())
            oAddr = New System.Net.IPAddress(.AddressList(0).Address)
            sAddr = oAddr.ToString
        End With
        GetIPAddress = sAddr
    End Function
End Module
