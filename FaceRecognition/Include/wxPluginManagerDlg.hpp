#ifndef PLUGIN_MANAGER_DLG_H_INCLUDED
#define PLUGIN_MANAGER_DLG_H_INCLUDED

#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/thread.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/textctrl.h>

#include <map>
#include <NCore.hpp>
#include <NPluginManager.hpp>
#include <NPlugin.hpp>

#undef wxPluginManagerDlgStyle
#ifdef __WXMAC__
#define wxPluginManagerDlgStyle wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMAXIMIZE_BOX
#else
#define wxPluginManagerDlgStyle wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCLOSE_BOX
#endif

namespace Neurotec { namespace Gui {

DEFINE_EVENT_TYPE(wxEVT_PLUGIN_MANAGER_DLG)

class wxPluginManagerDlg : public wxDialog
{
private:
	class AsyncRun : public wxThread
	{
	private:
		enum Target
		{
			AddPlugin,
			PluginManagerFunc,
			PluginFunc,
		};

		Target _target;
		Neurotec::Plugins::wxNPluginManager * _pluginManager;
		Neurotec::Plugins::wxNPlugin * _plugin;
		void (Neurotec::Plugins::wxNPluginManager:: * _pluginManagerFunction)();
		void (Neurotec::Plugins::wxNPlugin:: * _pluginFunction)();
		wxString _param;

		AsyncRun(void (Neurotec::Plugins::wxNPluginManager::*ptr)(), Neurotec::Plugins::wxNPluginManager * instance) : wxThread()
		{
			_pluginManagerFunction = ptr;
			_pluginManager = instance;
			_target = PluginManagerFunc;
		}

		AsyncRun(void (Neurotec::Plugins::wxNPlugin::*ptr)(), Neurotec::Plugins::wxNPlugin * plugin) : wxThread()
		{
			_pluginFunction = ptr;
			_plugin = plugin;
			_target = PluginFunc;
		}

		AsyncRun(Neurotec::Plugins::wxNPluginManager* manager, wxString param) : wxThread()
		{
			_pluginManager = manager;
			_param = param;
			_target = AddPlugin;
		}

	public:
		virtual void* Entry()
		{
			switch(_target)
			{
			case AddPlugin:
				_pluginManager->GetPlugins()->Add(_param);
				break;
			case PluginManagerFunc:
				(_pluginManager->*_pluginManagerFunction)();
				break;
			case PluginFunc:
				(_plugin->*_pluginFunction)();
				break;
			default:
				break;
			}
			return NULL;
		}

