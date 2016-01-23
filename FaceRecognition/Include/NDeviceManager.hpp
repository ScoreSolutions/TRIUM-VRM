#include <NDevice.hpp>

#ifndef N_DEVICE_MANAGER_HPP_INCLUDED
#define N_DEVICE_MANAGER_HPP_INCLUDED

#include <NPluginManager.hpp>
#include <NParameterDescriptor.hpp>
#include <NPropertyBag.hpp>
#include <NCollections.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Plugins::HNPluginManager;
using ::Neurotec::ComponentModel::HNParameterDescriptor;
#include <NDeviceManager.h>
}}

namespace Neurotec { namespace Devices
{

class N_CLASS(NDeviceManager) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NDeviceManager, NObject)

public:
	class N_CLASS(NDeviceCollection) : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDeviceManager)>
	{
	private:
		N_CLASS(NDeviceCollection)(N_CLASS(NDeviceManager) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDeviceManager)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNDeviceManager handle, NInt * pValue) const
		{
			return NDeviceManagerGetDeviceCount(handle, pValue);
		}

		virtual NResult GetNative(HNDeviceManager handle, NInt index, HNDevice * phValue) const
		{
			return NDeviceManagerGetDevice(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNDeviceManager, HNDevice *, NInt) const
		{
			NThrowNotImplementedException();
		}

	public:
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDeviceManager)>::IndexOf;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDeviceManager)>::Contains;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDeviceManager)>::Get;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDeviceManager)>::operator[];

		NInt IndexOf(const N_CLASS(NStringWrapper) & id) const
		{
			HNDevice hDevice;
			NCheck(NDeviceManagerGetDeviceByIdN(pOwner->GetHandle(), id.GetHandle(), &hDevice));
			try
			{
				NInt index = IndexOf(hDevice);
				Unref(hDevice); hDevice = NULL;
				return index;
			}
			catch (...)
			{
				Unref(hDevice);
				throw;
			}
		}

		bool Contains(const N_CLASS(NStringWrapper) & id) const
		{
			return IndexOf(id) != -1;
		}

		N_CLASS(NDevice) * Get(const N_CLASS(NStringWrapper) & id) const
		{
			HNDevice hDevice;
			NCheck(NDeviceManagerGetDeviceByIdN(pOwner->GetHandle(), id.GetHandle(), &hDevice));
			try
			{
				return FromHandle<N_CLASS(NDevice)>(hDevice, true, true);
			}
			catch (...)
			{
				Unref(hDevice);
				throw;
			}
		}

		N_CLASS(NDevice) * operator[](const N_CLASS(NStringWrapper) & id) const
		{
			return Get(id);
		}

		friend class N_CLASS(NDeviceManager);
	};

