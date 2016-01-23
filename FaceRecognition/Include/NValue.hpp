#ifndef N_VALUE_HPP_INCLUDED
#define N_VALUE_HPP_INCLUDED

#include <NType.hpp>
namespace Neurotec
{
#include <NValue.h>
}

namespace Neurotec
{

class N_CLASS(NValue) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NValue, NObject)

private:
	static HNValue Create(const void * value, N_CLASS(NTypes)::PointerFreeProc pFree, void * pFreeParam,
		N_CLASS(NTypes)::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, N_CLASS(NTypes)::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes);

	static HNValue Create(NByte value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromByte(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NSByte value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSByte(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NUShort value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromUInt16(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NShort value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromInt16(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NUInt value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromUInt32(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NInt value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromInt32(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NULong value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromUInt64(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NLong value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromInt64(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NFloat value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSingle(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NDouble value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromDouble(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(bool value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromBoolean(value ? NTrue : NFalse, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(const void * value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromPointer(value, attributes, &hValue));
		return hValue;
	}

	static N_CLASS(NValue) * FromObject(N_CLASS(NType) * pType, N_CLASS(NObject) * pValue, NAttributes attributes, bool autoAttributes)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		if (autoAttributes && pValue != NULL && (pValue->state & N_CLASS(NObject)::nosRegistered) == N_CLASS(NObject)::nosRegistered) attributes = (NAttributes)(attributes | naCache);
		HNValue hValue;
		NCheck(NValueCreateFromObject(pType->GetHandle(), ToHandle(pValue), attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

protected:
	N_CLASS(NValue)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NValue) * FromValue(N_CLASS(NType) * pType, const void * pValue, NSizeType valueSize, bool hasValue = true, NAttributes attributes = naNone)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		HNValue hValue;
		NCheck(NValueCreate(pType->GetHandle(), pValue, valueSize, hasValue ? NTrue : NFalse, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NValue) * FromSizeType(NSizeType value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSizeType(value, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NValue) * FromSSizeType(NSSizeType value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSSizeType(value, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NValue) * FromResult(NResult value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromResult(value, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NValue) * FromChar(NChar value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromChar(value, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NValue) * FromString(const N_CLASS(NStringWrapper) & value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromStringN(value.GetHandle(), attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NValue) * FromObject(N_CLASS(NType) * pType, N_CLASS(NObject) * pValue)
	{
		return FromObject(pType, pValue, naNone, true);
	}

	static N_CLASS(NValue) * FromObject(N_CLASS(NType) * pType, N_CLASS(NObject) * pValue, NAttributes attributes)
	{
		return FromObject(pType, pValue, attributes, false);
	}

	static void Set(N_CLASS(NValue) * pVal, N_CLASS(NType) * pType, NAttributes attributes, void * pValue, NSizeType valueSize, bool * pHasValue = NULL)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NBool hasValue = pHasValue != NULL && *pHasValue ? NTrue : NFalse;
		NCheck(NValueSet(ToHandle(pVal), pType->GetHandle(), attributes, pValue, valueSize, pHasValue ? &hasValue : NULL));
	}

	static N_CLASS(NValue) * ChangeType(N_CLASS(NValue) * pSrcValue, N_CLASS(NType) * pType, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		HNValue hValue;
		NCheck(NValueChangeType(ToHandle(pSrcValue), pType->GetHandle(), attributes, format.GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	N_CLASS(NValue)(void * value, N_CLASS(NTypes)::PointerFreeProc pFree, void * pFreeParam,
		N_CLASS(NTypes)::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, N_CLASS(NTypes)::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, pFree, pFreeParam, pGetHashCode, pGetHashCodeParam, pEquals, pEqualsParam, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NByte value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NSByte value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NUShort value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NShort value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NUInt value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NInt value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NULong value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NLong value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NFloat value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(NDouble value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(bool value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	explicit N_CLASS(NValue)(const void * value, NAttributes attributes = naNone)
		: N_CLASS(NObject)(Create(value, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NValue);
	}

	N_CLASS(NType) * GetValueType() const
	{
		HNType hValue;
		NCheck(NValueGetValueType(GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NType)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	NAttributes GetAttributes() const
	{
		NAttributes value;
		NCheck(NValueGetAttributes(GetHandle(), &value));
		return value;
	}

	N_CLASS(NCallback) GetFree() const
	{
		HNCallback hValue;
		NCheck(NValueGetFree(GetHandle(), &hValue));
		return N_CLASS(NCallback)(hValue, true);
	}

	N_CLASS(NTypes)::PointerFreeProc GetFreeProc(void * * ppParam) const;

	const void * GetPtr() const
	{
		const void * value;
		NCheck(NValueGetPtr(GetHandle(), &value));
		return value;
	}

	NSizeType GetSize() const
	{
		NSizeType value;
		NCheck(NValueGetSize(GetHandle(), &value));
		return value;
	}

	NTypeCode GetTypeCode() const
	{
		NTypeCode value;
		NCheck(NValueGetTypeCode(GetHandle(), &value));
		return value;
	}

	void ToValue(N_CLASS(NType) * pType, NAttributes attributes, const N_CLASS(NStringWrapper) & format, void * pResult, NSizeType resultSize) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(NValueToValue(GetHandle(), pType->GetHandle(), attributes, format.GetHandle(), pResult, resultSize));
	}
	void ToValue(N_CLASS(NType) * pType, NAttributes attributes, void * pResult, NSizeType resultSize) const { return ToValue(pType, attributes, N_CLASS(NString)(), pResult, resultSize); }
	void ToValue(N_CLASS(NType) * pType, void * pResult, NSizeType resultSize) const { return ToValue(pType, naNone, N_CLASS(NString)(), pResult, resultSize); }

	NByte ToByte(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NByte value;
		NCheck(NValueToByte(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NSByte ToSByte(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NSByte value;
		NCheck(NValueToSByte(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NUShort ToUInt16(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NUShort value;
		NCheck(NValueToUInt16(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NShort ToInt16(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NShort value;
		NCheck(NValueToInt16(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NUInt ToUInt32(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NUInt value;
		NCheck(NValueToUInt32(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NInt ToInt32(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NInt value;
		NCheck(NValueToInt32(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NULong ToUInt64(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NULong value;
		NCheck(NValueToUInt64(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NLong ToInt64(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NLong value;
		NCheck(NValueToInt64(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NFloat ToSingle(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NFloat value;
		NCheck(NValueToSingle(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NDouble ToDouble(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NDouble value;
		NCheck(NValueToDouble(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	bool ToBoolean(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NBool value;
		NCheck(NValueToBoolean(GetHandle(), attributes, format.GetHandle(), &value));
		return value != 0;
	}

	NSizeType ToSizeType(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NSizeType value;
		NCheck(NValueToSizeType(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NSSizeType ToSSizeType(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NSSizeType value;
		NCheck(NValueToSSizeType(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	void * ToPointer(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		void * value;
		NCheck(NValueToPointer(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NResult ToResult(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NResult value;
		NCheck(NValueToResult(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NChar ToChar(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NChar value;
		NCheck(NValueToChar(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	N_CLASS(NString) ToString(NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NValueToString(GetHandle(), attributes, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	N_CLASS(NObject) * ToObject(N_CLASS(NType) * pType, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		HNObject hValue;
		NCheck(NValueToObject(GetHandle(), pType->GetHandle(), attributes, format.GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NObject)>(hValue, true, (attributes & naCache) == naCache);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}
};

class N_CLASS(NKeyValuePair) : public NKeyValuePair_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NKeyValuePair)

public:
	N_CLASS(NKeyValuePair)(N_CLASS(NValue) * pKey, N_CLASS(NValue) * pValue)
	{
		NCheck(NKeyValuePairCreate(N_CLASS(NObject)::ToHandle(pKey), N_CLASS(NObject)::ToHandle(pValue), this));
	}

	N_CLASS(NValue) * GetKey() const
	{
		HNValue hKey;
		NCheck(NObjectGet(this->hKey, (HNObject *)&hKey));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NValue)>(hKey, true, false);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hKey);
			throw;
		}
	}

	void SetKey(N_CLASS(NValue) * pValue)
	{
		NCheck(NObjectSet(N_CLASS(NObject)::ToHandle(pValue), (HNObject *)&hKey));
	}

	N_CLASS(NValue) * GetValue() const
	{
		HNValue hValue;
		NCheck(NObjectGet(this->hValue, (HNObject *)&hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	void SetValue(N_CLASS(NValue) * pValue)
	{
		NCheck(NObjectSet(N_CLASS(NObject)::ToHandle(pValue), (HNObject *)&hValue));
	}
};
N_TYPEDEF_TYPE(NKeyValuePair)

class N_CLASS(NNameValuePair) : public NNameValuePair_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NNameValuePair)

public:
	N_CLASS(NNameValuePair)(const N_CLASS(NStringWrapper) & key, N_CLASS(NValue) * pValue)
	{
		NCheck(NNameValuePairCreateN(key.GetHandle(), N_CLASS(NObject)::ToHandle(pValue), this));
	}

	N_CLASS(NString) GetKey() const
	{
		return N_CLASS(NString)(hKey, false);
	}

	void SetName(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hKey));
	}

	N_CLASS(NValue) * GetValue() const
	{
		HNValue hValue;
		NCheck(NObjectGet(this->hValue, (HNObject *)&hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NValue)>(hValue, true, false);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	void SetValue(N_CLASS(NValue) * pValue)
	{
		NCheck(NObjectSet(N_CLASS(NObject)::ToHandle(pValue), (HNObject *)&hValue));
	}
};
N_TYPEDEF_TYPE(NNameValuePair)

}

#include <NCore.hpp>

namespace Neurotec
{

inline HNValue N_CLASS(NValue)::Create(const void * value, N_CLASS(NTypes)::PointerFreeProc pFree, void * pFreeParam,
		N_CLASS(NTypes)::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, N_CLASS(NTypes)::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes)
{
	N_CLASS(NCallback) free = N_CLASS(NTypes)::CreateCallback(N_CLASS(NTypes)::PointerFreeProcImpl, pFree, pFreeParam);
	N_CLASS(NCallback) getHashCode = N_CLASS(NTypes)::CreateCallback(N_CLASS(NTypes)::PointerGetHashCodeImpl, pGetHashCode, pGetHashCodeParam);
	N_CLASS(NCallback) equals = N_CLASS(NTypes)::CreateCallback(N_CLASS(NTypes)::PointerEqualsImpl, pEquals, pEqualsParam);
	HNValue hValue;
	NCheck(NValueCreateCustomN(value, free.GetHandle(), getHashCode.GetHandle(), equals.GetHandle(), attributes, &hValue));
	return hValue;
}

inline N_CLASS(NTypes)::PointerFreeProc N_CLASS(NValue)::GetFreeProc(void * * ppParam) const
{
	if (!ppParam) NThrowArgumentNullException(N_T("ppParam"));
	N_CLASS(NCallback) free = GetFree();
	if (free.GetProc<NPointerFreeProc>() != N_CLASS(NTypes)::PointerFreeProcImpl)
	{
		ppParam = NULL;
		return NULL;
	}
	N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(free.GetParam());
	*ppParam = p->pParam;
	return reinterpret_cast<N_CLASS(NTypes)::PointerFreeProc>(p->pCallback);
}

}

#endif // !N_VALUE_HPP_INCLUDED
