Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.Windows.Forms
Imports Neurotec.Devices
Imports Neurotec.Media
Imports System.IO

Namespace Forms
	Partial Public Class DeviceForm
		Inherits System.Windows.Forms.Form
		#Region "Private fields"

		Private _activeDevice As NCamera
		Private devMan As NDeviceManager
		Private usedDevices As List(Of NCamera)

#End Region

#Region "Public constructor"

		Public Sub New(ByVal devMan As NDeviceManager, ByVal usedDevices As List(Of NCamera))
			InitializeComponent()
			Me.usedDevices = usedDevices
			Me.devMan = devMan
			ListDevices()
			lvDevicesList.Focus()
		End Sub

#End Region

#Region "Public properties"

		Public Property ActiveDevice() As NCamera
			Set(ByVal value As NCamera)
				_activeDevice = value
			End Set
			Get
				Return _activeDevice
			End Get
		End Property

#End Region

#Region "Private methods"

        Private Sub ListDevices()
            If File.Exists(Application.StartupPath & "\ConfigPathFile.txt") = True Then
                Dim ConfigPath As String = File.ReadAllText(Application.StartupPath & "\ConfigPathFile.txt")

                If File.Exists(ConfigPath) = True Then
                    lvDevicesList.BeginUpdate()
                    Try
                        lvDevicesList.Items.Clear()

                        Dim ini As New Org.Mentalis.Files.IniReader(ConfigPath)
                        Dim strDeviceName As String = ini.ReadString("FaceRecognition", "Camera")
                        For Each device As NDevice In devMan.Devices
                            If (Not usedDevices.Contains(TryCast(device, NCamera))) Then
                                Dim item As New ListViewItem(device.DisplayName)
                                If device.DisplayName = strDeviceName Then
                                    item.Tag = device
                                    lvDevicesList.Items.Add(item)
                                    If _activeDevice Is device Then
                                        item.Selected = True
                                    End If
                                End If
                            End If
                        Next device
                    Finally
                        lvDevicesList.EndUpdate()
                    End Try

                    If lvDevicesList.Items.Count > 0 AndAlso lvDevicesList.SelectedItems.Count = 0 Then
                        lvDevicesList.Items(0).Selected = True
                    End If
                End If
            End If
        End Sub

#End Region

#Region "Private form event"

		Private Sub BtnOkClick(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnOk.Click
			If lvDevicesList.SelectedItems.Count <> 1 Then
				MessageBox.Show("Select one device from the list")
			Else
                Dim selectedItem As ListViewItem = lvDevicesList.SelectedItems(0)
				_activeDevice = CType(selectedItem.Tag, NCamera)
				Try
					_activeDevice.StopCapturing()
					If cbVideoFormat.SelectedIndex <> -1 Then
						_activeDevice.SetCurrentFormat(TryCast(cbVideoFormat.SelectedItem, NMediaFormat))
					End If
					DialogResult = System.Windows.Forms.DialogResult.OK
				Catch ex As Exception
					MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
				End Try
			End If
		End Sub

		Private Sub LvDevicesListDoubleClick(ByVal sender As Object, ByVal e As System.EventArgs) Handles lvDevicesList.DoubleClick
			btnOk.PerformClick()
		End Sub

		Private Sub ListVideoFormats(ByVal device As NCamera)
			Try
				cbVideoFormat.Items.Clear()
				Dim formats() As NMediaFormat = device.GetFormats()
				Dim currentFormat As NMediaFormat = device.GetCurrentFormat()
				cbVideoFormat.Items.AddRange(formats)

				If currentFormat IsNot Nothing Then
					Dim index As Integer = cbVideoFormat.Items.IndexOf(currentFormat)
					If index = -1 Then
						cbVideoFormat.Items.Insert(0, currentFormat)
						cbVideoFormat.SelectedIndex = 0
					Else
						cbVideoFormat.SelectedIndex = index
					End If
				End If
			Catch ex As Exception
				MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
			End Try
		End Sub

		Private Sub LvDevicesListSelectedIndexChanged(ByVal sender As Object, ByVal e As EventArgs) Handles lvDevicesList.SelectedIndexChanged
			Dim items As ListView.SelectedListViewItemCollection = lvDevicesList.SelectedItems
			If items.Count > 0 Then
				_activeDevice = TryCast(items(0).Tag, NCamera)
				ListVideoFormats(_activeDevice)
			Else
				_activeDevice = Nothing
				cbVideoFormat.Items.Clear()
			End If
			tsbDisconnect.Enabled = _activeDevice IsNot Nothing AndAlso _activeDevice.IsDisconnectable
		End Sub

		Private Sub TsbConnectClick(ByVal sender As Object, ByVal e As EventArgs) Handles tsbConnect.Click
			Using dialog As New ConnectToDeviceForm()
				If dialog.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
					Try
						devMan.ConnectToDevice(dialog.SelectedPlugin, dialog.Parameters)
						ListDevices()
					Catch ex As Exception
						MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
					End Try
				End If
			End Using
		End Sub

		Private Sub TsbDisconnectClick(ByVal sender As Object, ByVal e As EventArgs) Handles tsbDisconnect.Click
			If _activeDevice IsNot Nothing AndAlso _activeDevice.IsDisconnectable Then
				devMan.DisconnectFromDevice(_activeDevice)
				_activeDevice = Nothing
				ListDevices()
			End If
		End Sub

#End Region

        Private Sub DeviceForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
            BtnOkClick(New Object, New EventArgs)
        End Sub
    End Class
End Namespace
