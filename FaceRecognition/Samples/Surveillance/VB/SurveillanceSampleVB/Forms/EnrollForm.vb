Imports Microsoft.VisualBasic
Imports System
Imports System.ComponentModel
Imports System.Drawing
Imports System.IO
Imports System.Windows.Forms
Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.Samples.Code
Imports Neurotec.Surveillance

Namespace Forms
	Partial Public Class EnrollForm
		Inherits Form
#Region "Private types"
		Private Enum LineColor
			Normal
			Blue
			[Error]
		End Enum

		Private Delegate Sub WriteLogDel(ByVal text As String, ByVal color As LineColor)
#End Region

#Region "Private fields"
		Private extractor As NLExtractor
		Private files() As String
		Private faces As FaceRecordCollection
		Private surveillance As NSurveillance
		Private synchronization As DbSynchronizer
#End Region

#Region "Public constructor"
		Public Sub New(ByVal files() As String, ByVal faces As FaceRecordCollection, ByVal surveillance As NSurveillance, ByVal synchronization As DbSynchronizer)
			InitializeComponent()
			Me.files = files
			Me.faces = faces
			Me.surveillance = surveillance
			Me.synchronization = synchronization
		End Sub
#End Region

#Region "Private methods"
		Private Sub WriteLog(ByVal text As String, ByVal lineCol As LineColor)
			If Me.InvokeRequired Then
				Dim del As WriteLogDel = AddressOf WriteLog
				Me.BeginInvoke(del, text, lineCol)
				Return
			End If

			Dim textColor As Color
			Select Case lineCol
				Case LineColor.Blue
					textColor = Color.FromArgb(255, 0, 0, 255)
				Case LineColor.Error
					textColor = Color.FromArgb(255, 196, 0, 0)
				Case Else
					textColor = Color.Black
			End Select
			rtbLog.SelectionColor = textColor
			rtbLog.AppendText(text)
			rtbLog.Focus()
			rtbLog.SelectionStart = rtbLog.TextLength
		End Sub
		Private Sub WriteLog(ByVal color As LineColor, ByVal format As String, ByVal ParamArray args() As Object)
			WriteLog(String.Format(format, args), color)
		End Sub
		Private Sub WriteLog(ByVal format As String, ByVal ParamArray args() As Object)
			WriteLog(LineColor.Normal, format, args)
		End Sub
		Private Sub WriteLog(ByVal text As String)
			WriteLog(text, LineColor.Normal)
		End Sub
		Private Sub backgroundWorker_DoWork(ByVal sender As Object, ByVal e As DoWorkEventArgs) Handles backgroundWorker.DoWork
			
        End Sub

        Private Sub EnrollImage()
            Dim index As Integer = 0
            Try
                Dim filePath As String = files(index)
                If filePath <> "" Then
                    index += 1
                    WriteLog(LineColor.Blue, "[{0}/{1}] {2}" & Constants.vbLf, index, files.Length, filePath)

                    Using image As NImage = NImage.FromFile(filePath)
                        Using grayscale As NGrayscaleImage = image.ToGrayscale()
                            Dim details As NleDetectionDetails = Nothing
                            Dim status As NleExtractionStatus
                            Dim template As NLTemplate = extractor.Extract(grayscale, details, status)
                            If status = NleExtractionStatus.TemplateCreated Then
                                WriteLog("template created successfully" & Constants.vbLf)
                                Dim faceId As String = Path.GetFileNameWithoutExtension(filePath)
                                Dim face As FaceRecord = New FaceRecord(-1, template.Save().ToArray(), faceId, DateTime.Now, False, details, Guid.NewGuid())
                                surveillance.AddTemplate(face.Features, face.Guid)
                                faces.Add(face, image)
                                WriteLog("template added to database successfully" & Constants.vbLf)
                                If synchronization IsNot Nothing Then
                                    synchronization.InsertRecord(face, image)
                                End If
                            Else
                                WriteLog(LineColor.Error, "failed to extract ({0})" & Constants.vbLf, status)
                            End If
                        End Using
                    End Using
                End If
            Catch ex As Exception
                WriteLog(LineColor.Error, "failed to extract image: {0}" & Constants.vbLf, ex)
            End Try

            If backgroundWorker.CancellationPending Then
                WriteLog("canceled", LineColor.Error)
            Else
                WriteLog("done", LineColor.Blue)
            End If
        End Sub


		Private Sub backgroundWorker_RunWorkerCompleted(ByVal sender As Object, ByVal e As RunWorkerCompletedEventArgs) Handles backgroundWorker.RunWorkerCompleted
			btnAction.Text = "Close"
			btnAction.Enabled = True
		End Sub
		Private Sub EnrollForm_FormClosing(ByVal sender As Object, ByVal e As FormClosingEventArgs) Handles MyBase.FormClosing
            'If backgroundWorker.IsBusy Then
            '	e.Cancel = True
            '	backgroundWorker.CancelAsync()
            '	btnAction.Text = "Stopping ..."
            '	btnAction.Enabled = False
            'End If
		End Sub
		Private Sub EnrollForm_Load(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Load
			Dim settings As My.Settings = My.Settings.Default
			extractor = New NLExtractor()

			extractor.MaxIod = CInt(Fix(settings.DetectionMaxIod))
			extractor.MinIod = CInt(Fix(settings.DetectionMinIod))
			extractor.FaceDetectionScaleCount = settings.FaceDetectionScale
			extractor.FaceRollAngleBase = settings.FaceRollAngleBase
			extractor.MaxYawAngleDeviation = settings.MaxYawAngle
			extractor.DetectMoreFaces = settings.DetectMoreFaces
			extractor.FaceConfidenceThreshold = CDbl(settings.DetectionFaceConfidenceThreshold)
			extractor.MaxRollAngleDeviation = CShort(Fix(settings.DetectionMaxRollAngleDeviation))
			extractor.FaceQualityThreshold = CByte(settings.ExtractionFaceQualityThreshold)
			extractor.MaxRecordsPerTemplate = CInt(Fix(settings.ExtractionMaxRecordsPerTemplate))
			extractor.TemplateSize = CType(settings.ExtractionEnrollmentTemplateSize, NleTemplateSize)
			extractor.DetectGender = settings.ExtractionDetectGener
			extractor.GenderConfidenceThreshold = settings.ExtractionGenderConfidenceThreshold
			extractor.DetectExpression = settings.ExtractionDetectExpression
			extractor.ExpressionConfidenceThreshold = settings.ExtractionExpressionConfidenceThreshold
			extractor.DetectBlink = settings.ExtractionDetectBlink
			extractor.BlinkConfidenceThreshold = settings.ExtractionBlinkConfidenceThreshold
			extractor.DetectMouthOpen = settings.ExtractionDetectMouthOpen
			extractor.MouthOpenConfidenceThreshold = settings.ExtractionMouthOpenConfidenceThreshold
			extractor.DetectGlasses = settings.ExtractionDetectGlasses
			extractor.GlassesConfidenceThreshold = settings.ExtractionGlassesConfidenceThreshold
			extractor.DetectDarkGlasses = settings.ExtractionDetectDarkGlasses
			extractor.DarkGlassesConfidenceThreshold = settings.ExtractionDarkGlassesConfidenceThreshold

            'backgroundWorker.RunWorkerAsync()

            EnrollImage()

            Me.Close()
		End Sub
		Private Sub btnAction_Click(ByVal sender As Object, ByVal e As EventArgs) Handles btnAction.Click
			If (Not backgroundWorker.IsBusy) Then
				DialogResult = System.Windows.Forms.DialogResult.OK
			Else
				backgroundWorker.CancelAsync()
				btnAction.Text = "Stopping ..."
				btnAction.Enabled = False
			End If
		End Sub
#End Region
	End Class
End Namespace
