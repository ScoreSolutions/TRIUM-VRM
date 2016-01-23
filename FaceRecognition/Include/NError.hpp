#include <NObject.hpp>

#ifndef N_ERROR_HPP_INCLUDED
#define N_ERROR_HPP_INCLUDED

#include <NTypes.hpp>
#include <NMemory.hpp>
namespace Neurotec
{
#include <NError.h>
}
#include <stdexcept>
#include <ios>
#include <typeinfo>
#include <string>
#if defined(N_MSVC) && !defined(N_NO_UNICODE)
	#include <NWindows.hpp>
	#include <comdef.h>
#endif
#include <NStringBuilder.hpp>

namespace Neurotec
{
#undef N_OK
#undef N_E_FAILED
#undef N_E_CORE
#undef N_E_ABANDONED_MUTEX
#undef N_E_ARGUMENT
#undef N_E_ARGUMENT_NULL
#undef N_E_ARGUMENT_OUT_OF_RANGE
#undef N_E_INVALID_ENUM_ARGUMENT
#undef N_E_ARITHMETIC
#undef N_E_OVERFLOW
#undef N_E_BAD_IMAGE_FORMAT
#undef N_E_DLL_NOT_FOUND
#undef N_E_ENTRY_POINT_NOT_FOUND
#undef N_E_FORMAT
#undef N_E_FILE_FORMAT
#undef N_E_INDEX_OUT_OF_RANGE
#undef N_E_INVALID_CAST
#undef N_E_INVALID_OPERATION
#undef N_E_IO
#undef N_E_DIRECTORY_NOT_FOUND
#undef N_E_DRIVE_NOT_FOUND
#undef N_E_END_OF_STREAM
#undef N_E_FILE_NOT_FOUND
#undef N_E_FILE_LOAD
#undef N_E_PATH_TOO_LONG
#undef N_E_SOCKET
#undef N_E_KEY_NOT_FOUND
#undef N_E_NOT_IMPLEMENTED
#undef N_E_NOT_SUPPORTED
#undef N_E_NULL_REFERENCE
#undef N_E_OUT_OF_MEMORY
#undef N_E_SECURITY
#undef N_E_TIMEOUT
#undef N_E_EXTERNAL
#undef N_E_CLR
#undef N_E_COM
#undef N_E_CPP
#undef N_E_JVM
#undef N_E_MAC
#undef N_E_SYS
#undef N_E_WIN32
#undef N_E_PARAMETER
#undef N_E_PARAMETER_READ_ONLY
#undef N_E_NOT_ACTIVATED

#undef NFailed
#undef NSucceeded

#undef NE_PRESERVE_INNER_ERROR
#undef NE_NO_CALL_STACK
#undef NE_MERGE_CALL_STACK
#undef NE_IS_DIRECTORY_ACCESS
#undef NE_SKIP_ONE_FRAME

const NResult N_OK                            =   0;
const NResult N_E_FAILED                      =  -1;
  const NResult N_E_CORE                      =  -2;
    const NResult N_E_ABANDONED_MUTEX         = -25;
    const NResult N_E_ARGUMENT                = -10;
      const NResult N_E_ARGUMENT_NULL         = -11;
      const NResult N_E_ARGUMENT_OUT_OF_RANGE = -12;
      const NResult N_E_INVALID_ENUM_ARGUMENT = -16;
    const NResult N_E_ARITHMETIC              = -17;
      const NResult N_E_OVERFLOW              =  -8;
    const NResult N_E_BAD_IMAGE_FORMAT        = -26;
    const NResult N_E_DLL_NOT_FOUND           = -27;
    const NResult N_E_ENTRY_POINT_NOT_FOUND   = -28;
    const NResult N_E_FORMAT                  = -13;
      const NResult N_E_FILE_FORMAT           = -29;
    const NResult N_E_INDEX_OUT_OF_RANGE      =  -9;
    const NResult N_E_INVALID_CAST            = -18;
    const NResult N_E_INVALID_OPERATION       =  -7;
    const NResult N_E_IO                      = -14;
      const NResult N_E_DIRECTORY_NOT_FOUND   = -19;
      const NResult N_E_DRIVE_NOT_FOUND       = -20;
      const NResult N_E_END_OF_STREAM         = -15;
      const NResult N_E_FILE_NOT_FOUND        = -21;
      const NResult N_E_FILE_LOAD             = -22;
      const NResult N_E_PATH_TOO_LONG         = -23;
      const NResult N_E_SOCKET                = -31;
    const NResult N_E_KEY_NOT_FOUND           = -32;
    const NResult N_E_NOT_IMPLEMENTED         =  -5;
    const NResult N_E_NOT_SUPPORTED           =  -6;
    const NResult N_E_NULL_REFERENCE          =  -3;
    const NResult N_E_OUT_OF_MEMORY           =  -4;
    const NResult N_E_SECURITY                = -24;
    const NResult N_E_TIMEOUT                 = -30;

    const NResult N_E_EXTERNAL                = -90;
      const NResult N_E_CLR                   = -93;
      const NResult N_E_COM                   = -92;
      const NResult N_E_CPP                   = -96;
      const NResult N_E_JVM                   = -97;
      const NResult N_E_MAC                   = -95;
      const NResult N_E_SYS                   = -94;
      const NResult N_E_WIN32                 = -91;

    const NResult N_E_PARAMETER              = -100;
      const NResult N_E_PARAMETER_READ_ONLY  = -101;

    const NResult N_E_NOT_ACTIVATED          = -200;

inline bool NFailed(NResult result)
{
	return result < 0;
}

inline bool NSucceeded(NResult result)
{
	return result >= 0;
}

const NUInt NE_PRESERVE_INNER_ERROR = 0x00000001;
const NUInt NE_NO_CALL_STACK = 0x00000002;
const NUInt NE_MERGE_CALL_STACK = 0x00000004;
const NUInt NE_IS_DIRECTORY_ACCESS = 0x00000100;
const NUInt NE_SKIP_ONE_FRAME = 0x01000000;

class N_CLASS(NCallStackEntry) : public NCallStackEntry_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NCallStackEntry)

public:
	N_CLASS(NCallStackEntry)(void * addr, const N_CLASS(NStringWrapper) & function, const N_CLASS(NStringWrapper) & file, NInt line)
	{
		NCheck(NCallStackEntryCreateN(addr, function.GetHandle(), file.GetHandle(), line, this));
	}

	N_CLASS(NString) GetFunction() const
	{
		return N_CLASS(NString)(hFunction, false);
	}

	void SetFunction(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hFunction));
	}

	N_CLASS(NString) GetFile() const
	{
		return N_CLASS(NString)(hFile, false);
	}

	void SetFile(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hFile));
	}
};
N_TYPEDEF_TYPE(NCallStackEntry)

class N_CLASS(NException)
#if defined(N_FRAMEWORK_MFC)
	: public CException
#else
	: public N_CLASS(NObjectBase)