		static void AddPluginAsync(Neurotec::Plugins::wxNPluginManager * pManager, wxString plugin)
		{
			AsyncRun * target = new AsyncRun(pManager, plugin);
			target->Create();
			target->Run();
		}
		static void PlugAllAsync(Neurotec::Plugins::wxNPluginManager * pManager)
		{
			AsyncRun * target = new AsyncRun(&Neurotec::Plugins::wxNPluginManager::PlugAll, pManager);
			target->Create();
			target->Run();
		}
		static void UnplugAllAsync(Neurotec::Plugins::wxNPluginManager * pManager)
		{
			AsyncRun * target = new AsyncRun(&Neurotec::Plugins::wxNPluginManager::UnplugAll, pManager);
			target->Create();
			target->Run();
		}
		static void RefreshAsync(Neurotec::Plugins::wxNPluginManager * pManager)
		{
			AsyncRun * target = new AsyncRun(&Neurotec::Plugins::wxNPluginManager::Refresh, pManager);
			target->Create();
			target->Run();
		}
		static void PlugAsync(Neurotec::Plugins::wxNPlugin * plugin)
		{
			AsyncRun * target = new AsyncRun(&Neurotec::Plugins::wxNPlugin::Plug, plugin);
			target->Create();
			target->Run();
		}
		static void UnplugAsync(Neurotec::Plugins::wxNPlugin * plugin)
		{
			AsyncRun * target = new AsyncRun(&Neurotec::Plugins::wxNPlugin::Unplug, plugin);
			target->Create();
			target->Run();
		}
		static void EnableAsync(Neurotec::Plugins::wxNPlugin * plugin)
		{
			AsyncRun * target = new AsyncRun(&Neurotec::Plugins::wxNPlugin::Enable, plugin);
			target->Create();
			target->Run();
		}
		static void DisableAsync(Neurotec::Plugins::wxNPlugin * plugin)
		{
			AsyncRun * target = new AsyncRun(&Neurotec::Plugins::wxNPlugin::Disable, plugin);
			target->Create();
			target->Run();
		}
	};

public:
	wxPluginManagerDlg(wxWindow *parent, wxWindowID id, ::Neurotec::Plugins::wxNPluginManager * pManager, ::Neurotec::Plugins::wxNPlugin* selectedPlugin = NULL, const wxString& windowTitle = wxT("Plugin Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxPluginManagerDlgStyle)
		: wxDialog(parent, id, windowTitle, pos, size, style)
	{
		InitGUI();

		pluginManager = pManager;
		OnPluginManagerChanged();
		listActivated->SetFocus();
		OnSetSelectedPlugin(selectedPlugin);

		this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(wxPluginManagerDlg::OnClose), NULL, this);
		this->Connect(ID_BUTTON_ADD, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnAddClick), NULL, this);
		this->Connect(ID_BUTTON_BROWSE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnBrowseClick), NULL, this);
		this->Connect(ID_BUTTON_DISABLE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnDisableClick), NULL, this);
		this->Connect(ID_BUTTON_ENABLE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnEnableClick), NULL, this);
		this->Connect(ID_BUTTON_PLUG, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnPlugClick), NULL, this);
		this->Connect(ID_BUTTON_PLUGALL, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnPlugAllClick), NULL, this);
		this->Connect(ID_BUTTON_UNPLUG, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnUnplugClick), NULL, this);
		this->Connect(ID_BUTTON_UNPLUGALL, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnUnplugAllClick), NULL, this);
		this->Connect(ID_BUTTON_REFRESH, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnRefreshClick), NULL, this);
		this->Connect(ID_LIST_PLUGINS, wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(wxPluginManagerDlg::OnListItemSelected), NULL, this);
		this->Connect(ID_LIST_PLUGINS, wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxCommandEventHandler(wxPluginManagerDlg::OnListItemDeselected), NULL, this);
		this->Connect(wxEVT_PLUGIN_MANAGER_DLG, wxCommandEventHandler(wxPluginManagerDlg::OnPluginManagerEvent), NULL, this);
	}
	~wxPluginManagerDlg()
	{
		this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(wxPluginManagerDlg::OnClose), NULL, this);
		this->Disconnect(ID_BUTTON_ADD, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnAddClick), NULL, this);
		this->Disconnect(ID_BUTTON_BROWSE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnBrowseClick), NULL, this);
		this->Disconnect(ID_BUTTON_DISABLE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnDisableClick), NULL, this);
		this->Disconnect(ID_BUTTON_ENABLE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnEnableClick), NULL, this);
		this->Disconnect(ID_BUTTON_PLUG, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnPlugClick), NULL, this);
		this->Disconnect(ID_BUTTON_PLUGALL, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnPlugAllClick), NULL, this);
		this->Disconnect(ID_BUTTON_UNPLUG, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnUnplugClick), NULL, this);
		this->Disconnect(ID_BUTTON_UNPLUGALL, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnUnplugAllClick), NULL, this);
		this->Disconnect(ID_BUTTON_REFRESH, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxPluginManagerDlg::OnBtnRefreshClick), NULL, this);
		this->Disconnect(ID_LIST_PLUGINS, wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(wxPluginManagerDlg::OnListItemSelected), NULL, this);
		this->Disconnect(ID_LIST_PLUGINS, wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxCommandEventHandler(wxPluginManagerDlg::OnListItemDeselected), NULL, this);
		this->Disconnect(wxEVT_PLUGIN_MANAGER_DLG, wxCommandEventHandler(wxPluginManagerDlg::OnPluginManagerEvent), NULL, this);

		if(pluginManager)
		{
			int count = pluginManager->GetPlugins()->GetCount();
			for(int i = 0; i < count; i++)
			{
				Neurotec::Plugins::wxNPlugin * plugin = pluginManager->GetPlugins()->Get(i);
				plugin->RemoveChangedCallback(PluginChanged, this);
			}
			pluginManager->RemovePluginAddedCallback(PluginManager_PluginAdded, this);
			pluginManager->RemoveDisabledPluginsChangedCallback(PluginManager_DisabledPluginCanged, this);
		}
	}
