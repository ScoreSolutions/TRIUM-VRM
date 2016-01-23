#ifndef N_STREAM_WRITER_HPP_INCLUDED
#define N_STREAM_WRITER_HPP_INCLUDED

#include <NTextWriter.hpp>
namespace Neurotec { namespace IO
{
#include <NStreamWriter.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NStreamWriter) : public N_CLASS(NTextWriter)
{
	N_DECLARE_OBJECT_CLASS(NStreamWriter, NTextWriter)

private:
	static HNStreamWriter Create(N_CLASS(NStream) * pStream)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNStreamWriter handle;
		NCheck(NStreamWriterCreate(pStream->GetHandle(), &handle));
		return handle;
	}

	static HNStreamWriter Create(N_CLASS(NStream) * pStream, NEncoding encoding)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateWithEncoding(pStream->GetHandle(), encoding, &handle));
		return handle;
	}

	static HNStreamWriter Create(N_CLASS(NStream) * pStream, NEncoding encoding, NSizeType bufferSize)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateWithEncodingAndBufferSize(pStream->GetHandle(), encoding, bufferSize, &handle));
		return handle;
	}

	static HNStreamWriter Create(const N_CLASS(NStringWrapper) & path, bool append)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateFromFileN(path.GetHandle(), append ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNStreamWriter Create(const N_CLASS(NStringWrapper) & path, bool append, NEncoding encoding)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateFromFileWithEncodingN(path.GetHandle(), append ? NTrue : NFalse, encoding, &handle));
		return handle;
	}

	static HNStreamWriter Create(const N_CLASS(NStringWrapper) & path, bool append, NEncoding encoding, NSizeType bufferSize)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateFromFileWithEncodingAndBufferSizeN(path.GetHandle(), append ? NTrue : NFalse, encoding, bufferSize, &handle));
		return handle;
	}

	N_CLASS(NStreamWriter)(HNObject handle, bool claimHandle)
		: N_CLASS(NTextWriter)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NStreamWriter) * GetNull()
	{
		HNStreamWriter hValue;
		NCheck(NStreamWriterGetNull(&hValue));
		try
		{
			return FromHandle<N_CLASS(NStreamWriter)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	explicit N_CLASS(NStreamWriter)(N_CLASS(NStream) * pStream)
		: N_CLASS(NTextWriter)(Create(pStream), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamWriter);
	}

	N_CLASS(NStreamWriter)(N_CLASS(NStream) * pStream, NEncoding encoding)
		: N_CLASS(NTextWriter)(Create(pStream, encoding), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamWriter);
	}

	N_CLASS(NStreamWriter)(N_CLASS(NStream) * pStream, NEncoding encoding, NSizeType bufferSize)
		: N_CLASS(NTextWriter)(Create(pStream, encoding, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamWriter);
	}

	explicit N_CLASS(NStreamWriter)(const N_CLASS(NStringWrapper) & path, bool append = false)
		: N_CLASS(NTextWriter)(Create(path, append), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamWriter);
	}

	N_CLASS(NStreamWriter)(const N_CLASS(NStringWrapper) & path, bool append, NEncoding encoding)
		: N_CLASS(NTextWriter)(Create(path, append, encoding), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamWriter);
	}

	N_CLASS(NStreamWriter)(const N_CLASS(NStringWrapper) & path, bool append, NEncoding encoding, NSizeType bufferSize)
		: N_CLASS(NTextWriter)(Create(path, append, encoding, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamWriter);
	}

	N_CLASS(NStream) * GetBaseStream() const
	{
		HNStream hValue;
		NCheck(NStreamWriterGetBaseStream(GetHandle(), &hValue));
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

	bool GetAutoFlush() const
	{
		NBool value;
		NCheck(NStreamWriterGetAutoFlush(GetHandle(), &value));
		return value != 0;
	}

	void SetAutoFlush(bool value)
	{
		NCheck(NStreamWriterSetAutoFlush(GetHandle(), value ? NTrue : NFalse));
	}
};

}}

#endif // !N_STREAM_WRITER_HPP_INCLUDED
