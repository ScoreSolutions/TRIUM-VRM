#ifndef N_MEMORY_STREAM_HPP_INCLUDED
#define N_MEMORY_STREAM_HPP_INCLUDED

#include <NStream.hpp>
namespace Neurotec { namespace IO
{
#include <NMemoryStream.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NMemoryStream) : public N_CLASS(NStream)
{
	N_DECLARE_OBJECT_CLASS(NMemoryStream, NStream)

private:
	static HNMemoryStream Create()
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreate(&handle));
		return handle;
	}

	static HNMemoryStream Create(NSizeType capacity)
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateWithCapacity(capacity, &handle));
		return handle;
	}

	static HNMemoryStream Create(N_CLASS(NBuffer) * pBuffer, NFileAccess access, bool bufferExposable)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateFromBufferN(pBuffer->GetHandle(), access, bufferExposable ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNMemoryStream Create(void * pBuffer, NSizeType bufferSize, NFileAccess access, bool bufferExposable)
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateFromBuffer(pBuffer, bufferSize, access, bufferExposable ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNMemoryStream Create(const void * pBuffer, NSizeType bufferSize)
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateFromBufferForRead(pBuffer, bufferSize, &handle));
		return handle;
	}

	N_CLASS(NMemoryStream)(HNObject handle, bool claimHandle)
		: N_CLASS(NStream)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NMemoryStream)()
		: N_CLASS(NStream)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMemoryStream);
	}

	explicit N_CLASS(NMemoryStream)(NSizeType capacity)
		: N_CLASS(NStream)(Create(capacity), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMemoryStream);
	}

	explicit N_CLASS(NMemoryStream)(N_CLASS(NBuffer) * pBuffer, NFileAccess access = nfaRead, bool bufferExposable = false)
		: N_CLASS(NStream)(Create(pBuffer, access, bufferExposable), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMemoryStream);
	}

	N_CLASS(NMemoryStream)(void * pBuffer, NSizeType bufferSize, NFileAccess access = nfaRead, bool bufferExposable = false)
		: N_CLASS(NStream)(Create(pBuffer, bufferSize, access, bufferExposable), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMemoryStream);
	}

	N_CLASS(NMemoryStream)(const void * pBuffer, NSizeType bufferSize)
		: N_CLASS(NStream)(Create(pBuffer, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMemoryStream);
	}

	N_CLASS(NBuffer) * GetBuffer()
	{
		HNBuffer hValue;
		NCheck(NMemoryStreamGetBuffer(GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NBuffer)>(hValue);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void WriteTo(N_CLASS(NStream) * pDstStream)
	{
		if (!pDstStream) NThrowArgumentNullException(N_T("pDstStream"));
		NCheck(NMemoryStreamWriteTo(GetHandle(), pDstStream->GetHandle()));
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use GetBuffer instead")
	void * DetachBuffer(NSizeType * pBufferSize)
	{
		void * pBuffer;
		NCheck(NMemoryStreamDetachBuffer(GetHandle(), &pBuffer, pBufferSize));
		return pBuffer;
	}
#include <NReDeprecate.h>

	NSizeType GetPosition()
	{
		NSizeType value;
		NCheck(NMemoryStreamGetCapacity(GetHandle(), &value));
		return value;
	}

	void SetPosition(NSizeType value)
	{
		NCheck(NMemoryStreamSetCapacity(GetHandle(), value));
	}

	void * GetPositionPtr()
	{
		void * value;
		NCheck(NMemoryStreamGetPositionPtr(GetHandle(), &value));
		return value;
	}

	void SetPositionPtr(void * value)
	{
		NCheck(NMemoryStreamSetPositionPtr(GetHandle(), value));
	}

	void * ToPtr(NSizeType * pBufferSize)
	{
		void * pBuffer;
		NCheck(NMemoryStreamToPtr(GetHandle(), pBufferSize, &pBuffer));
		return pBuffer;
	}
};

}}

#endif // !N_MEMORY_STREAM_HPP_INCLUDED
