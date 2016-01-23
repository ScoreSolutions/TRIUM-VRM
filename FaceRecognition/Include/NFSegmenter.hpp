#ifndef NF_SEGMENTER_HPP_INCLUDED
#define NF_SEGMENTER_HPP_INCLUDED

#include <NBiometricTypes.hpp>
#include <NGrayscaleImage.hpp>
#include <NGeometry.hpp>
#include <NBiometrics.hpp>
#include <NFSegmenterParams.hpp>
namespace Neurotec { namespace Biometrics { namespace Tools
{
using ::Neurotec::Geometry::NPoint_;
using ::Neurotec::Images::HNGrayscaleImage;
#include <NFSegmenter.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Tools
{

class N_CLASS(NFSegment) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NFSegment, NObject)

public:
	class PossiblePositionCollection : public ::Neurotec::Collections::N_CLASS(NValueReadOnlyCollection)<NFPosition, N_CLASS(NFSegment)>
	{
		PossiblePositionCollection(N_CLASS(NFSegment) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NValueReadOnlyCollection)<NFPosition, N_CLASS(NFSegment)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFSegment handle, NInt * pValue) const
		{
			return NFSegmentGetPossiblePositionCount(handle, pValue);
		}

		virtual NResult GetNative(HNFSegment handle, NInt index, NFPosition * pValue) const
		{
			return NFSegmentGetPossiblePosition(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNFSegment handle, NFPosition * arValues, NInt valuesLength) const
		{
			return NFSegmentGetPossiblePositions(handle, arValues, valuesLength);
		}

		friend class N_CLASS(NFSegment);
	};

private:
	::std::auto_ptr<PossiblePositionCollection> possiblePositions;

	N_CLASS(NFSegment)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		possiblePositions.reset(new PossiblePositionCollection(this));
	}

public:
	::Neurotec::Geometry::N_CLASS(NPoint) GetTopLeft() const
	{
		::Neurotec::Geometry::N_CLASS(NPoint) value;
		NCheck(NFSegmentGetTopLeft(GetHandle(), &value));
		return value;
	}

	::Neurotec::Geometry::N_CLASS(NPoint) GetTopRight() const
	{
		::Neurotec::Geometry::N_CLASS(NPoint) value;
		NCheck(NFSegmentGetTopRight(GetHandle(), &value));
		return value;
	}

	::Neurotec::Geometry::N_CLASS(NPoint) GetBottomRight() const
	{
		::Neurotec::Geometry::N_CLASS(NPoint) value;
		NCheck(NFSegmentGetBottomRight(GetHandle(), &value));
		return value;
	}

	::Neurotec::Geometry::N_CLASS(NPoint) GetBottomLeft() const
	{
		::Neurotec::Geometry::N_CLASS(NPoint) value;
		NCheck(NFSegmentGetBottomLeft(GetHandle(), &value));
		return value;
	}

	NFPosition GetPosition() const
	{
		NFPosition value;
		NCheck(NFSegmentGetPosition(GetHandle(), &value));
		return value;
	}

	NBiometricStatus GetStatus() const
	{
		NBiometricStatus value;
		NCheck(NFSegmentGetStatus(GetHandle(), &value));
		return value;
	}

	PossiblePositionCollection * GetPossiblePositions() const
	{
		return possiblePositions.get();
	}
};

class N_CLASS(NFSegmenter)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NFSegmenter)

public:
	static N_CLASS(NFSegment) * * Locate(::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NFPosition position, NFPosition * arMissingFingers, NInt missingFingerCount, NInt * pSegmentCount)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pSegmentCount) NThrowArgumentNullException(N_T("pSegmentCount"));
		HNFSegment * arhSegments;
		NInt segmentCount;
		NCheck(NFSegmenterLocateEx(pImage->GetHandle(), position, arMissingFingers, missingFingerCount, &arhSegments, &segmentCount));
		try
		{
			N_CLASS(NObjectArray)<N_CLASS(NFSegment)> segments(arhSegments, segmentCount);
			arhSegments = NULL; segmentCount = 0;
			return segments.ToArray(pSegmentCount);
		}
		catch (...)
		{
			N_CLASS(NObject)::UnrefArray(arhSegments, segmentCount);
			throw;
		}
	}

	static N_CLASS(NFSegment) * * Locate(::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NFPosition position, NInt * pSegmentCount)
	{
		return Locate(pImage, position, NULL, 0, pSegmentCount);
	}

	static ::Neurotec::Images::N_CLASS(NGrayscaleImage) * CutSingle(::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, N_CLASS(NFSegment) * pSegment)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pSegment) NThrowArgumentNullException(N_T("pSegment"));
		HNGrayscaleImage hImage;
		NCheck(NFSegmenterCutSingle(pImage->GetHandle(), pSegment->GetHandle(), &hImage));
		try
		{
			return N_CLASS(NObject)::FromHandle< ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(hImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hImage);
			throw;
		}
	}

	static ::Neurotec::Images::N_CLASS(NGrayscaleImage) * * CutMultiple(::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, N_CLASS(NFSegment) * const * arpSegments, NInt segmentCount)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		N_CLASS(NObjectArray)<N_CLASS(NFSegment)> segments(arpSegments, segmentCount);
		HNGrayscaleImage * arhImages;
		NCheck(NFSegmenterCutMultiple(pImage->GetHandle(), segments.GetPtr(), segments.GetCount(), &arhImages));
		NInt imageCount = segmentCount;
		try
		{
			N_CLASS(NObjectArray)< ::Neurotec::Images::N_CLASS(NGrayscaleImage)> images(arhImages, imageCount);
			arhImages = NULL; imageCount = 0;
			return images.ToArray();
		}
		catch (...)
		{
			N_CLASS(NObject)::UnrefArray(arhImages, segmentCount);
			throw;
		}
	}

	static bool GetRemoveBackground()
	{
		return NativeTypeOf()->GetParameter<bool>(NULL, 0, NFSP_REMOVE_BACKGROUND);
	}

	static void SetRemoveBackground(bool value)
	{
		NativeTypeOf()->SetParameter(NULL, 0, NFSP_REMOVE_BACKGROUND, value);
	}

	static bool GetUseOld()
	{
		return NativeTypeOf()->GetParameter<bool>(NULL, 0, NFSP_USE_OLD);
	}

	static void SetUseOld(bool value)
	{
		NativeTypeOf()->SetParameter(NULL, 0, NFSP_USE_OLD, value);
	}
};

}}}

#endif // !NF_SEGMENTER_HPP_INCLUDED
