#ifndef N_BINARY_WRITER_HPP_INCLUDED
#define N_BINARY_WRITER_HPP_INCLUDED

#include <NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <NBinaryWriter.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NBinaryWriter) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NBinaryWriter, NObject)

private:
	static HNBinaryWriter Create(N_CLASS(NStream) * pStream, NByteOrder byteOrder)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNBinaryWriter handle;
		NCheck(NBinaryWriterCreate(pStream->GetHandle(), byteOrder, &handle));
		return handle;
	}

	static HNBinaryWriter Create(N_CLASS(NStream) * pStream, NByteOrder byteOrder, NEncoding encoding)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNBinaryWriter handle;
		NCheck(NBinaryWriterCreateWithEncoding(pStream->GetHandle(), byteOrder, encoding, &handle));
		return handle;
	}

	N_CLASS(NBinaryWriter)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NBinaryWriter) * GetNull()
	{
		HNBinaryWriter hValue;
		NCheck(NBinaryWriterGetNull(&hValue));
		try
		{
			return FromHandle<N_CLASS(NBinaryWriter)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	N_CLASS(NBinaryWriter)(N_CLASS(NStream) * pStream, NByteOrder byteOrder)
		: N_CLASS(NObject)(Create(pStream, byteOrder), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBinaryWriter);
	}

	N_CLASS(NBinaryWriter)(N_CLASS(NStream) * pStream, NByteOrder byteOrder, NEncoding encoding)
		: N_CLASS(NObject)(Create(pStream, byteOrder, encoding), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBinaryWriter);
	}

	void Flush()
	{
		NCheck(NBinaryWriterFlush(GetHandle()));
	}

	void Seek(NLong offset, NSeekOrigin origin)
	{
		NCheck(NBinaryWriterSeek(GetHandle(), offset, origin));
	}

	void Write(NByte value)
	{
		NCheck(NBinaryWriterWriteByte(GetHandle(), value));
	}

	void Write(NSByte value)
	{
		NCheck(NBinaryWriterWriteSByte(GetHandle(), value));
	}

	void Write(NUInt16 value)
	{
		NCheck(NBinaryWriterWriteUInt16(GetHandle(), value));
	}

	void Write(NInt16 value)
	{
		NCheck(NBinaryWriterWriteInt16(GetHandle(), value));
	}

	void Write(NUInt32 value)
	{
		NCheck(NBinaryWriterWriteUInt32(GetHandle(), value));
	}

	void Write(NInt32 value)
	{
		NCheck(NBinaryWriterWriteInt32(GetHandle(), value));
	}

#ifndef N_NO_INT_64
	void Write(NUInt64 value)
	{
		NCheck(NBinaryWriterWriteUInt64(GetHandle(), value));
	}

	void Write(NInt64 value)
	{
		NCheck(NBinaryWriterWriteInt64(GetHandle(), value));
	}
#endif

#ifndef N_NO_FLOAT
	void Write(NSingle value)
	{
		NCheck(NBinaryWriterWriteSingle(GetHandle(), value));
	}

	void Write(NDouble value)
	{
		NCheck(NBinaryWriterWriteDouble(GetHandle(), value));
	}
#endif

	void Write(bool value)
	{
		NCheck(NBinaryWriterWriteBoolean(GetHandle(), value ? NTrue : NFalse));
	}

	void Write(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NBinaryWriterWriteBytes(GetHandle(), pBuffer, bufferSize));
	}

	void Write(N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NBinaryWriterWriteBytesN(GetHandle(), pBuffer->GetHandle()));
	}

	void WriteChar(NChar value)
	{
		NCheck(NBinaryWriterWriteChar(GetHandle(), value));
	}

	void WriteChars(const NChar * arChars, NInt count)
	{
		NCheck(NBinaryWriterWriteChars(GetHandle(), arChars, count));
	}

	N_CLASS(NStream) * GetBaseStream()
	{
		HNStream hValue;
		NCheck(NBinaryWriterGetBaseStream(GetHandle(), &hValue));
		return FromHandle<N_CLASS(NStream)>(hValue, true, true);
	}

	NByteOrder GetByteOrder()
	{
		NByteOrder value;
		NCheck(NBinaryWriterGetByteOrder(GetHandle(), &value));
		return value;
	}

	NLong GetPosition()
	{
		NLong value;
		NCheck(NBinaryWriterGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NLong value)
	{
		NCheck(NBinaryWriterSetPosition(GetHandle(), value));
	}
};

}}

#endif // !N_BINARY_WRITER_HPP_INCLUDED
