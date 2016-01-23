#ifndef IHEAD_H_INCLUDED
#define IHEAD_H_INCLUDED

#include "NImage.h"

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(IHeadInfo, NImageInfo)

N_DEPRECATED("function is deprecated, use NImageCreateFromFileN and NImageFormatGetIHead instead")
NResult N_API IHeadLoadImageFromFileN(HNString hFileName, HNImage * phImage);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileA and NImageFormatGetIHead instead")
NResult N_API IHeadLoadImageFromFileA(const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileW and NImageFormatGetIHead instead")
NResult N_API IHeadLoadImageFromFileW(const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API IHeadLoadImageFromFile(const NChar * szFileName, HNImage * phImage);
#endif
#define IHeadLoadImageFromFile N_FUNC_AW(IHeadLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN and NImageFormatGetIHead instead")
NResult N_API IHeadLoadImageFromMemoryN(HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory and NImageFormatGetIHead instead")
NResult N_API IHeadLoadImageFromMemory(const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream and NImageFormatGetIHead instead")
NResult N_API IHeadLoadImageFromStream(HNStream hStream, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageSaveToFileN, NImageFormatGetIHead and NImageFormatCreateInfo instead")
NResult N_API IHeadSaveImageToFileN(HNImage hImage, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetIHead and NImageFormatCreateInfo instead")
NResult N_API IHeadSaveImageToFileA(HNImage hImage, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetIHead and NImageFormatCreateInfo instead")
NResult N_API IHeadSaveImageToFileW(HNImage hImage, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API IHeadSaveImageToFile(HNImage hImage, const NChar * szFileName);
#endif
#define IHeadSaveImageToFile N_FUNC_AW(IHeadSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetIHead and NImageFormatCreateInfo instead")
NResult N_API IHeadSaveImageToMemoryN(HNImage hImage, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetIHead and NImageFormatCreateInfo instead")
NResult N_API IHeadSaveImageToMemory(HNImage hImage, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetIHead and NImageFormatCreateInfo instead")
NResult N_API IHeadSaveImageToStream(HNImage hImage, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !IHEAD_H_INCLUDED
