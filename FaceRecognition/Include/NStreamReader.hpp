#ifndef N_STREAM_READER_HPP_INCLUDED
#define N_STREAM_READER_HPP_INCLUDED

#include <NTextReader.hpp>
#include <NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <NStreamReader.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NStreamReader) : public N_CLASS(NTextReader)
{
	N_DECLARE_OBJECT_CLASS(NStreamReader, NTextReader)

private:
	static HNStreamReader Create(N_CLASS(NStream) * pStream)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNStreamReader handle;
		NCheck(NStreamReaderCreate(pStream->GetHandle(), &handle));
		return handle;
	}

	static HNStreamReader Create(N_CLASS(NStream) * pStream, NEncoding encoding, bool detectEncodingFromByteOrderMarks)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNStreamReader handle;
		NCheck(NStreamReaderCreateWithEncoding(pStream->GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNStreamReader Create(N_CLASS(NStream) * pStream, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNStreamReader handle;
		NCheck(NStreamReaderCreateWithEncodingAndBufferSize(pStream->GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, bufferSize, &handle));
		return handle;
	}

	static HNStreamReader Create(const N_CLASS(NStringWrapper) & path)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateFromFileN(path.GetHandle(), &handle));
		return handle;
	}

	static HNStreamReader Create(const N_CLASS(NStringWrapper) & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateFromFileWithEncodingN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNStreamReader Create(const N_CLASS(NStringWrapper) & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateFromFileWithEncodingAndBufferSizeN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, bufferSize, &handle));
		return handle;
	}

	N_CLASS(NStreamReader)(HNObject handle, bool claimHandle)
		: N_CLASS(NTextReader)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NStreamReader) * GetNull()
	{
		HNStreamReader hValue;
		NCheck(NStreamReaderGetNull(&hValue));
		try
		{
			return FromHandle<N_CLASS(NStreamReader)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	explicit N_CLASS(NStreamReader)(N_CLASS(NStream) * pStream)
		: N_CLASS(NTextReader)(Create(pStream), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamReader);
	}

	N_CLASS(NStreamReader)(N_CLASS(NStream) * pStream, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
		: N_CLASS(NTextReader)(Create(pStream, encoding, detectEncodingFromByteOrderMarks), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamReader);
	}

	N_CLASS(NStreamReader)(N_CLASS(NStream) * pStream, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
		: N_CLASS(NTextReader)(Create(pStream, encoding, detectEncodingFromByteOrderMarks, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamReader);
	}

	explicit N_CLASS(NStreamReader)(const N_CLASS(NStringWrapper) & path)
		: N_CLASS(NTextReader)(Create(path), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamReader);
	}

	N_CLASS(NStreamReader)(const N_CLASS(NStringWrapper) & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
		: N_CLASS(NTextReader)(Create(path, encoding, detectEncodingFromByteOrderMarks), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamReader);
	}

	N_CLASS(NStreamReader)(const N_CLASS(NStringWrapper) & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
		: N_CLASS(NTextReader)(Create(path, encoding, detectEncodingFromByteOrderMarks, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStreamReader);
	}

	::Neurotec::Text::NEncoding GetEncoding() const
	{
		::Neurotec::Text::NEncoding value;
		NCheck(NStreamReaderGetCurrentEncoding(GetHandle(), &value));
		return value;
	}

	N_CLASS(NStream) * GetBaseStream() const
	{
		HNStream hValue;
		NCheck(NStreamReaderGetBaseStream(GetHandle(), &hValue));
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

	bool IsEndOfStream() const
	{
		NBool value;
		NCheck(NStreamReaderIsEndOfStream(GetHandle(), &value));
		return value != 0;
	}
};

}}

#endif // !N_STREAM_READER_HPP_INCLUDED
