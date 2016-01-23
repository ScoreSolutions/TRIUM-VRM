#ifndef N_PROPERTY_BAG_H_INCLUDED
#define N_PROPERTY_BAG_H_INCLUDED

#include <NValue.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPropertyBag, NObject)

NResult N_API NPropertyBagCreate(HNPropertyBag * phPropertyBag);
NResult N_API NPropertyBagGetCount(HNPropertyBag hPropertyBag, NInt * pValue);
NResult N_API NPropertyBagGetAt(HNPropertyBag hPropertyBag, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NPropertyBagGetKey(HNPropertyBag hPropertyBag, NInt index, HNString * phValue);
NResult N_API NPropertyBagGetValue(HNPropertyBag hPropertyBag, NInt index, HNValue * phValue);
NResult N_API NPropertyBagAddPair(HNPropertyBag hPropertyBag, const struct NNameValuePair_ * pValue);
NResult N_API NPropertyBagRemoveAt(HNPropertyBag hPropertyBag, NInt index);
NResult N_API NPropertyBagClear(HNPropertyBag hPropertyBag);

NResult N_API NPropertyBagContainsN(HNPropertyBag hPropertyBag, HNString hKey, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagContainsA(HNPropertyBag hPropertyBag, const NAChar * szKey, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagContainsW(HNPropertyBag hPropertyBag, const NWChar * szKey, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagContains(HNPropertyBag hPropertyBag, const NChar * szKey, NBool * pResult);
#endif
#define NPropertyBagContains N_FUNC_AW(NPropertyBagContains)

NResult N_API NPropertyBagGetN(HNPropertyBag hPropertyBag, HNString hKey, HNValue * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagGetA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagGetW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagGet(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue * phValue);
#endif
#define NPropertyBagGet N_FUNC_AW(NPropertyBagGet)

NResult N_API NPropertyBagTryGetN(HNPropertyBag hPropertyBag, HNString hKey, HNValue * phValue, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagTryGetA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagTryGetW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagTryGet(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#define NPropertyBagTryGet N_FUNC_AW(NPropertyBagTryGet)

NResult N_API NPropertyBagAddN(HNPropertyBag hPropertyBag, HNString hKey, HNValue hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagAddA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue hValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagAddW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagAdd(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue hValue);
#endif
#define NPropertyBagAdd N_FUNC_AW(NPropertyBagAdd)

NResult N_API NPropertyBagSetN(HNPropertyBag hPropertyBag, HNString hKey, HNValue hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagSetA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue hValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagSetW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagSet(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue hValue);
#endif
#define NPropertyBagSet N_FUNC_AW(NPropertyBagSet)

NResult N_API NPropertyBagRemoveN(HNPropertyBag hPropertyBag, HNString hKey, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagRemoveA(HNPropertyBag hPropertyBag, const NAChar * szKey, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagRemoveW(HNPropertyBag hPropertyBag, const NWChar * szKey, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagRemove(HNPropertyBag hPropertyBag, const NChar * szKey, NBool * pResult);
#endif
#define NPropertyBagRemove N_FUNC_AW(NPropertyBagRemove)

NResult N_API NPropertyBagApplyTo(HNPropertyBag hPropertyBag, HNObject hObject);

NResult N_API NPropertyBagTryParseN(HNString hValue, HNString hFormat, HNPropertyBag * phValue, NBool * pResult);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagTryParseVNA(HNString hValue, const NAChar * szFormat, HNPropertyBag * phValue, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagTryParseVNW(HNString hValue, const NWChar * szFormat, HNPropertyBag * phValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagTryParseVN(HNString hValue, const NChar * szFormat, HNPropertyBag * phValue, NBool * pResult);
#endif
#define NPropertyBagTryParseVN N_FUNC_AW(NPropertyBagTryParseVN)

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagTryParseA(const NAChar * szValue, const NAChar * szFormat, HNPropertyBag * phValue, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagTryParseW(const NWChar * szValue, const NWChar * szFormat, HNPropertyBag * phValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagTryParse(const NChar * szValue, const NChar * szFormat, HNPropertyBag * phValue, NBool * pResult);
#endif
#define NPropertyBagTryParse N_FUNC_AW(NPropertyBagTryParse)

NResult N_API NPropertyBagParseN(HNString hValue, HNString hFormat, HNPropertyBag * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagParseVNA(HNString hValue, const NAChar * szFormat, HNPropertyBag * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagParseVNW(HNString hValue, const NWChar * szFormat, HNPropertyBag * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagParseVN(HNString hValue, const NChar * szFormat, HNPropertyBag * phValue);
#endif
#define NPropertyBagParseVN N_FUNC_AW(NPropertyBagParseVN)

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagParseA(const NAChar * szValue, const NAChar * szFormat, HNPropertyBag * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagParseW(const NWChar * szValue, const NWChar * szFormat, HNPropertyBag * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagParse(const NChar * szValue, const NChar * szFormat, HNPropertyBag * phValue);
#endif
#define NPropertyBagParse N_FUNC_AW(NPropertyBagParse)

#ifdef N_CPP
}
#endif

#endif // !N_PROPERTY_BAG_H_INCLUDED
