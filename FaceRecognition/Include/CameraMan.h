#ifndef CAMERA_MAN_H_INCLUDED
#define CAMERA_MAN_H_INCLUDED

#include <Camera.h>
#include <NDeviceManager.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(CameraMan)

N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraManInitialize(void);
N_DEPRECATED("function is deprecated, use NCamera API instead")
void N_API CameraManUninitialize(void);

NResult N_API CameraManGetDeviceManager(HNDeviceManager * phDeviceManager);
NResult N_API CameraManGetCameraFromDevice(HNCamera hDevice, HCamera * phCamera);

N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraManGetCameraCount(NInt * pValue);
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraManGetCamera(NInt index, HCamera * phCamera);

N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraManGetCameraByIdN(HNString hId, HCamera * phCamera);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraManGetCameraByIdA(const NAChar * szId, HCamera * phCamera);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraManGetCameraByIdW(const NWChar * szId, HCamera * phCamera);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraManGetCameraById(const NChar * szId, HCamera * phCamera);
#endif
#define CameraManGetCameraById N_FUNC_AW(CameraManGetCameraById)

#ifdef N_CPP
}
#endif

#endif // !CAMERA_MAN_H_INCLUDED
