#ifndef N_OBJECT_H_INCLUDED
#define N_OBJECT_H_INCLUDED

#include <NTypes.h>
#include <NParameters.h>
#include <NString.h>
#include <NCallback.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NValue, NObject)
N_DECLARE_OBJECT_TYPE(NArray, NValue)
N_DECLARE_OBJECT_TYPE(NModule, NObject)
#ifndef N_OBJECT_HPP_INCLUDED
N_DECLARE_OBJECT_TYPE(NBuffer, NObject)
N_DECLARE_OBJECT_TYPE(NStream, NObject)
#endif

#define N_OBJECT_REF_RET 0x00000010

NResult N_API NObjectUnrefElements(HNObject * arhObjects, NInt objectCount);
NResult N_API NObjectUnrefArray(HNObject * arhObjects, NInt objectCount);
void N_API NObjectFreeElements(HNObject * arhObjects, NInt objectCount);
void N_API NObjectFreeArray(HNObject * arhObjects, NInt objectCount);

NResult N_API NObjectCopyProperties(HNObject hDstObject, HNObject hSrcObject);
#define NObjectCopyParameters(hDstObject, hSrcObject) NObjectCopyProperties(hDstObject, hSrcObject)
NResult N_API NObjectSaveManyToStream(const HNObject * arhObjects, NInt objectCount, HNStream hStream, NUInt flags);
NResult N_API NObjectSaveManyToMemoryN(const HNObject * arhObjects, NInt objectCount, NUInt flags, HNBuffer * phBuffer);
NResult N_API NObjectGetSizeMany(const HNObject * arhObjects, NInt objectCount, NUInt flags, NSizeType * pValue);
NResult N_API NObjectSaveManyToMemoryDstN(const HNObject * arhObjects, NInt objectCount, HNBuffer hBuffer, NUInt flags, NSizeType * pSize);
NResult N_API NObjectSaveManyToMemoryDst(const HNObject * arhObjects, NInt objectCount, void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize);

NResult N_API NObjectRef(HNObject hObject);
NResult N_API NObjectUnref(HNObject hObject);
NResult N_API NObjectGet(HNObject hObject, HNObject * phValue);
NResult N_API NObjectSet(HNObject hObject, HNObject * phVariable);
NResult N_API NObjectGetConcurrent(volatile HNObject * phVariable, HNObject * phValue);
NResult N_API NObjectSetConcurrent(HNObject hValue, volatile HNObject * phVariable);
NResult N_API NObjectGetElements(const HNObject * arhObjects, NInt objectCount, HNObject * arhValues, NInt valuesLength);
NResult N_API NObjectGetArray(const HNObject * arhObjects, NInt objectCount, HNObject * * parhValues, NInt * pValueCount);
void N_API NObjectFree(HNObject hObject);

NResult N_API NObjectEquals(HNObject hObject, HNObject hOtherObject, NBool * pResult);
NResult N_API NObjectCompareTo(HNObject hObject, HNObject hOtherObject, NInt * pResult);
NResult N_API NObjectGetHashCode(HNObject hObject, NInt * pValue);

