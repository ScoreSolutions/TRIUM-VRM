#ifndef JPEG_H_INCLUDED
#define JPEG_H_INCLUDED

#include "NImage.h"

#ifdef N_CPP
extern "C"
{
#endif

#define JPEG_DEFAULT_QUALITY 75

N_DECLARE_OBJECT_TYPE(JpegInfo, NImageInfo)

NResult N_API JpegInfoGetQuality(HJpegInfo hInfo, NInt * pValue);
NResult N_API JpegInfoSetQuality(HJpegInfo hInfo, NInt value);
NResult N_API JpegInfoIsLossless(HJpegInfo hInfo, NBool * pValue);
NResult N_API JpegInfoSetLossless(HJpegInfo hInfo, NBool value);

N_DEPRECATED("function is deprecated, use NImageCreateFromFileN and NImageFormatGetJpeg instead")
NResult N_API JpegLoadImageFromFileN(HNString hFileName, HNImage * phImage);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileA and NImageFormatGetJpeg instead")
NResult N_API JpegLoadImageFromFileA(const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileW and NImageFormatGetJpeg instead")
NResult N_API JpegLoadImageFromFileW(const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API JpegLoadImageFromFile(const NChar * szFileName, HNImage * phImage);
#endif
#define JpegLoadImageFromFile N_FUNC_AW(JpegLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN and NImageFormatGetJpeg instead")
NResult N_API JpegLoadImageFromMemoryN(HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory and NImageFormatGetJpeg instead")
NResult N_API JpegLoadImageFromMemory(const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream and NImageFormatGetJpeg instead")
NResult N_API JpegLoadImageFromStream(HNStream hStream, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageSaveToFileN, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetQuality instead")
NResult N_API JpegSaveImageToFileN(HNImage hImage, NInt quality, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetQuality instead")
NResult N_API JpegSaveImageToFileA(HNImage hImage, NInt quality, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetQuality instead")
NResult N_API JpegSaveImageToFileW(HNImage hImage, NInt quality, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API JpegSaveImageToFile(HNImage hImage, NInt quality, const NChar * szFileName);
#endif
#define JpegSaveImageToFile N_FUNC_AW(JpegSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetQuality instead")
NResult N_API JpegSaveImageToMemoryN(HNImage hImage, NInt quality, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetQuality instead")
NResult N_API JpegSaveImageToMemory(HNImage hImage, NInt quality, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetQuality instead")
NResult N_API JpegSaveImageToStream(HNImage hImage, NInt quality, HNStream hStream);

N_DEPRECATED("function is deprecated, use NImageSaveToFileN, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetLossless instead")
NResult N_API LosslessJpegSaveImageToFileN(HNImage hImage, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetLossless instead")
NResult N_API LosslessJpegSaveImageToFileA(HNImage hImage, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetLossless instead")
NResult N_API LosslessJpegSaveImageToFileW(HNImage hImage, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API LosslessJpegSaveImageToFile(HNImage hImage, const NChar * szFileName);
#endif
#define LosslessJpegSaveImageToFile N_FUNC_AW(LosslessJpegSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetLossless instead")
NResult N_API LosslessJpegSaveImageToMemoryN(HNImage hImage, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetLossless instead")
NResult N_API LosslessJpegSaveImageToMemory(HNImage hImage, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetJpeg, NImageFormatCreateInfo and JpegInfoSetLossless instead")
NResult N_API LosslessJpegSaveImageToStream(HNImage hImage, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !JPEG_H_INCLUDED
