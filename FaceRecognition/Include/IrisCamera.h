#ifndef IRIS_CAMERA_H_INCLUDED
#define IRIS_CAMERA_H_INCLUDED

#include <NGrayscaleImage.h>
#include <IrisCameraParams.h>
#include <NIrisScanner.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(IrisCamera, NObject)

typedef void (N_CALLBACK IrisCameraIrisesAcquiredCallback)(HIrisCamera hIrisCamera, HNGrayscaleImage hLeftIris, HNGrayscaleImage hRightIris, void * pParam);

NResult N_API IrisCameraGetDevice(HIrisCamera hIrisCamera, HNIrisScanner * phDevice);

N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraGetIdN(HIrisCamera hIrisCamera, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraGetIdA(HIrisCamera hIrisCamera, NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraGetIdW(HIrisCamera hIrisCamera, NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraGetId(HIrisCamera hIrisCamera, NChar * szValue);
#endif
#define IrisCameraGetId N_FUNC_AW(IrisCameraGetId)

N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraIsCapturing(HIrisCamera hIrisCamera, NBool * pValue);
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraStartCapturing(HIrisCamera hIrisCamera);
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraStopCapturing(HIrisCamera hIrisCamera);
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraGetImages(HIrisCamera hIrisCamera, HNGrayscaleImage * phLeftIris, HNGrayscaleImage * phRightIris);
N_DEPRECATED("function is deprecated, use NIrisScanner API instead")
NResult N_API IrisCameraSetIrisesAcquiredCallback(HIrisCamera hIrisCamera, IrisCameraIrisesAcquiredCallback pCallback, void * pParam);

typedef IrisCameraIrisesAcquiredCallback IrisCameraCallback;
#define IrisCameraCopyParameters(hDstIrisCamera, hSrcIrisCamera) NObjectCopyParameters(hDstIrisCamera, hSrcIrisCamera)
#define IrisCameraGetParameterA(hIrisCamera, parameterId, pValue) NObjectGetParameterA(hIrisCamera, parameterId, pValue)
#define IrisCameraGetParameterW(hIrisCamera, parameterId, pValue) NObjectGetParameterW(hIrisCamera, parameterId, pValue)
#define IrisCameraGetParameter(hIrisCamera, parameterId, pValue) NObjectGetParameter(hIrisCamera, parameterId, pValue)
#define IrisCameraSetParameterA(hIrisCamera, parameterId, pValue) NObjectSetParameterA(hIrisCamera, parameterId, pValue)
#define IrisCameraSetParameterW(hIrisCamera, parameterId, pValue) NObjectSetParameterW(hIrisCamera, parameterId, pValue)
#define IrisCameraSetParameter(hIrisCamera, parameterId, pValue) NObjectSetParameter(hIrisCamera, parameterId, pValue)

#ifdef N_MSVC
	#pragma deprecated("IrisCameraSetCallback", "IrisCameraCopyParameters", "IrisCameraGetParameterA", "IrisCameraGetParameterW", "IrisCameraGetParameter", "IrisCameraSetParameterA", "IrisCameraSetParameterW", "IrisCameraSetParameter")
#endif

#ifdef N_CPP
}
#endif

#endif // !IRIS_CAMERA_H_INCLUDED
