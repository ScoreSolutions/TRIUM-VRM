#ifndef N_TEMPLATE_H_INCLUDED
#define N_TEMPLATE_H_INCLUDED

#include <NFTemplate.h>
#include <NLTemplate.h>
#include <NETemplate.h>
#include <NSTemplate.h>
#include <NTemplates.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NTemplate, NObject)

NResult N_API NTemplateCalculateSize(NSizeType fingersTemplateSize, NSizeType facesTemplateSize, NSizeType irisesTemplateSize, NSizeType palmsTemplateSize, NSizeType voicesTemplateSize, NSizeType * pSize);
NResult N_API NTemplatePack(
	const void * pFingersTemplate, NSizeType fingersTemplateSize,
	const void * pFacesTemplate, NSizeType facesTemplateSize,
	const void * pIrisesTemplate, NSizeType irisesTemplateSize,
	const void * pPalmsTemplate, NSizeType palmsTemplateSize,
	const void * pVoicesTemplate, NSizeType voicesTemplateSize,
	void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NTemplateUnpack(const void * pBuffer, NSizeType bufferSize,
	NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	const void * * ppFingersTemplate, NSizeType * pFingersTemplateSize,
	const void * * ppFacesTemplate, NSizeType * pFacesTemplateSize,
	const void * * ppIrisesTemplate, NSizeType * pIrisesTemplateSize,
	const void * * ppPalmsTemplate, NSizeType * pPalmsTemplateSize,
	const void * * ppVoicesTemplate, NSizeType * pVoicesTemplateSize);
NResult N_API NTemplateCheckN(HNBuffer hBuffer);
NResult N_API NTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);

#define NTemplateCreate(phTemplate) NTemplateCreateEx(0, phTemplate)
NResult N_API NTemplateCreateEx(NUInt flags, HNTemplate * phTemplate);
NResult N_API NTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNTemplate * phTemplate);
NResult N_API NTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNTemplate * phTemplate);

N_DEPRECATED("function is deprecated, use NTemplateGetFingersEx instead")
NResult N_API NTemplateGetFingers(HNTemplate hTemplate, HNFTemplate * phValue);
NResult N_API NTemplateGetFingersEx(HNTemplate hTemplate, HNFTemplate * phValue);
NResult N_API NTemplateSetFingers(HNTemplate hTemplate, HNFTemplate hValue);
#define NTemplateAddFingers(hTemplate, phFingers) NTemplateAddFingersEx(hTemplate, 0, phFingers)
N_DEPRECATED("function is deprecated, use NFTemplateCreateEx and NTemplateSetFingers instead")
NResult N_API NTemplateAddFingersEx(HNTemplate hTemplate, NUInt flags, HNFTemplate * phFingers);
N_DEPRECATED("function is deprecated, use NFTemplateCreateFromMemoryN and NTemplateSetFingers instead")
NResult N_API NTemplateAddFingersFromMemoryN(HNTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNFTemplate * phFingers);
N_DEPRECATED("function is deprecated, use NFTemplateCreateFromMemory and NTemplateSetFingers instead")
NResult N_API NTemplateAddFingersFromMemoryEx(HNTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNFTemplate * phFingers);
#define NTemplateAddFingersCopy(hTemplate, hSrcFingers, phFingers) NTemplateAddFingersCopyEx(hTemplate, hSrcFingers, 0, phFingers)
N_DEPRECATED("function is deprecated, use NObjectClone and NTemplateSetFingers instead")
NResult N_API NTemplateAddFingersCopyEx(HNTemplate hTemplate, HNFTemplate hSrcFingers, NUInt flags, HNFTemplate * phFingers);
N_DEPRECATED("function is deprecated, use NTemplateSetFingers instead")
NResult N_API NTemplateRemoveFingers(HNTemplate hTemplate);

