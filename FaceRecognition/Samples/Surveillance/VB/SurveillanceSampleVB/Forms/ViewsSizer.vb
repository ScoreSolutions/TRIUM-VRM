Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.Drawing
Imports System.Windows.Forms
Imports Neurotec.Biometrics.Gui

Namespace Forms
	Partial Public Class ViewsSizer
		Inherits UserControl
#Region "Public constructor"
		Public Sub New()
			InitializeComponent()
			For i As Integer = 0 To 3
				Dim view As NLView = New NLView()
				view.BorderStyle = BorderStyle.FixedSingle
				view.AutoScroll = True
				views.Add(view)
			Next i
			Controls.AddRange(views.ToArray())
		End Sub
#End Region

#Region "Private fields"
		Private views As List(Of NLView) = New List(Of NLView)()
#End Region

#Region "Private methods"
		Private Sub ResizeViews()
			If views.Count = 0 Then
				Return
			End If

			views(0).Left = 0
			views(0).Top = 0
			views(1).Left = Width \ 2
			views(1).Top = 0
			views(2).Left = 0
			views(2).Top = Height \ 2
			views(3).Left = Width \ 2
			views(3).Top = Height \ 2

			Dim shownViews As List(Of NLView) = New List(Of NLView)()
			For Each item As NLView In views
				If item.Visible Then
					shownViews.Add(item)
				End If
			Next item

			Select Case shownViews.Count
				Case 1
					shownViews(0).Size = Size
					Exit Select
				Case 2
					Dim sz As Size = New Size(Size.Width \ 2, Height)
					shownViews(0).Size = sz
					shownViews(1).Size = sz
					Exit Select
				Case 3
					Dim sz As Size = New Size(Size.Width \ 2, Height \ 2)
					shownViews(0).Size = sz
					shownViews(1).Size = sz
					shownViews(2).Size = New Size(Width, Height \ 2)
					Exit Select
				Case 4
					Dim sz As Size = New Size(Size.Width \ 2, Height \ 2)
					shownViews(0).Size = sz
					shownViews(1).Size = sz
					shownViews(2).Size = sz
					shownViews(3).Size = sz
					Exit Select
				Case Else
			End Select
		End Sub
		Private Sub ViewsSizer_SizeChanged(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.SizeChanged
			ResizeViews()
		End Sub
#End Region

#Region "Public properties"
		Public ReadOnly Property Count() As Integer
			Get
				Return views.Count
			End Get
		End Property
		Default Public ReadOnly Property Item(ByVal index As Integer) As NLView
			Get
				Return views(index)
			End Get
		End Property
#End Region

#Region "Public methods"
		Public Sub ShowView(ByVal index As Integer)
			views(index).Visible = True
			ResizeViews()
		End Sub
		Public Sub HideView(ByVal index As Integer)
			views(index).Visible = False
			ResizeViews()
		End Sub
		Public Sub HideAll()
			For Each item As NLView In views
				item.Visible = False
			Next item
		End Sub
		Public Function IndexOf(ByVal view As Object) As Integer
			If TypeOf view Is NLView Then
				Dim nlview As NLView = CType(view, NLView)
				Return views.IndexOf(nlview)
			End If
			Return -1
		End Function
#End Region
	End Class
End Namespace
