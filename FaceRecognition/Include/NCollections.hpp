#ifndef N_COLLECTIONS_HPP_INCLUDED
#define N_COLLECTIONS_HPP_INCLUDED

#include <NObject.hpp>
#include <NMonitor.hpp>
#include <vector>
#include <memory.h>

#include <NNoDeprecate.h>

namespace Neurotec { namespace Collections
{

template<typename T, typename TOwner> class N_CLASS(NReadOnlyCollection) : public N_CLASS(NObjectBase)
{
public:
	typedef T ItemType;
	typedef T const ItemConstType;
	typedef T * ItemPtrType;
	typedef T const * ItemConstPtrType;
	typedef T & ItemRefType;
	typedef T const & ItemConstRefType;
	typedef TOwner OwnerType;
	typedef typename TOwner::HandleType OwnerHandleType;

private:
	NInt version;
	::Neurotec::Threading::NMonitorType lock;

	N_CLASS(NReadOnlyCollection)(const N_CLASS(NReadOnlyCollection) &)
	{
	}

protected:
	TOwner * const pOwner;

	N_CLASS(NReadOnlyCollection)(TOwner * pOwner)
		: version(0), lock(N_MONITOR_ARGS), pOwner(pOwner)
	{
	}

	virtual NInt GetVersion() const
	{
		return version;
	}

	virtual void Touch()
	{
		version++;
	}

	virtual bool ItemsEqual(ItemConstRefType value1, ItemConstRefType value2) const = 0;

public:
	class ConstIterator
	{
	private:
		const N_CLASS(NReadOnlyCollection)<T, TOwner> & collection;
		bool reverse;
		NInt index;
		NInt count;
		NInt version;

		ConstIterator(const N_CLASS(NReadOnlyCollection)<T, TOwner> & collection, NInt index, bool reverse = false)
			: collection(collection), reverse(reverse), index(index), count(collection.GetCount()), version(collection.GetVersion())
		{
		}

	public:
		ConstIterator(const ConstIterator & value)
			: collection(value.collection), reverse(value.reverse), index(value.index), count(value.count), version(value.version)
		{
		}

		ConstIterator & operator++()
		{
			if (reverse) index--;
			else index++;
			return *this;
		}

		ConstIterator & operator++(int)
		{
			if (reverse) index--;
			else index++;
			return *this;
		}

		ConstIterator & operator--()
		{
			if (reverse) index++;
			else index--;
			return *this;
		}

		ConstIterator & operator--(int)
		{
			if (reverse) index++;
			else index--;
			return *this;
		}

		T operator*() const
		{
			if (collection.GetVersion() != version) NThrowInvalidOperationException();
			return collection.Get(index);
		}

		bool operator==(const ConstIterator & value) const
		{
			if (&collection != &value.collection) NThrowInvalidOperationException();
			return index == value.index;
		}

		bool operator!=(const ConstIterator & value) const
		{
			if (&collection != &value.collection) NThrowInvalidOperationException();
			return index != value.index;
		}

		bool operator>(const ConstIterator & value) const
		{
			if (&collection != &value.collection) NThrowInvalidOperationException();
			return index > value.index;
		}

		bool operator>=(const ConstIterator & value) const
		{
			if (&collection != &value.collection) NThrowInvalidOperationException();
			return index >= value.index;
		}

		bool operator<(const ConstIterator & value) const
		{
			if (&collection != &value.collection) NThrowInvalidOperationException();
			return index < value.index;
		}

		bool operator<=(const ConstIterator & value) const
		{
			if (&collection != &value.collection) NThrowInvalidOperationException();
			return index <= value.index;
		}

		ConstIterator & operator=(const ConstIterator & value)
		{
			if (&collection != &value.collection || version != value.version) NThrowInvalidOperationException();
			index = value.index;
		}

		friend class N_CLASS(NReadOnlyCollection)<T, TOwner>;
	};

	ConstIterator GetBegin() const
	{
		return ConstIterator(*this, 0);
	}

	ConstIterator GetEnd() const
	{
		return ConstIterator(*this, GetCount());
	}

	ConstIterator GetRBegin() const
	{
		return ConstIterator(*this, GetCount() - 1, true);
	}

	ConstIterator GetREnd() const
	{
		return ConstIterator(*this, 0, true);
	}

	::Neurotec::Threading::NMonitorType & GetLock()
	{
		return lock;
	}

	virtual NInt GetCount() const = 0;
	virtual ItemType Get(NInt index) const = 0;

	virtual NInt GetAll(ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		NInt count = GetCount();
		if (arValues)
		{
			if (valuesLength < count) NThrowArgumentInsufficientException(N_T("valuesLength"));
			for (NInt i = 0; i < count; i++)
			{
				arValues[i] = Get(i);
			}
		}
		return count;
	}

	virtual NInt IndexOf(ItemConstRefType value) const
	{
		NInt count = GetCount();
		for (NInt i = 0; i < count; i++)
		{
			if (ItemsEqual(value, Get(i))) return i;
		}
		return -1;
	}

	virtual bool Contains(ItemConstRefType value) const
	{
		return IndexOf(value) != -1;
	}

	ItemType operator[](NInt index)
	{
		return Get(index);
	}
};

template<typename T, typename TOwner> class N_CLASS(NCollection) : public N_CLASS(NReadOnlyCollection)<T, TOwner>
{
protected:
	N_CLASS(NCollection)(TOwner * pOwner)
		: N_CLASS(NReadOnlyCollection)<T, TOwner>(pOwner)
	{
	}

	virtual void SetInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value) = 0;
	virtual NInt AddInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value) = 0;
	virtual void InsertInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value) = 0;

	virtual NInt RemoveInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index = this->IndexOf(value);
		if (index != -1)
		{
			RemoveAtInternal(index);
		}
		return index;
	}

	virtual void RemoveAtInternal(NInt index) = 0;
	virtual void RemoveRangeInternal(NInt index, NInt count) = 0;
	virtual void ClearInternal() = 0;

