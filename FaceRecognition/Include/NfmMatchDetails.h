#ifndef NFM_MATCH_DETAILS_H_INCLUDED
#define NFM_MATCH_DETAILS_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NfmMatchDetails_
{
	NBool IsPalm;
	NInt Score;
	NInt CenterX;
	NInt CenterY;
	NByte Rotation;
	NInt TranslationX;
	NInt TranslationY;
	NInt MatedMinutiaCount;
	struct NIndexPair_ * MatedMinutiae;
} NfmMatchDetails;

NResult N_API NfmMatchDetailsDeserializeN(HNBuffer hBuffer, NfmMatchDetails * * ppMatchDetails);
NResult N_API NfmMatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NfmMatchDetails * * ppMatchDetails);
NResult N_API NfmMatchDetailsDeserializeFromStream(HNStream hStream, NfmMatchDetails * * ppMatchDetails);
void N_API NfmMatchDetailsFree(NfmMatchDetails * pMatchDetails);
NResult N_API NfmMatchDetailsSerializeN(NfmMatchDetails * pMatchDetails, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NfmMatchDetailsSerializeN instead")
NResult N_API NfmMatchDetailsSerialize(NfmMatchDetails * pMatchDetails, void * * ppBuffer, NSizeType * pBufferSize);
NResult N_API NfmMatchDetailsSerializeToStream(NfmMatchDetails * pMatchDetails, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !NFM_MATCH_DETAILS_H_INCLUDED
