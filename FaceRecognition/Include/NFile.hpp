#ifndef N_FILE_HPP_INCLUDED
#define N_FILE_HPP_INCLUDED

#include <NFileStream.hpp>
#include <NStreamReader.hpp>
#include <NStreamWriter.hpp>
namespace Neurotec { namespace IO
{
#include <NFile.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NFile)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NFile)

public:
	static NFileAttributes GetAttributes(const N_CLASS(NStringWrapper) & path)
	{
		NFileAttributes value;
		NCheck(NFileGetAttributesN(path.GetHandle(), &value));
		return value;
	}

	static bool Exists(const N_CLASS(NStringWrapper) & path)
	{
		NBool value;
		NCheck(NFileExistsN(path.GetHandle(), &value));
		return value != 0;
	}

	static void Delete(const N_CLASS(NStringWrapper) & path)
	{
		NCheck(NFileDeleteN(path.GetHandle()));
	}

	static N_CLASS(NFileStream) * Open(const N_CLASS(NStringWrapper) & path, NFileMode mode)
	{
		HNFileStream hValue;
		NCheck(NFileOpenN(path.GetHandle(), mode, &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NFileStream)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NFileStream) * Open(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access)
	{
		HNFileStream hValue;
		NCheck(NFileOpenWithAccessN(path.GetHandle(), mode, access, &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NFileStream)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NFileStream) * Open(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access, NFileShare share)
	{
		HNFileStream hValue;
		NCheck(NFileOpenWithAccessAndShareN(path.GetHandle(), mode, access, share, &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NFileStream)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NFileStream) * Create(const N_CLASS(NStringWrapper) & path)
	{
		HNFileStream hValue;
		NCheck(NFileCreateN(path.GetHandle(), &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NFileStream)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NFileStream) * Create(NSizeType bufferSize, const N_CLASS(NStringWrapper) & path)
	{
		HNFileStream hValue;
		NCheck(NFileCreateWithBufferSizeN(path.GetHandle(), bufferSize, &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NFileStream)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NFileStream) * OpenRead(const N_CLASS(NStringWrapper) & path)
	{
		HNFileStream hValue;
		NCheck(NFileOpenReadN(path.GetHandle(), &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NFileStream)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NFileStream) * OpenWrite(const N_CLASS(NStringWrapper) & path)
	{
		HNFileStream hValue;
		NCheck(NFileOpenWriteN(path.GetHandle(), &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NFileStream)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NBuffer) * ReadAllBytes(const N_CLASS(NStringWrapper) & path)
	{
		HNBuffer hValue;
		NCheck(NFileReadAllBytesN(path.GetHandle(), &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NBuffer)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static void WriteAllBytes(const N_CLASS(NStringWrapper) & path, N_CLASS(NBuffer) * pContent)
	{
		if (!pContent) NThrowArgumentNullException(N_T("pContent"));
		NCheck(NFileWriteAllBytesN(path.GetHandle(), pContent->GetHandle()));
	}

	static void WriteAllBytes(const N_CLASS(NStringWrapper) & path, const void * pContent, NSizeType contentLength)
	{
		if (!pContent) NThrowArgumentNullException(N_T("pContent"));
		NCheck(NFileWriteAllBytesPN(path.GetHandle(), pContent, contentLength));
	}

	static N_CLASS(NStreamReader) * OpenText(const N_CLASS(NStringWrapper) & path)
	{
		HNStreamReader hValue;
		NCheck(NFileOpenTextN(path.GetHandle(), &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NStreamReader)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NStreamWriter) * AppendText(const N_CLASS(NStringWrapper) & path)
	{
		HNStreamWriter hValue;
		NCheck(NFileAppendTextN(path.GetHandle(), &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NStreamWriter)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NStreamWriter) * CreateText(const N_CLASS(NStringWrapper) & path)
	{
		HNStreamWriter hValue;
		NCheck(NFileCreateTextN(path.GetHandle(), &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NStreamWriter)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	static N_CLASS(NString) * ReadAllLines(const N_CLASS(NStringWrapper) & path, NInt * pContentLength)
	{
		HNString * arhContent;
		NCheck(NFileReadAllLinesN(path.GetHandle(), &arhContent, pContentLength));
		return reinterpret_cast<N_CLASS(NString) *>(arhContent);
	}

	static N_CLASS(NString) * ReadAllLines(const N_CLASS(NStringWrapper) & path, NInt * pContentLength, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
	{
		HNString * arhContent;
		NCheck(NFileReadAllLinesWithEncodingN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &arhContent, pContentLength));
		return reinterpret_cast<N_CLASS(NString) *>(arhContent);
	}

	static N_CLASS(NString) ReadAllText(const N_CLASS(NStringWrapper) & path)
	{
		HNString hContent;
		NCheck(NFileReadAllTextN(path.GetHandle(), &hContent));
		return N_CLASS(NString)(hContent, true);
	}

	static N_CLASS(NString) ReadAllText(const N_CLASS(NStringWrapper) & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
	{
		HNString hContent;
		NCheck(NFileReadAllTextWithEncodingN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &hContent));
		return N_CLASS(NString)(hContent, true);
	}

	static void AppendAllLines(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) * arContent, NInt contentLength)
	{
		NCheck(NFileAppendAllLinesN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength));
	}

	static void AppendAllLines(const N_CLASS(NStringWrapper) & path, const NChar * * arszContent, NInt contentLength)
	{
		NCheck(NFileAppendAllLinesPN(path.GetHandle(), arszContent, contentLength));
	}

	static void AppendAllLines(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) * arContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileAppendAllLinesWithEncodingN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength, encoding));
	}

	static void AppendAllLines(const N_CLASS(NStringWrapper) & path, const NChar * * arszContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileAppendAllLinesWithEncodingPN(path.GetHandle(), arszContent, contentLength, encoding));
	}

	static void AppendAllText(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) & content)
	{
		NCheck(NFileAppendAllTextN(path.GetHandle(), content.GetHandle()));
	}

	static void AppendAllText(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) & content, NEncoding encoding)
	{
		NCheck(NFileAppendAllTextWithEncodingN(path.GetHandle(), content.GetHandle(), encoding));
	}

	static void WriteAllLines(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) * arContent, NInt contentLength)
	{
		NCheck(NFileWriteAllLinesN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength));
	}

	static void WriteAllLines(const N_CLASS(NStringWrapper) & path, const NChar * * arszContent, NInt contentLength)
	{
		NCheck(NFileWriteAllLinesPN(path.GetHandle(), arszContent, contentLength));
	}

	static void WriteAllLines(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) * arContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileWriteAllLinesWithEncodingN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength, encoding));
	}

	static void WriteAllLines(const N_CLASS(NStringWrapper) & path, const NChar * * arszContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileWriteAllLinesWithEncodingPN(path.GetHandle(), arszContent, contentLength, encoding));
	}

	static void WriteAllText(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) & content)
	{
		NCheck(NFileWriteAllTextN(path.GetHandle(), content.GetHandle()));
	}

	static void WriteAllText(const N_CLASS(NStringWrapper) & path, const N_CLASS(NString) & content, NEncoding encoding)
	{
		NCheck(NFileWriteAllTextWithEncodingN(path.GetHandle(), content.GetHandle(), encoding));
	}
};

}}

#endif // !N_FILE_HPP_INCLUDED
