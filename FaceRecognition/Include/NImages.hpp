#ifndef N_IMAGES_HPP_INCLUDED
#define N_IMAGES_HPP_INCLUDED

#include <NRgbImage.hpp>
#include <NMedia.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::Media::NMediaModuleOf;
#include <NImages.h>
}}
#include <NStringBuilder.hpp>

namespace Neurotec { namespace Images
{

#include <NNoDeprecate.h>
class N_CLASS(NImages)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NImages)

public:
	N_DEPRECATED("method is deprecated, use N_NATIVE_MODULE_OF(NMedia) instead")
	static void GetInfo(NLibraryInfo * pValue)
	{
		NCheck(::Neurotec::Media::NMediaGetInfo(pValue));
	}

	static N_CLASS(NString) GetOpenFileFilter()
	{
		::Neurotec::Text::N_CLASS(NStringBuilder) fileFilter;
		for (N_CLASS(NImageFormat)::ImageFormatCollection::ConstIterator i = N_CLASS(NImageFormat)::GetFormats()->GetBegin(); i < N_CLASS(NImageFormat)::GetFormats()->GetEnd(); i++)
		{
			N_CLASS(NImageFormat) * pImageFormat = *i;
			if (pImageFormat->CanRead())
			{
				if (fileFilter.GetLength() != 0)
					fileFilter.AppendChar(N_T(';'));
				fileFilter.Append(pImageFormat->GetFileFilter());
			}
		}
		return fileFilter.DetachString();
	}

	static N_CLASS(NString) GetSaveFileFilter()
	{
		::Neurotec::Text::N_CLASS(NStringBuilder) fileFilter;
		for (N_CLASS(NImageFormat)::ImageFormatCollection::ConstIterator i = N_CLASS(NImageFormat)::GetFormats()->GetBegin(); i < N_CLASS(NImageFormat)::GetFormats()->GetEnd(); i++)
		{
			N_CLASS(NImageFormat) * pImageFormat = *i;
			if (pImageFormat->CanWrite())
			{
				if (fileFilter.GetLength() != 0)
					fileFilter.AppendChar(N_T(';'));
				fileFilter.Append(pImageFormat->GetFileFilter());
			}
		}
		return fileFilter.DetachString();
	}

	static N_CLASS(NString) GetOpenFileFilterString(bool addAllImage, bool addAllFiles)
	{
		::Neurotec::Text::N_CLASS(NStringBuilder) fileFilter;
		N_CLASS(NString) fileFormat = GetOpenFileFilter();
		if (addAllImage)
		{
			fileFilter.Append(N_T("All Image Files ("));
			fileFilter.Append(fileFormat);
			fileFilter.Append(N_T(")|"));
			fileFilter.Append(fileFormat);
		}
		for (N_CLASS(NImageFormat)::ImageFormatCollection::ConstIterator i = N_CLASS(NImageFormat)::GetFormats()->GetBegin(); i < N_CLASS(NImageFormat)::GetFormats()->GetEnd(); i++)
		{
			N_CLASS(NImageFormat) * pImageFormat = *i;
			if (pImageFormat->CanRead())
			{
				N_CLASS(NString) imageFormatFilter = pImageFormat->GetFileFilter();
				if (fileFilter.GetLength() != 0)
					fileFilter.AppendChar(N_T('|'));
				fileFilter.Append(pImageFormat->GetName());
				fileFilter.Append(N_T(" Files ("));
				fileFilter.Append(imageFormatFilter);
				fileFilter.Append(N_T(")|"));
				fileFilter.Append(imageFormatFilter);
			}
		}
		if (addAllFiles)
		{
			fileFilter.Append(N_T("|All Files (*.*)|*.*"));
		}
		return fileFilter.DetachString();
	}

	static N_CLASS(NString) GetSaveFileFilterString()
	{
		::Neurotec::Text::N_CLASS(NStringBuilder) fileFilter;
		for (N_CLASS(NImageFormat)::ImageFormatCollection::ConstIterator i = N_CLASS(NImageFormat)::GetFormats()->GetBegin(); i < N_CLASS(NImageFormat)::GetFormats()->GetEnd(); i++)
		{
			N_CLASS(NImageFormat) * pImageFormat = *i;
			if (pImageFormat->CanWrite())
			{
				N_CLASS(NString) imageFormatFilter = pImageFormat->GetFileFilter();
				if (fileFilter.GetLength() != 0)
					fileFilter.AppendChar(N_T('|'));
				fileFilter.Append(pImageFormat->GetName());
				fileFilter.Append(N_T(" Files ("));
				fileFilter.Append(imageFormatFilter);
				fileFilter.Append(N_T(")|"));
				fileFilter.Append(imageFormatFilter);
			}
		}
		return fileFilter.DetachString();
	}

	static N_CLASS(NImage) * GetGrayscaleColorWrapper(N_CLASS(NImage) * pImage, const N_CLASS(NRgb) & minColor, const N_CLASS(NRgb) & maxColor)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNImage hImage;
		NCheck(NImagesGetGrayscaleColorWrapperEx(pImage->GetHandle(), &minColor, &maxColor, &hImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(hImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hImage);
			throw;
		}
	}

	static N_CLASS(NImage) * RecolorImage(N_CLASS(NImage) * pImage, const N_CLASS(NPixelFormat) & pixelFormat, N_CLASS(NArray) * pMinValue, N_CLASS(NArray) * pMaxValue)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNImage hImage;
		NCheck(NImagesRecolorImage(pImage->GetHandle(), pixelFormat.GetValue(), N_CLASS(NObject)::ToHandle(pMinValue), N_CLASS(NObject)::ToHandle(pMaxValue), &hImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(hImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hImage);
			throw;
		}
	}

	N_DECLARE_MODULE_CLASS(NImages)
};
#include <NReDeprecate.h>

}}

#endif // !N_IMAGES_HPP_INCLUDED
