#ifndef NM_MATCH_DETAILS_H_INCLUDED
#define NM_MATCH_DETAILS_H_INCLUDED

#include <NfsmMatchDetails.h>
#include <NlsmMatchDetails.h>
#include <NesmMatchDetails.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NMMatchDetails_
{
	NInt Score;
	NfsmMatchDetails * FingersMatchDetails;
	NlsmMatchDetails * FacesMatchDetails;
	NesmMatchDetails * IrisesMatchDetails;
	NfsmMatchDetails * PalmsMatchDetails;
} NMMatchDetails;

NResult N_API NMMatchDetailsDeserializeN(HNBuffer hBuffer, NMMatchDetails * * ppMatchDetails);
NResult N_API NMMatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NMMatchDetails * * ppMatchDetails);
NResult N_API NMMatchDetailsDeserializeFromStream(HNStream hStream, NMMatchDetails * * ppMatchDetails);
void N_API NMMatchDetailsFree(NMMatchDetails * pMatchDetails);
NResult N_API NMMatchDetailsSerializeN(NMMatchDetails * pMatchDetails, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NMMatchDetailsSerializeN instead")
NResult N_API NMMatchDetailsSerialize(NMMatchDetails * pMatchDetails, void * * ppBuffer, NSizeType * pBufferSize);
NResult N_API NMMatchDetailsSerializeToStream(NMMatchDetails * pMatchDetails, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !NM_MATCH_DETAILS_H_INCLUDED
