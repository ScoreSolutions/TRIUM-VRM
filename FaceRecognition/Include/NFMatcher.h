#ifndef NF_MATCHER_H_INCLUDED
#define NF_MATCHER_H_INCLUDED

#include <NfmMatchDetails.h>
#include <NFMatcherParams.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFMatcher, NObject)

N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NfmCreate(HNFMatcher * phMatcher);
N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NfmCreateEx(NBool isPalm, HNFMatcher * phMatcher);

N_DEPRECATED("function is deprecated, use NMVerifyN instead")
NResult N_API NfmVerifyN(HNFMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, NfmMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMVerify instead")
NResult N_API NfmVerify(HNFMatcher hMatcher, const void * template1, NSizeType template1Size,
	const void * template2, NSizeType template2Size, NfmMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyStartN instead")
NResult N_API NfmIdentifyStartN(HNFMatcher hMatcher, HNBuffer hTemplate, NfmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyStart instead")
NResult N_API NfmIdentifyStart(HNFMatcher hMatcher, const void * templ, NSizeType templSize, NfmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyNextN instead")
NResult N_API NfmIdentifyNextN(HNFMatcher hMatcher, HNBuffer hTemplate, NfmMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyNext instead")
NResult N_API NfmIdentifyNext(HNFMatcher hMatcher, const void * templ, NSizeType templSize, NfmMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyEnd instead")
NResult N_API NfmIdentifyEnd(HNFMatcher hMatcher);

N_DEPRECATED("function is deprecated")
NResult N_API NfmIsPalm(HNFMatcher hMatcher, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // !NF_MATCHER_H_INCLUDED
