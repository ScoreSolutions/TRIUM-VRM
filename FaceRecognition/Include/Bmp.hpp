#ifndef BMP_HPP_INCLUDED
#define BMP_HPP_INCLUDED

#include <NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Bmp.h>
}}
#if defined(N_FRAMEWORK_MFC)
	#include <afxstr.h>
	#include <atlimage.h>
#elif defined(N_FRAMEWORK_WX)
	#include <wx/image.h>
#endif

#include <NImageDefWinTypes.h>

namespace Neurotec { namespace Images
{

class N_CLASS(BmpInfo) : public N_CLASS(NImageInfo)
{
	N_DECLARE_OBJECT_CLASS(BmpInfo, NImageInfo)

private:
	N_CLASS(BmpInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NImageInfo)(handle, claimHandle)
	{
	}
};

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) ", " N_STRINGIZEA(N_CLASS(NImageFormat)) "::GetBmp and " N_STRINGIZEA(N_CLASS(BmpInfo)) " instead")
	N_CLASS(Bmp)
{
private:
	N_CLASS(Bmp)() {}
	N_CLASS(Bmp)(const N_CLASS(Bmp)&) {}

public:
	static N_CLASS(NImage)* LoadImage(const N_CLASS(NStringWrapper) & fileName)
	{
		HNImage handle;
		NCheck(BmpLoadImageFromFileN(fileName.GetHandle(), &handle));
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
		NCheck(BmpLoadImageFromMemoryN(pBuffer->GetHandle(), &handle));
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
		NCheck(BmpLoadImageFromMemory(pBuffer, bufferSize, &handle));
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
		NCheck(BmpLoadImageFromStream(pStream->GetHandle(), &handle));
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

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
	static N_CLASS(NImage)* LoadImageFromHBitmap(HBITMAP hbmp)
	{
		return N_CLASS(NImage)::FromHBitmap(hbmp);
	}
#endif

#if defined(N_FRAMEWORK_MFC)
	static N_CLASS(NImage) * LoadImageFromBitmap(CImage * pImage)
	{
		return N_CLASS(NImage)::FromBitmap(pImage);
	}
#elif defined(N_FRAMEWORK_WX)
	static N_CLASS(NImage) * LoadImageFromBitmap(const wxImage & pImage, float horzResolution, float vertResolution)
	{
		::std::auto_ptr<N_CLASS(NImage)> image(N_CLASS(NImage)::FromBitmap(pImage));
		image->SetHorzResolution(horzResolution);
		image->SetVertResolution(vertResolution);
		image->SetResolutionIsAspectRatio(false);
		return image.release();
	}
#endif

	static void SaveImage(N_CLASS(NImage) * pImage, const N_CLASS(NStringWrapper) & fileName)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(BmpSaveImageToFileN(pImage->GetHandle(), fileName.GetHandle()));
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNBuffer hBuffer;
		NCheck(BmpSaveImageToMemoryN(pImage->GetHandle(), &hBuffer));
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
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		void * pBuffer;
		NCheck(BmpSaveImageToMemory(pImage->GetHandle(), &pBuffer, pBufferSize));
		return pBuffer;
	}

	static void SaveImage(N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		NCheck(BmpSaveImageToStream(pImage->GetHandle(), pStream->GetHandle()));
	}

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
	static HBITMAP SaveImageToHBitmap(N_CLASS(NImage)* pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		return pImage->ToHBitmap();
	}
#endif

#if defined(N_FRAMEWORK_MFC)
	static CImage * SaveImageToBitmap(N_CLASS(NImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		return pImage->ToBitmap();
	}
#elif defined(N_FRAMEWORK_WX)
	static wxImage SaveImageToBitmap(N_CLASS(NImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		return pImage->ToBitmap();
	}
#endif
};
#include <NReDeprecate.h>

}}

#include <NImageUndefWinTypes.h>

#endif // !BMP_HPP_INCLUDED
