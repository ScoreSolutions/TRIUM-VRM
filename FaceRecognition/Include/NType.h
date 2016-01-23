#ifndef N_TYPE_H_INCLUDED
#define N_TYPE_H_INCLUDED

#include <NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NTypeCode_
{
	ntcNone = 0,
	ntcOther = 1,
	ntcByte = 2,
	ntcSByte = 3,
	ntcUInt16 = 4,
	ntcInt16 = 5,
	ntcUInt32 = 6,
	ntcInt32 = 7,
	ntcUInt64 = 8,
	ntcInt64 = 9,
	ntcSingle = 10,
	ntcDouble = 11,
	ntcBoolean = 12,
	ntcSizeType = 13,
	ntcSSizeType = 14,
	ntcPointer = 15,
	ntcResult = 16,
	ntcAChar = 17,
#ifndef N_NO_UNICODE
	ntcWChar = 18,
#endif
#ifdef N_UNICODE
	ntcChar = ntcWChar,
#else
	ntcChar = ntcAChar,
#endif
	ntcString = 19,
	ntcObject = 20,
	ntcValue = 21,
	ntcArray = 22,
	ntcTimeSpan = 23,
	ntcDateTime = 24,
	ntcURational = 25,
	ntcRational = 26,
	ntcComplex = 27,
	ntcGuid = 28,
	ntcBuffer = 29,
} NTypeCode;

N_DECLARE_TYPE(NTypeCode)

NResult N_API NTypeIsSubclassOf(HNType hType, HNType hOtherType, NBool * pValue);
NResult N_API NTypeIsAssignableFrom(HNType hType, HNType hOtherType, NBool * pValue);
NResult N_API NTypeIsInstanceOfType(HNType hType, HNObject hObject, NBool * pValue);
NResult N_API NTypeIsInstanceOfTypeP(NTypeOfProc pTypeOf, HNObject hObject, NBool * pValue);
NResult N_API NTypeReset(HNType hType, HNObject hObject);

