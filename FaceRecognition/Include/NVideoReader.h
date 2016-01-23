#ifndef N_VIDEO_READER_H_INCLUDED
#define N_VIDEO_READER_H_INCLUDED

#include <NImages.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NVideoReader, NObject)

N_DEPRECATED("function is deprecated, use NMediaReaderCreateFromFileN instead")
NResult N_API NVideoReaderCreateFromFileN(HNString hFileName, HNVideoReader * phReader);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NMediaReaderCreateFromFileA instead")
NResult N_API NVideoReaderCreateFromFileA(const NAChar * szFileName, HNVideoReader * phReader);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NMediaReaderCreateFromFileW instead")
NResult N_API NVideoReaderCreateFromFileW(const NWChar * szFileName, HNVideoReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVideoReaderCreateFromFile(const NChar * szFileName, HNVideoReader * phReader);
#endif
#define NVideoReaderCreateFromFile N_FUNC_AW(NVideoReaderCreateFromFile)

N_DEPRECATED("function is deprecated, use NMediaReaderGetLength instead")
NResult N_API NVideoReaderGetFrameCount(HNVideoReader hReader, NInt * pValue);
N_DEPRECATED("function is deprecated, use NMediaReaderGetCurrentFormat and NVideoFormatGetWidth instead")
NResult N_API NVideoReaderGetFrameWidth(HNVideoReader hReader, NUInt * pValue);
N_DEPRECATED("function is deprecated, use NMediaReaderGetCurrentFormat and NVideoFormatGetHeight instead")
NResult N_API NVideoReaderGetFrameHeight(HNVideoReader hReader, NUInt * pValue);
N_DEPRECATED("function is deprecated, use NMediaReaderGetCurrentFormat and NVideoFormatGetFrameRate instead")
NResult N_API NVideoReaderGetFrameRate(HNVideoReader hReader, NDouble * pValue);
N_DEPRECATED("function is deprecated, use NMediaReaderReadFrame instead")
NResult N_API NVideoReaderGetFrame(HNVideoReader hReader, NInt frameIndex, HNImage * phFrame);

#define NVideoReaderFree(hReader) NObjectFree(hReader)

#ifdef N_MSVC
	#pragma deprecated("NVideoReaderFree")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_VIDEO_READER_H_INCLUDED
