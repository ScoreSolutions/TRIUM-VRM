#ifndef N_IMAGE_FORMAT_H_INCLUDED
#define N_IMAGE_FORMAT_H_INCLUDED

#include <NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageFormat, NObject)

#ifdef N_CPP
}
#endif

#include <NImage.h>
#include <NImageInfo.h>
#include <NImageFile.h>
#include <NImageReader.h>
#include <NImageWriter.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NImageFormatGetFormatCount(NInt * pValue);
NResult N_API NImageFormatGetFormat(NInt index, HNImageFormat * phValue);
NResult N_API NImageFormatGetFormatEx(NInt index, HNImageFormat * phValue);

NResult N_API NImageFormatSelectExN(HNString hFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectExA(const NAChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectExW(const NWChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelectEx(const NChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#define NImageFormatSelectEx N_FUNC_AW(NImageFormatSelectEx)

NResult N_API NImageFormatSelectN(HNString hFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectA(const NAChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectW(const NWChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelect(const NChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#define NImageFormatSelect N_FUNC_AW(NImageFormatSelect)

NResult N_API NImageFormatSelectByInternetMediaTypeN(HNString hInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectByInternetMediaTypeA(const NAChar * szInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectByInternetMediaTypeW(const NWChar * szInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelectByInternetMediaType(const NChar * szInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#define NImageFormatSelectByInternetMediaType N_FUNC_AW(NImageFormatSelectByInternetMediaType)

NResult N_API NImageFormatSelectReaderFromFileN(HNString hFileName, NUInt flags, HNImageReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectReaderFromFileA(const NAChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectReaderFromFileW(const NWChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelectReaderFromFile(const NChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#define NImageFormatSelectReaderFromFile N_FUNC_AW(NImageFormatSelectReaderFromFile)

NResult N_API NImageFormatSelectReaderFromMemoryN(HNBuffer hBuffer, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatSelectReaderFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatSelectReaderFromStream(HNStream hStream, NUInt flags, HNImageReader * phReader);

NResult N_API NImageFormatGetTiff(HNImageFormat * phValue);
NResult N_API NImageFormatGetTiffEx(HNImageFormat * phValue);
NResult N_API NImageFormatGetJpeg(HNImageFormat * phValue);
NResult N_API NImageFormatGetJpegEx(HNImageFormat * phValue);
NResult N_API NImageFormatGetPng(HNImageFormat * phValue);
NResult N_API NImageFormatGetPngEx(HNImageFormat * phValue);
NResult N_API NImageFormatGetWsq(HNImageFormat * phValue);
NResult N_API NImageFormatGetWsqEx(HNImageFormat * phValue);
NResult N_API NImageFormatGetJpeg2K(HNImageFormat * phValue);
NResult N_API NImageFormatGetJpeg2KEx(HNImageFormat * phValue);
NResult N_API NImageFormatGetBmp(HNImageFormat * phValue);
NResult N_API NImageFormatGetBmpEx(HNImageFormat * phValue);
NResult N_API NImageFormatGetIHead(HNImageFormat * phValue);
NResult N_API NImageFormatGetIHeadEx(HNImageFormat * phValue);

NResult N_API NImageFormatOpenReaderFromFileN(HNImageFormat hImageFormat, HNString hFileName, NUInt flags, HNImageReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatOpenReaderFromFileA(HNImageFormat hImageFormat, const NAChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatOpenReaderFromFileW(HNImageFormat hImageFormat, const NWChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatOpenReaderFromFile(HNImageFormat hImageFormat, const NChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#define NImageFormatOpenReaderFromFile N_FUNC_AW(NImageFormatOpenReaderFromFile)

NResult N_API NImageFormatOpenReaderFromMemoryN(HNImageFormat hImageFormat, HNBuffer hBuffer, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatOpenReaderFromMemory(HNImageFormat hImageFormat, const void * pBuffer, NSizeType bufferSize, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatOpenReaderFromStream(HNImageFormat hImageFormat, HNStream hStream, NUInt flags, HNImageReader * phReader);

NResult N_API NImageFormatCreateInfo(HNImageFormat hImageFormat, HNImage hImage, NUInt flags, HNImageInfo * phInfo);

NResult N_API NImageFormatOpenWriterToFileN(HNImageFormat hImageFormat, HNString hFileName, NUInt flags, HNImageWriter * phWriter);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatOpenWriterToFileA(HNImageFormat hImageFormat, const NAChar * szFileName, NUInt flags, HNImageWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatOpenWriterToFileW(HNImageFormat hImageFormat, const NWChar * szFileName, NUInt flags, HNImageWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatOpenWriterToFile(HNImageFormat hImageFormat, const NChar * szFileName, NUInt flags, HNImageWriter * phWriter);
#endif
#define NImageFormatOpenWriterToFile N_FUNC_AW(NImageFormatOpenWriterToFile)

NResult N_API NImageFormatOpenWriterToMemory(HNImageFormat hImageFormat, NUInt flags, HNImageWriter * phWriter);
NResult N_API NImageFormatOpenWriterToStream(HNImageFormat hImageFormat, HNStream hStream, NUInt flags, HNImageWriter * phWriter);

N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromFileN instead")
NResult N_API NImageFormatOpenFileN(HNImageFormat hImageFormat, HNString hFileName, HNImageFile * phImageFile);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromFileA instead")
NResult N_API NImageFormatOpenFileA(HNImageFormat hImageFormat, const NAChar * szFileName, HNImageFile * phImageFile);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromFileW instead")
NResult N_API NImageFormatOpenFileW(HNImageFormat hImageFormat, const NWChar * szFileName, HNImageFile * phImageFile);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatOpenFile(HNImageFormat hImageFormat, const NChar * szFileName, HNImageFile * phImageFile);
#endif
#define NImageFormatOpenFile N_FUNC_AW(NImageFormatOpenFile)

N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromMemoryN instead")
NResult N_API NImageFormatOpenFileFromMemoryN(HNImageFormat hImageFormat, HNBuffer hBuffer, HNImageFile * phImageFile);
N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromMemory instead")
NResult N_API NImageFormatOpenFileFromMemory(HNImageFormat hImageFormat, const void * pBuffer, NSizeType bufferSize, HNImageFile * phImageFile);
N_DEPRECATED("function is deprecated, use NImageFormatOpenReaderFromStream instead")
NResult N_API NImageFormatOpenFileFromStream(HNImageFormat hImageFormat, HNStream hStream, HNImageFile * phImageFile);

N_DEPRECATED("function is deprecated, use NImageCreateFromFileExN instead")
NResult N_API NImageFormatLoadImageFromFileN(HNImageFormat hImageFormat, HNString hFileName, HNImage * phImage);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileExA instead")
NResult N_API NImageFormatLoadImageFromFileA(HNImageFormat hImageFormat, const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileExW instead")
NResult N_API NImageFormatLoadImageFromFileW(HNImageFormat hImageFormat, const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatLoadImageFromFile(HNImageFormat hImageFormat, const NChar * szFileName, HNImage * phImage);
#endif
#define NImageFormatLoadImageFromFile N_FUNC_AW(NImageFormatLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN instead")
NResult N_API NImageFormatLoadImageFromMemoryN(HNImageFormat hImageFormat, HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory instead")
NResult N_API NImageFormatLoadImageFromMemory(HNImageFormat hImageFormat, const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream instead")
NResult N_API NImageFormatLoadImageFromStream(HNImageFormat hImageFormat, HNStream hStream, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageSaveToFileExN instead")
NResult N_API NImageFormatSaveImageToFileN(HNImageFormat hImageFormat, HNImage hImage, HNString hFileName);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileExA instead")
NResult N_API NImageFormatSaveImageToFileA(HNImageFormat hImageFormat, HNImage hImage, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileExW instead")
NResult N_API NImageFormatSaveImageToFileW(HNImageFormat hImageFormat, HNImage hImage, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSaveImageToFile(HNImageFormat hImageFormat, HNImage hImage, const NChar * szFileName);
#endif
#define NImageFormatSaveImageToFile N_FUNC_AW(NImageFormatSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN instead")
NResult N_API NImageFormatSaveImageToMemoryN(HNImageFormat hImageFormat, HNImage hImage, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory instead")
NResult N_API NImageFormatSaveImageToMemory(HNImageFormat hImageFormat, HNImage hImage, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream instead")
NResult N_API NImageFormatSaveImageToStream(HNImageFormat hImageFormat, HNImage hImage, HNStream hStream);

N_DEPRECATED("function is deprecated, use NImageFormatOpenWriterToFileN and NImageWriterWrite instead")
NResult N_API NImageFormatSaveImagesToFileN(HNImageFormat hImageFormat, NInt imageCount, HNImage * arhImages, HNString hFileName);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatOpenWriterToFileA and NImageWriterWrite instead")
NResult N_API NImageFormatSaveImagesToFileA(HNImageFormat hImageFormat, NInt imageCount, HNImage * arhImages, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatOpenWriterToFileW and NImageWriterWrite instead")
NResult N_API NImageFormatSaveImagesToFileW(HNImageFormat hImageFormat, NInt imageCount, HNImage * arhImages, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSaveImagesToFile(HNImageFormat hImageFormat, NInt imageCount, HNImage * arhImages, const NAChar * szFileName);
#endif
#define NImageFormatSaveImagesToFile N_FUNC_AW(NImageFormatSaveImagesToFile)

N_DEPRECATED("function is deprecated, use NImageFormatOpenWriterToMemory, NImageWriterWrite and NImageWriterGetBuffer instead")
NResult N_API NImageFormatSaveImagesToMemoryN(HNImageFormat hImageFormat, NInt imageCount, HNImage * arhImages, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageFormatOpenWriterToMemory, NImageWriterWrite and NImageWriterDetachBuffer instead")
NResult N_API NImageFormatSaveImagesToMemory(HNImageFormat hImageFormat, NInt imageCount, HNImage * arhImages, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageFormatOpenWriterToStream and NImageWriterWrite instead")
NResult N_API NImageFormatSaveImagesToStream(HNImageFormat hImageFormat, NInt imageCount, HNImage * arhImages, HNStream hStream);

NResult N_API NImageFormatGetNameN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatGetNameExA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatGetNameExW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetNameEx(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetNameEx N_FUNC_AW(NImageFormatGetNameEx)

NResult N_API NImageFormatGetDefaultFileExtensionN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatGetDefaultFileExtensionExA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatGetDefaultFileExtensionExW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetDefaultFileExtensionEx(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetDefaultFileExtensionEx N_FUNC_AW(NImageFormatGetDefaultFileExtensionEx)

NResult N_API NImageFormatGetDefaultInternetMediaTypeN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatGetDefaultInternetMediaTypeA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatGetDefaultInternetMediaTypeW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetDefaultInternetMediaType(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetDefaultInternetMediaType N_FUNC_AW(NImageFormatGetDefaultInternetMediaType)

NResult N_API NImageFormatGetFileFilterN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatGetFileFilterExA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatGetFileFilterExW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetFileFilterEx(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetFileFilterEx N_FUNC_AW(NImageFormatGetFileFilterEx)

NResult N_API NImageFormatGetInternetMediaTypeN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatGetInternetMediaTypeA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatGetInternetMediaTypeW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetInternetMediaType(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetInternetMediaType N_FUNC_AW(NImageFormatGetInternetMediaType)

NResult N_API NImageFormatCanRead(HNImageFormat hImageFormat, NBool * pValue);
NResult N_API NImageFormatCanWrite(HNImageFormat hImageFormat, NBool * pValue);
NResult N_API NImageFormatCanWriteMultiple(HNImageFormat hImageFormat, NBool * pValue);

#define NImageFormatGetNameA(hImageFormat, szValue) NImageFormatGetNameExA(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetNameW(hImageFormat, szValue) NImageFormatGetNameExW(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetName(hImageFormat, szValue) NImageFormatGetNameEx(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetDefaultFileExtensionA(hImageFormat, szValue) NImageFormatGetDefaultFileExtensionExA(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetDefaultFileExtensionW(hImageFormat, szValue) NImageFormatGetDefaultFileExtensionExW(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetDefaultFileExtension(hImageFormat, szValue) NImageFormatGetDefaultFileExtensionEx(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetFileFilterA(hImageFormat, szValue) NImageFormatGetFileFilterExA(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetFileFilterW(hImageFormat, szValue) NImageFormatGetFileFilterExW(hImageFormat, szValue, N_INT_MAX)
#define NImageFormatGetFileFilter(hImageFormat, szValue) NImageFormatGetFileFilterEx(hImageFormat, szValue, N_INT_MAX)

#ifdef N_MSVC
	#pragma deprecated("NImageFormatGetNameA", "NImageFormatGetNameW", "NImageFormatGetName")
	#pragma deprecated("NImageFormatGetDefaultFileExtensionA", "NImageFormatGetDefaultFileExtensionW", "NImageFormatGetDefaultFileExtension")
	#pragma deprecated("NImageFormatGetFileFilterA", "NImageFormatGetFileFilterW", "NImageFormatGetFileFilter")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_FORMAT_H_INCLUDED