N_DEPRECATED("function is deprecated, use NTemplateGetFacesEx instead")
NResult N_API NTemplateGetFaces(HNTemplate hTemplate, HNLTemplate * phValue);
NResult N_API NTemplateGetFacesEx(HNTemplate hTemplate, HNLTemplate * phValue);
NResult N_API NTemplateSetFaces(HNTemplate hTemplate, HNLTemplate hValue);
#define NTemplateAddFaces(hTemplate, phFaces) NTemplateAddFacesEx(hTemplate, 0, phFaces)
N_DEPRECATED("function is deprecated, use NLTemplateCreateEx and NTemplateSetFaces instead")
NResult N_API NTemplateAddFacesEx(HNTemplate hTemplate, NUInt flags, HNLTemplate * phFaces);
N_DEPRECATED("function is deprecated, use NLTemplateCreateFromMemoryN and NTemplateSetFaces instead")
NResult N_API NTemplateAddFacesFromMemoryN(HNTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNLTemplate * phFaces);
N_DEPRECATED("function is deprecated, use NLTemplateCreateFromMemory and NTemplateSetFaces instead")
NResult N_API NTemplateAddFacesFromMemoryEx(HNTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNLTemplate * phFaces);
#define NTemplateAddFacesCopy(hTemplate, hSrcFaces, phFaces) NTemplateAddFacesCopyEx(hTemplate, hSrcFaces, 0, phFaces)
N_DEPRECATED("function is deprecated, use NObjectClone and NTemplateSetFaces instead")
NResult N_API NTemplateAddFacesCopyEx(HNTemplate hTemplate, HNLTemplate hSrcFaces, NUInt flags, HNLTemplate * phFaces);
N_DEPRECATED("function is deprecated, use NTemplateSetFaces instead")
NResult N_API NTemplateRemoveFaces(HNTemplate hTemplate);

N_DEPRECATED("function is deprecated, use NTemplateGetIrisesEx instead")
NResult N_API NTemplateGetIrises(HNTemplate hTemplate, HNETemplate * phValue);
NResult N_API NTemplateGetIrisesEx(HNTemplate hTemplate, HNETemplate * phValue);
NResult N_API NTemplateSetIrises(HNTemplate hTemplate, HNETemplate hValue);
#define NTemplateAddIrises(hTemplate, phIrises) NTemplateAddIrisesEx(hTemplate, 0, phIrises)
N_DEPRECATED("function is deprecated, use NETemplateCreateEx and NTemplateSetIrises instead")
NResult N_API NTemplateAddIrisesEx(HNTemplate hTemplate, NUInt flags, HNETemplate * phIrises);
N_DEPRECATED("function is deprecated, use NETemplateCreateFromMemoryN and NTemplateSetIrises instead")
NResult N_API NTemplateAddIrisesFromMemoryN(HNTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNETemplate * phIrises);
N_DEPRECATED("function is deprecated, use NETemplateCreateFromMemory and NTemplateSetIrises instead")
NResult N_API NTemplateAddIrisesFromMemoryEx(HNTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNETemplate * phIrises);
#define NTemplateAddIrisesCopy(hTemplate, hSrcIrises, phIrises) NTemplateAddIrisesCopyEx(hTemplate, hSrcIrises, 0, phIrises)
N_DEPRECATED("function is deprecated, use NObjectClone and NTemplateSetIrises instead")
NResult N_API NTemplateAddIrisesCopyEx(HNTemplate hTemplate, HNETemplate hSrcIrises, NUInt flags, HNETemplate * phIrises);
N_DEPRECATED("function is deprecated, use NTemplateSetIrises instead")
NResult N_API NTemplateRemoveIrises(HNTemplate hTemplate);

N_DEPRECATED("function is deprecated, use NTemplateGetPalmsEx instead")
NResult N_API NTemplateGetPalms(HNTemplate hTemplate, HNFTemplate * phValue);
NResult N_API NTemplateGetPalmsEx(HNTemplate hTemplate, HNFTemplate * phValue);
NResult N_API NTemplateSetPalms(HNTemplate hTemplate, HNFTemplate hValue);
#define NTemplateAddPalms(hTemplate, phPalms) NTemplateAddPalmsEx(hTemplate, 0, phPalms)
N_DEPRECATED("function is deprecated, use NFTemplateCreateEx and NTemplateSetPalms instead")
NResult N_API NTemplateAddPalmsEx(HNTemplate hTemplate, NUInt flags, HNFTemplate * phPalms);
N_DEPRECATED("function is deprecated, use NFTemplateCreateFromMemoryN and NTemplateSetPalms instead")
NResult N_API NTemplateAddPalmsFromMemoryN(HNTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNFTemplate * phPalms);
N_DEPRECATED("function is deprecated, use NFTemplateCreateFromMemory and NTemplateSetPalms instead")
NResult N_API NTemplateAddPalmsFromMemoryEx(HNTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNFTemplate * phPalms);
#define NTemplateAddPalmsCopy(hTemplate, hSrcPalms, phPalms) NTemplateAddPalmsCopyEx(hTemplate, hSrcPalms, 0, phPalms)
N_DEPRECATED("function is deprecated, use NObjectClone and NTemplateSetPalms instead")
NResult N_API NTemplateAddPalmsCopyEx(HNTemplate hTemplate, HNFTemplate hSrcPalms, NUInt flags, HNFTemplate * phPalms);
N_DEPRECATED("function is deprecated, use NTemplateSetPalms instead")
NResult N_API NTemplateRemovePalms(HNTemplate hTemplate);