private:
	void InitGUI()
	{
		m_sizer = new wxBoxSizer(wxVERTICAL);
		SetSizer(m_sizer);
		SetAutoLayout(true);

		wxBoxSizer * bSizerTop = new wxBoxSizer(wxHORIZONTAL);

		wxBoxSizer * bSizerLeft = new wxBoxSizer(wxVERTICAL);

		lblInterfaceType = new wxStaticText(this, wxID_ANY, wxT("Interface type:"));
		bSizerLeft->Add(lblInterfaceType, 1, wxALL | wxEXPAND, 1);

		lblInterfaceVersion = new wxStaticText(this, wxID_ANY, wxT("Interface versions:"));
		bSizerLeft->Add(lblInterfaceVersion, 1, wxALL | wxEXPAND, 1);

		lblSearchPath = new wxStaticText(this, wxID_ANY, wxT("Plugin search path:"));
		bSizerLeft->Add(lblSearchPath, 1, wxALL | wxEXPAND, 1);

		bSizerLeft->AddStretchSpacer(1);

		bSizerTop->Add(bSizerLeft, 0, wxALL | wxEXPAND, 1);

		wxBoxSizer * bSizerRight = new wxBoxSizer(wxVERTICAL);
		lblInterfaceTypeValue = new wxStaticText(this, wxID_ANY, wxT("Type"));
		bSizerRight->Add(lblInterfaceTypeValue, 1, wxALL | wxEXPAND, 1);

		lblInterfaceVersionValue = new wxStaticText(this, wxID_ANY, wxT("Versions"));
		bSizerRight->Add(lblInterfaceVersionValue, 1, wxALL | wxEXPAND, 1);

		wxBoxSizer * bSizer1 = new wxBoxSizer(wxHORIZONTAL);
		tbSearchPath = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
		bSizer1->Add(tbSearchPath, 1, wxALL | wxEXPAND, 1);

		btnBrowse = new wxButton(this, ID_BUTTON_BROWSE, wxT("..."));
		bSizer1->Add(btnBrowse, 0, wxALL | wxEXPAND, 1);
		bSizerRight->Add(bSizer1, 1, wxALL | wxEXPAND, 1);

		wxBoxSizer * bSizer2 = new wxBoxSizer(wxHORIZONTAL);
		bSizer2->AddStretchSpacer(1);

		btnAdd = new wxButton(this, ID_BUTTON_ADD, wxT("&Add ..."));
		bSizer2->Add(btnAdd, 0, wxALL | wxEXPAND, 1);

		btnRefresh = new wxButton(this, ID_BUTTON_REFRESH, wxT("&Refresh"));
		bSizer2->Add(btnRefresh, 0, wxALL | wxEXPAND, 1);

		btnPlugAll = new wxButton(this, ID_BUTTON_PLUGALL, wxT("&Plug all"));
		bSizer2->Add(btnPlugAll, 0, wxALL | wxEXPAND, 1);

		btnUnplugAll = new wxButton(this, ID_BUTTON_UNPLUGALL, wxT("&Unplug all"));
		bSizer2->Add(btnUnplugAll, 0, wxALL | wxEXPAND, 1);

		bSizerRight->Add(bSizer2, 0, wxALL | wxEXPAND, 1);
		bSizerTop->Add(bSizerRight, 1, wxALL | wxEXPAND, 1);
		m_sizer->Add(bSizerTop, 0, wxALL | wxEXPAND, 1);

		wxStaticText * text4 = new wxStaticText(this, wxID_ANY, wxT("Plugins:"));
		m_sizer->Add(text4, 0, wxALL | wxEXPAND | wxALIGN_TOP, 1);

		listPlugins = new wxListCtrl(this, ID_LIST_PLUGINS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
		listPlugins->InsertColumn(0, wxT("Title"));
		listPlugins->InsertColumn(1, wxT("Version"));
		listPlugins->InsertColumn(2, wxT("Copyright"));
		listPlugins->InsertColumn(3, wxT("State"));
		listPlugins->InsertColumn(4, wxT("Load time"));
		listPlugins->InsertColumn(5, wxT("Plug time"));
		listPlugins->InsertColumn(6, wxT("Selected interface version"));
		listPlugins->InsertColumn(7, wxT("Name"));
		listPlugins->InsertColumn(8, wxT("File name"));
		listPlugins->InsertColumn(9, wxT("Interface type"));
		listPlugins->InsertColumn(10, wxT("Interface versions"));
		listPlugins->InsertColumn(11, wxT("Priority"));
		listPlugins->InsertColumn(12, wxT("Incompatible plugins"));
		listPlugins->SetSizeHints(700, 250);

		m_sizer->Add(listPlugins, 1, wxALL | wxEXPAND | wxALIGN_CENTER | wxALIGN_TOP, 5);

		wxBoxSizer * bSizer3 = new wxBoxSizer(wxHORIZONTAL);
		m_notebook = new wxNotebook(this, wxID_ANY);

		textError = new wxTextCtrl(m_notebook, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP | wxTE_AUTO_SCROLL | wxTE_MULTILINE);
		textError->SetEditable(false);
		m_notebook->AddPage(textError, wxT("Error"), true);

		listActivated = new wxListCtrl(m_notebook, wxID_ANY);
		listActivated->InsertColumn(0, wxT("Component"));
		listActivated->InsertColumn(1, wxT("Value"));
		m_notebook->AddPage(listActivated, wxT("Activated"));

		bSizer3->Add(m_notebook, 1, wxALL | wxEXPAND, 5);

		wxBoxSizer * bSizer4 = new wxBoxSizer(wxVERTICAL);
		btnPlug = new wxButton(this, ID_BUTTON_PLUG, wxT("P&lug"));
		bSizer4->Add(btnPlug, 0, wxALL | wxEXPAND, 5);

		btnUnplug = new wxButton(this, ID_BUTTON_UNPLUG, wxT("U&nplug"));
		bSizer4->Add(btnUnplug, 0, wxALL | wxEXPAND, 5);

		btnEnable = new wxButton(this, ID_BUTTON_ENABLE, wxT("&Enable"));
		bSizer4->Add(btnEnable, 0, wxALL | wxEXPAND, 5);

		btnDisable = new wxButton(this, ID_BUTTON_DISABLE, wxT("&Disable"));
		bSizer4->Add(btnDisable, 0, wxALL | wxEXPAND, 5);

		bSizer3->Add(bSizer4, 0, wxALL | wxEXPAND, 5);
		m_sizer->Add(bSizer3, 0, wxALL | wxEXPAND, 5);

		wxBoxSizer * bSizerBottom = new wxBoxSizer(wxHORIZONTAL);
		lblTotalInfo = new wxStaticText(this, wxID_ANY, wxT("Total info"));
		bSizerBottom->Add(lblTotalInfo, 1, wxALL | wxEXPAND, 5);

		btnOk = new wxButton(this, wxID_OK, wxT("OK"));
		bSizerBottom->Add(btnOk, 0, wxALL | wxEXPAND, 5);

		m_sizer->Add(bSizerBottom, 0, wxALL | wxEXPAND, 5);

		SetIcon(wxNullIcon);
		SetBackgroundColour(wxColour(255, 255, 255));
		GetSizer()->Layout();
		GetSizer()->Fit(this);
		GetSizer()->SetSizeHints(this);
		Center();
	}


	wxBoxSizer * m_sizer;

	wxStaticText * lblInterfaceTypeValue;
	wxStaticText * lblInterfaceType;
	wxStaticText * lblInterfaceVersionValue;
	wxStaticText * lblInterfaceVersion;
	wxStaticText * lblSearchPath;
	wxStaticText * lblTotalInfo;
	wxTextCtrl * tbSearchPath;
	wxButton * btnBrowse;
	wxButton * btnAdd;
	wxButton * btnRefresh;
	wxButton * btnPlugAll;
	wxButton * btnUnplugAll;
	wxButton * btnEnable;
	wxButton * btnDisable;
	wxButton * btnPlug;
	wxButton * btnUnplug;
	wxButton * btnOk;
	wxListCtrl * listActivated;
	wxNotebook * m_notebook;
	wxListCtrl * listPlugins;
	wxTextCtrl * textError;

	Neurotec::Plugins::wxNPluginManager * pluginManager;
	static const int StateCollumn = 3;
	static const int LoadTimeCollumn = 4;
	static const int PlugTimeCollumn = 5;
	std::map<long, Neurotec::Plugins::wxNPlugin*> plugins;

private:
	void OnClose(wxCloseEvent&)
	{
		Destroy();
	}
	wxString GetInterfaceVersionsString()
	{
		if(!pluginManager) return wxEmptyString;
		int count;
		std::auto_ptr<Neurotec::wxNVersionRange> versions(pluginManager->GetInterfaceVersions(&count));
		wxString value = InterfaceVersionsToString(versions.get(), count);
		return value;
	}

	wxString GetInterfaceVersionsString(Neurotec::Plugins::wxNPluginModule * module)
	{
		if(!module) return wxEmptyString;
		int count;
		std::auto_ptr<Neurotec::wxNVersionRange> versions(module->GetInterfaceVersions(&count));
		wxString result = InterfaceVersionsToString(versions.get(), count);
		return result;
	}

	wxString InterfaceVersionsToString(Neurotec::wxNVersionRange * pVersions, int count)
	{
		wxString value = wxT("");
		for(int i = 0; i < count; i++)
		{
			if(value.length() != 0)
				value.append(wxT(", "));
			value.append(pVersions[i].ToString());
		}
		return value;
	}

	wxString GetModuleVersion(Neurotec::wxNModule * module)
	{
		if(!module) return wxEmptyString;
		return wxString::Format(wxT("%d.%d.%d.%d"), module->GetVersionMajor(), module->GetVersionMinor(), module->GetVersionBuild(), module->GetVersionRevision());
	}

	Neurotec::Plugins::wxNPlugin * SelectedPlugin()
	{
		if(listPlugins->GetSelectedItemCount())
		{
			return plugins[listPlugins->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)];
		}
		else return NULL;
	}

	void OnPluginManagerEvent(wxCommandEvent& event)
	{
		if(event.GetId() == ID_PLUGINMANAGER_PLUGIN_ADDED)
		{
			OnPluginAdded((Neurotec::Plugins::wxNPlugin*)event.GetClientData());
		}
		else if(event.GetId() == ID_PLUGINMANAGER_DISABLED_PLUGINS_CHANGED)
		{
			OnDisabledPluginsChanged();
		}
		else if(event.GetId() == ID_PLUGINMANAGER_PLUGIN_CHANGED)
		{
			OnPluginChanged((Neurotec::Plugins::wxNPlugin*)event.GetClientData());
		}
	}

	void AddPlugin(Neurotec::Plugins::wxNPlugin * plugin)
	{
		Neurotec::Plugins::wxNPluginModule * module = plugin->GetModule();
		long index = listPlugins->InsertItem(listPlugins->GetItemCount(), module == NULL? wxString(wxEmptyString) : wxString::Format(wxT("%s (%s)"), ((wxString)module->GetTitle()).c_str(), NModuleOptionsToString(module->GetOptions()).c_str()));
		listPlugins->SetItem(index, 1, GetModuleVersion(module));
		listPlugins->SetItem(index, 2, module == NULL? wxString(wxEmptyString) : module->GetCopyright());
		listPlugins->SetItem(index, 3, wxEmptyString);
		listPlugins->SetItem(index, 4, wxEmptyString);
		listPlugins->SetItem(index, 5, wxEmptyString);
		listPlugins->SetItem(index, 6, plugin->GetSelectedInterfaceVersion().ToString());
		listPlugins->SetItem(index, 7, module == NULL? wxString(wxEmptyString) : module->GetPluginName());
		listPlugins->SetItem(index, 8, plugin->GetFileName());
		listPlugins->SetItem(index, 9, module == NULL? wxString(wxEmptyString) : module->GetInterfaceType());
		listPlugins->SetItem(index, 10, GetInterfaceVersionsString(module));
		listPlugins->SetItem(index, 11, module == NULL? wxString(wxEmptyString) : wxString::Format(wxT("%d"), module->GetPriority()));
		listPlugins->SetItem(index, 12, module == NULL? wxString(wxEmptyString) : module->GetIncompatiblePlugins());
		plugins[index] = plugin;

		::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(plugin->GetLock()));
		try
		{
			plugin->AddChangedCallback(PluginChanged, this);
			UpdatePluginState(index);
			listPlugins->SetColumnWidth(0, wxLIST_AUTOSIZE);
			listPlugins->SetColumnWidth(1, wxLIST_AUTOSIZE);
		}
		catch(...){}
	}

	void UpdatePluginState(int index)
	{
		Neurotec::Plugins::wxNPlugin * plugin = plugins[index];
		listPlugins->SetItem(index, StateCollumn, NPluginStateToString(plugin->GetState()));
		std::auto_ptr<Neurotec::wxNException> error(plugin->GetError());
		listPlugins->SetItem(index, LoadTimeCollumn, plugin->GetLoadTime().IsValid()? wxString::Format(wxT("%2.2f s"), plugin->GetLoadTime().GetTotalSeconds()) : wxString(wxEmptyString));
		listPlugins->SetItem(index, PlugTimeCollumn, plugin->GetPlugTime().IsValid()? wxString::Format(wxT("%2.2f s"), plugin->GetPlugTime().GetTotalSeconds()) : wxString(wxEmptyString));
	}

	void UpdateTotalInfo()
	{
		if(pluginManager)
		{
			Neurotec::wxNTimeSpan loadTime(0, 0, 0, 0, 0);
			Neurotec::wxNTimeSpan plugTime(0, 0, 0, 0, 0);
			int unpluggedCount = 0;
			int unusedCount = 0;
			int count = pluginManager->GetPlugins()->GetCount();
			for(int i = 0; i < count; i++)
			{
				Neurotec::Plugins::wxNPlugin* plugin = pluginManager->GetPlugins()->Get(i);
				loadTime = loadTime + plugin->GetLoadTime();
				plugTime = plugTime + plugin->GetPlugTime();
				if(plugin->GetState() == Neurotec::Plugins::npsUnplugged) unpluggedCount++;
				else if(plugin->GetState() == Neurotec::Plugins::npsUnused) unusedCount++;
			}
			wxString disabledPlugins = wxEmptyString;
			{
				::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(pluginManager->GetDisabledPlugins()->GetLock()));
				count = pluginManager->GetDisabledPlugins()->GetCount();
				for(int i = 0; i < count; i++)
				{
					disabledPlugins.append(disabledPlugins.length() == 0? wxT(". Disabled: ") : wxT(", "));
					disabledPlugins.append(pluginManager->GetDisabledPlugins()->Get(i));
				}
			}
			Neurotec::wxNTimeSpan totalTime = loadTime + plugTime;
			wxString parse = wxT("Total time: %.2f s (Load: %2.2f s. Plug: %2.2f s). Total plugins: %d (Unplugged: %d. Unused: %d)%s");
			lblTotalInfo->SetLabel(wxString::Format(parse, totalTime.GetTotalSeconds(), loadTime.GetTotalSeconds(), plugTime.GetTotalSeconds(),
				pluginManager->GetPlugins()->GetCount(), unpluggedCount, unusedCount, disabledPlugins.c_str()));
		}
		else
		{
			lblTotalInfo->SetLabel(wxEmptyString);
		}
	}

	void UpdatePlugin(Neurotec::Plugins::wxNPlugin* plugin)
	{
		long index = -1;
		while((index = listPlugins->GetNextItem(index, wxLIST_NEXT_ALL)) != -1)
		{
			Neurotec::Plugins::wxNPlugin * item = plugins[index];
			if(item->Equals(plugin))
			{
				UpdatePluginState(index);
				if(listPlugins->GetItemState(index, wxLIST_MASK_STATE) == wxLIST_STATE_SELECTED)
				{
					OnSelectedPluginChanged();
				}
			}
		}
	}

	void OnListItemSelected(wxCommandEvent&)
	{
		OnSelectedPluginChanged();
	}

	void OnListItemDeselected(wxCommandEvent&)
	{
		OnSelectedPluginChanged();
	}

	void OnBtnUnplugClick(wxCommandEvent&)
	{
		::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(pluginManager->GetPlugins()->GetLock()));
		try
		{
			this->Enable(false);
			long item = -1;
			while((item = listPlugins->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != -1)
			{
				AsyncRun::UnplugAsync(plugins[item]);
			}
		}
		catch(...){ }
		this->Enable(true);
	}

	void OnBtnUnplugAllClick(wxCommandEvent&)
	{
		if(!pluginManager) return;
		AsyncRun::UnplugAllAsync(pluginManager);
	}

	void OnBtnRefreshClick(wxCommandEvent&)
	{
		if(!pluginManager) return;
		AsyncRun::RefreshAsync(pluginManager);
	}

	void OnBtnPlugAllClick(wxCommandEvent&)
	{
		if(!pluginManager) return;
		AsyncRun::PlugAllAsync(pluginManager);
	}

	void OnBtnPlugClick(wxCommandEvent&)
	{
		::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(pluginManager->GetPlugins()->GetLock()));
		try
		{
			this->Enable(false);
			long item = -1;
			while((item = listPlugins->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != -1)
			{
				AsyncRun::PlugAsync(plugins[item]);
			}
		}
		catch(...){ }
		this->Enable(true);
	}

	void OnBtnEnableClick(wxCommandEvent&)
	{
		::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(pluginManager->GetPlugins()->GetLock()));
		try
		{
			this->Enable(false);
			long item = -1;
			while((item = listPlugins->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != -1)
			{
				AsyncRun::EnableAsync(plugins[item]);
			}
		}
		catch(...){ }
		this->Enable(true);
	}

	void OnBtnDisableClick(wxCommandEvent&)
	{
		::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(pluginManager->GetPlugins()->GetLock()));
		try
		{
			this->Enable(false);
			long item = -1;
			while((item = listPlugins->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != -1)
			{
				AsyncRun::DisableAsync(plugins[item]);
			}
		}
		catch(...){ }
		this->Enable(true);
	}

	void OnBtnBrowseClick(wxCommandEvent&)
	{
		if(pluginManager)
		{
			wxString folder;
			wxDirDialog dialog(this, wxT("Select folder"), pluginManager->GetPluginSearchPath());
			if(dialog.ShowModal() == wxID_OK)
			{
				pluginManager->SetPluginSearchPath(dialog.GetPath());
				OnPluginSearchPathChanged();
			}
		}
	}

	void OnBtnAddClick(wxCommandEvent&)
	{
		if(!pluginManager) return;
		wxArrayString paths;
		wxFileDialog dialog(this, wxFileSelectorPromptStr, wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN | wxFD_MULTIPLE | wxFD_FILE_MUST_EXIST);
		if(dialog.ShowModal() == wxID_OK)
		{
			dialog.GetPaths(paths);
			if(paths.Count() > 0)
			{
				this->Enable(false);
				try
				{
					for(wxArrayString::iterator it = paths.begin(); it != paths.end(); it++)
					{
						AsyncRun::AddPluginAsync(pluginManager, *it);
					}
				}
				catch(...){}
				this->Enable(true);
			}
		}
	}

	void OnSetSelectedPlugin(Neurotec::Plugins::wxNPlugin * select)
	{
		int index = -1;
		while((index = listPlugins->GetNextItem(index, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != -1)
		{
			listPlugins->SetItemState(index, 0, wxLIST_STATE_SELECTED | wxLIST_STATE_FOCUSED);
		}
		if(select)
		{
			index = -1;
			while((index = listPlugins->GetNextItem(index, wxLIST_NEXT_ALL)) != -1)
			{
				Neurotec::Plugins::wxNPlugin * plugin = plugins[index];
				if(plugin->Equals(select))
				{
					listPlugins->SetItemState(index, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
					OnSelectedPluginChanged();
					break;
				}
			}
		}
	}

	void OnPluginManagerChanged()
	{
		lblInterfaceTypeValue->SetLabel(pluginManager? pluginManager->GetInterfaceType() : wxString(wxEmptyString));
		lblInterfaceVersionValue->SetLabel(GetInterfaceVersionsString());
		bool enable = pluginManager != NULL;
		lblInterfaceType->Enable(enable);
		lblInterfaceVersion->Enable(enable);
		listPlugins->Enable(enable);
		lblSearchPath->Enable(enable);
		tbSearchPath->Enable(enable);
		tbSearchPath->SetEditable(false);
		btnBrowse->Enable(enable);
		btnUnplugAll->Enable(enable && pluginManager->AllowsUnplug());
		btnUnplug->Enable(enable && pluginManager->AllowsUnplug());
		btnAdd->Enable(enable);
		btnRefresh->Enable(enable);
		btnPlugAll->Enable(enable);
		OnPluginSearchPathChanged();

		listPlugins->DeleteAllItems();
		plugins.clear();
		if(pluginManager)
		{
			::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(pluginManager->GetDisabledPlugins()->GetLock()));
			::Neurotec::Threading::NMonitorLockerType locker2(N_MONITOR_LOCKER_ARGS(pluginManager->GetPlugins()->GetLock()));
			int pluginCount = pluginManager->GetPlugins()->GetCount();
			for(int i = 0; i < pluginCount; i++)
			{
				AddPlugin(pluginManager->GetPlugins()->Get(i));
			}

			if(pluginCount != 0)
			{
				listPlugins->SetColumnWidth(0, wxLIST_AUTOSIZE);
				listPlugins->SetColumnWidth(1, wxLIST_AUTOSIZE);
			}
			pluginManager->AddDisabledPluginsChangedCallback(PluginManager_DisabledPluginCanged, this);
			pluginManager->AddPluginAddedCallback(PluginManager_PluginAdded, this);
		}

		UpdateTotalInfo();
		OnSelectedPluginChanged();
	}
	void OnSelectedPluginChanged()
	{
		int count = listPlugins->GetSelectedItemCount();
		long item;
		Neurotec::Plugins::wxNPlugin * plugin = NULL;
		if(count == 1)
		{
			item = listPlugins->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
			plugin = plugins[item];
		}

		listActivated->DeleteAllItems();

		Neurotec::Plugins::wxNPluginModule * module = plugin == NULL? NULL : plugin->GetModule();
		if (module)
		{
			long index;
			wxArrayString strings = wxStringTokenize(module->GetActivated(), wxT(":,"), wxTOKEN_STRTOK);
			for (size_t i = 0; i < strings.Count() / 2; ++i)
			{
				index = listActivated->InsertItem(listActivated->GetItemCount(), strings[i * 2].Trim(false));
				listActivated->SetItem(index, 1, strings[i * 2 + 1].Trim(false));
			}

			listActivated->SetColumnWidth(0, wxLIST_AUTOSIZE);
			listActivated->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
		}

		textError->SetValue(wxEmptyString);
		if(plugin)
		{
			std::auto_ptr<Neurotec::wxNException> error(plugin->GetError());
			if(error.get())
			{
				textError->SetValue(error->ToString());
			}
		}
		btnUnplug->Enable(count > 0 && pluginManager->AllowsUnplug());
		btnPlug->Enable(count > 0);
		btnEnable->Enable(count > 0);
		btnDisable->Enable(count > 0);
	}

	void OnPluginSearchPathChanged()
	{
		tbSearchPath->SetValue(pluginManager == NULL ? wxString(wxEmptyString) : pluginManager->GetPluginSearchPath());
		tbSearchPath->SetEditable(true);
	}

	void OnPluginChanged(Neurotec::Plugins::wxNPlugin* plugin)
	{
		UpdatePlugin(plugin);
	}

	void OnPluginAdded(Neurotec::Plugins::wxNPlugin* plugin)
	{
		AddPlugin(plugin);
		OnSetSelectedPlugin(plugin);
		UpdateTotalInfo();
	}

	void OnDisabledPluginsChanged()
	{
		UpdateTotalInfo();
	}

	static void PluginChanged(Neurotec::wxNObject * pObject, void * pParam)
	{
		wxPluginManagerDlg * dialog = (wxPluginManagerDlg*)pParam;
		wxCommandEvent event;
		event.SetEventType(wxEVT_PLUGIN_MANAGER_DLG);
		event.SetId(ID_PLUGINMANAGER_PLUGIN_CHANGED);
		event.SetClientData((Neurotec::Plugins::wxNPlugin*)pObject);

		wxPostEvent(dialog, event);
	}

	static void PluginManager_PluginAdded(Neurotec::Plugins::wxNPluginManager *, Neurotec::Plugins::wxNPlugin * pPlugin, void * pParam)
	{
		wxPluginManagerDlg * dialog = (wxPluginManagerDlg*)pParam;
		wxCommandEvent event;
		event.SetEventType(wxEVT_PLUGIN_MANAGER_DLG);
		event.SetId(ID_PLUGINMANAGER_PLUGIN_ADDED);
		event.SetClientData(pPlugin);
		wxPostEvent(dialog, event);
	}

	static void PluginManager_DisabledPluginCanged(Neurotec::wxNObject *, void * pParam)
	{
		wxPluginManagerDlg * dialog = (wxPluginManagerDlg*)pParam;
		wxCommandEvent event;
		event.SetEventType(wxEVT_PLUGIN_MANAGER_DLG);
		event.SetId(ID_PLUGINMANAGER_DISABLED_PLUGINS_CHANGED);
		wxPostEvent(dialog, event);
	}

	static wxString NModuleOptionsToString(Neurotec::NModuleOptions options)
	{
		wxString value = wxEmptyString;
		if((options & Neurotec::nmoDebug) == Neurotec::nmoDebug)
			value = wxT("Debug");
		if((options  & Neurotec::nmoProtected) == Neurotec::nmoProtected)
		{
			value = value.IsEmpty() ? value : value.append(wxT(", "));
			value.append(wxT("Protected"));
		}
		if((options & Neurotec::nmoUnicode) == Neurotec::nmoUnicode)
		{
			value = value.IsEmpty()? value : value.append(wxT(", "));
			value.append(wxT("Unicode"));
		}
		if((options & Neurotec::nmoNoAnsiFunc) == Neurotec::nmoNoAnsiFunc)
		{
			value = value.IsEmpty()? value : value.append(wxT(", "));
			value.append(wxT("NoAnsiFunc"));
		}
		if((options & Neurotec::nmoNoUnicode) == Neurotec::nmoNoUnicode)
		{
			value = value.IsEmpty()? value : value.append(wxT(", "));
			value.append(wxT("NoUnicode"));
		}
		if((options & Neurotec::nmoLib) == Neurotec::nmoLib)
		{
			value = value.IsEmpty()? value : value.append(wxT(", "));
			value.append(wxT("Lib"));
		}
		if((options & Neurotec::nmoExe) == Neurotec::nmoExe)
		{
			value = value.IsEmpty()? value : value.append(wxT(", "));
			value.append(wxT("Exe"));
		}

		return value.IsEmpty()? wxT("None") : value;
	}

	static wxString NPluginStateToString(Neurotec::Plugins::NPluginState state)
	{
		switch(state)
		{
		case Neurotec::Plugins::npsNone: return wxT("None");
		case Neurotec::Plugins::npsLoadError: return wxT("LoadError");
		case Neurotec::Plugins::npsNotRecognized: return wxT("NotRecognized");
		case Neurotec::Plugins::npsInvalidModule: return wxT("InvalidModule");
		case Neurotec::Plugins::npsInterfaceTypeMismatch: return wxT("InterfaceTypeMismatch");
		case Neurotec::Plugins::npsInterfaceVersionMismatch: return wxT("InterfaceVersionMismatch");
		case Neurotec::Plugins::npsInvalidInterface: return wxT("InvalidInterface");
		case Neurotec::Plugins::npsUnplugged: return wxT("Unplugged");
		case Neurotec::Plugins::npsUnused: return wxT("Unused");
		case Neurotec::Plugins::npsDisabled: return wxT("Disabled");
		case Neurotec::Plugins::npsDuplicate: return wxT("Duplicate");
		case Neurotec::Plugins::npsIncompatibleWithOtherPlugins: return wxT("IncompatibleWithOtherPlugins");
		case Neurotec::Plugins::npsPluggingError: return wxT("PluggingError");
		case Neurotec::Plugins::npsPlugged: return wxT("Plugged");
		default: return wxT("Unknown");
		}
	}

	enum
	{
		ID_BUTTON_BROWSE = 1000,
		ID_BUTTON_ADD,
		ID_BUTTON_REFRESH,
		ID_BUTTON_PLUGALL,
		ID_BUTTON_UNPLUGALL,
		ID_BUTTON_ENABLE,
		ID_BUTTON_DISABLE,
		ID_BUTTON_PLUG,
		ID_BUTTON_UNPLUG,
		ID_LIST_PLUGINS,
		ID_LIST_COMPONENTS,
		
		ID_PLUGINMANAGER_PLUGIN_ADDED,
		ID_PLUGINMANAGER_PLUGIN_CHANGED,
		ID_PLUGINMANAGER_DISABLED_PLUGINS_CHANGED,
	};
};
	
}}


#endif
