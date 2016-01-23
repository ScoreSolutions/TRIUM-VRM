Imports Microsoft.VisualBasic
Imports System
Imports System.Windows.Forms

Partial Public Class WaitForm
	Inherits Form
	#Region "Private fields"

	Private allowClose As Boolean

	#End Region

	#Region "Private constructor"

	Public Sub New(ByVal title As String)
		InitializeComponent()

		lblTitle.Text = title
	End Sub

	#End Region

	#Region "Public methods"

	Public Sub NotifyReceived()
		allowClose = True
		Close()
	End Sub

	#End Region

	#Region "Private form events"

	Private Sub LongTaskFormFormClosing(ByVal sender As Object, ByVal e As FormClosingEventArgs) Handles MyBase.FormClosing
		If (Not allowClose) Then
			e.Cancel = True
		End If
	End Sub

	#End Region
End Class
