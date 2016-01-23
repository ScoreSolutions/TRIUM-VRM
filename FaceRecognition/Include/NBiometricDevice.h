#ifndef N_BIOMETRIC_DEVICE_H_INCLUDED
#define N_BIOMETRIC_DEVICE_H_INCLUDED

#include <NDevice.h>
#include <NBiometricTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBiometricDevice, NDevice)

NResult N_API NBiometricDeviceCancel(HNBiometricDevice hDevice);
NResult N_API NBiometricDeviceStartSequence(HNBiometricDevice hDevice);
NResult N_API NBiometricDeviceEndSequence(HNBiometricDevice hDevice);

NResult N_API NBiometricDeviceGetBiometricType(HNBiometricDevice hDevice, NBiometricType * pValue);
NResult N_API NBiometricDeviceGetVendorId(HNBiometricDevice hDevice, NUShort * pValue);
NResult N_API NBiometricDeviceGetProductId(HNBiometricDevice hDevice, NUShort * pValue);
NResult N_API NBiometricDeviceIsSpoofDetectionSupported(HNBiometricDevice hDevice, NBool * pValue);
NResult N_API NBiometricDeviceGetSpoofDetection(HNBiometricDevice hDevice, NBool * pValue);
NResult N_API NBiometricDeviceSetSpoofDetection(HNBiometricDevice hDevice, NBool value);

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_DEVICE_H_INCLUDED
