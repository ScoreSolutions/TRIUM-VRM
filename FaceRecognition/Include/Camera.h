#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <NImage.h>
#include <CameraParams.h>
#include <NCamera.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(Camera, NObject)

NResult N_API CameraGetDevice(HCamera hCamera, HNCamera * phDevice);

N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraGetIdN(HCamera hCamera, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraGetIdA(HCamera hCamera, NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraGetIdW(HCamera hCamera, NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraGetId(HCamera hCamera, NChar * szValue);
#endif
#define CameraGetId N_FUNC_AW(CameraGetId)

typedef struct CameraVideoFormat_
{
	NInt FrameWidth;
	NInt FrameHeight;
	NFloat FrameRate;
} CameraVideoFormat;

N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraGetVideoFormats(HCamera hCamera, CameraVideoFormat * arVideoFormats);
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraGetVideoFormat(HCamera hCamera, CameraVideoFormat * pVideoFormat);
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraSetVideoFormat(HCamera hCamera, const CameraVideoFormat * pVideoFormat);

N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraIsCapturing(HCamera hCamera, NBool * pValue);
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraStartCapturing(HCamera hCamera);
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraStopCapturing(HCamera hCamera);
N_DEPRECATED("function is deprecated, use NCamera API instead")
NResult N_API CameraGetCurrentFrame(HCamera hCamera, HNImage * pHImage);

#define CameraCopyParameters(hDstCamera, hSrcCamera) NObjectCopyParameters(hDstCamera, hSrcCamera)
#define CameraGetParameterA(hCamera, parameterId, pValue) NObjectGetParameterA(hCamera, parameterId, pValue)
#define CameraGetParameterW(hCamera, parameterId, pValue) NObjectGetParameterW(hCamera, parameterId, pValue)
#define CameraGetParameter(hCamera, parameterId, pValue) NObjectGetParameter(hCamera, parameterId, pValue)
#define CameraSetParameterA(hCamera, parameterId, pValue) NObjectSetParameterA(hCamera, parameterId, pValue)
#define CameraSetParameterW(hCamera, parameterId, pValue) NObjectSetParameterW(hCamera, parameterId, pValue)
#define CameraSetParameter(hCamera, parameterId, pValue) NObjectSetParameter(hCamera, parameterId, pValue)

#ifdef N_MSVC
	#pragma deprecated("CameraCopyParameters", "CameraGetParameterA", "CameraGetParameterW", "CameraGetParameter", "CameraSetParameterA", "CameraSetParameterW", "CameraSetParameter")
#endif

#ifdef N_CPP
}
#endif

#endif // !CAMERA_H_INCLUDED
