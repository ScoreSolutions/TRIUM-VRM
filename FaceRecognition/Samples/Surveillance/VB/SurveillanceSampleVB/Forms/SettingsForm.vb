Imports Microsoft.VisualBasic
Imports System
Imports System.Text
Imports System.Windows.Forms
Imports Neurotec.Biometrics

Partial Public Class SettingsForm
	Inherits Form
	#Region "Public constructor"

	Public Sub New()
		InitializeComponent()

		FillTemplateSizes(cmbEnrollmentTemplateSize)
		FillTemplateSizes(cmbIdentificationTemplateSize)
	End Sub

	#End Region

	#Region "Private methods"

	Private Sub FillTemplateSizes(ByVal combo As ComboBox)
		For Each templateSize As Object In System.Enum.GetValues(GetType(NleTemplateSize))
			combo.Items.Add(templateSize)
		Next templateSize
		combo.SelectedIndex = 1
	End Sub

	#End Region

	#Region "Data exchange"

	Public Sub LoadSettings()
		Dim settings As My.Settings = My.Settings.Default
		numericUpDown1.Value = settings.MaxThreadCount
		nudMinIod.Value = settings.DetectionMinIod
		nudMaxIod.Value = settings.DetectionMaxIod
		nudFaceConfidenceThreshold.Value = settings.DetectionFaceConfidenceThreshold
		nudMaxRoll.Value = settings.DetectionMaxRollAngleDeviation
		numericUpDown6.Value = settings.ExtractionFaceQualityThreshold
		numericUpDown7.Value = settings.ExtractionMaxRecordsPerTemplate
		cmbEnrollmentTemplateSize.Items(cmbEnrollmentTemplateSize.SelectedIndex) = settings.ExtractionEnrollmentTemplateSize
		cmbIdentificationTemplateSize.Items(cmbIdentificationTemplateSize.SelectedIndex) = settings.ExtractionIdentificationTemplateSize
		numericUpDown10.Value = settings.IdentificationMatchingThreshold
		numericUpDown11.Value = settings.IdentificationMaxBestMatchCount
		numericUpDown14.Value = settings.MiscMaxTreeNodeCount
		cbDisplayTime.SelectedIndex = 0
		cbDisplayTime.SelectedItem = settings.MiscDisplayTime.ToString()
	nudListenPort.Value = settings.ListenPort
	nudPort.Value = nudListenPort.Value
		Dim values() As String = settings.Instances.Split(New Char() { ";"c }, StringSplitOptions.RemoveEmptyEntries)
		lbInstances.Items.Clear()
		lbInstances.Items.AddRange(values)
		chbSynchronize.Checked = settings.Synchronize
		nudMaxYaw.Value = settings.MaxYawAngle
		nudFaceScale.Value = settings.FaceDetectionScale
		nudRollBase.Value = settings.FaceRollAngleBase
		chbDetectMoreFaces.Checked = settings.DetectMoreFaces
		chbDetectGender.Checked = settings.ExtractionDetectGener
		nudGenderThr.Value = settings.ExtractionGenderConfidenceThreshold
		chbDetectExpression.Checked = settings.ExtractionDetectExpression
		nudExpressionThr.Value = settings.ExtractionExpressionConfidenceThreshold
		chbDetectBlink.Checked = settings.ExtractionDetectBlink
		nudBlinkThr.Value = settings.ExtractionBlinkConfidenceThreshold
		chbDetectMouthOpen.Checked = settings.ExtractionDetectMouthOpen
		nudMoutOpenThr.Value = settings.ExtractionMouthOpenConfidenceThreshold
		chbDetectGlasses.Checked = settings.ExtractionDetectGlasses
		nudGlassesThr.Value = settings.ExtractionGlassesConfidenceThreshold
		chbDetectDarkGlasses.Checked = settings.ExtractionDetectDarkGlasses
		nudDarkGalssesThr.Value = settings.ExtractionDarkGlassesConfidenceThreshold
	End Sub

	Public Sub SaveSettings()
		Dim settings As My.Settings = My.Settings.Default
		settings.MaxThreadCount = numericUpDown1.Value
		settings.DetectionMinIod = nudMinIod.Value
		settings.DetectionMaxIod = nudMaxIod.Value
		settings.DetectionFaceConfidenceThreshold = nudFaceConfidenceThreshold.Value
		settings.DetectionMaxRollAngleDeviation = nudMaxRoll.Value
		settings.ExtractionFaceQualityThreshold = numericUpDown6.Value
		settings.ExtractionMaxRecordsPerTemplate = numericUpDown7.Value
		settings.ExtractionEnrollmentTemplateSize = CType(cmbEnrollmentTemplateSize.Items(cmbEnrollmentTemplateSize.SelectedIndex), NleTemplateSize)
		settings.ExtractionIdentificationTemplateSize = CType(cmbIdentificationTemplateSize.Items(cmbIdentificationTemplateSize.SelectedIndex), NleTemplateSize)
		settings.IdentificationMatchingThreshold = numericUpDown10.Value
		settings.IdentificationMaxBestMatchCount = numericUpDown11.Value
		settings.MiscMaxTreeNodeCount = numericUpDown14.Value
		settings.MiscDisplayTime = Integer.Parse(cbDisplayTime.Text)
		settings.ListenPort = Convert.ToInt32(nudListenPort.Value)
		settings.Synchronize = chbSynchronize.Checked
		Dim instances As New StringBuilder()
		For Each item As Object In lbInstances.Items
			instances.Append(String.Format("{0};", item))
		Next item
		settings.Instances = instances.ToString()
		settings.MaxYawAngle = CShort(Fix(nudMaxYaw.Value))
		settings.FaceDetectionScale = CInt(Fix(nudFaceScale.Value))
		settings.FaceRollAngleBase = CShort(Fix(nudRollBase.Value))
		settings.DetectMoreFaces = chbDetectMoreFaces.Checked

		settings.ExtractionDetectGener = chbDetectGender.Checked
		settings.ExtractionGenderConfidenceThreshold = Convert.ToByte(nudGenderThr.Value)
		settings.ExtractionDetectExpression = chbDetectExpression.Checked
		settings.ExtractionExpressionConfidenceThreshold = Convert.ToByte(nudExpressionThr.Value)
		settings.ExtractionDetectBlink = chbDetectBlink.Checked
		settings.ExtractionBlinkConfidenceThreshold = Convert.ToByte(nudBlinkThr.Value)
		settings.ExtractionDetectMouthOpen = chbDetectMouthOpen.Checked
		settings.ExtractionMouthOpenConfidenceThreshold = Convert.ToByte(nudMoutOpenThr.Value)
		settings.ExtractionDetectGlasses = chbDetectGlasses.Checked
		settings.ExtractionGlassesConfidenceThreshold = Convert.ToByte(nudGlassesThr.Value)
		settings.ExtractionDetectDarkGlasses = chbDetectDarkGlasses.Checked
		settings.ExtractionDarkGlassesConfidenceThreshold = Convert.ToByte(nudDarkGalssesThr.Value)

		settings.Save()
	End Sub

	#End Region ' Data exchange

	#Region "Private events"

	Private Sub nudMinIod_ValueChanged(ByVal sender As Object, ByVal e As EventArgs) Handles nudMinIod.ValueChanged
		nudMaxIod.Minimum = nudMinIod.Value
	End Sub

	Private Sub nudMaxIod_ValueChanged(ByVal sender As Object, ByVal e As EventArgs) Handles nudMaxIod.ValueChanged
		nudMinIod.Maximum = nudMaxIod.Value
	End Sub

	Private Sub buttonDefault_Click(ByVal sender As Object, ByVal e As EventArgs) Handles buttonDefault.Click
		My.Settings.Default.Reset()
		LoadSettings()
	End Sub

	Private Sub chbSynchronize_CheckedChanged(ByVal sender As Object, ByVal e As EventArgs) Handles chbSynchronize.CheckedChanged
		Dim enable As Boolean = chbSynchronize.Checked
		btnAdd.Enabled = enable
		lbInstances.Enabled = enable
		nudListenPort.Enabled = enable
		nudPort.Enabled = enable
		tbAddress.Enabled = enable
		btnRemove.Enabled = enable AndAlso lbInstances.SelectedIndex <> -1
	End Sub

	Private Sub btnAdd_Click(ByVal sender As Object, ByVal e As EventArgs) Handles btnAdd.Click
		If String.IsNullOrEmpty(tbAddress.Text) Then
			MessageBox.Show("Address is not valid")
			Return
		End If
		Dim item As String = String.Format("{0}:{1}", tbAddress.Text, nudPort.Value)
		If (Not lbInstances.Items.Contains(item)) Then
			lbInstances.Items.Add(item)
		End If
	End Sub

	Private Sub btnRemove_Click(ByVal sender As Object, ByVal e As EventArgs) Handles btnRemove.Click
		Dim index As Integer = lbInstances.SelectedIndex
		If index <> -1 Then
			lbInstances.Items.RemoveAt(index)
		End If
	End Sub

	Private Sub lbInstances_SelectedIndexChanged(ByVal sender As Object, ByVal e As EventArgs) Handles lbInstances.SelectedIndexChanged
		btnRemove.Enabled = lbInstances.SelectedIndex <> -1
	End Sub

	Private Sub ChbDetectCheckedChanged(ByVal sender As Object, ByVal e As EventArgs) Handles chbDetectGender.CheckedChanged, chbDetectMouthOpen.CheckedChanged, chbDetectBlink.CheckedChanged, chbDetectDarkGlasses.CheckedChanged, chbDetectGlasses.CheckedChanged, chbDetectExpression.CheckedChanged
		nudGenderThr.Enabled = chbDetectGender.Checked
		nudExpressionThr.Enabled = chbDetectExpression.Checked
		nudBlinkThr.Enabled = chbDetectBlink.Checked
		nudMoutOpenThr.Enabled = chbDetectMouthOpen.Checked
		nudGlassesThr.Enabled = chbDetectGlasses.Checked
		nudDarkGalssesThr.Enabled = chbDetectDarkGlasses.Checked
	End Sub

	#End Region
End Class
