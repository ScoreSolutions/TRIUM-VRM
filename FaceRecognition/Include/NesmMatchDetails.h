#ifndef NESM_MATCH_DETAILS_H_INCLUDED
#define NESM_MATCH_DETAILS_H_INCLUDED

#include <NemMatchDetails.h>
#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NesmIrisMatchDetails_
{
	NInt Score;
	NInt MatchedIndex;
	struct NemMatchDetails_ * NemMatchDetails;
} NesmIrisMatchDetails;

typedef struct NesmMatchDetails_
{
	NInt Score;
	NInt IrisCount;
	NesmIrisMatchDetails * Irises;
} NesmMatchDetails;

NResult N_API NesmMatchDetailsDeserializeN(HNBuffer hBuffer, NesmMatchDetails * * ppMatchDetails);
NResult N_API NesmMatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NesmMatchDetails * * ppMatchDetails);
NResult N_API NesmMatchDetailsDeserializeFromStream(HNStream hStream, NesmMatchDetails * * ppMatchDetails);
void N_API NesmMatchDetailsFree(NesmMatchDetails * pMatchDetails);
NResult N_API NesmMatchDetailsSerializeN(NesmMatchDetails * pMatchDetails, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NesmMatchDetailsSerializeN instead")
NResult N_API NesmMatchDetailsSerialize(NesmMatchDetails * pMatchDetails, void * * ppBuffer, NSizeType * pBufferSize);
NResult N_API NesmMatchDetailsSerializeToStream(NesmMatchDetails * pMatchDetails, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !NESM_MATCH_DETAILS_H_INCLUDED
