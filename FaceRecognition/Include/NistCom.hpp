#ifndef NIST_COM_HPP_INCLUDED
#define NIST_COM_HPP_INCLUDED

#include <NObject.hpp>
namespace Neurotec { namespace Images
{
#include <NistCom.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NistCom) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NistCom, NObject)

public:
	class ItemCollection : public ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NNameStringPair), N_CLASS(NistCom), true>
	{
		ItemCollection(N_CLASS(NistCom) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NNameStringPair), N_CLASS(NistCom), true>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNistCom handle, NInt * pValue) const
		{
			return NistComGetItemCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNistCom, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNistCom, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNistCom handle, NInt index, N_CLASS(NNameStringPair) * pValue) const
		{
			return NistComGetItem(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNistCom, N_CLASS(NNameStringPair) *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNistCom handle, NInt index, const N_CLASS(NNameStringPair) * pValue)
		{
			return NistComSetItem(handle, index, pValue);
		}

		virtual NResult AddNative(HNistCom handle, const N_CLASS(NNameStringPair) * pValue)
		{
			return NistComAddItem(handle, pValue);
		}

		virtual NResult AddWithOutIndexNative(HNistCom, const N_CLASS(NNameStringPair) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNistCom handle, NInt index, const N_CLASS(NNameStringPair) * pValue)
		{
			return NistComInsertItem(handle, index, pValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNistCom, const N_CLASS(NNameStringPair) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNistCom handle, NInt index)
		{
			return NistComRemoveItemAt(handle, index);
		}

		virtual NResult RemoveRangeNative(HNistCom, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNistCom handle)
		{
			return NistComClearItems(handle);
		}

	public:
		N_CLASS(NString) Get(const N_CLASS(NStringWrapper) & key) const
		{
			HNString hValue;
			NCheck(NistComGetValueN(pOwner->GetHandle(), key.GetHandle(), &hValue));
			return N_CLASS(NString)(hValue, true);
		}

		void Set(const N_CLASS(NStringWrapper) & key, const N_CLASS(NStringWrapper) & value)
		{
			NCheck(NistComSetValueN(pOwner->GetHandle(), key.GetHandle(), value.GetHandle()));
		}

		void Add(const N_CLASS(NStringWrapper) & key, const N_CLASS(NStringWrapper) & value)
		{
			NCheck(NistComAddValueN(pOwner->GetHandle(), key.GetHandle(), value.GetHandle()));
		}

		friend class N_CLASS(NistCom);
	};

private:
	static HNistCom Create(NUInt flags)
	{
		HNistCom handle;
		NCheck(NistComCreate(flags, &handle));
		return handle;
	}

	static HNistCom Create(const N_CLASS(NStringWrapper) & fileName, NUInt flags)
	{
		HNistCom handle;
		NCheck(NistComCreateFromFileN(fileName.GetHandle(), flags, &handle));
		return handle;
	}

	static HNistCom Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNistCom handle;
		NCheck(NistComCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNistCom Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNistCom handle;
		NCheck(NistComCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	static HNistCom Create(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNistCom handle;
		NCheck(NistComCreateFromStream(pStream->GetHandle(), flags, &handle));
		return handle;
	}

	::std::auto_ptr<ItemCollection> items;

	N_CLASS(NistCom)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		items.reset(new ItemCollection(this));
	}

public:
	explicit N_CLASS(NistCom)(NUInt flags = 0)
		: N_CLASS(NObject)(Create(flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NistCom);
		Init();
	}

	explicit N_CLASS(NistCom)(const N_CLASS(NStringWrapper) & fileName, NUInt flags = 0)
		: N_CLASS(NObject)(Create(fileName, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NistCom);
		Init();
	}

	explicit N_CLASS(NistCom)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NistCom);
		Init();
	}

	N_CLASS(NistCom)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NistCom);
		Init();
	}

	explicit N_CLASS(NistCom)(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0)
		: N_CLASS(NObject)(Create(pStream, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NistCom);
		Init();
	}

	void Save(const N_CLASS(NStringWrapper) & fileName, NUInt flags = 0) const
	{
		NCheck(NistComSaveToFileN(GetHandle(), fileName.GetHandle(), flags));
	}

	ItemCollection * GetItems()
	{
		return items.get();
	}
};

}}

#endif // !NIST_COM_HPP_INCLUDED
