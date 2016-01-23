#ifndef NF_TEMPLATE_HPP_INCLUDED
#define NF_TEMPLATE_HPP_INCLUDED

#include <NFRecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NFTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NFT_MAX_RECORD_COUNT
#undef NFT_PROCESS_FIRST_RECORD_ONLY

const NInt NFT_MAX_RECORD_COUNT = 255;
const NUInt NFT_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class N_CLASS(NFTemplate) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NFTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NFRecord), N_CLASS(NFTemplate)>
	{
		RecordCollection(N_CLASS(NFTemplate) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NFRecord), N_CLASS(NFTemplate)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFTemplate handle, NInt * pValue) const
		{
			return NFTemplateGetRecordCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNFTemplate handle, NInt * pValue) const
		{
			return NFTemplateGetRecordCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNFTemplate handle, NInt value)
		{
			return NFTemplateSetRecordCapacity(handle, value);
		}

		virtual NResult GetNative(HNFTemplate handle, NInt index, HNFRecord * phValue) const
		{
			return NFTemplateGetRecordEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNFTemplate, HNFRecord *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNFTemplate handle, NInt index, HNFRecord hValue)
		{
			return NFTemplateSetRecord(handle, index, hValue);
		}

		virtual NResult AddNative(HNFTemplate, HNFRecord)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNFTemplate handle, HNFRecord hValue, NInt * pIndex)
		{
			return NFTemplateAddRecordEx(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNFTemplate handle, NInt index, HNFRecord hValue)
		{
			return NFTemplateInsertRecord(handle, index, hValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNFTemplate, HNFRecord, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNFTemplate handle, NInt index)
		{
			return NFTemplateRemoveRecord(handle, index);
		}

		virtual NResult RemoveRangeNative(HNFTemplate, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNFTemplate handle)
		{
			return NFTemplateClearRecords(handle);
		}

		friend class N_CLASS(NFTemplate);

	public:
		using ::Neurotec::Collections::N_CLASS(NCollection)<N_CLASS(NFRecord) *, N_CLASS(NFTemplate)>::Add;

	#include <NNoDeprecate.h>
		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFRecord)) " constructor and Add instead")
		N_CLASS(NFRecord) * Add(NUShort width, NUShort height, NUShort horzResolution, NUShort vertResolution, NUInt flags = 0)
		{
			HNFRecord hRecord;
			NCheck(NFTemplateAddRecord(pOwner->GetHandle(), width, height, horzResolution, vertResolution, flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NFRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFRecord)) " constructor and Add instead")
		N_CLASS(NFRecord) * Add(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
			HNFRecord hRecord;
			NCheck(NFTemplateAddRecordFromMemoryN(pOwner->GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NFRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFRecord)) " constructor and Add instead")
		N_CLASS(NFRecord) * Add(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		{
			HNFRecord hRecord;
			NCheck(NFTemplateAddRecordFromMemoryEx(pOwner->GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NFRecord)>(hRecord, true, true);
			}
			catch (...)
			{
				Unref(hRecord);
				throw;
			}
		}

		N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and Add instead")
		N_CLASS(NFRecord) * AddCopy(N_CLASS(NFRecord)* pSrcRecord, NUInt flags = 0)
		{
			if (!pSrcRecord) NThrowArgumentNullException(N_T("pSrcRecord"));
			HNFRecord hRecord;
			NCheck(NFTemplateAddRecordCopyEx(pOwner->GetHandle(), pSrcRecord->GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			try
			{
				return FromHandle<N_CLASS(NFRecord)>(hRecord, true, true);
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
	static HNFTemplate Create(bool isPalm, NUInt flags)
	{
		HNFTemplate handle;
		NCheck(NFTemplateCreateEx(isPalm, flags, &handle));
		return handle;
	}

	static HNFTemplate Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNFTemplate handle;
		NCheck(NFTemplateCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNFTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNFTemplate handle;
		NCheck(NFTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	::std::auto_ptr<RecordCollection> records;

	N_CLASS(NFTemplate)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		records.reset(new RecordCollection(this));
	}

public:
	static NSizeType CalculateSize(NBool isPalm, NInt recordCount, NSizeType * arRecordSizes)
	{
		NSizeType value;
		NCheck(NFTemplateCalculateSize(isPalm, recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(bool isPalm, NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NFTemplatePack(isPalm ? NTrue : NFalse, recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize, NBool *isPalm,
		N_CLASS(NVersion) * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NFTemplateUnpack(pBuffer, bufferSize, isPalm,
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
		NCheck(NFTemplateCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NFTemplateCheck(pBuffer, bufferSize));
	}

	static bool IsPalm(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NBool value;
		NCheck(NFTemplateIsPalmMemN(pBuffer->GetHandle(), &value));
		return value != 0;
	}

	static bool IsPalm(const void * pBuffer, NSizeType bufferSize)
	{
		NBool value;
		NCheck(NFTemplateIsPalmMem(pBuffer, bufferSize, &value));
		return value != 0;
	}

	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NFTemplateGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NFTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NInt value;
		NCheck(NFTemplateGetRecordCountMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NFTemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit N_CLASS(NFTemplate)(bool isPalm = false, NUInt flags = 0)
		: N_CLASS(NObject)(Create(isPalm, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFTemplate);
		Init();
	}

	explicit N_CLASS(NFTemplate)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFTemplate);
		Init();
	}

	N_CLASS(NFTemplate)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFTemplate);
		Init();
	}

	RecordCollection * GetRecords() const
	{
		return records.get();
	}

	bool IsPalm() const
	{
		NBool value;
		NCheck(NFTemplateIsPalm((HNFTemplate)GetHandle(), &value));
		return value != 0;
	}
};

}}

#endif // !NF_TEMPLATE_HPP_INCLUDED
