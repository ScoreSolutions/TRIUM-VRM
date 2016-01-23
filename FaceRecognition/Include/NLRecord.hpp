#ifndef NL_RECORD_HPP_INCLUDED
#define NL_RECORD_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NLRecord.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NLRecord) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NLRecord, NObject)

private:
	static HNLRecord Create(NUInt flags)
	{
		HNLRecord handle;
		NCheck(NLRecordCreate(flags, &handle));
		return handle;
	}

	static HNLRecord Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNLRecord handle;
		NCheck(NLRecordCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNLRecord Create(const void *pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNLRecord handle;
		NCheck(NLRecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	N_CLASS(NLRecord)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NLRecordGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NLRecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NByte value;
		NCheck(NLRecordGetQualityMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void *pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NLRecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NLRecordGetCbeffProductTypeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void *pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NLRecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static void Check(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NLRecordCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void *pBuffer, NSizeType bufferSize)
	{
		NCheck(NLRecordCheck(pBuffer, bufferSize));
	}

	explicit N_CLASS(NLRecord)(NUInt flags = 0)
		: N_CLASS(NObject)(Create(flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLRecord);
	}

	explicit N_CLASS(NLRecord)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLRecord);
	}

	N_CLASS(NLRecord)(const void *pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLRecord);
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NLRecordGetQuality((HNLRecord)GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NLRecordSetQuality((HNLRecord)GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NLRecordGetCbeffProductType((HNLRecord)GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NLRecordSetCbeffProductType((HNLRecord)GetHandle(), value));
	}
};

}}

#endif // !NL_RECORD_HPP_INCLUDED
