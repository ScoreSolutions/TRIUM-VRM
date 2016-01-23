Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.ComponentModel
Imports System.Data
Imports System.Drawing
Imports System.Text
Imports System.Windows.Forms
Imports System.Reflection
Imports System.IO
Imports Neurotec
Imports Neurotec.Diagnostics

Partial Public Class MainForm
	Inherits Form
	Public Sub New()
		InitializeComponent()
	End Sub

	Private Sub btnClose_Click(ByVal sender As Object, ByVal e As EventArgs) Handles btnClose.Click
		Me.Close()
	End Sub

	Private Sub fillProducts()
		cbProducts.Items.Clear()

		For Each fInfo As FieldInfo In (CObj(New DiagnosticAPIProductId())).GetType().GetFields(BindingFlags.Public Or BindingFlags.Static)
			cbProducts.Items.Add(fInfo.Name)
		Next fInfo
	End Sub

	Private Sub MainForm_Load(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Load
		fillProducts()
		cbProducts.SelectedIndex = 0
	End Sub

	Private Sub btnGenerate_Click(ByVal sender As Object, ByVal e As EventArgs) Handles btnGenerate.Click
		richTextBox1.Clear()
		richTextBox1.AppendText(DiagnosticsAPI.GetGeneralInfo() + Constants.vbLf & "Program location: " & System.Windows.Forms.Application.StartupPath + Constants.vbLf + Constants.vbLf)

		'str += readLicFile(paramName, licFile);
		richTextBox1.AppendText(DiagnosticsAPI.GetRunningPgInfo() + Constants.vbLf + DiagnosticsAPI.GetInstalledRuntimesInfo() + Constants.vbLf)

		richTextBox1.AppendText("Trial server test: " & DiagnosticsAPI.TestTrialServerHttp() + ControlChars.Lf & "Trial server (sockets) test: " & DiagnosticsAPI.TestTrialServerSockets() + ControlChars.Lf & "Trial time left: " & DiagnosticsAPI.GetTrialTimeLeft() + Constants.vbLf)

		Dim selecteditem2 As String = cbProducts.Items(cbProducts.SelectedIndex).ToString()
		Dim fInfo2 As FieldInfo = (CObj(New DiagnosticAPIProductId())).GetType().GetField(selecteditem2)
		Dim productID2 As DiagnosticAPIProductId = CType(fInfo2.GetRawConstantValue(), DiagnosticAPIProductId)

		If (Not Directory.Exists(textBoxPath.Text)) AndAlso textBoxPath.Text <> String.Empty AndAlso textBoxPath.Text <> "null" Then
			richTextBox1.SelectionColor = Color.Red
			richTextBox1.SelectionFont = New Font("Courier New", 10, FontStyle.Bold)

			richTextBox1.SelectedText = "Error! directory '" & textBoxPath.Text & "' does not exist" & Constants.vbLf + Constants.vbCr

		End If

		richTextBox1.AppendText(DiagnosticsAPI.GetRegisteredComponents(productID2, textBoxPath.Text) + Constants.vbLf)

		If productID2 = DiagnosticAPIProductId.VeriFinger Then
			richTextBox1.AppendText(DiagnosticsAPI.GetComLibsAndFPSmmContents(textBoxPath.Text) + Constants.vbLf & "Path: " & Environment.GetEnvironmentVariable("PATH") + Constants.vbLf)
		End If
	End Sub

	Private Sub buttonPath_Click(ByVal sender As Object, ByVal e As EventArgs) Handles buttonPath.Click
		folderBrowserDialog.SelectedPath = textBoxPath.Text
		If folderBrowserDialog.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
			textBoxPath.Text = folderBrowserDialog.SelectedPath
		End If
	End Sub
End Class

