#ifndef NL_TEMPLATE_HPP_INCLUDED
#define NL_TEMPLATE_HPP_INCLUDED

#include <NLRecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NLTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NLT_MAX_RECORD_COUNT
#undef NLT_PROCESS_FIRST_RECORD_ONLY

const NInt NLT_MAX_RECORD_COUNT = 255;
const NUInt NLT_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class N_CLASS(NLTemplate) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NLTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NLRecord), N_CLASS(NLTemplate)>
	{
		RecordCollection(N_CLASS(NLTemplate) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NLRecord), N_CLASS(NLTemplate)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNLTemplate handle, NInt * pValue) const
		{
			return NLTemplateGetRecordCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNLTemplate handle, NInt * pValue) const
		{
			return NLTemplateGetRecordCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNLTemplate handle, NInt value)
		{
			return NLTemplateSetRecordCapacity(handle, value);
		}

		virtual NResult GetNative(HNLTemplate handle, NInt index, HNLRecord * phValue) const
		{
			return NLTemplateGetRecordEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNLTemplate, HNLRecord *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNLTemplate handle, NInt index, HNLRecord hValue)
		{
			return NLTemplateSetRecord(handle, index, hValue);
		}

		virtual NResult AddNative(HNLTemplate, HNLRecord)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNLTemplate handle, HNLRecord hValue, NInt * pIndex)
		{
			return NLTemplateAddRecordEx(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNLTemplate handle, NInt index, HNLRecord hValue)
		{
			return NLTemplateInsertRecord(handle, index, hValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNLTemplate, HNLRecord, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNLTemplate handle, NInt index)
		{
			return NLTemplateRemoveRecord(handle, index);
		}

		virtual NResult RemoveRangeNative(HNLTemplate, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNLTemplate handle)
		{
			return NLTemplateClearRecords(handle);
		}

		friend class N_CLASS(NLTemplate);

	public:
		using ::Neurotec::Collections::N_CLASS(NCollection)<N_CLASS(NLRecord) *, N_CLASS(NLTemplate)>::Add;

	#include <NNoDeprecate.h>
		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NLRecord)) " constructor and Add instead")
		N_CLASS(NLRecord) * Add(NUInt flags = 0)
		{
			HNLRecord hRecord;
			NCheck(NLTemplateAddRecord(pOwner->GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NLRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NLRecord)) " constructor and Add instead")
		N_CLASS(NLRecord) * Add(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
			HNLRecord hRecord;
			NCheck(NLTemplateAddRecordFromMemoryN(pOwner->GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NLRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NLRecord)) " constructor and Add instead")
		N_CLASS(NLRecord) * Add(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			HNLRecord hRecord;
			NCheck(NLTemplateAddRecordFromMemoryEx(pOwner->GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NLRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and Add instead")
		N_CLASS(NLRecord) * AddCopy(N_CLASS(NLRecord)* pSrcRecord, NUInt flags = 0)
		{
			if (!pSrcRecord) NThrowArgumentNullException(N_T("pSrcRecord"));
			HNLRecord hRecord;
			NCheck(NLTemplateAddRecordCopyEx(pOwner->GetHandle(), pSrcRecord->GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NLRecord)>(hRecord, true, true);
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
	static HNLTemplate Create(NUInt flags)
	{
		HNLTemplate handle;
		NCheck(NLTemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNLTemplate Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNLTemplate handle;
		NCheck(NLTemplateCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNLTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNLTemplate handle;
		NCheck(NLTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	::std::auto_ptr<RecordCollection> records;

	N_CLASS(NLTemplate)(HNObject handle, bool claimHandle)
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
		NCheck(NLTemplateCalculateSize(recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NLTemplatePack(recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		N_CLASS(NVersion) * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NLTemplateUnpack(pBuffer, bufferSize,
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
		NCheck(NLTemplateCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NLTemplateCheck(pBuffer, bufferSize));
	}

	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NLTemplateGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NLTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NInt value;
		NCheck(NLTemplateGetRecordCountMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NLTemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit N_CLASS(NLTemplate)(NUInt flags = 0)
		: N_CLASS(NObject)(Create(flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLTemplate);
		Init();
	}

	explicit N_CLASS(NLTemplate)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLTemplate);
		Init();
	}

	N_CLASS(NLTemplate)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLTemplate);
		Init();
	}

	RecordCollection * GetRecords() const
	{
		return records.get();
	}
};

}}

#endif // !NL_TEMPLATE_HPP_INCLUDED
