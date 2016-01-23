#ifndef NE_TEMPLATE_H_INCLUDED
#define NE_TEMPLATE_H_INCLUDED

#include <NERecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NET_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NETemplate, NObject)

NResult N_API NETemplateCalculateSize(NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NETemplatePack(NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NETemplateUnpack(const void * pBuffer, NSizeType bufferSize, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NETemplateCheckN(HNBuffer hBuffer);
NResult N_API NETemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NETemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NETemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NETemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NETemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NET_PROCESS_FIRST_RECORD_ONLY 0x00000100

#define NETemplateCreate(phTemplate) NETemplateCreateEx(0, phTemplate)
NResult N_API NETemplateCreateEx(NUInt flags, HNETemplate * phTemplate);
NResult N_API NETemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNETemplate * phTemplate);
NResult N_API NETemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNETemplate * phTemplate);

NResult N_API NETemplateGetRecordCount(HNETemplate hTemplate, NInt * pValue);
N_DEPRECATED("function is deprecated, use NETemplateGetRecordEx instead")
NResult N_API NETemplateGetRecord(HNETemplate hTemplate, NInt index, HNERecord * phValue);
NResult N_API NETemplateGetRecordEx(HNETemplate hTemplate, NInt index, HNERecord * phValue);
NResult N_API NETemplateGetRecordCapacity(HNETemplate hTemplate, NInt * pValue);
NResult N_API NETemplateSetRecordCapacity(HNETemplate hTemplate, NInt value);
NResult N_API NETemplateSetRecord(HNETemplate hTemplate, NInt index, HNERecord hValue);
NResult N_API NETemplateAddRecordEx(HNETemplate hTemplate, HNERecord hValue, NInt * pIndex);
NResult N_API NETemplateInsertRecord(HNETemplate hTemplate, NInt index, HNERecord hValue);
N_DEPRECATED("function is deprecated, use NERecordCreate and NETemplateAddRecordEx instead")
NResult N_API NETemplateAddRecord(HNETemplate hTemplate, NUShort width, NUShort height, NUInt flags, HNERecord * phRecord);
N_DEPRECATED("function is deprecated, use NERecordCreateFromMemoryN and NETemplateAddRecordEx instead")
NResult N_API NETemplateAddRecordFromMemoryN(HNETemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNERecord * phRecord);
N_DEPRECATED("function is deprecated, use NERecordCreateFromMemory and NETemplateAddRecordEx instead")
NResult N_API NETemplateAddRecordFromMemoryEx(HNETemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNERecord * phRecord);
#define NETemplateAddRecordCopy(hTemplate, hSrcRecord, phRecord) NETemplateAddRecordCopyEx(hTemplate, hSrcRecord, 0, phRecord)
N_DEPRECATED("function is deprecated, use NObjectClone and NETemplateAddRecordEx instead")
NResult N_API NETemplateAddRecordCopyEx(HNETemplate hTemplate, HNERecord hSrcRecord, NUInt flags, HNERecord * phRecord);
NResult N_API NETemplateRemoveRecord(HNETemplate hTemplate, NInt index);
NResult N_API NETemplateClearRecords(HNETemplate hTemplate);

#define NETemplateGetSize(hTemplate, flags, pValue) NObjectGetSize(hTemplate, flags, pValue)
#define NETemplateSaveToMemory(hTemplate, pBuffer, bufferSize, flags, pSize) NObjectSaveToMemoryDst(hTemplate, pBuffer, bufferSize, flags, pSize)

#define NETemplateAddRecordFromMemory(hTemplate, pBuffer, bufferSize, flags, phRecord) NETemplateAddRecordFromMemoryEx(hTemplate, pBuffer, bufferSize, flags, NULL, phRecord)
#define NETemplateClone(hTemplate, phClonedTemplate) NObjectClone(hTemplate, (HNObject *)phClonedTemplate)

#ifdef N_MSVC
	#pragma deprecated("NETemplateCreate")
	#pragma deprecated("NETemplateAddRecordFromMemory", "NETemplateAddRecordCopy")
	#pragma deprecated("NETemplateGetSize", "NETemplateSaveToMemory")
	#pragma deprecated("NETemplateClone")
#endif

#ifdef N_CPP
}
#endif

#endif // !NE_TEMPLATE_H_INCLUDED
