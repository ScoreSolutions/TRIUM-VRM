#ifndef JPEG_HPP_INCLUDED
#define JPEG_HPP_INCLUDED

#include <NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Jpeg.h>
}}

namespace Neurotec { namespace Images
{

#undef JPEG_DEFAULT_QUALITY

const NInt JPEG_DEFAULT_QUALITY = 75;

class N_CLASS(JpegInfo) : public N_CLASS(NImageInfo)
{
	N_DECLARE_OBJECT_CLASS(JpegInfo, NImageInfo)

private:
	N_CLASS(JpegInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NImageInfo)(handle, claimHandle)
	{
	}

public:
	NInt GetQuality() const
	{
		NInt value;
		NCheck(JpegInfoGetQuality(GetHandle(), &value));
		return value;
	}

	void SetQuality(NInt value)
	{
		NCheck(JpegInfoSetQuality(GetHandle(), value));
	}

	bool IsLossless() const
	{
		NBool value;
		NCheck(JpegInfoIsLossless(GetHandle(), &value));
		return value != 0;
	}

	void SetLossless(bool value)
	{
		NCheck(JpegInfoSetLossless(GetHandle(), value ? NTrue : NFalse));
	}
};

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) ", " N_STRINGIZEA(N_CLASS(NImageFormat)) "::GetJpeg and " N_STRINGIZEA(N_CLASS(JpegInfo)) " instead")
	Jpeg
{
private:
	Jpeg() {}
	Jpeg(const Jpeg&) {}

public:
	static N_CLASS(NImage)* LoadImage(const N_CLASS(NStringWrapper) & fileName)
	{
		HNImage handle;
		NCheck(JpegLoadImageFromFileN(fileName.GetHandle(), &handle));
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
		NCheck(JpegLoadImageFromMemoryN(pBuffer->GetHandle(), &handle));
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
		NCheck(JpegLoadImageFromMemory(pBuffer, bufferSize, &handle));
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
		NCheck(JpegLoadImageFromStream(pStream->GetHandle(), &handle));
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
		SaveImage(pImage, JPEG_DEFAULT_QUALITY, fileName);
	}

	static void SaveImage(N_CLASS(NImage)* pImage, NInt quality, const N_CLASS(NStringWrapper) & fileName)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(JpegSaveImageToFileN(pImage->GetHandle(), quality, fileName.GetHandle()));
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage)
	{
		return SaveImage(pImage, JPEG_DEFAULT_QUALITY);
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage, NInt quality)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNBuffer hBuffer;
		NCheck(JpegSaveImageToMemoryN(pImage->GetHandle(), quality, &hBuffer));
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
		return SaveImage(pImage, JPEG_DEFAULT_QUALITY, pBufferSize);
	}

	static void * SaveImage(N_CLASS(NImage) * pImage, NInt quality, NSizeType * pBufferSize)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		void * pBuffer;
		NCheck(JpegSaveImageToMemory(pImage->GetHandle(), quality, &pBuffer, pBufferSize));
		return pBuffer;
	}

	static void SaveImage(N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		SaveImage(pImage, JPEG_DEFAULT_QUALITY, pStream);
	}

	static void SaveImage(N_CLASS(NImage) * pImage, NInt quality, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		NCheck(JpegSaveImageToStream(pImage->GetHandle(), quality, pStream->GetHandle()));
	}
};
#include <NReDeprecate.h>

}}

#endif // !JPEG_HPP_INCLUDED
