Imports Microsoft.VisualBasic
Imports System
Imports System.Collections
Imports System.Data
Imports System.Data.SQLite
Imports System.Drawing
Imports System.IO
Imports System.Windows.Forms
Imports Neurotec.Biometrics
Imports Neurotec.Images

Namespace Code
	Public Class FaceRecord
#Region "Private fields"
		Private _id As Integer
		Private _guid As Guid
		Private _features() As Byte
		Private _faceId As String
		Private _enrollTime As DateTime
		Private _detailsEditable As Boolean
		Private _details As NleDetectionDetails

#End Region

#Region "Public constructor"

		Public Sub New(ByVal id As Integer, ByVal features() As Byte, ByVal faceId As String, ByVal enrollTime As DateTime, ByVal detailsEditable As Boolean, ByVal details As NleDetectionDetails, ByVal guid As Guid)
			Me._id = id
			Me._features = features
			Me._faceId = faceId
			Me._enrollTime = enrollTime
			Me._detailsEditable = detailsEditable
			Me._details = details
			Me._guid = guid
		End Sub

#End Region

#Region "Public properties"

		Public Property Id() As Integer
			Get
				Return _id
			End Get
			Set(ByVal value As Integer)
				_id = value
			End Set
		End Property

		Public ReadOnly Property Features() As Byte()
			Get
				Return _features
			End Get
		End Property

		Public ReadOnly Property FaceId() As String
			Get
				Return _faceId
			End Get
		End Property

		Public ReadOnly Property EnrollTime() As DateTime
			Get
				Return _enrollTime
			End Get
		End Property

		Public ReadOnly Property DetailsEditable() As Boolean
			Get
				Return _detailsEditable
			End Get
		End Property

		Public ReadOnly Property Details() As NleDetectionDetails
			Get
				Return _details
			End Get
		End Property

		Public ReadOnly Property Guid() As Guid
			Get
				Return _guid
			End Get
		End Property
#End Region
	End Class

	Public Class FaceRecordCollection
		Inherits CollectionBase
#Region "Private consts"

		Private Const tableName As String = "WatchList"
		Private Const dbFilename As String = "SurveillanceSample.db"

#End Region

#Region "Private fields"

		Private [syncLock] As Object = New Object()
		Private sqliteConnection As SQLiteConnection

#End Region

#Region "Public contructor"

		Public Sub New()
			Dim dbFile As String = Path.Combine(Utils.GetUserLocalDataDir("SurveillanceSampleNET"), dbFilename)
			CreateDBFile(dbFile)

			sqliteConnection = New SQLiteConnection("Version=3;New=False;Compress=False;Data Source=" & dbFile)
			Try
				sqliteConnection.Open()
			Catch ee As SQLiteException
				MessageBox.Show(ee.Message & ". StackTrace: " & ee.StackTrace.ToString())
			End Try
			If sqliteConnection.State = ConnectionState.Open Then
				Dim [select] As SQLiteCommand = New SQLiteCommand(String.Format("SELECT id, features, faceId, enrollTime, detailsEditable, " & "faceAvailable, faceRectangleX, faceRectangleY, faceRectangleWidth, faceRectangleHeight, " & "leftEyeConfidence, leftEyeX, leftEyeY, rightEyeConfidence, rightEyeX, rightEyeY, guid FROM {0}", tableName), sqliteConnection)
				Dim reader As SQLiteDataReader = [select].ExecuteReader()
				Do While reader.Read()
					Dim id As Integer = reader.GetInt32(0)
					Dim featuresSize As Long = reader.GetBytes(1, 0, Nothing, 0, 0)
					Dim features(CInt(featuresSize - 1)) As Byte
					reader.GetBytes(1, 0, features, 0, CInt(Fix(featuresSize)))
					Dim faceId As String = reader.GetString(2)
					Dim enrollTime As DateTime = reader.GetDateTime(3)
					Dim detailsEditable As Boolean = reader.GetBoolean(4)
					Dim details As NleDetectionDetails = New NleDetectionDetails()
					details.FaceAvailable = reader.GetBoolean(5)
					Dim face As NleFace = New NleFace()
					face.Rectangle = New Rectangle(reader.GetInt32(6), reader.GetInt32(7), reader.GetInt32(8), reader.GetInt32(9))
					details.Face = face
					Dim leftEye As NLFeaturePoint = New NLFeaturePoint()
					leftEye.Confidence = CByte(reader.GetInt32(10))
					leftEye.X = CUShort(reader.GetInt32(11))
					leftEye.Y = CUShort(reader.GetInt32(12))
					details.LeftEyeCenter = leftEye
					Dim rightEye As NLFeaturePoint = New NLFeaturePoint()
					rightEye.Confidence = CByte(reader.GetInt32(13))
					rightEye.X = CUShort(reader.GetInt32(14))
					rightEye.Y = CUShort(reader.GetInt32(15))
					details.RightEyeCenter = rightEye
					Dim guidBytes(15) As Byte
					reader.GetBytes(16, 0, guidBytes, 0, 16)
					Dim guid As Guid = New Guid(guidBytes)
					InnerList.Add(New FaceRecord(id, features, faceId, enrollTime, detailsEditable, details, guid))
				Loop
				reader.Close()
			End If
		End Sub

