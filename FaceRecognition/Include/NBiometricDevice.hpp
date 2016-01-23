#ifndef N_BIOMETRIC_DEVICE_HPP_INCLUDED
#define N_BIOMETRIC_DEVICE_HPP_INCLUDED

#include <NDevice.hpp>
#include <NBiometricTypes.hpp>
namespace Neurotec { namespace Devices
{
using Neurotec::Biometrics::NBiometricType;
using Neurotec::Biometrics::NBiometricStatus;
#include <NBiometricDevice.h>
}}

namespace Neurotec { namespace Devices
{

class N_CLASS(NBiometricDevice) : public N_CLASS(NDevice)
{
	N_DECLARE_OBJECT_CLASS(NBiometricDevice, NDevice)

protected:
	N_CLASS(NBiometricDevice)(HNObject handle, bool claimHandle)
		: N_CLASS(NDevice)(handle, claimHandle)
	{
	}

public:
	void Cancel()
	{
		NCheck(NBiometricDeviceCancel(GetHandle()));
	}

	NBiometricType GetBiometricType() const
	{
		NBiometricType type;
		NCheck(NBiometricDeviceGetBiometricType(GetHandle(), &type));
		return type;
	}

	NUShort GetVendorId() const
	{
		NUShort value;
		NCheck(NBiometricDeviceGetVendorId(GetHandle(), &value));
		return value;
	}

	NUShort GetProductId() const
	{
		NUShort value;
		NCheck(NBiometricDeviceGetProductId(GetHandle(), &value));
		return value;
	}

	bool IsSpoofDetectionSupported() const
	{
		NBool value;
		NCheck(NBiometricDeviceIsSpoofDetectionSupported(GetHandle(), &value));
		return value != 0;
	}

	bool GetSpoofDetection() const
	{
		NBool value;
		NCheck(NBiometricDeviceGetSpoofDetection(GetHandle(), &value));
		return value != 0;
	}

	void SetSpoofDetection(bool value)
	{
		NCheck(NBiometricDeviceSetSpoofDetection(GetHandle(), value ? NTrue : NFalse));
	}
};

}}

#endif // !N_BIOMETRIC_DEVICE_HPP_INCLUDED