public:
	virtual void Set(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		SetInternal(index, value);
		this->Touch();
	}

	NInt Add(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index = AddInternal(value);
		if (index != -1)
		{
			this->Touch();
		}
		return index;
	}

	void Insert(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		InsertInternal(index, value);
		this->Touch();
	}

	virtual NInt Remove(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index = RemoveInternal(value);
		if (index != -1)
		{
			this->Touch();
		}
		return index;
	}

	void RemoveAt(NInt index)
	{
		RemoveAtInternal(index);
		this->Touch();
	}

	void RemoveRange(NInt index, NInt count)
	{
		RemoveRangeInternal(index, count);
		this->Touch();
	}

	void Clear()
	{
		ClearInternal();
		this->Touch();
	}

	template<typename U, typename UBase, typename UOwner> friend class N_CLASS(NArrayCollection);
};

template<typename T, typename TOwner> class N_CLASS(NSimpleReadOnlyCollection) : public N_CLASS(NReadOnlyCollection)<T, TOwner>
{
protected:
	N_CLASS(NSimpleReadOnlyCollection)(TOwner * pOwner)
		: N_CLASS(NReadOnlyCollection)<T, TOwner>(pOwner)
	{
	}

	virtual bool SupportsGetAll() const
	{
		return false;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength) const = 0;

	virtual NResult GetCountNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt * pValue) const = 0;

public:
	virtual NInt GetCount() const
	{
		NInt value;
		NCheck(GetCountNative(N_CLASS(NObject)::ToHandle(this->pOwner), &value));
		return value;
	}

	virtual NInt GetAll(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		if (!SupportsGetAll())
		{
			return N_CLASS(NReadOnlyCollection)<T, TOwner>::GetAll(arValues, valuesLength);
		}
		else
		{
			return GetAllInternal(arValues, valuesLength);
		}
	}
};

template<typename T, typename TOwner, bool cache = true, bool oldSkool = false> class N_CLASS(NObjectReadOnlyCollection) : public N_CLASS(NSimpleReadOnlyCollection)<T *, TOwner>
{
private:
	static void UnrefIf(typename T::HandleType & hItem, bool isOldSkool)
	{
		if (!isOldSkool)
		{
			N_CLASS(NObject)::Unref(hItem);
			hItem = NULL;
		}
	}

protected:
	N_CLASS(NObjectReadOnlyCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleReadOnlyCollection)<T *, TOwner>(pOwner)
	{
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value2) const
	{
		return N_CLASS(NObject)::Equals(value1, value2);
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		NInt count = this->GetCount();
		if (arValues)
		{
			N_CLASS(NObjectArray)<T> items(count, !oldSkool, cache);
			count = NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), items.GetPtr(), items.GetCount()));
			items.CopyTo(arValues, valuesLength, count);
		}
		return count;
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt index, typename T::HandleType * phValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, typename T::HandleType * arhValues, NInt valuesLength) const = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemType Get(NInt index) const
	{
		typename T::HandleType hItem;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &hItem));
		try
		{
			return N_CLASS(NObject)::FromHandle<T>(hItem, !oldSkool, cache);
		}
		catch (...)
		{
			UnrefIf(hItem, oldSkool);
			throw;
		}
	}

	virtual NInt IndexOf(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value) const
	{
		return IndexOf(N_CLASS(NObject)::ToHandle(value));
	}

	NInt IndexOf(typename T::HandleType handle) const
	{
		NInt count = this->GetCount();
		typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType hOwner = N_CLASS(NObject)::ToHandle(this->pOwner);
		for (NInt i = 0; i < count; i++)
		{
			typename T::HandleType hItem;
			NCheck(GetNative(hOwner, i, &hItem));
			try
			{
				NBool r;
				NCheck(NObjectEquals(handle, hItem, &r));
				UnrefIf(hItem, oldSkool);
				if (r) return i;
			}
			catch (...)
			{
				UnrefIf(hItem, oldSkool);
				throw;
			}
		}
		return -1;
	}

	using N_CLASS(NReadOnlyCollection)<T *, TOwner>::Contains;
	using N_CLASS(NReadOnlyCollection)<T *, TOwner>::operator[];

	virtual NBool Contains(typename T::HandleType handle) const
	{
		return IndexOf(handle) != -1;
	}

	typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemType Get(typename T::HandleType handle) const
	{
		NInt index = IndexOf(handle);
		return index == -1 ? NULL : Get(index);
	}

	typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemType operator[](typename T::HandleType handle) const
	{
		return Get(handle);
	}
};

