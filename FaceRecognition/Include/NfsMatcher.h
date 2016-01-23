#ifndef NFS_MATCHER_H_INCLUDED
#define NFS_MATCHER_H_INCLUDED

#include <NFMatcher.h>
#include <NfsmMatchDetails.h>
#include <NfsMatcherParams.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NfsMatcher, NObject)

N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NfsmCreate(HNfsMatcher * phMatcher);
N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NfsmCreateEx(NBool isPalm, HNfsMatcher * phMatcher);

N_DEPRECATED("function is deprecated, use NMVerifyN instead")
NResult N_API NfsmVerifyN(HNfsMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, NfsmMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMVerify instead")
NResult N_API NfsmVerify(HNfsMatcher hMatcher, const void * template1, NSizeType template1Size,
	const void * template2, NSizeType template2Size, NfsmMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyStartN instead")
NResult N_API NfsmIdentifyStartN(HNfsMatcher hMatcher, HNBuffer hTemplate, NfsmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyStart instead")
NResult N_API NfsmIdentifyStart(HNfsMatcher hMatcher, const void * templ, NSizeType templSize, NfsmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyNextN instead")
NResult N_API NfsmIdentifyNextN(HNfsMatcher hMatcher, HNBuffer hTemplate, NfsmMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyNext instead")
NResult N_API NfsmIdentifyNext(HNfsMatcher hMatcher, const void * templ, NSizeType templSize, NfsmMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyEnd instead")
NResult N_API NfsmIdentifyEnd(HNfsMatcher hMatcher);

N_DEPRECATED("function is deprecated")
NResult N_API NfsmIsPalm(HNfsMatcher hMatcher, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // !NFS_MATCHER_H_INCLUDED
