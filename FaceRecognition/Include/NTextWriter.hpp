#ifndef N_TEXT_WRITER_HPP_INCLUDED
#define N_TEXT_WRITER_HPP_INCLUDED

#include <NObject.hpp>
#include <NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <NTextWriter.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NTextWriter) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NTextWriter, NObject)

protected:
	N_CLASS(NTextWriter)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NTextWriter) * Synchronized(N_CLASS(NTextWriter) * pWriter)
	{
		if (!pWriter) NThrowArgumentNullException(N_T("pWriter"));
		HNTextWriter hValue;
		NCheck(NTextWriterSynchronized(pWriter->GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NTextWriter)>(hValue);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NTextWriter) * GetNull()
	{
		HNTextWriter hValue;
		NCheck(NTextWriterGetNull(&hValue));
		try
		{
			return FromHandle<N_CLASS(NTextWriter)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	::Neurotec::Text::NEncoding GetEncoding() const
	{
		::Neurotec::Text::NEncoding value;
		NCheck(NTextWriterGetEncoding(GetHandle(), &value));
		return value;
	}

	N_CLASS(NString) GetNewLine() const
	{
		HNString hValue;
		NCheck(NTextWriterGetNewLine(GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	void SetNewLine(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NTextWriterSetNewLineN(GetHandle(), value.GetHandle()));
	}

	void Flush()
	{
		NCheck(NTextWriterFlush(GetHandle()));
	}

	void WriteChar(NChar value)
	{
		NCheck(NTextWriterWriteChar(GetHandle(), value));
	}

	void Write(const NChar * arValue, NInt valueLength)
	{
		NCheck(NTextWriterWriteChars(GetHandle(), arValue, valueLength));
	}

	void Write(NUInt value)
	{
		NCheck(NTextWriterWriteUInt32(GetHandle(), value));
	}

	void Write(NInt value)
	{
		NCheck(NTextWriterWriteInt32(GetHandle(), value));
	}

	void Write(NUInt64 value)
	{
		NCheck(NTextWriterWriteUInt64(GetHandle(), value));
	}

	void Write(NInt64 value)
	{
		NCheck(NTextWriterWriteInt64(GetHandle(), value));
	}

	void Write(NFloat value)
	{
		NCheck(NTextWriterWriteSingle(GetHandle(), value));
	}

	void Write(NDouble value)
	{
		NCheck(NTextWriterWriteDouble(GetHandle(), value));
	}

	void Write(bool value)
	{
		NCheck(NTextWriterWriteBoolean(GetHandle(), value ? NTrue : NFalse));
	}

	void WriteSizeType(NSizeType value)
	{
		NCheck(NTextWriterWriteSizeType(GetHandle(), value));
	}

	void WriteSSizeType(NSSizeType value)
	{
		NCheck(NTextWriterWriteSSizeType(GetHandle(), value));
	}

	void Write(const void * value)
	{
		NCheck(NTextWriterWritePointer(GetHandle(), value));
	}

	void WriteResult(NResult value)
	{
		NCheck(NTextWriterWriteResult(GetHandle(), value));
	}

	void Write(N_CLASS(NType) * pType, const void * pValue, NSizeType valueSize)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(NTextWriterWriteValue(GetHandle(), pType->GetHandle(), pValue, valueSize));
	}

	void Write(N_CLASS(NObject) * pValue)
	{
		NCheck(NTextWriterWriteObject(GetHandle(), ToHandle(pValue)));
	}

	void Write(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NTextWriterWriteN(GetHandle(), value.GetHandle()));
	}

	void Write(const N_CLASS(NStringWrapper) & format, ...)
	{
		va_list args;
		va_start(args, format);
		try
		{
			Write(format, args);
			va_end(args);
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	void Write(const N_CLASS(NStringWrapper) & value, va_list args)
	{
		NCheck(NTextWriterWriteFormatN(GetHandle(), value.GetHandle(), args));
	}

	void WriteLine()
	{
		NCheck(NTextWriterWriteEmptyLine(GetHandle()));
	}

	void WriteCharLine(NChar value)
	{
		NCheck(NTextWriterWriteCharLine(GetHandle(), value));
	}

	void WriteLine(const NChar * arValue, NInt valueLength)
	{
		NCheck(NTextWriterWriteCharsLine(GetHandle(), arValue, valueLength));
	}

	void WriteLine(NUInt value)
	{
		NCheck(NTextWriterWriteUInt32Line(GetHandle(), value));
	}

	void WriteLine(NInt value)
	{
		NCheck(NTextWriterWriteInt32Line(GetHandle(), value));
	}

	void WriteLine(NUInt64 value)
	{
		NCheck(NTextWriterWriteUInt64Line(GetHandle(), value));
	}

	void WriteLine(NInt64 value)
	{
		NCheck(NTextWriterWriteInt64Line(GetHandle(), value));
	}

	void WriteLine(NFloat value)
	{
		NCheck(NTextWriterWriteSingleLine(GetHandle(), value));
	}

	void WriteLine(NDouble value)
	{
		NCheck(NTextWriterWriteDoubleLine(GetHandle(), value));
	}

	void WriteLine(bool value)
	{
		NCheck(NTextWriterWriteBooleanLine(GetHandle(), value ? NTrue : NFalse));
	}

	void WriteSizeTypeLine(NSizeType value)
	{
		NCheck(NTextWriterWriteSizeTypeLine(GetHandle(), value));
	}

	void WriteSSizeTypeLine(NSSizeType value)
	{
		NCheck(NTextWriterWriteSSizeTypeLine(GetHandle(), value));
	}

	void WriteLine(const void * value)
	{
		NCheck(NTextWriterWritePointerLine(GetHandle(), value));
	}

	void WriteResultLine(NResult value)
	{
		NCheck(NTextWriterWriteResultLine(GetHandle(), value));
	}

	void WriteLine(N_CLASS(NType) * pType, const void * pValue, NSizeType valueSize)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(NTextWriterWriteValueLine(GetHandle(), pType->GetHandle(), pValue, valueSize));
	}

	void WriteLine(N_CLASS(NObject) * pValue)
	{
		NCheck(NTextWriterWriteObjectLine(GetHandle(), ToHandle(pValue)));
	}

	void WriteLine(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NTextWriterWriteLineN(GetHandle(), value.GetHandle()));
	}

	void WriteLine(const N_CLASS(NStringWrapper) & format, ...)
	{
		va_list args;
		va_start(args, format);
		try
		{
			WriteLine(format, args);
			va_end(args);
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	void WriteLine(const N_CLASS(NStringWrapper) & value, va_list args)
	{
		NCheck(NTextWriterWriteFormatLineN(GetHandle(), value.GetHandle(), args));
	}
};

}}

#endif // !N_TEXT_WRITER_HPP_INCLUDED
