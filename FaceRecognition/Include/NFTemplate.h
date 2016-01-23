#ifndef NF_TEMPLATE_H_INCLUDED
#define NF_TEMPLATE_H_INCLUDED

#include <NFRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NFT_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NFTemplate, NObject)

NResult N_API NFTemplateCalculateSize(NBool isPalm, NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NFTemplatePack(NBool isPalm, NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NFTemplateUnpack(const void * pBuffer, NSizeType bufferSize, NBool * pIsPalm, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NFTemplateCheckN(HNBuffer hBuffer);
NResult N_API NFTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NFTemplateIsPalmMemN(HNBuffer hBuffer, NBool * pValue);
NResult N_API NFTemplateIsPalmMem(const void * pBuffer, NSizeType bufferSize, NBool * pValue);
NResult N_API NFTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NFTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NFTemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NFTemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NFT_PROCESS_FIRST_RECORD_ONLY 0x00000100

#define NFTemplateCreate(phTemplate) NFTemplateCreateEx(NFalse, 0, phTemplate)
NResult N_API NFTemplateCreateEx(NBool isPalm, NUInt flags, HNFTemplate * phTemplate);
NResult N_API NFTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNFTemplate * phTemplate);
NResult N_API NFTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNFTemplate * phTemplate);

NResult N_API NFTemplateGetRecordCount(HNFTemplate hTemplate, NInt * pValue);
N_DEPRECATED("function is deprecated, use NFTemplateGetRecordEx instead")
NResult N_API NFTemplateGetRecord(HNFTemplate hTemplate, NInt index, HNFRecord * phValue);
NResult N_API NFTemplateGetRecordEx(HNFTemplate hTemplate, NInt index, HNFRecord * phValue);
NResult N_API NFTemplateGetRecordCapacity(HNFTemplate hTemplate, NInt * pValue);
NResult N_API NFTemplateSetRecordCapacity(HNFTemplate hTemplate, NInt value);
NResult N_API NFTemplateSetRecord(HNFTemplate hTemplate, NInt index, HNFRecord hValue);
NResult N_API NFTemplateAddRecordEx(HNFTemplate hTemplate, HNFRecord hValue, NInt * pIndex);
NResult N_API NFTemplateInsertRecord(HNFTemplate hTemplate, NInt index, HNFRecord hValue);
N_DEPRECATED("function is deprecated, use NFRecordCreateEx and NFTemplateAddRecordEx instead")
NResult N_API NFTemplateAddRecord(HNFTemplate hTemplate, NUShort width, NUShort height, NUShort horzResolution, NUShort vertResolution, NUInt flags, HNFRecord * phRecord);
N_DEPRECATED("function is deprecated, use NFRecordCreateFromMemoryN and NFTemplateAddRecordEx instead")
NResult N_API NFTemplateAddRecordFromMemoryN(HNFTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNFRecord * phRecord);
N_DEPRECATED("function is deprecated, use NFRecordCreateFromMemory and NFTemplateAddRecordEx instead")
NResult N_API NFTemplateAddRecordFromMemoryEx(HNFTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNFRecord * phRecord);
#define NFTemplateAddRecordCopy(hTemplate, hSrcRecord, phRecord) NFTemplateAddRecordCopyEx(hTemplate, hSrcRecord, 0, phRecord)
N_DEPRECATED("function is deprecated, use NObjectClone and NFTemplateAddRecordEx instead")
NResult N_API NFTemplateAddRecordCopyEx(HNFTemplate hTemplate, HNFRecord hSrcRecord, NUInt flags, HNFRecord * phRecord);
NResult N_API NFTemplateRemoveRecord(HNFTemplate hTemplate, NInt index);
NResult N_API NFTemplateClearRecords(HNFTemplate hTemplate);

#define NFTemplateGetSize(hTemplate, flags, pValue) NObjectGetSize(hTemplate, flags, pValue)
#define NFTemplateSaveToMemory(hTemplate, pBuffer, bufferSize, flags, pSize) NObjectSaveToMemoryDst(hTemplate, pBuffer, bufferSize, flags, pSize)

NResult N_API NFTemplateIsPalm(HNFTemplate hTemplate, NBool * pValue);

#define NFTemplateAddRecordFromMemory(hTemplate, pBuffer, bufferSize, flags, phRecord) NFTemplateAddRecordFromMemoryEx(hTemplate, pBuffer, bufferSize, flags, NULL, phRecord)
#define NFTemplateClone(hTemplate, phClonedTemplate) NObjectClone(hTemplate, (HNObject *)phClonedTemplate)

#ifdef N_MSVC
	#pragma deprecated("NFTemplateCreate")
	#pragma deprecated("NFTemplateAddRecordFromMemory", "NFTemplateAddRecordCopy")
	#pragma deprecated("NFTemplateGetSize", "NFTemplateSaveToMemory")
	#pragma deprecated("NFTemplateClone")
#endif

#ifdef N_CPP
}
#endif

#endif // !NF_TEMPLATE_H_INCLUDED
