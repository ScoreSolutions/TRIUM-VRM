#ifndef N_SURVEILLANCE_EVENT_DETAILS_HPP_INCLUDED
#define N_SURVEILLANCE_EVENT_DETAILS_HPP_INCLUDED

#include <NGrayscaleImage.hpp>
#include <NRgbImage.hpp>
#include <NTemplate.hpp>
#include <NLExtractor.hpp>
#include <NsedMatch.hpp>
namespace Neurotec { namespace Surveillance
{
using Neurotec::Images::HNImage;
using Neurotec::Images::HNGrayscaleImage;
using Neurotec::Biometrics::NleFace;
using Neurotec::Biometrics::NleDetectionDetails;
using Neurotec::Biometrics::NleExtractionStatus;
using Neurotec::Biometrics::HNLTemplate;
#include <NSurveillanceEventDetails.h>
}}

namespace Neurotec { namespace Surveillance
{

class N_CLASS(NSurveillance);

class N_CLASS(NSurveillanceEventDetails) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NSurveillanceEventDetails, NObject)

public:
	class BestMatchCollection : public ::Neurotec::Collections::N_CLASS(NStructReadOnlyCollection)<N_CLASS(NsedMatchEx), N_CLASS(NSurveillanceEventDetails)>
	{
	private:
		BestMatchCollection(N_CLASS(NSurveillanceEventDetails) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructReadOnlyCollection)<N_CLASS(NsedMatchEx), N_CLASS(NSurveillanceEventDetails)>(pOwner)
		{
		}

	protected:
		virtual bool SupportsGetAll() const
		{
			return true;
		}

		virtual NResult GetCountNative(HNSurveillanceEventDetails handle, NInt * pValue) const
		{
			return NsedGetBestMatchCount(handle, pValue);
		}

		virtual NResult GetNative(HNSurveillanceEventDetails handle, NInt index, N_CLASS(NsedMatchEx) * pValue) const
		{
			return NsedGetBestMatchEx(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNSurveillanceEventDetails handle, N_CLASS(NsedMatchEx) * arValues, NInt valuesLength) const
		{
			return NsedGetBestMatchesEx2(handle, arValues, valuesLength);
		}

		friend class N_CLASS(NSurveillanceEventDetails);
	};

private:
	::std::auto_ptr<BestMatchCollection> bestMatches;

	N_CLASS(NSurveillanceEventDetails)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		bestMatches.reset(new BestMatchCollection(this));
	}

public:
	N_CLASS(NSurveillance) * GetOwner() const;

	NInt GetFaces(NleFace * arFaces) const
	{
		return NCheck(NsedGetFaces(GetHandle(), arFaces));
	}

	BestMatchCollection * GetBestMatches() const
	{
		return bestMatches.get();
	}

	::Neurotec::Biometrics::N_CLASS(NLTemplate) * GetSubjectTemplate() const
	{
		return GetObject<HandleType, ::Neurotec::Biometrics::N_CLASS(NLTemplate)>(NsedGetSubjectTemplate);
	}

	NInt GetTraceIndex() const
	{
		NInt value;
		NCheck(NsedGetTraceIndex(GetHandle(), &value));
		return value;
	}

	NULong GetFrameIndex() const
	{
		NULong value;
		NCheck(NsedGetFrameIndex(GetHandle(), &value));
		return value;
	}

	N_CLASS(NDateTime) GetTimeStamp() const
	{
		NDateTime_ value;
		NCheck(NsedGetTimeStamp(GetHandle(), &value));
		return N_CLASS(NDateTime)(value);
	}

	NInt GetSourceIndex() const
	{
		NInt value;
		NCheck(NsedGetSourceIndex(GetHandle(), &value));
		return value;
	}
	
	::Neurotec::Images::N_CLASS(NImage) * GetOriginalImage() const
	{
		return GetObject<HandleType, ::Neurotec::Images::N_CLASS(NImage)>(NsedGetOriginalImageEx, true, true);
	}

	::Neurotec::Images::N_CLASS(NGrayscaleImage) * GetGrayscaleImage() const
	{
		return GetObject<HandleType, ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(NsedGetGrayscaleImageEx, true, true);
	}

	NleDetectionDetails GetDetectionDetails() const
	{
		NleDetectionDetails value;
		NCheck(NsedGetDetectionDetails(GetHandle(), &value));
		return value;
	}

	NleExtractionStatus GetExtractionStatus() const
	{
		NleExtractionStatus value;
		NCheck(NsedGetExtractionStatus(GetHandle(), &value));
		return value;
	}

	::Neurotec::Biometrics::N_CLASS(NLTemplate) * GetTemplate() const
	{
		return GetObject<HandleType, ::Neurotec::Biometrics::N_CLASS(NLTemplate)>(NsedGetTemplateEx, true, true);
	}
};

}}

#include <NSurveillance.hpp>

namespace Neurotec { namespace Surveillance
{
inline N_CLASS(NSurveillance) * N_CLASS(NSurveillanceEventDetails)::GetOwner() const
{
	return dynamic_cast<N_CLASS(NSurveillance) *>(N_CLASS(NObject)::GetOwner());
}
}}

#endif // !N_SURVEILLANCE_EVENT_DETAILS_HPP_INCLUDED
