#ifndef NS_TEMPLATE_HPP_INCLUDED
#define NS_TEMPLATE_HPP_INCLUDED

#include <NSRecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NSTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NST_MAX_RECORD_COUNT
#undef NST_PROCESS_FIRST_RECORD_ONLY

const NInt NST_MAX_RECORD_COUNT = 255;
const NUInt NST_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class N_CLASS(NSTemplate) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NSTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NSRecord), N_CLASS(NSTemplate)>
	{
		RecordCollection(N_CLASS(NSTemplate) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NSRecord), N_CLASS(NSTemplate)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNSTemplate handle, NInt * pValue) const
		{
			return NSTemplateGetRecordCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNSTemplate handle, NInt * pValue) const
		{
			return NSTemplateGetRecordCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNSTemplate handle, NInt value)
		{
			return NSTemplateSetRecordCapacity(handle, value);
		}

		virtual NResult GetNative(HNSTemplate handle, NInt index, HNSRecord * phValue) const
		{
			return NSTemplateGetRecordEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNSTemplate, HNSRecord *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNSTemplate handle, NInt index, HNSRecord hValue)
		{
			return NSTemplateSetRecord(handle, index, hValue);
		}

		virtual NResult AddNative(HNSTemplate, HNSRecord)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNSTemplate handle, HNSRecord hValue, NInt * pIndex)
		{
			return NSTemplateAddRecordEx(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNSTemplate handle, NInt index, HNSRecord hValue)
		{
			return NSTemplateInsertRecord(handle, index, hValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNSTemplate, HNSRecord, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNSTemplate handle, NInt index)
		{
			return NSTemplateRemoveRecord(handle, index);
		}

		virtual NResult RemoveRangeNative(HNSTemplate, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNSTemplate handle)
		{
			return NSTemplateClearRecords(handle);
		}

		friend class N_CLASS(NSTemplate);

	public:
		using ::Neurotec::Collections::N_CLASS(NCollection)<N_CLASS(NSRecord) *, N_CLASS(NSTemplate)>::Add;

	#include <NNoDeprecate.h>
		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFRecord)) " constructor and Add instead")
		N_CLASS(NSRecord) * Add(NUInt flags = 0)
		{
			HNSRecord hRecord;
			NCheck(NSTemplateAddRecord(pOwner->GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NSRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFRecord)) " constructor and Add instead")
		N_CLASS(NSRecord) * Add(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
			HNSRecord hRecord;
			NCheck(NSTemplateAddRecordFromMemoryN(pOwner->GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NSRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFRecord)) " constructor and Add instead")
		N_CLASS(NSRecord) * Add(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			HNSRecord hRecord;
			NCheck(NSTemplateAddRecordFromMemory(pOwner->GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NSRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and Add instead")
		N_CLASS(NSRecord) * AddCopy(N_CLASS(NSRecord)* pSrcRecord, NUInt flags = 0)
		{
			if (!pSrcRecord) NThrowArgumentNullException(N_T("pSrcRecord"));
			HNSRecord hRecord;
			NCheck(NSTemplateAddRecordCopyEx(pOwner->GetHandle(), pSrcRecord->GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NSRecord)>(hRecord, true, true);
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
	static HNSTemplate Create(NUInt flags)
	{
		HNSTemplate handle;
		NCheck(NSTemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNSTemplate Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNSTemplate handle;
		NCheck(NSTemplateCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNSTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNSTemplate handle;
		NCheck(NSTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	::std::auto_ptr<RecordCollection> records;

	N_CLASS(NSTemplate)(HNObject handle, bool claimHandle)
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
		NCheck(NSTemplateCalculateSize(recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NSTemplatePack(recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		N_CLASS(NVersion) * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NSTemplateUnpack(pBuffer, bufferSize,
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
		NCheck(NSTemplateCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NSTemplateCheck(pBuffer, bufferSize));
	}

	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NSTemplateGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NSTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NInt value;
		NCheck(NSTemplateGetRecordCountMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NSTemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit N_CLASS(NSTemplate)(NUInt flags = 0)
		: N_CLASS(NObject)(Create(flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSTemplate);
		Init();
	}

	explicit N_CLASS(NSTemplate)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSTemplate);
		Init();
	}

	N_CLASS(NSTemplate)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSTemplate);
		Init();
	}

	RecordCollection * GetRecords() const
	{
		return records.get();
	}
};

}}

#endif // !NS_TEMPLATE_HPP_INCLUDED