template<typename T, typename TOwner> class N_CLASS(NValueReadOnlyCollection) : public N_CLASS(NSimpleReadOnlyCollection)<T, TOwner>
{
protected:
	N_CLASS(NValueReadOnlyCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleReadOnlyCollection)<T, TOwner>(pOwner)
	{
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value2) const
	{
		return value1 == value2;
	}

	virtual bool SupportsGetAll() const
	{
		return true;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), arValues, valuesLength));
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, T * pValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, T * arValues, NInt valuesLength) const = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType Get(NInt index) const
	{
		typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType value;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &value));
		return value;
	}
};

template<typename TOwner> class N_CLASS(NStringReadOnlyCollection) : public N_CLASS(NSimpleReadOnlyCollection)<N_CLASS(NString), TOwner>
{
protected:
	N_CLASS(NStringReadOnlyCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleReadOnlyCollection)<N_CLASS(NString), TOwner>(pOwner)
	{
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value2) const
	{
		return value1 == value2;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), reinterpret_cast<HNString *>(arValues), valuesLength));
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, NInt index, HNString * phValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, HNString * arhValues, NInt valuesLength) const = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemType Get(NInt index) const
	{
		HNString hValue;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	using N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::Contains;
	using N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::IndexOf;

	virtual NInt IndexOf(const N_CLASS(NStringWrapper) & value) const
	{
		NInt count = this->GetCount();
		for (NInt i = 0; i < count; i++)
		{
			NBool r;
			NCheck(NStringEqualsN(value.GetHandle(), Get(i).GetHandle(), NFalse, &r));
			if (r) return i;
		}
		return -1;
	}

	virtual bool Contains(const N_CLASS(NStringWrapper) & value) const
	{
		return IndexOf(value) != -1;
	}
};

template<typename T, typename TOwner, bool disposable = false> class N_CLASS(NStructReadOnlyCollection) : public N_CLASS(NSimpleReadOnlyCollection)<T, TOwner>
{
protected:
	N_CLASS(NStructReadOnlyCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleReadOnlyCollection)<T, TOwner>(pOwner)
	{
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value2) const
	{
		return false;
		N_UNREFERENCED_PARAMETER(value1);
		N_UNREFERENCED_PARAMETER(value2);
	}

	virtual bool SupportsGetAll() const
	{
		return !disposable;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), arValues, valuesLength));
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, T * pValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, T * arValues, NInt valuesLength) const = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType Get(NInt index) const
	{
		typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType value;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &value));
		return value;
	}

	void Get(NInt index, T * pValue) const
	{
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, pValue));
	}
};

template<typename T, typename TOwner> class N_CLASS(NSimpleCollection) : public N_CLASS(NCollection)<T, TOwner>
{
protected:
	N_CLASS(NSimpleCollection)(TOwner * pOwner)
		: N_CLASS(NCollection)<T, TOwner>(pOwner)
	{
	}

	virtual NInt AddInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index;
		if (SupportsAddWithOutIndex())
		{
			index = AddWithOutIndexInternal(value);
		}
		else
		{
			index = this->GetCount();
			AddPlainInternal(value);
		}
		return index;
	}

	virtual NInt RemoveInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		if (!SupportsRemoveByValue())
		{
			return N_CLASS(NCollection)<T, TOwner>::RemoveInternal(value);
		}
		else
		{
			return RemoveWithOutIndexInternal(value);
		}
	}

	virtual void RemoveAtInternal(NInt index)
	{
		NCheck(RemoveAtNative(N_CLASS(NObject)::ToHandle(this->pOwner), index));
	}

	virtual void RemoveRangeInternal(NInt index, NInt count)
	{
		if (SupportsRemoveRange())
		{
			NCheck(RemoveRangeNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, count));
		}
		else if (index == 0 && count == this->GetCount())
		{
			ClearInternal();
		}
		else if (count == 1)
		{
			RemoveAtInternal(index);
		}
		else
		{
			if (index < 0) NThrowArgumentLessThanZeroException(N_T("index"));
			if (count < 0) NThrowArgumentLessThanZeroException(N_T("count"));
			if (index + count > this->GetCount()) NThrowArgumentException(N_T("index plus count is greater than GetCount()"));
			typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType hOwner = N_CLASS(NObject)::ToHandle(this->pOwner);
			for (NInt i = count - 1; i >= 0; i--)
			{
				NCheck(RemoveAtNative(hOwner, index + i));
			}
		}
	}

	virtual void ClearInternal()
	{
		NCheck(ClearNative(N_CLASS(NObject)::ToHandle(this->pOwner)));
	}

	virtual bool SupportsGetAll() const
	{
		return false;
	}

	virtual bool SupportsAddWithOutIndex() const
	{
		return false;
	}

	virtual bool SupportsRemoveByValue() const
	{
		return false;
	}

	virtual bool SupportsRemoveRange() const
	{
		return false;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength) const = 0;
	virtual void AddPlainInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value) = 0;
	virtual NInt AddWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value) = 0;
	virtual NInt RemoveWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value) = 0;

	virtual NResult GetCountNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt * pValue) const = 0;
	virtual NResult GetCapacityNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt * pValue) const = 0;
	virtual NResult SetCapacityNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt value) = 0;
	virtual NResult RemoveAtNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index) = 0;
	virtual NResult RemoveRangeNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, NInt count) = 0;
	virtual NResult ClearNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle) = 0;

