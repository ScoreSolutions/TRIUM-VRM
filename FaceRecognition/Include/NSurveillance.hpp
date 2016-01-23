#include <NSurveillanceEventDetails.hpp>

#ifndef N_SURVEILLANCE_HPP_INCLUDED
#define N_SURVEILLANCE_HPP_INCLUDED

#include <CameraMan.hpp>
#include <NDeviceManager.hpp>
#include <NCamera.hpp>
#include <NSurveillanceParams.hpp>
namespace Neurotec { namespace Surveillance
{
using ::Neurotec::DeviceManager::HCamera;
using ::Neurotec::Devices::HNDeviceManager;
using ::Neurotec::Devices::HNCamera;
#include <NSurveillance.h>
}}

namespace Neurotec { namespace Surveillance
{

#include <NNoDeprecate.h>
class N_CLASS(NSurveillance) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NSurveillance, NObject)

public:
	class N_DEPRECATED("class is deprecated, use SourceCollection instead")
		OldSourceCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::DeviceManager::N_CLASS(Camera), N_CLASS(NSurveillance), true, true>
	{
	private:
		OldSourceCollection(N_CLASS(NSurveillance) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::DeviceManager::N_CLASS(Camera), N_CLASS(NSurveillance), true, true>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNSurveillance handle, NInt * pValue) const
		{
			return NSurveillanceGetSourceCountEx(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNSurveillance, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNSurveillance, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNSurveillance handle, NInt index, HCamera * phValue) const
		{
			return NSurveillanceGetSourceEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNSurveillance, HCamera *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNSurveillance, NInt, HCamera)
		{
			NThrowNotSupportedException();
		}

		virtual NResult AddNative(HNSurveillance handle, HCamera hValue)
		{
			return NSurveillanceAddSourceEx(handle, hValue);
		}

		virtual NResult AddWithOutIndexNative(HNSurveillance, HCamera, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNSurveillance, NInt, HCamera)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveWithOutIndexNative(HNSurveillance, HCamera, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNSurveillance handle, NInt index)
		{
			return NSurveillanceRemoveSourceEx(handle, index);
		}

		virtual NResult RemoveRangeNative(HNSurveillance, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNSurveillance handle)
		{
			return NSurveillanceClearSourcesEx(handle);
		}

		friend class N_CLASS(NSurveillance);
	};

	class SourceCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::Devices::N_CLASS(NCamera), N_CLASS(NSurveillance)>
	{
	private:
		SourceCollection(N_CLASS(NSurveillance) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::Devices::N_CLASS(NCamera), N_CLASS(NSurveillance)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNSurveillance handle, NInt * pValue) const
		{
			return NSurveillanceGetSourceCountEx(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNSurveillance, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNSurveillance, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNSurveillance handle, NInt index, HNCamera * phValue) const
		{
			return NSurveillanceGetSourceEx2(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNSurveillance, HNCamera *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNSurveillance, NInt, HNCamera)
		{
			NThrowNotSupportedException();
		}

		virtual NResult AddNative(HNSurveillance, HNCamera)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNSurveillance handle, HNCamera hValue, NInt * pIndex)
		{
			return NSurveillanceAddSourceEx2(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNSurveillance, NInt, HNCamera)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveWithOutIndexNative(HNSurveillance, HNCamera, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNSurveillance handle, NInt index)
		{
			return NSurveillanceRemoveSourceEx(handle, index);
		}

		virtual NResult RemoveRangeNative(HNSurveillance, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNSurveillance handle)
		{
			return NSurveillanceClearSourcesEx(handle);
		}

		friend class N_CLASS(NSurveillance);
	};

private:
	static HNSurveillance Create()
	{
		HNSurveillance handle;
		NCheck(NSurveillanceCreate(&handle));
		return handle;
	}

	static NResult N_API EventCallbackImpl(HNSurveillance hSurveillance, NSurveillanceEventType eventType, HNSurveillanceEventDetails hEventDetails, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			::std::auto_ptr<N_CLASS(NSurveillanceEventDetails)> eventDetails(FromHandle<N_CLASS(NSurveillanceEventDetails)>(hEventDetails, false, false));
			reinterpret_cast<EventCallback>(p->pCallback)(FromHandle<N_CLASS(NSurveillance)>(hSurveillance, false, true), eventType, eventDetails.get(), p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	N_DEPRECATED("field is deprecated, use sources instead")
	::std::auto_ptr<OldSourceCollection> oldSources;
	::std::auto_ptr<SourceCollection> sources;

	N_CLASS(NSurveillance)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		oldSources.reset(new OldSourceCollection(this));
		sources.reset(new SourceCollection(this));
	}

public:
	typedef void (* EventCallback)(N_CLASS(NSurveillance) * pSurveillance, NSurveillanceEventType eventType, N_CLASS(NSurveillanceEventDetails) * pDetails, void * pParam);

	static N_CLASS(NType) * NSurveillanceEventTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NSurveillanceEventType), true, true);
	}

	N_DEPRECATED("method is deprecated, use N_NATIVE_MODULE_OF(NSurveillance) instead")
	static void GetInfo(NLibraryInfo * pValue)
	{
		NCheck(NSurveillanceGetInfo(pValue));
	}

	N_CLASS(NSurveillance)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSurveillance);
		Init();
	}

	::Neurotec::Devices::N_CLASS(NDeviceManager) * GetDeviceManager() const
	{
		return GetObject<HandleType, ::Neurotec::Devices::N_CLASS(NDeviceManager)>(NSurveillanceGetDeviceManager, true, true);
	}

	void AddEventCallback(NSurveillanceEventType eventType, EventCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(EventCallbackImpl, pCallback, pParam);
		NCheck(NSurveillanceAddEventEx(GetHandle(), eventType, callback.GetHandle()));
	}

	void RemoveEventCallback(NSurveillanceEventType eventType, EventCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(EventCallbackImpl, pCallback, pParam);
		NCheck(NSurveillanceRemoveEventEx(GetHandle(), eventType, callback.GetHandle()));
	}

	void AddIsRunningChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NSurveillanceAddIsRunningChanged(GetHandle(), callback.GetHandle()));
	}

	void RemoveIsRunningChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NSurveillanceRemoveIsRunningChanged(GetHandle(), callback.GetHandle()));
	}

	void Start()
	{
		NCheck(NSurveillanceStartEx(GetHandle()));
	}

	void Stop()
	{
		NCheck(NSurveillanceStopEx(GetHandle()));
	}

	void AddTemplate(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, N_CLASS(NValue) * pTemplateId)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		if (!pTemplateId) NThrowArgumentNullException(N_T("pTemplateId"));
		NCheck(NSurveillanceAddTemplateExN(GetHandle(), pTemplate->GetHandle(), pTemplateId->GetHandle()));
	}

	void AddTemplate(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, const void * templateId)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NSurveillanceAddTemplateExTN(GetHandle(), pTemplate->GetHandle(), templateId));
	}

	void AddTemplate(const void * pTemplate, NSizeType templateSize, N_CLASS(NValue) * pTemplateId)
	{
		if (!pTemplateId) NThrowArgumentNullException(N_T("pTemplateId"));
		NCheck(NSurveillanceAddTemplateExIN(GetHandle(), pTemplate, templateSize, pTemplateId->GetHandle()));
	}

	void AddTemplate(const void * pTemplate, NSizeType templateSize, const void * templateId)
	{
		NCheck(NSurveillanceAddTemplateEx(GetHandle(), pTemplate, templateSize, templateId));
	}

	void RemoveTemplate(N_CLASS(NValue) * pTemplateId)
	{
		if (!pTemplateId) NThrowArgumentNullException(N_T("pTemplateId"));
		NCheck(NSurveillanceRemoveTemplateExN(GetHandle(), pTemplateId->GetHandle()));
	}

	void RemoveTemplate(const void * templateId)
	{
		NCheck(NSurveillanceRemoveTemplateEx(GetHandle(), templateId));
	}

	void RemoveAllTemplates()
	{
		NCheck(NSurveillanceRemoveAllTemplatesEx(GetHandle()));
	}

	NInt GetTemplateIds(N_CLASS(NValue) * * arpTemplateIds, NInt templateIdsLength)
	{
		N_CLASS(NObjectArray)<N_CLASS(NValue)> templateIds(arpTemplateIds ? templateIdsLength : 0, true, true);
		NInt count = NCheck(NSurveillanceGetTemplateIdsExN(GetHandle(), arpTemplateIds ? templateIds.GetPtr() : NULL, templateIdsLength));
		if (arpTemplateIds) templateIds.CopyTo(arpTemplateIds, templateIdsLength, count);
		return count;
	}
	N_CLASS(NValue) * * GetTemplateIds(NInt * pCount)
	{
		NInt count = NCheck(NSurveillanceGetTemplateIdsExN(GetHandle(), NULL, 0));
		N_CLASS(NObjectArray)<N_CLASS(NValue)> templateIds(count, true, true);
		count = NCheck(NSurveillanceGetTemplateIdsExN(GetHandle(), templateIds.GetPtr(), count));
		return templateIds.ToArray(pCount);
	}

	NInt GetTemplateIds(const void * * arTemplateIds)
	{
		return NCheck(NSurveillanceGetTemplateIdsEx(GetHandle(), arTemplateIds));
	}

	bool IsRunning()
	{
		NBool value;
		NCheck(NSurveillanceIsRunning(GetHandle(), &value));
		return value != NFalse;
	}

	N_DEPRECATED("method is deprecated, use GetSources instead")
	OldSourceCollection * GetOldSources()
	{
		return oldSources.get();
	}

	SourceCollection * GetSources()
	{
		return sources.get();
	}

	NInt GetMaxThreadCount()
	{
		return GetParameter<NInt>(NSP_MAX_THREAD_COUNT);
	}

	void SetMaxThreadCount(NInt value)
	{
		SetParameter(NSP_MAX_THREAD_COUNT, value);
	}

	NInt GetDetectionMinIod()
	{
		return GetParameter<NInt>(NSP_DETECTION_MIN_IOD);
	}

	void SetDetectionMinIod(NInt value)
	{
		SetParameter(NSP_DETECTION_MIN_IOD, value);
	}

	NInt GetDetectionMaxIod()
	{
		return GetParameter<NInt>(NSP_DETECTION_MAX_IOD);
	}

	void SetDetectionMaxIod(NInt value)
	{
		SetParameter(NSP_DETECTION_MAX_IOD, value);
	}

	NDouble GetDetectionFaceConfidenceThreshold()
	{
		return GetParameter<NDouble>(NSP_DETECTION_FACE_CONFIDENCE_THRESHOLD);
	}

	void SetDetectionFaceConfidenceThreshold(NDouble value)
	{
		SetParameter(NSP_DETECTION_FACE_CONFIDENCE_THRESHOLD, value);
	}

	NShort GetDetectionMaxRollAngleDeviation()
	{
		return GetParameter<NShort>(NSP_DETECTION_MAX_ROLL_ANGLE_DEVIATION);
	}

	void SetDetectionMaxRollAngleDeviation(NShort value)
	{
		SetParameter(NSP_DETECTION_MAX_ROLL_ANGLE_DEVIATION, value);
	}

	NShort GetDetectionMaxYawAngleDeviation()
	{
		return GetParameter<NShort>(NSP_DETECTION_MAX_YAW_ANGLE_DEVIATION);
	}

	void SetDetectionMaxYawAngleDeviation(NShort value)
	{
		SetParameter(NSP_DETECTION_MAX_YAW_ANGLE_DEVIATION, value);
	}

	bool GetDetectionDetectMoreFaces()
	{
		return GetParameter<bool>(NSP_DETECTION_DETECT_MORE_FACES);
	}

	void SetDetectionDetectMoreFaces(bool value)
	{
		SetParameter(NSP_DETECTION_DETECT_MORE_FACES, value);
	}

	NInt GetDetectionFaceDetectionScaleCount()
	{
		return GetParameter<NInt>(NSP_DETECTION_FACE_DETECTION_SCALE_COUNT);
	}

	void SetDetectionFaceDetectionScaleCount(NInt value)
	{
		SetParameter(NSP_DETECTION_FACE_DETECTION_SCALE_COUNT, value);
	}

	NShort GetDetectionFaceRollAngleBase()
	{
		return GetParameter<NShort>(NSP_DETECTION_FACE_ROLL_ANGLE_BASE);
	}

	void SetDetectionFaceRollAngleBase(NShort value)
	{
		SetParameter(NSP_DETECTION_FACE_ROLL_ANGLE_BASE, value);
	}


	NByte GetExtractionFaceQualityThreshold()
	{
		return GetParameter<NByte>(NSP_EXTRACTION_FACE_QUALITY_THRESHOLD);
	}

	void SetExtractionFaceQualityThreshold(NByte value)
	{
		SetParameter(NSP_EXTRACTION_FACE_QUALITY_THRESHOLD, value);
	}

	NInt GetExtractionMaxRecordsPerTemplate()
	{
		return GetParameter<NInt>(NSP_EXTRACTION_MAX_RECORDS_PER_TEMPLATE);
	}

	void SetExtractionMaxRecordsPerTemplate(NInt value)
	{
		SetParameter(NSP_EXTRACTION_MAX_RECORDS_PER_TEMPLATE, value);
	}

	::Neurotec::Biometrics::NleTemplateSize GetExtractionEnrollmentTemplateSize()
	{
		return (::Neurotec::Biometrics::NleTemplateSize)GetParameter<NInt>(NSP_EXTRACTION_ENROLLMENT_TEMPLATE_SIZE);
	}

	void SetExtractionEnrollmentTemplateSize(::Neurotec::Biometrics::NleTemplateSize value)
	{
		SetParameter(NSP_EXTRACTION_ENROLLMENT_TEMPLATE_SIZE, (NInt)value);
	}

	::Neurotec::Biometrics::NleTemplateSize GetExtractionIdentificationTemplateSize()
	{
		return (::Neurotec::Biometrics::NleTemplateSize)GetParameter<NInt>(NSP_EXTRACTION_IDENTIFICATION_TEMPLATE_SIZE);
	}

	void SetExtractionIdentificationTemplateSize(::Neurotec::Biometrics::NleTemplateSize value)
	{
		SetParameter(NSP_EXTRACTION_IDENTIFICATION_TEMPLATE_SIZE, (NInt)value);
	}

	bool GetExtractionDetectGener()
	{
		return GetParameter<bool>(NSP_EXTRACTION_DETECT_GENDER);
	}

	void SetExtractionDetectGender(bool value)
	{
		SetParameter(NSP_EXTRACTION_DETECT_GENDER, value);
	}

	NInt GetExtractionGenderConfidenceThreshold()
	{
		return GetParameter<NInt>(NSP_EXTRACTION_GENDER_CONFIDENCE_THRESHOLD);
	}

	void SetExtractionGenderConfidenceThreshold(NInt value)
	{
		SetParameter(NSP_EXTRACTION_GENDER_CONFIDENCE_THRESHOLD, value);
	}

	bool GetExtractionDetectExpression()
	{
		return GetParameter<bool>(NSP_EXTRACTION_DETECT_EXPRESSION);
	}

	void SetExtractionDetectExpression(bool value)
	{
		SetParameter(NSP_EXTRACTION_DETECT_EXPRESSION, value);
	}

	NByte GetExtractionExpressionConfidenceThreshold()
	{
		return GetParameter<NByte>(NSP_EXTRACTION_EXPRESSION_CONFIDENCE_THRESHOLD);
	}

	void SetExtractionExpressionConfidenceThreshold(NByte value)
	{
		SetParameter(NSP_EXTRACTION_EXPRESSION_CONFIDENCE_THRESHOLD, value);
	}

	bool GetExtractionDetectBlink()
	{
		return GetParameter<bool>(NSP_EXTRACTION_DETECT_BLINK);
	}

	void SetExtractionDetectBlink(bool value)
	{
		SetParameter(NSP_EXTRACTION_DETECT_BLINK, value);
	}

	NByte GetExtractionBlinkConfidenceThreshold()
	{
		return GetParameter<NByte>(NSP_EXTRACTION_BLINK_CONFIDENCE_THRESHOLD);
	}

	void SetExtractionBlinkConfidenceThreshold(NByte value)
	{
		SetParameter(NSP_EXTRACTION_BLINK_CONFIDENCE_THRESHOLD, value);
	}

	bool GetExtractionDetectMouthOpen()
	{
		return GetParameter<bool>(NSP_EXTRACTION_DETECT_MOUTH_OPEN);
	}

	void SetExtractionDetectMouthOpen(bool value)
	{
		SetParameter(NSP_EXTRACTION_DETECT_MOUTH_OPEN, value);
	}

	NByte GetExtractionMouthOpenConfidenceThreshold()
	{
		return GetParameter<NByte>(NSP_EXTRACTION_MOUTH_OPEN_CONFIDENCE_THRESHOLD);
	}

	void SetExtractionMouthOpenConfidenceThreshold(NByte value)
	{
		SetParameter(NSP_EXTRACTION_MOUTH_OPEN_CONFIDENCE_THRESHOLD, value);
	}

	bool GetExtractionDetectGlasses()
	{
		return GetParameter<bool>(NSP_EXTRACTION_DETECT_GLASSES);
	}

	void SetExtractionDetectGlasses(bool value)
	{
		SetParameter(NSP_EXTRACTION_DETECT_GLASSES, value);
	}

	NByte GetExtractionGlassesConfidenceThreshold()
	{
		return GetParameter<NByte>(NSP_EXTRACTION_GLASSES_CONFIDENCE_THRESHOLD);
	}

	void SetExtractionGlassesConfidenceThreshold(NByte value)
	{
		SetParameter(NSP_EXTRACTION_GLASSES_CONFIDENCE_THRESHOLD, value);
	}

	bool GetExtractionDetectDarkGlasses()
	{
		return GetParameter<bool>(NSP_EXTRACTION_DETECT_DARK_GLASSES);
	}

	void SetExtractionDetectDarkGlasses(bool value)
	{
		SetParameter(NSP_EXTRACTION_DETECT_DARK_GLASSES, value);
	}

	NByte GetExtractionDarkGlassesConfidenceThreshold()
	{
		return GetParameter<NByte>(NSP_EXTRACTION_DARK_GLASSES_CONFIDENCE_THRESHOLD);
	}

	void SetExtractionDarkGlassesConfidenceThreshold(NByte value)
	{
		SetParameter(NSP_EXTRACTION_DARK_GLASSES_CONFIDENCE_THRESHOLD, value);
	}

	NInt GetIdentificationMatchingThreshold()
	{
		return GetParameter<NInt>(NSP_IDENTIFICATION_MATCHING_THRESHOLD);
	}

	void SetIdentificationMatchingThreshold(NInt value)
	{
		SetParameter(NSP_IDENTIFICATION_MATCHING_THRESHOLD, value);
	}

	NInt GetIdentificationMaxBestMatchCount()
	{
		return GetParameter<NInt>(NSP_IDENTIFICATION_MAX_BEST_MATCH_COUNT);
	}

	void SetIdentificationMaxBestMatchCount(NInt value)
	{
		SetParameter(NSP_IDENTIFICATION_MAX_BEST_MATCH_COUNT, value);
	}

	void AddAnyCallback(EventCallback pCallback, void * pParam)
	{
		AddEventCallback(nsetAny, pCallback, pParam);
	}

	void RemoveAnyCallback(EventCallback pCallback, void * pParam)
	{
		RemoveEventCallback(nsetAny, pCallback, pParam);
	}

	void AddImageCapturedCallback(EventCallback pCallback, void * pParam)
	{
		AddEventCallback(nsetImageCaptured, pCallback, pParam);
	}

	void RemoveImageCapturedCallback(EventCallback pCallback, void * pParam)
	{
		RemoveEventCallback(nsetImageCaptured, pCallback, pParam);
	}

	void AddFacesDetectedCallback(EventCallback pCallback, void * pParam)
	{
		AddEventCallback(nsetFacesDetected, pCallback, pParam);
	}

	void RemoveFacesDetectedCallback(EventCallback pCallback, void * pParam)
	{
		RemoveEventCallback(nsetFacesDetected, pCallback, pParam);
	}

	void AddSubjectAppearedCallback(EventCallback pCallback, void * pParam)
	{
		AddEventCallback(nsetSubjectAppeared, pCallback, pParam);
	}

	void RemoveSubjectAppearedCallback(EventCallback pCallback, void * pParam)
	{
		RemoveEventCallback(nsetSubjectAppeared, pCallback, pParam);
	}

	void AddSubjectTrackCallback(EventCallback pCallback, void * pParam)
	{
		AddEventCallback(nsetSubjectTrack, pCallback, pParam);
	}

	void RemoveSubjectTrackCallback(EventCallback pCallback, void * pParam)
	{
		RemoveEventCallback(nsetSubjectTrack, pCallback, pParam);
	}

	void AddSubjectDisappearedCallback(EventCallback pCallback, void * pParam)
	{
		AddEventCallback(nsetSubjectDisappeared, pCallback, pParam);
	}

	void RemoveSubjectDisappearedCallback(EventCallback pCallback, void * pParam)
	{
		RemoveEventCallback(nsetSubjectDisappeared, pCallback, pParam);
	}

	N_DECLARE_MODULE_CLASS(NSurveillance)
};
#include <NReDeprecate.h>

}}

#endif // !N_SURVEILLANCE_HPP_INCLUDED
