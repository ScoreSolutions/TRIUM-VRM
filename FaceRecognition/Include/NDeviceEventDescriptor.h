#ifndef N_DEVICE_EVENT_DESCRIPTOR_H_INCLUDED
#define N_DEVICE_EVENT_DESCRIPTOR_H_INCLUDED

#include <NCustomEventDescriptor.h>
#include <NDevice.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDeviceEventDescriptor, NCustomEventDescriptor)

typedef NResult (N_CALLBACK NDeviceEventDescriptorModifyHandlerProc)(HNDeviceEventDescriptor hEventDescriptor, NHandle hDevice, HNCallback hCallback, void * pParam);

NResult N_API NDeviceEventDescriptorCreate(HNString hName, HNType hEventType, NAttributes attributes, HNValue hData, HNCallback hAddHandler, HNCallback hRemoveHandler, HNDeviceEventDescriptor * phEventDescriptor);

#ifdef N_CPP
}
#endif

#endif // !N_DEVICE_EVENT_DESCRIPTOR_H_INCLUDED