#endif
{
private:
	static N_CLASS(NString) GetDefaultMessage(NResult code)
	{
		HNString hValue;
		return NFailed(NErrorGetDefaultMessageN(code, &hValue)) ? N_CLASS(NString)() : N_CLASS(NString)(hValue, true);
	}

	static NInt GetCode(HNError hError)
	{
		NInt value;
		return NFailed(NErrorGetCodeEx(hError, &value)) ? N_OK : value;
	}

	static N_CLASS(NString) GetMessage(HNError hError)
	{
		HNString hValue;
		return NFailed(NErrorGetMessageN(hError, &hValue)) ? N_CLASS(NString)() : N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GetParam(HNError hError)
	{
		HNString hValue;
		return NFailed(NErrorGetParamN(hError, &hValue)) ? N_CLASS(NString)() : N_CLASS(NString)(hValue, true);
	}

	static NInt GetExternalError(HNError hError)
	{
		NInt value;
		return NFailed(NErrorGetExternalErrorEx(hError, &value)) ? 0 : value;
	}

	static N_CLASS(NString) GetCallStack(HNError hError)
	{
		HNString hValue;
		return NFailed(NErrorGetCallStackN(hError, &hValue)) ? N_CLASS(NString)() : N_CLASS(NString)(hValue, true);
	}

	static HNError GetInnerError(HNError hError)
	{
		HNError hValue;
		return NFailed(NErrorGetInnerErrorEx(hError, &hValue)) ? NULL : hValue;
	}

	static N_CLASS(NException) * Get(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & param, NInt externalError, N_CLASS(NException) * pInnerException);

	static N_CLASS(NException) * Get(HNError hError)
	{
		if (!hError) return NULL;
		HNError hInnerError = GetInnerError(hError);
		try
		{
			::std::auto_ptr<N_CLASS(NException)> innerException(!hInnerError ? NULL : Get(hInnerError));
			if (hInnerError) { NObjectUnref(hInnerError); hInnerError = NULL; }
			N_CLASS(NException) * pException = Get(GetCode(hError), GetMessage(hError), GetParam(hError), GetExternalError(hError), innerException.get());
			innerException.release();
			pException->callStack = GetCallStack(hError);
			return pException;
		}
		catch (...)
		{
			if (hInnerError) NObjectUnref(hInnerError);
			throw;
		}
	}

	static void CheckCode(NResult code);

	static NResult SetLast(N_CLASS(NException) * pException, NUInt flags);

	NResult code;
	N_CLASS(NString) message;
	N_CLASS(NString) callStack;
	N_CLASS(NException) * pInnerException;

	N_CLASS(NException)(const N_CLASS(NException) &);
	N_CLASS(NException) & operator=(const N_CLASS(NException) &);

	void ToString(::Neurotec::Text::N_CLASS(NStringBuilder) & value) const
	{
		value.Append(NGetClassName(NGetObjectClass(this)));
		value.Append(N_T(": "));
		value.Append(message);
		N_CLASS(NString) params = GetParams();
		if (!params.IsEmpty())
		{
			value.AppendLine();
			value.Append(params);
		}
		if (pInnerException)
		{
			value.Append(N_T(" ---> "));
			pInnerException->ToString(value);
			value.Append(N_T("\n   --- End of inner exception stack trace ---"));
		}
		if (!callStack.IsEmpty())
		{
			value.AppendLine();
			value.Append(callStack);
		}
	}

protected:
	N_CLASS(NException)(NResult code, N_CLASS(NException) * pInnerException)
		: code(code), message(GetDefaultMessage(code)), callStack(), pInnerException(pInnerException)
		#ifdef N_FRAMEWORK_MFC
			, CException(TRUE)
		#endif
	{
		CheckCode(code);
	}

	N_CLASS(NException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: code(code), message(message), callStack(), pInnerException(pInnerException)
		#ifdef N_FRAMEWORK_MFC
			, CException(TRUE)
		#endif
	{
		CheckCode(code);
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return N_CLASS(NString)();
	}

public:
	static N_CLASS(NException) * GetLast(NResult code)
	{
		HNError hError = NULL;
		NErrorGetLastEx(0, &hError);
		try
		{
			N_CLASS(NException) * pError = Get(code, hError);
			if (hError) { NObjectUnref(hError); hError = NULL; }
			return pError;
		}
		catch (...)
		{
			if (hError) NObjectUnref(hError);
			throw;
		}
	}

	static N_CLASS(NException) * Get(NResult code, HNError hError)
	{
		if (NSucceeded(code))
		{
			return NULL;
		}
		else if (!hError || GetCode(hError) != code)
		{
			return Get(code, N_CLASS(NException)::GetDefaultMessage(code), N_CLASS(NString)(), 0, NULL);
		}
		else
		{
			return Get(hError);
		}
	}

	static N_NO_INLINE NResult SetLast(N_CLASS(NException) * pException)
	{
		return SetLast(pException, NE_SKIP_ONE_FRAME);
	}

	static N_NO_INLINE NResult SetLast(const std::exception & e)
	{
		NResult code;
		const std::type_info & eType = typeid(e);
		N_CLASS(NString) fullMessage;
		const NAChar * szMessage = NULL;
		if (typeid(std::exception) == eType)
		{
			code = N_E_FAILED;
		}
		else if (dynamic_cast<const std::bad_alloc *>(&e))
		{
			code = N_E_OUT_OF_MEMORY;
		}
		else if (dynamic_cast<const std::bad_cast *>(&e))
		{
			code = N_E_INVALID_CAST;
		}
		else if (dynamic_cast<const std::runtime_error *>(&e))
		{
			if (typeid(std::runtime_error) == eType)
			{
				code = N_E_CORE;
			}
			else if (dynamic_cast<const std::overflow_error *>(&e))
			{
				code = N_E_OVERFLOW;
			}
			else if (dynamic_cast<const std::range_error *>(&e))
			{
				code = N_E_ARITHMETIC;
			}
			else if (dynamic_cast<const std::underflow_error *>(&e))
			{
				code = N_E_ARITHMETIC;
			}
			else if (dynamic_cast<const std::ios_base::failure *>(&e))
			{
				code = N_E_IO;
			}
			else
			{
				code = N_E_CPP;
			}
		}
		else if (dynamic_cast<const std::logic_error *>(&e))
		{
			if (typeid(std::logic_error) == eType)
			{
				code = N_E_CORE;
			}
			else if (dynamic_cast<const std::invalid_argument *>(&e))
			{
				code = N_E_ARGUMENT;
			}
			else if (dynamic_cast<const std::out_of_range *>(&e))
			{
				code = N_E_ARGUMENT_OUT_OF_RANGE;
			}
			else if (dynamic_cast<const std::domain_error *>(&e))
			{
				code = N_E_ARGUMENT;
			}
			else
			{
				code = N_E_CPP;
			}
		}
		else
		{
			code = N_E_CPP;
		}
		try
		{
			szMessage = e.what();
			fullMessage = szMessage && szMessage[0] ? N_CLASS(NString)::ConcatA(3, eType.name(), ": ", szMessage) : N_CLASS(NString)(eType.name());
		}
		catch (...)
		{
		}
		NErrorSetLastN(N_E_CPP, fullMessage.GetHandle(), NULL, 0, NULL, (code == N_E_CPP ? 0 : NE_NO_CALL_STACK) | NE_SKIP_ONE_FRAME);
		if (code != N_E_CPP)
		{
			NErrorSetLastA(code, szMessage, NULL, 0, NULL, NE_PRESERVE_INNER_ERROR | NE_SKIP_ONE_FRAME);
		}
		return code;
	}

#if defined(N_MSVC) && !defined(N_NO_UNICODE)
	static N_NO_INLINE NResult SetLast(const _com_error & e)
	{
		const std::type_info & eType = typeid(e);
		_bstr_t message;
		N_CLASS(NString) fullMessage;
		HRESULT comError = 0;
		const NWChar * szMessage = NULL;
		const NWChar * szExternalCallStack = NULL;
		try
		{
			comError = e.Error();
			IErrorInfo * pErrorInfo = e.ErrorInfo();
			if (pErrorInfo) pErrorInfo->Release(); // pointer is unusable from here
			if (pErrorInfo)
			{
				szMessage = e.Description();
				szExternalCallStack = e.Source();
			}
			else
			{
				szMessage = message = e.ErrorMessage();
				szExternalCallStack = NULL;
			}
			fullMessage = szMessage && szMessage[0] ? N_CLASS(NString)::ConcatW(3, eType.name(), L": ", szMessage) : N_CLASS(NString)(eType.name());
		}
		catch (...)
		{
		}
		NErrorSetLastN(N_E_CPP, fullMessage.GetHandle(), NULL, 0, NULL, NE_NO_CALL_STACK | NE_SKIP_ONE_FRAME);
		return NErrorSetComW(comError, szMessage, NULL, szExternalCallStack, NE_PRESERVE_INNER_ERROR | NE_SKIP_ONE_FRAME);
	}
#endif

#ifdef N_FRAMEWORK_MFC
	static N_NO_INLINE NResult SetLast(CException * pException)
	{
		NResult code;
		CRuntimeClass * pExceptionClass = pException->GetRuntimeClass();
		N_CLASS(NString) fullMessage;
		NChar szMessage[1024];
		const NChar * szParam = NULL;
		if (NIsClassAssignableFrom(RUNTIME_CLASS(CMemoryException), pExceptionClass))
		{
			code = N_E_OUT_OF_MEMORY;
		}
		else if (NIsClassAssignableFrom(RUNTIME_CLASS(CNotSupportedException), pExceptionClass))
		{
			code = N_E_NOT_SUPPORTED;
		}
		else if (NIsClassAssignableFrom(RUNTIME_CLASS(CInvalidArgException), pExceptionClass))
		{
			code = N_E_ARGUMENT;
		}
		else if (NIsClassAssignableFrom(RUNTIME_CLASS(CArchiveException), pExceptionClass))
		{
			switch (((CArchiveException *)pException)->m_cause)
			{
			case CArchiveException::readOnly:
			case CArchiveException::writeOnly:
				code = N_E_NOT_SUPPORTED; break;
			case CArchiveException::endOfFile:
				code = N_E_END_OF_STREAM; break;
			case CArchiveException::badIndex:
			case CArchiveException::badSchema:
				szParam = ((CArchiveException *)pException)->m_strFileName.GetString();
				code = N_E_FILE_FORMAT; break;
			case CArchiveException::badClass:
				code = N_E_INVALID_CAST; break;
			default: code = N_E_IO; break;
			}
		}
		else if (NIsClassAssignableFrom(RUNTIME_CLASS(CFileException), pExceptionClass))
		{
			switch (((CFileException *)pException)->m_cause)
			{
			case CFileException::fileNotFound:
				szParam = ((CFileException *)pException)->m_strFileName.GetString();
				code = N_E_FILE_NOT_FOUND; break;
			case CFileException::accessDenied:
			case CFileException::sharingViolation:
				code = N_E_SECURITY; break;
			case CFileException::badPath:
			case CFileException::invalidFile:
				code = N_E_ARGUMENT; break;
			case CFileException::endOfFile:
				code = N_E_END_OF_STREAM; break;
			default:
				code = N_E_IO; break;
			}
		}
		try
		{
			if (!pException->GetErrorMessage(szMessage, sizeof(szMessage) / sizeof(szMessage[0]), NULL)) szMessage[0] = 0;
			fullMessage = szMessage[0] ? N_CLASS(NString)::Concat(3, pExceptionClass->m_lpszClassName, ": ", szMessage) : N_CLASS(NString)(pExceptionClass->m_lpszClassName);
		}
		catch (...)
		{
		}
		NErrorSetLastN(N_E_CPP, fullMessage.GetHandle(), NULL, 0, NULL, (code == N_E_CPP ? 0 : NE_NO_CALL_STACK) | NE_SKIP_ONE_FRAME);
		if (code != N_E_CPP)
		{
			NErrorSetLast(code, szMessage, szParam, 0, NULL, NE_PRESERVE_INNER_ERROR | NE_SKIP_ONE_FRAME);
		}
		return code;
	}
#endif

	N_CLASS(NException)()
		: code(N_E_FAILED), message(GetDefaultMessage(code)), callStack(), pInnerException(NULL)
		#ifdef N_FRAMEWORK_MFC
			, CException(TRUE)
		#endif
	{
		CheckCode(code);
	}

	explicit N_CLASS(NException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: code(N_E_FAILED), message(message), callStack(), pInnerException(pInnerException)
		#ifdef N_FRAMEWORK_MFC
			, CException(TRUE)
		#endif
	{
		CheckCode(code);
	}

	virtual ~N_CLASS(NException)()
	{
		if(pInnerException)
		{
			delete pInnerException;
		}
	}

	NResult GetCode() const
	{
		return code;
	}

	N_CLASS(NString) GetMessage() const
	{
		return message;
	}

	N_CLASS(NString) GetCallStack() const
	{
		return callStack;
	}

	N_CLASS(NException) * GetInnerException() const
	{
		return pInnerException;
	}

	N_CLASS(NException) * GetBaseException() const
	{
		return pInnerException ? pInnerException->GetBaseException() : (N_CLASS(NException) *)this;
	}

	N_CLASS(NString) ToString() const
	{
		::Neurotec::Text::N_CLASS(NStringBuilder) value;
		ToString(value);
		return value.DetachString();
	}

	N_DECLARE_CLASS(NException)

	friend void N_NO_RETURN NRaiseError(NResult error);
};

class N_CLASS(NCoreException) : public N_CLASS(NException)
{
protected:
	N_CLASS(NCoreException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NException)(code, pInnerException)
	{
	}

	N_CLASS(NCoreException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NCoreException)()
		: N_CLASS(NException)(N_E_CORE, NULL)
	{
	}

	explicit N_CLASS(NCoreException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NException)(N_E_CORE, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NCoreException)
};

namespace Threading
{

class N_CLASS(NAbandonedMutexException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NAbandonedMutexException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NAbandonedMutexException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NAbandonedMutexException)()
		: N_CLASS(NCoreException)(N_E_ABANDONED_MUTEX, NULL)
	{
	}

	explicit N_CLASS(NAbandonedMutexException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_ABANDONED_MUTEX, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NAbandonedMutexException)
};

} // namespace Threading

class N_CLASS(NArgumentException) : public N_CLASS(NCoreException)
{
private:
	N_CLASS(NString) paramName;

protected:
	N_CLASS(NArgumentException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException), paramName()
	{
	}

	N_CLASS(NArgumentException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException), paramName(paramName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return paramName.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("ParamName: ") + paramName;
	}

public:
	N_CLASS(NArgumentException)()
		: N_CLASS(NCoreException)(N_E_ARGUMENT, NULL), paramName()
	{
	}

	explicit N_CLASS(NArgumentException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_ARGUMENT, message, pInnerException), paramName()
	{
	}

	N_CLASS(NArgumentException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_ARGUMENT, message, pInnerException), paramName(paramName)
	{
	}

	N_CLASS(NString) GetParamName() const
	{
		return paramName;
	}

	N_DECLARE_CLASS(NArgumentException)
};

class N_CLASS(NArgumentNullException) : public N_CLASS(NArgumentException)
{
private:
	static N_CLASS(NString) GetMessage(const N_CLASS(NStringWrapper) & paramName)
	{
		return paramName.GetString() + N_T(" is NULL");
	}

protected:
	N_CLASS(NArgumentNullException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(code, pInnerException)
	{
	}

	N_CLASS(NArgumentNullException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(code, message, paramName, pInnerException)
	{
	}

public:
	N_CLASS(NArgumentNullException)()
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_NULL, NULL)
	{
	}

	explicit N_CLASS(NArgumentNullException)(const N_CLASS(NStringWrapper) & paramName)
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_NULL, GetMessage(paramName), paramName, NULL)
	{
	}

	N_CLASS(NArgumentNullException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_NULL, message, N_CLASS(NString)(), pInnerException)
	{
	}

	N_CLASS(NArgumentNullException)(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_NULL, message, paramName, pInnerException)
	{
	}

	N_DECLARE_CLASS(NArgumentNullException)
};

class N_CLASS(NArgumentOutOfRangeException) : public N_CLASS(NArgumentException)
{
private:
	static N_CLASS(NString) GetMessage(const N_CLASS(NStringWrapper) & paramName)
	{
		return paramName.GetString() + N_T(" is out of range");
	}

protected:
	N_CLASS(NArgumentOutOfRangeException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(code, pInnerException)
	{
	}

	N_CLASS(NArgumentOutOfRangeException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(code, message, paramName, pInnerException)
	{
	}

public:
	N_CLASS(NArgumentOutOfRangeException)()
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_NULL, NULL)
	{
	}

	explicit N_CLASS(NArgumentOutOfRangeException)(const N_CLASS(NStringWrapper) & paramName)
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_OUT_OF_RANGE, GetMessage(paramName), paramName, NULL)
	{
	}

	N_CLASS(NArgumentOutOfRangeException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_OUT_OF_RANGE, message, N_CLASS(NString)(), pInnerException)
	{
	}

	N_CLASS(NArgumentOutOfRangeException)(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NArgumentException)(N_E_ARGUMENT_OUT_OF_RANGE, message, paramName, pInnerException)
	{
	}

	N_DECLARE_CLASS(NArgumentOutOfRangeException)
};

class N_CLASS(NInvalidEnumArgumentException) : public N_CLASS(NArgumentException)
{
private:
	static N_CLASS(NString) GetMessage(const N_CLASS(NStringWrapper) & paramName)
	{
		return paramName.GetString() + N_T(" is an invalid enum value");
	}

protected:
	N_CLASS(NInvalidEnumArgumentException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(code, pInnerException)
	{
	}

	N_CLASS(NInvalidEnumArgumentException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(code, message, paramName, pInnerException)
	{
	}

public:
	N_CLASS(NInvalidEnumArgumentException)()
		: N_CLASS(NArgumentException)(N_E_INVALID_ENUM_ARGUMENT, NULL)
	{
	}

	explicit N_CLASS(NInvalidEnumArgumentException)(const N_CLASS(NStringWrapper) & paramName)
		: N_CLASS(NArgumentException)(N_E_INVALID_ENUM_ARGUMENT, GetMessage(paramName), paramName, NULL)
	{
	}

	N_CLASS(NInvalidEnumArgumentException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArgumentException)(N_E_INVALID_ENUM_ARGUMENT, message, N_CLASS(NString)(), pInnerException)
	{
	}

	N_CLASS(NInvalidEnumArgumentException)(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NArgumentException)(N_E_INVALID_ENUM_ARGUMENT, message, paramName, pInnerException)
	{
	}

	N_DECLARE_CLASS(NInvalidEnumArgumentException)
};

class N_CLASS(NArithmeticException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NArithmeticException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NArithmeticException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NArithmeticException)()
		: N_CLASS(NCoreException)(N_E_ARITHMETIC, NULL)
	{
	}

	explicit N_CLASS(NArithmeticException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_ARITHMETIC, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NArithmeticException)
};

class N_CLASS(NOverflowException) : public N_CLASS(NArithmeticException)
{
protected:
	N_CLASS(NOverflowException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArithmeticException)(code, pInnerException)
	{
	}

	N_CLASS(NOverflowException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NArithmeticException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NOverflowException)()
		: N_CLASS(NArithmeticException)(N_E_OVERFLOW, NULL)
	{
	}

	explicit N_CLASS(NOverflowException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NArithmeticException)(N_E_OVERFLOW, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NOverflowException)
};

class N_CLASS(NBadImageFormatException) : public N_CLASS(NCoreException)
{
private:
	N_CLASS(NString) fileName;

protected:
	N_CLASS(NBadImageFormatException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException), fileName()
	{
	}

	N_CLASS(NBadImageFormatException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException), fileName(fileName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return fileName.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("FileName: ") + fileName;
	}

public:
	N_CLASS(NBadImageFormatException)()
		: N_CLASS(NCoreException)(N_E_BAD_IMAGE_FORMAT, NULL), fileName()
	{
	}

	explicit N_CLASS(NBadImageFormatException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_BAD_IMAGE_FORMAT, message, pInnerException), fileName()
	{
	}

	N_CLASS(NBadImageFormatException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_BAD_IMAGE_FORMAT, message, pInnerException), fileName(fileName)
	{
	}

	N_CLASS(NString) GetFileName() const
	{
		return fileName;
	}

	N_DECLARE_CLASS(NBadImageFormatException)
};

class N_CLASS(NDllNotFoundException) : public N_CLASS(NCoreException)
{
private:
	N_CLASS(NString) fileName;

protected:
	N_CLASS(NDllNotFoundException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException), fileName()
	{
	}

	N_CLASS(NDllNotFoundException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException), fileName(fileName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return fileName.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("FileName: ") + fileName;
	}

public:
	N_CLASS(NDllNotFoundException)()
		: N_CLASS(NCoreException)(N_E_DLL_NOT_FOUND, NULL), fileName()
	{
	}

	explicit N_CLASS(NDllNotFoundException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_DLL_NOT_FOUND, message, pInnerException), fileName()
	{
	}

	N_CLASS(NDllNotFoundException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_DLL_NOT_FOUND, message, pInnerException), fileName(fileName)
	{
	}

	N_CLASS(NString) GetFileName() const
	{
		return fileName;
	}

	N_DECLARE_CLASS(NDllNotFoundException)
};

class N_CLASS(NEntryPointNotFoundException) : public N_CLASS(NCoreException)
{
private:
	N_CLASS(NString) symbolName;

protected:
	N_CLASS(NEntryPointNotFoundException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException), symbolName()
	{
	}

	N_CLASS(NEntryPointNotFoundException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & symbolName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException), symbolName(symbolName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return symbolName.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("SymbolName: ") + symbolName;
	}

public:
	N_CLASS(NEntryPointNotFoundException)()
		: N_CLASS(NCoreException)(N_E_ENTRY_POINT_NOT_FOUND, NULL), symbolName()
	{
	}

	explicit N_CLASS(NEntryPointNotFoundException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_ENTRY_POINT_NOT_FOUND, message, pInnerException), symbolName()
	{
	}

	N_CLASS(NEntryPointNotFoundException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & symbolName, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_ENTRY_POINT_NOT_FOUND, message, pInnerException), symbolName(symbolName)
	{
	}

	N_CLASS(NString) GetSymbolName() const
	{
		return symbolName;
	}

	N_DECLARE_CLASS(NEntryPointNotFoundException)
};

class N_CLASS(NFormatException) : public N_CLASS(NCoreException)
{
private:
	N_CLASS(NString) paramName;

	static N_CLASS(NString) GetMessage(const N_CLASS(NStringWrapper) & paramName)
	{
		return paramName.GetString() + N_T(" format is invalid");
	}

protected:
	N_CLASS(NFormatException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException), paramName()
	{
	}

	N_CLASS(NFormatException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException), paramName(paramName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return paramName.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("ParamName: ") + paramName;
	}

public:
	N_CLASS(NFormatException)()
		: N_CLASS(NCoreException)(N_E_FORMAT, NULL), paramName()
	{
	}

	explicit N_CLASS(NFormatException)(const N_CLASS(NStringWrapper) & paramName)
		: N_CLASS(NCoreException)(N_E_FORMAT, GetMessage(paramName), NULL), paramName(paramName)
	{
	}

	N_CLASS(NFormatException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(N_E_FORMAT, message, pInnerException), paramName()
	{
	}

	N_CLASS(NFormatException)(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_FORMAT, message, pInnerException), paramName(paramName)
	{
	}

	N_CLASS(NString) GetParamName() const
	{
		return paramName;
	}

	N_DECLARE_CLASS(NFormatException)
};

namespace IO
{

class N_CLASS(NFileFormatException) : public N_CLASS(NFormatException)
{
private:
	N_CLASS(NString) fileName;

protected:
	N_CLASS(NFileFormatException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NFormatException)(code, pInnerException), fileName()
	{
	}

	N_CLASS(NFileFormatException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NFormatException)(code, message, N_CLASS(NString)(), pInnerException), fileName(fileName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return fileName.IsEmpty() ? N_CLASS(NFormatException)::GetParams() : N_T("FileName: ") + fileName;
	}

public:
	N_CLASS(NFileFormatException)()
		: N_CLASS(NFormatException)(N_E_FILE_FORMAT, NULL), fileName()
	{
	}

	explicit N_CLASS(NFileFormatException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NFormatException)(N_E_FILE_FORMAT, message, N_CLASS(NString)(), pInnerException), fileName()
	{
	}

	N_CLASS(NFileFormatException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NFormatException)(N_E_FILE_FORMAT, message, N_CLASS(NString)(), pInnerException), fileName(fileName)
	{
	}

	N_CLASS(NString) GetFileName() const
	{
		return fileName;
	}

	N_DECLARE_CLASS(NFileFormatException)
};

} // namespace IO

class N_CLASS(NIndexOutOfRangeException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NIndexOutOfRangeException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NIndexOutOfRangeException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NIndexOutOfRangeException)()
		: N_CLASS(NCoreException)(N_E_INDEX_OUT_OF_RANGE, NULL)
	{
	}

	explicit N_CLASS(NIndexOutOfRangeException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_INDEX_OUT_OF_RANGE, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NIndexOutOfRangeException)
};

class N_CLASS(NInvalidCastException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NInvalidCastException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NInvalidCastException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NInvalidCastException)()
		: N_CLASS(NCoreException)(N_E_INVALID_CAST, NULL)
	{
	}

	explicit N_CLASS(NInvalidCastException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_INVALID_CAST, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NInvalidCastException)
};

class N_CLASS(NInvalidOperationException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NInvalidOperationException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NInvalidOperationException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NInvalidOperationException)()
		: N_CLASS(NCoreException)(N_E_INVALID_OPERATION, NULL)
	{
	}

	explicit N_CLASS(NInvalidOperationException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_INVALID_OPERATION, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NInvalidOperationException)
};

namespace IO
{

class N_CLASS(NIOException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NIOException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NIOException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NIOException)()
		: N_CLASS(NCoreException)(N_E_IO, NULL)
	{
	}

	explicit N_CLASS(NIOException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_IO, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NIOException)
};

class N_CLASS(NDirectoryNotFoundException) : public N_CLASS(NIOException)
{
private:
	N_CLASS(NString) path;

protected:
	N_CLASS(NDirectoryNotFoundException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, pInnerException), path()
	{
	}

	N_CLASS(NDirectoryNotFoundException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, message, pInnerException), path(path)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return path.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("Path: ") + path;
	}

public:
	N_CLASS(NDirectoryNotFoundException)()
		: N_CLASS(NIOException)(N_E_DIRECTORY_NOT_FOUND, NULL), path()
	{
	}

	explicit N_CLASS(NDirectoryNotFoundException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_DIRECTORY_NOT_FOUND, message, pInnerException), path()
	{
	}

	N_CLASS(NDirectoryNotFoundException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_DIRECTORY_NOT_FOUND, message, pInnerException), path(path)
	{
	}

	N_CLASS(NString) GetPath() const
	{
		return path;
	}

	N_DECLARE_CLASS(NDirectoryNotFoundException)
};