public:
	virtual NInt GetCount() const
	{
		NInt value;
		NCheck(GetCountNative(N_CLASS(NObject)::ToHandle(this->pOwner), &value));
		return value;
	}

	virtual NInt GetAll(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		if (!SupportsGetAll())
		{
			return N_CLASS(NReadOnlyCollection)<T, TOwner>::GetAll(arValues, valuesLength);
		}
		else
		{
			return GetAllInternal(arValues, valuesLength);
		}
	}

	NInt GetCapacity() const
	{
		NInt value;
		NCheck(GetCapacityNative(N_CLASS(NObject)::ToHandle(this->pOwner), &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(SetCapacityNative(N_CLASS(NObject)::ToHandle(this->pOwner), value));
	}
};

template<typename T, typename TOwner, bool cache = true, bool oldSkool = false> class N_CLASS(NObjectCollection) : public N_CLASS(NSimpleCollection)<T *, TOwner>
{
private:
	static void UnrefIf(typename T::HandleType & hItem, bool isOldSkool)
	{
		if (!isOldSkool)
		{
			N_CLASS(NObject)::Unref(hItem);
			hItem = NULL;
		}
	}

protected:
	N_CLASS(NObjectCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleCollection)<T *, TOwner>(pOwner)
	{
	}

	virtual bool SupportsAddWithOutIndex() const
	{
		return !oldSkool;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		NInt count = this->GetCount();
		if (arValues)
		{
			N_CLASS(NObjectArray)<T> items(count, !oldSkool, cache);
			count = NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), items.GetPtr(), items.GetCount()));
			items.CopyTo(arValues, valuesLength, count);
		}
		return count;
	}

	virtual void SetInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value)
	{
		NCheck(SetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, N_CLASS(NObject)::ToHandle(value)));
	}

	virtual void AddPlainInternal(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value)
	{
		NCheck(AddNative(N_CLASS(NObject)::ToHandle(this->pOwner), N_CLASS(NObject)::ToHandle(value)));
	}

	virtual NInt AddWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value)
	{
		NInt index;
		NCheck(AddWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), N_CLASS(NObject)::ToHandle(value), &index));
		return index;
	}

	virtual void InsertInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value)
	{
		NCheck(InsertNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, N_CLASS(NObject)::ToHandle(value)));
	}

	virtual NInt RemoveWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value)
	{
		NInt index;
		NCheck(RemoveWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), N_CLASS(NObject)::ToHandle(value), &index));
		return index;
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value2) const
	{
		return N_CLASS(NObject)::Equals(value1, value2);
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt index, typename T::HandleType * phValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, typename T::HandleType * arhValues, NInt valuesLength) const = 0;
	virtual NResult SetNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt index, typename T::HandleType hValue) = 0;
	virtual NResult AddNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, typename T::HandleType hValue) = 0;
	virtual NResult AddWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, typename T::HandleType hValue, NInt * pIndex) = 0;
	virtual NResult InsertNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt index, typename T::HandleType hValue) = 0;
	virtual NResult RemoveWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, typename T::HandleType hValue, NInt * pIndex) = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemType Get(NInt index) const
	{
		typename T::HandleType hItem;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &hItem));
		try
		{
			return N_CLASS(NObject)::FromHandle<T>(hItem, !oldSkool, cache);
		}
		catch (...)
		{
			UnrefIf(hItem, oldSkool);
			throw;
		}
	}

	virtual NInt IndexOf(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value) const
	{
		return IndexOf(N_CLASS(NObject)::ToHandle(value));
	}

	NInt IndexOf(typename T::HandleType handle) const
	{
		NInt count = this->GetCount();
		typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType hOwner = N_CLASS(NObject)::ToHandle(this->pOwner);
		for (NInt i = 0; i < count; i++)
		{
			typename T::HandleType hItem;
			NCheck(GetNative(hOwner, i, &hItem));
			try
			{
				NBool r;
				NCheck(NObjectEquals(handle, hItem, &r));
				UnrefIf(hItem, oldSkool);
				if (r) return i;
			}
			catch (...)
			{
				UnrefIf(hItem, oldSkool);
				throw;
			}
		}
		return -1;
	}

	using N_CLASS(NReadOnlyCollection)<T *, TOwner>::Contains;
	using N_CLASS(NReadOnlyCollection)<T *, TOwner>::operator[];

	virtual NBool Contains(typename T::HandleType handle) const
	{
		return IndexOf(handle) != -1;
	}

	typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemType Get(typename T::HandleType handle) const
	{
		NInt index = IndexOf(handle);
		return index == -1 ? NULL : Get(index);
	}

	typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemType operator[](typename T::HandleType handle) const
	{
		return Get(handle);
	}
};

