#ifndef N_CONSOLE_HPP_INCLUDED
#define N_CONSOLE_HPP_INCLUDED

#include <NCore.hpp>
#include <NTextReader.hpp>
#include <NTextWriter.hpp>
namespace Neurotec
{
using ::Neurotec::IO::HNTextReader;
using ::Neurotec::IO::HNTextWriter;
#include <NConsole.h>
}

namespace Neurotec
{

class N_CLASS(NConsole)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NConsole)

public:
	static ::Neurotec::IO::N_CLASS(NTextReader) * GetIn()
	{
		HNTextReader hValue;
		NCheck(NConsoleGetIn(&hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle< ::Neurotec::IO::N_CLASS(NTextReader)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static ::Neurotec::IO::N_CLASS(NTextWriter) * GetOut()
	{
		HNTextWriter hValue;
		NCheck(NConsoleGetOut(&hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle< ::Neurotec::IO::N_CLASS(NTextWriter)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static ::Neurotec::IO::N_CLASS(NTextWriter) * GetError()
	{
		HNTextWriter hValue;
		NCheck(NConsoleGetError(&hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle< ::Neurotec::IO::N_CLASS(NTextWriter)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static void SetIn(::Neurotec::IO::N_CLASS(NTextReader) * pValue)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NCheck(NConsoleSetIn(pValue->GetHandle()));
	}

	static void SetOut(::Neurotec::IO::N_CLASS(NTextWriter) * pValue)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NCheck(NConsoleSetOut(pValue->GetHandle()));
	}

	static void SetError(::Neurotec::IO::N_CLASS(NTextWriter) * pValue)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NCheck(NConsoleSetError(pValue->GetHandle()));
	}

	static NInt ReadChar()
	{
		NInt value;
		NCheck(NConsoleReadChar(&value));
		return value;
	}

	static N_CLASS(NString) ReadLine()
	{
		HNString hValue;
		NCheck(NConsoleReadLine(&hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static void WriteChar(NChar value)
	{
		NCheck(NConsoleWriteChar(value));
	}

	static void Write(const NChar * arValue, NInt valueLength)
	{
		NCheck(NConsoleWriteChars(arValue, valueLength));
	}

	static void Write(NUInt value)
	{
		NCheck(NConsoleWriteUInt32(value));
	}

	static void Write(NInt value)
	{
		NCheck(NConsoleWriteInt32(value));
	}

	static void Write(NUInt64 value)
	{
		NCheck(NConsoleWriteUInt64(value));
	}

	static void Write(NInt64 value)
	{
		NCheck(NConsoleWriteInt64(value));
	}

	static void Write(NFloat value)
	{
		NCheck(NConsoleWriteSingle(value));
	}

	static void Write(NDouble value)
	{
		NCheck(NConsoleWriteDouble(value));
	}

	static void Write(bool value)
	{
		NCheck(NConsoleWriteBoolean(value ? NTrue : NFalse));
	}

	static void WriteSizeType(NSizeType value)
	{
		NCheck(NConsoleWriteSizeType(value));
	}

	static void WriteSSizeType(NSSizeType value)
	{
		NCheck(NConsoleWriteSSizeType(value));
	}

	static void Write(const void * value)
	{
		NCheck(NConsoleWritePointer(value));
	}

	static void WriteResult(NResult value)
	{
		NCheck(NConsoleWriteResult(value));
	}

	static void Write(N_CLASS(NType) * pType, const void * pValue, NSizeType valueSize)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(NConsoleWriteValue(pType->GetHandle(), pValue, valueSize));
	}

	static void Write(N_CLASS(NObject) * pValue)
	{
		NCheck(NConsoleWriteObject(N_CLASS(NObject)::ToHandle(pValue)));
	}

	static void Write(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NConsoleWriteN(value.GetHandle()));
	}

	static void Write(const N_CLASS(NStringWrapper) & format, ...)
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

	static void Write(const N_CLASS(NStringWrapper) & value, va_list args)
	{
		NCheck(NConsoleWriteFormatN(value.GetHandle(), args));
	}

	static void WriteLine()
	{
		NCheck(NConsoleWriteEmptyLine());
	}

	static void WriteCharLine(NChar value)
	{
		NCheck(NConsoleWriteCharLine(value));
	}

	static void WriteLine(const NChar * arValue, NInt valueLength)
	{
		NCheck(NConsoleWriteCharsLine(arValue, valueLength));
	}

	static void WriteLine(NUInt value)
	{
		NCheck(NConsoleWriteUInt32Line(value));
	}

	static void WriteLine(NInt value)
	{
		NCheck(NConsoleWriteInt32Line(value));
	}

	static void WriteLine(NUInt64 value)
	{
		NCheck(NConsoleWriteUInt64Line(value));
	}

	static void WriteLine(NInt64 value)
	{
		NCheck(NConsoleWriteInt64Line(value));
	}

	static void WriteLine(NFloat value)
	{
		NCheck(NConsoleWriteSingleLine(value));
	}

	static void WriteLine(NDouble value)
	{
		NCheck(NConsoleWriteDoubleLine(value));
	}

	static void WriteLine(bool value)
	{
		NCheck(NConsoleWriteBooleanLine(value ? NTrue : NFalse));
	}

	static void WriteSizeTypeLine(NSizeType value)
	{
		NCheck(NConsoleWriteSizeTypeLine(value));
	}

	static void WriteSSizeTypeLine(NSSizeType value)
	{
		NCheck(NConsoleWriteSSizeTypeLine(value));
	}

	static void WriteLine(const void * value)
	{
		NCheck(NConsoleWritePointerLine(value));
	}

	static void WriteResultLine(NResult value)
	{
		NCheck(NConsoleWriteResultLine(value));
	}

	static void WriteLine(N_CLASS(NType) * pType, const void * pValue, NSizeType valueSize)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(NConsoleWriteValueLine(pType->GetHandle(), pValue, valueSize));
	}

	static void WriteLine(N_CLASS(NObject) * pValue)
	{
		NCheck(NConsoleWriteObjectLine(N_CLASS(NObject)::ToHandle(pValue)));
	}

	static void WriteLine(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NConsoleWriteLineN(value.GetHandle()));
	}

	static void WriteLine(const N_CLASS(NStringWrapper) & format, ...)
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

	static void WriteLine(const N_CLASS(NStringWrapper) & value, va_list args)
	{
		NCheck(NConsoleWriteFormatLineN(value.GetHandle(), args));
	}
};

}

#endif // !N_CONSOLE_HPP_INCLUDED
