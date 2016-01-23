#ifndef N_PROPERTY_BAG_HPP_INCLUDED
#define N_PROPERTY_BAG_HPP_INCLUDED

#include <NValue.hpp>
#include <NCollections.hpp>
namespace Neurotec
{
#include <NPropertyBag.h>
}

namespace Neurotec
{

class N_CLASS(NPropertyBag) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NPropertyBag, NObject)

public:
	class KeyCollection : public ::Neurotec::Collections::N_CLASS(NStringReadOnlyCollection)<N_CLASS(NPropertyBag)>
	{
		KeyCollection(N_CLASS(NPropertyBag) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStringReadOnlyCollection)<N_CLASS(NPropertyBag)>(pOwner)
		{
		}

	protected:
		virtual NInt GetVersion() const
		{
			return pOwner->version;
		}

		virtual NResult GetCountNative(HNPropertyBag handle, NInt * pValue) const
		{
			return NPropertyBagGetCount(handle, pValue);
		}

		virtual NResult GetNative(HNPropertyBag handle, NInt index, HNString * phValue) const
		{
			return NPropertyBagGetKey(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNPropertyBag, HNString *, NInt) const
		{
			NThrowNotImplementedException();
		}

	public:
		virtual bool Contains(const N_CLASS(NString) & value) const
		{
			return pOwner->Contains(value);
		}

		virtual bool Contains(const N_CLASS(NStringWrapper) & value) const
		{
			return pOwner->Contains(value);
		}

		friend class N_CLASS(NPropertyBag);
	};

	class ValueCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NValue), N_CLASS(NPropertyBag), false>
	{
		ValueCollection(N_CLASS(NPropertyBag) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NValue), N_CLASS(NPropertyBag), false>(pOwner)
		{
		}

	protected:
		virtual NInt GetVersion() const
		{
			return pOwner->version;
		}

		virtual NResult GetCountNative(HNPropertyBag handle, NInt * pValue) const
		{
			return NPropertyBagGetCount(handle, pValue);
		}

		virtual NResult GetNative(HNPropertyBag handle, NInt index, HNValue * phValue) const
		{
			return NPropertyBagGetValue(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNPropertyBag, HNValue *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NPropertyBag);
	};

private:
	static HNPropertyBag Create()
	{
		HNPropertyBag handle;
		NCheck(NPropertyBagCreate(&handle));
		return handle;
	}

	::std::auto_ptr<KeyCollection> keys;
	::std::auto_ptr<ValueCollection> values;
	int version;

	N_CLASS(NPropertyBag)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		keys.reset(new KeyCollection(this));
		values.reset(new ValueCollection(this));
		version = 0;
	}

	void Touch()
	{
		version++;
	}

