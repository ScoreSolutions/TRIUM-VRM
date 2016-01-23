#ifndef N_PARAMETER_BAG_HPP_INCLUDED
#define N_PARAMETER_BAG_HPP_INCLUDED

#include <NParameterDescriptor.hpp>
#include <NPropertyBag.hpp>
#include <NCollections.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NParameterBag.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NParameterBag) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NParameterBag, NObject)

public:
	class KeyCollection : public ::Neurotec::Collections::N_CLASS(NStringReadOnlyCollection)<N_CLASS(NParameterBag)>
	{
		KeyCollection(N_CLASS(NParameterBag) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStringReadOnlyCollection)<N_CLASS(NParameterBag)>(pOwner)
		{
		}

	protected:
		virtual NInt GetVersion() const
		{
			return pOwner->version;
		}

		virtual NResult GetCountNative(HNParameterBag handle, NInt * pValue) const
		{
			return NParameterBagGetCount(handle, pValue);
		}

		virtual NResult GetNative(HNParameterBag handle, NInt index, HNString * phValue) const
		{
			return NParameterBagGetKey(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNParameterBag, HNString *, NInt) const
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

		friend class N_CLASS(NParameterBag);
	};

	class ValueCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NValue), N_CLASS(NParameterBag), false>
	{
		ValueCollection(N_CLASS(NParameterBag) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NValue), N_CLASS(NParameterBag), false>(pOwner)
		{
		}

	protected:
		virtual NInt GetVersion() const
		{
			return pOwner->version;
		}

		virtual void Touch()
		{
			pOwner->Touch();
		}

		virtual NResult GetCountNative(HNParameterBag handle, NInt * pValue) const
		{
			return NParameterBagGetCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNParameterBag, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNParameterBag, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNParameterBag handle, NInt index, HNValue * phValue) const
		{
			return NParameterBagGetValue(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNParameterBag, HNValue *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNParameterBag handle, NInt index, HNValue hValue)
		{
			return NParameterBagSetValue(handle, index, hValue);
		}

		virtual NResult AddNative(HNParameterBag, HNValue)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNParameterBag, HNValue, NInt *)
		{
			NThrowNotSupportedException();
		}

		virtual NResult InsertNative(HNParameterBag, NInt, HNValue)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveWithOutIndexNative(HNParameterBag, HNValue, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNParameterBag, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveRangeNative(HNParameterBag, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNParameterBag)
		{
			NThrowNotSupportedException();
		}

		friend class N_CLASS(NParameterBag);
	};

private:
	static HNParameterBag Create(N_CLASS(NParameterDescriptor) * const * arpParameters, NInt parameterCount)
	{
		N_CLASS(NObjectArray)<N_CLASS(NParameterDescriptor)> parameters(arpParameters, parameterCount);
		HNParameterBag handle;
		NCheck(NParameterBagCreate(parameters.GetPtr(), parameters.GetCount(), &handle));
		return handle;
	}

	::std::auto_ptr<KeyCollection> keys;
	::std::auto_ptr<ValueCollection> values;
	int version;

	N_CLASS(NParameterBag)(HNObject handle, bool claimHandle)
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
		const N_CLASS(NParameterBag) & parameterBag;
		bool reverse;
		NInt index;
		NInt count;
		NInt version;

		ConstIterator(const N_CLASS(NParameterBag) & parameterBag, NInt index, bool reverse = false)
			: parameterBag(parameterBag), reverse(reverse), index(index), count(parameterBag.GetCount()), version(parameterBag.version)
		{
		}

	public:
		ConstIterator(const ConstIterator & value)
			: parameterBag(value.parameterBag), reverse(value.reverse), index(value.index), count(value.count), version(value.version)
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
			if (parameterBag.version != version) NThrowInvalidOperationException();
			return parameterBag.Get(index);
		}

		bool operator==(const ConstIterator & value) const
		{
			if (&parameterBag != &value.parameterBag) NThrowInvalidOperationException();
			return index == value.index;
		}

		bool operator!=(const ConstIterator & value) const
		{
			if (&parameterBag != &value.parameterBag) NThrowInvalidOperationException();
			return index != value.index;
		}

		bool operator>(const ConstIterator & value) const
		{
			if (&parameterBag != &value.parameterBag) NThrowInvalidOperationException();
			return index > value.index;
		}

		bool operator>=(const ConstIterator & value) const
		{
			if (&parameterBag != &value.parameterBag) NThrowInvalidOperationException();
			return index >= value.index;
		}

		bool operator<(const ConstIterator & value) const
		{
			if (&parameterBag != &value.parameterBag) NThrowInvalidOperationException();
			return index < value.index;
		}

		bool operator<=(const ConstIterator & value) const
		{
			if (&parameterBag != &value.parameterBag) NThrowInvalidOperationException();
			return index <= value.index;
		}

		ConstIterator & operator=(const ConstIterator & value)
		{
			if (&parameterBag != &value.parameterBag || version != value.version) NThrowInvalidOperationException();
			index = value.index;
		}

		friend class N_CLASS(NParameterBag);
	};

	N_CLASS(NParameterBag)(N_CLASS(NParameterDescriptor) * const * arpParameters, NInt parameterCount)
		: N_CLASS(NObject)(Create(arpParameters, parameterCount), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NParameterBag);
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
		NCheck(NParameterBagGetCount(GetHandle(), &value));
		return value;
	}

	N_CLASS(NNameValuePair) Get(NInt index) const
	{
		N_CLASS(NNameValuePair) value;
		NCheck(NParameterBagGetAt(GetHandle(), index, &value));
		return value;
	}

	bool Contains(const N_CLASS(NStringWrapper) & key) const
	{
		NBool result;
		NCheck(NParameterBagContainsN(GetHandle(), key.GetHandle(), &result));
		return result != 0;
	}

	N_CLASS(NValue) * Get(const N_CLASS(NStringWrapper) & key) const
	{
		HNValue hValue;
		NCheck(NParameterBagGetN(GetHandle(), key.GetHandle(), &hValue));
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
		NCheck(NParameterBagTryGetN(GetHandle(), key.GetHandle(), &hValue, &result));
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

	void Set(const N_CLASS(NStringWrapper) & key, N_CLASS(NValue) * pValue)
	{
		NCheck(NParameterBagSetN(GetHandle(), key.GetHandle(), ToHandle(pValue)));
		Touch();
	}

	void Apply(N_CLASS(NPropertyBag) * pValue, bool ignoreUnknown = false)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NCheck(NParameterBagApplyPropertyBag(GetHandle(), pValue->GetHandle(), ignoreUnknown ? NTrue : NFalse));
	}

	N_CLASS(NPropertyBag) * ToPropertyBag() const
	{
		HNPropertyBag hValue;
		NCheck(NParameterBagToPropertyBag(GetHandle(), &hValue));
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

}}

#endif // !N_PARAMETER_BAG_HPP_INCLUDED
