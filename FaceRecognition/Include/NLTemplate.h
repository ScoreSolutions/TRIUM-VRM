#ifndef NL_TEMPLATE_H_INCLUDED
#define NL_TEMPLATE_H_INCLUDED

#include <NLRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NLT_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NLTemplate, NObject)

NResult N_API NLTemplateCalculateSize(NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NLTemplatePack(NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NLTemplateUnpack(const void * pBuffer, NSizeType bufferSize, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NLTemplateCheckN(HNBuffer hBuffer);
NResult N_API NLTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NLTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NLTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NLTemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NLTemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NLT_PROCESS_FIRST_RECORD_ONLY 0x00000100

#define NLTemplateCreate(phTemplate) NLTemplateCreateEx(0, phTemplate)
NResult N_API NLTemplateCreateEx(NUInt flags, HNLTemplate * phTemplate);
NResult N_API NLTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNLTemplate * phTemplate);
NResult N_API NLTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNLTemplate * phTemplate);

NResult N_API NLTemplateGetRecordCount(HNLTemplate hTemplate, NInt * pValue);
N_DEPRECATED("function is deprecated, use NLTemplateGetRecordEx instead")
NResult N_API NLTemplateGetRecord(HNLTemplate hTemplate, NInt index, HNLRecord * phValue);
NResult N_API NLTemplateGetRecordEx(HNLTemplate hTemplate, NInt index, HNLRecord * phValue);
NResult N_API NLTemplateGetRecordCapacity(HNLTemplate hTemplate, NInt * pValue);
NResult N_API NLTemplateSetRecordCapacity(HNLTemplate hTemplate, NInt value);
NResult N_API NLTemplateSetRecord(HNLTemplate hTemplate, NInt index, HNLRecord hValue);
NResult N_API NLTemplateAddRecordEx(HNLTemplate hTemplate, HNLRecord hValue, NInt * pIndex);
NResult N_API NLTemplateInsertRecord(HNLTemplate hTemplate, NInt index, HNLRecord hValue);
N_DEPRECATED("function is deprecated, use NLRecordCreate and NLTemplateAddRecordEx instead")
NResult N_API NLTemplateAddRecord(HNLTemplate hTemplate, NUInt flags, HNLRecord * phRecord);
N_DEPRECATED("function is deprecated, use NLRecordCreateFromMemoryN and NLTemplateAddRecordEx instead")
NResult N_API NLTemplateAddRecordFromMemoryN(HNLTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNLRecord * phRecord);
N_DEPRECATED("function is deprecated, use NLRecordCreateFromMemory and NLTemplateAddRecordEx instead")
NResult N_API NLTemplateAddRecordFromMemoryEx(HNLTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNLRecord * phRecord);
#define NLTemplateAddRecordCopy(hTemplate, hSrcRecord, phRecord) NLTemplateAddRecordCopyEx(hTemplate, hSrcRecord, 0, phRecord)
N_DEPRECATED("function is deprecated, use NObjectClone and NLTemplateAddRecordEx instead")
NResult N_API NLTemplateAddRecordCopyEx(HNLTemplate hTemplate, HNLRecord hSrcRecord, NUInt flags, HNLRecord * phRecord);
NResult N_API NLTemplateRemoveRecord(HNLTemplate hTemplate, NInt index);
NResult N_API NLTemplateClearRecords(HNLTemplate hTemplate);

#define NLTemplateGetSize(hTemplate, flags, pValue) NObjectGetSize(hTemplate, flags, pValue)
#define NLTemplateSaveToMemory(hTemplate, pBuffer, bufferSize, flags, pSize) NObjectSaveToMemoryDst(hTemplate, pBuffer, bufferSize, flags, pSize)

#define NLTemplateAddRecordFromMemory(hTemplate, pBuffer, bufferSize, flags, phRecord) NLTemplateAddRecordFromMemoryEx(hTemplate, pBuffer, bufferSize, flags, NULL, phRecord)
#define NLTemplateClone(hTemplate, phClonedTemplate) NObjectClone(hTemplate, (HNObject *)phClonedTemplate)

#ifdef N_MSVC
	#pragma deprecated("NLTemplateCreate")
	#pragma deprecated("NLTemplateAddRecordFromMemory", "NLTemplateAddRecordCopy")
	#pragma deprecated("NLTemplateGetSize", "NLTemplateSaveToMemory")
	#pragma deprecated("NLTemplateClone")
#endif

#ifdef N_CPP
}
#endif

#endif // !NL_TEMPLATE_H_INCLUDED
