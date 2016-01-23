#ifndef N_TEXT_READER_HPP_INCLUDED
#define N_TEXT_READER_HPP_INCLUDED

#include <NObject.hpp>
namespace Neurotec { namespace IO
{
#include <NTextReader.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NTextReader) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NTextReader, NObject)

protected:
	N_CLASS(NTextReader)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NTextReader) * Synchronized(N_CLASS(NTextReader) * pReader)
	{
		if (!pReader) NThrowArgumentNullException(N_T("pReader"));
		HNTextReader hValue;
		NCheck(NTextReaderSynchronized(pReader->GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NTextReader)>(hValue);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NTextReader) * GetNull()
	{
		HNTextReader hValue;
		NCheck(NTextReaderGetNull(&hValue));
		try
		{
			return FromHandle<N_CLASS(NTextReader)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	NInt PeekChar()
	{
		NInt value;
		NCheck(NTextReaderPeekChar(GetHandle(), &value));
		return value;
	}

	NInt ReadChar()
	{
		NInt value;
		NCheck(NTextReaderReadChar(GetHandle(), &value));
		return value;
	}

	NInt ReadChars(NChar * szBuffer, NInt count)
	{
		NInt charsRead;
		NCheck(NTextReaderReadChars(GetHandle(), szBuffer, count, &charsRead));
		return charsRead;
	}

	N_CLASS(NString) ReadLine()
	{
		HNString hValue;
		NCheck(NTextReaderReadLine(GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	N_CLASS(NString) ReadToEnd()
	{
		HNString hValue;
		NCheck(NTextReaderReadToEnd(GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};

}}

#endif // !N_TEXT_READER_HPP_INCLUDED
