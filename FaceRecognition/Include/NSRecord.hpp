#ifndef NS_RECORD_HPP_INCLUDED
#define NS_RECORD_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NSRecord.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NSRecord) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NSRecord, NObject)

private:
	static HNSRecord Create(NUInt flags)
	{
		HNSRecord handle;
		NCheck(NSRecordCreate(flags, &handle));
		return handle;
	}

	static HNSRecord Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNSRecord handle;
		NCheck(NSRecordCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNSRecord Create(const void *pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNSRecord handle;
		NCheck(NSRecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	N_CLASS(NSRecord)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NSRecordGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NSRecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetPhraseId(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NInt value;
		NCheck(NSRecordGetPhraseIdMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NInt GetPhraseId(const void *pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NSRecordGetPhraseIdMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NSRecordGetCbeffProductTypeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void *pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NSRecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NByte value;
		NCheck(NSRecordGetQualityMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void *pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NSRecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetSnr(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NByte value;
		NCheck(NSRecordGetSnrMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NByte GetSnr(const void *pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NSRecordGetSnrMem(pBuffer, bufferSize, &value));
		return value;
	}

	static void Check(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NSRecordCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void *pBuffer, NSizeType bufferSize)
	{
		NCheck(NSRecordCheck(pBuffer, bufferSize));
	}

	explicit N_CLASS(NSRecord)(NUInt flags = 0)
		: N_CLASS(NObject)(Create(flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSRecord);
	}

	explicit N_CLASS(NSRecord)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSRecord);
	}

	N_CLASS(NSRecord)(const void *pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSRecord);
	}

	NInt GetPhraseId() const
	{
		NInt value;
		NCheck(NSRecordGetPhraseId(GetHandle(), &value));
		return value;
	}

	void SetPhraseId(NInt value)
	{
		NCheck(NSRecordSetPhraseId(GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NSRecordGetCbeffProductType(GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NSRecordSetCbeffProductType(GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NSRecordGetQuality(GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NSRecordSetQuality(GetHandle(), value));
	}

	NByte GetSnr() const
	{
		NByte value;
		NCheck(NSRecordGetSnr(GetHandle(), &value));
		return value;
	}

	void SetSnr(NByte value)
	{
		NCheck(NSRecordSetSnr(GetHandle(), value));
	}

	NBool GetHasTextDependentFeatures() const
	{
		NBool value;
		NCheck(NSRecordGetHasTextDependentFeatures(GetHandle(), &value));
		return value;
	}

	void SetHasTextDependentFeatures(NBool value)
	{
		NCheck(NSRecordSetHasTextDependentFeatures(GetHandle(), value));
	}

	NBool GetHasTextIndependentFeatures() const
	{
		NBool value;
		NCheck(NSRecordGetHasTextIndependentFeatures(GetHandle(), &value));
		return value;
	}

	void SetHasTextIndependentFeatures(NBool value)
	{
		NCheck(NSRecordSetHasTextIndependentFeatures(GetHandle(), value));
	}
};

}}

#endif // !NS_RECORD_HPP_INCLUDED
