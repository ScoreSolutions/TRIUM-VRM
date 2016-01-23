#ifndef N_BINARY_READER_HPP_INCLUDED
#define N_BINARY_READER_HPP_INCLUDED

#include <NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <NBinaryReader.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NBinaryReader) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NBinaryReader, NObject)

private:
	static HNBinaryReader Create(N_CLASS(NStream) * pStream, NByteOrder byteOrder)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNBinaryReader handle;
		NCheck(NBinaryReaderCreate(pStream->GetHandle(), byteOrder, &handle));
		return handle;
	}

	static HNBinaryReader Create(N_CLASS(NStream) * pStream, NByteOrder byteOrder, NEncoding encoding)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNBinaryReader handle;
		NCheck(NBinaryReaderCreateWithEncoding(pStream->GetHandle(), byteOrder, encoding, &handle));
		return handle;
	}

	N_CLASS(NBinaryReader)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NBinaryReader) * GetNull()
	{
		HNBinaryReader hValue;
		NCheck(NBinaryReaderGetNull(&hValue));
		try
		{
			return FromHandle<N_CLASS(NBinaryReader)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	N_CLASS(NBinaryReader)(N_CLASS(NStream) * pStream, NByteOrder byteOrder)
		: N_CLASS(NObject)(Create(pStream, byteOrder), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBinaryReader);
	}

	N_CLASS(NBinaryReader)(N_CLASS(NStream) * pStream, NByteOrder byteOrder, NEncoding encoding)
		: N_CLASS(NObject)(Create(pStream, byteOrder, encoding), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBinaryReader);
	}

	void Seek(NLong offset, NSeekOrigin origin)
	{
		NCheck(NBinaryReaderSeek(GetHandle(), offset, origin));
	}

	NInt Read()
	{
		NInt value;
		NCheck(NBinaryReaderRead(GetHandle(), &value));
		return value;
	}

	NByte ReadByte()
	{
		NByte value;
		NCheck(NBinaryReaderReadByte(GetHandle(), &value));
		return value;
	}

	NSByte ReadSByte()
	{
		NSByte value;
		NCheck(NBinaryReaderReadSByte(GetHandle(), &value));
		return value;
	}

	NUInt16 ReadUInt16()
	{
		NUInt16 value;
		NCheck(NBinaryReaderReadUInt16(GetHandle(), &value));
		return value;
	}

	NInt16 ReadInt16()
	{
		NInt16 value;
		NCheck(NBinaryReaderReadInt16(GetHandle(), &value));
		return value;
	}

	NUInt32 ReadUInt32()
	{
		NUInt32 value;
		NCheck(NBinaryReaderReadUInt32(GetHandle(), &value));
		return value;
	}

	NInt32 ReadInt32()
	{
		NInt32 value;
		NCheck(NBinaryReaderReadInt32(GetHandle(), &value));
		return value;
	}

#ifndef N_NO_INT_64
	NUInt64 ReadUInt64()
	{
		NUInt64 value;
		NCheck(NBinaryReaderReadUInt64(GetHandle(), &value));
		return value;
	}

	NInt64 ReadInt64()
	{
		NInt64 value;
		NCheck(NBinaryReaderReadInt64(GetHandle(), &value));
		return value;
	}
#endif

#ifndef N_NO_FLOAT
	NSingle ReadSingle()
	{
		NSingle value;
		NCheck(NBinaryReaderReadSingle(GetHandle(), &value));
		return value;
	}

	NDouble ReadDouble()
	{
		NDouble value;
		NCheck(NBinaryReaderReadDouble(GetHandle(), &value));
		return value;
	}
#endif

	bool ReadBoolean()
	{
		NBoolean value;
		NCheck(NBinaryReaderReadBoolean(GetHandle(), &value));
		return value != 0;
	}

	NInt PeekChar()
	{
		NInt value;
		NCheck(NBinaryReaderPeekChar(GetHandle(), &value));
		return value;
	}

	NChar ReadChar()
	{
		NChar value;
		NCheck(NBinaryReaderReadChar(GetHandle(), &value));
		return value;
	}

	NSizeType ReadBytes(void * pBuffer, NSizeType bufferSize, bool readAll = false)
	{
		NSizeType sizeRead;
		NCheck(NBinaryReaderReadBytesDst(GetHandle(), pBuffer, bufferSize, readAll ? NTrue : NFalse, &sizeRead));
		return sizeRead;
	}

	NSizeType ReadBytes(N_CLASS(NBuffer) * pBuffer, bool readAll = false)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType sizeRead;
		NCheck(NBinaryReaderReadBytesDstN(GetHandle(), pBuffer->GetHandle(), readAll ? NTrue : NFalse, &sizeRead));
		return sizeRead;
	}

	N_CLASS(NBuffer) * ReadBytes(NSizeType size, bool readAll = false)
	{
		HNBuffer hBuffer;
		NCheck(NBinaryReaderReadBytesN(GetHandle(), size, readAll ? NTrue : NFalse, &hBuffer));
		try
		{
			return FromHandle<N_CLASS(NBuffer)>(hBuffer);
		}
		catch (...)
		{
			Unref(hBuffer);
			throw;
		}
	}

	NInt ReadChars(NChar * arChars, NInt count, bool readAll = false)
	{
		NInt countRead;
		NCheck(NBinaryReaderReadCharsDst(GetHandle(), arChars, count, readAll ? NTrue : NFalse, &countRead));
		return countRead;
	}

	NChar * ReadChars(NInt count, NInt * pCharCount, bool readAll = false)
	{
		NChar * arChars;
		NCheck(NBinaryReaderReadChars(GetHandle(), count, readAll ? NTrue : NFalse, pCharCount, &arChars));
		return arChars;
	}

	N_CLASS(NStream) * GetBaseStream()
	{
		HNStream hValue;
		NCheck(NBinaryReaderGetBaseStream(GetHandle(), &hValue));
		return FromHandle<N_CLASS(NStream)>(hValue, true, true);
	}

	NByteOrder GetByteOrder()
	{
		NByteOrder value;
		NCheck(NBinaryReaderGetByteOrder(GetHandle(), &value));
		return value;
	}

	NLong GetPosition()
	{
		NLong value;
		NCheck(NBinaryReaderGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NLong value)
	{
		NCheck(NBinaryReaderSetPosition(GetHandle(), value));
	}
};

}}

#endif // !N_BINARY_READER_HPP_INCLUDED