#End Region

#Region "Public methods"

		Public Sub Close()
			sqliteConnection.Close()
		End Sub

		Public Sub Add(ByVal faceRecord As FaceRecord, ByVal image As NImage)
			SyncLock [syncLock]
				Dim id As Integer = WriteToDB(faceRecord.Features, faceRecord.FaceId, image, faceRecord.EnrollTime, faceRecord.DetailsEditable, faceRecord.Details, faceRecord.Guid)
				If id >= 0 Then
					faceRecord.Id = id
					InnerList.Add(faceRecord)
				End If
			End SyncLock
		End Sub

		Public Function Remove(ByVal guid As Guid) As Boolean
			SyncLock [syncLock]
				Dim record As FaceRecord = Me(guid)
				If record IsNot Nothing Then
					InnerList.Remove(record)
					Using cmd As SQLiteCommand = sqliteConnection.CreateCommand()
						cmd.CommandText = String.Format("DELETE FROM {0} WHERE id={1}", tableName, record.Id)
						cmd.ExecuteNonQuery()
					End Using
					Return True
				End If
				Return False
			End SyncLock
		End Function

		Default Public ReadOnly Property Item(ByVal index As Integer) As FaceRecord
			Get
				Return CType(InnerList(index), FaceRecord)
			End Get
		End Property

		Default Public ReadOnly Property Item(ByVal guid As Guid) As FaceRecord
			Get
				For Each record As FaceRecord In InnerList
					If record.Guid = guid Then
						Return record
					End If
				Next record
				Return Nothing
			End Get
		End Property

		Public Shadows Sub Clear()
			InnerList.Clear()
			Dim deleteAll As SQLiteCommand = New SQLiteCommand(String.Format("DELETE FROM {0}", tableName), sqliteConnection)
			deleteAll.ExecuteNonQuery()
		End Sub

		Public Function GetImageById(ByVal id As Integer) As Bitmap
			Dim bitmap As Bitmap = Nothing
			Dim [select] As SQLiteCommand = New SQLiteCommand(String.Format("SELECT picture FROM {0} WHERE id = {1}", tableName, id), sqliteConnection)
			Dim reader As SQLiteDataReader = [select].ExecuteReader()
			Do While reader.Read()
				Dim fieldSize As Long = reader.GetBytes(0, 0, Nothing, 0, 0)
				Dim image(CInt(fieldSize - 1)) As Byte
				reader.GetBytes(0, 0, image, 0, CInt(Fix(fieldSize)))
				Dim stream As MemoryStream = New MemoryStream(image)
				bitmap = New Bitmap(stream)
				stream.Close()
			Loop
			reader.Close()

			Return bitmap
		End Function

		Public Function GetFaceIdByGuid(ByVal guid As Guid) As String
			Dim record As FaceRecord = Me(guid)
			If record Is Nothing Then
				Return String.Empty
			End If
			Return record.FaceId
		End Function

#End Region

