#ifndef N_IMAGE_FORMAT_HPP_INCLUDED
#define N_IMAGE_FORMAT_HPP_INCLUDED

#include <NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::NFileAccess;
#include <NImageFormat.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NImage);
class N_CLASS(NImageInfo);
class N_CLASS(NImageReader);
class N_CLASS(NImageWriter);
class N_CLASS(NImageFile);

#include <NNoDeprecate.h>
class N_CLASS(NImageFormat) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NImageFormat, NObject)

public:
	class ImageFormatCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NImageFormat), N_CLASS(NImageFormat)>
	{
		ImageFormatCollection()
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NImageFormat), N_CLASS(NImageFormat)>(NULL)
		{
		}

	protected:
		virtual NResult GetCountNative(HNImageFormat, NInt * pValue) const
		{
			return NImageFormatGetFormatCount(pValue);
		}

		virtual NResult GetNative(HNImageFormat, NInt index, HNImageFormat * phValue) const
		{
			return NImageFormatGetFormatEx(index, phValue);
		}

		virtual NResult GetAllNative(HNImageFormat, HNImageFormat *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NImageFormat);
	};

private:
	static ::std::auto_ptr<ImageFormatCollection> formats;

	N_CLASS(NImageFormat)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NImageFormat) * GetTiff()
	{
		return GetObject<N_CLASS(NImageFormat)>(NImageFormatGetTiffEx, true, true);
	}

	static N_CLASS(NImageFormat) * GetJpeg()
	{
		return GetObject<N_CLASS(NImageFormat)>(NImageFormatGetJpegEx, true, true);
	}

	static N_CLASS(NImageFormat) * GetPng()
	{
		return GetObject<N_CLASS(NImageFormat)>(NImageFormatGetPngEx, true, true);
	}

	static N_CLASS(NImageFormat) * GetWsq()
	{
		return GetObject<N_CLASS(NImageFormat)>(NImageFormatGetWsqEx, true, true);
	}

	static N_CLASS(NImageFormat) * GetJpeg2K()
	{
		return GetObject<N_CLASS(NImageFormat)>(NImageFormatGetJpeg2KEx, true, true);
	}

	static N_CLASS(NImageFormat) * GetBmp()
	{
		return GetObject<N_CLASS(NImageFormat)>(NImageFormatGetBmpEx, true, true);
	}

	static N_CLASS(NImageFormat) * GetIHead()
	{
		return GetObject<N_CLASS(NImageFormat)>(NImageFormatGetIHeadEx, true, true);
	}

	static ImageFormatCollection * GetFormats()
	{
		return formats.get();
	}

	static N_CLASS(NImageFormat) * Select(const N_CLASS(NStringWrapper) & fileName, NFileAccess fileAccess)
	{
		HNImageFormat handle;
		NCheck(NImageFormatSelectExN(fileName.GetHandle(), fileAccess, &handle));
		try
		{
			return FromHandle<N_CLASS(NImageFormat)>(handle, true, true);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImageFormat) * SelectByInternetMediaType(const N_CLASS(NStringWrapper) & internetMediaType, NFileAccess fileAccess)
	{
		HNImageFormat handle;
		NCheck(NImageFormatSelectByInternetMediaTypeN(internetMediaType.GetHandle(), fileAccess, &handle));
		try
		{
			return FromHandle<N_CLASS(NImageFormat)>(handle, true, true);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImageReader) * SelectReader(const N_CLASS(NStringWrapper) & fileName, NUInt flags = 0);
	static N_CLASS(NImageReader) * SelectReader(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0);
	static N_CLASS(NImageReader) * SelectReader(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0);
	static N_CLASS(NImageReader) * SelectReader(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0);
	N_CLASS(NImageReader) * OpenReader(const N_CLASS(NStringWrapper) & fileName, NUInt flags = 0) const;
	N_CLASS(NImageReader) * OpenReader(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0) const;
	N_CLASS(NImageReader) * OpenReader(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0) const;
	N_CLASS(NImageReader) * OpenReader(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0) const;
	N_CLASS(NImageInfo) * CreateInfo(N_CLASS(NImage) * pImage, NUInt flags = 0) const;
	N_CLASS(NImageWriter) * OpenWriter(const N_CLASS(NStringWrapper) & fileName, NUInt flags = 0) const;
	N_CLASS(NImageWriter) * OpenWriter(NUInt flags = 0) const;
	N_CLASS(NImageWriter) * OpenWriter(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0) const;
	N_DEPRECATED("method is deprecated, use OpenReader instead")
	N_CLASS(NImageFile) * OpenFile(const N_CLASS(NStringWrapper) & fileName) const;
	N_DEPRECATED("method is deprecated, use OpenReader instead")
	N_CLASS(NImageFile) * OpenFile(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer) const;
	N_DEPRECATED("method is deprecated, use OpenReader instead")
	N_CLASS(NImageFile) * OpenFile(const void * pBuffer, NSizeType bufferSize) const;
	N_DEPRECATED("method is deprecated, use OpenReader instead")
	N_CLASS(NImageFile) * OpenFile(::Neurotec::IO::N_CLASS(NStream) * pStream) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::FromFile instead")
	N_CLASS(NImage) * LoadImage(const N_CLASS(NStringWrapper) & fileName) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::FromMemory instead")
	N_CLASS(NImage) * LoadImage(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::FromMemory instead")
	N_CLASS(NImage) * LoadImage(const void * pBuffer, NSizeType bufferSize) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::FromMemory instead")
	N_CLASS(NImage) * LoadImage(::Neurotec::IO::N_CLASS(NStream) * pStream) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::Save instead")
	void SaveImage(const N_CLASS(NImage) * pImage, const N_CLASS(NStringWrapper) & fileName) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::Save instead")
	::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(const N_CLASS(NImage) * pImage) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::Save instead")
	void * SaveImage(const N_CLASS(NImage) * pImage, NSizeType * pBufferSize) const;
	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) "::Save instead")
	void SaveImage(const N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream) const;
	N_DEPRECATED("method is deprecated, use OpenWriter and " N_STRINGIZEA(N_CLASS(NImageWriter)) "::Write instead")
	void SaveImages(NInt imageCount, N_CLASS(NImage) * const * arImages, const N_CLASS(NStringWrapper) & fileName) const;
	N_DEPRECATED("method is deprecated, use OpenWriter and " N_STRINGIZEA(N_CLASS(NImageWriter)) "::Write instead")
	::Neurotec::IO::N_CLASS(NBuffer) * SaveImages(NInt imageCount, N_CLASS(NImage) * const * arImages) const;
	N_DEPRECATED("method is deprecated, use OpenWriter and " N_STRINGIZEA(N_CLASS(NImageWriter)) "::Write instead")
	void * SaveImages(NInt imageCount, N_CLASS(NImage) * const * arImages, NSizeType * pBufferSize) const;
	N_DEPRECATED("method is deprecated, use OpenWriter and " N_STRINGIZEA(N_CLASS(NImageWriter)) "::Write instead")
	void SaveImages(NInt imageCount, N_CLASS(NImage) * const * arImages, ::Neurotec::IO::N_CLASS(NStream) * pStream) const;

	N_CLASS(NString) GetName() const
	{
		return GetString(NImageFormatGetNameN);
	}

	N_CLASS(NString) GetDefaultFileExtension() const
	{
		return GetString(NImageFormatGetDefaultFileExtensionN);
	}

	N_CLASS(NString) GetDefaultInternetMediaType() const
	{
		return GetString(NImageFormatGetDefaultInternetMediaTypeN);
	}

	N_CLASS(NString) GetFileFilter() const
	{
		return GetString(NImageFormatGetFileFilterN);
	}

	N_CLASS(NString) GetInternetMediaType() const
	{
		return GetString(NImageFormatGetInternetMediaTypeN);
	}

	bool CanRead() const
	{
		NBool value;
		NCheck(NImageFormatCanRead(GetHandle(), &value));
		return value != 0;
	}

	bool CanWrite() const
	{
		NBool value;
		NCheck(NImageFormatCanWrite(GetHandle(), &value));
		return value != 0;
	}

	bool CanWriteMultiple() const
	{
		NBool value;
		NCheck(NImageFormatCanWriteMultiple(GetHandle(), &value));
		return value != 0;
	}
};
#include <NReDeprecate.h>

}}

