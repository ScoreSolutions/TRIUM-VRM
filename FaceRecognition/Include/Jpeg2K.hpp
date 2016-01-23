#ifndef JPEG2K_HPP_INCLUDED
#define JPEG2K_HPP_INCLUDED

#include <NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Jpeg2K.h>
}}

namespace Neurotec { namespace Images
{

#undef JPEG_2K_DEFAULT_RATIO

const NFloat JPEG_2K_DEFAULT_RATIO = 10.0f;

class N_CLASS(Jpeg2KInfo) : public N_CLASS(NImageInfo)
{
	N_DECLARE_OBJECT_CLASS(Jpeg2KInfo, NImageInfo)

private:
	N_CLASS(Jpeg2KInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NImageInfo)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * Jpeg2KProfileNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(Jpeg2KProfile), true, true);
	}

	Jpeg2KProfile GetProfile() const
	{
		Jpeg2KProfile value;
		NCheck(Jpeg2KInfoGetProfile(GetHandle(), &value));
		return value;
	}

	void SetProfile(Jpeg2KProfile value)
	{
		NCheck(Jpeg2KInfoSetProfile(GetHandle(), value));
	}

	NFloat GetRatio() const
	{
		NFloat value;
		NCheck(Jpeg2KInfoGetRatio(GetHandle(), &value));
		return value;
	}

	void SetRatio(NFloat value)
	{
		NCheck(Jpeg2KInfoSetRatio(GetHandle(), value));
	}
};

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) ", " N_STRINGIZEA(N_CLASS(NImageFormat)) "::GetJpeg2K and " N_STRINGIZEA(N_CLASS(Jpeg2KInfo)) " instead")
	N_CLASS(Jpeg2K)
{
private:
	N_CLASS(Jpeg2K)() {}
	N_CLASS(Jpeg2K)(const N_CLASS(Jpeg2K)&) {}
public:
	static N_CLASS(NImage)* LoadImage(const N_CLASS(NStringWrapper) & fileName)
	{
		HNImage handle;
		NCheck(Jpeg2KLoadImageFromFileN(fileName.GetHandle(), &handle));
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
		NCheck(Jpeg2KLoadImageFromMemoryN(pBuffer->GetHandle(), &handle));
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
		NCheck(Jpeg2KLoadImageFromMemory(pBuffer, bufferSize, &handle));
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
		NCheck(Jpeg2KLoadImageFromStream(pStream->GetHandle(), &handle));
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
		SaveImage(pImage, JPEG_2K_DEFAULT_RATIO, fileName);
	}

	static void SaveImage(N_CLASS(NImage)* pImage, NFloat ratio, const N_CLASS(NStringWrapper) & fileName)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(Jpeg2KSaveImageToFileN(pImage->GetHandle(), ratio, fileName.GetHandle()));
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage)
	{
		return SaveImage(pImage, JPEG_2K_DEFAULT_RATIO);
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage, NFloat ratio)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNBuffer hBuffer;
		NCheck(Jpeg2KSaveImageToMemoryN(pImage->GetHandle(), ratio, &hBuffer));
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
		return SaveImage(pImage, JPEG_2K_DEFAULT_RATIO, pBufferSize);
	}

	static void * SaveImage(N_CLASS(NImage) * pImage, NFloat ratio, NSizeType * pBufferSize)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		void * pBuffer;
		NCheck(Jpeg2KSaveImageToMemory(pImage->GetHandle(), ratio, &pBuffer, pBufferSize));
		return pBuffer;
	}

	static void SaveImage(N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		SaveImage(pImage, JPEG_2K_DEFAULT_RATIO, pStream);
	}

	static void SaveImage(N_CLASS(NImage) * pImage, NFloat ratio, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		NCheck(Jpeg2KSaveImageToStream(pImage->GetHandle(), ratio, pStream->GetHandle()));
	}

	static void SaveImage(N_CLASS(NImage)* pImage, Jpeg2KProfile profile, const N_CLASS(NStringWrapper) & fileName)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(Jpeg2KSaveImageToFileWithProfileN(pImage->GetHandle(), profile, fileName.GetHandle()));
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage, Jpeg2KProfile profile)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNBuffer hBuffer;
		NCheck(Jpeg2KSaveImageToMemoryWithProfileN(pImage->GetHandle(), profile, &hBuffer));
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

	static void * SaveImage(N_CLASS(NImage) * pImage, Jpeg2KProfile profile, NSizeType * pBufferSize)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		void * pBuffer;
		NCheck(Jpeg2KSaveImageToMemoryWithProfile(pImage->GetHandle(), profile, &pBuffer, pBufferSize));
		return pBuffer;
	}

	static void SaveImage(N_CLASS(NImage) * pImage, Jpeg2KProfile profile, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		NCheck(Jpeg2KSaveImageToStreamWithProfile(pImage->GetHandle(), profile, pStream->GetHandle()));
	}
};
#include <NReDeprecate.h>

}}

#endif // !JPEG2K_HPP_INCLUDED
