#ifndef TIFF_H_INCLUDED
#define TIFF_H_INCLUDED

#include "NImage.h"

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(TiffInfo, NImageInfo)

N_DEPRECATED("function is deprecated, use NImageCreateFromFileN and NImageFormatGetTiff instead")
NResult N_API TiffLoadImageFromFileN(HNString hFileName, HNImage * phImage);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileA and NImageFormatGetTiff instead")
NResult N_API TiffLoadImageFromFileA(const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileW and NImageFormatGetTiff instead")
NResult N_API TiffLoadImageFromFileW(const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API TiffLoadImageFromFile(const NChar * szFileName, HNImage * phImage);
#endif
#define TiffLoadImageFromFile N_FUNC_AW(TiffLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN and NImageFormatGetTiff instead")
NResult N_API TiffLoadImageFromMemoryN(HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory and NImageFormatGetTiff instead")
NResult N_API TiffLoadImageFromMemory(const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream and NImageFormatGetTiff instead")
NResult N_API TiffLoadImageFromStream(HNStream hStream, HNImage * phImage);

#ifdef N_CPP
}
#endif

#endif // !TIFF_H_INCLUDED
