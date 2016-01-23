#ifndef NE_RECORD_HPP_INCLUDED
#define NE_RECORD_HPP_INCLUDED

#include <NCore.hpp>
#include <NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NERecord.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NERecord) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NERecord, NObject)

private:
	static HNERecord Create(NUShort width, NUShort height, NUInt flags)
	{
		HNERecord handle;
		NCheck(NERecordCreate(width, height, flags, &handle));
		return handle;
	}

	static HNERecord Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNERecord handle;
		NCheck(NERecordCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNERecord Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNERecord handle;
		NCheck(NERecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	N_CLASS(NERecord)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NERecordGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NERecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetWidth(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NERecordGetWidthMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetWidth(const void *pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NERecordGetWidthMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetHeight(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NERecordGetHeightMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetHeight(const void *pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NERecordGetHeightMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NEPosition GetPosition(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NEPosition value;
		NCheck(NERecordGetPositionMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NEPosition GetPosition(const void *pBuffer, NSizeType bufferSize)
	{
		NEPosition value;
		NCheck(NERecordGetPositionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NByte value;
		NCheck(NERecordGetQualityMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void *pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NERecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NERecordGetCbeffProductTypeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void *pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NERecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static void Check(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NERecordCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void *pBuffer, NSizeType bufferSize)
	{
		NCheck(NERecordCheck(pBuffer, bufferSize));
	}

	N_CLASS(NERecord)(NUShort width, NUShort height, NUInt flags = 0)
		: N_CLASS(NObject)(Create(width, height, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NERecord);
	}

	explicit N_CLASS(NERecord)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NERecord);
	}

	N_CLASS(NERecord)(const void *pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType *pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NERecord);
	}

	NUShort GetWidth() const
	{
		NUShort value;
		NCheck(NERecordGetWidth((HNERecord)GetHandle(), &value));
		return value;
	}

	NUShort GetHeight() const
	{
		NUShort value;
		NCheck(NERecordGetHeight((HNERecord)GetHandle(), &value));
		return value;
	}

	NEPosition GetPosition() const
	{
		NEPosition value;
		NCheck(NERecordGetPosition((HNERecord)GetHandle(), &value));
		return value;
	}

	void SetPosition(NEPosition value)
	{
		NCheck(NERecordSetPosition((HNERecord)GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NERecordGetQuality((HNERecord)GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NERecordSetQuality((HNERecord)GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NERecordGetCbeffProductType((HNERecord)GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NERecordSetCbeffProductType((HNERecord)GetHandle(), value));
	}
};

}}

#endif // !NE_RECORD_HPP_INCLUDED
