#ifndef N_VIDEO_WRITER_H_INCLUDED
#define N_VIDEO_WRITER_H_INCLUDED

#include <NImages.h>
#include <NVideoWriterOptions.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NVideoWriter, NObject)

NResult N_API NVideoWriterCreateFileN(HNString hFileName, NUInt width, NUInt height, NDouble frameRate, HNVideoWriterOptions hOptions, HNVideoWriter * phWriter);

#ifndef N_NO_ANSI_FUNC
NResult N_API NVideoWriterCreateFileA(const NAChar * szFileName, NUInt width, NUInt height, NDouble frameRate, HNVideoWriterOptions hOptions, HNVideoWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NVideoWriterCreateFileW(const NWChar * szFileName, NUInt width, NUInt height, NDouble frameRate, HNVideoWriterOptions hOptions, HNVideoWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVideoWriterCreateFile(const NChar * szFileName, NUInt width, NUInt height, NDouble frameRate, HNVideoWriterOptions hOptions, HNVideoWriter * phWriter);
#endif
#define NVideoWriterCreateFile N_FUNC_AW(NVideoWriterCreateFile)

NResult N_API NVideoWriterWriteFrame(HNVideoWriter hWriter, HNImage hFrame);

#define NVideoWriterFree(hWriter) NObjectFree(hWriter)

#ifdef N_MSVC
	#pragma deprecated("NVideoWriterFree")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_VIDEO_WRITER_H_INCLUDED
