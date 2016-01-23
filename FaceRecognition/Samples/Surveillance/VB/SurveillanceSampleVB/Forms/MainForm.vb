Imports Microsoft.VisualBasic
Imports System.Data
Imports System
Imports System.Collections.Generic
Imports System.Drawing
Imports System.IO
Imports System.Text
Imports System.Threading
Imports System.Windows.Forms
Imports Neurotec.Biometrics
Imports Neurotec.Biometrics.Gui
Imports Neurotec.Devices
Imports Neurotec.Gui
Imports Neurotec.Images
Imports Neurotec.IO
Imports Neurotec.Samples.Code
Imports Neurotec.Surveillance

Namespace Forms

	Partial Public Class MainForm
        Inherits Form

        Dim strID As String = String.Empty
        Dim PathFile As String = String.Empty
        Dim blnSave As Boolean = False

#Region "Private types"

		Private Class ValueInTime(Of T)
			Public Time As DateTime
			Public Value As T

			Public Sub New(ByVal time As DateTime, ByVal value As T)
				Me.Time = time
				Me.Value = value
			End Sub
		End Class

		Private Class FacesInTime
			Inherits ValueInTime(Of NleDetectionDetails())
			Public Sub New(ByVal time As DateTime, ByVal details() As NleDetectionDetails)
				MyBase.New(time, details)
			End Sub
		End Class

		Private Class IdInTime
			Inherits ValueInTime(Of Point)
			Public Sub New(ByVal time As DateTime, ByVal location As Point)
				MyBase.New(time, location)
			End Sub
		End Class

		Private Class DetailsInTime
			Inherits ValueInTime(Of NleDetectionDetails)
			Public Sub New(ByVal time As DateTime, ByVal details As NleDetectionDetails)
				MyBase.New(time, details)
			End Sub
		End Class

		Private Class EventData
			Implements IDisposable
			Public TimeStamp As DateTime
			Public SourceIndex As Integer
			Public FrameIndex As ULong
			Public TraceIndex As Integer
			Public Image As NImage
			Public Bmp As Bitmap
			Public Details As NleDetectionDetails
			Public Faces() As NleFace
			Public ExtractionStatus As NleExtractionStatus
			Public TemplateId As Object
			Public HasTemplateId As Boolean
			Public BestMatches() As String
			Public Template As NLTemplate

			Public Sub New(ByVal sourceIndex As Integer, ByVal timeStamp As DateTime)
				Me.TimeStamp = timeStamp
				Me.SourceIndex = sourceIndex
			End Sub

#Region "IDisposable Members"

			Public Sub Dispose() Implements IDisposable.Dispose
				If Image IsNot Nothing Then
					Image.Dispose()
				End If
				If Template IsNot Nothing Then
					Template.Dispose()
				End If
				If Bmp IsNot Nothing Then
					Bmp.Dispose()
				End If
			End Sub

#End Region
		End Class

		Private Delegate Sub SurveillanceEventDelegate(ByVal data As EventData)

#End Region

#Region "Private fields"

		Private waitingForFrames As New List(Of NLView)()
		Private framesWaitForm As WaitForm

		Private faceRecords As FaceRecordCollection = Nothing
		Private surveillance As NSurveillance = Nothing
		Private isRunning As Boolean = False

		Private deviceForm As DeviceForm = Nothing
		Private activeDevices As New List(Of NCamera)()

		Private miscFlipImage As Boolean
		Private miscMaxTreeNodeCount As Integer

		Private fpsMeasureTime As Double = 3.0 ' in seconds
		Private framesInTime() As Queue(Of DateTime)
		Private faceInTime() As Queue(Of FacesInTime)
		Private idsInTime() As Dictionary(Of Object, IdInTime)
		Private detailInTime() As Dictionary(Of Integer, DetailsInTime)

		Private subjectInfos As New List(Of SubjectInfo)()
		Private traceMap() As Dictionary(Of Integer, TreeNode)

		Private synchronization As DbSynchronizer
		Private synchronize As Boolean
		Private [syncLock] As Object = New Object()

		Private Const MaxWorkingSourcesCount As Integer = 4
		Private Const NotCalcualted As Byte = 254

#End Region

#Region "Public constructor"

		Public Sub New()
			InitializeComponent()

			framesInTime = New Queue(Of DateTime)(MaxWorkingSourcesCount - 1) {}
			faceInTime = New Queue(Of FacesInTime)(MaxWorkingSourcesCount - 1) {}
			idsInTime = New Dictionary(Of Object, IdInTime)(MaxWorkingSourcesCount - 1) {}
			detailInTime = New Dictionary(Of Integer, DetailsInTime)(MaxWorkingSourcesCount - 1) {}
			traceMap = New Dictionary(Of Integer, TreeNode)(MaxWorkingSourcesCount - 1) {}
			For i As Integer = 0 To MaxWorkingSourcesCount - 1
				framesInTime(i) = New Queue(Of DateTime)()
				faceInTime(i) = New Queue(Of FacesInTime)()
				idsInTime(i) = New Dictionary(Of Object, IdInTime)()
				detailInTime(i) = New Dictionary(Of Integer, DetailsInTime)()
				traceMap(i) = New Dictionary(Of Integer, TreeNode)()
			Next i
			For i As Integer = 0 To MaxWorkingSourcesCount - 1
				AddHandler nlViews(i).Paint, AddressOf NlViewPaint
				AddHandler nlViews(i).MouseClick, AddressOf NlViewMouseClick
			Next i
			nlViews.HideAll()

			openFileDialog.Filter = NImages.GetOpenFileFilterString(True, True)
			aboutToolStripMenuItem.Text = "&"c + AboutBox.Name
		End Sub

#End Region

#Region "Public static methods"

		Public Shared Sub ReplaceImage(ByVal nlView As NLView, ByVal image As Bitmap)
			Dim oldImage As Bitmap = nlView.Image
			nlView.Image = image
			If oldImage IsNot Nothing Then
				oldImage.Dispose()
			End If
		End Sub

#End Region

