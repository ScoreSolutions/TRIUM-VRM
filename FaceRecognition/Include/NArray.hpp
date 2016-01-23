#ifndef N_ARRAY_HPP_INCLUDED
#define N_ARRAY_HPP_INCLUDED

#include <NValue.hpp>
namespace Neurotec
{
#include <NArray.h>
}

namespace Neurotec
{

class N_CLASS(NArray) : public N_CLASS(NValue)
{
	N_DECLARE_OBJECT_CLASS(NArray, NValue)

private:
	static HNArray Create(N_CLASS(NType) * pType, const void * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes = naNone)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		HNArray hValue;
		NCheck(NArrayCreate(pType->GetHandle(), arValues, valuesSize, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const void * const * arValues, NInt valuesLength, N_CLASS(NTypes)::PointerFreeProc pFree, void * pFreeParam,
		N_CLASS(NTypes)::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, N_CLASS(NTypes)::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes)
	{
		N_CLASS(NCallback) free = N_CLASS(NTypes)::CreateCallback(N_CLASS(NTypes)::PointerFreeProcImpl, pFree, pFreeParam);
		N_CLASS(NCallback) getHashCode = N_CLASS(NTypes)::CreateCallback(N_CLASS(NTypes)::PointerGetHashCodeImpl, pGetHashCode, pGetHashCodeParam);
		N_CLASS(NCallback) equals = N_CLASS(NTypes)::CreateCallback(N_CLASS(NTypes)::PointerEqualsImpl, pEquals, pEqualsParam);
		HNArray hValue;
		NCheck(NArrayCreateCustomN(arValues, valuesLength, free.GetHandle(), getHashCode.GetHandle(), equals.GetHandle(), attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NByte * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromByteArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NSByte * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSByteArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NUShort * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromUInt16Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NShort * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromInt16Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NUInt * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromUInt32Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NInt * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromInt32Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NULong * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromUInt64Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NLong * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromInt64Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NFloat * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSingleArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NDouble * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromDoubleArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const bool * arValues, NInt valuesLength, NAttributes attributes)
	{
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (!arValues && valuesLength != 0) NThrowArgumentNullException("arValues");
		NAutoFree values(NAlloc(valuesLength * sizeof(NBool)));
		for (NInt i = 0; i < valuesLength; i++)
		{
			((NBool *)values.Get())[i] = arValues[i] ? NTrue : NFalse;
		}
		HNArray hValue;
		NCheck(NArrayCreateFromBooleanArray((NBool *)values.Get(), valuesLength, (NAttributes)(attributes | naPromoteValue), &hValue));
		values.Release();
		return hValue;
	}

	static HNArray Create(const void * const * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromPointerArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const N_CLASS(NString) * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromStringArrayN(reinterpret_cast<const HNString *>(arValues), valuesLength, (NAttributes)(attributes & ~naPromoteValue), &hValue));
		return hValue;
	}

	static HNArray Create(const NChar * const * arszValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromStringArray(arszValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(N_CLASS(NType) * pType, N_CLASS(NObject) * const * arpValues, NInt valuesLength, NAttributes attributes, bool autoAttributes)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (!arpValues && valuesLength != 0) NThrowArgumentNullException("arpValues");
		if (autoAttributes)
		{
			if (valuesLength != 0)
			{
				bool isRegistered =(arpValues[0]->state & N_CLASS(NObject)::nosRegistered) == N_CLASS(NObject)::nosRegistered;
				for (NInt i = 1; i < valuesLength; i++)
				{
					if ((arpValues[i]->state & N_CLASS(NObject)::nosRegistered) == N_CLASS(NObject)::nosRegistered ? !isRegistered : isRegistered)
					{
						isRegistered = false;
						break;
					}
				}
				if (isRegistered) attributes = (NAttributes)(attributes | naCache);
			}
		}
		N_CLASS(NObjectArray)<N_CLASS(NObject)> values(arpValues, valuesLength);
		HNArray hValue;
		NCheck(NArrayCreateFromObjectArray(pType->GetHandle(), values.GetPtr(), values.GetCount(), (NAttributes)(attributes | naPromoteValue), &hValue));
		values.Release();
		return hValue;
	}

	N_CLASS(NArray)(HNObject handle, bool claimHandle)
		: N_CLASS(NValue)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NArray) * FromSizeTypeArray(const NSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSizeTypeArray(arValues, valuesLength, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NArray) * FromSSizeTypeArray(const NSSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSSizeTypeArray(arValues, valuesLength, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NArray) * FromResultArray(const NResult * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromResultArray(arValues, valuesLength, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NArray) * FromCharArray(const NChar * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromCharArray(arValues, valuesLength, attributes, &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	N_CLASS(NArray)(N_CLASS(NType) * pType, const void * const * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(pType, arValues, valuesSize, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NByte * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NSByte * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NUShort * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NShort * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NUInt * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NInt * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NULong * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NLong * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NFloat * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NDouble * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const bool * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const void * const * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const N_CLASS(NString) * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(const NChar * const * arszValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(arszValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	N_CLASS(NArray)(N_CLASS(NType) * pType, N_CLASS(NObject) * const * arpValues, NInt valuesLength, NAttributes attributes = naNone)
		: N_CLASS(NValue)(Create(pType, arpValues, valuesLength, attributes), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NArray);
	}

	NInt GetLength() const
	{
		NInt value;
		NCheck(NArrayGetLength(GetHandle(), &value));
		return value;
	}

	void CopyTo(N_CLASS(NType) * pType, void * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(NArrayCopyTo(GetHandle(), pType->GetHandle(), attributes, format.GetHandle(), arValues, valuesSize, valuesLength));
	}

	void CopyTo(NByte * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToByteArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NByte * ToByteArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NByte> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NSByte * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToSByteArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NSByte * ToSByteArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NSByte> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NUShort * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToUInt16Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NUShort * ToUInt16Array(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NUShort> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NShort * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToInt16Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NShort * ToInt16Array(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NShort> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NUInt * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToUInt32Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NUInt * ToUInt32Array(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NUInt> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NInt * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToInt32Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NInt * ToInt32Array(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NInt> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NULong * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToUInt64Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NULong * ToUInt64Array(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NULong> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NLong * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToInt64Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NLong * ToInt64Array(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NLong> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NFloat * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToSingleArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NFloat * ToSingleArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NFloat> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(NDouble * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToDoubleArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NDouble * ToDoubleArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NDouble> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(bool * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (!arValues && valuesLength != 0) NThrowArgumentNullException("arValues");
		auto_array<NBool> values(valuesLength);
		NCheck(NArrayCopyToBooleanArray(GetHandle(), attributes, format.GetHandle(), values.get(), values.size()));
		for (NInt i = 0; i < valuesLength; i++)
		{
			arValues[i] = values[i] != 0;
		}
	}
	bool * ToBooleanArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<bool> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyToSizeTypeArray(NSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToSizeTypeArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NSizeType * ToSizeTypeArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NSizeType> values(GetLength());
		CopyToSizeTypeArray(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyToSSizeTypeArray(NSSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToSSizeTypeArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NSSizeType * ToSSizeTypeArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NSSizeType> values(GetLength());
		CopyToSSizeTypeArray(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(void * * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToPointerArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	void * * ToPointerArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<void *> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyToResultArray(NResult * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToResultArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NResult * ToResultArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NResult> values(GetLength());
		CopyToResultArray(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyToCharArray(NChar * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToCharArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NChar * ToCharArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<NChar> values(GetLength());
		CopyToCharArray(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(N_CLASS(NString) * arValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NCheck(NArrayCopyToStringArray(GetHandle(), attributes, format.GetHandle(), reinterpret_cast<HNString *>(arValues), valuesLength));
	}
	N_CLASS(NString) * ToStringArray(NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<N_CLASS(NString)> values(GetLength());
		CopyTo(values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	void CopyTo(N_CLASS(NType) * pType, N_CLASS(NObject) * * arpValues, NInt valuesLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		N_CLASS(NObjectArray)<N_CLASS(NObject)> values(valuesLength, true, (attributes & naCache) == naCache);
		NCheck(NArrayCopyToObjectArray(GetHandle(), pType->GetHandle(), attributes, format.GetHandle(), values.GetPtr(), values.GetCount()));
		values.CopyTo(arpValues, valuesLength);
	}
	N_CLASS(NObject) * * ToObjectArray(N_CLASS(NType) * pType, NInt * pLength, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pLength) NThrowArgumentNullException(N_T("pLength"));
		auto_array<N_CLASS(NObject) *> values(GetLength());
		CopyTo(pType, values.get(), values.size(), attributes, format);
		*pLength = values.size();
		return values.release();
	}

	N_CLASS(NValue) * GetValue(NInt index) const
	{
		HNValue hValue;
		NCheck(NArrayGetValue(GetHandle(), index, &hValue));
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

	void GetValueAs(NInt index, N_CLASS(NType) * pType, void * pResult, NSizeType resultSize, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(NArrayGetValueAs(GetHandle(), index, pType->GetHandle(), attributes, format.GetHandle(), pResult, resultSize));
	}

	NByte GetValueAsByte(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NByte value;
		NCheck(NArrayGetValueAsByte(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NSByte GetValueAsSByte(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NSByte value;
		NCheck(NArrayGetValueAsSByte(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NUShort GetValueAsUInt16(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NUShort value;
		NCheck(NArrayGetValueAsUInt16(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NShort GetValueAsInt16(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NShort value;
		NCheck(NArrayGetValueAsInt16(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NUInt GetValueAsUInt32(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NUInt value;
		NCheck(NArrayGetValueAsUInt32(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NInt GetValueAsInt32(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NInt value;
		NCheck(NArrayGetValueAsInt32(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NULong GetValueAsUInt64(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NULong value;
		NCheck(NArrayGetValueAsUInt64(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NLong GetValueAsInt64(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NLong value;
		NCheck(NArrayGetValueAsInt64(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NFloat GetValueAsSingle(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NFloat value;
		NCheck(NArrayGetValueAsSingle(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NDouble GetValueAsDouble(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NDouble value;
		NCheck(NArrayGetValueAsDouble(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	bool GetValueAsBoolean(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NBool value;
		NCheck(NArrayGetValueAsBoolean(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value != 0;
	}

	NSizeType GetValueAsSizeType(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NSizeType value;
		NCheck(NArrayGetValueAsSizeType(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NSSizeType GetValueAsSSizeType(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NSSizeType value;
		NCheck(NArrayGetValueAsSSizeType(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	void * GetValueAsPointer(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		void * value;
		NCheck(NArrayGetValueAsPointer(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NResult GetValueAsResult(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NResult value;
		NCheck(NArrayGetValueAsResult(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NChar GetValueAsChar(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		NChar value;
		NCheck(NArrayGetValueAsChar(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	N_CLASS(NString) GetValueAsString(NInt index, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NArrayGetValueAsString(GetHandle(), index, attributes, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	N_CLASS(NObject) * GetValueAsObject(NInt index, N_CLASS(NType) * pType, NAttributes attributes = naNone, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		HNObject hValue;
		NCheck(NArrayGetValueAsObject(GetHandle(), index, pType->GetHandle(), attributes, format.GetHandle(), &hValue));
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

}

#endif // !N_ARRAY_HPP_INCLUDED
