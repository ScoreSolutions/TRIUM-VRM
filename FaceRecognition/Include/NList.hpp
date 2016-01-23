#ifndef N_LIST_HPP_INCLUDED
#define N_LIST_HPP_INCLUDED

#include <NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <NList.h>
}}}

namespace Neurotec { namespace Collections
{

class N_CLASS(NList) : private Internal::NList
{
	N_DECLARE_PRIMITIVE_CLASS(NList)

public:
	explicit N_CLASS(NList)(NSizeType elementSize)
	{
		NCheck(Internal::NListInit(this, elementSize, NULL));
	}

	template<typename T> N_CLASS(NList)()
	{
		NCheck(Internal::NListInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType())));
	}

	N_CLASS(NList)(N_CLASS(NType) * pElementType)
	{
		NCheck(Internal::NListInit(this, 0, N_CLASS(NObject)::ToHandle(pElementType)));
	}

	N_CLASS(NList)(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NListInitP(this, 0, pElementTypeOf));
	}

	N_CLASS(NList)(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NListInitWithCapacity(this, elementSize, NULL, capacity));
	}

	template<typename T> N_CLASS(NList)(NInt capacity)
	{
		NCheck(Internal::NListInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity));
	}

	N_CLASS(NList)(NSizeType elementSize, N_CLASS(NType) * pElementType, NInt capacity)
	{
		NCheck(Internal::NListInitWithCapacity(this, elementSize, N_CLASS(NObject)::ToHandle(pElementType), capacity));
	}

	N_CLASS(NList)(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NListInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	N_CLASS(NList)(NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitEx(this, 0, NULL, capacity, maxCapacity, growthDelta, alignment));
	}

	template<typename T> N_CLASS(NList)(NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitEx(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity, maxCapacity, growthDelta, alignment));
	}

	N_CLASS(NList)(N_CLASS(NType) * pElementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitEx(this, 0, N_CLASS(NObject)::ToHandle(pElementType), capacity, maxCapacity, growthDelta, alignment));
	}

	N_CLASS(NList)(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, alignment));
	}

	~N_CLASS(NList)()
	{
		NCheck(Internal::NListDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NListGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NListSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NListGetCount(this, &value));
		return value;
	}

	void SetCount(NInt value)
	{
		NCheck(Internal::NListSetCount(this, value));
	}

	NInt IndexOf(const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListIndexOfInRange(this, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt IndexOf(const T & value, NInt startIndex, NInt count)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListIndexOfInRange(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt IndexOf(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListIndexOfInRange(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListIndexOfInRangeP(this, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListIndexOfFrom(this, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt IndexOf(const T & value, NInt startIndex)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListIndexOfFrom(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt IndexOf(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListIndexOfFrom(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListIndexOfFromP(this, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListIndexOf(this, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt IndexOf(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListIndexOf(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result;
	}

	NInt IndexOf(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListIndexOf(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result;
	}

	NInt IndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListIndexOfP(this, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfInRange(this, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(const T & value, NInt startIndex, NInt count)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListLastIndexOfInRange(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfInRange(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfInRangeP(this, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfFrom(this, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(const T & value, NInt startIndex)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListLastIndexOfFrom(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt LastIndexOf(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfFrom(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfFromP(this, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOf(this, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListLastIndexOf(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result;
	}

	NInt LastIndexOf(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOf(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfP(this, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	bool Contains(const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListContains(this, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NBool result;
		NCheck(Internal::NListContains(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result != 0;
	}

	bool Contains(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListContains(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListContainsP(this, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetStart(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListGetStart(this, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetStart()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NListGetStart(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetStart(N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NListGetStart(this, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetStart(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListGetStartP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetEnd(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListGetEnd(this, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetEnd()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NListGetEnd(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetEnd(N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NListGetEnd(this, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetEnd(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListGetEndP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetPtr(NInt index, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListGetPtr(this, index, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetPtr(NInt index)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NListGetPtr(this, index, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetPtr(NInt index, N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NListGetPtr(this, index, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetPtr(NInt index, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListGetPtrP(this, index, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Get(NInt index, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListGet(this, index, NULL, pValue, valueSize));
	}

	template<typename T> T Get(NInt index)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NCheck(Internal::NListGet(this, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &value, sizeof(value)));
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

	void Get(NInt index, N_CLASS(NType) * pValueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListGet(this, index, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Get(NInt index, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListGetP(this, index, pValueTypeOf, pValue, valueSize));
	}

	void Set(NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListSet(this, index, NULL, pValue, valueSize));
	}

	template<typename T> void Set(NInt index, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NListSet(this, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Set(NInt index, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListSet(this, index, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Set(NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListSetP(this, index, pValueTypeOf, pValue, valueSize));
	}

	void Add(const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListAdd(this, NULL, pValue, valueSize));
	}

	template<typename T> void Add(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NListAdd(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Add(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListAdd(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Add(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListAddP(this, pValueTypeOf, pValue, valueSize));
	}

	void AddRange(const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListAddRange(this, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void AddRange(const T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListAddRange(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
	}

	void AddRange(N_CLASS(NType) * pValueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListAddRange(this, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	void AddRange(NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListAddRangeP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void AddList(N_CLASS(NList) & srcList)
	{
		NCheck(Internal::NListAddList(this, &srcList));
	}

	void Insert(NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListInsert(this, index, NULL, pValue, valueSize));
	}

	template<typename T> void Insert(NInt index, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NListInsert(this, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Insert(NInt index, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListInsert(this, index, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Insert(NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListInsertP(this, index, pValueTypeOf, pValue, valueSize));
	}

	void InsertRange(NInt index, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListInsertRange(this, index, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void InsertRange(NInt index, const T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListInsertRange(this, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
	}

	void InsertRange(NInt index, N_CLASS(NType) * pValueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListInsertRange(this, index, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	void InsertRange(NInt index, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListInsertRangeP(this, index, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void InsertList(NInt index, N_CLASS(NList) & srcList)
	{
		NCheck(Internal::NListInsertList(this, index, &srcList));
	}

	void RemoveAt(NInt index)
	{
		NCheck(Internal::NListRemoveAt(this, index));
	}

	void RemoveRange(NInt index, NInt count)
	{
		NCheck(Internal::NListRemoveRange(this, index, count));
	}

	NInt Remove(const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListRemove(this, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt Remove(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListRemove(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result;
	}

	NInt Remove(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListRemove(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result;
	}

	NInt Remove(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListRemoveP(this, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	void Clear()
	{
		NCheck(Internal::NListClear(this));
	}

	NInt CopyTo(NInt index, NInt count, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToRange(this, index, count, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(NInt index, NInt count, T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt realCount = NCheck(Internal::NListCopyToRange(this, index, count, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), arValues ? N_CLASS(NTypeTraits)<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, realCount);
	}

	NInt CopyTo(NInt index, NInt count, N_CLASS(NType) * pValueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToRange(this, index, count, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt index, NInt count, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToRangeP(this, index, count, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyTo(this, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt count = NCheck(Internal::NListCopyTo(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), arValues ? N_CLASS(NTypeTraits)<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(N_CLASS(NType) * pValueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyTo(this, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NInt index, NInt count, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayRange(this, index, count, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * ToArray(NInt index, NInt count, NInt * pCount)
	{
		void * pValues;
		NInt realCount;
		NCheck(Internal::NListToArrayRange(this, index, count, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &realCount));
		try
		{
			typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(pValues, realCount);
			pValues = NULL; realCount = 0;
			return values.ToArray(pCount);
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNativeArray(pValues, realCount);
			throw;
		}
	}

	void * ToArray(NInt index, NInt count, N_CLASS(NType) * pValueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayRange(this, index, count, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt index, NInt count, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayRangeP(this, index, count, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * ToArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * ToArray(NInt * pCount)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListToArray(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &count));
		try
		{
			typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(pValues, count);
			pValues = NULL; count = 0;
			return values.ToArray(pCount);
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNativeArray(pValues, count);
			throw;
		}
	}

	void * ToArray(N_CLASS(NType) * pValueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArray(this, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListDetachArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * DetachArray(NInt * pCount)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListDetachArray(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &count));
		try
		{
			typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(pValues, count);
			pValues = NULL; count = 0;
			return values.ToArray(pCount);
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNativeArray(pValues, count);
			throw;
		}
	}

	void * DetachArray(N_CLASS(NType) * pValueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListDetachArray(this, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListDetachArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_LIST_HPP_INCLUDED
