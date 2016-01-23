#ifndef N_IMAGE_HPP_INCLUDED
#define N_IMAGE_HPP_INCLUDED

#include <NPixelFormat.hpp>
#include <NObject.hpp>
#include <NArray.hpp>
#include <NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::NFileAccess;
#include <NImage.h>
}}
#if defined(N_FRAMEWORK_MFC)
	#include <afxstr.h>
	#include <atlimage.h>
#elif defined(N_FRAMEWORK_WX)
	#include <wx/image.h>
#elif defined(N_FRAMEWORK_QT)
	#include <QImage>
#endif

#include <NImageDefWinTypes.h>

namespace Neurotec { namespace Images
{

#undef NI_READ_UNKNOWN_IMAGE
#undef NI_WRITE_UNKNOWN_IMAGE
#undef NI_DST_SWAP_CHANNELS
#undef NI_DST_ALPHA_CHANNEL_FIRST
#undef NI_DST_BOTTOM_TO_TOP
#undef NI_SRC_SWAP_CHANNELS
#undef NI_SRC_ALPHA_CHANNEL_FIRST
#undef NI_SRC_BOTTOM_TO_TOP

#undef NI_ALL_DST
#undef NI_ALL_SRC
#undef NI_ALL_DST_AND_SRC

const NUInt NI_READ_UNKNOWN_IMAGE      = 0x00000001;
const NUInt NI_WRITE_UNKNOWN_IMAGE     = 0x00000001;
const NUInt NI_DST_SWAP_CHANNELS       = 0x00000100;
const NUInt NI_DST_ALPHA_CHANNEL_FIRST = 0x00000200;
const NUInt NI_DST_BOTTOM_TO_TOP       = 0x00000400;
const NUInt NI_SRC_SWAP_CHANNELS       = 0x00001000;
const NUInt NI_SRC_ALPHA_CHANNEL_FIRST = 0x00002000;
const NUInt NI_SRC_BOTTOM_TO_TOP       = 0x00004000;

const NUInt NI_ALL_DST = 0x00000F00;
const NUInt NI_ALL_SRC = 0x0000F000;
const NUInt NI_ALL_DST_AND_SRC = (NI_ALL_DST | NI_ALL_SRC);

class N_CLASS(NImageFormat);
class N_CLASS(NImageInfo);
class N_CLASS(NMonochromeImage);
class N_CLASS(NGrayscaleImage);
class N_CLASS(NRgbImage);

#include <NNoDeprecate.h>
class N_CLASS(NImage) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NImage, NObject)

public:
	class PlaneCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)< ::Neurotec::IO::N_CLASS(NBuffer), N_CLASS(NImage)>
	{
		PlaneCollection(N_CLASS(NImage) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)< ::Neurotec::IO::N_CLASS(NBuffer), N_CLASS(NImage)>(pOwner)
		{
		}

	protected:
		virtual bool SupportsGetAll() const
		{
			return true;
		}

		virtual NResult GetCountNative(HNImage handle, NInt * pValue) const
		{
			return NImageGetPlaneCount(handle, pValue);
		}

		virtual NResult GetNative(HNImage handle, NInt index, HNBuffer * phValue) const
		{
			return NImageGetPlane(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNImage handle, HNBuffer * arhValues, NInt valuesLength) const
		{
			return NImageGetPlanes(handle, arhValues, valuesLength);
		}

		friend class N_CLASS(NImage);
	};

	class ImagePalette : public ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NArray), N_CLASS(NImage), false>
	{
		ImagePalette(N_CLASS(NImage) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)<N_CLASS(NArray), N_CLASS(NImage), false>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNImage handle, NInt * pValue) const
		{
			return NImageGetPaletteLength(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNImage, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNImage, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNImage handle, NInt index, HNArray * phValue) const
		{
			return NImageGetPaletteEntry(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNImage, HNArray *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNImage handle, NInt index, HNArray hValue)
		{
			return NImageSetPaletteEntry(handle, index, hValue);
		}

		virtual NResult AddNative(HNImage, HNArray)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNImage, HNArray, NInt *)
		{
			NThrowNotSupportedException();
		}

		virtual NResult InsertNative(HNImage, NInt, HNArray)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveWithOutIndexNative(HNImage, HNArray, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNImage, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveRangeNative(HNImage, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNImage)
		{
			NThrowNotSupportedException();
		}

	public:
		NSizeType GetEntriesSize()
		{
			NSizeType value;
			NCheck(NImageGetPaletteSize(pOwner->GetHandle(), &value));
			return value;
		}

		::Neurotec::IO::N_CLASS(NBuffer) * GetEntries()
		{
			HNBuffer hValue;
			NCheck(NImageGetPalette(pOwner->GetHandle(), &hValue));
			try
			{
				return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hValue, true, true);
			}
			catch (...)
			{
				Unref(hValue);
				throw;
			}
		}

		const void * GetEntriesPtr() const
		{
			void * pValue;
			NCheck(NImageGetPalettePtr(pOwner->GetHandle(), &pValue));
			return pValue;
		}

		void * GetEntriesPtr()
		{
			void * pValue;
			NCheck(NImageGetPalettePtr(pOwner->GetHandle(), &pValue));
			return pValue;
		}

		void SetEnrties(::Neurotec::IO::N_CLASS(NBuffer) * pPalette, NInt paletteLength)
		{
			NCheck(NImageSetPaletteN(pOwner->GetHandle(), ToHandle(pPalette), paletteLength));
		}

		void SetEnrties(const void * pPalette, NSizeType paletteSize, NInt paletteLength)
		{
			NCheck(NImageSetPalette(pOwner->GetHandle(), pPalette, paletteSize, paletteLength));
		}

		friend class N_CLASS(NImage);
	};

