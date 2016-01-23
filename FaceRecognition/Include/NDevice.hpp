#ifndef N_DEVICE_HPP_INCLUDED
#define N_DEVICE_HPP_INCLUDED

#include <NCore.hpp>
#include <NPlugin.hpp>

namespace Neurotec { namespace Devices
{
using Neurotec::Plugins::HNPlugin;
#include <NDevice.h>
}}

namespace Neurotec { namespace Devices
{
class N_CLASS(NDeviceManager);

class N_CLASS(NDevice) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NDevice, NObject)

public:
	class ChildCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDevice)>
	{
		ChildCollection(N_CLASS(NDevice) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NDevice), N_CLASS(NDevice)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNDevice handle, NInt * pValue) const
		{
			return NDeviceGetChildCount(handle, pValue);
		}

		virtual NResult GetNative(HNDevice handle, NInt index, HNDevice * phValue) const
		{
			return NDeviceGetChild(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNDevice, HNDevice *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NDevice);
	};

private:
	::std::auto_ptr<ChildCollection> children;

protected:
	N_CLASS(NDevice)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		children.reset(new ChildCollection(this));
	}

public:
	N_CLASS(NDeviceManager) * GetOwner() const;

	::Neurotec::Plugins::N_CLASS(NPlugin) * GetPlugin() const
	{
		return GetObject<HandleType, ::Neurotec::Plugins::N_CLASS(NPlugin)>(NDeviceGetPlugin, true, true);
	}

	NDeviceType GetDeviceType() const
	{
		NDeviceType type;
		NCheck(NDeviceGetDeviceType(GetHandle(), &type));
		return type;
	}

	NBool IsAvailable() const
	{
		NBool isAvailable;
		NCheck(NDeviceIsAvailable(GetHandle(), &isAvailable));
		return isAvailable;
	}

	NBool IsPrivate() const
	{
		NBool isPrivate;
		NCheck(NDeviceIsPrivate(GetHandle(), &isPrivate));
		return isPrivate;
	}

	NBool IsDisconnectable() const
	{
		NBool isPrivate;
		NCheck(NDeviceIsDisconnectable(GetHandle(), &isPrivate));
		return isPrivate;
	}

	N_CLASS(NDevice) * GetParent() const
	{
		return GetObject<HandleType, N_CLASS(NDevice)>(NDeviceGetParent, true, true);
	}

	N_CLASS(NString) GetId() const
	{
		return GetString(NDeviceGetIdN);
	}

	N_CLASS(NString) GetDisplayName() const
	{
		return GetString(NDeviceGetDisplayNameN);
	}

	N_CLASS(NString) GetMake() const
	{
		return GetString(NDeviceGetMakeN);
	}

	N_CLASS(NString) GetModel() const
	{
		return GetString(NDeviceGetModelN);
	}

	N_CLASS(NString) GetSerialNumber() const
	{
		return GetString(NDeviceGetSerialNumberN);
	}

	ChildCollection * GetChildren() const
	{
		return children.get();
	}
};

}}

#include <NDeviceManager.hpp>

namespace Neurotec { namespace Devices
{

inline N_CLASS(NDeviceManager) * N_CLASS(NDevice)::GetOwner() const
{
	return dynamic_cast<N_CLASS(NDeviceManager) *>(N_CLASS(NObject)::GetOwner());
}

}}

#endif // !N_DEVICE_HPP_INCLUDED
