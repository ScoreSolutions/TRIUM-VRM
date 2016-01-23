Imports Microsoft.VisualBasic
Imports System
Namespace Forms
	Partial Public Class WatchListForm
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
			Me.components = New System.ComponentModel.Container()
			Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(WatchListForm))
			Me.bindingNavigator = New System.Windows.Forms.BindingNavigator(Me.components)
			Me.bindingNavigatorAddNewItem = New System.Windows.Forms.ToolStripButton()
			Me.bindingNavigatorCountItem = New System.Windows.Forms.ToolStripLabel()
			Me.bindingNavigatorDeleteItem = New System.Windows.Forms.ToolStripButton()
			Me.bindingNavigatorMoveFirstItem = New System.Windows.Forms.ToolStripButton()
			Me.bindingNavigatorMovePreviousItem = New System.Windows.Forms.ToolStripButton()
			Me.bindingNavigatorSeparator = New System.Windows.Forms.ToolStripSeparator()
			Me.bindingNavigatorPositionItem = New System.Windows.Forms.ToolStripTextBox()
			Me.bindingNavigatorSeparator1 = New System.Windows.Forms.ToolStripSeparator()
			Me.bindingNavigatorMoveNextItem = New System.Windows.Forms.ToolStripButton()
			Me.bindingNavigatorMoveLastItem = New System.Windows.Forms.ToolStripButton()
			Me.bindingNavigatorSeparator2 = New System.Windows.Forms.ToolStripSeparator()
			Me.nlView = New Neurotec.Biometrics.Gui.NLView()
			Me.bindingSource = New System.Windows.Forms.BindingSource(Me.components)
			Me.tslTemplateId = New System.Windows.Forms.ToolStripLabel()
			CType(Me.bindingNavigator, System.ComponentModel.ISupportInitialize).BeginInit()
			Me.bindingNavigator.SuspendLayout()
			CType(Me.bindingSource, System.ComponentModel.ISupportInitialize).BeginInit()
			Me.SuspendLayout()
			' 
			' bindingNavigator
			' 
			Me.bindingNavigator.AddNewItem = Me.bindingNavigatorAddNewItem
			Me.bindingNavigator.BindingSource = Me.bindingSource
			Me.bindingNavigator.CountItem = Me.bindingNavigatorCountItem
			Me.bindingNavigator.DeleteItem = Me.bindingNavigatorDeleteItem
			Me.bindingNavigator.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.bindingNavigatorMoveFirstItem, Me.bindingNavigatorMovePreviousItem, Me.bindingNavigatorSeparator, Me.bindingNavigatorPositionItem, Me.bindingNavigatorCountItem, Me.bindingNavigatorSeparator1, Me.bindingNavigatorMoveNextItem, Me.bindingNavigatorMoveLastItem, Me.bindingNavigatorSeparator2, Me.bindingNavigatorAddNewItem, Me.bindingNavigatorDeleteItem, Me.tslTemplateId})
			Me.bindingNavigator.Location = New System.Drawing.Point(0, 0)
			Me.bindingNavigator.MoveFirstItem = Me.bindingNavigatorMoveFirstItem
			Me.bindingNavigator.MoveLastItem = Me.bindingNavigatorMoveLastItem
			Me.bindingNavigator.MoveNextItem = Me.bindingNavigatorMoveNextItem
			Me.bindingNavigator.MovePreviousItem = Me.bindingNavigatorMovePreviousItem
			Me.bindingNavigator.Name = "bindingNavigator"
			Me.bindingNavigator.PositionItem = Me.bindingNavigatorPositionItem
			Me.bindingNavigator.Size = New System.Drawing.Size(642, 25)
			Me.bindingNavigator.TabIndex = 1
			Me.bindingNavigator.Text = "bindingNavigator"
			' 
			' bindingNavigatorAddNewItem
			' 
			Me.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
			Me.bindingNavigatorAddNewItem.Image = (CType(resources.GetObject("bindingNavigatorAddNewItem.Image"), System.Drawing.Image))
			Me.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem"
			Me.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = True
			Me.bindingNavigatorAddNewItem.Size = New System.Drawing.Size(23, 22)
			Me.bindingNavigatorAddNewItem.Text = "Add new"
			Me.bindingNavigatorAddNewItem.Visible = False
			' 
			' bindingNavigatorCountItem
			' 
			Me.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem"
			Me.bindingNavigatorCountItem.Size = New System.Drawing.Size(36, 22)
			Me.bindingNavigatorCountItem.Text = "of {0}"
			Me.bindingNavigatorCountItem.ToolTipText = "Total number of items"
			' 
			' bindingNavigatorDeleteItem
			' 
			Me.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
			Me.bindingNavigatorDeleteItem.Image = (CType(resources.GetObject("bindingNavigatorDeleteItem.Image"), System.Drawing.Image))
			Me.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem"
			Me.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = True
			Me.bindingNavigatorDeleteItem.Size = New System.Drawing.Size(23, 22)
			Me.bindingNavigatorDeleteItem.Text = "Delete"
			Me.bindingNavigatorDeleteItem.Visible = False
			' 
			' bindingNavigatorMoveFirstItem
			' 
			Me.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
			Me.bindingNavigatorMoveFirstItem.Image = (CType(resources.GetObject("bindingNavigatorMoveFirstItem.Image"), System.Drawing.Image))
			Me.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem"
			Me.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = True
			Me.bindingNavigatorMoveFirstItem.Size = New System.Drawing.Size(23, 22)
			Me.bindingNavigatorMoveFirstItem.Text = "Move first"
			' 
			' bindingNavigatorMovePreviousItem
			' 
			Me.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
			Me.bindingNavigatorMovePreviousItem.Image = (CType(resources.GetObject("bindingNavigatorMovePreviousItem.Image"), System.Drawing.Image))
			Me.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem"
			Me.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = True
			Me.bindingNavigatorMovePreviousItem.Size = New System.Drawing.Size(23, 22)
			Me.bindingNavigatorMovePreviousItem.Text = "Move previous"
			' 
			' bindingNavigatorSeparator
			' 
			Me.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator"
			Me.bindingNavigatorSeparator.Size = New System.Drawing.Size(6, 25)
			' 
			' bindingNavigatorPositionItem
			' 
			Me.bindingNavigatorPositionItem.AccessibleName = "Position"
			Me.bindingNavigatorPositionItem.AutoSize = False
			Me.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem"
			Me.bindingNavigatorPositionItem.Size = New System.Drawing.Size(50, 21)
			Me.bindingNavigatorPositionItem.Text = "0"
			Me.bindingNavigatorPositionItem.ToolTipText = "Current position"
			' 
			' bindingNavigatorSeparator1
			' 
			Me.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1"
			Me.bindingNavigatorSeparator1.Size = New System.Drawing.Size(6, 25)
			' 
			' bindingNavigatorMoveNextItem
			' 
			Me.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
			Me.bindingNavigatorMoveNextItem.Image = (CType(resources.GetObject("bindingNavigatorMoveNextItem.Image"), System.Drawing.Image))
			Me.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem"
			Me.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = True
			Me.bindingNavigatorMoveNextItem.Size = New System.Drawing.Size(23, 22)
			Me.bindingNavigatorMoveNextItem.Text = "Move next"
			' 
			' bindingNavigatorMoveLastItem
			' 
			Me.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
			Me.bindingNavigatorMoveLastItem.Image = (CType(resources.GetObject("bindingNavigatorMoveLastItem.Image"), System.Drawing.Image))
			Me.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem"
			Me.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = True
			Me.bindingNavigatorMoveLastItem.Size = New System.Drawing.Size(23, 22)
			Me.bindingNavigatorMoveLastItem.Text = "Move last"
			' 
			' bindingNavigatorSeparator2
			' 
			Me.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2"
			Me.bindingNavigatorSeparator2.Size = New System.Drawing.Size(6, 25)
			' 
			' nlView
			' 
			Me.nlView.AutoScroll = True
			Me.nlView.DetectionDetails = Nothing
			Me.nlView.Dock = System.Windows.Forms.DockStyle.Fill
			Me.nlView.ShowEyesConfidence = False
			Me.nlView.ShowFaceConfidence = False
			Me.nlView.FaceIds = Nothing
			Me.nlView.FaceRectangleColor = System.Drawing.Color.GreenYellow
			Me.nlView.Image = Nothing
			Me.nlView.Location = New System.Drawing.Point(0, 25)
			Me.nlView.Name = "nlView"
			Me.nlView.Size = New System.Drawing.Size(642, 491)
			Me.nlView.TabIndex = 2
			' 
			' bindingSource
			' 
			'			Me.bindingSource.CurrentChanged += New System.EventHandler(Me.bindingSource_CurrentChanged);
			' 
			' tslTemplateId
			' 
			Me.tslTemplateId.Name = "tslTemplateId"
			Me.tslTemplateId.Size = New System.Drawing.Size(0, 22)
			' 
			' WatchListForm
			' 
			Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0F, 13.0F)
			Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
			Me.ClientSize = New System.Drawing.Size(642, 516)
			Me.Controls.Add(Me.nlView)
			Me.Controls.Add(Me.bindingNavigator)
			Me.Icon = (CType(resources.GetObject("$this.Icon"), System.Drawing.Icon))
			Me.Name = "WatchListForm"
			Me.Text = "Watch List"
			CType(Me.bindingNavigator, System.ComponentModel.ISupportInitialize).EndInit()
			Me.bindingNavigator.ResumeLayout(False)
			Me.bindingNavigator.PerformLayout()
			CType(Me.bindingSource, System.ComponentModel.ISupportInitialize).EndInit()
			Me.ResumeLayout(False)
			Me.PerformLayout()

		End Sub

