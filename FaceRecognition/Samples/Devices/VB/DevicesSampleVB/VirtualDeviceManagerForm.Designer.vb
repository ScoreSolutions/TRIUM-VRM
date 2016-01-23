Imports Microsoft.VisualBasic
Imports System
Partial Public Class VirtualDeviceManagerForm
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
		Me.propertyGrid = New System.Windows.Forms.PropertyGrid()
		Me.btnAdd = New System.Windows.Forms.Button()
		Me.btnRemove = New System.Windows.Forms.Button()
		Me.btnPlug = New System.Windows.Forms.Button()
		Me.btnUnplug = New System.Windows.Forms.Button()
		Me.btnClose = New System.Windows.Forms.Button()
		Me.lvDevices = New System.Windows.Forms.ListView()
		Me.SuspendLayout()
		' 
		' propertyGrid
		' 
		Me.propertyGrid.Anchor = (CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) Or System.Windows.Forms.AnchorStyles.Left) Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.propertyGrid.Location = New System.Drawing.Point(208, 3)
		Me.propertyGrid.Name = "propertyGrid"
		Me.propertyGrid.Size = New System.Drawing.Size(403, 330)
		Me.propertyGrid.TabIndex = 0
		'			Me.propertyGrid.PropertyValueChanged += New System.Windows.Forms.PropertyValueChangedEventHandler(Me.PropertyGridPropertyValueChanged);
		' 
		' btnAdd
		' 
		Me.btnAdd.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.btnAdd.Location = New System.Drawing.Point(3, 310)
		Me.btnAdd.Name = "btnAdd"
		Me.btnAdd.Size = New System.Drawing.Size(97, 23)
		Me.btnAdd.TabIndex = 2
		Me.btnAdd.Text = "&Add"
		Me.btnAdd.UseVisualStyleBackColor = True
		'			Me.btnAdd.Click += New System.EventHandler(Me.BtnAddClick);
		' 
		' btnRemove
		' 
		Me.btnRemove.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.btnRemove.Enabled = False
		Me.btnRemove.Location = New System.Drawing.Point(3, 339)
		Me.btnRemove.Name = "btnRemove"
		Me.btnRemove.Size = New System.Drawing.Size(97, 23)
		Me.btnRemove.TabIndex = 3
		Me.btnRemove.Text = "&Remove"
		Me.btnRemove.UseVisualStyleBackColor = True
		'			Me.btnRemove.Click += New System.EventHandler(Me.BtnRemoveClick);
		' 
		' btnPlug
		' 
		Me.btnPlug.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.btnPlug.Enabled = False
		Me.btnPlug.Location = New System.Drawing.Point(106, 310)
		Me.btnPlug.Name = "btnPlug"
		Me.btnPlug.Size = New System.Drawing.Size(96, 23)
		Me.btnPlug.TabIndex = 4
		Me.btnPlug.Text = "&Plug"
		Me.btnPlug.UseVisualStyleBackColor = True
		'			Me.btnPlug.Click += New System.EventHandler(Me.BtnPlugClick);
		' 
		' btnUnplug
		' 
		Me.btnUnplug.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.btnUnplug.Enabled = False
		Me.btnUnplug.Location = New System.Drawing.Point(105, 339)
		Me.btnUnplug.Name = "btnUnplug"
		Me.btnUnplug.Size = New System.Drawing.Size(97, 23)
		Me.btnUnplug.TabIndex = 5
		Me.btnUnplug.Text = "&Unplug"
		Me.btnUnplug.UseVisualStyleBackColor = True
		'			Me.btnUnplug.Click += New System.EventHandler(Me.BtnUnplugClick);
		' 
		' btnClose
		' 
		Me.btnClose.Anchor = (CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles))
		Me.btnClose.Location = New System.Drawing.Point(536, 339)
		Me.btnClose.Name = "btnClose"
		Me.btnClose.Size = New System.Drawing.Size(75, 23)
		Me.btnClose.TabIndex = 6
		Me.btnClose.Text = "&Close"
		Me.btnClose.UseVisualStyleBackColor = True
		'			Me.btnClose.Click += New System.EventHandler(Me.BtnCloseClick);
		' 
		' lvDevices
		' 
		Me.lvDevices.Anchor = (CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles))
		Me.lvDevices.FullRowSelect = True
		Me.lvDevices.HideSelection = False
		Me.lvDevices.Location = New System.Drawing.Point(3, 3)
		Me.lvDevices.MultiSelect = False
		Me.lvDevices.Name = "lvDevices"
		Me.lvDevices.Size = New System.Drawing.Size(199, 301)
		Me.lvDevices.TabIndex = 7
		Me.lvDevices.TileSize = New System.Drawing.Size(195, 30)
		Me.lvDevices.UseCompatibleStateImageBehavior = False
		Me.lvDevices.View = System.Windows.Forms.View.List
		'			Me.lvDevices.SelectedIndexChanged += New System.EventHandler(Me.LvDevicesSelectedIndexChanged);
		' 
		' VirtualDeviceManagerForm
		' 
		Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0F, 13.0F)
		Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
		Me.ClientSize = New System.Drawing.Size(613, 364)
		Me.Controls.Add(Me.lvDevices)
		Me.Controls.Add(Me.btnClose)
		Me.Controls.Add(Me.btnUnplug)
		Me.Controls.Add(Me.btnPlug)
		Me.Controls.Add(Me.btnRemove)
		Me.Controls.Add(Me.btnAdd)
		Me.Controls.Add(Me.propertyGrid)
		Me.Name = "VirtualDeviceManagerForm"
		Me.ShowIcon = False
		Me.Text = "Virtual Device Manager"
		Me.ResumeLayout(False)

	End Sub

#End Region

	Private WithEvents propertyGrid As System.Windows.Forms.PropertyGrid
	Private WithEvents btnAdd As System.Windows.Forms.Button
	Private WithEvents btnRemove As System.Windows.Forms.Button
	Private WithEvents btnPlug As System.Windows.Forms.Button
	Private WithEvents btnUnplug As System.Windows.Forms.Button
	Private WithEvents btnClose As System.Windows.Forms.Button
	Private WithEvents lvDevices As System.Windows.Forms.ListView

End Class
