#ifndef NFSM_MATCH_DETAILS_H_INCLUDED
#define NFSM_MATCH_DETAILS_H_INCLUDED

#include <NfmMatchDetails.h>
#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NfsmFingerMatchDetails_
{
	NInt Score;
	NInt MatchedIndex;
	struct NfmMatchDetails_ * NfmMatchDetails;
} NfsmFingerMatchDetails;

typedef struct NfsmMatchDetails_
{
	NBool IsPalm;
	NInt Score;
	NInt FingerCount;
	NfsmFingerMatchDetails * Fingers;
} NfsmMatchDetails;

NResult N_API NfsmMatchDetailsDeserializeN(HNBuffer hBuffer, NfsmMatchDetails * * ppMatchDetails);
NResult N_API NfsmMatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NfsmMatchDetails * * ppMatchDetails);
NResult N_API NfsmMatchDetailsDeserializeFromStream(HNStream hStream, NfsmMatchDetails * * ppMatchDetails);
void N_API NfsmMatchDetailsFree(NfsmMatchDetails * pMatchDetails);
NResult N_API NfsmMatchDetailsSerializeN(NfsmMatchDetails * pMatchDetails, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NfsmMatchDetailsSerializeN instead")
NResult N_API NfsmMatchDetailsSerialize(NfsmMatchDetails * pMatchDetails, void * * ppBuffer, NSizeType * pBufferSize);
NResult N_API NfsmMatchDetailsSerializeToStream(NfsmMatchDetails * pMatchDetails, HNStream hStream);

#ifdef N_CPP
}
#endif

#endif // !NFSM_MATCH_DETAILS_H_INCLUDED