class N_CLASS(NDriveNotFoundException) : public N_CLASS(NIOException)
{
private:
	N_CLASS(NString) path;

protected:
	N_CLASS(NDriveNotFoundException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, pInnerException), path()
	{
	}

	N_CLASS(NDriveNotFoundException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, message, pInnerException), path(path)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return path.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("Path: ") + path;
	}

public:
	N_CLASS(NDriveNotFoundException)()
		: N_CLASS(NIOException)(N_E_DRIVE_NOT_FOUND, NULL), path()
	{
	}

	explicit N_CLASS(NDriveNotFoundException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_DRIVE_NOT_FOUND, message, pInnerException), path()
	{
	}

	N_CLASS(NDriveNotFoundException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_DRIVE_NOT_FOUND, message, pInnerException), path(path)
	{
	}

	N_CLASS(NString) GetPath() const
	{
		return path;
	}

	N_DECLARE_CLASS(NDriveNotFoundException)
};

class N_CLASS(NEndOfStreamException) : public N_CLASS(NIOException)
{
protected:
	N_CLASS(NEndOfStreamException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, pInnerException)
	{
	}

	N_CLASS(NEndOfStreamException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NEndOfStreamException)()
		: N_CLASS(NIOException)(N_E_END_OF_STREAM, NULL)
	{
	}