#Region "Private methods"

		Private Function WriteToDB(ByVal features() As Byte, ByVal faceId As String, ByVal nImage As NImage, ByVal enrollTime As DateTime, ByVal detailsEditable As Boolean, ByVal details As NleDetectionDetails, ByVal guid As Guid) As Integer
			Dim maxId As Integer = -1
			Try
				Dim checkalreadyPresent As SQLiteCommand = New SQLiteCommand(String.Format("SELECT id FROM {0} WHERE guid=@guid", tableName), sqliteConnection)
				checkalreadyPresent.Parameters.AddWithValue("@guid", guid.ToByteArray())
				Using reader As SQLiteDataReader = checkalreadyPresent.ExecuteReader()
					If reader.Read() Then
						Return reader.GetInt32(0)
					End If
				End Using

				Dim image() As Byte
				Using image2 As Bitmap = nImage.ToBitmap()
					Dim stream As MemoryStream = New MemoryStream()
					image2.Save(stream, System.Drawing.Imaging.ImageFormat.Png)
					image = stream.ToArray()
				End Using

				Dim cmdstr As String = String.Format("INSERT INTO {0} (features, faceId, picture, enrollTime, detailsEditable, " & "faceAvailable, faceRectangleX, faceRectangleY, faceRectangleWidth, faceRectangleHeight, " & "leftEyeConfidence, leftEyeX, leftEyeY, rightEyeConfidence, rightEyeX, rightEyeY, guid) " & "VALUES (@features, @faceId, @picture, @enrollTime, @detailsEditable, " & "@faceAvailable, @faceRectangleX, @faceRectangleY, @faceRectangleWidth, @faceRectangleHeight, " & "@leftEyeConfidence, @leftEyeX, @leftEyeY, @rightEyeConfidence, @rightEyeX, @rightEyeY, @guid)", tableName)

				Dim insert As SQLiteCommand = New SQLiteCommand(cmdstr, sqliteConnection)
				insert.Parameters.AddWithValue("@features", features)
				insert.Parameters.AddWithValue("@faceId", faceId)
				insert.Parameters.AddWithValue("@picture", image)
				insert.Parameters.AddWithValue("@enrollTime", enrollTime)
				insert.Parameters.AddWithValue("@detailsEditable", detailsEditable)
				insert.Parameters.AddWithValue("@faceAvailable", details.FaceAvailable)
				insert.Parameters.AddWithValue("@faceRectangleX", details.Face.Rectangle.X)
				insert.Parameters.AddWithValue("@faceRectangleY", details.Face.Rectangle.Y)
				insert.Parameters.AddWithValue("@faceRectangleWidth", details.Face.Rectangle.Width)
				insert.Parameters.AddWithValue("@faceRectangleHeight", details.Face.Rectangle.Height)
				insert.Parameters.AddWithValue("@leftEyeConfidence", details.LeftEyeCenter.Confidence)
				insert.Parameters.AddWithValue("@leftEyeX", details.LeftEyeCenter.X)
				insert.Parameters.AddWithValue("@leftEyeY", details.LeftEyeCenter.Y)
				insert.Parameters.AddWithValue("@rightEyeConfidence", details.RightEyeCenter.Confidence)
				insert.Parameters.AddWithValue("@rightEyeX", details.RightEyeCenter.X)
				insert.Parameters.AddWithValue("@rightEyeY", details.RightEyeCenter.Y)
				insert.Parameters.AddWithValue("@guid", guid.ToByteArray())
				insert.ExecuteNonQuery()

				Dim getMaxId As SQLiteCommand = New SQLiteCommand(String.Format("SELECT MAX(id) FROM {0}", tableName), sqliteConnection)
				maxId = CInt(Fix(CLng(Fix(getMaxId.ExecuteScalar()))))
			Catch ex As InvalidOperationException
				MessageBox.Show(String.Format("Failed to insert record into DB:" & Constants.vbLf & "{0}", ex.Message))
			End Try
			If maxId = -1 Then
				MessageBox.Show("Error. Cannot get id from database! Description: function writeToDB")
			End If

			Return maxId
		End Function

		Private Sub CreateDBFile(ByVal dbFile As String)
			If (Not File.Exists(dbFile)) Then
				Try
					sqliteConnection.CreateFile(dbFile)
					Dim conn As SQLiteConnection = New SQLiteConnection("Version=3;New=True;Compress=False;Data Source=" & dbFile)
					conn.Open()
					Dim cmd As SQLiteCommand = New SQLiteCommand("CREATE TABLE WatchList (" & "[id] INTEGER PRIMARY KEY, " & "[features] BINARY, " & "[faceId] TEXT, " & "[picture] IMAGE, " & "[enrollTime] TIMESTAMP, " & "[detailsEditable] BOOL, " & "[faceAvailable] BOOL, " & "[faceRectangleX] INTEGER, " & "[faceRectangleY] INTEGER, " & "[faceRectangleWidth] INTEGER, " & "[faceRectangleHeight] INTEGER, " & "[leftEyeConfidence] INTEGER, " & "[leftEyeX] INTEGER, " & "[leftEyeY] INTEGER, " & "[rightEyeConfidence] INTEGER, " & "[rightEyeX] INTEGER, " & "[rightEyeY] INTEGER, " & "[guid] BINARY, " & "[comment] TEXT)", conn)
					cmd.ExecuteNonQuery()
					conn.Close()
				Catch ee As SQLiteException
					MessageBox.Show(ee.Message)
				End Try
			End If
		End Sub

#End Region
	End Class
End Namespace
