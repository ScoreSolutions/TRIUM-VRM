#ifndef NE_TEMPLATE_HPP_INCLUDED
#define NE_TEMPLATE_HPP_INCLUDED

#include <NERecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NETemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NET_MAX_RECORD_COUNT
#undef NET_PROCESS_FIRST_RECORD_ONLY

const NInt NET_MAX_RECORD_COUNT = 255;
const NUInt NET_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class N_CLASS(NETemplate) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NETemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NERecord), N_CLASS(NETemplate)>
	{
		RecordCollection(N_CLASS(NETemplate) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NERecord), N_CLASS(NETemplate)>(pOwner)
		{
		}

		friend class N_CLASS(NETemplate);

	protected:
		virtual NResult GetCountNative(HNETemplate handle, NInt * pValue) const
		{
			return NETemplateGetRecordCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNETemplate handle, NInt * pValue) const
		{
			return NETemplateGetRecordCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNETemplate handle, NInt value)
		{
			return NETemplateSetRecordCapacity(handle, value);
		}

		virtual NResult GetNative(HNETemplate handle, NInt index, HNERecord * phValue) const
		{
			return NETemplateGetRecordEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNETemplate, HNERecord *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNETemplate handle, NInt index, HNERecord hValue)
		{
			return NETemplateSetRecord(handle, index, hValue);
		}

		virtual NResult AddNative(HNETemplate, HNERecord)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNETemplate handle, HNERecord hValue, NInt * pIndex)
		{
			return NETemplateAddRecordEx(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNETemplate handle, NInt index, HNERecord hValue)
		{
			return NETemplateInsertRecord(handle, index, hValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNETemplate, HNERecord, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNETemplate handle, NInt index)
		{
			return NETemplateRemoveRecord(handle, index);
		}

		virtual NResult RemoveRangeNative(HNETemplate, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNETemplate handle)
		{
			return NETemplateClearRecords(handle);
		}

	public:
		using ::Neurotec::Collections::N_CLASS(NCollection)<N_CLASS(NERecord) *, N_CLASS(NETemplate)>::Add;

	#include <NNoDeprecate.h>
		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NERecord)) " constructor and Add instead")
		N_CLASS(NERecord) * Add(NUShort width, NUShort height, NUInt flags = 0)
		{
			HNERecord hRecord;
			NCheck(NETemplateAddRecord(pOwner->GetHandle(), width, height, flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NERecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NERecord)) " constructor and Add instead")
		N_CLASS(NERecord) * Add(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
			HNERecord hRecord;
			NCheck(NETemplateAddRecordFromMemoryN(pOwner->GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NERecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NERecord)) " constructor and Add instead")
		N_CLASS(NERecord) * Add(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			HNERecord hRecord;
			NCheck(NETemplateAddRecordFromMemoryEx(pOwner->GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NERecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and Add instead")
		N_CLASS(NERecord) * AddCopy(N_CLASS(NERecord)* pSrcRecord, NUInt flags = 0)
		{
			if (!pSrcRecord) NThrowArgumentNullException(N_T("pSrcRecord"));
			HNERecord hRecord;
			NCheck(NETemplateAddRecordCopyEx(pOwner->GetHandle(), pSrcRecord->GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NERecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}
	#include <NReDeprecate.h>
	};

private:
	static HNETemplate Create(NUInt flags)
	{
		HNETemplate handle;
		NCheck(NETemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNETemplate Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNETemplate handle;
		NCheck(NETemplateCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNETemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNETemplate handle;
		NCheck(NETemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	::std::auto_ptr<RecordCollection> records;

	N_CLASS(NETemplate)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		records.reset(new RecordCollection(this));
	}

public:
	static NSizeType CalculateSize(NInt recordCount, NSizeType * arRecordSizes)
	{
		NSizeType value;
		NCheck(NETemplateCalculateSize(recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NETemplatePack(recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		N_CLASS(NVersion) * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NETemplateUnpack(pBuffer, bufferSize,
			pVersion ? &v : NULL, pSize, pHeaderSize,
			pRecordCount, arPRecords, arRecordSizes));
		if (pVersion) *pVersion = N_CLASS(NVersion)(v);
	}

#ifdef N_DEBUG
	using N_CLASS(NObject)::Check;
#endif

	static void Check(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NETemplateCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NETemplateCheck(pBuffer, bufferSize));
	}

	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NETemplateGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NETemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NInt value;
		NCheck(NETemplateGetRecordCountMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NETemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit N_CLASS(NETemplate)(NUInt flags = 0)
		: N_CLASS(NObject)(Create(flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NETemplate);
		Init();
	}

	explicit N_CLASS(NETemplate)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NETemplate);
		Init();
	}

	N_CLASS(NETemplate)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NETemplate);
		Init();
	}

	RecordCollection * GetRecords() const
	{
		return records.get();
	}
};

}}

#endif // !NE_TEMPLATE_HPP_INCLUDED