	explicit N_CLASS(NEndOfStreamException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_END_OF_STREAM, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NEndOfStreamException)
};

class N_CLASS(NFileNotFoundException) : public N_CLASS(NIOException)
{
private:
	N_CLASS(NString) fileName;

protected:
	N_CLASS(NFileNotFoundException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, pInnerException), fileName()
	{
	}

	N_CLASS(NFileNotFoundException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, message, pInnerException), fileName(fileName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return fileName.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("FileName: ") + fileName;
	}

public:
	N_CLASS(NFileNotFoundException)()
		: N_CLASS(NIOException)(N_E_FILE_NOT_FOUND, NULL), fileName()
	{
	}

	explicit N_CLASS(NFileNotFoundException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_FILE_NOT_FOUND, message, pInnerException), fileName()
	{
	}

	N_CLASS(NFileNotFoundException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_FILE_NOT_FOUND, message, pInnerException), fileName(fileName)
	{
	}

	N_CLASS(NString) GetFileName() const
	{
		return fileName;
	}

	N_DECLARE_CLASS(NFileNotFoundException)
};

class N_CLASS(NFileLoadException) : public N_CLASS(NIOException)
{
private:
	N_CLASS(NString) fileName;

protected:
	N_CLASS(NFileLoadException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, pInnerException), fileName()
	{
	}

	N_CLASS(NFileLoadException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, message, pInnerException), fileName(fileName)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return fileName.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("FileName: ") + fileName;
	}

public:
	N_CLASS(NFileLoadException)()
		: N_CLASS(NIOException)(N_E_FILE_LOAD, NULL), fileName()
	{
	}

	explicit N_CLASS(NFileLoadException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_FILE_LOAD, message, pInnerException), fileName()
	{
	}

	N_CLASS(NFileLoadException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_FILE_NOT_FOUND, message, pInnerException), fileName(fileName)
	{
	}

	N_CLASS(NString) GetFileName() const
	{
		return fileName;
	}

	N_DECLARE_CLASS(NFileLoadException)
};

class N_CLASS(NPathTooLongException) : public N_CLASS(NIOException)
{
private:
	N_CLASS(NString) path;

protected:
	N_CLASS(NPathTooLongException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, pInnerException), path()
	{
	}

	N_CLASS(NPathTooLongException)(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException)
		: N_CLASS(NIOException)(code, message, pInnerException), path(path)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return path.IsEmpty() ? N_CLASS(NException)::GetParams() : N_T("Path: ") + path;
	}

public:
	N_CLASS(NPathTooLongException)()
		: N_CLASS(NIOException)(N_E_PATH_TOO_LONG, NULL), path()
	{
	}

	explicit N_CLASS(NPathTooLongException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_PATH_TOO_LONG, message, pInnerException), path()
	{
	}

	N_CLASS(NPathTooLongException)(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NIOException)(N_E_PATH_TOO_LONG, message, pInnerException), path(path)
	{
	}

	N_CLASS(NString) GetPath() const
	{
		return path;
	}

	N_DECLARE_CLASS(NPathTooLongException)
};

} // namespace IO

namespace Net
{

	class N_CLASS(NSocketException) : public ::Neurotec::IO::N_CLASS(NIOException)
{
protected:
	N_CLASS(NSocketException)(NResult code, N_CLASS(NException) * pInnerException)
		: ::Neurotec::IO::N_CLASS(NIOException)(code, pInnerException)
	{
	}

	N_CLASS(NSocketException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: ::Neurotec::IO::N_CLASS(NIOException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NSocketException)()
		: ::Neurotec::IO::N_CLASS(NIOException)(N_E_SOCKET, NULL)
	{
	}

	explicit N_CLASS(NSocketException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: ::Neurotec::IO::N_CLASS(NIOException)(N_E_SOCKET, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NSocketException)
};

} // namespace Net

namespace Collections
{

class N_CLASS(NKeyNotFoundException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NKeyNotFoundException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NKeyNotFoundException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NKeyNotFoundException)()
		: N_CLASS(NCoreException)(N_E_KEY_NOT_FOUND, NULL)
	{
	}