#Region "Private methods"

		Private Sub ResetSettings()
			Dim settings As My.Settings = My.Settings.Default
			' modify surveillance parameters
			surveillance.MaxThreadCount = CInt(Fix(settings.MaxThreadCount))
			surveillance.DetectionMinIod = CInt(Fix(settings.DetectionMinIod))
			surveillance.DetectionMaxIod = CInt(Fix(settings.DetectionMaxIod))
			surveillance.DetectionFaceDetectionScaleCount = settings.FaceDetectionScale
			surveillance.DetectionFaceRollAngleBase = settings.FaceRollAngleBase
			surveillance.DetectionMaxYawAngleDeviation = settings.MaxYawAngle
			surveillance.DetectionDetectMoreFaces = settings.DetectMoreFaces
			surveillance.DetectionFaceConfidenceThreshold = CDbl(settings.DetectionFaceConfidenceThreshold)
			surveillance.DetectionMaxRollAngleDeviation = CShort(Fix(settings.DetectionMaxRollAngleDeviation))
			surveillance.ExtractionFaceQualityThreshold = CByte(settings.ExtractionFaceQualityThreshold)
			surveillance.ExtractionMaxRecordsPerTemplate = CInt(Fix(settings.ExtractionMaxRecordsPerTemplate))
			surveillance.ExtractionEnrollmentTemplateSize = CType(settings.ExtractionEnrollmentTemplateSize, NleTemplateSize)
			surveillance.ExtractionIdentificationTemplateSize = CType(settings.ExtractionIdentificationTemplateSize, NleTemplateSize)
			surveillance.ExtractionDetectGender = settings.ExtractionDetectGener
			surveillance.ExtractionGenderConfidenceThreshold = settings.ExtractionGenderConfidenceThreshold
			surveillance.ExtractionDetectExpression = settings.ExtractionDetectExpression
			surveillance.ExtractionExpressionConfidenceThreshold = settings.ExtractionExpressionConfidenceThreshold
			surveillance.ExtractionDetectBlink = settings.ExtractionDetectBlink
			surveillance.ExtractionBlinkConfidenceThreshold = settings.ExtractionBlinkConfidenceThreshold
			surveillance.ExtractionDetectMouthOpen = settings.ExtractionDetectMouthOpen
			surveillance.ExtractionMouthOpenConfidenceThreshold = settings.ExtractionMouthOpenConfidenceThreshold
			surveillance.ExtractionDetectGlasses = settings.ExtractionDetectGlasses
			surveillance.ExtractionGlassesConfidenceThreshold = settings.ExtractionGlassesConfidenceThreshold
			surveillance.ExtractionDetectDarkGlasses = settings.ExtractionDetectDarkGlasses
			surveillance.ExtractionDarkGlassesConfidenceThreshold = settings.ExtractionDarkGlassesConfidenceThreshold
			surveillance.IdentificationMatchingThreshold = CInt(Fix(settings.IdentificationMatchingThreshold))
			surveillance.IdentificationMaxBestMatchCount = CInt(Fix(settings.IdentificationMaxBestMatchCount))
			' modify sample parameters
			miscFlipImage = settings.MiscFlipImage
			miscMaxTreeNodeCount = CInt(Fix(settings.MiscMaxTreeNodeCount))
			'synchronization
			synchronization.UpdateInstances(settings.Instances)
			synchronize = settings.Synchronize
			synchronization.ListenPort = settings.ListenPort
		End Sub

		Private Sub SurveillanceStart()
			If activeDevices.Count > 0 Then
				Try
					nlViews.HideAll()
					ResetSettings()
					surveillance.Sources.Clear()
					waitingForFrames.Clear()
					For i As Integer = 0 To activeDevices.Count - 1
						nlViews.ShowView(i)
						surveillance.Sources.Add(activeDevices(i))
						waitingForFrames.Add(nlViews(i))
                    Next i

                    'ยังไม่ต้องเปิดกล้อง ยังไม่ได้ใช้
                    framesWaitForm = New WaitForm("Waiting for frames from camera")
                    surveillance.Start()
                    framesWaitForm.ShowDialog()
                    framesWaitForm = Nothing

					EnableMenu()
				Catch ex As IOException
					If framesWaitForm IsNot Nothing Then
						framesWaitForm.NotifyReceived()
						framesWaitForm = Nothing
					End If
					MessageBox.Show(String.Format("Could not start capture: {0}", ex.Message))
				End Try
			End If
		End Sub

		Private Sub SurveillanceStop()
			NGui.InvokeAsync(New MethodInvoker(AddressOf surveillance.Stop))
			Do While Thread.VolatileRead(isRunning)
				Application.DoEvents()
			Loop
			surveillance.Sources.Clear()
			For i As Integer = 0 To nlViews.Count - 1
				ReplaceImage(nlViews(i), Nothing)
			Next i
			EnableMenu()
		End Sub

#End Region

