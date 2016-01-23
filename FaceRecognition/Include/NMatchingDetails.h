#ifndef N_MATCHING_DETAILS_H_INCLUDED
#define N_MATCHING_DETAILS_H_INCLUDED

#include <NFMatchingDetails.h>
#include <NLMatchingDetails.h>
#include <NEMatchingDetails.h>
#include <NSMatchingDetails.h>
#include <NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMatchingDetails, NMatchingDetailsBase)

NResult N_API NMatchingDetailsCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNMatchingDetails * phMatchingDetails);
NResult N_API NMatchingDetailsCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNMatchingDetails * phMatchingDetails);
NResult N_API NMatchingDetailsCreateFromStream(HNStream hStream, NUInt flags, HNMatchingDetails * phMatchingDetails);

N_DEPRECATED("function is deprecated, use NObjectSaveToMemoryN instead")
NResult N_API NMatchingDetailsSaveToMemory(HNMatchingDetailsBase hMatchingDetails, NUInt flags, void * * ppBuffer, NSizeType * pBufferSize);
#define NMatchingDetailsSaveToStream(hMatchingDetails, hStream, flags) NObjectSaveToStream(hMatchingDetails, hStream, flags)

NResult N_API NMatchingDetailsGetId(HNMatchingDetails hMatchingDetails, const void * * pValue);

NResult N_API NMatchingDetailsGetFingersScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFingerCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
N_DEPRECATED("function is deprecated, use NMatchingDetailsGetFingerEx instead")
NResult N_API NMatchingDetailsGetFinger(HNMatchingDetails hMatchingDetails, NInt index, HNFMatchingDetails * phValue);
NResult N_API NMatchingDetailsGetFingerEx(HNMatchingDetails hMatchingDetails, NInt index, HNFMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetFacesScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFacesMatchedIndex(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFaceCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
N_DEPRECATED("function is deprecated, use NMatchingDetailsGetFaceEx instead")
NResult N_API NMatchingDetailsGetFace(HNMatchingDetails hMatchingDetails, NInt index, HNLMatchingDetails * phValue);
NResult N_API NMatchingDetailsGetFaceEx(HNMatchingDetails hMatchingDetails, NInt index, HNLMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetIrisesScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetIrisCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
N_DEPRECATED("function is deprecated, use NMatchingDetailsGetIrisEx instead")
NResult N_API NMatchingDetailsGetIris(HNMatchingDetails hMatchingDetails, NInt index, HNEMatchingDetails * phValue);
NResult N_API NMatchingDetailsGetIrisEx(HNMatchingDetails hMatchingDetails, NInt index, HNEMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetPalmsScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetPalmCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
N_DEPRECATED("function is deprecated, use NMatchingDetailsGetPalmEx instead")
NResult N_API NMatchingDetailsGetPalm(HNMatchingDetails hMatchingDetails, NInt index, HNFMatchingDetails * phValue);
NResult N_API NMatchingDetailsGetPalmEx(HNMatchingDetails hMatchingDetails, NInt index, HNFMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetVoicesScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetVoiceCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
N_DEPRECATED("function is deprecated, use NMatchingDetailsGetVoiceEx instead")
NResult N_API NMatchingDetailsGetVoice(HNMatchingDetails hMatchingDetails, NInt index, HNSMatchingDetails * phValue);
NResult N_API NMatchingDetailsGetVoiceEx(HNMatchingDetails hMatchingDetails, NInt index, HNSMatchingDetails * phValue);

#ifdef N_MSVC
	#pragma deprecated("NMatchingDetailsSaveToStream")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_MATCHING_DETAILS_H_INCLUDED
