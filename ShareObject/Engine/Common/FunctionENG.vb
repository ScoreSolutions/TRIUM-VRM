Imports System.Drawing
Imports System.IO
Imports LinqDB.ConnectDB
Namespace Common
    Public Class FunctionENG
        Public Shared Function GetDataTable(sql As String) As DataTable
            Dim ret As New DataTable
            Try
                ret = SqlDB.ExecuteTable(sql)
            Catch ex As Exception
                ret = New DataTable
            End Try
            Return ret
        End Function

        Public Shared Function GetDataTable(sql As String, trans As SqlClient.SqlTransaction) As DataTable
            Dim ret As New DataTable
            Try
                ret = SqlDB.ExecuteTable(sql, trans)
            Catch ex As Exception
                ret = New DataTable
            End Try
            Return ret
        End Function

        Public Shared Function ConvertByteToImage(ByteData As Byte()) As Image
            Dim ret As Image = Nothing
            If ByteData IsNot Nothing Then
                Dim ms As New MemoryStream(ByteData)
                ret = System.Drawing.Image.FromStream(ms)
                ms.Dispose()
            End If

            Return ret
        End Function
    End Class
End Namespace