#End Region

		Private bindingNavigator As System.Windows.Forms.BindingNavigator
		Private bindingNavigatorAddNewItem As System.Windows.Forms.ToolStripButton
		Private bindingNavigatorCountItem As System.Windows.Forms.ToolStripLabel
		Private bindingNavigatorDeleteItem As System.Windows.Forms.ToolStripButton
		Private bindingNavigatorMoveFirstItem As System.Windows.Forms.ToolStripButton
		Private bindingNavigatorMovePreviousItem As System.Windows.Forms.ToolStripButton
		Private bindingNavigatorSeparator As System.Windows.Forms.ToolStripSeparator
		Private bindingNavigatorPositionItem As System.Windows.Forms.ToolStripTextBox
		Private bindingNavigatorSeparator1 As System.Windows.Forms.ToolStripSeparator
		Private bindingNavigatorMoveNextItem As System.Windows.Forms.ToolStripButton
		Private bindingNavigatorMoveLastItem As System.Windows.Forms.ToolStripButton
		Private bindingNavigatorSeparator2 As System.Windows.Forms.ToolStripSeparator
		Private nlView As Neurotec.Biometrics.Gui.NLView
		Private WithEvents bindingSource As System.Windows.Forms.BindingSource
		Private tslTemplateId As System.Windows.Forms.ToolStripLabel

	End Class
End Namespace