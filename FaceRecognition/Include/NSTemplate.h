#ifndef NS_TEMPLATE_H_INCLUDED
#define NS_TEMPLATE_H_INCLUDED

#include <NSRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NST_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NSTemplate, NObject)

NResult N_API NSTemplateCalculateSize(NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NSTemplatePack(NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NSTemplateUnpack(const void * pBuffer, NSizeType bufferSize, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NSTemplateCheckN(HNBuffer hBuffer);
NResult N_API NSTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NSTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NSTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NSTemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NSTemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NST_PROCESS_FIRST_RECORD_ONLY 0x00000100

#define NSTemplateCreate(phTemplate) NSTemplateCreateEx(0, phTemplate)
NResult N_API NSTemplateCreateEx(NUInt flags, HNSTemplate * phTemplate);
NResult N_API NSTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNSTemplate * phTemplate);
NResult N_API NSTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNSTemplate * phTemplate);

NResult N_API NSTemplateGetRecordCount(HNSTemplate hTemplate, NInt * pValue);
N_DEPRECATED("function is deprecated, use NSTemplateGetRecordEx instead")
NResult N_API NSTemplateGetRecord(HNSTemplate hTemplate, NInt index, HNSRecord * phValue);
NResult N_API NSTemplateGetRecordEx(HNSTemplate hTemplate, NInt index, HNSRecord * phValue);
NResult N_API NSTemplateGetRecordCapacity(HNSTemplate hTemplate, NInt * pValue);
NResult N_API NSTemplateSetRecordCapacity(HNSTemplate hTemplate, NInt value);
NResult N_API NSTemplateSetRecord(HNSTemplate hTemplate, NInt index, HNSRecord hValue);
NResult N_API NSTemplateAddRecordEx(HNSTemplate hTemplate, HNSRecord hValue, NInt * pIndex);
NResult N_API NSTemplateInsertRecord(HNSTemplate hTemplate, NInt index, HNSRecord hValue);
N_DEPRECATED("function is deprecated, use NSRecordCreate and NSTemplateAddRecordEx instead")
NResult N_API NSTemplateAddRecord(HNSTemplate hTemplate, NUInt flags, HNSRecord * phRecord);
N_DEPRECATED("function is deprecated, use NSRecordCreateFromMemoryN and NSTemplateAddRecordEx instead")
NResult N_API NSTemplateAddRecordFromMemoryN(HNSTemplate hTemplate, HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNSRecord * phRecord);
N_DEPRECATED("function is deprecated, use NSRecordCreateFromMemory and NSTemplateAddRecordEx instead")
NResult N_API NSTemplateAddRecordFromMemory(HNSTemplate hTemplate, const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNSRecord * phRecord);
#define NSTemplateAddRecordCopy(hTemplate, hSrcRecord, phRecord) NSTemplateAddRecordCopyEx(hTemplate, hSrcRecord, 0, phRecord)
N_DEPRECATED("function is deprecated, use NObjectClone and NSTemplateAddRecordEx instead")
NResult N_API NSTemplateAddRecordCopyEx(HNSTemplate hTemplate, HNSRecord hSrcRecord, NUInt flags, HNSRecord * phRecord);
NResult N_API NSTemplateRemoveRecord(HNSTemplate hTemplate, NInt index);
NResult N_API NSTemplateClearRecords(HNSTemplate hTemplate);

#define NSTemplateGetSize(hTemplate, flags, pValue) NObjectGetSize(hTemplate, flags, pValue)
#define NSTemplateSaveToMemory(hTemplate, pBuffer, bufferSize, flags, pSize) NObjectSaveToMemoryDst(hTemplate, pBuffer, bufferSize, flags, pSize)

#ifdef N_MSVC
	#pragma deprecated("NSTemplateCreate")
	#pragma deprecated("NSTemplateAddRecordCopy")
	#pragma deprecated("NSTemplateGetSize", "NSTemplateSaveToMemory")
#endif

#ifdef N_CPP
}
#endif

#endif // !NS_TEMPLATE_H_INCLUDED
