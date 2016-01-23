#ifndef PNG_HPP_INCLUDED
#define PNG_HPP_INCLUDED

#include <NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Png.h>
}}

namespace Neurotec { namespace Images
{

#undef PNG_DEFAULT_COMPRESSION_LEVEL

const NInt PNG_DEFAULT_COMPRESSION_LEVEL = 6;

class N_CLASS(PngInfo) : public N_CLASS(NImageInfo)
{
	N_DECLARE_OBJECT_CLASS(PngInfo, NImageInfo)

private:
	N_CLASS(PngInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NImageInfo)(handle, claimHandle)
	{
	}

public:
	NInt GetCompressionLevel() const
	{
		NInt value;
		NCheck(PngInfoGetCompressionLevel(GetHandle(), &value));
		return value;
	}

	void SetCompressionLevel(NInt value)
	{
		NCheck(PngInfoSetCompressionLevel(GetHandle(), value));
	}
};

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) ", " N_STRINGIZEA(N_CLASS(NImageFormat)) "::GetPng and " N_STRINGIZEA(N_CLASS(PngInfo)) " instead")
	N_CLASS(Png)
{
private:
	N_CLASS(Png)() {}
	N_CLASS(Png)(const N_CLASS(Png)&) {}

public:
	static N_CLASS(NImage)* LoadImage(const N_CLASS(NStringWrapper) & fileName)
	{
		HNImage handle;
		NCheck(PngLoadImageFromFileN(fileName.GetHandle(), &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImage)* LoadImage(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNImage handle;
		NCheck(PngLoadImageFromMemoryN(pBuffer->GetHandle(), &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImage)* LoadImage(const void * pBuffer, NSizeType bufferSize)
	{
		HNImage handle;
		NCheck(PngLoadImageFromMemory(pBuffer, bufferSize, &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImage)* LoadImage(::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNImage handle;
		NCheck(PngLoadImageFromStream(pStream->GetHandle(), &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}

	static void SaveImage(N_CLASS(NImage)* pImage, const N_CLASS(NStringWrapper) & fileName)
	{
		SaveImage(pImage, PNG_DEFAULT_COMPRESSION_LEVEL, fileName);
	}

	static void SaveImage(N_CLASS(NImage)* pImage, NInt compressionLevel, const N_CLASS(NStringWrapper) & fileName)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(PngSaveImageToFileN(pImage->GetHandle(), compressionLevel, fileName.GetHandle()));
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage)
	{
		return SaveImage(pImage, PNG_DEFAULT_COMPRESSION_LEVEL);
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage, NInt compressionLevel)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNBuffer hBuffer;
		NCheck(PngSaveImageToMemoryN(pImage->GetHandle(), compressionLevel, &hBuffer));
		try
		{
			return N_CLASS(NObject)::FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hBuffer);
			throw;
		}
	}

	static void * SaveImage(N_CLASS(NImage) * pImage, NSizeType * pBufferSize)
	{
		return SaveImage(pImage, PNG_DEFAULT_COMPRESSION_LEVEL, pBufferSize);
	}

	static void * SaveImage(N_CLASS(NImage) * pImage, NInt compressionLevel, NSizeType * pBufferSize)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		void * pBuffer;
		NCheck(PngSaveImageToMemory(pImage->GetHandle(), compressionLevel, &pBuffer, pBufferSize));
		return pBuffer;
	}

	static void SaveImage(N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		SaveImage(pImage, PNG_DEFAULT_COMPRESSION_LEVEL, pStream);
	}

	static void SaveImage(N_CLASS(NImage) * pImage, NInt compressionLevel, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		NCheck(PngSaveImageToStream(pImage->GetHandle(), compressionLevel, pStream->GetHandle()));
	}
};
#include <NReDeprecate.h>

}}

#endif // !PNG_HPP_INCLUDED