template<typename T, typename TOwner> class N_CLASS(NValueCollection) : public N_CLASS(NSimpleCollection)<T, TOwner>
{
protected:
	N_CLASS(NValueCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleCollection)<T, TOwner>(pOwner)
	{
	}

	virtual bool SupportsGetAll() const
	{
		return true;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), arValues, valuesLength));
	}

	virtual void SetInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NCheck(SetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, value));
	}

	virtual void AddPlainInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NCheck(AddNative(N_CLASS(NObject)::ToHandle(this->pOwner), value));
	}

	virtual NInt AddWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index;
		NCheck(AddWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), value, &index));
		return index;
	}

	virtual void InsertInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NCheck(InsertNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, value));
	}

	virtual NInt RemoveWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index;
		NCheck(RemoveWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), value, &index));
		return index;
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value2) const
	{
		return value1 == value2;
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, T * pValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, T * arValues, NInt valuesLength) const = 0;
	virtual NResult SetNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, T value) = 0;
	virtual NResult AddNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, T value) = 0;
	virtual NResult AddWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, T value, NInt * pIndex) = 0;
	virtual NResult InsertNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, T value) = 0;
	virtual NResult RemoveWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, T value, NInt * pIndex) = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType Get(NInt index) const
	{
		typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType value;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &value));
		return value;
	}
};

template<typename TOwner> class N_CLASS(NStringCollection) : public N_CLASS(NSimpleCollection)<N_CLASS(NString), TOwner>
{
protected:
	N_CLASS(NStringCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleCollection)<N_CLASS(NString), TOwner>(pOwner)
	{
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), reinterpret_cast<HNString *>(arValues), valuesLength));
	}

	virtual void SetInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value)
	{
		SetRaw(index, value);
	}

	virtual void AddPlainInternal(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value)
	{
		AddRaw(value);
	}

	virtual NInt AddWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value)
	{
		return AddWithOutIndexRaw(value);
	}

	virtual void InsertInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value)
	{
		InsertRaw(index, value);
	}

	virtual NInt RemoveWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value)
	{
		return RemoveRaw(value);
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemConstRefType value2) const
	{
		return value1 == value2;
	}

	void SetRaw(NInt index, const N_CLASS(NStringWrapper) & value)
	{
		NCheck(SetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, value.GetHandle()));
	}

	void AddRaw(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(AddNative(N_CLASS(NObject)::ToHandle(this->pOwner), value.GetHandle()));
	}

	NInt AddWithOutIndexRaw(const N_CLASS(NStringWrapper) & value)
	{
		NInt index;
		NCheck(AddWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), value.GetHandle(), &index));
		return index;
	}

	void InsertRaw(NInt index, const N_CLASS(NStringWrapper) & value)
	{
		NCheck(InsertNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, value.GetHandle()));
	}

	int RemoveRaw(const N_CLASS(NStringWrapper) & value)
	{
		NInt index;
		NCheck(RemoveWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), value.GetHandle(), &index));
		return index;
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, NInt index, HNString * phValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, HNString * arhValues, NInt valuesLength) const = 0;
	virtual NResult SetNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, NInt index, HNString hValue) = 0;
	virtual NResult AddNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, HNString hValue) = 0;
	virtual NResult AddWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, HNString hValue, NInt * pIndex) = 0;
	virtual NResult InsertNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, NInt index, HNString hValue) = 0;
	virtual NResult RemoveWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::OwnerHandleType handle, HNString hValue, NInt * pIndex) = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::ItemType Get(NInt index) const
	{
		HNString hValue;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	using N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::Contains;
	using N_CLASS(NReadOnlyCollection)<N_CLASS(NString), TOwner>::IndexOf;
	using N_CLASS(NCollection)<N_CLASS(NString), TOwner>::Set;
	using N_CLASS(NCollection)<N_CLASS(NString), TOwner>::Add;
	using N_CLASS(NCollection)<N_CLASS(NString), TOwner>::Insert;

	virtual NInt IndexOf(const N_CLASS(NStringWrapper) & value) const
	{
		NInt count = this->GetCount();
		for (NInt i = 0; i < count; i++)
		{
			NBool r;
			NCheck(NStringEqualsN(value.GetHandle(), Get(i).GetHandle(), NFalse, &r));
			if (r) return i;
		}
		return -1;
	}

	virtual bool Contains(const N_CLASS(NStringWrapper) & value) const
	{
		return IndexOf(value) != -1;
	}

	void Set(NInt index, const N_CLASS(NStringWrapper) & value)
	{
		SetRaw(index, value);
		this->Touch();
	}

	NInt Add(const N_CLASS(NStringWrapper) & value)
	{
		NInt index;
		if (this->SupportsAddWithOutIndex())
		{
			index = AddWithOutIndexRaw(value);
		}
		else
		{
			index = this->GetCount();
			AddRaw(value);
		}
		if (index != -1) this->Touch();
		return index;
	}

	void Insert(NInt index, const N_CLASS(NStringWrapper) & value)
	{
		InsertRaw(index, value);
		this->Touch();
	}

	NInt Remove(const N_CLASS(NStringWrapper) & value)
	{
		NInt index;
		if (this->SupportsRemoveByValue())
		{
			index = RemoveRaw(value);
			if (index != -1) this->Touch();
		}
		else
		{
			index = IndexOf(value);
			if (index != -1) this->RemoveAt(index);
		}
		return index;
	}
};

