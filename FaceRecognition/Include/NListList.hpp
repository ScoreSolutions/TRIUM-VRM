#ifndef N_LIST_LIST_HPP_INCLUDED
#define N_LIST_LIST_HPP_INCLUDED

#include <NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <NListList.h>
}}}

namespace Neurotec { namespace Collections
{

class N_CLASS(NListList) : private Internal::NListList
{
	N_DECLARE_PRIMITIVE_CLASS(NListList)

public:
	explicit N_CLASS(NListList)(NSizeType elementSize)
	{
		NCheck(Internal::NListListInit(this, elementSize, NULL));
	}

	template<typename T> N_CLASS(NListList)()
	{
		NCheck(Internal::NListListInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType())));
	}

	N_CLASS(NListList)(N_CLASS(NType) * pElementType)
	{
		NCheck(Internal::NListListInit(this, 0, N_CLASS(NObject)::ToHandle(pElementType)));
	}

	N_CLASS(NListList)(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NListListInitP(this, 0, pElementTypeOf));
	}

	N_CLASS(NListList)(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NListListInitWithCapacity(this, elementSize, NULL, capacity));
	}

	template<typename T> N_CLASS(NListList)(NInt capacity)
	{
		NCheck(Internal::NListListInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity));
	}

	N_CLASS(NListList)(NSizeType elementSize, N_CLASS(NType) * pElementType, NInt capacity)
	{
		NCheck(Internal::NListListInitWithCapacity(this, elementSize, N_CLASS(NObject)::ToHandle(pElementType), capacity));
	}

	N_CLASS(NListList)(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NListListInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	N_CLASS(NListList)(NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitEx(this, 0, NULL, capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	template<typename T> N_CLASS(NListList)(NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitEx(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	N_CLASS(NListList)(N_CLASS(NType) * pElementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitEx(this, 0, N_CLASS(NObject)::ToHandle(pElementType), capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	N_CLASS(NListList)(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	~N_CLASS(NListList)()
	{
		NCheck(Internal::NListListDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NListListGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NListListSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NListListGetCount(this, &value));
		return value;
	}

	void SetCount(NInt value)
	{
		NCheck(Internal::NListListSetCount(this, value));
	}

	void Add(NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListAdd(this, itemCapacity));
	}

	void AddRange(NInt count, NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListAddRange(this, count, itemCapacity));
	}

	void AddListList(N_CLASS(NListList) & srcList)
	{
		NCheck(Internal::NListListAddListList(this, &srcList));
	}

	void Insert(NInt index, NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListInsert(this, index, itemCapacity));
	}

	void InsertRange(NInt index, NInt count, NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListInsertRange(this, index, count, itemCapacity));
	}

	void InsertListList(NInt index, N_CLASS(NListList) & srcList)
	{
		NCheck(Internal::NListListInsertListList(this, index, &srcList));
	}

	void RemoveAt(NInt index)
	{
		NCheck(Internal::NListListRemoveAt(this, index));
	}

	void RemoveRange(NInt index, NInt count)
	{
		NCheck(Internal::NListListRemoveRange(this, index, count));
	}

	void Clear()
	{
		NCheck(Internal::NListListClear(this));
	}

	NInt GetCapacity(NInt listIndex)
	{
		NInt value;
		NCheck(Internal::NListListGetItemCapacity(this, listIndex, &value));
		return value;
	}

	void SetCapacity(NInt listIndex, NInt value)
	{
		NCheck(Internal::NListListSetItemCapacity(this, listIndex, value));
	}

	NInt GetCount(NInt listIndex)
	{
		NInt value;
		NCheck(Internal::NListListGetItemCount(this, listIndex, &value));
		return value;
	}

	void SetCount(NInt listIndex, NInt value)
	{
		NCheck(Internal::NListListSetItemCount(this, listIndex, value));
	}

	NInt IndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRange(this, listIndex, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt IndexOf(NInt listIndex, const T & value, NInt startIndex, NInt count)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRange(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRange(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRangeP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemFrom(this, listIndex, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt IndexOf(NInt listIndex, const T & value, NInt startIndex)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListIndexOfItemFrom(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemFrom(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemFromP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt IndexOf(NInt listIndex, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListIndexOfItem(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItem(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRange(this, listIndex, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(NInt listIndex, const T & value, NInt startIndex, NInt count)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRange(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRange(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRangeP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFrom(this, listIndex, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(NInt listIndex, const T & value, NInt startIndex)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFrom(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFrom(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFromP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(NInt listIndex, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListLastIndexOfItem(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItem(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	bool Contains(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListListContainsItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(NInt listIndex, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NBool result;
		NCheck(Internal::NListListContainsItem(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result != 0;
	}

	bool Contains(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListListContainsItem(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListListContainsItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetStart(NInt listIndex, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsStart(this, listIndex, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetStart(NInt listIndex)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NListListGetItemsStart(this, listIndex, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetStart(NInt listIndex, N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsStart(this, listIndex, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetStart(NInt listIndex, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsStartP(this, listIndex, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetEnd(NInt listIndex, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsEnd(this, listIndex, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetEnd(NInt listIndex)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NListListGetItemsEnd(this, listIndex, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetEnd(NInt listIndex, N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsEnd(this, listIndex, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetEnd(NInt listIndex, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsEndP(this, listIndex, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetPtr(NInt listIndex, NInt index, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemPtr(this, listIndex, index, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetPtr(NInt listIndex, NInt index)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NListListGetItemPtr(this, listIndex, index, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetPtr(NInt listIndex, NInt index, N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemPtr(this, listIndex, index, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetPtr(NInt listIndex, NInt index, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemPtrP(this, listIndex, index, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Get(NInt listIndex, NInt index, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListGetItem(this, listIndex, index, NULL, pValue, valueSize));
	}

	template<typename T> T Get(NInt listIndex, NInt index)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NCheck(Internal::NListListGetItem(this, listIndex, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &value, sizeof(value)));
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

	void Get(NInt listIndex, NInt index, N_CLASS(NType) * pValueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListGetItem(this, listIndex, index, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Get(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListGetItemP(this, listIndex, index, pValueTypeOf, pValue, valueSize));
	}

	void Set(NInt listIndex, NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListSetItem(this, listIndex, index, NULL, pValue, valueSize));
	}

	template<typename T> void Set(NInt listIndex, NInt index, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NListListSetItem(this, listIndex, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Set(NInt listIndex, NInt index, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListSetItem(this, listIndex, index, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Set(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListSetItemP(this, listIndex, index, pValueTypeOf, pValue, valueSize));
	}

	void Add(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListAddItem(this, listIndex, NULL, pValue, valueSize));
	}

	template<typename T> void Add(NInt listIndex, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NListListAddItem(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Add(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListAddItem(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Add(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListAddItemP(this, listIndex, pValueTypeOf, pValue, valueSize));
	}

	void AddRange(NInt listIndex, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListAddItemRange(this, listIndex, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void AddRange(NInt listIndex, const T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListListAddItemRange(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
	}

	void AddRange(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListAddItemRange(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	void AddRange(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListAddItemRangeP(this, listIndex, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void AddList(NInt listIndex, N_CLASS(NListList) & srcList, NInt srcListIndex)
	{
		NCheck(Internal::NListListAddListListItems(this, listIndex, &srcList, srcListIndex));
	}

	void Insert(NInt listIndex, NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListInsertItem(this, listIndex, index, NULL, pValue, valueSize));
	}

	template<typename T> void Insert(NInt listIndex, NInt index, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NListListInsertItem(this, listIndex, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Insert(NInt listIndex, NInt index, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListInsertItem(this, listIndex, index, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Insert(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListInsertItemP(this, listIndex, index, pValueTypeOf, pValue, valueSize));
	}

	void InsertRange(NInt listIndex, NInt index, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListInsertItemRange(this, listIndex, index, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void InsertRange(NInt listIndex, NInt index, const T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListListInsertItemRange(this, listIndex, index, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
	}

	void InsertRange(NInt listIndex, NInt index, N_CLASS(NType) * pValueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListInsertItemRange(this, listIndex, index, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	void InsertRange(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListInsertItemRangeP(this, listIndex, index, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void InsertList(NInt listIndex, NInt index, N_CLASS(NListList) & srcList, NInt srcListIndex)
	{
		NCheck(Internal::NListListInsertListListItems(this, listIndex, index, &srcList, srcListIndex));
	}

	void RemoveAt(NInt listIndex, NInt index)
	{
		NCheck(Internal::NListListRemoveItemAt(this, listIndex, index));
	}

	void RemoveRange(NInt listIndex, NInt index, NInt count)
	{
		NCheck(Internal::NListListRemoveItemRange(this, listIndex, index, count));
	}

	NInt Remove(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListRemoveItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt Remove(NInt listIndex, const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListRemoveItem(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result;
	}

	NInt Remove(NInt listIndex, N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListRemoveItem(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result;
	}

	NInt Remove(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListRemoveItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	void Clear(NInt listIndex)
	{
		NCheck(Internal::NListListClearItems(this, listIndex));
	}

	NInt CopyTo(NInt listIndex, NInt index, NInt count, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToRange(this, listIndex, index, count, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(NInt listIndex, NInt index, NInt count, T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt realCount = NCheck(Internal::NListListCopyItemsToRange(this, listIndex, index, count, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), arValues ? N_CLASS(NTypeTraits)<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, realCount);
	}

	NInt CopyTo(NInt listIndex, NInt index, NInt count, N_CLASS(NType) * pValueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToRange(this, listIndex, index, count, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt listIndex, NInt index, NInt count, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToRangeP(this, listIndex, index, count, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt listIndex, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsTo(this, listIndex, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(NInt listIndex, T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt count = NCheck(Internal::NListListCopyItemsTo(this, listIndex, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), arValues ? N_CLASS(NTypeTraits)<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(NInt listIndex, N_CLASS(NType) * pValueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsTo(this, listIndex, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt listIndex, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToP(this, listIndex, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NInt listIndex, NInt index, NInt count, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayRange(this, listIndex, index, count, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * ToArray(NInt listIndex, NInt index, NInt count, NInt * pCount)
	{
		void * pValues;
		NInt realCount;
		NCheck(Internal::NListListItemsToArrayRange(this, listIndex, index, count, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &realCount));
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

	void * ToArray(NInt listIndex, NInt index, NInt count, N_CLASS(NType) * pValueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayRange(this, listIndex, index, count, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt listIndex, NInt index, NInt count, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayRangeP(this, listIndex, index, count, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt listIndex, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArray(this, listIndex, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * ToArray(NInt listIndex, NInt * pCount)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListListItemsToArray(this, listIndex, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &count));
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

	void * ToArray(NInt listIndex, N_CLASS(NType) * pValueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArray(this, listIndex, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt listIndex, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayP(this, listIndex, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NInt listIndex, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListDetachItemsArray(this, listIndex, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * DetachArray(NInt listIndex, NInt * pCount)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListListDetachItemsArray(this, listIndex, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &count));
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

	void * DetachArray(NInt listIndex, N_CLASS(NType) * pValueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListDetachItemsArray(this, listIndex, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NInt listIndex, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListDetachItemsArrayP(this, listIndex, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_LIST_LIST_HPP_INCLUDED
