#include <NPlugin.hpp>

#ifndef N_PLUGIN_MANAGER_HPP_INCLUDED
#define N_PLUGIN_MANAGER_HPP_INCLUDED

namespace Neurotec { namespace Plugins
{
#include <NPluginManager.h>
}}

namespace Neurotec { namespace Plugins
{

class N_CLASS(NPluginManager) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NPluginManager, NObject)

public:
	class PluginCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NPlugin), N_CLASS(NPluginManager)>
	{
		PluginCollection(N_CLASS(NPluginManager) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NPlugin), N_CLASS(NPluginManager)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNPluginManager handle, NInt * pValue) const
		{
			return NPluginManagerGetPluginCount(handle, pValue);
		}

		virtual NResult GetNative(HNPluginManager handle, NInt index, HNPlugin * phValue) const
		{
			return NPluginManagerGetPlugin(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNPluginManager, HNPlugin *, NInt) const
		{
			NThrowNotImplementedException();
		}

	public:
		N_CLASS(NPlugin) * Add(N_CLASS(NPluginModule) * pModule, const N_CLASS(NStringWrapper) & directory)
		{
			if (!pModule) NThrowArgumentNullException(N_T("pModule"));
			::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(GetLock()));
			HNPlugin hPlugin;
			NCheck(NPluginManagerAddPluginN(pOwner->GetHandle(), pModule->GetHandle(), directory.GetHandle(), &hPlugin));
			try
			{
				return FromHandle<N_CLASS(NPlugin)>(hPlugin, true, true);
			}
			catch (...)
			{
				Unref(hPlugin);
				throw;
			}
		}

		N_CLASS(NPlugin) * Add(const N_CLASS(NStringWrapper) & fileName)
		{
			::Neurotec::Threading::NMonitorLockerType locker(N_MONITOR_LOCKER_ARGS(GetLock()));
			HNPlugin hPlugin;
			NCheck(NPluginManagerAddPluginFromFileN(pOwner->GetHandle(), fileName.GetHandle(), &hPlugin));
			try
			{
				return FromHandle<N_CLASS(NPlugin)>(hPlugin, true, true);
			}
			catch (...)
			{
				Unref(hPlugin);
				throw;
			}
		}

		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NPlugin), N_CLASS(NPluginManager)>::IndexOf;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NPlugin), N_CLASS(NPluginManager)>::Contains;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NPlugin), N_CLASS(NPluginManager)>::Get;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NPlugin), N_CLASS(NPluginManager)>::operator[];

		NInt IndexOf(const N_CLASS(NStringWrapper) & name) const
		{
			HNPlugin hPlugin;
			NCheck(NPluginManagerGetPluginByNameN(pOwner->GetHandle(), name.GetHandle(), &hPlugin));
			try
			{
				NInt index = IndexOf(hPlugin);
				Unref(hPlugin); hPlugin = NULL;
				return index;
			}
			catch (...)
			{
				Unref(hPlugin);
				throw;
			}
		}

		bool Contains(const N_CLASS(NStringWrapper) & name) const
		{
			return IndexOf(name) != -1;
		}

		N_CLASS(NPlugin) * Get(const N_CLASS(NStringWrapper) & name) const
		{
			HNPlugin hPlugin;
			NCheck(NPluginManagerGetPluginByNameN(pOwner->GetHandle(), name.GetHandle(), &hPlugin));
			try
			{
				return FromHandle<N_CLASS(NPlugin)>(hPlugin, true, true);
			}
			catch (...)
			{
				Unref(hPlugin);
				throw;
			}
		}

		N_CLASS(NPlugin) * operator[](const N_CLASS(NStringWrapper) & name) const
		{
			return Get(name);
		}

		friend class N_CLASS(NPluginManager);
	};

	class DisabledPluginCollection : public ::Neurotec::Collections::N_CLASS(NStringCollection)<N_CLASS(NPluginManager)>
	{
		DisabledPluginCollection(N_CLASS(NPluginManager) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStringCollection)<N_CLASS(NPluginManager)>(pOwner)
		{
		}

	protected:
		virtual bool SupportsAddWithOutIndex() const
		{
			return true;
		}

		virtual bool SupportsRemoveByValue() const
		{
			return true;
		}

		virtual NResult GetCountNative(HNPluginManager handle, NInt * pValue) const
		{
			return NPluginManagerGetDisabledPluginCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNPluginManager, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNPluginManager, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNPluginManager handle, NInt index, HNString * phValue) const
		{
			return NPluginManagerGetDisabledPluginN(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNPluginManager, HNString *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNPluginManager, NInt, HNString)
		{
			NThrowNotSupportedException();
		}

		virtual NResult AddNative(HNPluginManager, HNString)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNPluginManager handle, HNString hValue, NInt * pIndex)
		{
			return NPluginManagerAddDisabledPluginN(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNPluginManager, NInt, HNString)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveWithOutIndexNative(HNPluginManager handle, HNString hValue, NInt * pIndex)
		{
			return NPluginManagerRemoveDisabledPluginN(handle, hValue, pIndex);
		}

		virtual NResult RemoveAtNative(HNPluginManager handle, NInt index)
		{
			return NPluginManagerRemoveDisabledPluginAt(handle, index);
		}

		virtual NResult RemoveRangeNative(HNPluginManager, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNPluginManager handle)
		{
			return NPluginManagerClearDisabledPlugins(handle);
		}

		friend class N_CLASS(NPluginManager);
	};

private:
	static NResult N_API PluginCallbackImpl(HNPluginManager hPluginManager, HNPlugin hPlugin, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<PluginCallback>(p->pCallback)(FromHandle<N_CLASS(NPluginManager)>(hPluginManager, false, true), FromHandle<N_CLASS(NPlugin)>(hPlugin, false, true), p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	::std::auto_ptr<PluginCollection> plugins;
	::std::auto_ptr<DisabledPluginCollection> disabledPlugins;
	mutable ::std::auto_ptr< ::Neurotec::Threading::N_CLASS(NSyncChangeObject)> pluginsChangeObject;
	mutable ::std::auto_ptr< ::Neurotec::Threading::N_CLASS(NSyncChangeObject)> disabledPluginsChangeObject;

	N_CLASS(NPluginManager)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		plugins.reset(new PluginCollection(this));
		disabledPlugins.reset(new DisabledPluginCollection(this));
		try
		{
			pluginsChangeObject.reset(new ::Neurotec::Threading::N_CLASS(NSyncChangeObject)(plugins->GetLock()));
			NCheck(NPluginManagerAddPluginsChangingCallback(GetHandle(), OnSyncChanging, pluginsChangeObject.get()));
			NCheck(NPluginManagerAddPluginsChangedCallback(GetHandle(), OnSyncChanged, pluginsChangeObject.get()));
			disabledPluginsChangeObject.reset(new ::Neurotec::Threading::N_CLASS(NSyncChangeObject)(disabledPlugins->GetLock()));
			NCheck(NPluginManagerAddDisabledPluginsChangingCallback(GetHandle(), OnSyncChanging, disabledPluginsChangeObject.get()));
			NCheck(NPluginManagerAddDisabledPluginsChangedCallback(GetHandle(), OnSyncChanged, disabledPluginsChangeObject.get()));
		}
		catch (...)
		{
			Uninit();
			throw;
		}
	}

	void Uninit()
	{
		if (!IsDisposed())
		{
			NCheck(NPluginManagerRemovePluginsChangingCallback(GetHandle(), OnSyncChanging, pluginsChangeObject.get()));
			NCheck(NPluginManagerRemovePluginsChangedCallback(GetHandle(), OnSyncChanged, pluginsChangeObject.get()));
			NCheck(NPluginManagerRemoveDisabledPluginsChangingCallback(GetHandle(), OnSyncChanging, disabledPluginsChangeObject.get()));
			NCheck(NPluginManagerRemoveDisabledPluginsChangedCallback(GetHandle(), OnSyncChanged, disabledPluginsChangeObject.get()));
		}
	}

public:
	typedef void (* PluginCallback)(N_CLASS(NPluginManager) * pPluginManager, N_CLASS(NPlugin)* pPlugin, void * pParam);

	static N_CLASS(NPluginManager) * * GetInstances(NInt * pCount)
	{
		return GetObjects<N_CLASS(NPluginManager)>(NPluginManagerGetInstances, pCount, true, true);
	}

	~N_CLASS(NPluginManager)()
	{
		Uninit();
	}

	void EnsurePluginSearchPerformed()
	{
		NCheck(NPluginManagerEnsurePluginSearchPerformed(GetHandle()));
	}

	void Refresh()
	{
		NCheck(NPluginManagerRefresh(GetHandle()));
	}

	void PlugAll()
	{
		NCheck(NPluginManagerPlugAll(GetHandle()));
	}

	void UnplugAll()
	{
		NCheck(NPluginManagerUnplugAll(GetHandle()));
	}

	N_CLASS(NString) GetPluginSearchPath() const
	{
		return GetString(NPluginManagerGetPluginSearchPathN);
	}

	void SetPluginSearchPath(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NPluginManagerSetPluginSearchPathN, value);
	}

	N_CLASS(NString) GetInterfaceType() const
	{
		return GetString(NPluginManagerGetInterfaceTypeN);
	}

	NInt GetInterfaceVersions(N_CLASS(NVersionRange) * arValues, NInt valuesLength) const
	{
		return NCheck(NPluginManagerGetInterfaceVersions(GetHandle(), reinterpret_cast<NVersionRange_ *>(arValues), valuesLength));
	}

	N_CLASS(NVersionRange) * GetInterfaceVersions(NInt * pCount) const
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		auto_array<N_CLASS(NVersionRange)> values(GetInterfaceVersions(NULL, 0));
		*pCount = GetInterfaceVersions(values.get(), values.size());
		return values.release();
	}

	NBool AllowsUnplug() const
	{
		NBool value;
		NCheck(NPluginManagerAllowsUnplug(GetHandle(), &value));
		return value;
	}

	PluginCollection * GetPlugins()
	{
		return plugins.get();
	}

	DisabledPluginCollection * GetDisabledPlugins()
	{
		return disabledPlugins.get();
	}

	void AddPluginsChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerAddPluginsChanging(GetHandle(), callback.GetHandle()));
	}

	void RemovePluginsChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerRemovePluginsChanging(GetHandle(), callback.GetHandle()));
	}

	void AddPluginsChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerAddPluginsChanged(GetHandle(), callback.GetHandle()));
	}

	void RemovePluginsChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerRemovePluginsChanged(GetHandle(), callback.GetHandle()));
	}

	void AddPluginAddedCallback(PluginCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(PluginCallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerAddPluginAdded(GetHandle(), callback.GetHandle()));
	}

	void RemovePluginAddedCallback(PluginCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(PluginCallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerRemovePluginAdded(GetHandle(), callback.GetHandle()));
	}

	void AddDisabledPluginsChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerAddDisabledPluginsChanging(GetHandle(), callback.GetHandle()));
	}

	void RemoveDisabledPluginsChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerRemoveDisabledPluginsChanging(GetHandle(), callback.GetHandle()));
	}

	void AddDisabledPluginsChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerAddDisabledPluginsChanged(GetHandle(), callback.GetHandle()));
	}

	void RemoveDisabledPluginsChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginManagerRemoveDisabledPluginsChanged(GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_PLUGIN_MANAGER_HPP_INCLUDED