NResult N_API NTypeGetPropertyValueN(HNType hType, HNObject hObject, HNString hName, HNValue * phValue);
NResult N_API NTypeGetPropertyValueNN(HNType hType, HNObject hObject, HNString hName, HNType hValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetPropertyValuePA(HNType hType, HNObject hObject, const NAChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetPropertyValuePW(HNType hType, HNObject hObject, const NWChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetPropertyValueP(HNType hType, HNObject hObject, const NChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#define NTypeGetPropertyValueP N_FUNC_AW(NTypeGetPropertyValueP)

NResult N_API NTypeGetParameterExN(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, HNValue * phValue);
NResult N_API NTypeGetParameterEx(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, NInt typeId, void * pValue, NSizeType valueSize);

NResult N_API NTypeSetPropertyValueN(HNType hType, HNObject hObject, HNString hName, HNValue hValue);
NResult N_API NTypeSetPropertyValueNN(HNType hType, HNObject hObject, HNString hName, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeSetPropertyValuePA(HNType hType, HNObject hObject, const NAChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeSetPropertyValuePW(HNType hType, HNObject hObject, const NWChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeSetPropertyValueP(HNType hType, HNObject hObject, const NChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#define NTypeSetPropertyValueP N_FUNC_AW(NTypeSetPropertyValueP)

NResult N_API NTypeSetParameterExN(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, HNValue hValue);
NResult N_API NTypeSetParameterEx(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, NInt typeId, const void * pValue, NSizeType valueSize);

NResult N_API NTypeResetPropertyValueN(HNType hType, HNObject hObject, HNString hName);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeResetPropertyValueA(HNType hType, HNObject hObject, const NAChar * szName);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeResetPropertyValueW(HNType hType, HNObject hObject, const NWChar * szName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeResetPropertyValue(HNType hType, HNObject hObject, const NChar * szName);
#endif
#define NTypeResetPropertyValueP N_FUNC_AW(NTypeResetPropertyValue)

NResult N_API NTypeCopyPropertyValues(HNType hType, HNObject hDstObject, HNObject hSrcObject);
#define NTypeCopyParameters(hType, hDstObject, hSrcObject) NTypeCopyPropertyValues(hType, hDstObject, hSrcObject)

NResult N_API NTypeGetModule(HNType hType, HNModule * phValue);

NResult N_API NTypeGetNameN(HNType hType, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetNameExA(HNType hType, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetNameExW(HNType hType, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetNameEx(HNType hType, NChar * szValue, NInt valueSize);
#endif
#define NTypeGetNameEx N_FUNC_AW(NTypeGetNameEx)

NResult N_API NTypeGetBaseType(HNType hType, HNType * phValue);
NResult N_API NTypeGetTypeCode(HNType hType, NTypeCode * pValue);
NResult N_API NTypeGetRootType(HNType hType, HNType * phValue);
NResult N_API NTypeGetRootTypeCode(HNType hType, NTypeCode * pValue);
NResult N_API NTypeGetValueSize(HNType hType, NSizeType * pValue);
NResult N_API NTypeIsBasic(HNType hType, NBool * pValue);
NResult N_API NTypeIsPrimitive(HNType hType, NBool * pValue);
NResult N_API NTypeIsEnum(HNType hType, NBool * pValue);
NResult N_API NTypeIsStruct(HNType hType, NBool * pValue);
NResult N_API NTypeIsCallback(HNType hType, NBool * pValue);
NResult N_API NTypeIsHandle(HNType hType, NBool * pValue);
NResult N_API NTypeIsObject(HNType hType, NBool * pValue);
NResult N_API NTypeIsDisposable(HNType hType, NBool * pValue);
NResult N_API NTypeIsPublic(HNType hType, NBool * pValue);
NResult N_API NTypeIsStatic(HNType hType, NBool * pValue);
NResult N_API NTypeIsSealed(HNType hType, NBool * pValue);
NResult N_API NTypeIsAbstract(HNType hType, NBool * pValue);
NResult N_API NTypeIsDeprecated(HNType hType, NBool * pValue);
NResult N_API NTypeGetUseInsteadType(HNType hType, HNType * phValue);
NResult N_API NTypeIsEquatable(HNType hType, NBool * pValue);
NResult N_API NTypeIsComparable(HNType hType, NBool * pValue);
NResult N_API NTypeIsParsable(HNType hType, NBool * pValue);
NResult N_API NTypeIsSignNeutral(HNType hType, NBool * pValue);
NResult N_API NTypeIsFlagsEnum(HNType hType, NBool * pValue);
NResult N_API NTypeIsCloneable(HNType hType, NBool * pValue);
NResult N_API NTypeIsSerializable(HNType hType, NBool * pValue);
NResult N_API NTypeIsMemorySerializable(HNType hType, NBool * pValue);
NResult N_API NTypeGetOwnerType(HNType hType, HNType * phValue);
NResult N_API NTypeHasOwnerType(HNType hType, NBool * pValue);
NResult N_API NTypeDisposeValue(HNType hType, void * pValue, NSizeType valueSize);
NResult N_API NTypeDisposeValues(HNType hType, void * arValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NTypeFreeValues(HNType hType, void * arValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NTypeCopyValue(HNType hType, const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize);
NResult N_API NTypeSetValue(HNType hType, const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize);
NResult N_API NTypeAreValuesEqual(HNType hType, const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size, NBool * pResult);
NResult N_API NTypeCompareValues(HNType hType, const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size, NInt * pResult);
NResult N_API NTypeGetValueHashCode(HNType hType, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NTypeValueToStringN(HNType hType, const void * pValue, NSizeType valueSize, HNString hFormat, HNString * phValue);
NResult N_API NTypeValueToStringA(HNType hType, const void * pValue, NSizeType valueSize, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NTypeValueToStringW(HNType hType, const void * pValue, NSizeType valueSize, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeValueToString(HNType hType, const void * pValue, NSizeType valueSize, const NChar * szFormat, HNString * phValue);
#endif
#define NTypeValueToString N_FUNC_AW(NTypeValueToString)

NResult N_API NTypeTryParseValueN(HNType hType, HNString hValue, HNString hFormat, void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NTypeTryParseValueVNA(HNType hType, HNString hValue, const NAChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NTypeTryParseValueVNW(HNType hType, HNString hValue, const NWChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeTryParseValueVN(HNType hType, HNString hValue, const NChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#define NTypeTryParseValueVN N_FUNC_AW(NTypeTryParseValueVN)

NResult N_API NTypeTryParseValueA(HNType hType, const NAChar * szValue, const NAChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NTypeTryParseValueW(HNType hType, const NWChar * szValue, const NWChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeTryParseValue(HNType hType, const NChar * szValue, const NChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#define NTypeTryParseValue N_FUNC_AW(NTypeTryParseValue)

NResult N_API NTypeParseValueN(HNType hType, HNString hValue, HNString hFormat, void * pValue, NSizeType valueSize);
NResult N_API NTypeParseValueVNA(HNType hType, HNString hValue, const NAChar * szFormat, void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NTypeParseValueVNW(HNType hType, HNString hValue, const NWChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeParseValueVN(HNType hType, HNString hValue, const NChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#define NTypeParseValueVN N_FUNC_AW(NTypeParseValueVN)

NResult N_API NTypeParseValueA(HNType hType, const NAChar * szValue, const NAChar * szFormat, void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NTypeParseValueW(HNType hType, const NWChar * szValue, const NWChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeParseValue(HNType hType, const NChar * szValue, const NChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#define NTypeParseValue N_FUNC_AW(NTypeParseValue)

NResult N_API NTypeIdentifierToStringN(HNString hValue, HNString hFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeIdentifierToStringVNA(HNString hValue, const NAChar * szFormat, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeIdentifierToStringVNW(HNString hValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeIdentifierToStringVN(HNString hValue, const NChar * szFormat, HNString * phValue);
#endif
#define NTypeIdentifierToStringVN N_FUNC_AW(NTypeIdentifierToStringVN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeIdentifierToStringFNA(const NAChar * szValue, HNString hFormat, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeIdentifierToStringFNW(const NWChar * szValue, HNString hFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeIdentifierToStringFN(const NChar * szValue, HNString hFormat, HNString * phValue);
#endif
#define NTypeIdentifierToStringFN N_FUNC_AW(NTypeIdentifierToStringFN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeIdentifierToStringA(const NAChar * szValue, const NAChar * szFormat, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeIdentifierToStringW(const NWChar * szValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeIdentifierToString(const NChar * szValue, const NChar * szFormat, HNString * phValue);
#endif
#define NTypeIdentifierToString N_FUNC_AW(NTypeIdentifierToString)

#define NTypeGetNameA(hType, pValue) NTypeGetNameExA(hType, pValue, N_INT_MAX)
#define NTypeGetNameW(hType, pValue) NTypeGetNameExW(hType, pValue, N_INT_MAX)
#define NTypeGetName(hType, pValue) NTypeGetNameEx(hType, pValue, N_INT_MAX)
#define NTypeGetParameter(hType, hObject, partId, parameterId, pValue) NTypeGetParameterEx(hType, hObject, partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX)
#define NTypeSetParameter(hType, hObject, partId, parameterId, pValue) NTypeSetParameterEx(hType, hObject, partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX)

#ifdef N_MSVC
	#pragma deprecated("NTypeGetNameA", "NTypeGetNameW", "NTypeGetName", "NTypeGetParameter", "NTypeSetParameter")
#endif

#ifdef N_CPP
}
#endif

#include <NValue.h>
#include <NModule.h>

#endif // !N_TYPE_H_INCLUDED
