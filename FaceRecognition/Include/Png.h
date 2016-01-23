#ifndef PNG_H_INCLUDED
#define PNG_H_INCLUDED

#include <NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

#define PNG_DEFAULT_COMPRESSION_LEVEL 6

N_DECLARE_OBJECT_TYPE(PngInfo, NImageInfo)

NResult N_API PngInfoGetCompressionLevel(HPngInfo hInfo, NInt * pValue);
NResult N_API PngInfoSetCompressionLevel(HPngInfo hInfo, NInt value);

N_DEPRECATED("function is deprecated, use NImageCreateFromFileN and NImageFormatGetPng instead")
NResult N_API PngLoadImageFromFileN(HNString hFileName, HNImage * phImage);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileA and NImageFormatGetPng instead")
NResult N_API PngLoadImageFromFileA(const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileW and NImageFormatGetPng instead")
NResult N_API PngLoadImageFromFileW(const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API PngLoadImageFromFile(const NChar * szFileName, HNImage * phImage);
#endif
#define PngLoadImageFromFile N_FUNC_AW(PngLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN and NImageFormatGetPng instead")
NResult N_API PngLoadImageFromMemoryN(HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory and NImageFormatGetPng instead")
NResult N_API PngLoadImageFromMemory(const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream and NImageFormatGetPng instead")
NResult N_API PngLoadImageFromStream(HNStream hStream, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageSaveToFileN, NImageFormatGetPng, NImageFormatCreateInfo and PngInfoSetCompressionLevel instead")
NResult N_API PngSaveImageToFileN(HNImage hImage, NInt compressionLevel, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetPng, NImageFormatCreateInfo and PngInfoSetCompressionLevel instead")
NResult N_API PngSaveImageToFileA(HNImage hImage, NInt compressionLevel, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetPng, NImageFormatCreateInfo and PngInfoSetCompressionLevel instead")
NResult N_API PngSaveImageToFileW(HNImage hImage, NInt compressionLevel, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API PngSaveImageToFile(HNImage hImage, NInt compressionLevel, const NChar * szFileName);
#endif
#define PngSaveImageToFile N_FUNC_AW(PngSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetPng, NImageFormatCreateInfo and PngInfoSetCompressionLevel instead")
NResult N_API PngSaveImageToMemoryN(HNImage hImage, NInt compressionLevel, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetPng, NImageFormatCreateInfo and PngInfoSetCompressionLevel instead")
NResult N_API PngSaveImageToMemory(HNImage hImage, NInt compressionLevel, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetPng, NImageFormatCreateInfo and PngInfoSetCompressionLevel instead")
NResult N_API PngSaveImageToStream(HNImage hImage, NInt compressionLevel, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !PNG_H_INCLUDED