template<typename T, typename TOwner, bool disposable = false> class N_CLASS(NStructCollection) : public N_CLASS(NSimpleCollection)<T, TOwner>
{
protected:
	N_CLASS(NStructCollection)(TOwner * pOwner)
		: N_CLASS(NSimpleCollection)<T, TOwner>(pOwner)
	{
	}

	virtual bool SupportsGetAll() const
	{
		return !disposable;
	}

	virtual NInt GetAllInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemPtrType arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), arValues, valuesLength));
	}

	virtual void SetInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NCheck(SetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &value));
	}

	virtual void AddPlainInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NCheck(AddNative(N_CLASS(NObject)::ToHandle(this->pOwner), &value));
	}

	virtual NInt AddWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index;
		NCheck(AddWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), &value, &index));
		return index;
	}

	virtual void InsertInternal(NInt index, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NCheck(InsertNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &value));
	}

	virtual NInt RemoveWithOutIndexInternal(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value)
	{
		NInt index;
		NCheck(RemoveWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), &value, &index));
		return index;
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemConstRefType value2) const
	{
		return false;
		N_UNREFERENCED_PARAMETER(value1);
		N_UNREFERENCED_PARAMETER(value2);
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, T * pValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, T * arValues, NInt valuesLength) const = 0;
	virtual NResult SetNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, const T * pValue) = 0;
	virtual NResult AddNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, const T * pValue) = 0;
	virtual NResult AddWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, const T * pValue, NInt * pIndex) = 0;
	virtual NResult InsertNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, NInt index, const T * pValue) = 0;
	virtual NResult RemoveWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T, TOwner>::OwnerHandleType handle, const T * pValue, NInt * pIndex) = 0;

public:
	virtual typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType Get(NInt index) const
	{
		typename N_CLASS(NReadOnlyCollection)<T, TOwner>::ItemType value;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, &value));
		return value;
	}

	void Get(NInt index, T * pValue) const
	{
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), index, pValue));
	}
};

template<typename T, typename TBase, typename TOwner> class N_CLASS(NArrayCollection) : public N_CLASS(NReadOnlyCollection)<T *, TOwner>
{
private:
	N_CLASS(NCollection)<TBase, TOwner> * pBaseCollection;

protected:
	N_CLASS(NArrayCollection)(TOwner * pOwner, N_CLASS(NCollection)<TBase, TOwner> * pBaseCollection)
		: N_CLASS(NReadOnlyCollection)<T *, TOwner>(pOwner), pBaseCollection(pBaseCollection)
	{
		if (!pBaseCollection) NThrowArgumentNullException(N_T("pBaseCollection"));
	}

	virtual NInt GetVersion() const
	{
		return pBaseCollection->GetVersion();
	}

	virtual void Touch()
	{
		pBaseCollection->Touch();
	}

	virtual bool ItemsEqual(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value1, typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value2) const
	{
		return false;
		N_UNREFERENCED_PARAMETER(value1);
		N_UNREFERENCED_PARAMETER(value2);
	}

	virtual bool ElementsEqual(const T & value1, const T & value2) const = 0;

	virtual bool SupportsGetAll() const
	{
		return false;
	}

	virtual bool SupportsAddWithOutIndex() const
	{
		return false;
	}

	virtual bool SupportsRemoveByValue() const
	{
		return false;
	}

	virtual bool SupportsRemoveRange() const
	{
		return false;
	}

	virtual NInt GetAllInternal(NInt baseIndex, T * arValues, NInt valuesLength = N_INT_MAX) const = 0;
	virtual void SetInternal(NInt baseIndex, NInt index, const T & value) = 0;
	virtual void AddPlainInternal(NInt baseIndex, const T & value) = 0;
	virtual NInt AddWithOutIndexInternal(NInt baseIndex, const T & value) = 0;
	virtual void InsertInternal(NInt baseIndex, NInt index, const T & value) = 0;
	virtual NInt RemoveWithOutIndexInternal(NInt baseIndex, const T & value) = 0;

	virtual NResult GetCountNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt * pValue) const = 0;
	virtual NResult GetCapacityNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt * pValue) const = 0;
	virtual NResult SetCapacityNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt value) = 0;
	virtual NResult RemoveAtNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index) = 0;
	virtual NResult RemoveRangeNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index, NInt count) = 0;
	virtual NResult ClearNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex) = 0;

