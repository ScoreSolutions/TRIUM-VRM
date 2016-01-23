#include <NDeviceManager.hpp>

#ifndef N_DEVICES_HPP_INCLUDED
#define N_DEVICES_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Devices
{
#include <NDevices.h>
}}

namespace Neurotec { namespace Devices
{

#include <NNoDeprecate.h>
class N_CLASS(NDevices)
{
private:
	N_CLASS(NDevices)()
	{
	}

public:
	N_DEPRECATED("method is deprecated, use N_NATIVE_MODULE_OF(NDevices) instead")
	static void GetInfo(NLibraryInfo * pValue)
	{
		NCheck(NDevicesGetInfo(pValue));
	}

	N_DECLARE_MODULE_CLASS(NDevices)
};
#include <NReDeprecate.h>

}}

#endif // !N_DEVICES_HPP_INCLUDED
