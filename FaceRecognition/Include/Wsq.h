#ifndef WSQ_H_INCLUDED
#define WSQ_H_INCLUDED

#include <NImage.h>
#include <NistCom.h>

#ifdef N_CPP
extern "C"
{
#endif

#define WSQ_DEFAULT_BIT_RATE 0.75f

#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN32_X86 10150
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN64_X64 10151

#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_I386 10152
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_AMD64 10153

#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL 10154
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL64 10155
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_POWERPC 10156

N_DECLARE_OBJECT_TYPE(WsqInfo, NImageInfo)

NResult N_API WsqInfoGetBitRate(HWsqInfo hInfo, NFloat * pValue);
NResult N_API WsqInfoSetBitRate(HWsqInfo hInfo, NFloat value);
NResult N_API WsqInfoGetImplementationNumber(HWsqInfo hInfo, NUShort * pValue);
NResult N_API WsqInfoHasNistCom(HWsqInfo hInfo, NBool * pValue);
NResult N_API WsqInfoSetHasNistCom(HWsqInfo hInfo, NBool value);
NResult N_API WsqInfoGetNistCom(HWsqInfo hInfo, HNistCom * phValue);

N_DEPRECATED("function is deprecated, use NImageCreateFromFileN and NImageFormatGetWsq instead")
NResult N_API WsqLoadImageFromFileN(HNString hFileName, HNImage * phImage);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageCreateFromFileA and NImageFormatGetWsq instead")
NResult N_API WsqLoadImageFromFileA(const NAChar * szFileName, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageCreateFromFileW and NImageFormatGetWsq instead")
NResult N_API WsqLoadImageFromFileW(const NWChar * szFileName, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API WsqLoadImageFromFile(const NChar * szFileName, HNImage * phImage);
#endif
#define WsqLoadImageFromFile N_FUNC_AW(WsqLoadImageFromFile)

N_DEPRECATED("function is deprecated, use NImageCreateFromMemoryN and NImageFormatGetWsq instead")
NResult N_API WsqLoadImageFromMemoryN(HNBuffer hBuffer, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromMemory and NImageFormatGetWsq instead")
NResult N_API WsqLoadImageFromMemory(const void * pBuffer, NSizeType bufferSize, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromStream and NImageFormatGetWsq instead")
NResult N_API WsqLoadImageFromStream(HNStream hStream, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageSaveToFileN, NImageFormatGetWsq, NImageFormatCreateInfo and WsqInfoSetBitRate instead")
NResult N_API WsqSaveImageToFileN(HNImage hImage, NFloat bitRate, HNString hFileName);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageSaveToFileA, NImageFormatGetWsq, NImageFormatCreateInfo and WsqInfoSetBitRate instead")
NResult N_API WsqSaveImageToFileA(HNImage hImage, NFloat bitRate, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageSaveToFileW, NImageFormatGetWsq, NImageFormatCreateInfo and WsqInfoSetBitRate instead")
NResult N_API WsqSaveImageToFileW(HNImage hImage, NFloat bitRate, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API WsqSaveImageToFile(HNImage hImage, NFloat bitRate, const NChar * szFileName);
#endif
#define WsqSaveImageToFile N_FUNC_AW(WsqSaveImageToFile)

N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN, NImageFormatGetWsq, NImageFormatCreateInfo and WsqInfoSetBitRate instead")
NResult N_API WsqSaveImageToMemoryN(HNImage hImage, NFloat bitRate, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemory, NImageFormatGetWsq, NImageFormatCreateInfo and WsqInfoSetBitRate instead")
NResult N_API WsqSaveImageToMemory(HNImage hImage, NFloat bitRate, void * * ppBuffer, NSizeType * pBufferSize);
N_DEPRECATED("function is deprecated, use NImageSaveToStream, NImageFormatGetWsq, NImageFormatCreateInfo and WsqInfoSetBitRate instead")
NResult N_API WsqSaveImageToStream(HNImage hImage, NFloat bitRate, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !WSQ_H_INCLUDED