N_DEPRECATED("function is deprecated, use NTemplateGetVoicesEx instead")
NResult N_API NTemplateGetVoices(HNTemplate hTemplate, HNSTemplate * phValue);
NResult N_API NTemplateGetVoicesEx(HNTemplate hTemplate, HNSTemplate * phValue);
NResult N_API NTemplateSetVoices(HNTemplate hTemplate, HNSTemplate hValue);
N_DEPRECATED("function is deprecated, use NSTemplateCreateEx and NTemplateSetVoices instead")
NResult N_API NTemplateAddVoices(HNTemplate hTemplate, NUInt flags, HNSTemplate * phVoices);
N_DEPRECATED("function is deprecated, use NSTemplateCreateFromMemoryN and NTemplateSetVoices instead")
NResult N_API NTemplateAddVoicesFromMemoryN(HNTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNSTemplate * phVoices);
N_DEPRECATED("function is deprecated, use NSTemplateCreateFromMemory and NTemplateSetVoices instead")
NResult N_API NTemplateAddVoicesFromMemory(HNTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNSTemplate * phVoices);
#define NTemplateAddVoicesCopy(hTemplate, hSrcVoices, phVoices) NTemplateAddVoicesCopyEx(hTemplate, hSrcVoices, 0, phVoices)
N_DEPRECATED("function is deprecated, use NObjectClone and NTemplateSetVoices instead")
NResult N_API NTemplateAddVoicesCopyEx(HNTemplate hTemplate, HNSTemplate hSrcVoices, NUInt flags, HNSTemplate * phVoices);
N_DEPRECATED("function is deprecated, use NTemplateSetVoices instead")
NResult N_API NTemplateRemoveVoices(HNTemplate hTemplate);

NResult N_API NTemplateClear(HNTemplate hTemplate);
#define NTemplateGetSize(hTemplate, flags, pValue) NObjectGetSize(hTemplate, flags, pValue)
#define NTemplateSaveToMemory(hTemplate, pBuffer, bufferSize, flags, pSize) NObjectSaveToMemoryDst(hTemplate, pBuffer, bufferSize, flags, pSize)

#define NTemplateAddFingersFromMemory(hTemplate, pBuffer, bufferSize, flags, phFingers) NTemplateAddFingersFromMemoryEx(hTemplate, pBuffer, bufferSize, flags, NULL, phFingers)
#define NTemplateAddFacesFromMemory(hTemplate, pBuffer, bufferSize, flags, phFaces) NTemplateAddFacesFromMemoryEx(hTemplate, pBuffer, bufferSize, flags, NULL, phFaces)
#define NTemplateAddIrisesFromMemory(hTemplate, pBuffer, bufferSize, flags, phIrises) NTemplateAddIrisesFromMemoryEx(hTemplate, pBuffer, bufferSize, flags, NULL, phIrises)
#define NTemplateAddPalmsFromMemory(hTemplate, pBuffer, bufferSize, flags, phPalms) NTemplateAddPalmsFromMemoryEx(hTemplate, pBuffer, bufferSize, flags, NULL, phPalms)
#define NTemplateClone(hTemplate, phClonedTemplate) NObjectClone(hTemplate, (HNObject *)phClonedTemplate)

#ifdef N_MSVC
	#pragma deprecated("NTemplateCreate")
	#pragma deprecated("NTemplateAddFingers", "NTemplateAddFaces", "NTemplateAddIrises", "NTemplateAddPalms")
	#pragma deprecated("NTemplateAddFingersFromMemory", "NTemplateAddFacesFromMemory", "NTemplateAddIrisesFromMemory", "NTemplateAddPalmsFromMemory")
	#pragma deprecated("NTemplateAddFingersCopy", "NTemplateAddFacesCopy", "NTemplateAddIrisesCopy", "NTemplateAddPalmsCopy", "NTemplateAddVoicesCopy")
	#pragma deprecated("NTemplateGetSize", "NTemplateSaveToMemory")
	#pragma deprecated("NTemplateClone")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_TEMPLATE_H_INCLUDED
