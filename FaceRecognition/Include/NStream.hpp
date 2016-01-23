#ifndef N_STREAM_HPP_INCLUDED
#define N_STREAM_HPP_INCLUDED

#include <NObject.hpp>
#include <NBuffer.hpp>
#include <NIOTypes.hpp>
namespace Neurotec { namespace IO
{
#include <NStream.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NStream) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NStream, NObject)

protected:
	N_CLASS(NStream)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NStream) * Synchronized(N_CLASS(NStream) * pStream)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNStream hValue;
		NCheck(NStreamSynchronized(pStream->GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NStream)>(hValue);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NStream) * GetNull()
	{
		HNStream hValue;
		NCheck(NStreamGetNull(&hValue));
		try
		{
			return FromHandle<N_CLASS(NStream)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void CopyTo(N_CLASS(NStream) * pDstStream)
	{
		if (!pDstStream) NThrowArgumentNullException(N_T("pDstStream"));
		NCheck(NStreamCopyTo(GetHandle(), pDstStream->GetHandle()));
	}

	void CopyTo(N_CLASS(NStream) * pDstStream, NSizeType bufferSize)
	{
		if (!pDstStream) NThrowArgumentNullException(N_T("pDstStream"));
		NCheck(NStreamCopyToWithBufferSize(GetHandle(), pDstStream->GetHandle(), bufferSize));
	}

	void Flush()
	{
		NCheck(NStreamFlush(GetHandle()));
	}

	NLong GetLength()
	{
		NLong value;
		NCheck(NStreamGetLength(GetHandle(), &value));
		return value;
	}

	void SetLength(NLong value)
	{
		NCheck(NStreamSetLength(GetHandle(), value));
	}

	void Seek(NLong offset, NSeekOrigin origin)
	{
		NCheck(NStreamSeek(GetHandle(), offset, origin));
	}

	NInt ReadByte()
	{
		NInt value;
		NCheck(NStreamReadByte(GetHandle(), &value));
		return value;
	}

	NSizeType Read(void * pBuffer, NSizeType bufferSize)
	{
		NSizeType sizeRead;
		NCheck(NStreamRead(GetHandle(), pBuffer, bufferSize, &sizeRead));
		return sizeRead;
	}

	NSizeType Read(N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType sizeRead;
		NCheck(NStreamReadN(GetHandle(), pBuffer->GetHandle(), &sizeRead));
		return sizeRead;
	}

	void WriteByte(NByte value)
	{
		NCheck(NStreamWriteByte(GetHandle(), value));
	}

	void Write(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NStreamWrite(GetHandle(), pBuffer, bufferSize));
	}

	void Write(N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NStreamWriteN(GetHandle(), pBuffer->GetHandle()));
	}

	bool CanRead()
	{
		NBool value;
		NCheck(NStreamCanRead(GetHandle(), &value));
		return value != 0;
	}

	bool CanWrite()
	{
		NBool value;
		NCheck(NStreamCanWrite(GetHandle(), &value));
		return value != 0;
	}

	bool CanSeek()
	{
		NBool value;
		NCheck(NStreamCanSeek(GetHandle(), &value));
		return value != 0;
	}

	NLong GetPosition()
	{
		NLong value;
		NCheck(NStreamGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NLong value)
	{
		NCheck(NStreamSetPosition(GetHandle(), value));
	}
};

}}

#endif // !N_STREAM_HPP_INCLUDED