public:
	class ConstIterator
	{
	private:
		const N_CLASS(NPropertyBag) & propertyBag;
		bool reverse;
		NInt index;
		NInt count;
		NInt version;

		ConstIterator(const N_CLASS(NPropertyBag) & propertyBag, NInt index, bool reverse = false)
			: propertyBag(propertyBag), reverse(reverse), index(index), count(propertyBag.GetCount()), version(propertyBag.version)
		{
		}

	public:
		ConstIterator(const ConstIterator & value)
			: propertyBag(value.propertyBag), reverse(value.reverse), index(value.index), count(value.count), version(value.version)
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

		N_CLASS(NNameValuePair) operator*() const
		{
			if (propertyBag.version != version) NThrowInvalidOperationException();
			return propertyBag.Get(index);
		}

		bool operator==(const ConstIterator & value) const
		{
			if (&propertyBag != &value.propertyBag) NThrowInvalidOperationException();
			return index == value.index;
		}

		bool operator!=(const ConstIterator & value) const
		{
			if (&propertyBag != &value.propertyBag) NThrowInvalidOperationException();
			return index != value.index;
		}

		bool operator>(const ConstIterator & value) const
		{
			if (&propertyBag != &value.propertyBag) NThrowInvalidOperationException();
			return index > value.index;
		}

		bool operator>=(const ConstIterator & value) const
		{
			if (&propertyBag != &value.propertyBag) NThrowInvalidOperationException();
			return index >= value.index;
		}

		bool operator<(const ConstIterator & value) const
		{
			if (&propertyBag != &value.propertyBag) NThrowInvalidOperationException();
			return index < value.index;
		}

		bool operator<=(const ConstIterator & value) const
		{
			if (&propertyBag != &value.propertyBag) NThrowInvalidOperationException();
			return index <= value.index;
		}

		ConstIterator & operator=(const ConstIterator & value)
		{
			if (&propertyBag != &value.propertyBag || version != value.version) NThrowInvalidOperationException();
			index = value.index;
		}

		friend class N_CLASS(NPropertyBag);
	};

	static bool TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, N_CLASS(NPropertyBag) * * ppValue)
	{
		if (!ppValue) NThrowArgumentNullException(N_T("ppValue"));
		NBool result;
		HNPropertyBag hValue;
		NCheck(NPropertyBagTryParseN(value.GetHandle(), format.GetHandle(), &hValue, &result));
		try
		{
			*ppValue = FromHandle<N_CLASS(NPropertyBag)>(hValue);
			return result != 0;
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}
	static bool TryParse(const N_CLASS(NStringWrapper) & value, N_CLASS(NPropertyBag) * * ppValue) { return TryParse(value, N_CLASS(NString)(), ppValue); }

	static N_CLASS(NPropertyBag) * Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNPropertyBag hValue;
		NCheck(NPropertyBagParseN(value.GetHandle(), format.GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NPropertyBag)>(hValue);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	N_CLASS(NPropertyBag)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NPropertyBag);
		Init();
	}

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

	NInt GetCount() const
	{
		NInt value;
		NCheck(NPropertyBagGetCount(GetHandle(), &value));
		return value;
	}

	N_CLASS(NNameValuePair) Get(NInt index) const
	{
		N_CLASS(NNameValuePair) value;
		NCheck(NPropertyBagGetAt(GetHandle(), index, &value));
		return value;
	}

	void Add(const N_CLASS(NNameValuePair) & value)
	{
		NCheck(NPropertyBagAddPair(GetHandle(), &value));
		Touch();
	}

	void RemoveAt(NInt index)
	{
		NCheck(NPropertyBagRemoveAt(GetHandle(), index));
		Touch();
	}

	void Clear()
	{
		NCheck(NPropertyBagClear(GetHandle()));
		Touch();
	}

	bool Contains(const N_CLASS(NStringWrapper) & key) const
	{
		NBool result;
		NCheck(NPropertyBagContainsN(GetHandle(), key.GetHandle(), &result));
		return result != 0;
	}

	N_CLASS(NValue) * Get(const N_CLASS(NStringWrapper) & key) const
	{
		HNValue hValue;
		NCheck(NPropertyBagGetN(GetHandle(), key.GetHandle(), &hValue));
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

	bool TryGet(const N_CLASS(NStringWrapper) & key, N_CLASS(NValue) * * ppValue) const
	{
		if (!ppValue) NThrowArgumentNullException(N_T("ppValue"));
		HNValue hValue;
		NBool result;
		NCheck(NPropertyBagTryGetN(GetHandle(), key.GetHandle(), &hValue, &result));
		try
		{
			*ppValue = FromHandle<N_CLASS(NValue)>(hValue);
			return result != 0;
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void Add(const N_CLASS(NStringWrapper) & key, N_CLASS(NValue) * pValue)
	{
		NCheck(NPropertyBagAddN(GetHandle(), key.GetHandle(), ToHandle(pValue)));
		Touch();
	}

	void Set(const N_CLASS(NStringWrapper) & key, N_CLASS(NValue) * pValue)
	{
		NCheck(NPropertyBagSetN(GetHandle(), key.GetHandle(), ToHandle(pValue)));
		Touch();
	}

	bool Remove(const N_CLASS(NStringWrapper) & key)
	{
		NBool result;
		NCheck(NPropertyBagRemoveN(GetHandle(), key.GetHandle(), &result));
		if (result) Touch();
		return result != 0;
	}

	void ApplyTo(N_CLASS(NObject) * pObject) const
	{
		NCheck(NPropertyBagApplyTo(GetHandle(), ToHandle(pObject)));
	}

	KeyCollection * GetKeys()
	{
		return keys.get();
	}

	ValueCollection * GetValues()
	{
		return values.get();
	}

	N_CLASS(NNameValuePair) operator[](NInt index) const
	{
		return Get(index);
	}

	N_CLASS(NValue) * operator[](const N_CLASS(NStringWrapper) & key) const
	{
		return Get(key);
	}
};

}

#endif // !N_PROPERTY_BAG_HPP_INCLUDED
