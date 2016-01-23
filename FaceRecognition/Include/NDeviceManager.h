#ifndef N_DEVICE_MANAGER_H_INCLUDED
#define N_DEVICE_MANAGER_H_INCLUDED

#include <NDevice.h>
#include <NPluginManager.h>
#include <NParameterDescriptor.h>
#include <NPropertyBag.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDeviceManager, NObject)

NResult N_API NDeviceManagerGetPluginManager(HNPluginManager * phValue);

NResult N_API NDeviceManagerIsConnectToDeviceSupported(HNPlugin hPlugin, NBool * pValue);
NResult N_API NDeviceManagerGetConnectToDeviceParameters(HNPlugin hPlugin, HNParameterDescriptor * * parhParameters, NInt * pParameterCount);

NResult N_API NDeviceManagerCreate(NDeviceType deviceTypes, NBool autoPlug, NBool autoUpdate, HNDeviceManager * phDeviceManager);

NResult N_API NDeviceManagerGetDeviceCount(HNDeviceManager hDeviceManager, NInt * pValue);
NResult N_API NDeviceManagerGetDevice(HNDeviceManager hDeviceManager, NInt index, HNDevice * phValue);

NResult N_API NDeviceManagerGetDeviceByIdN(HNDeviceManager hDeviceManager, HNString hId, HNDevice * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NDeviceManagerGetDeviceByIdA(HNDeviceManager hDeviceManager, const NAChar * szId, HNDevice * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDeviceManagerGetDeviceByIdW(HNDeviceManager hDeviceManager, const NWChar * szId, HNDevice * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDeviceManagerGetDeviceById(HNDeviceManager hDeviceManager, const NChar * szId, HNDevice * phValue);
#endif
#define NDeviceManagerGetDeviceById N_FUNC_AW(NDeviceManagerGetDeviceById)

NResult N_API NDeviceManagerRefresh(HNDeviceManager hDeviceManager);
NResult N_API NDeviceManagerConnectToDevice(HNDeviceManager hDeviceManager, HNPlugin hPlugin, HNPropertyBag hParameters, HNDevice * phDevice);

NResult N_API NDeviceManagerConnectToDeviceWithStringN(HNDeviceManager hDeviceManager, HNString hPlugin, HNString hParameters, HNDevice * phDevice);
#ifndef N_NO_ANSI_FUNC
NResult N_API NDeviceManagerConnectToDeviceWithStringA(HNDeviceManager hDeviceManager, const NAChar * szPlugin, const NAChar * szParameters, HNDevice * phDevice);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDeviceManagerConnectToDeviceWithStringW(HNDeviceManager hDeviceManager, const NWChar * szPlugin, const NWChar * szParameters, HNDevice * phDevice);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDeviceManagerConnectToDeviceWithString(HNDeviceManager hDeviceManager, const NChar * szPlugin, const NChar * szParameters, HNDevice * phDevice);
#endif
#define NDeviceManagerConnectToDeviceWithString N_FUNC_AW(NDeviceManagerConnectToDeviceWithString)

NResult N_API NDeviceManagerDisconnectFromDevice(HNDeviceManager hDeviceManager, HNDevice hDevice);

NResult N_API NDeviceManagerGetDeviceTypes(HNDeviceManager hDeviceManager, NDeviceType * pValue);
NResult N_API NDeviceManagerGetAutoUpdate(HNDeviceManager hDeviceManager, NBool * pValue);

typedef NResult (N_CALLBACK NDeviceManagerDeviceCallback)(HNDeviceManager hDeviceManager, HNDevice hDevice, void * pParam);

NResult N_API NDeviceManagerAddDevicesChanging(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerAddDevicesChangingCallback(HNDeviceManager hDeviceManager, NObjectCallback pCallback, void * pParam);
NResult N_API NDeviceManagerRemoveDevicesChanging(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerRemoveDevicesChangingCallback(HNDeviceManager hDeviceManager, NObjectCallback pCallback, void * pParam);
NResult N_API NDeviceManagerAddDevicesChanged(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerAddDevicesChangedCallback(HNDeviceManager hDeviceManager, NObjectCallback pCallback, void * pParam);
NResult N_API NDeviceManagerRemoveDevicesChanged(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerRemoveDevicesChangedCallback(HNDeviceManager hDeviceManager, NObjectCallback pCallback, void * pParam);
NResult N_API NDeviceManagerAddDeviceAdded(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerAddDeviceAddedCallback(HNDeviceManager hDeviceManager, NDeviceManagerDeviceCallback pCallback, void * pParam);
NResult N_API NDeviceManagerRemoveDeviceAdded(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerRemoveDeviceAddedCallback(HNDeviceManager hDeviceManager, NDeviceManagerDeviceCallback pCallback, void * pParam);
NResult N_API NDeviceManagerAddDeviceRemoved(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerAddDeviceRemovedCallback(HNDeviceManager hDeviceManager, NDeviceManagerDeviceCallback pCallback, void * pParam);
NResult N_API NDeviceManagerRemoveDeviceRemoved(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerRemoveDeviceRemovedCallback(HNDeviceManager hDeviceManager, NDeviceManagerDeviceCallback pCallback, void * pParam);
NResult N_API NDeviceManagerAddDevicesRefreshed(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerAddDevicesRefreshedCallback(HNDeviceManager hDeviceManager, NObjectCallback pCallback, void * pParam);
NResult N_API NDeviceManagerRemoveDevicesRefreshed(HNDeviceManager hDeviceManager, HNCallback hCallback);
NResult N_API NDeviceManagerRemoveDevicesRefreshedCallback(HNDeviceManager hDeviceManager, NObjectCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#include <NDevices.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NDeviceManagerGetInfoA NDevicesGetInfoA
#define NDeviceManagerGetInfoW NDevicesGetInfoW
#define NDeviceManagerGetInfo NDevicesGetInfo

#ifdef N_MSVC
	#pragma deprecated("NDeviceManagerGetInfoA", "NDeviceManagerGetInfoW", "NDeviceManagerGetInfo")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_DEVICE_MANAGER_H_INCLUDED
