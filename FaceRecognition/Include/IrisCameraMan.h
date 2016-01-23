#ifndef IRIS_CAMERA_MAN_H_INCLUDED
#define IRIS_CAMERA_MAN_H_INCLUDED

#include <IrisCamera.h>
#include <NDeviceManager.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(IrisCameraMan)

N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraManInitialize(void);
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
void N_API IrisCameraManUninitialize(void);

NResult N_API IrisCameraManGetDeviceManager(HNDeviceManager * phDeviceManager);
NResult N_API IrisCameraManGetCameraFromDevice(HNIrisScanner hDevice, HIrisCamera * phIrisCamera);

N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraManGetCameraCount(NInt *pValue);
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraManGetCamera(NInt index, HIrisCamera *phIrisCamera);

N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraManGetCameraByIdN(HNString hId, HIrisCamera *phIrisCamera);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraManGetCameraByIdA(const NAChar *szId, HIrisCamera *phIrisCamera);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraManGetCameraByIdW(const NWChar *szId, HIrisCamera *phIrisCamera);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraManGetCameraById(const NChar *szId, HIrisCamera *phIrisCamera);
#endif
#define IrisCameraManGetCameraById N_FUNC_AW(IrisCameraManGetCameraById)

#ifdef N_CPP
}
#endif

#endif // !IRIS_CAMERA_MAN_H_INCLUDED
