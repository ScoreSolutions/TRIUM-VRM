#ifndef JPEG_2K_H_INCLUDED
#define JPEG_2K_H_INCLUDED

#include "NImage.h"

#ifdef N_CPP
extern "C"
{
#endif

typedef enum Jpeg2KProfile_
{
	jpeg2kpNone = 0,
	jpeg2kpFingerprint1000Ppi = 1000,
	jpeg2kpFaceLossy = 2000,
	jpeg2kpFaceLossless = 2001,
} Jpeg2KProfile;

N_DECLARE_TYPE(Jpeg2KProfile)

#define JPEG_2K_DEFAULT_RATIO 10.0f

N_DECLARE_OBJECT_TYPE(Jpeg2KInfo, NImageInfo)

NResult N_API Jpeg2KInfoGetProfile(HJpeg2KInfo hInfo, Jpeg2KProfile * pValue);
NResult N_API Jpeg2KInfoSetProfile(HJpeg2KInfo hInfo, Jpeg2KProfile value);
NResult N_API Jpeg2KInfoGetRatio(HJpeg2KInfo hInfo, NFloat * pValue);
NResult N_API Jpeg2KInfoSetRatio(HJpeg2KInfo hInfo, NFloat value);

N_DEPRECATED("function is deprecated, use NImageCreateFromFileN and NImageFormatGetJpeg2K instead")
NResult N_API Jpeg2KLoadImageFromFileN(HNString hFileName, HNImage * phImage);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileA and NImageFormatGetJpeg2K instead")
NResult N_API Jpeg2KLoadImageFromFileA(const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileW and NImageFormatGetJpeg2K instead")
NResult N_API Jpeg2KLoadImageFromFileW(const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API Jpeg2KLoadImageFromFile(const NChar * szFileName, HNImage * phImage);
#endif
#define Jpeg2KLoadImageFromFile N_FUNC_AW(Jpeg2KLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN and NImageFormatGetJpeg2K instead")
NResult N_API Jpeg2KLoadImageFromMemoryN(HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory and NImageFormatGetJpeg2K instead")
NResult N_API Jpeg2KLoadImageFromMemory(const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream and NImageFormatGetJpeg2K instead")
NResult N_API Jpeg2KLoadImageFromStream(HNStream hStream, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageSaveToFileN, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetRatio instead")
NResult N_API Jpeg2KSaveImageToFileN(HNImage hImage, NFloat ratio, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetRatio instead")
NResult N_API Jpeg2KSaveImageToFileA(HNImage hImage, NFloat ratio, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetRatio instead")
NResult N_API Jpeg2KSaveImageToFileW(HNImage hImage, NFloat ratio, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API Jpeg2KSaveImageToFile(HNImage hImage, NFloat ratio, const NChar * szFileName);
#endif
#define Jpeg2KSaveImageToFile N_FUNC_AW(Jpeg2KSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetRatio instead")
NResult N_API Jpeg2KSaveImageToMemoryN(HNImage hImage, NFloat ratio, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetRatio instead")
NResult N_API Jpeg2KSaveImageToMemory(HNImage hImage, NFloat ratio, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetRatio instead")
NResult N_API Jpeg2KSaveImageToStream(HNImage hImage, NFloat ratio, HNStream hStream);

NResult N_API Jpeg2KSaveImageToFileWithProfileN(HNImage hImage, Jpeg2KProfile profile, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetProfile instead")
NResult N_API Jpeg2KSaveImageToFileWithProfileA(HNImage hImage, Jpeg2KProfile profile, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetProfile instead")
NResult N_API Jpeg2KSaveImageToFileWithProfileW(HNImage hImage, Jpeg2KProfile profile, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API Jpeg2KSaveImageToFileWithProfile(HNImage hImage, Jpeg2KProfile profile, const NChar * szFileName);
#endif
#define Jpeg2KSaveImageToFileWithProfile N_FUNC_AW(Jpeg2KSaveImageToFileWithProfile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetProfile instead")
NResult N_API Jpeg2KSaveImageToMemoryWithProfileN(HNImage hImage, Jpeg2KProfile profile, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetProfile instead")
NResult N_API Jpeg2KSaveImageToMemoryWithProfile(HNImage hImage, Jpeg2KProfile profile, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetJpeg2K, NImageFormatCreateInfo and Jpeg2KInfoSetProfile instead")
NResult N_API Jpeg2KSaveImageToStreamWithProfile(HNImage hImage, Jpeg2KProfile profile, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !JPEG_2K_H_INCLUDED
