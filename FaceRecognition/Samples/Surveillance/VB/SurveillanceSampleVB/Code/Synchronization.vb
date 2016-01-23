Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.Net
Imports System.Net.Sockets
Imports System.Runtime.Serialization
Imports System.Runtime.Serialization.Formatters.Binary
Imports System.Threading
Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.IO

Namespace Code
	Public Class DbSynchronizer
		Implements IDisposable
#Region "Nested types"

		Private Enum Task
			None = 0
			Insert = 4
			Remove = 5
		End Enum
		Private Class InsertTaskBinder
			Inherits SerializationBinder
			Public Overrides Function BindToType(ByVal assemblyName As String, ByVal typeName As String) As System.Type

				If typeName.Contains("InsertTask") Then
					Return GetType(InsertTask)
				End If
				Return Type.GetType(String.Format("{0}, {1}", typeName, assemblyName))
			End Function
		End Class

		<Serializable()> _
		Private Class InsertTask
			Implements ISerializable
#Region "Public constructors"
			Public Sub New(ByVal record As FaceRecord, ByVal image As NImage)
				Me.Image = image
				Me.Record = record
			End Sub
			<System.Security.Permissions.SecurityPermissionAttribute(System.Security.Permissions.SecurityAction.Demand, SerializationFormatter:=True)> _
			Public Sub New(ByVal info As SerializationInfo, ByVal context As StreamingContext)
				Image = NImage.FromMemory(New NBuffer(CType(info.GetValue("Image", GetType(Byte())), Byte())))
				Dim features() As Byte = CType(info.GetValue("Features", GetType(Byte())), Byte())
				Dim faceId As String = CStr(info.GetValue("FaceID", GetType(String)))
				Dim enrollTime As DateTime = CDate(info.GetValue("EnrollTime", GetType(DateTime)))
				Dim detailsEditable As Boolean = CBool(info.GetValue("DetailsEditable", GetType(Boolean)))
				Dim details As NleDetectionDetails = CType(info.GetValue("DetectionDetails", GetType(NleDetectionDetails)), NleDetectionDetails)
				Dim guid As Guid = CType(info.GetValue("Guid", GetType(Guid)), Guid)
				Record = New FaceRecord(-1, features, faceId, enrollTime, detailsEditable, details, guid)
			End Sub
#End Region

#Region "Private fields"
			Private _image As NImage
			Private _record As FaceRecord
#End Region

#Region "Public properties"
			Public Property Image() As NImage
				Get
					Return _image
				End Get
				Private Set(ByVal value As NImage)
					_image = value
				End Set
			End Property
			Public Property Record() As FaceRecord
				Get
					Return _record
				End Get
				Private Set(ByVal value As FaceRecord)
					_record = value
				End Set
			End Property
#End Region

#Region "Public methods"
			Public Function Serialize() As Byte()
				Dim serializer As BinaryFormatter = New BinaryFormatter()
				Using ms As System.IO.MemoryStream = New System.IO.MemoryStream()
					serializer.Serialize(ms, Me)
					Return ms.GetBuffer()
				End Using
			End Function
			<System.Security.Permissions.SecurityPermissionAttribute(System.Security.Permissions.SecurityAction.Demand, SerializationFormatter:=True)> _
			Public Sub GetObjectData(ByVal info As SerializationInfo, ByVal context As StreamingContext) Implements ISerializable.GetObjectData
				Using buff As Neurotec.IO.NBuffer = Image.Save(NImageFormat.Png)
					info.AddValue("Image", buff.ToArray())
				End Using

				info.AddValue("Features", Record.Features)
				info.AddValue("FaceID", Record.FaceId)
				info.AddValue("EnrollTime", Record.EnrollTime)
				info.AddValue("DetailsEditable", Record.DetailsEditable)
				info.AddValue("DetectionDetails", Record.Details)
				info.AddValue("Guid", Record.Guid)
			End Sub
			Public Shared Function Serialize(ByVal record As FaceRecord, ByVal image As NImage) As Byte()
				Return (New InsertTask(record, image)).Serialize()
			End Function
			Public Shared Function Deserialize(ByVal buffer() As Byte) As InsertTask
				Dim serializer As BinaryFormatter = New BinaryFormatter()
				serializer.Binder = New InsertTaskBinder()
				Using ms As System.IO.MemoryStream = New System.IO.MemoryStream(buffer)
					Dim recordObject As Object = serializer.Deserialize(ms)
					Return TryCast(recordObject, InsertTask)
				End Using
			End Function
