#ifndef NLSM_MATCH_DETAILS_H_INCLUDED
#define NLSM_MATCH_DETAILS_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NlsmFaceMatchDetails_
{
	NDouble Score;
	NInt MatchedIndex;
} NlsmFaceMatchDetails;

typedef struct NlsmMatchDetails_
{
	NDouble Score;
	NInt MatchedIndex;
	NInt FaceCount;
	NlsmFaceMatchDetails * Faces;
} NlsmMatchDetails;

NResult N_API NlsmMatchDetailsDeserializeN(HNBuffer hBuffer, NlsmMatchDetails * * ppMatchDetails);
NResult N_API NlsmMatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NlsmMatchDetails * * ppMatchDetails);
NResult N_API NlsmMatchDetailsDeserializeFromStream(HNStream hStream, NlsmMatchDetails * * ppMatchDetails);
void N_API NlsmMatchDetailsFree(NlsmMatchDetails * pMatchDetails);
NResult N_API NlsmMatchDetailsSerializeN(NlsmMatchDetails * pMatchDetails, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NlsmMatchDetailsSerializeN instead")
NResult N_API NlsmMatchDetailsSerialize(NlsmMatchDetails * pMatchDetails, void * * ppBuffer, NSizeType * pBufferSize);
NResult N_API NlsmMatchDetailsSerializeToStream(NlsmMatchDetails * pMatchDetails, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !NLSM_MATCH_DETAILS_H_INCLUDED