public:
	virtual NInt GetCount() const
	{
		return pBaseCollection->GetCount();
	}

	virtual typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemType Get(NInt index) const
	{
		NThrowNotSupportedException();
		N_UNREFERENCED_PARAMETER(index);
	}

	virtual NInt IndexOf(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::ItemConstRefType value) const
	{
		return -1;
		N_UNREFERENCED_PARAMETER(value);
	}

	NInt GetCount(NInt baseIndex) const
	{
		NInt value;
		NCheck(GetCountNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, &value));
		return value;
	}

	NInt GetCapacity(NInt baseIndex) const
	{
		NInt value;
		NCheck(GetCapacityNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, &value));
		return value;
	}

	void SetCapacity(NInt baseIndex, NInt value) const
	{
		NCheck(SetCapacityNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, value));
	}

	virtual T Get(NInt baseIndex, NInt index) const = 0;

	NInt GetAll(NInt baseIndex, T * arValues, NInt valuesLength = N_INT_MAX) const
	{
		if (!SupportsGetAll())
		{
			NInt count = GetCount(baseIndex);
			if (arValues)
			{
				if (valuesLength < count)  NThrowArgumentInsufficientException(N_T("valuesLength"));
				for (NInt i = 0; i < count; i++)
				{
					arValues[i] = Get(baseIndex, i);
				}
			}
			return count;
		}
		else
		{
			return GetAllInternal(baseIndex, arValues, valuesLength);
		}
	}

	virtual NInt IndexOf(NInt baseIndex, const T & value) const
	{
		NInt count = GetCount(baseIndex);
		for (NInt i = 0; i < count; i++)
		{
			if (ElementsEqual(value, Get(baseIndex, i))) return i;
		}
		return -1;
	}

	virtual bool Contains(NInt baseIndex, const T & value) const
	{
		return IndexOf(baseIndex, value) != -1;
	}

	void Set(NInt baseIndex, NInt index, const T & value)
	{
		SetInternal(baseIndex, index, value);
		this->Touch();
	}

	NInt Add(NInt baseIndex, const T & value)
	{
		NInt index;
		if (SupportsAddWithOutIndex())
		{
			index = AddWithOutIndexInternal(baseIndex, value);
		}
		else
		{
			index = GetCount(baseIndex);
			AddPlainInternal(baseIndex, value);
		}
		return index;
	}

	void Insert(NInt baseIndex, NInt index, const T & value)
	{
		InsertInternal(baseIndex, index, value);
		this->Touch();
	}

	NInt Remove(NInt baseIndex, const T & value)
	{
		NInt index;
		if (SupportsRemoveByValue())
		{
			index = RemoveWithOutIndexInternal(baseIndex, value);
			if (index != -1)
			{
				this->Touch();
			}
		}
		else
		{
			NInt index = IndexOf(baseIndex, value);
			if (index != -1)
			{
				RemoveAt(baseIndex, index);
			}
		}
		return index;
	}

	void RemoveAt(NInt baseIndex, NInt index)
	{
		NCheck(RemoveAtNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, index));
		this->Touch();
	}

	void RemoveRange(NInt baseIndex, NInt index, NInt count)
	{
		if (SupportsRemoveRange())
		{
			NCheck(RemoveRangeNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, index, count));
			this->Touch();
		}
		else if (index == 0 && count == GetCount(baseIndex))
		{
			Clear(baseIndex);
		}
		else if (count == 1)
		{
			RemoveAt(baseIndex, index);
		}
		else
		{
			if (index < 0) NThrowArgumentLessThanZeroException(N_T("index"));
			if (count < 0) NThrowArgumentLessThanZeroException(N_T("count"));
			if (index + count > GetCount(baseIndex)) NThrowArgumentException(N_T("index plus count is greater than GetCount(baseIndex)"));
			typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType hOwner = N_CLASS(NObject)::ToHandle(this->pOwner);
			for (NInt i = count - 1; i >= 0; i--)
			{
				NCheck(RemoveAtNative(hOwner, baseIndex, index + i));
			}
			this->Touch();
		}
	}

	void Clear(NInt baseIndex)
	{
		NCheck(ClearNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex));
		this->Touch();
	}
};

