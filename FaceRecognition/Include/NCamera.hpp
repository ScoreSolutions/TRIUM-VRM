#include <NCaptureDevice.hpp>

#ifndef N_CAMERA_HPP_INCLUDED
#define N_CAMERA_HPP_INCLUDED

#include <NImage.hpp>
#include <NGeometry.hpp>
#include <NVideoFormat.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Geometry::NRectF_;
using ::Neurotec::Media::HNVideoFormat;
#include <NCamera.h>
}}

namespace Neurotec { namespace Devices
{
class N_CLASS(NCamera) : public N_CLASS(NCaptureDevice)
{
	N_DECLARE_OBJECT_CLASS(NCamera, NCaptureDevice)

private:
	static NResult N_API StillCapturedCallbackImpl(HNCamera hCamera, HNStream hStream, HNValue hId, HNPropertyBag hProperties, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			::std::auto_ptr< ::Neurotec::IO::N_CLASS(NStream)> stream(FromHandle< ::Neurotec::IO::N_CLASS(NStream)>(hStream, false, false));
			::std::auto_ptr<N_CLASS(NValue)> id(FromHandle<N_CLASS(NValue)>(hId, false, false));
			::std::auto_ptr<N_CLASS(NPropertyBag)> properties(FromHandle<N_CLASS(NPropertyBag)>(hProperties, false, false));
			reinterpret_cast<StillCapturedCallback>(p->pCallback)(FromHandle<N_CLASS(NCamera)>(hCamera, false, true), stream.get(), id.get(), properties.get(), p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

private:
	N_CLASS(NCamera)(HNObject handle, bool claimHandle)
		: N_CLASS(NCaptureDevice)(handle, claimHandle)
	{
	}

public:
	typedef void (* StillCapturedCallback)(N_CLASS(NCamera) * pDevice, ::Neurotec::IO::N_CLASS(NStream) * pStream, N_CLASS(NValue) * pId, N_CLASS(NPropertyBag) * pProperties, void * pParam);

	::Neurotec::Images::N_CLASS(NImage) * GetFrame()
	{
		HNImage hImage = NULL;
		NCheck(NCameraGetFrame(GetHandle(), &hImage));
		try
		{
			return FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hImage);
		}
		catch (...)
		{
			Unref(hImage);
			throw;
		}
	}

	bool IsFocusSupported() const
	{
		NBool value;
		NCheck(NCameraIsFocusSupported(GetHandle(), &value));
		return value != 0;
	}

	bool IsFocusRegionSupported() const
	{
		NBool value;
		NCheck(NCameraIsFocusRegionSupported(GetHandle(), &value));
		return value != 0;
	}

	bool GetFocusRegion(::Neurotec::Geometry::N_CLASS(NRectF) * pValue) const
	{
		NBool hasValue;
		NCheck(NCameraGetFocusRegion(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetFocusRegion(const ::Neurotec::Geometry::N_CLASS(NRectF) * pValue)
	{
		NCheck(NCameraSetFocusRegion(GetHandle(), pValue));
	}

	void ResetFocus()
	{
		NCheck(NCameraResetFocus(GetHandle()));
	}

	NCameraStatus Focus()
	{
		NCameraStatus status;
		NCheck(NCameraFocus(GetHandle(), &status));
		return status;
	}

	bool IsStillCaptureSupported() const
	{
		NBool value;
		NCheck(NCameraIsStillCaptureSupported(GetHandle(), &value));
		return value != 0;
	}

	::Neurotec::Media::N_CLASS(NVideoFormat) * * GetStillFormats(NInt * pCount) const
	{
		return GetObjects<HandleType, ::Neurotec::Media::N_CLASS(NVideoFormat)>(NCameraGetStillFormats, pCount);
	}

	::Neurotec::Media::N_CLASS(NVideoFormat) * GetCurrentStillFormat() const
	{
		return GetObject<HandleType, ::Neurotec::Media::N_CLASS(NVideoFormat)>(NCameraGetCurrentStillFormat);
	}

	void SetCurrentStillFormat(::Neurotec::Media::N_CLASS(NVideoFormat) * pValue)
	{
		NCheck(NCameraSetCurrentStillFormat(GetHandle(), ToHandle(pValue)));
	}

	NCameraStatus CaptureStill()
	{
		NCameraStatus status;
		NCheck(NCameraCaptureStill(GetHandle(), &status));
		return status;
	}

	void AddStillCapturedCallback(StillCapturedCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(StillCapturedCallbackImpl, pCallback, pParam);
		NCheck(NCameraAddStillCaptured(GetHandle(), callback.GetHandle()));
	}

	void RemoveStillCapturedCallback(StillCapturedCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(StillCapturedCallbackImpl, pCallback, pParam);
		NCheck(NCameraRemoveStillCaptured(GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_CAMERA_HPP_INCLUDED