private:
	::std::auto_ptr<PlaneCollection> planes;
	::std::auto_ptr<ImagePalette> palette;

protected:
	N_CLASS(NImage)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		planes.reset(new PlaneCollection(this));
		palette.reset(new ImagePalette(this));
	}

public:
	static N_CLASS(NType) * NImageRotateFlipTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NImageRotateFlipType), true, true);
	}

	N_DEPRECATED("method is deprecated, use GetWrapper(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NUInt, NUInt, NSizeType, " N_STRINGIZEA(N_CLASS(NBuffer)) " *, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, ::Neurotec::IO::N_CLASS(NBuffer) * pPixels)
	{
		if (!pPixels) NThrowArgumentNullException(N_T("pPixels"));
		HNImage handle;
		NCheck(NImageCreateWrapperN(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution, pPixels->GetHandle(), &handle));
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

	N_DEPRECATED("method is deprecated, use GetWrapper(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NUInt, NUInt, NSizeType, void *, bool, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, void * pPixels, bool ownsPixels)
	{
		HNImage handle;
		NCheck(NImageCreateWrapper(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution, pPixels, ownsPixels ? NTrue : NFalse, &handle));
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

	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		::Neurotec::IO::N_CLASS(NBuffer) * pPixels, NUInt flags = 0)
	{
		if (!pPixels) NThrowArgumentNullException(N_T("pPixels"));
		HNImage handle;
		NCheck(NImageCreateWrapperExN(pixelFormat.GetValue(), width, height, stride, pPixels->GetHandle(), flags, &handle));
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

	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		void * pPixels, NSizeType pixelsSize, bool ownsPixels, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperEx(pixelFormat.GetValue(), width, height, stride, pPixels, pixelsSize, ownsPixels ? NTrue : NFalse, flags, &handle));
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

	N_DEPRECATED("method is deprecated, use GetWrapper(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NUInt, NUInt, NSizeType, " N_STRINGIZEA(N_CLASS(NBuffer)) " *, NUInt, NUInt, NUInt, NUInt, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, ::Neurotec::IO::N_CLASS(NBuffer) * pPixels, NUInt left, NUInt top)
	{
		if (!pPixels) NThrowArgumentNullException(N_T("pPixels"));
		HNImage handle;
		NCheck(NImageCreateWrapperForPartN(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution, pPixels->GetHandle(), left, top, &handle));
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

	N_DEPRECATED("method is deprecated, use GetWrapper(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NUInt, NUInt, NSizeType, void *, NUInt, NUInt, NUInt, NUInt, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, void * pPixels, NUInt left, NUInt top)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForPart(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution, pPixels, left, top, &handle));
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

	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		::Neurotec::IO::N_CLASS(NBuffer) * pPixels, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		if (!pPixels) NThrowArgumentNullException(N_T("pPixels"));
		HNImage handle;
		NCheck(NImageCreateWrapperForPartExN(pixelFormat.GetValue(), srcWidth, srcHeight, stride, pPixels->GetHandle(), left, top, width, height, flags, &handle));
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

	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		void * pPixels, NSizeType pixelsSize, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForPartEx(pixelFormat.GetValue(), srcWidth, srcHeight, stride, pPixels, pixelsSize, left, top, width, height, flags, &handle));
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

	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		::Neurotec::IO::N_CLASS(NBuffer) * const * arpPlanes, NInt planeCount, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> planes(arpPlanes, planeCount);
		HNImage handle;
		NCheck(NImageCreateWrapperForPlanesPartN(pixelFormat.GetValue(), srcWidth, srcHeight, stride, planes.GetPtr(), planes.GetCount(), left, top, width, height, flags, &handle));
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

	static N_CLASS(NImage) * GetWrapper(const N_CLASS(NPixelFormat) & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		void * const * arpPlanes, const NSizeType * arPlaneSizes, NInt planeCount, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForPlanesPart(pixelFormat.GetValue(), srcWidth, srcHeight, stride, arpPlanes, arPlaneSizes, planeCount, left, top, width, height, flags, &handle));
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

	N_DEPRECATED("method is deprecated, use GetWrapper(" N_STRINGIZEA(N_CLASS(NImage)) " *, NUInt, NUInt, NUInt, NUInt, NUInt), SetHorzResolution, SetVertResolution and SetResolutionIsAspectRatio instead")
	static N_CLASS(NImage) * GetWrapper(N_CLASS(NImage) * pSrcImage, NUInt left, NUInt top, NUInt width, NUInt height,
		NFloat horzResolution, NFloat vertResolution)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNImage handle;
		NCheck(NImageCreateWrapperForImagePartEx(pSrcImage->GetHandle(), left, top, width, height,
			horzResolution, vertResolution, &handle));
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

	static N_CLASS(NImage) * GetWrapper(N_CLASS(NImage) * pSrcImage, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNImage handle;
		NCheck(NImageCreateWrapperForImagePartEx2(pSrcImage->GetHandle(), left, top, width, height, flags, &handle));
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

	N_DEPRECATED("method is deprecated, use Create(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NUInt, NUInt, NSizeType, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * Create(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution)
	{
		HNImage handle;
		NCheck(NImageCreate(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution, &handle));
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

	static N_CLASS(NImage) * Create(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateEx(pixelFormat.GetValue(), width, height, stride, flags, &handle));
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

	N_DEPRECATED("method is deprecated, use FromData(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NUInt, NUInt, NSizeType, NSizeType, " N_STRINGIZEA(N_CLASS(NBuffer)) " *, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, NSizeType srcStride, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcPixels)
	{
		if (!pSrcPixels) NThrowArgumentNullException(N_T("pSrcPixels"));
		HNImage handle;
		NCheck(NImageCreateFromDataN(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution, srcStride, pSrcPixels->GetHandle(), &handle));
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

	N_DEPRECATED("method is deprecated, use FromData(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NUInt, NUInt, NSizeType, NSizeType, const void *, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, NSizeType srcStride, const void * pSrcPixels)
	{
		HNImage handle;
		NCheck(NImageCreateFromData(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution, srcStride, pSrcPixels, &handle));
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

	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NSizeType srcStride, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcPixels, NUInt flags = 0)
	{
		if (!pSrcPixels) NThrowArgumentNullException(N_T("pSrcPixels"));
		HNImage handle;
		NCheck(NImageCreateFromDataExN(pixelFormat.GetValue(), width, height, stride, srcStride, pSrcPixels->GetHandle(), flags, &handle));
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

	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NSizeType srcStride, const void * pSrcPixels, NSizeType srcPixelsSize, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataEx(pixelFormat.GetValue(), width, height, stride, srcStride, pSrcPixels, srcPixelsSize, flags, &handle));
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

	N_DEPRECATED("method is deprecated, use FromData(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NSizeType, NUInt, NUInt, NSizeType, " N_STRINGIZEA(N_CLASS(NBuffer)) " *, NUInt, NUInt, NUInt, NUInt, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, NSizeType srcStride, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcPixels, NUInt left, NUInt top)
	{
		if (!pSrcPixels) NThrowArgumentNullException(N_T("pSrcPixels"));
		HNImage handle;
		NCheck(NImageCreateFromDataPartN(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution,
			srcStride, pSrcPixels->GetHandle(), left, top, &handle));
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

	N_DEPRECATED("method is deprecated, use FromData(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NSizeType, NUInt, NUInt, NSizeType, const void *, NUInt, NUInt, NUInt, NUInt, NUInt), SetHorzResolution and SetVertResolution instead")
	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NFloat horzResolution, NFloat vertResolution, NSizeType srcStride, const void * pSrcPixels, NUInt left, NUInt top)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataPart(pixelFormat.GetValue(), width, height, stride, horzResolution, vertResolution,
			srcStride, pSrcPixels, left, top, &handle));
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

	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		::Neurotec::IO::N_CLASS(NBuffer) * pSrcPixels, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		if (!pSrcPixels) NThrowArgumentNullException(N_T("pSrcPixels"));
		HNImage handle;
		NCheck(NImageCreateFromDataPartExN(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, pSrcPixels->GetHandle(), srcLeft, srcTop, width, height, flags, &handle));
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

	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * pSrcPixels, NSizeType srcPixelsSize, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataPartEx(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, pSrcPixels, srcPixelsSize, srcLeft, srcTop, width, height, flags, &handle));
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

	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		::Neurotec::IO::N_CLASS(NBuffer) * const * arpSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> srcPlanes(arpSrcPlanes, srcPlaneCount);
		HNImage handle;
		NCheck(NImageCreateFromDataPlanesPartN(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop, width, height, flags, &handle));
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

	static N_CLASS(NImage) * FromData(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataPlanesPart(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop, width, height, flags, &handle));
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

	N_DEPRECATED("method is deprecated, use FromImage(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NSizeType, " N_STRINGIZEA(N_CLASS(NImage)) " *, NUInt), ToGrayscale, ToMonochrome or ToRgb and SetHorzResolution, SetVertResolution and SetResolutionIsAspectRatio instead")
	static N_CLASS(NImage) * FromImage(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, NFloat horzResolution, NFloat vertResolution, N_CLASS(NImage) * pSrcImage)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNImage handle;
		NCheck(NImageCreateFromImageEx(pixelFormat.GetValue(), stride, horzResolution, vertResolution,
			pSrcImage->GetHandle(), &handle));
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

	static N_CLASS(NImage) * FromImage(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, N_CLASS(NImage) * pSrcImage, NUInt flags = 0)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNImage handle;
		NCheck(NImageCreateFromImageEx2(pixelFormat.GetValue(), stride, pSrcImage->GetHandle(), flags, &handle));
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

	N_DEPRECATED("method is deprecated, use FromImage(const " N_STRINGIZEA(N_CLASS(NPixelFormat)) " &, NSizeType, " N_STRINGIZEA(N_CLASS(NImage)) " *, NUInt, NUInt, NUInt, NUInt, NUInt), SetHorzResolution, SetVertResolution and SetResolutionIsAspectRatio instead")
	static N_CLASS(NImage) * FromImage(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
		N_CLASS(NImage) * pSrcImage, NUInt left, NUInt top, NUInt width, NUInt height)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNImage handle;
		NCheck(NImageCreateFromImagePartEx(pixelFormat.GetValue(),
			stride, horzResolution, vertResolution, pSrcImage->GetHandle(),
			left, top, width, height, &handle));
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

	static N_CLASS(NImage) * FromImage(const N_CLASS(NPixelFormat) & pixelFormat, NSizeType stride, N_CLASS(NImage) * pSrcImage,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNImage handle;
		NCheck(NImageCreateFromImagePartEx2(pixelFormat.GetValue(), stride, pSrcImage->GetHandle(),
			left, top, width, height, flags, &handle));
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

	static N_CLASS(NImage) * FromFile(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NImageFormat) * pImageFormat = NULL, NUInt flags = 0, N_CLASS(NImageInfo) * * ppInfo = NULL);
	static N_CLASS(NImage) * FromMemory(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, N_CLASS(NImageFormat) * pImageFormat = NULL, NUInt flags = 0, NSizeType * pSize = NULL, N_CLASS(NImageInfo) * * ppInfo = NULL);
	static N_CLASS(NImage) * FromMemory(const void * pBuffer, NSizeType bufferSize, N_CLASS(NImageFormat) * pImageFormat = NULL, NUInt flags = 0, NSizeType * pSize = NULL, N_CLASS(NImageInfo) * * ppInfo = NULL);
	static N_CLASS(NImage) * FromStream(::Neurotec::IO::N_CLASS(NStream) * pStream, N_CLASS(NImageFormat) * pImageFormat = NULL, NUInt flags = 0, N_CLASS(NImageInfo) * * ppInfo = NULL);

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
	static N_CLASS(NImage) * FromHBitmap(HBITMAP hBitmap, NUInt flags = 0)
	{
		HNImage hImage;
		NCheck(NImageCreateFromHBitmap(hBitmap, flags, &hImage));
		try
		{
			return FromHandle<N_CLASS(NImage)>(hImage);
		}
		catch (...)
		{
			Unref(hImage);
			throw;
		}
	}

	static N_CLASS(NImage) * FromBitmapInfoAndBits(BITMAPINFO * pBitmapInfo, NSizeType bitmapInfoSize, const void * pBits, NSizeType bitsSize, NUInt flags = 0)
	{
		HNImage hImage;
		NCheck(NImageCreateFromBitmapInfoAndBits(pBitmapInfo, bitmapInfoSize, pBits, bitsSize, flags, &hImage));
		try
		{
			return FromHandle<N_CLASS(NImage)>(hImage);
		}
		catch (...)
		{
			Unref(hImage);
			throw;
		}
	}
#endif

#if defined(N_FRAMEWORK_MFC)
	static N_CLASS(NImage) * FromBitmap(CImage * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		return FromHBitmap((HBITMAP)*pImage);
	}
#elif defined(N_FRAMEWORK_WX)
	static N_CLASS(NImage) * FromBitmap(const wxImage & image)
	{
		return FromData(npfRgb, image.GetWidth(), image.GetHeight(), 0,
			image.GetWidth() * 3, image.GetData(), image.GetHeight() * image.GetWidth() * 3);
	}
#elif defined(N_FRAMEWORK_QT)
	static N_CLASS(NImage) * FromBitmap(const QImage & image)
	{
		QImage rgbImage = image;
		if (image.format() != QImage::Format_RGB32)
		{
			rgbImage = image.convertToFormat(QImage::Format_RGB32);
		}
		NUInt width = rgbImage.width();
		NUInt height = rgbImage.height();
		
		const uchar * srcBits = rgbImage.bits();
		uchar * dstBits = NULL;
		dstBits = (uchar*) NAlloc(width*height*3);
		for (uint y=0; y<height; y++)
		{
			int dstOffset_y = y*width*3;
			int srcOffset_y = y*4*width;
			for (uint x=0; x<width; x++)
			{
				int dstOffset = dstOffset_y + x*3;
				int srcOffset = srcOffset_y + x*4;
				
				dstBits[dstOffset] = srcBits[srcOffset+2];
				dstBits[dstOffset+1] = srcBits[srcOffset+1];
				dstBits[dstOffset+2] = srcBits[srcOffset];
			}
		}
		N_CLASS(NImage) * nimage = FromData(npfRgb, width, height, 0,
			width * 3, dstBits, height * width * 3);
		NFree(dstBits);
		return nimage;
	}
#endif

	static void Copy(const N_CLASS(NPixelFormat) & srcPixelFormat, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcPalette, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, ::Neurotec::IO::N_CLASS(NBuffer) * const * arpSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		const N_CLASS(NPixelFormat) & dstPixelFormat, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, ::Neurotec::IO::N_CLASS(NBuffer) * pDstPalette, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, ::Neurotec::IO::N_CLASS(NBuffer) * const * arpDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> srcPlanes(arpSrcPlanes, srcPlaneCount);
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> dstPlanes(arpDstPlanes, dstPlaneCount);
		NCheck(NImageCopyDataPlanesExN(srcPixelFormat.GetValue(), ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), ToHandle(pSrcPalette), srcPaletteLength, srcWidth, srcHeight, srcStride, srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			dstPixelFormat.GetValue(), ToHandle(pDstMinValue), ToHandle(pDstMaxValue), ToHandle(pDstPalette), dstPaletteLength, dstWidth, dstHeight, dstStride, dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const N_CLASS(NPixelFormat) & srcPixelFormat, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, const void * pSrcPalette, NSizeType srcPaletteSize, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		const N_CLASS(NPixelFormat) & dstPixelFormat, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, const void * pDstPalette, NSizeType dstPaletteSize, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyDataPlanesEx(srcPixelFormat.GetValue(), ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), pSrcPalette, srcPaletteSize, srcPaletteLength, srcWidth, srcHeight, srcStride, arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			dstPixelFormat.GetValue(), ToHandle(pDstMinValue), ToHandle(pDstMaxValue), pDstPalette, dstPaletteSize, dstPaletteLength, dstWidth, dstHeight, dstStride, arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, ::Neurotec::IO::N_CLASS(NBuffer) * const * arpSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, ::Neurotec::IO::N_CLASS(NBuffer) * const * arpDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> srcPlanes(arpSrcPlanes, srcPlaneCount);
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> dstPlanes(arpDstPlanes, dstPlaneCount);
		NCheck(NImageCopyDataPlanesN(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyDataPlanes(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcPixels, NUInt srcLeft, NUInt srcTop,
		const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, ::Neurotec::IO::N_CLASS(NBuffer) * pDstPixels, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		if (!pSrcPixels) NThrowArgumentNullException(N_T("pSrcPixels"));
		if (!pDstPixels) NThrowArgumentNullException(N_T("pDstPixels"));
		NCheck(NImageCopyDataN(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, pSrcPixels->GetHandle(), srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, pDstPixels->GetHandle(), dstLeft, dstTop,
			width, height, flags));
	}

	static void Copy(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * pSrcPixels, NSizeType srcPixelsSize, NUInt srcLeft, NUInt srcTop,
		const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * pDstPixels, NSizeType dstPixelsSizes, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyData(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, pSrcPixels, srcPixelsSize, srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, pDstPixels, dstPixelsSizes, dstLeft, dstTop,
			width, height, flags));
	}

	static void Copy(N_CLASS(NImage) * pSrcImage, NUInt left, NUInt top, NUInt width, NUInt height, N_CLASS(NImage) * pDstImage, NUInt dstLeft, NUInt dstTop)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NImageCopy(pSrcImage->GetHandle(), left, top, width, height, pDstImage->GetHandle(), dstLeft, dstTop));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		::Neurotec::IO::N_CLASS(NBuffer) * pSrcPixels, NUInt left, NUInt top, NUInt flags = 0)
	{
		if (!pSrcPixels) NThrowArgumentNullException(N_T("pSrcPixels"));
		NCheck(NImageCopyFromDataN(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, pSrcPixels->GetHandle(), left, top, flags));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * pSrcPixels, NSizeType srcPixelsSizes, NUInt left, NUInt top, NUInt flags = 0)
	{
		NCheck(NImageCopyFromData(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, pSrcPixels, srcPixelsSizes, left, top, flags));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		::Neurotec::IO::N_CLASS(NBuffer) * pSrcPixels, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		if (!pSrcPixels) NThrowArgumentNullException(N_T("pSrcPixels"));
		NCheck(NImageCopyFromDataPartN(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			pSrcPixels->GetHandle(), srcLeft, srcTop, left, top, width, height, flags));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * pSrcPixels, NSizeType srcPixelsSizes, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPart(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			pSrcPixels, srcPixelsSizes, srcLeft, srcTop, left, top, width, height, flags));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		::Neurotec::IO::N_CLASS(NBuffer) * const * arpSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> srcPlanes(arpSrcPlanes, srcPlaneCount);
		NCheck(NImageCopyFromDataPlanesPartN(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPlanesPart(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcPalette, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, ::Neurotec::IO::N_CLASS(NBuffer) * const * arpSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> srcPlanes(arpSrcPlanes, srcPlaneCount);
		NCheck(NImageCopyFromDataPlanesPartExN(GetHandle(), srcPixelFormat.GetValue(), ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), ToHandle(pSrcPalette), srcPaletteLength, srcWidth, srcHeight, srcStride,
			srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyFrom(const N_CLASS(NPixelFormat) & srcPixelFormat, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, const void * pSrcPalette, NSizeType srcPaletteSize, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPlanesPartEx(GetHandle(), srcPixelFormat.GetValue(), ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), pSrcPalette, srcPaletteSize, srcPaletteLength, srcWidth, srcHeight, srcStride,
			arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyTo(const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight,
		NSizeType dstStride, ::Neurotec::IO::N_CLASS(NBuffer) * pDstPixels, NUInt dstLeft, NUInt dstTop, NUInt flags = 0) const
	{
		if (!pDstPixels) NThrowArgumentNullException(N_T("pDstPixels"));
		NCheck(NImageCopyToDataN((HNImage)GetHandle(), dstPixelFormat.GetValue(), dstWidth, dstHeight,
			dstStride, pDstPixels->GetHandle(), dstLeft, dstTop, flags));
	}

	void CopyTo(const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight,
		NSizeType dstStride, void * pDstPixels, NSizeType dstPixelsSize, NUInt dstLeft, NUInt dstTop, NUInt flags = 0) const
	{
		NCheck(NImageCopyToData((HNImage)GetHandle(), dstPixelFormat.GetValue(), dstWidth, dstHeight,
			dstStride, pDstPixels, dstPixelsSize, dstLeft, dstTop, flags));
	}

	void CopyTo(NUInt left, NUInt top, const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		::Neurotec::IO::N_CLASS(NBuffer) * pDstPixels, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		if (!pDstPixels) NThrowArgumentNullException(N_T("pDstPixels"));
		NCheck(NImageCopyToDataPartN(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			pDstPixels->GetHandle(), dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		void * pDstPixels, NSizeType dstPixelsSize, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPart(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			pDstPixels, dstPixelsSize, dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		::Neurotec::IO::N_CLASS(NBuffer) * const * arpDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> dstPlanes(arpDstPlanes, dstPlaneCount);
		NCheck(NImageCopyToDataPlanesPartN(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const N_CLASS(NPixelFormat) & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPlanesPart(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const N_CLASS(NPixelFormat) & dstPixelFormat, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, ::Neurotec::IO::N_CLASS(NBuffer) * pDstPalette, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, ::Neurotec::IO::N_CLASS(NBuffer) * const * arpDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		N_CLASS(NObjectArray)< ::Neurotec::IO::N_CLASS(NBuffer)> dstPlanes(arpDstPlanes, dstPlaneCount);
		NCheck(NImageCopyToDataPlanesPartExN(GetHandle(), left, top, dstPixelFormat.GetValue(), ToHandle(pDstMinValue), ToHandle(pDstMaxValue), ToHandle(pDstPalette), dstPaletteLength,
			dstWidth, dstHeight, dstStride, dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const N_CLASS(NPixelFormat) & dstPixelFormat, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, const void * pDstPalette, NSizeType dstPaletteSize, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPlanesPartEx(GetHandle(), left, top, dstPixelFormat.GetValue(), ToHandle(pDstMinValue), ToHandle(pDstMaxValue), pDstPalette, dstPaletteSize, dstPaletteLength,
			dstWidth, dstHeight, dstStride, arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(N_CLASS(NImage) * pDstImage, NUInt dstLeft, NUInt dstTop) const
	{
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NImageCopyTo(GetHandle(), pDstImage->GetHandle(), dstLeft, dstTop));
	}

	::Neurotec::IO::N_CLASS(NBuffer) * ExportPalette(const N_CLASS(NPixelFormat) & dstPixelFormat, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, NInt * pPaletteLength, NUInt flags = 0) const
	{
		HNBuffer hPalette;
		NCheck(NImageExportPalette(GetHandle(), dstPixelFormat.GetValue(), ToHandle(pDstMinValue), ToHandle(pDstMaxValue), flags, pPaletteLength, &hPalette));
		try
		{
			return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hPalette);
		}
		catch (...)
		{
			Unref(hPalette);
			throw;
		}
	}

	void Save(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NImageFormat) * pImageFormat = NULL, N_CLASS(NImageInfo) * pInfo = NULL, NUInt flags = 0) const;
	::Neurotec::IO::N_CLASS(NBuffer) * Save(N_CLASS(NImageFormat) * pImageFormat, N_CLASS(NImageInfo) * pInfo = NULL, NUInt flags = 0) const;
	N_DEPRECATED("method is deprecated, use Save(" N_STRINGIZEA(N_CLASS(NImageInfo)) " *, NUInt) instead")
	void * Save(NSizeType * pBufferSize, N_CLASS(NImageFormat) * pImageFormat, N_CLASS(NImageInfo) * pInfo = NULL, NUInt flags = 0) const;
	void Save(::Neurotec::IO::N_CLASS(NStream) * pSteam, N_CLASS(NImageFormat) * pImageFormat, N_CLASS(NImageInfo) * pInfo = NULL, NUInt flags = 0) const;

	void FlipHorizontally()
	{
		NCheck(NImageFlipHorizontally((HNImage)GetHandle()));
	}

	void FlipVertically()
	{
		NCheck(NImageFlipVertically((HNImage)GetHandle()));
	}

	void FlipDiagonally()
	{
		NCheck(NImageFlipDiagonally((HNImage)GetHandle()));
	}

	N_CLASS(NImage) * RotateFlip(NImageRotateFlipType rotateFlipType) const
	{
		HNImage handle;
		NCheck(NImageRotateFlip(GetHandle(), rotateFlipType, &handle));
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

	N_CLASS(NImage) * Crop(NUInt left, NUInt top, NUInt width, NUInt height) const
	{
		HNImage handle;
		NCheck(NImageCrop(GetHandle(), left, top, width, height, &handle));
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

	N_CLASS(NMonochromeImage) * ToMonochrome() const;
	N_CLASS(NGrayscaleImage) * ToGrayscale() const;
	N_CLASS(NRgbImage) * ToRgb() const;

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
	HBITMAP ToHBitmap() const
	{
		HBITMAP hBitmap;
		NCheck(NImageToHBitmap(GetHandle(), &hBitmap));
		return hBitmap;
	}
#endif
#if defined(N_FRAMEWORK_MFC)
	CImage * ToBitmap() const
	{
		::std::auto_ptr<CImage> image(new CImage());
		image->Attach(ToHBitmap());
		return image.release();
	}
#elif defined(N_FRAMEWORK_WX)
	wxImage ToBitmap() const
	{
		NUInt width = GetWidth();
		NUInt height = GetHeight();
		wxImage image(width, height, false);
		CopyTo(npfRgb, width, height, width * 3, image.GetData(), height * width * 3, 0, 0);
		return image;
	}
#elif defined(N_FRAMEWORK_QT)
	QImage ToBitmap() const;
#endif

	N_CLASS(NPixelFormat) GetPixelFormat() const
	{
		NPixelFormat_ value;
		NCheck(NImageGetPixelFormat(GetHandle(), &value));
		return N_CLASS(NPixelFormat)(value);
	}

	N_CLASS(NArray) * GetMinValue() const
	{
		HNArray hValue;
		NCheck(NImageGetMinValue(GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void SetMinValue(N_CLASS(NArray) * pValue)
	{
		NCheck(NImageSetMinValue(GetHandle(), ToHandle(pValue)));
	}

	N_CLASS(NArray) * GetMaxValue() const
	{
		HNArray hValue;
		NCheck(NImageGetMaxValue(GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void SetMaxValue(N_CLASS(NArray) * pValue)
	{
		NCheck(NImageSetMaxValue(GetHandle(), ToHandle(pValue)));
	}

	NUInt GetWidth() const
	{
		NUInt value;
		NCheck(NImageGetWidth(GetHandle(), &value));
		return value;
	}

	NUInt GetHeight() const
	{
		NUInt value;
		NCheck(NImageGetHeight(GetHandle(), &value));
		return value;
	}

	NSizeType GetStride() const
	{
		NSizeType value;
		NCheck(NImageGetStride(GetHandle(), &value));
		return value;
	}

	NSizeType GetPlaneSize() const
	{
		NSizeType value;
		NCheck(NImageGetPlaneSize(GetHandle(), &value));
		return value;
	}

	NSizeType GetImageSize() const
	{
		NSizeType value;
		NCheck(NImageGetImageSize(GetHandle(), &value));
		return value;
	}

	NFloat GetHorzResolution() const
	{
		NFloat value;
		NCheck(NImageGetHorzResolution(GetHandle(), &value));
		return value;
	}

	void SetHorzResolution(NFloat value)
	{
		NCheck(NImageSetHorzResolution(GetHandle(), value));
	}

	NFloat GetVertResolution() const
	{
		NFloat value;
		NCheck(NImageGetVertResolution(GetHandle(), &value));
		return value;
	}

	void SetVertResolution(NFloat value)
	{
		NCheck(NImageSetVertResolution(GetHandle(), value));
	}

	bool GetResolutionIsAspectRatio() const
	{
		NBool value;
		NCheck(NImageGetResolutionIsAspectRatio(GetHandle(), &value));
		return value != 0;
	}

	void SetResolutionIsAspectRatio(bool value)
	{
		NCheck(NImageSetResolutionIsAspectRatio(GetHandle(), value ? NTrue : NFalse));
	}

	N_CLASS(NArray) * GetPixel(NUInt x, NUInt y) const
	{
		HNArray hValue;
		NCheck(NImageGetPixel(GetHandle(), x, y, &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void SetPixel(NUInt x, NUInt y, N_CLASS(NArray) * pValue)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NCheck(NImageSetPixel(GetHandle(), x, y, pValue->GetHandle()));
	}

	NInt GetIndex(NUInt x, NUInt y) const
	{
		NInt value;
		NCheck(NImageGetIndex(GetHandle(), x, y, &value));
		return value != 0;
	}

	void SetIndex(NUInt x, NUInt y, NInt value)
	{
		NCheck(NImageSetIndex(GetHandle(), x, y, value ? NTrue : NFalse));
	}

	::Neurotec::IO::N_CLASS(NBuffer) * GetPixels()
	{
		HNBuffer hValue;
		NCheck(NImageGetPixelsN(GetHandle(), &hValue));
		try
		{
			return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	const void * GetPixelsPtr() const
	{
		void * pValue;
		NCheck(NImageGetPixelsPtr(GetHandle(), &pValue));
		return pValue;
	}

	void * GetPixelsPtr()
	{
		void * pValue;
		NCheck(NImageGetPixelsPtr(GetHandle(), &pValue));
		return pValue;
	}

	PlaneCollection * GetPlanes()
	{
		return planes.get();
	}

	ImagePalette * GetPalette()
	{
		return palette.get();
	}

	N_CLASS(NImageInfo) * GetInfo();
};
#include <NReDeprecate.h>

}}

#include <NImageUndefWinTypes.h>

#include <NImageFormat.hpp>
#include <NImageInfo.hpp>
#include <NMonochromeImage.hpp>
#include <NGrayscaleImage.hpp>
#include <NRgbImage.hpp>

namespace Neurotec { namespace Images
{

inline N_CLASS(NImage) * N_CLASS(NImage)::FromFile(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NImageFormat) * pImageFormat, NUInt flags, N_CLASS(NImageInfo) * * ppInfo)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromFileExN(fileName.GetHandle(), ToHandle(pImageFormat), flags, ppInfo ? &hInfo : NULL, &hImage));
	N_CLASS(NImage) * pImage = NULL;
	N_CLASS(NImageInfo) * pInfo = NULL;
	try
	{
		pInfo = FromHandle<N_CLASS(NImageInfo)>(hInfo);
		pImage = FromHandle<N_CLASS(NImage)>(hImage);
		if (ppInfo) *ppInfo = pInfo;
		return pImage;
	}
	catch (...)
	{
		UnrefOrDelete(hInfo, pInfo);
		UnrefOrDelete(hImage, pImage);
		throw;
	}
}

inline N_CLASS(NImage) * N_CLASS(NImage)::FromMemory(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, N_CLASS(NImageFormat) * pImageFormat, NUInt flags, NSizeType * pSize, N_CLASS(NImageInfo) * * ppInfo)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromMemoryN(pBuffer->GetHandle(), ToHandle(pImageFormat), flags, pSize, ppInfo ? &hInfo : NULL, &hImage));
	N_CLASS(NImage) * pImage = NULL;
	N_CLASS(NImageInfo) * pInfo = NULL;
	try
	{
		pInfo = FromHandle<N_CLASS(NImageInfo)>(hInfo);
		pImage = FromHandle<N_CLASS(NImage)>(hImage);
		if (ppInfo) *ppInfo = pInfo;
		return pImage;
	}
	catch (...)
	{
		UnrefOrDelete(hInfo, pInfo);
		UnrefOrDelete(hImage, pImage);
		throw;
	}
}

inline N_CLASS(NImage) * N_CLASS(NImage)::FromMemory(const void * pBuffer, NSizeType bufferSize, N_CLASS(NImageFormat) * pImageFormat, NUInt flags, NSizeType * pSize, N_CLASS(NImageInfo) * * ppInfo)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromMemory(pBuffer, bufferSize, ToHandle(pImageFormat), flags, pSize, ppInfo ? &hInfo : NULL, &hImage));
	N_CLASS(NImage) * pImage = NULL;
	N_CLASS(NImageInfo) * pInfo = NULL;
	try
	{
		pInfo = FromHandle<N_CLASS(NImageInfo)>(hInfo);
		pImage = FromHandle<N_CLASS(NImage)>(hImage);
		if (ppInfo) *ppInfo = pInfo;
		return pImage;
	}
	catch (...)
	{
		UnrefOrDelete(hInfo, pInfo);
		UnrefOrDelete(hImage, pImage);
		throw;
	}
}

inline N_CLASS(NImage) * N_CLASS(NImage)::FromStream(::Neurotec::IO::N_CLASS(NStream) * pStream, N_CLASS(NImageFormat) * pImageFormat, NUInt flags, N_CLASS(NImageInfo) * * ppInfo)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromStream(pStream->GetHandle(), ToHandle(pImageFormat), flags, ppInfo ? &hInfo : NULL, &hImage));
	N_CLASS(NImage) * pImage = NULL;
	N_CLASS(NImageInfo) * pInfo = NULL;
	try
	{
		pInfo = FromHandle<N_CLASS(NImageInfo)>(hInfo);
		pImage = FromHandle<N_CLASS(NImage)>(hImage);
		if (ppInfo) *ppInfo = pInfo;
		return pImage;
	}
	catch (...)
	{
		UnrefOrDelete(hInfo, pInfo);
		UnrefOrDelete(hImage, pImage);
		throw;
	}
}

inline N_CLASS(NMonochromeImage) * N_CLASS(NImage)::ToMonochrome() const
{
	HNMonochromeImage hResultImage;
	NCheck(NImageToMonochrome(GetHandle(), &hResultImage));
	try
	{
		return FromHandle<N_CLASS(NMonochromeImage)>(hResultImage);
	}
	catch (...)
	{
		Unref(hResultImage);
		throw;
	}
}

inline N_CLASS(NGrayscaleImage) * N_CLASS(NImage)::ToGrayscale() const
{
	HNGrayscaleImage hResultImage;
	NCheck(NImageToGrayscale(GetHandle(), &hResultImage));
	try
	{
		return FromHandle<N_CLASS(NGrayscaleImage)>(hResultImage);
	}
	catch (...)
	{
		Unref(hResultImage);
		throw;
	}
}

inline N_CLASS(NRgbImage) * N_CLASS(NImage)::ToRgb() const
{
	HNRgbImage hResultImage;
	NCheck(NImageToRgb(GetHandle(), &hResultImage));
	try
	{
		return FromHandle<N_CLASS(NRgbImage)>(hResultImage);
	}
	catch (...)
	{
		Unref(hResultImage);
		throw;
	}
}

#if defined(N_FRAMEWORK_QT)
inline QImage N_CLASS(NImage)::ToBitmap() const
{
	::std::auto_ptr<N_CLASS(NRgbImage)> rgbImage(ToRgb());
	NUInt width = GetWidth();
	NUInt height = GetHeight();
	QImage image(width, height, QImage::Format_RGB32);
	uchar * dstBits = image.bits();
	uchar * srcBits = (uchar *)rgbImage->GetPixelsPtr();
	NSizeType stride = rgbImage->GetStride();
	for (uint y = 0; y < height; y++)
	{
		int dstOffset_y = y * 4 * width;
		int srcOffset_y = y * stride;
		for (uint x = 0; x < width; x++)
		{
			int dstOffset = dstOffset_y + x * 4;
			int srcOffset = srcOffset_y + x * 3;
			dstBits[dstOffset    ] = srcBits[srcOffset + 2];
			dstBits[dstOffset + 1] = srcBits[srcOffset + 1];
			dstBits[dstOffset + 2] = srcBits[srcOffset    ];
			dstBits[dstOffset + 3] = 0xFF;
		}
	}
    image.setDotsPerMeterX(rgbImage->GetHorzResolution() * 100 / 2.54);
    image.setDotsPerMeterY(rgbImage->GetVertResolution() * 100 / 2.54);
	return image;
}
#endif

inline void N_CLASS(NImage)::Save(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NImageFormat) * pImageFormat, N_CLASS(NImageInfo) * pInfo, NUInt flags) const
{
	NCheck(NImageSaveToFileExN(GetHandle(), fileName.GetHandle(), ToHandle(pImageFormat), ToHandle(pInfo), flags));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * N_CLASS(NImage)::Save(N_CLASS(NImageFormat) * pImageFormat, N_CLASS(NImageInfo) * pInfo, NUInt flags) const
{
	HNBuffer hBuffer;
	NCheck(NImageSaveToMemoryN(GetHandle(), ToHandle(pImageFormat), ToHandle(pInfo), flags, &hBuffer));
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

#include <NNoDeprecate.h>
inline void * N_CLASS(NImage)::Save(NSizeType * pBufferSize, N_CLASS(NImageFormat) * pImageFormat, N_CLASS(NImageInfo) * pInfo, NUInt flags) const
{
	void * pBuffer;
	NCheck(NImageSaveToMemory(GetHandle(), ToHandle(pImageFormat), ToHandle(pInfo), flags, &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

inline void N_CLASS(NImage)::Save(::Neurotec::IO::N_CLASS(NStream) * pStream, N_CLASS(NImageFormat) * pImageFormat, N_CLASS(NImageInfo) * pInfo, NUInt flags) const
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NImageSaveToStream(GetHandle(), pStream->GetHandle(), ToHandle(pImageFormat), ToHandle(pInfo), flags));
}

inline N_CLASS(NImageInfo) * N_CLASS(NImage)::GetInfo()
{
	HNImageInfo hValue;
	NCheck(NImageGetInfo(GetHandle(), &hValue));
	try
	{
		return FromHandle<N_CLASS(NImageInfo)>(hValue, true, true);
	}
	catch (...)
	{
		Unref(hValue);
		throw;
	}
}

}}

#endif // !N_IMAGE_HPP_INCLUDED
