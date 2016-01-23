#ifndef N_IMAGE_FILE_H_INCLUDED
#define N_IMAGE_FILE_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageFile, NObject)

#ifdef N_CPP
}
#endif

#include <NImageFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromFileN or NImageFormatSelectReaderFromFileN instead")
NResult N_API NImageFileCreateN(HNString hFileName, HNImageFormat hImageFormat, HNImageFile * phImageFile);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromFileA or NImageFormatSelectReaderFromFileA instead")
NResult N_API NImageFileCreateA(const NAChar * szFileName, HNImageFormat hImageFormat, HNImageFile * phImageFile);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromFileW or NImageFormatSelectReaderFromFileW instead")
NResult N_API NImageFileCreateW(const NWChar * szFileName, HNImageFormat hImageFormat, HNImageFile * phImageFile);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFileCreate(const NChar * szFileName, HNImageFormat hImageFormat, HNImageFile * phImageFile);
#endif
#define NImageFileCreate N_FUNC_AW(NImageFileCreate)

N_DEPRECATED("function is deprecated, use NObjectFree instead")
NResult N_API NImageFileClose(HNImageFile hImageFile);
N_DEPRECATED("function is deprecated, use NImageReaderRead instead")
NResult N_API NImageFileReadImage(HNImageFile hImageFile, HNImage * phImage);

N_DEPRECATED("function is deprecated, do not use")
NResult N_API NImageFileIsOpened(HNImageFile hImageFile, NBool * pValue);
N_DEPRECATED("function is deprecated, use NImageReaderGetFormat instead")
NResult N_API NImageFileGetFormat(HNImageFile hImageFile, HNImageFormat * phValue);
N_DEPRECATED("function is deprecated, use NImageReaderGetFormatEx instead")
NResult N_API NImageFileGetFormatEx(HNImageFile hImageFile, HNImageFormat * phValue);

#define NImageFileFree(hImageFile) NObjectFree(hImageFile)

#ifdef N_MSVC
	#pragma deprecated("NImageFileFree")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_FILE_H_INCLUDED