private:
	static HNDeviceManager Create(NDeviceType deviceTypes, bool autoPlug, bool autoUpdate)
	{
		HNDeviceManager handle;
		NCheck(NDeviceManagerCreate(deviceTypes, autoPlug ? NTrue : NFalse, autoUpdate ? NTrue : NFalse, &handle));
		return handle;
	}

	static NResult N_API DeviceCallbackImpl(HNDeviceManager hDeviceManager, HNDevice hDevice, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<DeviceCallback>(p->pCallback)(FromHandle<N_CLASS(NDeviceManager)>(hDeviceManager, false, true), FromHandle<N_CLASS(NDevice)>(hDevice, false, true), p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	::std::auto_ptr<N_CLASS(NDeviceCollection)> devices;
	mutable ::std::auto_ptr< ::Neurotec::Threading::N_CLASS(NSyncChangeObject)> devicesChangeObject;

	N_CLASS(NDeviceManager)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		devices.reset(new N_CLASS(NDeviceCollection)(this));
		try
		{
			devicesChangeObject.reset(new ::Neurotec::Threading::N_CLASS(NSyncChangeObject)(devices->GetLock()));
			NCheck(NDeviceManagerAddDevicesChangingCallback(GetHandle(), OnSyncChanging, devicesChangeObject.get()));
			NCheck(NDeviceManagerAddDevicesChangedCallback(GetHandle(), OnSyncChanged, devicesChangeObject.get()));
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
			NCheck(NDeviceManagerRemoveDevicesChangingCallback(GetHandle(), OnSyncChanging, devicesChangeObject.get()));
			NCheck(NDeviceManagerRemoveDevicesChangedCallback(GetHandle(), OnSyncChanged, devicesChangeObject.get()));
		}
	}

public:
	typedef void (* DeviceCallback)(N_CLASS(NDeviceManager) * pDeviceManager, N_CLASS(NDevice)* pDevice, void * pParam);

	static ::Neurotec::Plugins::N_CLASS(NPluginManager) * GetPluginManager()
	{
		return GetObject< ::Neurotec::Plugins::N_CLASS(NPluginManager)>(NDeviceManagerGetPluginManager, true, true);
	}

	static bool IsConnectToDeviceSupported(::Neurotec::Plugins::N_CLASS(NPlugin) * pPlugin)
	{
		if (!pPlugin) NThrowArgumentNullException(N_T("pPlugin"));
		NBool value;
		NCheck(NDeviceManagerIsConnectToDeviceSupported(pPlugin->GetHandle(), &value));
		return value != 0;
	}

	static ::Neurotec::ComponentModel::N_CLASS(NParameterDescriptor) * * GetConnectToDeviceParameters(::Neurotec::Plugins::N_CLASS(NPlugin) * pPlugin, NInt * pCount)
	{
		if (!pPlugin) NThrowArgumentNullException(N_T("pPlugin"));
		HNParameterDescriptor * arhParameters;
		NInt parameterCount;
		NCheck(NDeviceManagerGetConnectToDeviceParameters(pPlugin->GetHandle(), &arhParameters, &parameterCount));
		try
		{
			N_CLASS(NObjectArray)< ::Neurotec::ComponentModel::N_CLASS(NParameterDescriptor)> p(arhParameters, parameterCount);
			arhParameters = NULL; parameterCount = 0;
			return p.ToArray(pCount);
		}
		catch (...)
		{
			UnrefArray(arhParameters, parameterCount);
			throw;
		}
	}

	explicit N_CLASS(NDeviceManager)(NDeviceType deviceTypes = ndtAny, bool autoPlug = true, bool autoUpdate = true)
		: N_CLASS(NObject)(Create(deviceTypes, autoPlug, autoUpdate), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NDeviceManager);
		Init();
	}

	~N_CLASS(NDeviceManager)()
	{
		Uninit();
	}

	void Refresh()
	{
		NCheck(NDeviceManagerRefresh(GetHandle()));
	}

	N_CLASS(NDevice) * ConnectToDevice(::Neurotec::Plugins::N_CLASS(NPlugin) * pPlugin, N_CLASS(NPropertyBag) * pParameters)
	{
		if (!pPlugin) NThrowArgumentNullException(N_T("pPlugin"));
		if (!pParameters) NThrowArgumentNullException(N_T("pParameters"));
		HNDevice hDevice;
		NCheck(NDeviceManagerConnectToDevice(GetHandle(), pPlugin->GetHandle(), pParameters->GetHandle(), &hDevice));
		try
		{
			return FromHandle<N_CLASS(NDevice)>(hDevice, true, true);
		}
		catch (...)
		{
			Unref(hDevice);
			throw;
		}
	}

	N_CLASS(NDevice) * ConnectToDevice(const N_CLASS(NStringWrapper) plugin, const N_CLASS(NStringWrapper) parameters)
	{
		HNDevice hDevice;
		NCheck(NDeviceManagerConnectToDeviceWithStringN(GetHandle(), plugin.GetHandle(), parameters.GetHandle(), &hDevice));
		try
		{
			return FromHandle<N_CLASS(NDevice)>(hDevice, true, true);
		}
		catch (...)
		{
			Unref(hDevice);
			throw;
		}
	}

	void DisconnectFromDevice(N_CLASS(NDevice) * pDevice)
	{
		if (!pDevice) NThrowArgumentNullException(N_T("pDevice"));
		NCheck(NDeviceManagerDisconnectFromDevice(GetHandle(), pDevice->GetHandle()));
	}

	NDeviceType GetDeviceTypes()
	{
		NDeviceType types;
		NCheck(NDeviceManagerGetDeviceTypes(GetHandle(), &types));
		return types;
	}

	bool GetAutoUpdate()
	{
		NBool autoUpdate;
		NCheck(NDeviceManagerGetAutoUpdate(GetHandle(), &autoUpdate));
		return autoUpdate != 0;
	}

	N_CLASS(NDeviceCollection) * GetDevices() const
	{
		return devices.get();
	}

	void AddDevicesChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerAddDevicesChanging(GetHandle(), callback.GetHandle()));
	}

	void RemoveDevicesChangingCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerRemoveDevicesChanging(GetHandle(), callback.GetHandle()));
	}

	void AddDevicesChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerAddDevicesChanged(GetHandle(), callback.GetHandle()));
	}

	void RemoveDevicesChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerRemoveDevicesChanged(GetHandle(), callback.GetHandle()));
	}

	void AddDeviceAddedCallback(DeviceCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(DeviceCallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerAddDeviceAdded(GetHandle(), callback.GetHandle()));
	}

	void RemoveDeviceAddedCallback(DeviceCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(DeviceCallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerRemoveDeviceAdded(GetHandle(), callback.GetHandle()));
	}

	void AddDeviceRemovedCallback(DeviceCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(DeviceCallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerAddDeviceRemoved(GetHandle(), callback.GetHandle()));
	}

	void RemoveDeviceRemovedCallback(DeviceCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(DeviceCallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerRemoveDeviceRemoved(GetHandle(), callback.GetHandle()));
	}

	void AddDevicesRefreshedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerAddDevicesRefreshed(GetHandle(), callback.GetHandle()));
	}

	void RemoveDevicesRefreshedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NDeviceManagerRemoveDevicesRefreshed(GetHandle(), callback.GetHandle()));
	}
};

}}

#include <NDevices.hpp>

namespace Neurotec { namespace DeviceManager
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Devices::" N_STRINGIZEA(N_CLASS(NDevices)) " instead")
	N_CLASS(NDeviceManager)
{
private:
	N_CLASS(NDeviceManager)()
	{
	}

public:
	static void GetInfo(NLibraryInfo * pValue)
	{
		::Neurotec::Devices::N_CLASS(NDevices)::GetInfo(pValue);
	}
};
#include <NReDeprecate.h>

}}

#endif // !N_DEVICE_MANAGER_HPP_INCLUDED
