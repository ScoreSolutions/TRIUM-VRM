Imports Microsoft.VisualBasic
Imports System
Partial Public Class SettingsForm
	''' <summary>
	''' Required designer variable.
	''' </summary>
	Private components As System.ComponentModel.IContainer = Nothing

	''' <summary>
	''' Clean up any resources being used.
	''' </summary>
	''' <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
	Protected Overrides Sub Dispose(ByVal disposing As Boolean)
		If disposing AndAlso (components IsNot Nothing) Then
			components.Dispose()
		End If
		MyBase.Dispose(disposing)
	End Sub

	#Region "Windows Form Designer generated code"

	''' <summary>
	''' Required method for Designer support - do not modify
	''' the contents of this method with the code editor.
	''' </summary>
	Private Sub InitializeComponent()
		Dim resources As New System.ComponentModel.ComponentResourceManager(GetType(SettingsForm))
		Me.label2 = New System.Windows.Forms.Label()
		Me.label5 = New System.Windows.Forms.Label()
		Me.groupBoxDetection = New System.Windows.Forms.GroupBox()
		Me.nudRollBase = New System.Windows.Forms.NumericUpDown()
		Me.label20 = New System.Windows.Forms.Label()
		Me.nudFaceScale = New System.Windows.Forms.NumericUpDown()
		Me.label19 = New System.Windows.Forms.Label()
		Me.chbDetectMoreFaces = New System.Windows.Forms.CheckBox()
		Me.nudMaxYaw = New System.Windows.Forms.NumericUpDown()
		Me.label18 = New System.Windows.Forms.Label()
		Me.nudMaxRoll = New System.Windows.Forms.NumericUpDown()
		Me.label10 = New System.Windows.Forms.Label()
		Me.nudFaceConfidenceThreshold = New System.Windows.Forms.NumericUpDown()
		Me.nudMaxIod = New System.Windows.Forms.NumericUpDown()
		Me.nudMinIod = New System.Windows.Forms.NumericUpDown()
		Me.label7 = New System.Windows.Forms.Label()
		Me.label6 = New System.Windows.Forms.Label()
		Me.numericUpDown1 = New System.Windows.Forms.NumericUpDown()
		Me.groupBoxExtraction = New System.Windows.Forms.GroupBox()
		Me.groupBox1 = New System.Windows.Forms.GroupBox()
		Me.label21 = New System.Windows.Forms.Label()
		Me.chbDetectGender = New System.Windows.Forms.CheckBox()
		Me.nudGenderThr = New System.Windows.Forms.NumericUpDown()
		Me.label22 = New System.Windows.Forms.Label()
		Me.nudExpressionThr = New System.Windows.Forms.NumericUpDown()
		Me.label23 = New System.Windows.Forms.Label()
		Me.nudBlinkThr = New System.Windows.Forms.NumericUpDown()
		Me.label24 = New System.Windows.Forms.Label()
		Me.nudMoutOpenThr = New System.Windows.Forms.NumericUpDown()
		Me.label25 = New System.Windows.Forms.Label()
		Me.nudGlassesThr = New System.Windows.Forms.NumericUpDown()
		Me.label26 = New System.Windows.Forms.Label()
		Me.nudDarkGalssesThr = New System.Windows.Forms.NumericUpDown()
		Me.chbDetectMouthOpen = New System.Windows.Forms.CheckBox()
		Me.chbDetectBlink = New System.Windows.Forms.CheckBox()
		Me.chbDetectDarkGlasses = New System.Windows.Forms.CheckBox()
		Me.chbDetectGlasses = New System.Windows.Forms.CheckBox()
		Me.chbDetectExpression = New System.Windows.Forms.CheckBox()
		Me.cmbIdentificationTemplateSize = New System.Windows.Forms.ComboBox()
		Me.cmbEnrollmentTemplateSize = New System.Windows.Forms.ComboBox()
		Me.label4 = New System.Windows.Forms.Label()
		Me.label1 = New System.Windows.Forms.Label()
		Me.numericUpDown7 = New System.Windows.Forms.NumericUpDown()
		Me.numericUpDown6 = New System.Windows.Forms.NumericUpDown()
		Me.label3 = New System.Windows.Forms.Label()
		Me.label8 = New System.Windows.Forms.Label()
		Me.groupBoxIdentification = New System.Windows.Forms.GroupBox()
		Me.numericUpDown11 = New System.Windows.Forms.NumericUpDown()
		Me.numericUpDown10 = New System.Windows.Forms.NumericUpDown()
		Me.label9 = New System.Windows.Forms.Label()
		Me.label11 = New System.Windows.Forms.Label()
		Me.groupBoxMisc = New System.Windows.Forms.GroupBox()
		Me.cbDisplayTime = New System.Windows.Forms.ComboBox()
		Me.label12 = New System.Windows.Forms.Label()
		Me.numericUpDown14 = New System.Windows.Forms.NumericUpDown()
		Me.label14 = New System.Windows.Forms.Label()
		Me.buttonDefault = New System.Windows.Forms.Button()
		Me.buttonOk = New System.Windows.Forms.Button()
		Me.buttonCancel = New System.Windows.Forms.Button()
		Me.tabControl1 = New System.Windows.Forms.TabControl()
		Me.tabPage1 = New System.Windows.Forms.TabPage()
		Me.tabPage2 = New System.Windows.Forms.TabPage()
		Me.gbSynchronization = New System.Windows.Forms.GroupBox()
		Me.btnRemove = New System.Windows.Forms.Button()
		Me.label17 = New System.Windows.Forms.Label()
		Me.label16 = New System.Windows.Forms.Label()
		Me.label15 = New System.Windows.Forms.Label()
		Me.tbAddress = New System.Windows.Forms.TextBox()
		Me.nudPort = New System.Windows.Forms.NumericUpDown()
		Me.lbInstances = New System.Windows.Forms.ListBox()
		Me.nudListenPort = New System.Windows.Forms.NumericUpDown()
		Me.label13 = New System.Windows.Forms.Label()
		Me.chbSynchronize = New System.Windows.Forms.CheckBox()
		Me.btnAdd = New System.Windows.Forms.Button()
		Me.groupBoxDetection.SuspendLayout()
		CType(Me.nudRollBase, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudFaceScale, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudMaxYaw, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudMaxRoll, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudFaceConfidenceThreshold, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudMaxIod, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudMinIod, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.numericUpDown1, System.ComponentModel.ISupportInitialize).BeginInit()
		Me.groupBoxExtraction.SuspendLayout()
		Me.groupBox1.SuspendLayout()
		CType(Me.nudGenderThr, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudExpressionThr, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudBlinkThr, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudMoutOpenThr, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudGlassesThr, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudDarkGalssesThr, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.numericUpDown7, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.numericUpDown6, System.ComponentModel.ISupportInitialize).BeginInit()
		Me.groupBoxIdentification.SuspendLayout()
		CType(Me.numericUpDown11, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.numericUpDown10, System.ComponentModel.ISupportInitialize).BeginInit()
		Me.groupBoxMisc.SuspendLayout()
		CType(Me.numericUpDown14, System.ComponentModel.ISupportInitialize).BeginInit()
		Me.tabControl1.SuspendLayout()
		Me.tabPage1.SuspendLayout()
		Me.tabPage2.SuspendLayout()
		Me.gbSynchronization.SuspendLayout()
		CType(Me.nudPort, System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.nudListenPort, System.ComponentModel.ISupportInitialize).BeginInit()
		Me.SuspendLayout()
		' 
		' label2
		' 
		Me.label2.AutoSize = True
		Me.label2.Location = New System.Drawing.Point(6, 21)
		Me.label2.Name = "label2"
		Me.label2.Size = New System.Drawing.Size(95, 13)
		Me.label2.TabIndex = 62
		Me.label2.Text = "Max Thread Count"
		' 
		' label5
		' 
		Me.label5.AutoSize = True
		Me.label5.Location = New System.Drawing.Point(6, 21)
		Me.label5.Name = "label5"
		Me.label5.Size = New System.Drawing.Size(125, 13)
		Me.label5.TabIndex = 2
		Me.label5.Text = "Min Inter-ocular Distance"
		' 
		' groupBoxDetection
		' 
		Me.groupBoxDetection.Controls.Add(Me.nudRollBase)
		Me.groupBoxDetection.Controls.Add(Me.label20)
		Me.groupBoxDetection.Controls.Add(Me.nudFaceScale)
		Me.groupBoxDetection.Controls.Add(Me.label19)
		Me.groupBoxDetection.Controls.Add(Me.chbDetectMoreFaces)
		Me.groupBoxDetection.Controls.Add(Me.nudMaxYaw)
		Me.groupBoxDetection.Controls.Add(Me.label18)
		Me.groupBoxDetection.Controls.Add(Me.nudMaxRoll)
		Me.groupBoxDetection.Controls.Add(Me.label10)
		Me.groupBoxDetection.Controls.Add(Me.nudFaceConfidenceThreshold)
		Me.groupBoxDetection.Controls.Add(Me.nudMaxIod)
		Me.groupBoxDetection.Controls.Add(Me.nudMinIod)
		Me.groupBoxDetection.Controls.Add(Me.label7)
		Me.groupBoxDetection.Controls.Add(Me.label6)
		Me.groupBoxDetection.Controls.Add(Me.label5)
		Me.groupBoxDetection.Location = New System.Drawing.Point(6, 6)
		Me.groupBoxDetection.Name = "groupBoxDetection"
		Me.groupBoxDetection.Size = New System.Drawing.Size(223, 225)
		Me.groupBoxDetection.TabIndex = 1
		Me.groupBoxDetection.TabStop = False
		Me.groupBoxDetection.Text = "Detection"
		' 
		' nudRollBase
		' 
		Me.nudRollBase.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudRollBase.Location = New System.Drawing.Point(167, 120)
		Me.nudRollBase.Maximum = New Decimal(New Integer() { 180, 0, 0, 0})
		Me.nudRollBase.Minimum = New Decimal(New Integer() { 180, 0, 0, -2147483648})
		Me.nudRollBase.Name = "nudRollBase"
		Me.nudRollBase.Size = New System.Drawing.Size(50, 20)
		Me.nudRollBase.TabIndex = 16
		' 
		' label20
		' 
		Me.label20.AutoSize = True
		Me.label20.Location = New System.Drawing.Point(8, 122)
		Me.label20.Name = "label20"
		Me.label20.Size = New System.Drawing.Size(109, 13)
		Me.label20.TabIndex = 15
		Me.label20.Text = "Face Roll Angle Base"
		' 
		' nudFaceScale
		' 
		Me.nudFaceScale.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudFaceScale.Location = New System.Drawing.Point(167, 172)
		Me.nudFaceScale.Maximum = New Decimal(New Integer() { 16, 0, 0, 0})
		Me.nudFaceScale.Minimum = New Decimal(New Integer() { 1, 0, 0, 0})
		Me.nudFaceScale.Name = "nudFaceScale"
		Me.nudFaceScale.Size = New System.Drawing.Size(50, 20)
		Me.nudFaceScale.TabIndex = 14
		Me.nudFaceScale.Value = New Decimal(New Integer() { 1, 0, 0, 0})
		' 
		' label19
		' 
		Me.label19.AutoSize = True
		Me.label19.Location = New System.Drawing.Point(7, 174)
		Me.label19.Name = "label19"
		Me.label19.Size = New System.Drawing.Size(110, 13)
		Me.label19.TabIndex = 13
		Me.label19.Text = "Face Detection Scale"
		' 
		' chbDetectMoreFaces
		' 
		Me.chbDetectMoreFaces.AutoSize = True
		Me.chbDetectMoreFaces.Location = New System.Drawing.Point(10, 199)
		Me.chbDetectMoreFaces.Name = "chbDetectMoreFaces"
		Me.chbDetectMoreFaces.Size = New System.Drawing.Size(113, 17)
		Me.chbDetectMoreFaces.TabIndex = 12
		Me.chbDetectMoreFaces.Text = "Detect more faces"
		Me.chbDetectMoreFaces.UseVisualStyleBackColor = True
		' 
		' nudMaxYaw
		' 
		Me.nudMaxYaw.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudMaxYaw.Location = New System.Drawing.Point(167, 146)
		Me.nudMaxYaw.Maximum = New Decimal(New Integer() { 90, 0, 0, 0})
		Me.nudMaxYaw.Name = "nudMaxYaw"
		Me.nudMaxYaw.Size = New System.Drawing.Size(50, 20)
		Me.nudMaxYaw.TabIndex = 11
		Me.nudMaxYaw.Value = New Decimal(New Integer() { 15, 0, 0, 0})
		' 
		' label18
		' 
		Me.label18.AutoSize = True
		Me.label18.Location = New System.Drawing.Point(6, 148)
		Me.label18.Name = "label18"
		Me.label18.Size = New System.Drawing.Size(129, 13)
		Me.label18.TabIndex = 10
		Me.label18.Text = "Max Yaw Angle Deviation"
		' 
		' nudMaxRoll
		' 
		Me.nudMaxRoll.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudMaxRoll.Location = New System.Drawing.Point(167, 97)
		Me.nudMaxRoll.Maximum = New Decimal(New Integer() { 180, 0, 0, 0})
		Me.nudMaxRoll.Name = "nudMaxRoll"
		Me.nudMaxRoll.Size = New System.Drawing.Size(50, 20)
		Me.nudMaxRoll.TabIndex = 9
		Me.nudMaxRoll.Value = New Decimal(New Integer() { 15, 0, 0, 0})
		' 
		' label10
		' 
		Me.label10.AutoSize = True
		Me.label10.Location = New System.Drawing.Point(7, 99)
		Me.label10.Name = "label10"
		Me.label10.Size = New System.Drawing.Size(126, 13)
		Me.label10.TabIndex = 8
		Me.label10.Text = "Max Roll Angle Deviation"
		' 
		' nudFaceConfidenceThreshold
		' 
		Me.nudFaceConfidenceThreshold.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudFaceConfidenceThreshold.DecimalPlaces = 1
		Me.nudFaceConfidenceThreshold.Location = New System.Drawing.Point(167, 71)
		Me.nudFaceConfidenceThreshold.Name = "nudFaceConfidenceThreshold"
		Me.nudFaceConfidenceThreshold.Size = New System.Drawing.Size(50, 20)
		Me.nudFaceConfidenceThreshold.TabIndex = 7
		Me.nudFaceConfidenceThreshold.Value = New Decimal(New Integer() { 51, 0, 0, 0})
		' 
		' nudMaxIod
		' 
		Me.nudMaxIod.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudMaxIod.Increment = New Decimal(New Integer() { 10, 0, 0, 0})
		Me.nudMaxIod.Location = New System.Drawing.Point(167, 45)
		Me.nudMaxIod.Maximum = New Decimal(New Integer() { 16000, 0, 0, 0})
		Me.nudMaxIod.Minimum = New Decimal(New Integer() { 40, 0, 0, 0})
		Me.nudMaxIod.Name = "nudMaxIod"
		Me.nudMaxIod.Size = New System.Drawing.Size(50, 20)
		Me.nudMaxIod.TabIndex = 5
		Me.nudMaxIod.Value = New Decimal(New Integer() { 4000, 0, 0, 0})
'		Me.nudMaxIod.ValueChanged += New System.EventHandler(Me.nudMaxIod_ValueChanged);
		' 
		' nudMinIod
		' 
		Me.nudMinIod.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudMinIod.Increment = New Decimal(New Integer() { 10, 0, 0, 0})
		Me.nudMinIod.Location = New System.Drawing.Point(167, 19)
		Me.nudMinIod.Maximum = New Decimal(New Integer() { 4000, 0, 0, 0})
		Me.nudMinIod.Minimum = New Decimal(New Integer() { 10, 0, 0, 0})
		Me.nudMinIod.Name = "nudMinIod"
		Me.nudMinIod.Size = New System.Drawing.Size(50, 20)
		Me.nudMinIod.TabIndex = 3
		Me.nudMinIod.Value = New Decimal(New Integer() { 40, 0, 0, 0})
'		Me.nudMinIod.ValueChanged += New System.EventHandler(Me.nudMinIod_ValueChanged);
		' 
		' label7
		' 
		Me.label7.AutoSize = True
		Me.label7.Location = New System.Drawing.Point(6, 73)
		Me.label7.Name = "label7"
		Me.label7.Size = New System.Drawing.Size(138, 13)
		Me.label7.TabIndex = 6
		Me.label7.Text = "Face Confidence Threshold"
		' 
		' label6
		' 
		Me.label6.AutoSize = True
		Me.label6.Location = New System.Drawing.Point(6, 47)
		Me.label6.Name = "label6"
		Me.label6.Size = New System.Drawing.Size(128, 13)
		Me.label6.TabIndex = 4
		Me.label6.Text = "Max Inter-ocular Distance"
		' 
		' numericUpDown1
		' 
		Me.numericUpDown1.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.numericUpDown1.Location = New System.Drawing.Point(157, 19)
		Me.numericUpDown1.Maximum = New Decimal(New Integer() { 8, 0, 0, 0})
		Me.numericUpDown1.Minimum = New Decimal(New Integer() { 3, 0, 0, 0})
		Me.numericUpDown1.Name = "numericUpDown1"
		Me.numericUpDown1.Size = New System.Drawing.Size(59, 20)
		Me.numericUpDown1.TabIndex = 63
		Me.numericUpDown1.Value = New Decimal(New Integer() { 5, 0, 0, 0})
		' 
		' groupBoxExtraction
		' 
		Me.groupBoxExtraction.Controls.Add(Me.groupBox1)
		Me.groupBoxExtraction.Controls.Add(Me.cmbIdentificationTemplateSize)
		Me.groupBoxExtraction.Controls.Add(Me.cmbEnrollmentTemplateSize)
		Me.groupBoxExtraction.Controls.Add(Me.label4)
		Me.groupBoxExtraction.Controls.Add(Me.label1)
		Me.groupBoxExtraction.Controls.Add(Me.numericUpDown7)
		Me.groupBoxExtraction.Controls.Add(Me.numericUpDown6)
		Me.groupBoxExtraction.Controls.Add(Me.label3)
		Me.groupBoxExtraction.Controls.Add(Me.label8)
		Me.groupBoxExtraction.Location = New System.Drawing.Point(238, 6)
		Me.groupBoxExtraction.Name = "groupBoxExtraction"
		Me.groupBoxExtraction.Size = New System.Drawing.Size(282, 306)
		Me.groupBoxExtraction.TabIndex = 21
		Me.groupBoxExtraction.TabStop = False
		Me.groupBoxExtraction.Text = "Extraction"
		' 
		' groupBox1
		' 
		Me.groupBox1.Anchor = (CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) Or System.Windows.Forms.AnchorStyles.Left) Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.groupBox1.Controls.Add(Me.label21)
		Me.groupBox1.Controls.Add(Me.chbDetectGender)
		Me.groupBox1.Controls.Add(Me.nudGenderThr)
		Me.groupBox1.Controls.Add(Me.label22)
		Me.groupBox1.Controls.Add(Me.nudExpressionThr)
		Me.groupBox1.Controls.Add(Me.label23)
		Me.groupBox1.Controls.Add(Me.nudBlinkThr)
		Me.groupBox1.Controls.Add(Me.label24)
		Me.groupBox1.Controls.Add(Me.nudMoutOpenThr)
		Me.groupBox1.Controls.Add(Me.label25)
		Me.groupBox1.Controls.Add(Me.nudGlassesThr)
		Me.groupBox1.Controls.Add(Me.label26)
		Me.groupBox1.Controls.Add(Me.nudDarkGalssesThr)
		Me.groupBox1.Controls.Add(Me.chbDetectMouthOpen)
		Me.groupBox1.Controls.Add(Me.chbDetectBlink)
		Me.groupBox1.Controls.Add(Me.chbDetectDarkGlasses)
		Me.groupBox1.Controls.Add(Me.chbDetectGlasses)
		Me.groupBox1.Controls.Add(Me.chbDetectExpression)
		Me.groupBox1.Location = New System.Drawing.Point(6, 143)
		Me.groupBox1.Name = "groupBox1"
		Me.groupBox1.Size = New System.Drawing.Size(270, 157)
		Me.groupBox1.TabIndex = 45
		Me.groupBox1.TabStop = False
		Me.groupBox1.Text = "Feature detection"
		' 
		' label21
		' 
		Me.label21.AutoSize = True
		Me.label21.Location = New System.Drawing.Point(148, 20)
		Me.label21.Name = "label21"
		Me.label21.Size = New System.Drawing.Size(57, 13)
		Me.label21.TabIndex = 57
		Me.label21.Text = "Threshold:"
		' 
		' chbDetectGender
		' 
		Me.chbDetectGender.AutoSize = True
		Me.chbDetectGender.Location = New System.Drawing.Point(14, 19)
		Me.chbDetectGender.Name = "chbDetectGender"
		Me.chbDetectGender.Size = New System.Drawing.Size(96, 17)
		Me.chbDetectGender.TabIndex = 30
		Me.chbDetectGender.Text = "Detect Gender"
		Me.chbDetectGender.UseVisualStyleBackColor = True
'		Me.chbDetectGender.CheckedChanged += New System.EventHandler(Me.ChbDetectCheckedChanged);
		' 
		' nudGenderThr
		' 
		Me.nudGenderThr.Enabled = False
		Me.nudGenderThr.Location = New System.Drawing.Point(210, 16)
		Me.nudGenderThr.Maximum = New Decimal(New Integer() { 255, 0, 0, 0})
		Me.nudGenderThr.Name = "nudGenderThr"
		Me.nudGenderThr.Size = New System.Drawing.Size(60, 20)
		Me.nudGenderThr.TabIndex = 56
		' 
		' label22
		' 
		Me.label22.AutoSize = True
		Me.label22.Location = New System.Drawing.Point(148, 43)
		Me.label22.Name = "label22"
		Me.label22.Size = New System.Drawing.Size(57, 13)
		Me.label22.TabIndex = 55
		Me.label22.Text = "Threshold:"
		' 
		' nudExpressionThr
		' 
		Me.nudExpressionThr.Enabled = False
		Me.nudExpressionThr.Location = New System.Drawing.Point(210, 39)
		Me.nudExpressionThr.Maximum = New Decimal(New Integer() { 255, 0, 0, 0})
		Me.nudExpressionThr.Name = "nudExpressionThr"
		Me.nudExpressionThr.Size = New System.Drawing.Size(60, 20)
		Me.nudExpressionThr.TabIndex = 54
		' 
		' label23
		' 
		Me.label23.AutoSize = True
		Me.label23.Location = New System.Drawing.Point(148, 66)
		Me.label23.Name = "label23"
		Me.label23.Size = New System.Drawing.Size(57, 13)
		Me.label23.TabIndex = 53
		Me.label23.Text = "Threshold:"
		' 
		' nudBlinkThr
		' 
		Me.nudBlinkThr.Enabled = False
		Me.nudBlinkThr.Location = New System.Drawing.Point(210, 62)
		Me.nudBlinkThr.Maximum = New Decimal(New Integer() { 255, 0, 0, 0})
		Me.nudBlinkThr.Name = "nudBlinkThr"
		Me.nudBlinkThr.Size = New System.Drawing.Size(60, 20)
		Me.nudBlinkThr.TabIndex = 52
		' 
		' label24
		' 
		Me.label24.AutoSize = True
		Me.label24.Location = New System.Drawing.Point(148, 89)
		Me.label24.Name = "label24"
		Me.label24.Size = New System.Drawing.Size(57, 13)
		Me.label24.TabIndex = 51
		Me.label24.Text = "Threshold:"
		' 
		' nudMoutOpenThr
		' 
		Me.nudMoutOpenThr.Enabled = False
		Me.nudMoutOpenThr.Location = New System.Drawing.Point(210, 85)
		Me.nudMoutOpenThr.Maximum = New Decimal(New Integer() { 255, 0, 0, 0})
		Me.nudMoutOpenThr.Name = "nudMoutOpenThr"
		Me.nudMoutOpenThr.Size = New System.Drawing.Size(60, 20)
		Me.nudMoutOpenThr.TabIndex = 50
		' 
		' label25
		' 
		Me.label25.AutoSize = True
		Me.label25.Location = New System.Drawing.Point(148, 112)
		Me.label25.Name = "label25"
		Me.label25.Size = New System.Drawing.Size(57, 13)
		Me.label25.TabIndex = 49
		Me.label25.Text = "Threshold:"
		' 
		' nudGlassesThr
		' 
		Me.nudGlassesThr.Enabled = False
		Me.nudGlassesThr.Location = New System.Drawing.Point(210, 108)
		Me.nudGlassesThr.Maximum = New Decimal(New Integer() { 255, 0, 0, 0})
		Me.nudGlassesThr.Name = "nudGlassesThr"
		Me.nudGlassesThr.Size = New System.Drawing.Size(60, 20)
		Me.nudGlassesThr.TabIndex = 48
		' 
		' label26
		' 
		Me.label26.AutoSize = True
		Me.label26.Location = New System.Drawing.Point(148, 135)
		Me.label26.Name = "label26"
		Me.label26.Size = New System.Drawing.Size(57, 13)
		Me.label26.TabIndex = 47
		Me.label26.Text = "Threshold:"
		' 
		' nudDarkGalssesThr
		' 
		Me.nudDarkGalssesThr.Enabled = False
		Me.nudDarkGalssesThr.Location = New System.Drawing.Point(210, 131)
		Me.nudDarkGalssesThr.Maximum = New Decimal(New Integer() { 255, 0, 0, 0})
		Me.nudDarkGalssesThr.Name = "nudDarkGalssesThr"
		Me.nudDarkGalssesThr.Size = New System.Drawing.Size(60, 20)
		Me.nudDarkGalssesThr.TabIndex = 46
		' 
		' chbDetectMouthOpen
		' 
		Me.chbDetectMouthOpen.AutoSize = True
		Me.chbDetectMouthOpen.Location = New System.Drawing.Point(14, 88)
		Me.chbDetectMouthOpen.Name = "chbDetectMouthOpen"
		Me.chbDetectMouthOpen.Size = New System.Drawing.Size(120, 17)
		Me.chbDetectMouthOpen.TabIndex = 45
		Me.chbDetectMouthOpen.Text = "Detect Mouth Open"
		Me.chbDetectMouthOpen.UseVisualStyleBackColor = True
'		Me.chbDetectMouthOpen.CheckedChanged += New System.EventHandler(Me.ChbDetectCheckedChanged);
		' 
		' chbDetectBlink
		' 
		Me.chbDetectBlink.AutoSize = True
		Me.chbDetectBlink.Location = New System.Drawing.Point(14, 65)
		Me.chbDetectBlink.Name = "chbDetectBlink"
		Me.chbDetectBlink.Size = New System.Drawing.Size(84, 17)
		Me.chbDetectBlink.TabIndex = 35
		Me.chbDetectBlink.Text = "Detect Blink"
		Me.chbDetectBlink.UseVisualStyleBackColor = True
'		Me.chbDetectBlink.CheckedChanged += New System.EventHandler(Me.ChbDetectCheckedChanged);
		' 
		' chbDetectDarkGlasses
		' 
		Me.chbDetectDarkGlasses.AutoSize = True
		Me.chbDetectDarkGlasses.Location = New System.Drawing.Point(14, 134)
		Me.chbDetectDarkGlasses.Name = "chbDetectDarkGlasses"
		Me.chbDetectDarkGlasses.Size = New System.Drawing.Size(124, 17)
		Me.chbDetectDarkGlasses.TabIndex = 34
		Me.chbDetectDarkGlasses.Text = "Detect Dark Glasses"
		Me.chbDetectDarkGlasses.UseVisualStyleBackColor = True
'		Me.chbDetectDarkGlasses.CheckedChanged += New System.EventHandler(Me.ChbDetectCheckedChanged);
		' 
		' chbDetectGlasses
		' 
		Me.chbDetectGlasses.AutoSize = True
		Me.chbDetectGlasses.Location = New System.Drawing.Point(14, 111)
		Me.chbDetectGlasses.Name = "chbDetectGlasses"
		Me.chbDetectGlasses.Size = New System.Drawing.Size(98, 17)
		Me.chbDetectGlasses.TabIndex = 33
		Me.chbDetectGlasses.Text = "Detect Glasses"
		Me.chbDetectGlasses.UseVisualStyleBackColor = True
'		Me.chbDetectGlasses.CheckedChanged += New System.EventHandler(Me.ChbDetectCheckedChanged);
		' 
		' chbDetectExpression
		' 
		Me.chbDetectExpression.AutoSize = True
		Me.chbDetectExpression.Location = New System.Drawing.Point(14, 42)
		Me.chbDetectExpression.Name = "chbDetectExpression"
		Me.chbDetectExpression.Size = New System.Drawing.Size(112, 17)
		Me.chbDetectExpression.TabIndex = 32
		Me.chbDetectExpression.Text = "Detect Expression"
		Me.chbDetectExpression.UseVisualStyleBackColor = True
'		Me.chbDetectExpression.CheckedChanged += New System.EventHandler(Me.ChbDetectCheckedChanged);
		' 
		' cmbIdentificationTemplateSize
		' 
		Me.cmbIdentificationTemplateSize.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.cmbIdentificationTemplateSize.FormattingEnabled = True
		Me.cmbIdentificationTemplateSize.Location = New System.Drawing.Point(208, 96)
		Me.cmbIdentificationTemplateSize.Name = "cmbIdentificationTemplateSize"
		Me.cmbIdentificationTemplateSize.Size = New System.Drawing.Size(68, 21)
		Me.cmbIdentificationTemplateSize.TabIndex = 29
		' 
		' cmbEnrollmentTemplateSize
		' 
		Me.cmbEnrollmentTemplateSize.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.cmbEnrollmentTemplateSize.FormattingEnabled = True
		Me.cmbEnrollmentTemplateSize.Location = New System.Drawing.Point(208, 70)
		Me.cmbEnrollmentTemplateSize.Name = "cmbEnrollmentTemplateSize"
		Me.cmbEnrollmentTemplateSize.Size = New System.Drawing.Size(68, 21)
		Me.cmbEnrollmentTemplateSize.TabIndex = 27
		' 
		' label4
		' 
		Me.label4.AutoSize = True
		Me.label4.Location = New System.Drawing.Point(6, 99)
		Me.label4.Name = "label4"
		Me.label4.Size = New System.Drawing.Size(137, 13)
		Me.label4.TabIndex = 28
		Me.label4.Text = "Identification Template Size"
		' 
		' label1
		' 
		Me.label1.AutoSize = True
		Me.label1.Location = New System.Drawing.Point(6, 73)
		Me.label1.Name = "label1"
		Me.label1.Size = New System.Drawing.Size(126, 13)
		Me.label1.TabIndex = 26
		Me.label1.Text = "Enrollment Template Size"
		' 
		' numericUpDown7
		' 
		Me.numericUpDown7.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.numericUpDown7.Location = New System.Drawing.Point(226, 45)
		Me.numericUpDown7.Maximum = New Decimal(New Integer() { 16, 0, 0, 0})
		Me.numericUpDown7.Minimum = New Decimal(New Integer() { 1, 0, 0, 0})
		Me.numericUpDown7.Name = "numericUpDown7"
		Me.numericUpDown7.Size = New System.Drawing.Size(50, 20)
		Me.numericUpDown7.TabIndex = 25
		Me.numericUpDown7.Value = New Decimal(New Integer() { 5, 0, 0, 0})
		' 
		' numericUpDown6
		' 
		Me.numericUpDown6.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.numericUpDown6.Location = New System.Drawing.Point(226, 19)
		Me.numericUpDown6.Maximum = New Decimal(New Integer() { 255, 0, 0, 0})
		Me.numericUpDown6.Name = "numericUpDown6"
		Me.numericUpDown6.Size = New System.Drawing.Size(50, 20)
		Me.numericUpDown6.TabIndex = 23
		Me.numericUpDown6.Value = New Decimal(New Integer() { 128, 0, 0, 0})
		' 
		' label3
		' 
		Me.label3.AutoSize = True
		Me.label3.Location = New System.Drawing.Point(6, 47)
		Me.label3.Name = "label3"
		Me.label3.Size = New System.Drawing.Size(136, 13)
		Me.label3.TabIndex = 24
		Me.label3.Text = "Max Records Per Template"
		' 
		' label8
		' 
		Me.label8.AutoSize = True
		Me.label8.Location = New System.Drawing.Point(6, 21)
		Me.label8.Name = "label8"
		Me.label8.Size = New System.Drawing.Size(116, 13)
		Me.label8.TabIndex = 22
		Me.label8.Text = "Face Quality Threshold"
		' 
		' groupBoxIdentification
		' 
		Me.groupBoxIdentification.Controls.Add(Me.numericUpDown11)
		Me.groupBoxIdentification.Controls.Add(Me.numericUpDown10)
		Me.groupBoxIdentification.Controls.Add(Me.label9)
		Me.groupBoxIdentification.Controls.Add(Me.label11)
		Me.groupBoxIdentification.Location = New System.Drawing.Point(238, 314)
		Me.groupBoxIdentification.Name = "groupBoxIdentification"
		Me.groupBoxIdentification.Size = New System.Drawing.Size(282, 71)
		Me.groupBoxIdentification.TabIndex = 41
		Me.groupBoxIdentification.TabStop = False
		Me.groupBoxIdentification.Text = "Identification"
		' 
		' numericUpDown11
		' 
		Me.numericUpDown11.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.numericUpDown11.Location = New System.Drawing.Point(217, 45)
		Me.numericUpDown11.Maximum = New Decimal(New Integer() { 1024, 0, 0, 0})
		Me.numericUpDown11.Minimum = New Decimal(New Integer() { 1, 0, 0, 0})
		Me.numericUpDown11.Name = "numericUpDown11"
		Me.numericUpDown11.Size = New System.Drawing.Size(59, 20)
		Me.numericUpDown11.TabIndex = 45
		Me.numericUpDown11.Value = New Decimal(New Integer() { 10, 0, 0, 0})
		' 
		' numericUpDown10
		' 
		Me.numericUpDown10.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.numericUpDown10.Increment = New Decimal(New Integer() { 12, 0, 0, 0})
		Me.numericUpDown10.Location = New System.Drawing.Point(217, 19)
		Me.numericUpDown10.Maximum = New Decimal(New Integer() { 16000, 0, 0, 0})
		Me.numericUpDown10.Name = "numericUpDown10"
		Me.numericUpDown10.Size = New System.Drawing.Size(59, 20)
		Me.numericUpDown10.TabIndex = 43
		Me.numericUpDown10.Value = New Decimal(New Integer() { 48, 0, 0, 0})
		' 
		' label9
		' 
		Me.label9.AutoSize = True
		Me.label9.Location = New System.Drawing.Point(6, 48)
		Me.label9.Name = "label9"
		Me.label9.Size = New System.Drawing.Size(115, 13)
		Me.label9.TabIndex = 44
		Me.label9.Text = "Max Best Match Count"
		' 
		' label11
		' 
		Me.label11.AutoSize = True
		Me.label11.Location = New System.Drawing.Point(6, 22)
		Me.label11.Name = "label11"
		Me.label11.Size = New System.Drawing.Size(101, 13)
		Me.label11.TabIndex = 42
		Me.label11.Text = "Matching Threshold"
		' 
		' groupBoxMisc
		' 
		Me.groupBoxMisc.Controls.Add(Me.cbDisplayTime)
		Me.groupBoxMisc.Controls.Add(Me.label12)
		Me.groupBoxMisc.Controls.Add(Me.numericUpDown14)
		Me.groupBoxMisc.Controls.Add(Me.label14)
		Me.groupBoxMisc.Controls.Add(Me.label2)
		Me.groupBoxMisc.Controls.Add(Me.numericUpDown1)
		Me.groupBoxMisc.Location = New System.Drawing.Point(6, 236)
		Me.groupBoxMisc.Name = "groupBoxMisc"
		Me.groupBoxMisc.Size = New System.Drawing.Size(222, 149)
		Me.groupBoxMisc.TabIndex = 61
		Me.groupBoxMisc.TabStop = False
		Me.groupBoxMisc.Text = "Misc"
		' 
		' cbDisplayTime
		' 
		Me.cbDisplayTime.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.cbDisplayTime.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
		Me.cbDisplayTime.FormattingEnabled = True
		Me.cbDisplayTime.Items.AddRange(New Object() { "250", "500", "1000"})
		Me.cbDisplayTime.Location = New System.Drawing.Point(157, 75)
		Me.cbDisplayTime.Name = "cbDisplayTime"
		Me.cbDisplayTime.Size = New System.Drawing.Size(59, 21)
		Me.cbDisplayTime.TabIndex = 69
		' 
		' label12
		' 
		Me.label12.AutoSize = True
		Me.label12.Location = New System.Drawing.Point(6, 78)
		Me.label12.Name = "label12"
		Me.label12.Size = New System.Drawing.Size(99, 13)
		Me.label12.TabIndex = 68
		Me.label12.Text = "Display time (in ms):"
		' 
		' numericUpDown14
		' 
		Me.numericUpDown14.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.numericUpDown14.Location = New System.Drawing.Point(157, 50)
		Me.numericUpDown14.Minimum = New Decimal(New Integer() { 2, 0, 0, 0})
		Me.numericUpDown14.Name = "numericUpDown14"
		Me.numericUpDown14.Size = New System.Drawing.Size(59, 20)
		Me.numericUpDown14.TabIndex = 67
		Me.numericUpDown14.Value = New Decimal(New Integer() { 10, 0, 0, 0})
		' 
		' label14
		' 
		Me.label14.AutoSize = True
		Me.label14.Location = New System.Drawing.Point(6, 52)
		Me.label14.Name = "label14"
		Me.label14.Size = New System.Drawing.Size(112, 13)
		Me.label14.TabIndex = 66
		Me.label14.Text = "Max Tree Node Count"
		' 
		' buttonDefault
		' 
		Me.buttonDefault.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.buttonDefault.Location = New System.Drawing.Point(5, 424)
		Me.buttonDefault.Name = "buttonDefault"
		Me.buttonDefault.Size = New System.Drawing.Size(75, 23)
		Me.buttonDefault.TabIndex = 101
		Me.buttonDefault.Text = "&Default"
		Me.buttonDefault.UseVisualStyleBackColor = True
'		Me.buttonDefault.Click += New System.EventHandler(Me.buttonDefault_Click);
		' 
		' buttonOk
		' 
		Me.buttonOk.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.buttonOk.DialogResult = System.Windows.Forms.DialogResult.OK
		Me.buttonOk.Location = New System.Drawing.Point(365, 421)
		Me.buttonOk.Name = "buttonOk"
		Me.buttonOk.Size = New System.Drawing.Size(75, 23)
		Me.buttonOk.TabIndex = 0
		Me.buttonOk.Text = "&OK"
		Me.buttonOk.UseVisualStyleBackColor = True
		' 
		' buttonCancel
		' 
		Me.buttonCancel.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel
		Me.buttonCancel.Location = New System.Drawing.Point(446, 421)
		Me.buttonCancel.Name = "buttonCancel"
		Me.buttonCancel.Size = New System.Drawing.Size(75, 23)
		Me.buttonCancel.TabIndex = 102
		Me.buttonCancel.Text = "&Cancel"
		Me.buttonCancel.UseVisualStyleBackColor = True
		' 
		' tabControl1
		' 
		Me.tabControl1.Controls.Add(Me.tabPage1)
		Me.tabControl1.Controls.Add(Me.tabPage2)
		Me.tabControl1.Location = New System.Drawing.Point(1, 2)
		Me.tabControl1.Name = "tabControl1"
		Me.tabControl1.SelectedIndex = 0
		Me.tabControl1.Size = New System.Drawing.Size(532, 416)
		Me.tabControl1.TabIndex = 103
		' 
		' tabPage1
		' 
		Me.tabPage1.Controls.Add(Me.groupBoxIdentification)
		Me.tabPage1.Controls.Add(Me.groupBoxDetection)
		Me.tabPage1.Controls.Add(Me.groupBoxExtraction)
		Me.tabPage1.Controls.Add(Me.groupBoxMisc)
		Me.tabPage1.Location = New System.Drawing.Point(4, 22)
		Me.tabPage1.Name = "tabPage1"
		Me.tabPage1.Padding = New System.Windows.Forms.Padding(3)
		Me.tabPage1.Size = New System.Drawing.Size(524, 390)
		Me.tabPage1.TabIndex = 0
		Me.tabPage1.Text = "Surveillance settings"
		Me.tabPage1.UseVisualStyleBackColor = True
		' 
		' tabPage2
		' 
		Me.tabPage2.Controls.Add(Me.gbSynchronization)
		Me.tabPage2.Location = New System.Drawing.Point(4, 22)
		Me.tabPage2.Name = "tabPage2"
		Me.tabPage2.Padding = New System.Windows.Forms.Padding(3)
		Me.tabPage2.Size = New System.Drawing.Size(524, 390)
		Me.tabPage2.TabIndex = 1
		Me.tabPage2.Text = "Synchronization settings"
		Me.tabPage2.UseVisualStyleBackColor = True
		' 
		' gbSynchronization
		' 
		Me.gbSynchronization.Controls.Add(Me.btnRemove)
		Me.gbSynchronization.Controls.Add(Me.label17)
		Me.gbSynchronization.Controls.Add(Me.label16)
		Me.gbSynchronization.Controls.Add(Me.label15)
		Me.gbSynchronization.Controls.Add(Me.tbAddress)
		Me.gbSynchronization.Controls.Add(Me.nudPort)
		Me.gbSynchronization.Controls.Add(Me.lbInstances)
		Me.gbSynchronization.Controls.Add(Me.nudListenPort)
		Me.gbSynchronization.Controls.Add(Me.label13)
		Me.gbSynchronization.Controls.Add(Me.chbSynchronize)
		Me.gbSynchronization.Controls.Add(Me.btnAdd)
		Me.gbSynchronization.Dock = System.Windows.Forms.DockStyle.Fill
		Me.gbSynchronization.Location = New System.Drawing.Point(3, 3)
		Me.gbSynchronization.Name = "gbSynchronization"
		Me.gbSynchronization.Size = New System.Drawing.Size(518, 384)
		Me.gbSynchronization.TabIndex = 42
		Me.gbSynchronization.TabStop = False
		Me.gbSynchronization.Text = "Database Synchronization"
		' 
		' btnRemove
		' 
		Me.btnRemove.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.btnRemove.Enabled = False
		Me.btnRemove.Location = New System.Drawing.Point(437, 44)
		Me.btnRemove.Name = "btnRemove"
		Me.btnRemove.Size = New System.Drawing.Size(75, 23)
		Me.btnRemove.TabIndex = 11
		Me.btnRemove.Text = "Remove"
		Me.btnRemove.UseVisualStyleBackColor = True
'		Me.btnRemove.Click += New System.EventHandler(Me.btnRemove_Click);
		' 
		' label17
		' 
		Me.label17.AutoSize = True
		Me.label17.Location = New System.Drawing.Point(6, 49)
		Me.label17.Name = "label17"
		Me.label17.Size = New System.Drawing.Size(53, 13)
		Me.label17.TabIndex = 10
		Me.label17.Text = "Instances"
		' 
		' label16
		' 
		Me.label16.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.label16.AutoSize = True
		Me.label16.Location = New System.Drawing.Point(6, 361)
		Me.label16.Name = "label16"
		Me.label16.Size = New System.Drawing.Size(45, 13)
		Me.label16.TabIndex = 9
		Me.label16.Text = "Address"
		' 
		' label15
		' 
		Me.label15.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.label15.AutoSize = True
		Me.label15.Location = New System.Drawing.Point(340, 361)
		Me.label15.Name = "label15"
		Me.label15.Size = New System.Drawing.Size(26, 13)
		Me.label15.TabIndex = 7
		Me.label15.Text = "Port"
		' 
		' tbAddress
		' 
		Me.tbAddress.Anchor = (CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.tbAddress.Enabled = False
		Me.tbAddress.Location = New System.Drawing.Point(57, 358)
		Me.tbAddress.Name = "tbAddress"
		Me.tbAddress.Size = New System.Drawing.Size(277, 20)
		Me.tbAddress.TabIndex = 8
		' 
		' nudPort
		' 
		Me.nudPort.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudPort.Enabled = False
		Me.nudPort.Location = New System.Drawing.Point(372, 358)
		Me.nudPort.Maximum = New Decimal(New Integer() { 65536, 0, 0, 0})
		Me.nudPort.Name = "nudPort"
		Me.nudPort.Size = New System.Drawing.Size(69, 20)
		Me.nudPort.TabIndex = 6
		Me.nudPort.Value = New Decimal(New Integer() { 42222, 0, 0, 0})
		' 
		' lbInstances
		' 
		Me.lbInstances.Anchor = (CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) Or System.Windows.Forms.AnchorStyles.Left) Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.lbInstances.Enabled = False
		Me.lbInstances.FormattingEnabled = True
		Me.lbInstances.Location = New System.Drawing.Point(6, 68)
		Me.lbInstances.Name = "lbInstances"
		Me.lbInstances.Size = New System.Drawing.Size(506, 277)
		Me.lbInstances.TabIndex = 4
'		Me.lbInstances.SelectedIndexChanged += New System.EventHandler(Me.lbInstances_SelectedIndexChanged);
		' 
		' nudListenPort
		' 
		Me.nudListenPort.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.nudListenPort.Enabled = False
		Me.nudListenPort.Location = New System.Drawing.Point(447, 18)
		Me.nudListenPort.Maximum = New Decimal(New Integer() { 65536, 0, 0, 0})
		Me.nudListenPort.Name = "nudListenPort"
		Me.nudListenPort.Size = New System.Drawing.Size(65, 20)
		Me.nudListenPort.TabIndex = 2
		Me.nudListenPort.Value = New Decimal(New Integer() { 42222, 0, 0, 0})
		' 
		' label13
		' 
		Me.label13.Anchor = (CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.label13.AutoSize = True
		Me.label13.Location = New System.Drawing.Point(381, 20)
		Me.label13.Name = "label13"
		Me.label13.Size = New System.Drawing.Size(56, 13)
		Me.label13.TabIndex = 1
		Me.label13.Text = "Listen port"
		' 
		' chbSynchronize
		' 
		Me.chbSynchronize.AutoSize = True
		Me.chbSynchronize.Location = New System.Drawing.Point(6, 19)
		Me.chbSynchronize.Name = "chbSynchronize"
		Me.chbSynchronize.Size = New System.Drawing.Size(223, 17)
		Me.chbSynchronize.TabIndex = 0
		Me.chbSynchronize.Text = "Synchronize subjects with other instances"
		Me.chbSynchronize.UseVisualStyleBackColor = True
'		Me.chbSynchronize.CheckedChanged += New System.EventHandler(Me.chbSynchronize_CheckedChanged);
		' 
		' btnAdd
		' 
		Me.btnAdd.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.btnAdd.Enabled = False
		Me.btnAdd.Location = New System.Drawing.Point(447, 356)
		Me.btnAdd.Name = "btnAdd"
		Me.btnAdd.Size = New System.Drawing.Size(65, 23)
		Me.btnAdd.TabIndex = 5
		Me.btnAdd.Text = "Add"
		Me.btnAdd.UseVisualStyleBackColor = True
'		Me.btnAdd.Click += New System.EventHandler(Me.btnAdd_Click);
		' 
		' SettingsForm
		' 
		Me.AcceptButton = Me.buttonOk
		Me.AutoScaleDimensions = New System.Drawing.SizeF(6F, 13F)
		Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
		Me.CancelButton = Me.buttonCancel
		Me.ClientSize = New System.Drawing.Size(533, 447)
		Me.Controls.Add(Me.tabControl1)
		Me.Controls.Add(Me.buttonCancel)
		Me.Controls.Add(Me.buttonDefault)
		Me.Controls.Add(Me.buttonOk)
		Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
		Me.Icon = (CType(resources.GetObject("$this.Icon"), System.Drawing.Icon))
		Me.Name = "SettingsForm"
		Me.Text = "Settings"
		Me.groupBoxDetection.ResumeLayout(False)
		Me.groupBoxDetection.PerformLayout()
		CType(Me.nudRollBase, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudFaceScale, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudMaxYaw, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudMaxRoll, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudFaceConfidenceThreshold, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudMaxIod, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudMinIod, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.numericUpDown1, System.ComponentModel.ISupportInitialize).EndInit()
		Me.groupBoxExtraction.ResumeLayout(False)
		Me.groupBoxExtraction.PerformLayout()
		Me.groupBox1.ResumeLayout(False)
		Me.groupBox1.PerformLayout()
		CType(Me.nudGenderThr, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudExpressionThr, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudBlinkThr, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudMoutOpenThr, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudGlassesThr, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudDarkGalssesThr, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.numericUpDown7, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.numericUpDown6, System.ComponentModel.ISupportInitialize).EndInit()
		Me.groupBoxIdentification.ResumeLayout(False)
		Me.groupBoxIdentification.PerformLayout()
		CType(Me.numericUpDown11, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.numericUpDown10, System.ComponentModel.ISupportInitialize).EndInit()
		Me.groupBoxMisc.ResumeLayout(False)
		Me.groupBoxMisc.PerformLayout()
		CType(Me.numericUpDown14, System.ComponentModel.ISupportInitialize).EndInit()
		Me.tabControl1.ResumeLayout(False)
		Me.tabPage1.ResumeLayout(False)
		Me.tabPage2.ResumeLayout(False)
		Me.gbSynchronization.ResumeLayout(False)
		Me.gbSynchronization.PerformLayout()
		CType(Me.nudPort, System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.nudListenPort, System.ComponentModel.ISupportInitialize).EndInit()
		Me.ResumeLayout(False)

	End Sub

	#End Region

	Private label2 As System.Windows.Forms.Label
	Private numericUpDown1 As System.Windows.Forms.NumericUpDown
	Private label5 As System.Windows.Forms.Label
	Private groupBoxDetection As System.Windows.Forms.GroupBox
	Private label7 As System.Windows.Forms.Label
	Private label6 As System.Windows.Forms.Label
	Private groupBoxExtraction As System.Windows.Forms.GroupBox
	Private label3 As System.Windows.Forms.Label
	Private label8 As System.Windows.Forms.Label
	Private groupBoxIdentification As System.Windows.Forms.GroupBox
	Private label9 As System.Windows.Forms.Label
	Private label11 As System.Windows.Forms.Label
	Private groupBoxMisc As System.Windows.Forms.GroupBox
	Private numericUpDown14 As System.Windows.Forms.NumericUpDown
	Private label14 As System.Windows.Forms.Label
	Private WithEvents buttonDefault As System.Windows.Forms.Button
	Private buttonOk As System.Windows.Forms.Button
	Private buttonCancel As System.Windows.Forms.Button
	Private nudFaceConfidenceThreshold As System.Windows.Forms.NumericUpDown
	Private WithEvents nudMaxIod As System.Windows.Forms.NumericUpDown
	Private WithEvents nudMinIod As System.Windows.Forms.NumericUpDown
	Private numericUpDown7 As System.Windows.Forms.NumericUpDown
	Private numericUpDown6 As System.Windows.Forms.NumericUpDown
	Private numericUpDown11 As System.Windows.Forms.NumericUpDown
	Private numericUpDown10 As System.Windows.Forms.NumericUpDown
	Private label4 As System.Windows.Forms.Label
	Private label1 As System.Windows.Forms.Label
	Private cmbIdentificationTemplateSize As System.Windows.Forms.ComboBox
	Private cmbEnrollmentTemplateSize As System.Windows.Forms.ComboBox
	Private nudMaxRoll As System.Windows.Forms.NumericUpDown
	Private label10 As System.Windows.Forms.Label
	Private cbDisplayTime As System.Windows.Forms.ComboBox
	Private label12 As System.Windows.Forms.Label
	Private nudMaxYaw As System.Windows.Forms.NumericUpDown
	Private label18 As System.Windows.Forms.Label
	Private chbDetectMoreFaces As System.Windows.Forms.CheckBox
	Private nudRollBase As System.Windows.Forms.NumericUpDown
	Private label20 As System.Windows.Forms.Label
	Private nudFaceScale As System.Windows.Forms.NumericUpDown
	Private label19 As System.Windows.Forms.Label
	Private WithEvents chbDetectGender As System.Windows.Forms.CheckBox
	Private groupBox1 As System.Windows.Forms.GroupBox
	Private label21 As System.Windows.Forms.Label
	Private nudGenderThr As System.Windows.Forms.NumericUpDown
	Private label22 As System.Windows.Forms.Label
	Private nudExpressionThr As System.Windows.Forms.NumericUpDown
	Private label23 As System.Windows.Forms.Label
	Private nudBlinkThr As System.Windows.Forms.NumericUpDown
	Private label24 As System.Windows.Forms.Label
	Private nudMoutOpenThr As System.Windows.Forms.NumericUpDown
	Private label25 As System.Windows.Forms.Label
	Private nudGlassesThr As System.Windows.Forms.NumericUpDown
	Private label26 As System.Windows.Forms.Label
	Private nudDarkGalssesThr As System.Windows.Forms.NumericUpDown
	Private WithEvents chbDetectMouthOpen As System.Windows.Forms.CheckBox
	Private WithEvents chbDetectBlink As System.Windows.Forms.CheckBox
	Private WithEvents chbDetectDarkGlasses As System.Windows.Forms.CheckBox
	Private WithEvents chbDetectGlasses As System.Windows.Forms.CheckBox
	Private WithEvents chbDetectExpression As System.Windows.Forms.CheckBox
	Private tabControl1 As System.Windows.Forms.TabControl
	Private tabPage1 As System.Windows.Forms.TabPage
	Private tabPage2 As System.Windows.Forms.TabPage
	Private gbSynchronization As System.Windows.Forms.GroupBox
	Private WithEvents btnRemove As System.Windows.Forms.Button
	Private label17 As System.Windows.Forms.Label
	Private label16 As System.Windows.Forms.Label
	Private label15 As System.Windows.Forms.Label
	Private tbAddress As System.Windows.Forms.TextBox
	Private nudPort As System.Windows.Forms.NumericUpDown
	Private WithEvents lbInstances As System.Windows.Forms.ListBox
	Private nudListenPort As System.Windows.Forms.NumericUpDown
	Private label13 As System.Windows.Forms.Label
	Private WithEvents chbSynchronize As System.Windows.Forms.CheckBox
	Private WithEvents btnAdd As System.Windows.Forms.Button
End Class