#Region "Private surveillance events"

		Private Sub SurveillanceIsRunningChanged(ByVal sender As Object, ByVal e As EventArgs)
			BeginInvoke(New MethodInvoker(AddressOf OnIsRunningChanged))
		End Sub

		Private Sub OnIsRunningChanged()
			If surveillance.IsRunning Then
				Text = "VeriLook Surveillance SDK Sample - " & ("Running")
			Else
				Text = "VeriLook Surveillance SDK Sample - " & ("Stopped")
			End If
			Thread.VolatileWrite(isRunning, surveillance.IsRunning)
			EnableMenu()
		End Sub

		Private Sub SurveillanceImageCaptured(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
			Dim data As New EventData(e.EventDetails.SourceIndex, e.EventDetails.TimeStamp)
			Using image As NImage = e.EventDetails.OriginalImage
				data.Bmp = image.ToBitmap()
			End Using

			Dim del As SurveillanceEventDelegate = AddressOf OnImageCaptured
			BeginInvoke(del, data)
		End Sub

		Private Sub OnImageCaptured(ByVal data As EventData)
			SyncLock framesInTime(data.SourceIndex)
				framesInTime(data.SourceIndex).Enqueue(data.TimeStamp)
				Dim view As NLView = nlViews(data.SourceIndex)
				If waitingForFrames.Count > 0 AndAlso framesWaitForm IsNot Nothing Then
					waitingForFrames.Remove(view)
					If waitingForFrames.Count = 0 Then
						framesWaitForm.NotifyReceived()
					End If
				End If

				ReplaceImage(view, data.Bmp)
				data.Bmp = Nothing
				data.Dispose()
			End SyncLock
		End Sub

		Private Sub SurveillanceFacesDetected(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
			Dim data As New EventData(e.EventDetails.SourceIndex, e.EventDetails.TimeStamp)
			data.Faces = e.EventDetails.GetFaces()

			Dim del As SurveillanceEventDelegate = AddressOf OnFacesDetected
			BeginInvoke(del, data)
		End Sub

		Private Sub OnFacesDetected(ByVal data As EventData)
			Dim details(data.Faces.Length - 1) As NleDetectionDetails
			For i As Integer = 0 To details.Length - 1
				details(i) = New NleDetectionDetails()
				details(i).FaceAvailable = True
				details(i).Face = data.Faces(i)
			Next i

			SyncLock faceInTime(data.SourceIndex)
				faceInTime(data.SourceIndex).Enqueue(New FacesInTime(data.TimeStamp, details))
			End SyncLock
			data.Dispose()
		End Sub

		Private Sub SurveillanceSubjectAppeared(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
			Dim data As New EventData(e.EventDetails.SourceIndex, e.EventDetails.TimeStamp)
			Using image As NImage = e.EventDetails.OriginalImage
				data.Image = TryCast(image.Clone(), NImage)
			End Using
			data.ExtractionStatus = e.EventDetails.ExtractionStatus
			data.Details = e.EventDetails.DetectionDetails
			data.TraceIndex = e.EventDetails.TraceIndex
			data.FrameIndex = e.EventDetails.FrameIndex

			Dim del As SurveillanceEventDelegate = AddressOf OnSubjectAppeared
			BeginInvoke(del, data)
		End Sub

		Private Sub OnSubjectAppeared(ByVal data As EventData)
			Dim cameraIndex As Integer = data.SourceIndex
			SyncLock traceMap(cameraIndex)
				treeView.BeginUpdate()
				Try
					SyncLock subjectInfos
						Dim subjectAppearedNode As TreeNode = CreateSubjectTrackNode(String.Format("appeared at {0}", data.TimeStamp.ToLocalTime()))
						FillSubjectTrackNode(subjectAppearedNode, data.FrameIndex, data.Details, data.ExtractionStatus)
						Dim nodeSubject As New TreeNode(String.Format("Camera {0} - Subject {1}", cameraIndex + 1, subjectInfos.Count), New TreeNode() {subjectAppearedNode})
						Dim si As New SubjectInfo(subjectInfos.Count, cameraIndex)
						si.DetectionDetails = data.Details
						si.Image = data.Image
						data.Image = Nothing
						nodeSubject.Tag = si
						treeView.Nodes.Insert(0, nodeSubject)
						If treeView.Nodes.Count > miscMaxTreeNodeCount Then
							Dim treeNode As TreeNode = treeView.Nodes(treeView.Nodes.Count - 1)
							treeView.Nodes.Remove(treeNode)
							If treeView.SelectedNode Is treeNode Then
								treeView.SelectedNode = Nothing
							End If
							Dim subjectInfoToRemove As SubjectInfo = TryCast(treeNode.Tag, SubjectInfo)
							treeNode.Tag = Nothing
							If subjectInfoToRemove IsNot Nothing Then
								subjectInfoToRemove.Dispose()
								subjectInfoToRemove = Nothing
							End If
						End If
						traceMap(cameraIndex).Add(data.TraceIndex, nodeSubject)
						subjectInfos.Add(si)
					End SyncLock
				Catch ex As Exception
					MessageBox.Show(String.Format("Error while processing event. Details: {0}", ex.Message))
				Finally
					treeView.EndUpdate()
					data.Dispose()
				End Try
			End SyncLock
		End Sub

		Private Sub SurveillanceSubjectTrack(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
			Dim data As New EventData(e.EventDetails.SourceIndex, e.EventDetails.TimeStamp)
			data.TraceIndex = e.EventDetails.TraceIndex
			data.FrameIndex = e.EventDetails.FrameIndex
			data.ExtractionStatus = e.EventDetails.ExtractionStatus
			data.Details = e.EventDetails.DetectionDetails
			Using image As NImage = e.EventDetails.OriginalImage
				data.Image = TryCast(image.Clone(), NImage)
			End Using

			Dim bmc As NSurveillanceEventDetails.BestMatchCollection = e.EventDetails.BestMatches
			data.HasTemplateId = bmc.Count > 0
			If data.HasTemplateId Then
				data.TemplateId = bmc(0).TemplateId
			End If

			Dim del As SurveillanceEventDelegate = AddressOf OnSubjectTrack
			BeginInvoke(del, data)
		End Sub

		Private Sub OnSubjectTrack(ByVal data As EventData)
			Dim cameraIndex As Integer = data.SourceIndex
			SyncLock traceMap(cameraIndex)
				If (Not traceMap(cameraIndex).ContainsKey(data.TraceIndex)) Then
					Return
				End If
				treeView.BeginUpdate()
				Try
					Dim nodeSubject As TreeNode = traceMap(cameraIndex)(data.TraceIndex)
					Dim subjectTrackNode As TreeNode = Nothing
					Dim timeStamp As DateTime = data.TimeStamp

					If nodeSubject.Nodes.Count = 1 Then
						subjectTrackNode = CreateSubjectTrackNode(String.Format("track at {0}", timeStamp.ToLocalTime()))
						nodeSubject.Nodes.Add(subjectTrackNode)
					ElseIf nodeSubject.Nodes.Count > 1 Then
						subjectTrackNode = nodeSubject.Nodes(1)
					End If
					If subjectTrackNode IsNot Nothing Then
						subjectTrackNode.Text = String.Format("track at {0}", timeStamp.ToLocalTime())
						FillSubjectTrackNode(subjectTrackNode, data.FrameIndex, data.Details, data.ExtractionStatus)
						Dim si As SubjectInfo = CType(nodeSubject.Tag, SubjectInfo)
						If si IsNot Nothing Then
							Dim details As NleDetectionDetails = data.Details
							If si.Image Is Nothing OrElse si.DetectionDetails.Face.Confidence < details.Face.Confidence Then
								If si.Image IsNot Nothing Then
									si.Image.Dispose()
									si.Image = Nothing
								End If

								si.Image = data.Image
								data.Image = Nothing
								si.DetectionDetails = details
							End If

							Dim faceRect As Rectangle = details.Face.Rectangle
							If details.GenderConfidence > 0 OrElse details.ExpressionConfidence > 0 OrElse details.BlinkConfidence > 0 OrElse details.MouthOpenConfidence > 0 OrElse details.GlassesConfidence > 0 OrElse details.DarkGlassesConfidence > 0 Then
								SyncLock detailInTime(cameraIndex)
									Dim item As DetailsInTime = Nothing
									If (Not detailInTime(cameraIndex).TryGetValue(si.Index, item)) Then
										item = New DetailsInTime(timeStamp, details)
										detailInTime(cameraIndex).Add(si.Index, item)
									Else
										item.Time = timeStamp
										item.Value = details
									End If
								End SyncLock
							End If

							If data.HasTemplateId Then
								If data.TemplateId Is Nothing Then
									nodeSubject.Text = String.Format("Camera {0} - Subject {1}", cameraIndex + 1, si.Index)
								Else
									nodeSubject.Text = String.Format("Camera {0} - Subject {1} ({2})", cameraIndex + 1, si.Index, faceRecords.GetFaceIdByGuid(CType(data.TemplateId, Guid)))
									SyncLock idsInTime(cameraIndex)
										Dim timeAndPoint As IdInTime = Nothing
										Dim location As New Point((faceRect.Left + faceRect.Right) / 2, faceRect.Bottom)
										If (Not idsInTime(cameraIndex).TryGetValue(data.TemplateId, timeAndPoint)) Then
											timeAndPoint = New IdInTime(timeStamp, location)
											idsInTime(cameraIndex).Add(data.TemplateId, timeAndPoint)
										Else
											If timeAndPoint.Time < timeStamp Then
												timeAndPoint.Time = timeStamp
												timeAndPoint.Value = location
											End If
										End If
									End SyncLock
								End If
							End If
						End If
					End If
				Catch ex As Exception
					MessageBox.Show(String.Format("Error while processing event. Details: {0}", ex.Message))
				Finally
					treeView.EndUpdate()
					data.Dispose()
				End Try
			End SyncLock
		End Sub

		Private Sub SurveillanceSubjectDisappeared(ByVal sender As Object, ByVal e As NSurveillanceEventArgs)
			Dim data As New EventData(e.EventDetails.SourceIndex, e.EventDetails.TimeStamp)
			data.TraceIndex = e.EventDetails.TraceIndex
			data.Template = e.EventDetails.GetSubjectTemplate()

			Dim bms As NSurveillanceEventDetails.BestMatchCollection = e.EventDetails.BestMatches
			Dim list As New List(Of String)()
			data.HasTemplateId = bms.Count > 0
			If data.HasTemplateId Then
				For Each bm As NsedMatch In bms
					Dim faceId As String = faceRecords.GetFaceIdByGuid(CType(bm.TemplateId, Guid))
					list.Add(String.Format("{0:d3} {1}", bm.Score, faceId))
				Next bm
				data.BestMatches = list.ToArray()
				data.TemplateId = bms(0).TemplateId
			End If

			Dim del As SurveillanceEventDelegate = AddressOf OnSubjectDisappeared
			BeginInvoke(del, data)
		End Sub

		Private Sub OnSubjectDisappeared(ByVal data As EventData)
			Dim cameraIndex As Integer = data.SourceIndex
			SyncLock traceMap(cameraIndex)
				If (Not traceMap(cameraIndex).ContainsKey(data.TraceIndex)) Then
					Return
				End If
				treeView.BeginUpdate()
				Try
					Dim nodeSubject As TreeNode = traceMap(cameraIndex)(data.TraceIndex)
					nodeSubject.NodeFont = New Font(Me.Font, FontStyle.Bold)
					Dim si As SubjectInfo = CType(nodeSubject.Tag, SubjectInfo)
					If si IsNot Nothing Then
						Dim nodeTimeStamp As New TreeNode(String.Format("TimeStamp: {0}", data.TimeStamp.ToLocalTime()))
						Dim nodeDisappeared As New TreeNode(String.Format("disappeared at {0}", data.TimeStamp.ToLocalTime()), New TreeNode() {nodeTimeStamp, CreateBestMatchesNode(data.BestMatches)})
						If data.Template IsNot Nothing Then
							nodeDisappeared.Nodes.Add("Contains successfully generated template")
							si.Template = data.Template
							data.Template = Nothing
						Else
							nodeSubject.ForeColor = Color.DarkGray
						End If
						nodeSubject.Nodes.Add(nodeDisappeared)
						If data.HasTemplateId Then
							Dim templateId As Object = data.TemplateId
							If templateId Is Nothing Then
								nodeSubject.Text = String.Format("Camera {0} - Subject {1}", cameraIndex + 1, si.Index)
							Else
								Dim faceId As String = faceRecords.GetFaceIdByGuid(CType(data.TemplateId, Guid))
								nodeSubject.Text = String.Format("Camera {0} - Subject {1} ({2})", cameraIndex + 1, si.Index, faceId)
							End If
						Else
							nodeSubject.Text = nodeSubject.Text
						End If
					End If
				Catch ex As Exception
					MessageBox.Show(String.Format("Error while processing event. Details: {0}", ex.Message))
				Finally
					treeView.EndUpdate()
				End Try

				traceMap(cameraIndex).Remove(data.TraceIndex)
				data.Dispose()
			End SyncLock
			TreeViewAfterSelect(Nothing, Nothing)
		End Sub

#End Region

#Region "Private form events"

		Private Sub MainFormLoad(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Load
			' create surveillance instance
			Try
				surveillance = New NSurveillance(CType(Nothing, System.Threading.SynchronizationContext))
			Catch ex As Exception
				MessageBox.Show(String.Format("Error while creating NSurveillance object. Details: {0}", ex.Message))
				Close()
				Return
			End Try

			faceRecords = New FaceRecordCollection()
			synchronization = New DbSynchronizer(String.Empty, 0)

			' reset settings
			ResetSettings()

			AddHandler synchronization.OnRecordAdded, AddressOf SynchronizationOnRecordAdded
			AddHandler synchronization.OnRecordsRemoved, AddressOf SynchronizationOnRecordsRemoved
			If synchronize Then
                synchronization.StartListener()
			End If

			' load watch list
			For Each faceRecord As FaceRecord In faceRecords
				surveillance.AddTemplate(faceRecord.Features, faceRecord.Guid)
			Next faceRecord
			' set events
			AddHandler surveillance.IsRunningChanged, AddressOf SurveillanceIsRunningChanged
			AddHandler surveillance.ImageCaptured, AddressOf SurveillanceImageCaptured
			AddHandler surveillance.FacesDetected, AddressOf SurveillanceFacesDetected
			AddHandler surveillance.SubjectAppeared, AddressOf SurveillanceSubjectAppeared
			AddHandler surveillance.SubjectTrack, AddressOf SurveillanceSubjectTrack
            AddHandler surveillance.SubjectDisappeared, AddressOf SurveillanceSubjectDisappeared

            'Me.WindowState = FormWindowState.Minimized
		End Sub

        Private Sub MainFormShown(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Shown

            ChooseDevice()
            SurveillanceStart()
            Me.Opacity = 100
        End Sub

		Private Sub MainFormClosing(ByVal sender As Object, ByVal e As FormClosingEventArgs) Handles MyBase.FormClosing
			If surveillance IsNot Nothing Then
				SurveillanceStop()
				RemoveHandler surveillance.IsRunningChanged, AddressOf SurveillanceIsRunningChanged
				RemoveHandler surveillance.ImageCaptured, AddressOf SurveillanceImageCaptured
				RemoveHandler surveillance.FacesDetected, AddressOf SurveillanceFacesDetected
				RemoveHandler surveillance.SubjectAppeared, AddressOf SurveillanceSubjectAppeared
				RemoveHandler surveillance.SubjectTrack, AddressOf SurveillanceSubjectTrack
				RemoveHandler surveillance.SubjectDisappeared, AddressOf SurveillanceSubjectDisappeared
				surveillance.Dispose()
			End If
			If synchronization IsNot Nothing Then
				synchronization.Dispose()
			End If
			If faceRecords IsNot Nothing Then
				faceRecords.Close()
			End If
		End Sub

        Private Sub AboutToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            AboutBox.Show()
        End Sub

		Private Sub NlViewPaint(ByVal sender As Object, ByVal e As PaintEventArgs)
			Dim view As NLView = CType(sender, NLView)
			If view.Image Is Nothing Then
				Return
            End If

            Try
                If blnSave Then
                    'เมื่อคลิกปุ่ม Save รูป
                    Try
                        view.Image.Save(PathFile, System.Drawing.Imaging.ImageFormat.Jpeg)
                        Application.Exit()
                    Catch ex As Exception

                    End Try

                End If
            Catch ex As Exception

            End Try

			Dim constant As Integer = My.Settings.Default.MiscDisplayTime
			Dim now As DateTime = DateTime.Now.ToUniversalTime()
			Dim cameraIndex As Integer = nlViews.IndexOf(sender)
			SyncLock framesInTime(cameraIndex)
				Do While framesInTime(cameraIndex).Count > 0 AndAlso (now - framesInTime(cameraIndex).Peek()).TotalSeconds > fpsMeasureTime
					framesInTime(cameraIndex).Dequeue()
				Loop
			End SyncLock
			Dim g As Graphics = e.Graphics
			Dim maxFaceCount As Integer = 0
			SyncLock faceInTime(cameraIndex)
				For Each pair As FacesInTime In faceInTime(cameraIndex)
					Dim length As Integer = pair.Value.Length
					If length > maxFaceCount Then
						maxFaceCount = length
					End If
				Next pair
				If maxFaceCount > 0 Then
					Dim dequeueCount As Integer = 0
					For Each pair As FacesInTime In faceInTime(cameraIndex)
						Dim ts As TimeSpan = now - pair.Time
						Dim alpha As Integer = (constant * maxFaceCount - CInt(Fix(Math.Round(ts.TotalMilliseconds)))) / maxFaceCount
						If (alpha > 255) Then
							alpha = 255
						Else
							alpha = alpha
						End If
						If alpha > 0 Then
							alpha = 255
							Using pen As New Pen(Color.FromArgb(alpha, Color.GreenYellow), 2)
								For Each details As NleDetectionDetails In pair.Value
									g.DrawRectangle(pen, details.Face.Rectangle)
								Next details
                            End Using

						Else
                            dequeueCount += 1

						End If
					Next pair
					For i As Integer = 0 To dequeueCount - 1
						faceInTime(cameraIndex).Dequeue()
					Next i
				End If
				If maxFaceCount = 0 Then
					maxFaceCount = 1
				Else
					maxFaceCount = maxFaceCount
				End If
				SyncLock detailInTime(cameraIndex)
					Dim removals As New List(Of Integer)()
					Using f As New Font(Font.FontFamily, 10, FontStyle.Bold)
						For Each pair As KeyValuePair(Of Integer, DetailsInTime) In detailInTime(cameraIndex)
							Dim item As DetailsInTime = pair.Value
							Dim ts As TimeSpan = now - item.Time
							Dim alpha As Integer = (constant * 2 * maxFaceCount - CInt(Fix(Math.Round(ts.TotalMilliseconds)))) / (maxFaceCount * 2)
                            If alpha > 0 Then
                                Dim value As String = GetFacePropertiesString(item.Value)
                                If String.IsNullOrEmpty(value) Then
                                    Continue For
                                End If
                                Using b As New SolidBrush(Color.GreenYellow)
                                    Dim rect As Rectangle = item.Value.Face.Rectangle
                                    Dim size As SizeF = g.MeasureString(value, f, rect.Width * 2)
                                    Dim layoutRect As New RectangleF(rect.Left, rect.Top - size.Height - 5, rect.Width * 2, size.Height)
                                    If size.Width > rect.Width Then
                                        layoutRect.X -= rect.Width \ 3
                                    End If
                                    g.DrawString(value, f, b, layoutRect)
                                End Using
                            Else
                                removals.Add(pair.Key)
                            End If
						Next pair
					End Using
					For Each key As Integer In removals
						detailInTime(cameraIndex).Remove(key)
					Next key
				End SyncLock
				SyncLock idsInTime(cameraIndex)
                    Using f As New Font(Font.FontFamily, 14, FontStyle.Bold)
                        Try
                            Dim removals As New List(Of Object)()
                            For Each entry As KeyValuePair(Of Object, IdInTime) In idsInTime(cameraIndex)
                                Dim pair As IdInTime = entry.Value
                                Dim ts As TimeSpan = now - pair.Time
                                Dim alpha As Integer = (constant * 2 * maxFaceCount - CInt(Fix(Math.Round(ts.TotalMilliseconds)))) / (maxFaceCount * 2)
                                If alpha > 0 Then
                                    'เมื่อตรวจสอบพบว่ารูปภาพติด BlackList
                                    Using b As New SolidBrush(Color.GreenYellow)
                                        Dim faceId As String = faceRecords.GetFaceIdByGuid(CType(entry.Key, Guid))
                                        'Put Function To Sent Data
                                        g.DrawString(faceId, f, b, pair.Value.X - g.MeasureString(faceId, f).Width \ 2, pair.Value.Y + 5)
                                        'Call Method to close form first
                                        'get faceId to parameter
                                        'open next form or other function
                                        Try
                                            Dim PathTempBlackList As String = Application.StartupPath & "\TempBlackList\"
                                            If Directory.Exists(PathTempBlackList) = False Then
                                                Directory.CreateDirectory(PathTempBlackList)
                                            End If

                                            Dim TempBlackListFile As String = PathTempBlackList & faceId.Trim & ".jpg"
                                            view.Image.Save(TempBlackListFile, System.Drawing.Imaging.ImageFormat.Jpeg)
                                            'Return to textfile and close
                                            If File.Exists(TempBlackListFile) = True Then
                                                CreateTempTextFile(Application.StartupPath & "\IsBlacklist.txt", TempBlackListFile)
                                                Application.Exit()
                                                Exit Sub
                                            End If
                                        Catch ex As Exception

                                        End Try
                                    End Using
                                Else
                                    removals.Add(entry.Key)
                                End If
                            Next entry
                            For Each key As Object In removals
                                idsInTime(cameraIndex).Remove(key)
                            Next key
                        Catch ex As Exception

                        End Try
                        
                    End Using
				End SyncLock
				If framesInTime(cameraIndex).Count > 0 Then
					SyncLock framesInTime(cameraIndex)
						Using f As New Font(Font.FontFamily, 12, FontStyle.Bold)
							Using b As New SolidBrush(Color.GreenYellow)
								Dim fps As String = String.Format("{0:f0} fps, watch list = {1} subjects", framesInTime(cameraIndex).Count / fpsMeasureTime, faceRecords.Count)
								g.DrawString(fps, f, b, 5, 5)
							End Using
						End Using
					End SyncLock
				End If
			End SyncLock
        End Sub

        Private Sub CreateTempTextFile(ByVal FileName As String, ByVal ReturnData As String)
            Try
                Dim txtFile As New StreamWriter(FileName, False, System.Text.Encoding.UTF8, ReturnData.Length)
                With txtFile
                    .Write(ReturnData)
                    .Close()
                End With
            Catch ex As Exception

            End Try
        End Sub

		Private Sub NlViewMouseClick(ByVal sender As Object, ByVal e As MouseEventArgs)
            'If e.Button = MouseButtons.Right Then
            '	Dim view As NLView = TryCast(sender, NLView)
            '	contextMnuStrip.Tag = view
            '	contextMnuStrip.Show(view, e.Location)
            'End If
		End Sub

        Private Sub ButtonAddToWatchListClick(ByVal sender As Object, ByVal e As EventArgs)
            Dim selected As TreeNode = TreeView.SelectedNode
            Dim si As SubjectInfo = CType(selected.Tag, SubjectInfo)
            Dim addForm As New AddToWatchListForm()
            If addForm.ShowDialog(si) = System.Windows.Forms.DialogResult.OK Then
                If addForm.SubjectId <> String.Empty Then
                    Try
                        Dim features As NBuffer = si.Template.Save()
                        Dim guid As Guid = guid.NewGuid()
                        surveillance.AddTemplate(features, guid)
                        Dim faceRecord As New FaceRecord(-1, features.ToArray(), addForm.SubjectId, DateTime.Now, False, si.DetectionDetails, guid)
                        faceRecords.Add(faceRecord, si.Image)
                        If synchronize Then
                            synchronization.InsertRecord(faceRecord, si.Image)
                        End If
                        selected.Text = String.Format("Camera {0} - Subject {1} ({2})", si.SourceIndex + 1, si.Index, addForm.SubjectId)
                    Catch ex As Exception
                        MessageBox.Show("Template was not added to the watch list. " & ex.Message, "Add To Watch List")
                    End Try
                Else
                    MessageBox.Show("Template was not added to the watch list. Specify non-empty subject id.", "Add To Watch List")
                End If
            End If
        End Sub

        Private Sub ExitToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            Close()
        End Sub

        Private Sub ChooseDeviceToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            SurveillanceStop()
            ChooseDevice()
            SurveillanceStart()
        End Sub

        Private Sub SettingsToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            Using settingsForm As New SettingsForm()
                settingsForm.LoadSettings()
                If settingsForm.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
                    Try
                        SurveillanceStop()
                        settingsForm.SaveSettings()
                        synchronization.StopListener()
                        ResetSettings()
                        If synchronize Then
                            synchronization.StartListener()
                        End If
                        SurveillanceStart()
                    Catch ex As Exception
                        MessageBox.Show(String.Format("Changing of settings failed: {0}", ex.Message), "Change Settings")
                    End Try
                End If
            End Using
        End Sub

        Private Sub WatchListToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            Using watchListForm As New WatchListForm()
                watchListForm.FaceRecords = faceRecords
                watchListForm.ShowDialog()
            End Using
        End Sub

        Private Sub ClearWatchListToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            If MessageBox.Show("Are you sure you want to delete all subjects with saved names?", "Confirm clear", MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) = System.Windows.Forms.DialogResult.Yes Then
                SurveillanceStop()
                SyncLock [syncLock]
                    surveillance.RemoveAllTemplates()
                    Dim items(faceRecords.Count - 1) As Guid
                    For i As Integer = 0 To items.Length - 1
                        items(i) = faceRecords(i).Guid
                    Next i
                    faceRecords.Clear()
                    If synchronize Then
                        synchronization.RemoveRecords(items)
                    End If
                End SyncLock
                SurveillanceStart()
            End If
        End Sub

        Private Sub TreeViewAfterSelect(ByVal sender As Object, ByVal e As TreeViewEventArgs)
            For Each tn As TreeNode In TreeView.Nodes
                If tn.IsSelected Then
                    Dim si As SubjectInfo = CType(tn.Tag, SubjectInfo)
                    If si.Template IsNot Nothing Then
                        buttonAddToWatchList.Enabled = True
                        Return
                    Else
                        Exit For
                    End If
                End If
            Next tn
            If buttonAddToWatchList.Enabled Then
                buttonAddToWatchList.Enabled = False
            End If
        End Sub

        Private Sub EnrollFromImagesToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            Dim TempEnrollImage As String = Application.StartupPath & "\TempEnrollImage\"
            Dim StartEnroll As Boolean = True
            If Directory.Exists(TempEnrollImage) = False Then
                Try
                    Directory.CreateDirectory(TempEnrollImage)
                Catch ex As Exception
                    StartEnroll = False
                End Try
            End If

            If StartEnroll = True Then
                Dim files() As String = Directory.GetFiles(TempEnrollImage) 'openFileDialog.FileNames
                Dim cnt As Integer = files.Length - 1
                Dim tempList(cnt) As String
                Dim index As Integer = 0
                Dim strID As String = String.Empty
                Dim blnCall As Boolean = False
                For Each face As FaceRecord In faceRecords
                    strID &= face.FaceId.Trim & ","
                Next

                Dim EnrolledImagePath As String = Application.StartupPath & "\EnrolledImage"
                If files.Length > 0 Then
                    If Directory.Exists(EnrolledImagePath) = False Then
                        Try
                            Directory.CreateDirectory(EnrolledImagePath)
                        Catch ex As Exception
                            StartEnroll = False
                        End Try
                    End If
                Else
                    StartEnroll = False
                End If

                If StartEnroll = True Then
                    For i As Integer = 0 To files.Length - 1
                        Try
                            Dim arrFileName As String() = files(i).Split("\")
                            Dim strFileName As String = arrFileName(arrFileName.Length - 1).Split(".")(0).Trim

                            'Copy File to EnrolledImage Folder
                            Dim EnrolledFile As String = EnrolledImagePath & "\" & strFileName & ".JPG"
                            If File.Exists(EnrolledFile) = True Then
                                Try
                                    File.SetAttributes(EnrolledFile, FileAttributes.Normal)
                                    File.Delete(EnrolledFile)
                                Catch ex As Exception

                                End Try
                            End If

                            File.Copy(files(i), EnrolledFile)
                            Dim blnCheck As Boolean = strID.Contains(strFileName)
                            If blnCheck <> True Then
                                tempList(index) = EnrolledFile
                                index += 1
                                blnCall = True
                            End If

                            Try
                                File.SetAttributes(files(i), FileAttributes.Normal)
                                File.Delete(files(i))
                            Catch ex As Exception

                            End Try
                        Catch ex As Exception
                            tempList(index) = files(i)
                            index += 1
                        End Try
                    Next
                    If blnCall Then
                        Dim enrollDlg As EnrollForm
                        If synchronize Then
                            enrollDlg = New EnrollForm(tempList, faceRecords, surveillance, synchronization)
                        Else
                            enrollDlg = New EnrollForm(tempList, faceRecords, surveillance, Nothing)
                        End If
                        enrollDlg.ShowDialog()
                    End If
                End If
            End If
        End Sub

        'Call this function to Enroll your Image Directory to generate Alghorityhm
        Private Sub EnrollFromDirectoryToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            If folderBrowserDialog.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
                Dim files() As String = GetAllImages(folderBrowserDialog.SelectedPath)
                Dim enrollDlg As EnrollForm
                If synchronize Then
                    enrollDlg = New EnrollForm(files, faceRecords, surveillance, synchronization)
                Else
                    enrollDlg = New EnrollForm(files, faceRecords, surveillance, Nothing)
                End If
                enrollDlg.ShowDialog()
            End If
        End Sub

        Private Sub ContextMenuStripItemClicked(ByVal sender As Object, ByVal e As ToolStripItemClickedEventArgs)
            Dim view As NLView = TryCast(contextMnuStrip.Tag, NLView)
            If view Is Nothing Then
                Return
            End If

            If e.ClickedItem Is removeToolStripMenuItem Then
                Dim index As Integer = nlViews.IndexOf(view)
                nlViews.HideView(index)
                SurveillanceStop()
                If index < activeDevices.Count Then
                    activeDevices.RemoveAt(index)
                End If
                SurveillanceStart()
                EnableMenu()
            Else
                Dim zoom As Single = Single.NaN
                If e.ClickedItem Is zoomTo50ToolStripMenuItem Then
                    zoom = 0.5F
                ElseIf e.ClickedItem Is zoom100ToolStripMenuItem Then
                    zoom = 1.0F
                ElseIf e.ClickedItem Is zoom200ToolStripMenuItem Then
                    zoom = 2.0F
                Else
                    Dim viewSize As New Size(view.Width - 5, view.Height - 5)
                    Dim imgSize As Size
                    If view.Image IsNot Nothing Then
                        imgSize = view.Image.Size
                    Else
                        imgSize = viewSize
                    End If
                    zoom = Math.Min(viewSize.Width / CSng(imgSize.Width), viewSize.Height / CSng(imgSize.Height))
                End If
                view.Zoom = zoom
            End If
        End Sub

        Private Sub StartSurveillanceToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            SurveillanceStart()
        End Sub

        Private Sub StopSurveillanceToolStripMenuItemClick(ByVal sender As Object, ByVal e As EventArgs)
            SurveillanceStop()
        End Sub

#End Region

#Region "Private methods"

		Private Function CreateBestMatchesNode(ByVal matches() As String) As TreeNode
			Dim nodeBestMatches As New TreeNode(String.Format("Top {0} of Best Matches", surveillance.IdentificationMaxBestMatchCount))
			If matches IsNot Nothing AndAlso matches.Length > 0 Then
				For Each item As String In matches
					nodeBestMatches.Nodes.Add(item)
				Next item
			Else
				nodeBestMatches.Nodes.Add("no matches found")
			End If
			Return nodeBestMatches
		End Function

		Private Function CreateSubjectTrackNode(ByVal text As String) As TreeNode
			Dim node As New TreeNode(text, New TreeNode() {New TreeNode(), New TreeNode(), New TreeNode(), New TreeNode(), New TreeNode(), New TreeNode(), New TreeNode(), New TreeNode(), New TreeNode()})

			Return node
		End Function

		Private Function GetFacePropertiesString(ByVal details As NleDetectionDetails) As String
			Dim builder As New StringBuilder()
			If details.GenderConfidence > 0 AndAlso details.GenderConfidence <= 100 Then
				builder.Append(details.Gender.ToString())
			End If
			If details.ExpressionConfidence > 0 AndAlso details.ExpressionConfidence <= 100 AndAlso details.Expression <> NLExpression.Unknown Then
				If builder.Length > 0 Then
					builder.Append(", ")
				End If
				builder.Append(details.Expression.ToString())
			End If
			If (details.Properties And NLProperties.Blink) = NLProperties.Blink AndAlso details.BlinkConfidence > 0 AndAlso details.BlinkConfidence <= 100 Then
				If builder.Length > 0 Then
					builder.Append(", ")
				End If
				builder.Append("Blink")
			End If
			If (details.Properties And NLProperties.MouthOpen) = NLProperties.MouthOpen AndAlso details.MouthOpenConfidence > 0 AndAlso details.MouthOpenConfidence <= 100 Then
				If builder.Length > 0 Then
					builder.Append(", ")
				End If
				builder.Append("Mouth open")
			End If
			If (details.Properties And NLProperties.Glasses) = NLProperties.Glasses AndAlso details.GlassesConfidence > 0 AndAlso details.GlassesConfidence <= 100 Then
				If builder.Length > 0 Then
					builder.Append(", ")
				End If
				builder.Append("Glasses")
			End If
			If (details.Properties And NLProperties.DarkGlasses) = NLProperties.DarkGlasses AndAlso details.DarkGlassesConfidence > 0 AndAlso details.DarkGlassesConfidence <= 100 Then
				If builder.Length > 0 Then
					builder.Append(", ")
				End If
				builder.Append("Blink")
			End If
			Return builder.ToString()
		End Function

		Private Sub FillSubjectTrackNode(ByVal node As TreeNode, ByVal frameIndex As ULong, ByVal details As NleDetectionDetails, ByVal status As NleExtractionStatus)
			node.Nodes(0).Text = String.Format("FrameIndex: {0}", frameIndex)
			Dim format As String = "DetectionDetails: eyes at ({0}) and ({1})"
			Dim leftEye As String
			If details.LeftEyeCenter.Confidence = 0 Then
				leftEye = "not deteced"
			Else
				leftEye = String.Format("{0}; {1}", details.LeftEyeCenter.X, details.LeftEyeCenter.Y)
			End If
			Dim rightEye As String
			If details.RightEyeCenter.Confidence = 0 Then
				rightEye = "not deteced"
			Else
				rightEye = String.Format("{0}; {1}", details.RightEyeCenter.X, details.RightEyeCenter.Y)
			End If
			node.Nodes(1).Text = String.Format(format, leftEye, rightEye)
			node.Nodes(2).Text = String.Format("ExtractionStatus: {0}", status)

			Dim conf As Byte
			Dim text As String
			Dim contains As Boolean
			If details.GenderConfidence <> NotCalcualted Then
				conf = details.GenderConfidence
				If conf = 0 OrElse conf = 255 Then
					text = "not detected"
				Else
					text = String.Format("{0}, Confidence: {1}", details.Gender, details.GenderConfidence)
				End If
				node.Nodes(3).Text = String.Format("Gender: {0}", text)
			Else
				node.Nodes(3).Text = "Gender: not detecting"
			End If

			If details.ExpressionConfidence <> NotCalcualted Then
				conf = details.ExpressionConfidence
				If conf = 0 OrElse conf = 255 Then
					text = "not detected"
				Else
					text = String.Format("{0}, Confidence: {1}", details.Expression, details.ExpressionConfidence)
				End If
				node.Nodes(4).Text = String.Format("Expression: {0}", text)
			Else
				node.Nodes(4).Text = "Expression: not detecting"
			End If

			If details.BlinkConfidence <> NotCalcualted Then
				conf = details.BlinkConfidence
				contains = (NLProperties.Blink And details.Properties) = NLProperties.Blink
				text = "not detected"
				If conf > 0 AndAlso conf <= 100 Then
					If contains Then
						text = String.Format("{0}, Confidence: {1}", "Yes", conf)
					Else
						text = String.Format("{0}, Confidence: {1}", "No", conf)
					End If
				End If
				node.Nodes(5).Text = String.Format("Blink: {0}", text)
			Else
				node.Nodes(5).Text = "Blink: not detecting"
			End If

			If details.MouthOpenConfidence <> NotCalcualted Then
				conf = details.MouthOpenConfidence
				contains = (NLProperties.MouthOpen And details.Properties) = NLProperties.MouthOpen
				text = "not detected"
				If conf > 0 AndAlso conf <= 100 Then
					If contains Then
						text = String.Format("{0}, Confidence: {1}", "Yes", conf)
					Else
						text = String.Format("{0}, Confidence: {1}", "No", conf)
					End If
				End If
				node.Nodes(6).Text = String.Format("Mouth open: {0}", text)
			Else
				node.Nodes(6).Text = "Mouth open: not detecting"
			End If

			If details.GlassesConfidence <> NotCalcualted Then
				conf = details.GlassesConfidence
				contains = (NLProperties.Glasses And details.Properties) = NLProperties.Glasses
				text = "not detected"
				If conf > 0 AndAlso conf <= 100 Then
					If contains Then
						text = String.Format("{0}, Confidence: {1}", "Yes", conf)
					Else
						text = String.Format("{0}, Confidence: {1}", "No", conf)
					End If
				End If
				node.Nodes(7).Text = String.Format("Glasses: {0}", text)
			Else
				node.Nodes(7).Text = "Glasses: not detecting"
			End If

			If details.DarkGlassesConfidence <> NotCalcualted Then
				conf = details.DarkGlassesConfidence
				contains = (NLProperties.DarkGlasses And details.Properties) = NLProperties.DarkGlasses
				text = "not detected"
				If conf > 0 AndAlso conf <= 100 Then
					If contains Then
						text = String.Format("{0}, Confidence: {1}", "Yes", conf)
					Else
						text = String.Format("{0}, Confidence: {1}", "No", conf)
					End If
				End If
				node.Nodes(8).Text = String.Format("Dark Glasses: {0}", text)
			Else
				node.Nodes(8).Text = "Dark Glasses: not detecting"
			End If
		End Sub

		Private Sub OnStopped()
			For i As Integer = 0 To MaxWorkingSourcesCount - 1
				SyncLock traceMap(i)
					For Each node As TreeNode In traceMap(i).Values
						node.NodeFont = New Font(Me.Font, FontStyle.Bold)
						node.ForeColor = Color.DarkGray
						Dim si As SubjectInfo = TryCast(node.Tag, SubjectInfo)
						If si IsNot Nothing Then
							node.Text = String.Format("Camera {0} - Subject {1}", i + 1, si.Index)
						End If
					Next node
					traceMap(i).Clear()
				End SyncLock
			Next i
		End Sub

		Private Sub EnableMenu()
			If Me.InvokeRequired Then
				Me.BeginInvoke(New MethodInvoker(AddressOf EnableMenu))
				Return
			End If
			If Thread.VolatileRead(isRunning) Then
				stopSurveillanceToolStripMenuItem.Enabled = True
				startSurveillanceToolStripMenuItem.Enabled = False
			Else
				OnStopped()
				stopSurveillanceToolStripMenuItem.Enabled = False
				startSurveillanceToolStripMenuItem.Enabled = activeDevices.Count > 0
			End If
		End Sub

		Private Sub SynchronizationOnRecordsRemoved(ByVal guids() As Guid)
			SyncLock [syncLock]
				For Each item As Guid In guids
					If faceRecords.Remove(item) Then
						surveillance.RemoveTemplate(item)
					End If
				Next item
			End SyncLock
		End Sub

		Private Sub SynchronizationOnRecordAdded(ByVal record As FaceRecord, ByVal image As NImage)
			SyncLock [syncLock]
				faceRecords.Add(record, image)
				surveillance.AddTemplate(record.Features, record.Guid)
			End SyncLock
		End Sub

		Private Sub ChooseDevice()
			If activeDevices.Count >= MaxWorkingSourcesCount Then
				MessageBox.Show("Only 4 devices are supported in this sample" & Constants.vbLf)
				Return
			End If

			deviceForm = New DeviceForm(surveillance.DeviceManager, activeDevices)
			Using deviceForm
				If deviceForm.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
					activeDevices.Add(deviceForm.ActiveDevice)
				End If
			End Using
		End Sub

		Private Function GetAllImages(ByVal path As String) As String()
			Dim results As New List(Of String)()
			Dim extensions() As String = NImages.GetOpenFileFilter().Split(";"c)
			Dim allFiles() As String = Directory.GetFiles(path, "*", SearchOption.AllDirectories)
			For i As Integer = 0 To extensions.Length - 1
				Dim extension As String = extensions(i).Replace("*.", String.Empty)
				For Each file As String In allFiles
					If file.EndsWith(extension) Then
						results.Add(file)
					End If
				Next file
			Next i
			Return results.ToArray()
		End Function

#End Region


        Private Sub TimerEnrollImage_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TimerEnrollImage.Tick
            TimerEnrollImage.Enabled = False
            EnrollFromImagesToolStripMenuItemClick(Nothing, Nothing)
            Try
                If File.Exists(Application.StartupPath & "\ConfigPathFile.txt") = True Then
                    Dim ConfigFile As String = File.ReadAllText(Application.StartupPath & "\ConfigPathFile.txt")

                    If File.Exists(ConfigFile) = True Then
                        Dim ini As New Org.Mentalis.Files.IniReader(ConfigFile)
                        Dim IDPath As String = ini.ReadString("FaceRecognition", "SurveillanceSamplePath")
                        Dim TmpCnt As Integer = 0
                        Dim stw As New StreamReader(IDPath & "cnt.txt")
                        With stw
                            TmpCnt = Convert.ToInt16(.ReadLine())
                            .Close()
                        End With
                        Dim intCnt As Integer = 0
                        For Each face As FaceRecord In faceRecords
                            intCnt += 1
                        Next
                        If TmpCnt < intCnt Then
                            SurveillanceStop()
                            SyncLock [syncLock]
                                surveillance.RemoveAllTemplates()
                                Dim items(faceRecords.Count - 1) As Guid
                                For i As Integer = 0 To items.Length - 1
                                    items(i) = faceRecords(i).Guid
                                Next i
                                faceRecords.Clear()
                                If synchronize Then
                                    synchronization.RemoveRecords(items)
                                End If
                            End SyncLock
                            SurveillanceStart()
                        End If
                    End If
                End If
            Catch ex As Exception

            End Try
            TimerEnrollImage.Enabled = True
        End Sub

        Private Sub cmbTakePhoto_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmbTakePhoto.Click
            If File.Exists(Application.StartupPath & "\ConfigPathFile.txt") = True Then
                Dim ConfigPath As String = File.ReadAllText(Application.StartupPath & "\ConfigPathFile.txt")

                If File.Exists(ConfigPath) = True Then
                    Dim ini As New Org.Mentalis.Files.IniReader(ConfigPath)
                    Dim IDPath As String = ini.ReadString("FaceRecognition", "SurveillanceSamplePath")
                    Dim Path As String = ini.ReadString("VRM", "VRMPath")

                    Try
                        Dim stw As New StreamReader(IDPath & "/ID.txt")
                        With stw
                            strID = .ReadLine()
                            .Close()
                        End With

                        Dim FileName As String = strID.ToString().Trim & ".jpg"
                        If Directory.Exists(Path) = False Then
                            Directory.CreateDirectory(Path)
                        End If

                        PathFile = Path & FileName
                        If File.Exists(PathFile) = True Then
                            Try
                                File.SetAttributes(PathFile, FileAttributes.Normal)
                                File.Delete(PathFile)
                            Catch ex As Exception

                            End Try
                        End If
                        blnSave = True
                    Catch ex As Exception

                    End Try
                Else
                    MessageBox.Show("Cannot open Config File " & ConfigPath, "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error)
                End If
            Else
                MessageBox.Show("Cannot open Config File " & Application.StartupPath & "\ConfigPathFile.txt", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error)
            End If
        End Sub

        Private Sub btnClearBlackList_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnClearBlackList.Click
            ClearWatchListToolStripMenuItemClick(Nothing, Nothing)
        End Sub
    End Class
End Namespace
