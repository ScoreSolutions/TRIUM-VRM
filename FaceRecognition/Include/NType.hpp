#include <NObject.hpp>

#ifndef N_TYPE_HPP_INCLUDED
#define N_TYPE_HPP_INCLUDED

namespace Neurotec
{
#include <NType.h>
}

namespace Neurotec
{
class N_CLASS(NType) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NType, NObject)

private:
	N_CLASS(NType)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NTypeCodeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NTypeCode), true, true);
	}

	static bool IsInstanceOfType(NTypeOfProc pTypeOf, N_CLASS(NObject) * pObject)
	{
		NBool result;
		NCheck(NTypeIsInstanceOfTypeP(pTypeOf, ToHandle(pObject), &result));
		return result != 0;
	}

	static N_CLASS(NString) IdentifierToString(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NTypeIdentifierToStringN(value.GetHandle(), format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	bool IsSubclassOf(const N_CLASS(NType) * pType) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NBool value;
		NCheck(NTypeIsSubclassOf(GetHandle(), pType->GetHandle(), &value));
		return value != 0;
	}

	bool IsAssignableFrom(const N_CLASS(NType) * pType) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NBool value;
		NCheck(NTypeIsAssignableFrom(GetHandle(), pType->GetHandle(), &value));
		return value != 0;
	}

	bool IsInstanceOfType(N_CLASS(NObject) * pObject) const
	{
		if (!pObject) NThrowArgumentNullException(N_T("pObject"));
		NBool value;
		NCheck(NTypeIsInstanceOfType(GetHandle(), pObject->GetHandle(), &value));
		return value != 0;
	}

	void Reset(N_CLASS(NObject) * pObject) const
	{
		if (!pObject) NThrowArgumentNullException(N_T("pObject"));
		NCheck(NTypeReset(GetHandle(), pObject->GetHandle()));
	}

	N_CLASS(NValue) * GetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name) const;
	bool GetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		if (!pValueType) NThrowArgumentNullException(N_T("pValueType"));
		NBool hasValue;
		NCheck(NTypeGetPropertyValueNN(GetHandle(), ToHandle(pObject), name.GetHandle(), pValueType->GetHandle(), attributes, arValues, valuesSize, valuesLength, &hasValue));
		return hasValue != 0;
	}
	template<typename T> T GetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name, NAttributes attributes = naNone, bool * pHasValue = NULL) const
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NBool hasValue;
		NCheck(NTypeGetPropertyValueNN(GetHandle(), ToHandle(pObject), name.GetHandle(), N_CLASS(NTypeTraits)<T>::GetNativeType()->GetHandle(), attributes, &value, sizeof(value), 1, pHasValue ? &hasValue : NULL));
		try
		{
			T v = N_CLASS(NTypeTraits)<T>::FromNative(value);
			if (pHasValue) *pHasValue = hasValue != 0;
			return v;
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNative(value);
			throw;
		}
	}

	NInt GetParameter(const N_CLASS(NObject) * pObject, NUShort partId, NUInt parameterId, NInt typeId, void * pValue, NSizeType valueSize) const
	{
		return NCheck(NTypeGetParameterEx(GetHandle(), ToHandle(pObject), partId, parameterId, typeId, pValue, valueSize));
	}
	N_DEPRECATED("method is deprecated, use GetParameter(const N_CLASS(NObject) *, NUShort, NUInt, NInt, void *, NSizeType) instead")
	NInt GetParameter(const N_CLASS(NObject) * pObject, NUShort partId, NUInt parameterId, void * pValue) const
	{
		return GetParameter(pObject, partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX);
	}
	template<typename T> T GetParameter(const N_CLASS(NObject) * pObject, NUShort partId, NUShort parameterId) const
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		GetParameter(pObject, partId, parameterId, N_CLASS(NTypeTraits)<T>::TypeId, &value, sizeof(value));
		try
		{
			return N_CLASS(NTypeTraits)<T>::FromNative(value);
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNative(value);
			throw;
		}
	}

	void SetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name, N_CLASS(NValue) * pValue) const;
	void SetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue = true) const
	{
		if (!pValueType) NThrowArgumentNullException(N_T("pValueType"));
		NCheck(NTypeSetPropertyValueNN(GetHandle(), ToHandle(pObject), name.GetHandle(), pValueType->GetHandle(), attributes, arValues, valuesSize, valuesLength, hasValue ? NTrue : NFalse));
	}
	template<typename T> void SetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name, const T & value, NAttributes attributes = naNone, bool hasValue = true) const
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(NTypeSetPropertyValueNN(GetHandle(), ToHandle(pObject), name.GetHandle(), N_CLASS(NTypeTraits)<T>::GetNativeType()->GetHandle(), attributes, &v, sizeof(v), 1, hasValue ? NTrue : NFalse));
	}

	void SetParameter(N_CLASS(NObject) * pObject, NUShort partId, NUShort parameterId, NInt typeId, const void * pValue, NSizeType valueSize) const
	{
		NCheck(NTypeSetParameterEx(GetHandle(), ToHandle(pObject), partId, parameterId, typeId, pValue, valueSize));
	}
	N_DEPRECATED("method is deprecated, use SetParameter(N_CLASS(NObject) *, NUShort, NUInt, NInt, const void *, NSizeType) instead")
	void SetParameter(N_CLASS(NObject) * pObject, NUShort partId, NUShort parameterId, const void * pValue) const
	{
		return SetParameter(pObject, partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX);
	}
	template<typename T> void SetParameter(N_CLASS(NObject) * pObject, NUShort partId, NUShort parameterId, const T & value) const
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		SetParameter(pObject, partId, parameterId, N_CLASS(NTypeTraits)<T>::TypeId, &v, sizeof(v));
	}

	void ResetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name) const
	{
		NCheck(NTypeResetPropertyValueN(GetHandle(), ToHandle(pObject), name.GetHandle()));
	}

	void CopyPropertyValues(N_CLASS(NObject) * pDstObject, const N_CLASS(NObject) * pSrcObject) const
	{
		if (!pDstObject) NThrowArgumentNullException(N_T("pDstObject"));
		if (!pSrcObject) NThrowArgumentNullException(N_T("pSrcObject"));
		NCheck(NTypeCopyPropertyValues(GetHandle(), pDstObject->GetHandle(), pSrcObject->GetHandle()));
	}

	void CopyParameters(N_CLASS(NObject) * pDstObject, const N_CLASS(NObject) * pSrcObject) const
	{
		return CopyPropertyValues(pDstObject, pSrcObject);
	}

	N_CLASS(NModule) * GetModule() const;

	N_CLASS(NString) GetName() const
	{
		return GetString(NTypeGetNameN);
	}

	N_CLASS(NType) * GetBaseType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NTypeGetBaseType, true, true);
	}

	NTypeCode GetTypeCode() const
	{
		NTypeCode value;
		NCheck(NTypeGetTypeCode(GetHandle(), &value));
		return value;
	}

	N_CLASS(NType) * GetRootType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NTypeGetRootType, true, true);
	}

	NTypeCode GetRootTypeCode() const
	{
		NTypeCode value;
		NCheck(NTypeGetRootTypeCode(GetHandle(), &value));
		return value;
	}

	NSizeType GetValueSize() const
	{
		NSizeType value;
		NCheck(NTypeGetValueSize(GetHandle(), &value));
		return value;
	}

	bool IsBasic() const
	{
		NBool value;
		NCheck(NTypeIsBasic(GetHandle(), &value));
		return value != 0;
	}

	bool IsPrimitive() const
	{
		NBool value;
		NCheck(NTypeIsPrimitive(GetHandle(), &value));
		return value != 0;
	}

	bool IsEnum() const
	{
		NBool value;
		NCheck(NTypeIsEnum(GetHandle(), &value));
		return value != 0;
	}

	bool IsStruct() const
	{
		NBool value;
		NCheck(NTypeIsStruct(GetHandle(), &value));
		return value != 0;
	}

	bool IsHandle() const
	{
		NBool value;
		NCheck(NTypeIsHandle(GetHandle(), &value));
		return value != 0;
	}

	bool IsCallback() const
	{
		NBool value;
		NCheck(NTypeIsCallback(GetHandle(), &value));
		return value != 0;
	}

	bool IsObject() const
	{
		NBool value;
		NCheck(NTypeIsObject(GetHandle(), &value));
		return value != 0;
	}

	bool IsDisposable() const
	{
		NBool value;
		NCheck(NTypeIsDisposable(GetHandle(), &value));
		return value != 0;
	}

	bool IsPublic() const
	{
		NBool value;
		NCheck(NTypeIsPublic(GetHandle(), &value));
		return value != 0;
	}

	bool IsStatic() const
	{
		NBool value;
		NCheck(NTypeIsStatic(GetHandle(), &value));
		return value != 0;
	}

	bool IsSealed() const
	{
		NBool value;
		NCheck(NTypeIsAbstract(GetHandle(), &value));
		return value != 0;
	}

	bool IsAbstract() const
	{
		NBool value;
		NCheck(NTypeIsAbstract(GetHandle(), &value));
		return value != 0;
	}

	bool IsDeprecated() const
	{
		NBool value;
		NCheck(NTypeIsDeprecated(GetHandle(), &value));
		return value != 0;
	}

	N_CLASS(NType) * GetUseInsteadType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NTypeGetUseInsteadType, true, true);
	}

	bool IsEquatable() const
	{
		NBool value;
		NCheck(NTypeIsEquatable(GetHandle(), &value));
		return value != 0;
	}

	bool IsComparable() const
	{
		NBool value;
		NCheck(NTypeIsComparable(GetHandle(), &value));
		return value != 0;
	}

	bool IsParsable() const
	{
		NBool value;
		NCheck(NTypeIsParsable(GetHandle(), &value));
		return value != 0;
	}

	bool IsSingNeutral() const
	{
		NBool value;
		NCheck(NTypeIsSignNeutral(GetHandle(), &value));
		return value != 0;
	}

	bool IsFlagsEnum() const
	{
		NBool value;
		NCheck(NTypeIsFlagsEnum(GetHandle(), &value));
		return value != 0;
	}

	bool IsCloneable() const
	{
		NBool value;
		NCheck(NTypeIsCloneable(GetHandle(), &value));
		return value != 0;
	}

	bool IsSerializable() const
	{
		NBool value;
		NCheck(NTypeIsSerializable(GetHandle(), &value));
		return value != 0;
	}

	bool IsMemorySerializable() const
	{
		NBool value;
		NCheck(NTypeIsMemorySerializable(GetHandle(), &value));
		return value != 0;
	}

	N_CLASS(NType) * GetOwnerType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NTypeGetOwnerType, true, true);
	}

	bool HasOwnerType() const
	{
		NBool value;
		NCheck(NTypeHasOwnerType(GetHandle(), &value));
		return value != 0;
	}

	void DisposeValue(void * pValue, NSizeType valueSize) const
	{
		NCheck(NTypeDisposeValue(GetHandle(), pValue, valueSize));
	}

	void DisposeValues(void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		NCheck(NTypeDisposeValues(GetHandle(), arValues, valuesSize, valuesLength));
	}

	void FreeValues(void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		NCheck(NTypeFreeValues(GetHandle(), arValues, valuesSize, valuesLength));
	}

	void CopyValue(const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize) const
	{
		NCheck(NTypeCopyValue(GetHandle(), pSrcValue, srcValueSize, pDstValue, dstValueSize));
	}

	void SetValue(const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize) const
	{
		NCheck(NTypeSetValue(GetHandle(), pSrcValue, srcValueSize, pDstValue, dstValueSize));
	}

	bool AreValuesEqual(const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size) const
	{
		NBool result;
		NCheck(NTypeAreValuesEqual(GetHandle(), pValue1, value1Size, pValue2, value2Size, &result));
		return result != 0;
	}

	NInt CompareValues(const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size) const
	{
		NInt result;
		NCheck(NTypeCompareValues(GetHandle(), pValue1, value1Size, pValue2, value2Size, &result));
		return result;
	}

	NInt GetValueHashCode(const void * pValue, NSizeType valueSize) const
	{
		NInt value;
		NCheck(NTypeGetValueHashCode(GetHandle(), pValue, valueSize, &value));
		return value;
	}

	N_CLASS(NString) ValueToString(const void * pValue, NSizeType valueSize, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NTypeValueToStringN(GetHandle(), pValue, valueSize, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	bool TryParseValue(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(NTypeTryParseValueN(GetHandle(), value.GetHandle(), format.GetHandle(), pValue, valueSize, &result));
		return result != 0;
	}
	bool TryParseValue(const N_CLASS(NStringWrapper) & value, void * pValue, NSizeType valueSize) { return TryParseValue(value, N_CLASS(NString)(), pValue, valueSize); }

	void ParseValue(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, void * pValue, NSizeType valueSize)
	{
		NCheck(NTypeParseValueN(GetHandle(), value.GetHandle(), format.GetHandle(), pValue, valueSize));
	}
	void ParseValue(const N_CLASS(NStringWrapper) & value, void * pValue, NSizeType valueSize) { ParseValue(value, N_CLASS(NString)(), pValue, valueSize); }
};

template<> struct N_CLASS(NTypeTraits)<NUInt8>
{
	typedef NUInt8 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NUInt8NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_BYTE;
	static NUInt8 ToNative(const NUInt8 & value) { return value; }
	static NUInt8 FromNative(NUInt8 value) { return value; }
	static void FreeNative(NUInt8 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NUInt8, NUInt8> NativeArrayType;
	NUInt8 * GetNativeArray(N_CLASS(NDummyArray)<NUInt8, NUInt8> &, NUInt8 * arValues) { return arValues; }
	void FreeNativeArray(NUInt8 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NInt8>
{
	typedef NInt8 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NInt8NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_SBYTE;
	static NInt8 ToNative(const NInt8 & value) { return value; }
	static NInt8 FromNative(NInt8 value) { return value; }
	static void FreeNative(NInt8 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NInt8,NInt8> NativeArrayType;
	NInt8 * GetNativeArray(N_CLASS(NDummyArray)<NInt8, NInt8> &, NInt8 * arValues) { return arValues; }
	void FreeNativeArray(NInt8 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NUInt16>
{
	typedef NUInt16 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NUInt16NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_USHORT;
	static NUInt16 ToNative(const NUInt16 & value) { return value; }
	static NUInt16 FromNative(NUInt16 value) { return value; }
	static void FreeNative(NUInt16 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NUInt16, NUInt16> NativeArrayType;
	NUInt16 * GetNativeArray(N_CLASS(NDummyArray)<NUInt16, NUInt16> &, NUInt16 * arValues) { return arValues; }
	void FreeNativeArray(NUInt16 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NInt16>
{
	typedef NInt16 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NInt16NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_SHORT;
	static NInt16 ToNative(const NInt16 & value) { return value; }
	static NInt16 FromNative(NInt16 value) { return value; }
	static void FreeNative(NInt16 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NInt16, NInt16> NativeArrayType;
	NInt16 * GetNativeArray(N_CLASS(NDummyArray)<NInt16, NInt16> &, NInt16 * arValues) { return arValues; }
	void FreeNativeArray(NInt16 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NUInt32>
{
	typedef NUInt32 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NUInt32NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_UINT;
	static NUInt32 ToNative(const NUInt32 & value) { return value; }
	static NUInt32 FromNative(NUInt32 value) { return value; }
	static void FreeNative(NUInt32 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NUInt32, NUInt32> NativeArrayType;
	NUInt32 * GetNativeArray(N_CLASS(NDummyArray)<NUInt32, NUInt32> &, NUInt32 * arValues) { return arValues; }
	void FreeNativeArray(NUInt32 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NInt32>
{
	typedef NInt32 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NInt32NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_INT;
	static NInt32 ToNative(const NInt32 & value) { return value; }
	static NInt32 FromNative(NInt32 value) { return value; }
	static void FreeNative(NInt32 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NInt32, NInt32> NativeArrayType;
	NInt32 * GetNativeArray(N_CLASS(NDummyArray)<NInt32, NInt32> &, NInt32 * arValues) { return arValues; }
	void FreeNativeArray(NInt32 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NUInt64>
{
	typedef NUInt64 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NUInt64NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_ULONG;
	static NUInt64 ToNative(const NUInt64 & value) { return value; }
	static NUInt64 FromNative(NUInt64 value) { return value; }
	static void FreeNative(NUInt64 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NUInt64, NUInt64> NativeArrayType;
	NUInt64 * GetNativeArray(N_CLASS(NDummyArray)<NUInt64, NUInt64> &, NUInt64 * arValues) { return arValues; }
	void FreeNativeArray(NUInt64 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NInt64>
{
	typedef NInt64 NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NInt64NativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_LONG;
	static NInt64 ToNative(const NInt64 & value) { return value; }
	static NInt64 FromNative(NInt64 value) { return value; }
	static void FreeNative(NInt64 value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NInt64, NInt64> NativeArrayType;
	NInt64 * GetNativeArray(N_CLASS(NDummyArray)<NInt64, NInt64> &, NInt64 * arValues) { return arValues; }
	void FreeNativeArray(NInt64 * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NSingle>
{
	typedef NSingle NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NSingleNativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_FLOAT;
	static NSingle ToNative(const NSingle & value) { return value; }
	static NSingle FromNative(NSingle value) { return value; }
	static void FreeNative(NSingle value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NSingle, NSingle> NativeArrayType;
	NSingle * GetNativeArray(N_CLASS(NDummyArray)<NSingle, NSingle> &, NSingle * arValues) { return arValues; }
	void FreeNativeArray(NSingle * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<NDouble>
{
	typedef NDouble NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NDoubleNativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_DOUBLE;
	static NDouble ToNative(const NDouble & value) { return value; }
	static NDouble FromNative(NDouble value) { return value; }
	static void FreeNative(NDouble value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<NDouble, NDouble> NativeArrayType;
	NDouble * GetNativeArray(N_CLASS(NDummyArray)<NDouble, NDouble> &, NDouble * arValues) { return arValues; }
	void FreeNativeArray(NDouble * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<bool>
{
	typedef NBoolean NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NBooleanNativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_BOOL;
	static NativeType ToNative(const bool & value) { return value ? NTrue : NFalse; }
	static bool FromNative(NBoolean value) { return value != 0; }
	static void FreeNative(NBoolean value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NBooleanArray) NativeArrayType;
	NBoolean * GetNativeArray(N_CLASS(NBooleanArray) & nativeArray, bool *) { return nativeArray.GetPtr(); }
	void FreeNativeArray(NBoolean * arValues, NInt) { NFree(arValues); }
};

template<> struct N_CLASS(NTypeTraits)<N_CLASS(NString)>
{
	typedef HNString NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NStringNativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_STRING;
	static HNString ToNative(const N_CLASS(NString) & value) { return value.GetHandle(); }
	static N_CLASS(NString) FromNative(HNString value) { return N_CLASS(NString)(value, true); }
	static void FreeNative(HNString value) { NStringFree(value); }
	typedef N_CLASS(NDummyArray)<N_CLASS(NString), HNString> NativeArrayType;
	HNString * GetNativeArray(N_CLASS(NDummyArray)<N_CLASS(NString), HNString> &, N_CLASS(NString) * arValues) { return reinterpret_cast<HNString *>(arValues); }
	void FreeNativeArray(HNString * arhValues, NInt count) { NStringFreeArray(arhValues, count); }
};

template<> struct N_CLASS(NTypeTraits)<N_CLASS(NStringWrapper)>
{
	typedef HNString NativeType;
	static N_CLASS(NType) * GetNativeType() { return N_CLASS(NTypes)::NStringNativeTypeOf(); }
	static const NUShort TypeId = N_TYPE_STRING;
	static HNString ToNative(const N_CLASS(NStringWrapper) & value) { return value.GetHandle(); }
	static N_CLASS(NString) FromNative(HNString value) { return N_CLASS(NString)(value, true); }
	static void FreeNative(HNString value) { NStringFree(value); }
	typedef N_CLASS(NDummyArray)<N_CLASS(NString), HNString> NativeArrayType;
	HNString * GetNativeArray(N_CLASS(NDummyArray)<N_CLASS(NString), HNString> & nativeArray, N_CLASS(NStringWrapper) *) { return nativeArray.GetPtr(); }
	void FreeNativeArray(HNString * arhValues, NInt count) { NStringFreeArray(arhValues, count); }
};

template<typename T> struct N_CLASS(NTypeTraits)<T *>
{
	typedef typename T::HandleType NativeType;
	static N_CLASS(NType) * GetNativeType() { return T::NativeTypeOf(); }
	static const NUShort TypeId = 0;
	static typename T::HandleType ToNative(T * const & value) { return N_CLASS(NObject)::ToHandle(value); }
	static T * FromNative(typename T::HandleType value) { return N_CLASS(NObject)::FromHandle<T>(value); }
	static void FreeNative(typename T::HandleType value) { N_CLASS(NObject)::Unref(value); }
	typedef N_CLASS(NObjectArray)<T> NativeArrayType;
	typename T::HandleType * GetNativeArray(N_CLASS(NObjectArray)<T> & nativeArray, T * *) { return nativeArray.GetPtr(); }
	void FreeNativeArray(typename T::HandleType * arhValues, NInt count) { NCheck(NObjectUnrefArray(reinterpret_cast<HNObject *>(arhValues), count)); }
};

}

#include <NValue.hpp>
#include <NModule.hpp>

namespace Neurotec
{

inline N_CLASS(NModule) * N_CLASS(NType)::GetModule() const
{
	return GetObject<HandleType, N_CLASS(NModule)>(NTypeGetModule, true, true);
}

inline N_CLASS(NValue) * N_CLASS(NType)::GetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name) const
{
	HNValue hValue;
	NCheck(NTypeGetPropertyValueN(GetHandle(), ToHandle(pObject), name.GetHandle(), &hValue));
	try
	{
		return FromHandle<N_CLASS(NValue)>(hValue);
	}
	catch (...)
	{
		Unref(hValue);
		throw;
	}
}

inline void N_CLASS(NType)::SetPropertyValue(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) & name, N_CLASS(NValue) * pValue) const
{
	NCheck(NTypeSetPropertyValueN(GetHandle(), ToHandle(pObject), name.GetHandle(), ToHandle(pValue)));
}

}

#endif // !N_TYPE_HPP_INCLUDED