#End Region
		End Class

#End Region

#Region "Public events"
		Public Delegate Sub RecordsRemoved(ByVal guid() As Guid)
		Public Event OnRecordsRemoved As RecordsRemoved
		Public Delegate Sub RecordAdded(ByVal record As FaceRecord, ByVal image As NImage)
		Public Event OnRecordAdded As RecordAdded
#End Region

#Region "Private fields"
		Private _instances As List(Of String) = New List(Of String)()
		Private _isStarted As Boolean = False
		Private _continueListen As Boolean = False
		Private _listener As TcpListener
		Private _listenPort As Integer
		Private [syncLock] As Object = New Object()
#End Region

#Region "Public constructor"
		Public Sub New(ByVal instances As String, ByVal listenPort As Integer)
			UpdateInstances(instances)
			_listenPort = listenPort
		End Sub
#End Region

#Region "Public properties"
		Public Property ListenPort() As Integer
			Get
				Return _listenPort
			End Get
			Set(ByVal value As Integer)
				If _listenPort <> value AndAlso _isStarted Then
					Throw New InvalidOperationException("Can not change listen port while listening")
				End If
				_listenPort = value
			End Set
		End Property
#End Region

#Region "Public methods"
		Public Sub StartListener()
			If _isStarted Then
				Throw New InvalidOperationException("Already started")
			End If
			_isStarted = True
			_continueListen = True
			_listener = New TcpListener(IPAddress.Any, _listenPort)
			_listener.Start()
			Dim th As Thread = New Thread(AddressOf ListenerThread)
			th.Start()
		End Sub
		Public Sub StopListener()
			If (Not _isStarted) Then
				Return
			End If
			_isStarted = False
			_continueListen = False
			_listener.Stop()
		End Sub
		Public Sub UpdateInstances(ByVal instances As String)
			_instances.Clear()
			_instances.AddRange(instances.Split(New Char() {";"c}, StringSplitOptions.RemoveEmptyEntries))
		End Sub
		Public Sub InsertRecord(ByVal record As FaceRecord, ByVal image As NImage)
			Dim insert() As Byte = InsertTask.Serialize(record, image)
			For Each item As String In _instances
				SendTask(item, Task.Insert, insert)
			Next item
		End Sub
		Public Sub RemoveRecords(ByVal ParamArray guid() As Guid)
			If guid Is Nothing OrElse guid.Length = 0 Then
				Return
			End If
			Dim remove(guid.Length * 16 - 1) As Byte
			For i As Integer = 0 To guid.Length - 1
				guid(i).ToByteArray().CopyTo(remove, i * 16)
			Next i
			For Each item As String In _instances
				SendTask(item, Task.Remove, remove)
			Next item
		End Sub
#End Region

#Region "IDisposable members"

		Public Sub Dispose() Implements IDisposable.Dispose
			StopListener()
		End Sub

#End Region