	explicit N_CLASS(NKeyNotFoundException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_KEY_NOT_FOUND, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NKeyNotFoundException)
};

} // namespace Collections

class N_CLASS(NNotImplementedException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NNotImplementedException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NNotImplementedException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NNotImplementedException)()
		: N_CLASS(NCoreException)(N_E_NOT_IMPLEMENTED, NULL)
	{
	}

	explicit N_CLASS(NNotImplementedException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_NOT_IMPLEMENTED, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NNotImplementedException)
};

class N_CLASS(NNotSupportedException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NNotSupportedException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NNotSupportedException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NNotSupportedException)()
		: N_CLASS(NCoreException)(N_E_NOT_SUPPORTED, NULL)
	{
	}

	explicit N_CLASS(NNotSupportedException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_NOT_SUPPORTED, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NNotSupportedException)
};

class N_CLASS(NNullReferenceException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NNullReferenceException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NNullReferenceException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NNullReferenceException)()
		: N_CLASS(NCoreException)(N_E_NULL_REFERENCE, NULL)
	{
	}

	explicit N_CLASS(NNullReferenceException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_NULL_REFERENCE, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NNullReferenceException)
};

class N_CLASS(NOutOfMemoryException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NOutOfMemoryException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NOutOfMemoryException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NOutOfMemoryException)()
		: N_CLASS(NCoreException)(N_E_OUT_OF_MEMORY, NULL)
	{
	}

	explicit N_CLASS(NOutOfMemoryException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_OUT_OF_MEMORY, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NOutOfMemoryException)
};

namespace Security
{

class N_CLASS(NSecurityException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NSecurityException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NSecurityException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NSecurityException)()
		: N_CLASS(NCoreException)(N_E_SECURITY, NULL)
	{
	}

	explicit N_CLASS(NSecurityException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_SECURITY, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NSecurityException)
};

} // namespace Security

class N_CLASS(NTimeoutException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NTimeoutException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NTimeoutException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NTimeoutException)()
		: N_CLASS(NCoreException)(N_E_TIMEOUT, NULL)
	{
	}

	explicit N_CLASS(NTimeoutException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_TIMEOUT, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NTimeoutException)
};

class N_CLASS(NExternalException) : public N_CLASS(NCoreException)
{
private:
	NInt errorCode;

protected:
	N_CLASS(NExternalException)(NResult code, NInt errorCode, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException), errorCode(errorCode)
	{
	}

	N_CLASS(NExternalException)(NResult code, NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException), errorCode(errorCode)
	{
	}

	virtual N_CLASS(NString) GetParams() const
	{
		return errorCode == 0 ? N_CLASS(NException)::GetParams() : N_CLASS(NString)::Format(N_T("ErrorCode: {I}"), errorCode);
	}

public:
	N_CLASS(NExternalException)()
		: N_CLASS(NCoreException)(N_E_EXTERNAL, NULL), errorCode(0)
	{
	}

	N_CLASS(NExternalException)(NInt errorCode)
		: N_CLASS(NCoreException)(N_E_EXTERNAL, NULL), errorCode(errorCode)
	{
	}

	explicit N_CLASS(NExternalException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_EXTERNAL, message, pInnerException), errorCode(0)
	{
	}

	N_CLASS(NExternalException)(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_EXTERNAL, message, pInnerException), errorCode(errorCode)
	{
	}

	NInt GetErrorCode() const
	{
		return errorCode;
	}

	N_DECLARE_CLASS(NExternalException)
};

class N_CLASS(NClrException) : public N_CLASS(NExternalException)
{
protected:
	N_CLASS(NClrException)(NResult code, NInt errorCode, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, pInnerException)
	{
	}

	N_CLASS(NClrException)(NResult code, NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, message, pInnerException)
	{
	}

public:
	N_CLASS(NClrException)()
		: N_CLASS(NExternalException)(N_E_CLR, 0, NULL)
	{
	}

	explicit N_CLASS(NClrException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_CLR, 0, message, pInnerException)
	{
	}

	N_CLASS(NClrException)(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_CLR, errorCode, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NClrException)
};

class N_CLASS(NComException) : public N_CLASS(NExternalException)
{
protected:
	N_CLASS(NComException)(NResult code, NInt errorCode, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, pInnerException)
	{
	}

	N_CLASS(NComException)(NResult code, NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, message, pInnerException)
	{
	}

public:
	N_CLASS(NComException)()
		: N_CLASS(NExternalException)(N_E_COM, 0, NULL)
	{
	}

	explicit N_CLASS(NComException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_COM, 0, message, pInnerException)
	{
	}

	N_CLASS(NComException)(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_COM, errorCode, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NComException)
};

class N_CLASS(NCppException) : public N_CLASS(NExternalException)
{
protected:
	N_CLASS(NCppException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, 0, pInnerException)
	{
	}

	N_CLASS(NCppException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, 0, message, pInnerException)
	{
	}

public:
	N_CLASS(NCppException)()
		: N_CLASS(NExternalException)(N_E_CPP, 0, NULL)
	{
	}

	explicit N_CLASS(NCppException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_CPP, 0, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NCppException)
};

class N_CLASS(NJvmException) : public N_CLASS(NExternalException)
{
protected:
	N_CLASS(NJvmException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, 0, pInnerException)
	{
	}

	N_CLASS(NJvmException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, 0, message, pInnerException)
	{
	}

public:
	N_CLASS(NJvmException)()
		: N_CLASS(NExternalException)(N_E_JVM, 0, NULL)
	{
	}

	explicit N_CLASS(NJvmException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_JVM, 0, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NJvmException)
};

class N_CLASS(NMacException) : public N_CLASS(NExternalException)
{
	static N_CLASS(NString) GetErrorMessage(NInt errorCode)
	{
		HNString hValue;
		return NFailed(NErrorGetMacErrorMessageN(errorCode, &hValue)) ? N_CLASS(NString)() : N_CLASS(NString)(hValue, true);
	}

protected:
	N_CLASS(NMacException)(NResult code, NInt errorCode, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, pInnerException)
	{
	}

	N_CLASS(NMacException)(NResult code, NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, message, pInnerException)
	{
	}

public:
	N_CLASS(NMacException)()
		: N_CLASS(NExternalException)(N_E_MAC, 0, NULL)
	{
	}

	explicit N_CLASS(NMacException)(NInt errorCode)
		: N_CLASS(NExternalException)(N_E_MAC, errorCode, GetErrorMessage(errorCode), NULL)
	{
	}

	explicit N_CLASS(NMacException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_MAC, 0, message, pInnerException)
	{
	}

	N_CLASS(NMacException)(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_MAC, errorCode, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NMacException)
};

class N_CLASS(NSysException) : public N_CLASS(NExternalException)
{
	static N_CLASS(NString) GetErrorMessage(NInt errorCode)
	{
		HNString hValue;
		return NFailed(NErrorGetSysErrorMessageN(errorCode, &hValue)) ? N_CLASS(NString)() : N_CLASS(NString)(hValue, true);
	}

protected:
	N_CLASS(NSysException)(NResult code, NInt errorCode, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, pInnerException)
	{
	}

	N_CLASS(NSysException)(NResult code, NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, errorCode, message, pInnerException)
	{
	}

public:
	N_CLASS(NSysException)()
		: N_CLASS(NExternalException)(N_E_SYS, NErrorGetLastSysError(), GetErrorMessage(NErrorGetLastSysError()), NULL)
	{
	}

	explicit N_CLASS(NSysException)(NInt errorCode)
		: N_CLASS(NExternalException)(N_E_SYS, errorCode, GetErrorMessage(errorCode), NULL)
	{
	}

	explicit N_CLASS(NSysException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_SYS, NErrorGetLastSysError(), message, pInnerException)
	{
	}

	N_CLASS(NSysException)(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_SYS, errorCode, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NSysException)
};

class N_CLASS(NWin32Exception) : public N_CLASS(NExternalException)
{
private:
	static N_CLASS(NString) GetErrorMessage(NUInt errorCode)
	{
		HNString hValue;
		return NFailed(NErrorGetWin32ErrorMessageN(errorCode, &hValue)) ? N_CLASS(NString)() : N_CLASS(NString)(hValue, true);
	}

protected:
	N_CLASS(NWin32Exception)(NResult code, NUInt errorCode, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, (NInt)errorCode, pInnerException)
	{
	}

	N_CLASS(NWin32Exception)(NResult code, NUInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NExternalException)(code, (NInt)errorCode, message, pInnerException)
	{
	}

public:
	N_CLASS(NWin32Exception)()
		: N_CLASS(NExternalException)(N_E_WIN32, (NInt)NErrorGetLastWin32Error(), GetErrorMessage(NErrorGetLastWin32Error()), NULL)
	{
	}

	explicit N_CLASS(NWin32Exception)(NUInt errorCode)
		: N_CLASS(NExternalException)(N_E_WIN32, (NInt)errorCode, GetErrorMessage(errorCode), NULL)
	{
	}

	explicit N_CLASS(NWin32Exception)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_WIN32, (NInt)NErrorGetLastWin32Error(), message, pInnerException)
	{
	}

	N_CLASS(NWin32Exception)(NUInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NExternalException)(N_E_WIN32, (NInt)errorCode, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NWin32Exception)
};

class N_CLASS(NParameterException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NParameterException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NParameterException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NParameterException)()
		: N_CLASS(NCoreException)(N_E_PARAMETER, NULL)
	{
	}

	explicit N_CLASS(NParameterException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_PARAMETER, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NParameterException)
};

