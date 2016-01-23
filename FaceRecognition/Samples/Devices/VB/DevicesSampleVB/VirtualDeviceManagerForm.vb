Imports Microsoft.VisualBasic
Imports System
Imports System.Drawing
Imports System.Windows.Forms
Imports Neurotec.Devices.Virtual

Partial Public Class VirtualDeviceManagerForm
	Inherits Form
#Region "Public constructor"

	Public Sub New()
		InitializeComponent()
	End Sub

#End Region

#Region "Public properties"

	Public Property VirtualDevices() As NVirtualDevice()
		Get
			Dim value(lvDevices.Items.Count - 1) As NVirtualDevice
			For i As Integer = 0 To value.Length - 1
				value(i) = TryCast(lvDevices.Items(i).Tag, NVirtualDevice)
			Next i
			Return value
		End Get
		Set(ByVal value As NVirtualDevice())
			lvDevices.Items.Clear()
			If value IsNot Nothing Then
				For Each item As NVirtualDevice In value
					AddDevice(item)
				Next item
			End If
		End Set
	End Property

#End Region

#Region "Private form events"

	Private Sub BtnAddClick(ByVal sender As Object, ByVal e As EventArgs) Handles btnAdd.Click
		Try
			AddDevice(New NVirtualDevice())
		Catch ex As Exception
			MessageBox.Show(ex.ToString())
		End Try
	End Sub

	Private Sub BtnRemoveClick(ByVal sender As Object, ByVal e As EventArgs) Handles btnRemove.Click
		Dim index As Integer = GetSelectedIndex()
		If index <> -1 Then
			Dim lvi As ListViewItem = GetSelectedItem()
			Dim selected As NVirtualDevice = TryCast(lvi.Tag, NVirtualDevice)
			selected.IsPluggedIn = False
			lvDevices.Items.Remove(lvi)
			If lvDevices.Items.Count > 0 Then
				lvDevices.Items(CType(IIf(index > 0, index - 1, 0), Integer)).Selected = True
			End If
		End If
	End Sub

	Private Sub BtnPlugClick(ByVal sender As Object, ByVal e As EventArgs) Handles btnPlug.Click
		Dim item As ListViewItem = GetSelectedItem()
		If item IsNot Nothing Then
			Dim selected As NVirtualDevice = TryCast(item.Tag, NVirtualDevice)
			selected.IsPluggedIn = True
			EnableControls()
			propertyGrid.SelectedObject = selected
		End If
	End Sub

	Private Sub BtnUnplugClick(ByVal sender As Object, ByVal e As EventArgs) Handles btnUnplug.Click
		Dim item As ListViewItem = GetSelectedItem()
		If item IsNot Nothing Then
			Dim selected As NVirtualDevice = TryCast(item.Tag, NVirtualDevice)
			selected.IsPluggedIn = False
			EnableControls()
			propertyGrid.SelectedObject = selected
		End If
	End Sub

	Private Sub PropertyGridPropertyValueChanged(ByVal s As Object, ByVal e As PropertyValueChangedEventArgs) Handles propertyGrid.PropertyValueChanged
		If e.ChangedItem.Label = "IsPluggedIn" Then
			EnableControls()
		End If
	End Sub

	Private Sub LvDevicesSelectedIndexChanged(ByVal sender As Object, ByVal e As EventArgs) Handles lvDevices.SelectedIndexChanged
		Dim item As ListViewItem = GetSelectedItem()
		If item IsNot Nothing Then
			propertyGrid.SelectedObject = item.Tag
		Else
			propertyGrid.SelectedObject = Nothing
		End If
		EnableControls()
	End Sub

	Private Sub BtnCloseClick(ByVal sender As Object, ByVal e As EventArgs) Handles btnClose.Click
		Close()
	End Sub

#End Region

#Region "Private methods"

	Private Function GetSelectedIndex() As Integer
		If lvDevices.SelectedIndices.Count > 0 Then
			Return lvDevices.SelectedIndices(0)
		Else
			Return -1
		End If
	End Function

	Private Function GetSelectedItem() As ListViewItem
		If lvDevices.SelectedItems.Count > 0 Then
			Return lvDevices.SelectedItems(0)
		Else
			Return Nothing
		End If
	End Function

	Private Sub EnableControls()
		Dim item As ListViewItem = GetSelectedItem()
		If item IsNot Nothing Then
			Dim selected As NVirtualDevice = TryCast(item.Tag, NVirtualDevice)
			btnPlug.Enabled = Not selected.IsPluggedIn
			btnUnplug.Enabled = Not btnPlug.Enabled
			btnRemove.Enabled = True
			item.ForeColor = CType(IIf(selected.IsPluggedIn, Color.DarkGreen, Color.Black), Color)
		Else
			btnUnplug.Enabled = False
			btnPlug.Enabled = btnUnplug.Enabled
			btnRemove.Enabled = btnPlug.Enabled
		End If
	End Sub

	Private Sub AddDevice(ByVal device As NVirtualDevice)
		Dim item As ListViewItem = lvDevices.Items.Add(device.ToString())
		item.Tag = device
		item.Selected = True
	End Sub

#End Region
End Class