#Region "Private methods"

		Private Sub SendTask(ByVal instance As String, ByVal task As Task, ByVal bytes() As Byte)
			Dim client As TcpClient = Nothing
			Dim networkStream As NetworkStream = Nothing
			Try
				Dim split() As String = instance.Split(":"c)
				Dim host As String = split(0)
				Dim port As Integer = Convert.ToInt32(split(1))
				client = New TcpClient(host, port)
				networkStream = client.GetStream()
				Send(networkStream, task, bytes)
			Catch e1 As Exception
			Finally
				If networkStream IsNot Nothing Then
					networkStream.Close()
				End If
				If client IsNot Nothing Then
					client.Close()
				End If
			End Try
		End Sub
		Private Sub ListenerThread()
			Do While _continueListen
				Try
					Dim endPoint As TcpClient = _listener.AcceptTcpClient()
					endPoint.LingerState.Enabled = False
					NewConnection(endPoint)
				Catch
					Thread.Sleep(2000)
				End Try
			Loop
			_listener.Stop()
		End Sub
		Private Sub Send(ByVal ns As NetworkStream, ByVal task As Task, ByVal buffer() As Byte)
			ns.WriteByte(0)
			Dim lb1() As Byte = BitConverter.GetBytes(System.Net.IPAddress.HostToNetworkOrder(buffer.Length + 1))
			ns.Write(lb1, 0, lb1.Length)
			ns.WriteByte(CByte(task))
			ns.Write(buffer, 0, buffer.Length)
		End Sub
		Private Sub NewConnection(ByVal endPoint As TcpClient)
			Dim th As Thread = New Thread(AddressOf WorkerThread)
			th.Start(endPoint)
		End Sub
		Private Function ReadBytes(ByVal ns As NetworkStream, ByVal length As Integer) As Byte()
			Dim buf(length - 1) As Byte
			Dim bytesRead As Integer = 0
			Do While bytesRead < length
				Dim nowRead As Integer = ns.Read(buf, bytesRead, length - bytesRead)
				If nowRead <= 0 Then
					Return Nothing
				End If
				bytesRead += nowRead
			Loop
			Return buf
		End Function
		Private Sub WorkerThread(ByVal parameter As Object)
			Dim endPoint As TcpClient = TryCast(parameter, TcpClient)
			Dim ns As NetworkStream = Nothing
			Try
				If endPoint IsNot Nothing Then
					ns = endPoint.GetStream()
					Try
						Do
							Dim task As Task = CType(ns.ReadByte(), Task)
							If task <> task.None Then
								ns.Close()
								endPoint.Close()
								Return
							End If
							Dim lb1() As Byte = ReadBytes(ns, Len(New Integer))
							Dim length As Integer = System.Net.IPAddress.NetworkToHostOrder(BitConverter.ToInt32(lb1, 0))
							task = CType(ns.ReadByte(), Task)
							Dim buffer() As Byte = ReadBytes(ns, length - 1)
							Dim response() As Byte = Nothing
							response = ExecuteTask(task, endPoint, buffer)
							If response.Length > 0 Then
								ns.WriteByte(0)
								lb1 = BitConverter.GetBytes(IPAddress.HostToNetworkOrder(response.Length))
								ns.Write(lb1, 0, lb1.Length)
								If response.Length > 0 Then
									ns.Write(response, 0, response.Length)
								End If
							End If
						Loop
					Catch e1 As System.IO.IOException
						ns.Close()
						ns.Dispose()
						ns = Nothing
						endPoint.Close()
						endPoint = Nothing
					Catch e2 As ObjectDisposedException
						ns.Close()
						ns.Dispose()
						ns = Nothing
						endPoint.Close()
						endPoint = Nothing
					End Try
				End If
			Finally
				If ns IsNot Nothing Then
					ns.Close()
					ns.Dispose()
				End If
				If endPoint IsNot Nothing Then
					endPoint.Close()
				End If
			End Try
		End Sub
		Private Function ExecuteTask(ByVal task As Task, ByVal sender As TcpClient, ByVal data() As Byte) As Byte()
			SyncLock [syncLock]
				Select Case task
					Case task.Insert
						If OnRecordAddedEvent IsNot Nothing Then
							Dim insert As InsertTask = InsertTask.Deserialize(data)
							RaiseEvent OnRecordAdded(insert.Record, insert.Image)
						End If
					Case task.Remove
						If OnRecordsRemovedEvent IsNot Nothing Then
							Dim bytes(15) As Byte
							Dim guids(CInt(data.Length / 16 - 1)) As Guid
							For i As Integer = 0 To guids.Length - 1
								Array.Copy(data, i * 16, bytes, 0, 16)
								guids(i) = New Guid(bytes)
							Next i
							RaiseEvent OnRecordsRemoved(guids)
						End If
					Case Else
				End Select
			End SyncLock
			Return New Byte() {}
		End Function

#End Region
	End Class
End Namespace