class N_CLASS(NParameterReadOnlyException) : public N_CLASS(NParameterException)
{
protected:
	N_CLASS(NParameterReadOnlyException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NParameterException)(code, pInnerException)
	{
	}

	N_CLASS(NParameterReadOnlyException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NParameterException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NParameterReadOnlyException)()
		: N_CLASS(NParameterException)(N_E_PARAMETER_READ_ONLY, NULL)
	{
	}

	explicit N_CLASS(NParameterReadOnlyException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NParameterException)(N_E_PARAMETER_READ_ONLY, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NParameterReadOnlyException)
};

class N_CLASS(NNotActivatedException) : public N_CLASS(NCoreException)
{
protected:
	N_CLASS(NNotActivatedException)(NResult code, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, pInnerException)
	{
	}

	N_CLASS(NNotActivatedException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

public:
	N_CLASS(NNotActivatedException)()
		: N_CLASS(NCoreException)(N_E_NOT_ACTIVATED, NULL)
	{
	}

	explicit N_CLASS(NNotActivatedException)(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(N_E_NOT_ACTIVATED, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NNotActivatedException)
};

class N_CLASS(NeurotecException) : public N_CLASS(NCoreException)
{
protected:
	virtual N_CLASS(NString) GetParams() const
	{
		return N_CLASS(NString)::Format(N_T("Code: {I}"), GetCode());
	}

public:
	N_CLASS(NeurotecException)(NResult code)
		: N_CLASS(NCoreException)(code, NULL)
	{
	}

	N_CLASS(NeurotecException)(NResult code, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL)
		: N_CLASS(NCoreException)(code, message, pInnerException)
	{
	}

	N_DECLARE_CLASS(NeurotecException)
};

inline N_CLASS(NException) * N_CLASS(NException)::Get(NResult code, const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & param, NInt externalError, N_CLASS(NException) * pInnerException)
{
	switch(code)
	{
	case N_E_FAILED:
		return new N_CLASS(NException)(message, pInnerException);
	case N_E_CORE:
		return new N_CLASS(NCoreException)(message, pInnerException);
	case N_E_ABANDONED_MUTEX:
		return new Threading::N_CLASS(NAbandonedMutexException)(message, pInnerException);
	case N_E_ARGUMENT:
		return new N_CLASS(NArgumentException)(message, param, pInnerException);
	case N_E_ARGUMENT_NULL:
		return new N_CLASS(NArgumentNullException)(param, message, pInnerException);
	case N_E_ARGUMENT_OUT_OF_RANGE:
		return new N_CLASS(NArgumentOutOfRangeException)(param, message, pInnerException);
	case N_E_INVALID_ENUM_ARGUMENT:
		return new N_CLASS(NInvalidEnumArgumentException)(param, message, pInnerException);
	case N_E_ARITHMETIC:
		return new N_CLASS(NArithmeticException)(message, pInnerException);
	case N_E_OVERFLOW:
		return new N_CLASS(NOverflowException)(message, pInnerException);
	case N_E_BAD_IMAGE_FORMAT:
		return new N_CLASS(NBadImageFormatException)(message, param, pInnerException);
	case N_E_DLL_NOT_FOUND:
		return new N_CLASS(NDllNotFoundException)(message, param, pInnerException);
	case N_E_ENTRY_POINT_NOT_FOUND:
		return new N_CLASS(NEntryPointNotFoundException)(message, param, pInnerException);
	case N_E_FORMAT:
		return new N_CLASS(NFormatException)(param, message, pInnerException);
	case N_E_FILE_FORMAT:
		return new IO::N_CLASS(NFileFormatException)(message, param, pInnerException);
	case N_E_INDEX_OUT_OF_RANGE:
		return new N_CLASS(NIndexOutOfRangeException)(message, pInnerException);
	case N_E_INVALID_CAST:
		return new N_CLASS(NInvalidCastException)(message, pInnerException);
	case N_E_INVALID_OPERATION:
		return new N_CLASS(NInvalidOperationException)(message, pInnerException);
	case N_E_IO:
		return new IO::N_CLASS(NIOException)(message, pInnerException);
	case N_E_DIRECTORY_NOT_FOUND:
		return new IO::N_CLASS(NDirectoryNotFoundException)(message, param, pInnerException);
	case N_E_DRIVE_NOT_FOUND:
		return new IO::N_CLASS(NDriveNotFoundException)(message, param, pInnerException);
	case N_E_END_OF_STREAM:
		return new IO::N_CLASS(NEndOfStreamException)(message, pInnerException);
	case N_E_FILE_NOT_FOUND:
		return new IO::N_CLASS(NFileNotFoundException)(message, param, pInnerException);
	case N_E_FILE_LOAD:
		return new IO::N_CLASS(NFileLoadException)(message, param, pInnerException);
	case N_E_PATH_TOO_LONG:
		return new IO::N_CLASS(NPathTooLongException)(message, param, pInnerException);
	case N_E_SOCKET:
		return new Net::N_CLASS(NSocketException)(message, pInnerException);
	case N_E_KEY_NOT_FOUND:
		return new Collections::N_CLASS(NKeyNotFoundException)(message, pInnerException);
	case N_E_NOT_IMPLEMENTED:
		return new N_CLASS(NNotImplementedException)(message, pInnerException);
	case N_E_NOT_SUPPORTED:
		return new N_CLASS(NNotSupportedException)(message, pInnerException);
	case N_E_NULL_REFERENCE:
		return new N_CLASS(NNullReferenceException)(message, pInnerException);
	case N_E_OUT_OF_MEMORY:
		return new N_CLASS(NOutOfMemoryException)(message, pInnerException);
	case N_E_SECURITY:
		return new Security::N_CLASS(NSecurityException)(message, pInnerException);
	case N_E_TIMEOUT:
		return new N_CLASS(NTimeoutException)(message, pInnerException);
	case N_E_EXTERNAL:
		return new N_CLASS(NExternalException)(externalError, message, pInnerException);
	case N_E_CLR:
		return new N_CLASS(NClrException)(externalError, message, pInnerException);
	case N_E_COM:
		return new N_CLASS(NComException)(externalError, message, pInnerException);
	case N_E_CPP:
		return new N_CLASS(NCppException)(message, pInnerException);
	case N_E_JVM:
		return new N_CLASS(NJvmException)(message, pInnerException);
	case N_E_MAC:
		return new N_CLASS(NMacException)(externalError, message, pInnerException);
	case N_E_SYS:
		return new N_CLASS(NSysException)(externalError, message, pInnerException);
	case N_E_WIN32:
		return new N_CLASS(NWin32Exception)(externalError, message, pInnerException);
	case N_E_PARAMETER:
		return new N_CLASS(NParameterException)(message, pInnerException);
	case N_E_PARAMETER_READ_ONLY:
		return new N_CLASS(NParameterReadOnlyException)(message, pInnerException);
	case N_E_NOT_ACTIVATED:
		return new N_CLASS(NNotActivatedException)(message, pInnerException);
	default:
		return new N_CLASS(NeurotecException)(code, message, pInnerException);
	}
}

inline NResult N_CLASS(NException)::SetLast(N_CLASS(NException) * pException, NUInt flags)
{
	using IO::N_CLASS(NFileFormatException);
	using IO::N_CLASS(NIOException);
	using IO::N_CLASS(NDirectoryNotFoundException);
	using IO::N_CLASS(NDriveNotFoundException);
	using IO::N_CLASS(NFileNotFoundException);
	using IO::N_CLASS(NFileLoadException);
	using IO::N_CLASS(NPathTooLongException);
	N_CLASS(NException) * pInnerException = pException->GetInnerException();
	flags += NE_SKIP_ONE_FRAME;
	if(pInnerException)
	{
		SetLast(pInnerException, flags | NE_NO_CALL_STACK);
	}
	const NClass * pExceptionClass = NGetObjectClass(pException);
	N_CLASS(NString) message = pException->GetMessage();
	N_CLASS(NString) param;
	N_CLASS(NString) externalCallStack = pException->GetCallStack();
	NInt externalError = 0;
	if (NIsClassAssignableFrom(N_CLASS_OF(NArgumentException), pExceptionClass))
	{
		param = ((N_CLASS(NArgumentException) *)pException)->GetParamName();
	}
	else if (NIsClassAssignableFrom(N_CLASS_OF(NBadImageFormatException), pExceptionClass))
	{
		param = ((N_CLASS(NBadImageFormatException) *)pException)->GetFileName();
	}
	else if (NIsClassAssignableFrom(N_CLASS_OF(NDllNotFoundException), pExceptionClass))
	{
		param = ((N_CLASS(NDllNotFoundException) *)pException)->GetFileName();
	}
	else if (NIsClassAssignableFrom(N_CLASS_OF(NEntryPointNotFoundException), pExceptionClass))
	{
		param = ((N_CLASS(NEntryPointNotFoundException) *)pException)->GetSymbolName();
	}
	else if (NIsClassAssignableFrom(N_CLASS_OF(NFormatException), pExceptionClass))
	{
		param = ((N_CLASS(NFormatException) *)pException)->GetParamName();
	}
	else if (NIsClassAssignableFrom(N_CLASS_OF(NFileFormatException), pExceptionClass))
	{
		param = ((N_CLASS(NFileFormatException) *)pException)->GetFileName();
	}
	else if (NIsClassAssignableFrom(N_CLASS_OF(NIOException), pExceptionClass))
	{
		if (NIsClassAssignableFrom(N_CLASS_OF(NDirectoryNotFoundException), pExceptionClass))
		{
			param = ((N_CLASS(NDirectoryNotFoundException) *)pException)->GetPath();
		}
		else if (NIsClassAssignableFrom(N_CLASS_OF(NDriveNotFoundException), pExceptionClass))
		{
			param = ((N_CLASS(NDriveNotFoundException) *)pException)->GetPath();
		}
		else if (NIsClassAssignableFrom(N_CLASS_OF(NFileNotFoundException), pExceptionClass))
		{
			param = ((N_CLASS(NFileNotFoundException) *)pException)->GetFileName();
		}
		else if (NIsClassAssignableFrom(N_CLASS_OF(NFileLoadException), pExceptionClass))
		{
			param = ((N_CLASS(NFileLoadException) *)pException)->GetFileName();
		}
		else if (NIsClassAssignableFrom(N_CLASS_OF(NPathTooLongException), pExceptionClass))
		{
			param = ((N_CLASS(NPathTooLongException) *)pException)->GetPath();
		}
	}
	else if (NIsClassAssignableFrom(N_CLASS_OF(NExternalException), pExceptionClass))
	{
		externalError = ((N_CLASS(NExternalException) *)pException)->GetErrorCode();
	}
	return NErrorSetLastN(pException->GetCode(), message.GetHandle(), param.GetHandle(), externalError, externalCallStack.GetHandle(), flags | (pInnerException ? NE_PRESERVE_INNER_ERROR : 0));
}

inline void N_NO_RETURN NRaiseError(NResult error)
{
	N_CLASS(NException)::CheckCode(error);
	throw N_CLASS(NException)::GetLast(error);
}

inline NInt NCheck(NResult result)
{
	if (NFailed(result))
	{
		NRaiseError(result);
	}
	return result;
}

inline void N_NO_RETURN NThrowException() { throw new N_CLASS(NException)(); }
inline void N_NO_RETURN NThrowException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NException)(message, pInnerException); }
inline void N_NO_RETURN NThrowCoreException() { throw new N_CLASS(NCoreException)(); }
inline void N_NO_RETURN NThrowCoreException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NCoreException)(message, pInnerException); }
inline void N_NO_RETURN NThrowAbandonedMutexException() { throw new Threading::N_CLASS(NAbandonedMutexException)(); }
inline void N_NO_RETURN NThrowAbandonedMutexException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new Threading::N_CLASS(NAbandonedMutexException)(message, pInnerException); }
inline void N_NO_RETURN NThrowArgumentException() { throw new N_CLASS(NArgumentException)(); }
inline void N_NO_RETURN NThrowArgumentException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException) { throw new N_CLASS(NArgumentException)(message, pInnerException); }
inline void N_NO_RETURN NThrowArgumentException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException) { throw new N_CLASS(NArgumentException)(message, paramName, pInnerException); }
inline void N_NO_RETURN NThrowArgumentValueException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(paramName + N_T(" is invalid"), paramName); }
inline void N_NO_RETURN NThrowArgumentNotNullException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(paramName + N_T(" is not NULL"), paramName); }
inline void N_NO_RETURN NThrowArgumentNotZeroException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(paramName + N_T(" is not zero"), paramName); }
inline void N_NO_RETURN NThrowArgumentTypeException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(paramName + N_T(" type is not the one that is expected"), paramName); }
inline void N_NO_RETURN NThrowArgumentElementTypeException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(N_T("One of ") + paramName + N_T(" elements type is not the one that is expected"), paramName); }
inline void N_NO_RETURN NThrowEmptyStringArgumentException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(paramName + N_T(" is an empty string"), paramName); }
inline void N_NO_RETURN NThrowNotEmptyStringArgumentException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(paramName + N_T(" is not an empty string"), paramName); }
inline void N_NO_RETURN NThrowEmptyStringArgumentElementException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(N_T("One of ") + paramName + N_T(" elements is an empty string"), paramName); }
inline void N_NO_RETURN NThrowArgumentElementException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(N_T("One of ") + paramName + N_T(" elements is invalid"), paramName); }
inline void N_NO_RETURN NThrowArgumentInsufficientException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(paramName + N_T(" is insufficient"), paramName); }
inline void N_NO_RETURN NThrowArgumentPointerException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentException)(N_T("Value ") + paramName + N_T(" points to is invalid"), paramName); }
inline void N_NO_RETURN NThrowArgumentNullException() { throw new N_CLASS(NArgumentNullException)(); }
inline void N_NO_RETURN NThrowArgumentNullException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentNullException)(paramName); }
inline void N_NO_RETURN NThrowArgumentNullException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException) { throw new N_CLASS(NArgumentNullException)(message, pInnerException); }
inline void N_NO_RETURN NThrowArgumentNullException(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NArgumentNullException)(paramName, message, pInnerException); }
inline void N_NO_RETURN NThrowArgumentElementNullException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentNullException)(paramName, N_T("One of ") + paramName + N_T(" elements is NULL")); }
inline void N_NO_RETURN NThrowArgumentOutOfRangeException() { throw new N_CLASS(NArgumentOutOfRangeException)(); }
inline void N_NO_RETURN NThrowArgumentOutOfRangeException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentOutOfRangeException)(paramName); }
inline void N_NO_RETURN NThrowArgumentOutOfRangeException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException) { throw new N_CLASS(NArgumentOutOfRangeException)(message, pInnerException); }
inline void N_NO_RETURN NThrowArgumentOutOfRangeException(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NArgumentOutOfRangeException)(paramName, message, pInnerException); }
inline void N_NO_RETURN NThrowArgumentLessThanZeroException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentOutOfRangeException)(paramName, paramName + N_T(" is less than zero")); }
inline void N_NO_RETURN NThrowArgumentLessThanOneException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentOutOfRangeException)(paramName, paramName + N_T(" is less than one")); }
inline void N_NO_RETURN NThrowArgumentLessThanMinusOneException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentOutOfRangeException)(paramName, paramName + N_T(" is less than minus one")); }
inline void N_NO_RETURN NThrowArgumentZeroException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NArgumentOutOfRangeException)(paramName, paramName + N_T(" is zero")); }
inline void N_NO_RETURN NThrowInvalidEnumArgumentException() { throw new N_CLASS(NInvalidEnumArgumentException)(); }
inline void N_NO_RETURN NThrowInvalidEnumArgumentException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NInvalidEnumArgumentException)(paramName); }
inline void N_NO_RETURN NThrowInvalidEnumArgumentException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException) { throw new N_CLASS(NInvalidEnumArgumentException)(message, pInnerException); }
inline void N_NO_RETURN NThrowInvalidEnumArgumentException(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NInvalidEnumArgumentException)(paramName, message, pInnerException); }
inline void N_NO_RETURN NThrowArithmeticException() { throw new N_CLASS(NArithmeticException)(); }
inline void N_NO_RETURN NThrowArithmeticException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NArithmeticException)(message, pInnerException); }
inline void N_NO_RETURN NThrowOverflowException() { throw new N_CLASS(NOverflowException)(); }
inline void N_NO_RETURN NThrowOverflowException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NOverflowException)(message, pInnerException); }
inline void N_NO_RETURN NThrowBadImageFormatException() { throw new N_CLASS(NBadImageFormatException)(); }
inline void N_NO_RETURN NThrowBadImageFormatException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NBadImageFormatException)(message, pInnerException); }
inline void N_NO_RETURN NThrowBadImageFormatException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NBadImageFormatException)(message, fileName, pInnerException); }
inline void N_NO_RETURN NThrowDllNotFoundException() { throw new N_CLASS(NDllNotFoundException)(); }
inline void N_NO_RETURN NThrowDllNotFoundException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NDllNotFoundException)(message, pInnerException); }
inline void N_NO_RETURN NThrowDllNotFoundException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NDllNotFoundException)(message, fileName, pInnerException); }
inline void N_NO_RETURN NThrowEntryPointNotFoundException() { throw new N_CLASS(NEntryPointNotFoundException)(); }
inline void N_NO_RETURN NThrowEntryPointNotFoundException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NEntryPointNotFoundException)(message, pInnerException); }
inline void N_NO_RETURN NThrowEntryPointNotFoundException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & symbolName, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NEntryPointNotFoundException)(message, symbolName, pInnerException); }
inline void N_NO_RETURN NThrowFormatException() { throw new N_CLASS(NFormatException)(); }
inline void N_NO_RETURN NThrowFormatException(const N_CLASS(NStringWrapper) & paramName) { throw new N_CLASS(NFormatException)(paramName); }
inline void N_NO_RETURN NThrowFormatException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException) { throw new N_CLASS(NFormatException)(message, pInnerException); }
inline void N_NO_RETURN NThrowFormatException(const N_CLASS(NStringWrapper) & paramName, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NFormatException)(paramName, message, pInnerException); }
inline void N_NO_RETURN NThrowFileFormatException() { throw new IO::N_CLASS(NFileFormatException)(); }
inline void N_NO_RETURN NThrowFileFormatException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NFileFormatException)(message, pInnerException); }
inline void N_NO_RETURN NThrowFileFormatException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NFileFormatException)(message, fileName, pInnerException); }
inline void N_NO_RETURN NThrowIndexOutOfRangeException() { throw new N_CLASS(NIndexOutOfRangeException)(); }
inline void N_NO_RETURN NThrowIndexOutOfRangeException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NIndexOutOfRangeException)(message, pInnerException); }
inline void N_NO_RETURN NThrowInvalidCastException() { throw new N_CLASS(NInvalidCastException)(); }
inline void N_NO_RETURN NThrowInvalidCastException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NInvalidCastException)(message, pInnerException); }
inline void N_NO_RETURN NThrowInvalidOperationException() { throw new N_CLASS(NInvalidOperationException)(); }
inline void N_NO_RETURN NThrowInvalidOperationException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException) { throw new N_CLASS(NInvalidOperationException)(message, pInnerException); }
inline void N_NO_RETURN NThrowIOException() { throw new IO::N_CLASS(NIOException)(); }
inline void N_NO_RETURN NThrowIOException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NIOException)(message, pInnerException); }
inline void N_NO_RETURN NThrowDirectoryNotFoundException() { throw new IO::N_CLASS(NDirectoryNotFoundException)(); }
inline void N_NO_RETURN NThrowDirectoryNotFoundException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NDirectoryNotFoundException)(message, pInnerException); }
inline void N_NO_RETURN NThrowDirectoryNotFoundException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NDirectoryNotFoundException)(message, path, pInnerException); }
inline void N_NO_RETURN NThrowDriveNotFoundException() { throw new IO::N_CLASS(NDriveNotFoundException)(); }
inline void N_NO_RETURN NThrowDriveNotFoundException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NDriveNotFoundException)(message, pInnerException); }
inline void N_NO_RETURN NThrowDriveNotFoundException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NDriveNotFoundException)(message, path, pInnerException); }
inline void N_NO_RETURN NThrowEndOfStreamException() { throw new IO::N_CLASS(NEndOfStreamException)(); }
inline void N_NO_RETURN NThrowEndOfStreamException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NEndOfStreamException)(message, pInnerException); }
inline void N_NO_RETURN NThrowFileNotFoundException() { throw new IO::N_CLASS(NFileNotFoundException)(); }
inline void N_NO_RETURN NThrowFileNotFoundException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NFileNotFoundException)(message, pInnerException); }
inline void N_NO_RETURN NThrowFileNotFoundException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NFileNotFoundException)(message, fileName, pInnerException); }
inline void N_NO_RETURN NThrowFileLoadException() { throw new IO::N_CLASS(NFileLoadException)(); }
inline void N_NO_RETURN NThrowFileLoadException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NFileLoadException)(message, pInnerException); }
inline void N_NO_RETURN NThrowFileLoadException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & fileName, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NFileLoadException)(message, fileName, pInnerException); }
inline void N_NO_RETURN NThrowPathTooLongException() { throw new IO::N_CLASS(NPathTooLongException)(); }
inline void N_NO_RETURN NThrowPathTooLongException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NPathTooLongException)(message, pInnerException); }
inline void N_NO_RETURN NThrowPathTooLongException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & path, N_CLASS(NException) * pInnerException = NULL) { throw new IO::N_CLASS(NPathTooLongException)(message, path, pInnerException); }
inline void N_NO_RETURN NThrowSocketException() { throw new Net::N_CLASS(NSocketException)(); }
inline void N_NO_RETURN NThrowSocketException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new Net::N_CLASS(NSocketException)(message, pInnerException); }
inline void N_NO_RETURN NThrowKeyNotFoundException() { throw new Collections::N_CLASS(NKeyNotFoundException)(); }
inline void N_NO_RETURN NThrowKeyNotFoundException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new Collections::N_CLASS(NKeyNotFoundException)(message, pInnerException); }
inline void N_NO_RETURN NThrowNotImplementedException() { throw new N_CLASS(NNotImplementedException)(); }
inline void N_NO_RETURN NThrowNotImplementedException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NNotImplementedException)(message, pInnerException); }
inline void N_NO_RETURN NThrowNotSupportedException() { throw new N_CLASS(NNotSupportedException)(); }
inline void N_NO_RETURN NThrowNotSupportedException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NNotSupportedException)(message, pInnerException); }
inline void N_NO_RETURN NThrowNullReferenceException() { throw new N_CLASS(NNullReferenceException)(); }
inline void N_NO_RETURN NThrowNullReferenceException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NNullReferenceException)(message, pInnerException); }
inline void N_NO_RETURN NThrowOutOfMemoryException() { throw new N_CLASS(NOutOfMemoryException)(); }
inline void N_NO_RETURN NThrowOutOfMemoryException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NOutOfMemoryException)(message, pInnerException); }
inline void N_NO_RETURN NThrowSecurityException() { throw new Security::N_CLASS(NSecurityException)(); }
inline void N_NO_RETURN NThrowSecurityException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new Security::N_CLASS(NSecurityException)(message, pInnerException); }
inline void N_NO_RETURN NThrowTimeoutException() { throw new N_CLASS(NTimeoutException)(); }
inline void N_NO_RETURN NThrowTimeoutException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NTimeoutException)(message, pInnerException); }
inline void N_NO_RETURN NThrowExternalException() { throw new N_CLASS(NExternalException)(); }
inline void N_NO_RETURN NThrowExternalException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NExternalException)(message, pInnerException); }
inline void N_NO_RETURN NThrowExternalException(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NExternalException)(errorCode, message, pInnerException); }
inline void N_NO_RETURN NThrowClrException() { throw new N_CLASS(NClrException)(); }
inline void N_NO_RETURN NThrowClrException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NClrException)(message, pInnerException); }
inline void N_NO_RETURN NThrowClrException(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NClrException)(errorCode, message, pInnerException); }
inline void N_NO_RETURN NThrowComException() { throw new N_CLASS(NComException)(); }
inline void N_NO_RETURN NThrowComException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NComException)(message, pInnerException); }
inline void N_NO_RETURN NThrowComException(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NComException)(errorCode, message, pInnerException); }
inline void N_NO_RETURN NThrowCppException() { throw new N_CLASS(NCppException)(); }
inline void N_NO_RETURN NThrowCppException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NCppException)(message, pInnerException); }
inline void N_NO_RETURN NThrowJvmException() { throw new N_CLASS(NJvmException)(); }
inline void N_NO_RETURN NThrowJvmException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NJvmException)(message, pInnerException); }
inline void N_NO_RETURN NThrowMacException() { throw new N_CLASS(NMacException)(); }
inline void N_NO_RETURN NThrowMacException(NInt errorCode) { throw new N_CLASS(NMacException)(errorCode); }
inline void N_NO_RETURN NThrowMacException(NInt errorCode, const N_CLASS(NStringWrapper) & message) { throw new N_CLASS(NMacException)(errorCode, message); }
inline void N_NO_RETURN NThrowMacException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NMacException)(message, pInnerException); }
inline void N_NO_RETURN NThrowMacException(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NMacException)(errorCode, message, pInnerException); }
inline void N_NO_RETURN NThrowSysException() { throw new N_CLASS(NSysException)(); }
inline void N_NO_RETURN NThrowSysException(NInt errorCode) { throw new N_CLASS(NSysException)(errorCode); }
inline void N_NO_RETURN NThrowSysException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NSysException)(message, pInnerException); }
inline void N_NO_RETURN NThrowSysException(NInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NSysException)(errorCode, message, pInnerException); }
inline void N_NO_RETURN NThrowWin32Exception() { throw new N_CLASS(NWin32Exception)(); }
inline void N_NO_RETURN NThrowWin32Exception(NUInt errorCode) { throw new N_CLASS(NWin32Exception)(errorCode); }
inline void N_NO_RETURN NThrowWin32Exception(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NWin32Exception)(message, pInnerException); }
inline void N_NO_RETURN NThrowWin32Exception(NUInt errorCode, const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NWin32Exception)(errorCode, message, pInnerException); }
inline void N_NO_RETURN NThrowParameterException() { throw new N_CLASS(NParameterException)(); }
inline void N_NO_RETURN NThrowParameterException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NParameterException)(message, pInnerException); }
inline void N_NO_RETURN NThrowParameterReadOnlyException() { throw new N_CLASS(NParameterReadOnlyException)(); }
inline void N_NO_RETURN NThrowParameterReadOnlyException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NParameterReadOnlyException)(message, pInnerException); }
inline void N_NO_RETURN NThrowNotActivatedException() { throw new N_CLASS(NNotActivatedException)(); }
inline void N_NO_RETURN NThrowNotActivatedException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL) { throw new N_CLASS(NNotActivatedException)(message, pInnerException); }