NResult N_API NObjectToStringN(HNObject hObject, HNString hFormat, HNString * phValue);
NResult N_API NObjectToStringA(HNObject hObject, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NObjectToStringW(HNObject hObject, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectToString(HNObject hObject, const NChar * szFormat, HNString * phValue);
#endif
#define NObjectToString N_FUNC_AW(NObjectToString)

NResult N_API NObjectClone(HNObject hObject, HNObject * phClonedObject);
NResult N_API NObjectReset(HNObject hObject);

NResult N_API NObjectGetPropertyN(HNObject hObject, HNString hName, HNValue * phValue);
NResult N_API NObjectGetPropertyNN(HNObject hObject, HNString hName, HNType hValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectGetPropertyPA(HNObject hObject, const NAChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectGetPropertyPW(HNObject hObject, const NWChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectGetPropertyP(HNObject hObject, const NChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#define NObjectGetPropertyP N_FUNC_AW(NObjectGetPropertyP)

NResult N_API NObjectGetParameterWithPartExN(HNObject hObject, NUShort partId, NUInt parameterId, HNValue * phValue);
NResult N_API NObjectGetParameterWithPartEx(HNObject hObject, NUShort partId, NUInt parameterId, NInt typeId, void * pValue, NSizeType valueSize);
#define NObjectGetParameterExN(hObject, parameterId, phValue) NObjectGetParameterWithPartExN(hObject, 0, parameterId, phValue)
#define NObjectGetParameterEx(hObject, parameterId, typeId, pValue, valueSize) NObjectGetParameterWithPartEx(hObject, 0, parameterId, typeId, pValue, valueSize)

NResult N_API NObjectSetPropertyN(HNObject hObject, HNString hName, HNValue hValue);
NResult N_API NObjectSetPropertyNN(HNObject hObject, HNString hName, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectSetPropertyPA(HNObject hObject, const NAChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectSetPropertyPW(HNObject hObject, const NWChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectSetPropertyP(HNObject hObject, const NChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#define NObjectSetPropertyP N_FUNC_AW(NObjectSetPropertyP)

NResult N_API NObjectSetParameterWithPartExN(HNObject hObject, NUShort partId, NUInt parameterId, HNValue hValue);
NResult N_API NObjectSetParameterWithPartEx(HNObject hObject, NUShort partId, NUInt parameterId, NInt typeId, const void * pValue, NSizeType valueSize);
#define NObjectSetParameterExN(hObject, parameterId, hValue) NObjectSetParameterWithPartExN(hObject, 0, parameterId, hValue)
#define NObjectSetParameterEx(hObject, parameterId, typeId, pValue, valueSize) NObjectSetParameterWithPartEx(hObject, 0, parameterId, typeId, pValue, valueSize)

NResult N_API NObjectResetPropertyN(HNObject hObject, HNString hName);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectResetPropertyA(HNObject hObject, const NAChar * szName);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectResetPropertyW(HNObject hObject, const NWChar * szName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectResetProperty(HNObject hObject, const NChar * szName);
#endif
#define NObjectResetProperty N_FUNC_AW(NObjectResetProperty)

NResult N_API NObjectSaveToStream(HNObject hObject, HNStream hStream, NUInt flags);
NResult N_API NObjectSaveToMemoryN(HNObject hObject, NUInt flags, HNBuffer * phBuffer);
NResult N_API NObjectGetSize(HNObject hObject, NUInt flags, NSizeType * pValue);
NResult N_API NObjectSaveToMemoryDstN(HNObject hObject, HNBuffer hBuffer, NUInt flags, NSizeType * pSize);
NResult N_API NObjectSaveToMemoryDst(HNObject hObject, void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize);

NResult N_API NObjectGetType(HNObject hObject, HNType * phValue);
NResult N_API NObjectGetOwnerEx(HNObject hObject, HNObject * phValue);
NResult N_API NObjectGetOwner(HNObject hObject, HNObject * phValue);
NResult N_API NObjectGetFlags(HNObject hObject, NUInt * pValue);
NResult N_API NObjectSetFlags(HNObject hObject, NUInt value);

typedef NResult (N_CALLBACK NObjectCallback)(HNObject hObject, void * pParam);
N_DECLARE_TYPE(NObjectCallback)

typedef NResult (N_CALLBACK NObjectPropertyChangedCallback)(HNObject hObject, HNString hPropertyName, void * pParam);
N_DECLARE_TYPE(NObjectPropertyChangedCallback)

NResult N_API NObjectAddDisposed(HNObject hObject, HNCallback hCallback);
NResult N_API NObjectAddDisposedCallback(HNObject hObject, NObjectCallback pCallback, void * pParam);
NResult N_API NObjectRemoveDisposed(HNObject hObject, HNCallback hCallback);
NResult N_API NObjectRemoveDisposedCallback(HNObject hObject, NObjectCallback pCallback, void * pParam);
NResult N_API NObjectAddOwnerChanged(HNObject hObject, HNCallback hCallback);
NResult N_API NObjectAddOwnerChangedCallback(HNObject hObject, NObjectCallback pCallback, void * pParam);
NResult N_API NObjectRemoveOwnerChanged(HNObject hObject, HNCallback hCallback);
NResult N_API NObjectRemoveOwnerChangedCallback(HNObject hObject, NObjectCallback pCallback, void * pParam);
NResult N_API NObjectAddPropertyChanged(HNObject hObject, HNCallback hCallback);
NResult N_API NObjectAddPropertyChangedCallback(HNObject hObject, NObjectPropertyChangedCallback pCallback, void * pParam);
NResult N_API NObjectRemovePropertyChanged(HNObject hObject, HNCallback hCallback);
NResult N_API NObjectRemovePropertyChangedCallback(HNObject hObject, NObjectPropertyChangedCallback pCallback, void * pParam);

#define NObjectGetParameterWithPart(hObject, partId, parameterId, pValue) NObjectGetParameterWithPartEx(hObject, partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX)
#define NObjectSetParameterWithPart(hObject, partId, parameterId, pValue) NObjectSetParameterWithPartEx(hObject, partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX)
#define NObjectGetParameter(hObject, parameterId, pValue) NObjectGetParameterEx(hObject, parameterId, -1, pValue, N_SIZE_TYPE_MAX)
#define NObjectSetParameter(hObject, parameterId, pValue) NObjectSetParameterEx(hObject, parameterId, -1, pValue, N_SIZE_TYPE_MAX)

#ifdef N_MSVC
	#pragma deprecated("NObjectGetParameterWithPart", "NObjectSetParameterWithPart", "NObjectGetParameter", "NObjectSetParameter")
#endif

#ifdef N_CPP
}
#endif

#include <NType.h>
#include <NModule.h>
#include <NError.h>
#ifndef N_OBJECT_HPP_INCLUDED
#include <NBuffer.h>
#include <NStream.h>
#endif

#endif // !N_OBJECT_H_INCLUDED
