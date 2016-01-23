#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include <NImage.h>

#include <NImageDefWinTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(BmpInfo, NImageInfo)

N_DEPRECATED("function is deprecated, use NImageCreateFromFileN and NImageFormatGetBmp instead")
NResult N_API BmpLoadImageFromFileN(HNString hFileName, HNImage * phImage);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileA and NImageFormatGetBmp instead")
NResult N_API BmpLoadImageFromFileA(const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileW and NImageFormatGetBmp instead")
NResult N_API BmpLoadImageFromFileW(const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API BmpLoadImageFromFile(const NChar * szFileName, HNImage * phImage);
#endif
#define BmpLoadImageFromFile N_FUNC_AW(BmpLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN and NImageFormatGetBmp instead")
NResult N_API BmpLoadImageFromMemoryN(HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory and NImageFormatGetBmp instead")
NResult N_API BmpLoadImageFromMemory(const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream and NImageFormatGetBmp instead")
NResult N_API BmpLoadImageFromStream(HNStream hStream, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageSaveToFileN, NImageFormatGetBmp and NImageFormatCreateInfo instead")
NResult N_API BmpSaveImageToFileN(HNImage hImage, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetBmp and NImageFormatCreateInfo instead")
NResult N_API BmpSaveImageToFileA(HNImage hImage, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetBmp and NImageFormatCreateInfo instead")
NResult N_API BmpSaveImageToFileW(HNImage hImage, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API BmpSaveImageToFile(HNImage hImage, const NChar * szFileName);
#endif
#define BmpSaveImageToFile N_FUNC_AW(BmpSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetBmp and NImageFormatCreateInfo instead")
NResult N_API BmpSaveImageToMemoryN(HNImage hImage, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetBmp and NImageFormatCreateInfo instead")
NResult N_API BmpSaveImageToMemory(HNImage hImage, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetBmp and NImageFormatCreateInfo instead")
NResult N_API BmpSaveImageToStream(HNImage hImage, HNStream hStream);

#define BmpLoadImageFromHBitmap(handle, phImage) NImageCreateFromHBitmap((HBITMAP)handle, 0, phImage)
#define BmpSaveImageToHBitmap(hImage, pHandle) NImageToHBitmap(hImage, (HBITMAP *)pHandle)

#ifdef N_MSVC
	#pragma deprecated("BmpLoadImageFromHBitmap", "BmpSaveImageToHBitmap")
#endif

#ifdef N_CPP
}
#endif

#include <NImageUndefWinTypes.h>

#endif // !BMP_H_INCLUDED