inline void N_CLASS(NException)::CheckCode(NResult code)
{
	if(NSucceeded(code))
	{
		NThrowArgumentOutOfRangeException(N_T("code"), N_T("error is greater than or equal to zero"));
	}
}

#if defined(N_MSVC) && !defined(N_NO_UNICODE)
	#define N_EXCEPTION_CATCH_AND_SET_COM(result) \
		catch (const _com_error & e)\
		{\
			(result) = ::Neurotec::N_CLASS(NException)::SetLast(e);\
		}
#else
	#define N_EXCEPTION_CATCH_AND_SET_COM(result)
#endif

#define N_EXCEPTION_SET_STD(code, e, result) (result) = ::Neurotec::N_CLASS(NException)::SetLast(e, code);

#ifdef N_FRAMEWORK_MFC
	#define N_EXCEPTION_DELETE(pException) { pException->Delete(); }
	#define N_EXCEPTION_CATCH_AND_SET_FRAMEWORK(result) \
		catch (CException * pException)\
		{\
			(result) = ::Neurotec::N_CLASS(NException)::SetLast(pException);\
		}
#else
	#define N_EXCEPTION_DELETE(pException) { delete pException; }
	#define N_EXCEPTION_CATCH_AND_SET_FRAMEWORK(result)
#endif

#define N_EXCEPTION_CATCH_AND_SET_LAST(result) \
	catch (::Neurotec::N_CLASS(NException) * pException)\
	{\
		(result) = ::Neurotec::N_CLASS(NException)::SetLast(pException);\
		N_EXCEPTION_DELETE(pException)\
	}\
	N_EXCEPTION_CATCH_AND_SET_FRAMEWORK(result)\
	N_EXCEPTION_CATCH_AND_SET_COM(result)\
	catch (const std::exception & e)\
	{\
		(result) = ::Neurotec::N_CLASS(NException)::SetLast(e);\
	}\
	catch (...)\
	{\
		(result) = NErrorSetLast(N_E_CPP, N_T("A C++ exception was thrown"), NULL, 0, NULL, 0);\
	}

#define N_EXCEPTION_CATCH_AND_SUPPRESS(result) \
	N_EXCEPTION_CATCH_AND_SET_LAST(result)\
	if (NFailed(result)) NErrorSuppress(result);
}

#endif // !N_ERROR_HPP_INCLUDED
