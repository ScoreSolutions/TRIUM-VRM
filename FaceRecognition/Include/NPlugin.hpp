#ifndef N_PLUGIN_HPP_INCLUDED
#define N_PLUGIN_HPP_INCLUDED

#include <NCore.hpp>
#include <NPluginModule.hpp>
namespace Neurotec { namespace Plugins
{
#include <NPlugin.h>
}}

namespace Neurotec { namespace Plugins
{
class N_CLASS(NPluginManager);

class N_CLASS(NPlugin) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NPlugin, NObject)

private:
	mutable ::Neurotec::Threading::NMonitorType lock;
	mutable ::std::auto_ptr< ::Neurotec::Threading::N_CLASS(NSyncChangeObject)> changeObject;

	N_CLASS(NPlugin)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle), lock(N_MONITOR_ARGS)
	{
		try
		{
			changeObject.reset(new ::Neurotec::Threading::N_CLASS(NSyncChangeObject)(lock));
			NCheck(NPluginAddChangingCallback(GetHandle(), OnSyncChanging, changeObject.get()));
			NCheck(NPluginAddChangedCallback(GetHandle(), OnSyncChanged, changeObject.get()));
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
			NCheck(NPluginRemoveChangingCallback(GetHandle(), OnSyncChanging, changeObject.get()));
			NCheck(NPluginRemoveChangedCallback(GetHandle(), OnSyncChanged, changeObject.get()));
		}
	}

public:
	static N_CLASS(NType) * NPluginStateNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NPluginState), true, true);
	}

	~N_CLASS(NPlugin)()
	{
		Uninit();
	}

	void Plug()
	{
		NCheck(NPluginPlug(GetHandle()));
	}

	void Unplug()
	{
		NCheck(NPluginUnplug(GetHandle()));
	}

	void Enable()
	{
		NCheck(NPluginEnable(GetHandle()));
	}

	void Disable()
	{
		NCheck(NPluginDisable(GetHandle()));
	}

	N_CLASS(NPluginManager) * GetOwner() const;

	::Neurotec::Threading::NMonitorType & GetLock() const
	{
		return lock;
	}

	N_CLASS(NString) GetFileName() const
	{
		return GetString(NPluginGetFileNameN);
	}

	NPluginState GetState() const
	{
		NPluginState state;
		NCheck(NPluginGetState(GetHandle(), &state));
		return state;
	}

	N_CLASS(NException) * GetError() const
	{
		NResult errorCode;
		NCheck(NPluginGetErrorCode(GetHandle(), &errorCode));
		HNError hError;
		NCheck(NPluginGetError(GetHandle(), &hError));
		try
		{
			N_CLASS(NException) * pError = N_CLASS(NException)::Get(errorCode, hError);
			Unref(hError); hError = NULL;
			return pError;
		}
		catch (...)
		{
			Unref(hError);
			throw;
		}
	}

	N_CLASS(NTimeSpan) GetLoadTime() const
	{
		NTimeSpan_ loadTime;
		NCheck(NPluginGetLoadTime(GetHandle(), &loadTime));
		return N_CLASS(NTimeSpan)(loadTime);
	}

	N_CLASS(NPluginModule) * GetModule() const
	{
		return GetObject<HandleType, N_CLASS(NPluginModule)>(NPluginGetModule, true, true);
	}

	N_CLASS(NVersion) GetSelectedInterfaceVersion() const
	{
		NVersion_ version;
		NCheck(NPluginGetSelectedInterfaceVersion(GetHandle(), &version));
		return N_CLASS(NVersion)(version);
	}

	N_CLASS(NTimeSpan) GetPlugTime() const
	{
		NTimeSpan_ plugTime;
		NCheck(NPluginGetPlugTime(GetHandle(), &plugTime));
		return N_CLASS(NTimeSpan)(plugTime);
	}

	void AddChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginAddChanging(GetHandle(), callback.GetHandle()));
	}

	void RemoveChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginRemoveChanging(GetHandle(), callback.GetHandle()));
	}

	void AddChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginAddChanged(GetHandle(), callback.GetHandle()));
	}

	void RemoveChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPluginRemoveChanged(GetHandle(), callback.GetHandle()));
	}
};

}}

#include <NPluginManager.hpp>

namespace Neurotec { namespace Plugins
{
inline N_CLASS(NPluginManager) * N_CLASS(NPlugin)::GetOwner() const
{
	return dynamic_cast<N_CLASS(NPluginManager) *>(N_CLASS(NObject)::GetOwner());
}
}}

#endif // !N_PLUGIN_HPP_INCLUDED