#include <NImage.hpp>
#include <NImageInfo.hpp>
#include <NImageReader.hpp>
#include <NImageWriter.hpp>
#include <NImageFile.hpp>

namespace Neurotec { namespace Images
{

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::SelectReader(const N_CLASS(NStringWrapper) & fileName, NUInt flags)
{
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromFileN(fileName.GetHandle(), flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::SelectReader(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromMemoryN(pBuffer->GetHandle(), flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::SelectReader(const void * pBuffer, NSizeType bufferSize, NUInt flags)
{
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromMemory(pBuffer, bufferSize, flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::SelectReader(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromStream(pStream->GetHandle(), flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::OpenReader(const N_CLASS(NStringWrapper) & fileName, NUInt flags) const
{
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromFileN(GetHandle(), fileName.GetHandle(), flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::OpenReader(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags) const
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromMemoryN(GetHandle(), pBuffer->GetHandle(), flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::OpenReader(const void * pBuffer, NSizeType bufferSize, NUInt flags) const
{
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromMemory(GetHandle(), pBuffer, bufferSize, flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageReader) * N_CLASS(NImageFormat)::OpenReader(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags) const
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromStream(GetHandle(), pStream->GetHandle(), flags, &hReader));
	try
	{
		return FromHandle<N_CLASS(NImageReader)>(hReader);
	}
	catch (...)
	{
		Unref(hReader);
		throw;
	}
}

inline N_CLASS(NImageInfo) * N_CLASS(NImageFormat)::CreateInfo(N_CLASS(NImage) * pImage, NUInt flags) const
{
	if (!pImage) NThrowArgumentNullException(N_T("pImage"));
	HNImageInfo hInfo;
	NCheck(NImageFormatCreateInfo(GetHandle(), pImage->GetHandle(), flags, &hInfo));
	try
	{
		return FromHandle<N_CLASS(NImageInfo)>(hInfo);
	}
	catch (...)
	{
		Unref(hInfo);
		throw;
	}
}

inline N_CLASS(NImageWriter) * N_CLASS(NImageFormat)::OpenWriter(const N_CLASS(NStringWrapper) & fileName, NUInt flags) const
{
	HNImageWriter hWriter;
	NCheck(NImageFormatOpenWriterToFileN(GetHandle(), fileName.GetHandle(), flags, &hWriter));
	try
	{
		return FromHandle<N_CLASS(NImageWriter)>(hWriter);
	}
	catch (...)
	{
		Unref(hWriter);
		throw;
	}
}

inline N_CLASS(NImageWriter) * N_CLASS(NImageFormat)::OpenWriter(NUInt flags) const
{
	HNImageWriter hWriter;
	NCheck(NImageFormatOpenWriterToMemory(GetHandle(), flags, &hWriter));
	try
	{
		return FromHandle<N_CLASS(NImageWriter)>(hWriter);
	}
	catch (...)
	{
		Unref(hWriter);
		throw;
	}
}

#include <NNoDeprecate.h>
inline N_CLASS(NImageFile) * N_CLASS(NImageFormat)::OpenFile(const N_CLASS(NStringWrapper) & fileName) const
{
	HNImageFile handle;
	NCheck(NImageFormatOpenFileN(GetHandle(), fileName.GetHandle(), &handle));
	try
	{
		return FromHandle<N_CLASS(NImageFile)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline N_CLASS(NImageFile) * N_CLASS(NImageFormat)::OpenFile(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer) const
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	HNImageFile handle;
	NCheck(NImageFormatOpenFileFromMemoryN(GetHandle(), pBuffer->GetHandle(), &handle));
	try
	{
		return FromHandle<N_CLASS(NImageFile)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline N_CLASS(NImageFile) * N_CLASS(NImageFormat)::OpenFile(const void * pBuffer, NSizeType bufferSize) const
{
	HNImageFile handle;
	NCheck(NImageFormatOpenFileFromMemory(GetHandle(), pBuffer, bufferSize, &handle));
	try
	{
		return FromHandle<N_CLASS(NImageFile)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline N_CLASS(NImageFile) * N_CLASS(NImageFormat)::OpenFile(::Neurotec::IO::N_CLASS(NStream) * pStream) const
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	HNImageFile handle;
	NCheck(NImageFormatOpenFileFromStream(GetHandle(), pStream->GetHandle(), &handle));
	try
	{
		return FromHandle<N_CLASS(NImageFile)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline N_CLASS(NImage) * N_CLASS(NImageFormat)::LoadImage(const N_CLASS(NStringWrapper) & fileName) const
{
	HNImage handle;
	NCheck(NImageFormatLoadImageFromFileN(GetHandle(), fileName.GetHandle(), &handle));
	try
	{
		return FromHandle<N_CLASS(NImage)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline N_CLASS(NImage) * N_CLASS(NImageFormat)::LoadImage(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer) const
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	HNImage handle;
	NCheck(NImageFormatLoadImageFromMemoryN(GetHandle(), pBuffer->GetHandle(), &handle));
	try
	{
		return FromHandle<N_CLASS(NImage)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline N_CLASS(NImage) * N_CLASS(NImageFormat)::LoadImage(const void * pBuffer, NSizeType bufferSize) const
{
	HNImage handle;
	NCheck(NImageFormatLoadImageFromMemory(GetHandle(), pBuffer, bufferSize, &handle));
	try
	{
		return FromHandle<N_CLASS(NImage)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline N_CLASS(NImage) * N_CLASS(NImageFormat)::LoadImage(::Neurotec::IO::N_CLASS(NStream) * pStream) const
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	HNImage handle;
	NCheck(NImageFormatLoadImageFromStream(GetHandle(), pStream->GetHandle(), &handle));
	try
	{
		return FromHandle<N_CLASS(NImage)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline void N_CLASS(NImageFormat)::SaveImage(const N_CLASS(NImage) * pImage, const N_CLASS(NStringWrapper) & fileName) const
{
	if (!pImage) NThrowArgumentNullException(N_T("pImage"));
	NCheck(NImageFormatSaveImageToFileN(GetHandle(), pImage->GetHandle(), fileName.GetHandle()));
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline ::Neurotec::IO::N_CLASS(NBuffer) * N_CLASS(NImageFormat)::SaveImage(const N_CLASS(NImage) * pImage) const
{
	HNBuffer hBuffer;
	NCheck(NImageFormatSaveImageToMemoryN(GetHandle(), pImage->GetHandle(), &hBuffer));
	try
	{
		return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
	}
	catch (...)
	{
		Unref(hBuffer);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline void * N_CLASS(NImageFormat)::SaveImage(const N_CLASS(NImage) * pImage, NSizeType * pBufferSize) const
{
	void * pBuffer;
	NCheck(NImageFormatSaveImageToMemory(GetHandle(), pImage->GetHandle(), &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline void N_CLASS(NImageFormat)::SaveImage(const N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream) const
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NImageFormatSaveImageToStream(GetHandle(), pImage->GetHandle(), pStream->GetHandle()));
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline void N_CLASS(NImageFormat)::SaveImages(NInt imageCount, N_CLASS(NImage) * const * arpImages, const N_CLASS(NStringWrapper) & fileName) const
{
	N_CLASS(NObjectArray)<N_CLASS(NImage)> images(arpImages, imageCount);
	NCheck(NImageFormatSaveImagesToFileN(GetHandle(), images.GetCount(), images.GetPtr(), fileName.GetHandle()));
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline ::Neurotec::IO::N_CLASS(NBuffer) * N_CLASS(NImageFormat)::SaveImages(NInt imageCount, N_CLASS(NImage) * const * arpImages) const
{
	N_CLASS(NObjectArray)<N_CLASS(NImage)> images(arpImages, imageCount);
	HNBuffer hBuffer;
	NCheck(NImageFormatSaveImagesToMemoryN(GetHandle(), images.GetCount(), images.GetPtr(), &hBuffer));
	try
	{
		return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
	}
	catch (...)
	{
		Unref(hBuffer);
		throw;
	}
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline void * N_CLASS(NImageFormat)::SaveImages(NInt imageCount, N_CLASS(NImage) * const * arpImages, NSizeType * pBufferSize) const
{
	N_CLASS(NObjectArray)<N_CLASS(NImage)> images(arpImages, imageCount);
	void * pBuffer;
	NCheck(NImageFormatSaveImagesToMemory(GetHandle(), images.GetCount(), images.GetPtr(), &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

#include <NNoDeprecate.h>
inline void N_CLASS(NImageFormat)::SaveImages(NInt imageCount, N_CLASS(NImage) * const * arpImages, ::Neurotec::IO::N_CLASS(NStream) * pStream) const
{
	N_CLASS(NObjectArray)<N_CLASS(NImage)> images(arpImages, imageCount);
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NImageFormatSaveImagesToStream(GetHandle(), images.GetCount(), images.GetPtr(), pStream->GetHandle()));
}
#include <NReDeprecate.h>

}}

#endif // !N_IMAGE_FORMAT_HPP_INCLUDED