template<typename T, typename TBase, typename TOwner> class N_CLASS(NValueArrayCollection) : public N_CLASS(NArrayCollection)<T, TBase, TOwner>
{
protected:
	N_CLASS(NValueArrayCollection)(TOwner * pOwner, N_CLASS(NCollection)<TBase, TOwner> * pBaseCollection)
		: N_CLASS(NArrayCollection)<T, TBase, TOwner>(pOwner, pBaseCollection)
	{
	}

	virtual bool ElementsEqual(const T & value1, const T & value2) const
	{
		return value1 == value2;
	}

	virtual bool SupportsGetAll() const
	{
		return true;
	}

	virtual NInt GetAllInternal(NInt baseIndex, T * arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, arValues, valuesLength));
	}

	virtual void SetInternal(NInt baseIndex, NInt index, const T & value)
	{
		NCheck(SetNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, index, value));
		this->Touch();
	}

	virtual void AddPlainInternal(NInt baseIndex, const T & value)
	{
		NCheck(AddNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, value));
	}

	virtual NInt AddWithOutIndexInternal(NInt baseIndex, const T & value)
	{
		NInt index;
		NCheck(AddWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, value, &index));
		return index;
	}

	virtual void InsertInternal(NInt baseIndex, NInt index, const T & value)
	{
		NCheck(InsertNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, index, value));
	}

	virtual NInt RemoveWithOutIndexInternal(NInt baseIndex, const T & value)
	{
		NInt index;
		NCheck(RemoveWithOutIndexNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, value, &index));
		return index;
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index, T * pValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, T * arValues, NInt valuesLength) const = 0;
	virtual NResult SetNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index, T value) = 0;
	virtual NResult AddNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, T value) = 0;
	virtual NResult AddWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, T value, NInt * pIndex) = 0;
	virtual NResult InsertNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index, T value) = 0;
	virtual NResult RemoveWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, T value, NInt * pIndex) = 0;

public:
	virtual T Get(NInt baseIndex, NInt index) const
	{
		T value;
		NCheck(GetNative(N_CLASS(NObject)::ToHandle(this->pOwner), baseIndex, index, &value));
		return value;
	}
};

template<typename T, typename TBase, typename TOwner, bool disposable = false> class N_CLASS(NStructArrayCollection) : public N_CLASS(NArrayCollection)<T, TBase, TOwner>
{
protected:
	N_CLASS(NStructArrayCollection)(TOwner * pOwner, N_CLASS(NCollection)<TBase, TOwner> * pBaseCollection)
		: N_CLASS(NArrayCollection)<T, TBase, TOwner>(pOwner, pBaseCollection)
	{
	}

	virtual bool ElementsEqual(const T & value1, const T & value2) const
	{
		return false;
		N_UNREFERENCED_PARAMETER(value1);
		N_UNREFERENCED_PARAMETER(value2);
	}

	virtual bool SupportsGetAll() const
	{
		return !disposable;
	}

	virtual NInt GetAllInternal(NInt baseIndex, T * arValues, NInt valuesLength = N_INT_MAX) const
	{
		return NCheck(GetAllNative(this->pOwner->GetHandle(), baseIndex, arValues, valuesLength));
	}

	virtual void SetInternal(NInt baseIndex, NInt index, const T & value)
	{
		NCheck(SetNative(this->pOwner->GetHandle(), baseIndex, index, &value));
	}

	virtual void AddPlainInternal(NInt baseIndex, const T & value)
	{
		NCheck(AddNative(this->pOwner->GetHandle(), baseIndex, &value));
	}

	virtual NInt AddWithOutIndexInternal(NInt baseIndex, const T & value)
	{
		NInt index;
		NCheck(AddWithOutIndexNative(this->pOwner->GetHandle(), baseIndex, &value, &index));
		return index;
	}

	virtual NInt RemoveWithOutIndexInternal(NInt baseIndex, const T & value)
	{
		NInt index;
		NCheck(RemoveWithOutIndexNative(this->pOwner->GetHandle(), baseIndex, &value, &index));
		return index;
	}

	virtual void InsertInternal(NInt baseIndex, NInt index, const T & value)
	{
		NCheck(InsertNative(this->pOwner->GetHandle(), baseIndex, index, &value));
	}

	virtual NResult GetNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index, T * pValue) const = 0;
	virtual NResult GetAllNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, T * arValues, NInt valuesLength) const = 0;
	virtual NResult SetNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index, const T * pValue) = 0;
	virtual NResult AddNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, const T * pValue) = 0;
	virtual NResult AddWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, const T * pValue, NInt * pIndex) = 0;
	virtual NResult InsertNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, NInt index, const T * pValue) = 0;
	virtual NResult RemoveWithOutIndexNative(typename N_CLASS(NReadOnlyCollection)<T *, TOwner>::OwnerHandleType handle, NInt baseIndex, const T * pValue, NInt * pIndex) = 0;

public:
	virtual T Get(NInt baseIndex, NInt index) const
	{
		T value;
		NCheck(GetNative(this->pOwner->GetHandle(), baseIndex, index, &value));
		return value;
	}

	void Get(NInt baseIndex, NInt index, T * pValue) const
	{
		NCheck(GetNative(this->pOwner->GetHandle(), baseIndex, index, pValue));
	}
};

}}

#include <NReDeprecate.h>

#endif // !N_COLLECTIONS_HPP_INCLUDED
