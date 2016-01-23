#ifndef NEM_MATCH_DETAILS_H_INCLUDED
#define NEM_MATCH_DETAILS_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NemMatchDetails_
{
	NInt Score;
} NemMatchDetails;

NResult N_API NemMatchDetailsDeserializeN(HNBuffer hBuffer, NemMatchDetails * * ppMatchDetails);
NResult N_API NemMatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NemMatchDetails * * ppMatchDetails);
NResult N_API NemMatchDetailsDeserializeFromStream(HNStream hStream, NemMatchDetails * * ppMatchDetails);
void N_API NemMatchDetailsFree(NemMatchDetails * pMatchDetails);
NResult N_API NemMatchDetailsSerializeN(NemMatchDetails * pMatchDetails, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NemMatchDetailsSerializeN instead")
NResult N_API NemMatchDetailsSerialize(NemMatchDetails * pMatchDetails, void * * ppBuffer, NSizeType * pBufferSize);
NResult N_API NemMatchDetailsSerializeToStream(NemMatchDetails * pMatchDetails, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !NEM_MATCH_DETAILS_H_INCLUDED
