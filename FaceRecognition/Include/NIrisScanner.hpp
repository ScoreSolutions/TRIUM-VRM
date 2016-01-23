#include <NDevice.hpp>

#ifndef N_IRIS_SCANNER_HPP_INCLUDED
#define N_IRIS_SCANNER_HPP_INCLUDED

#include <NBiometricDevice.hpp>
#include <NImage.hpp>
#include <NEAttributes.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Biometrics::NEPosition;
using ::Neurotec::Biometrics::HNEAttributes;
using ::Neurotec::Biometrics::NBiometricType;
using ::Neurotec::Biometrics::NBiometricStatus;
#include <NIrisScanner.h>
}}

namespace Neurotec { namespace Devices
{

class N_CLASS(NIrisScanner) : public N_CLASS(NBiometricDevice)
{
	N_DECLARE_OBJECT_CLASS(NIrisScanner, NBiometricDevice)

private:
	static NResult N_API PreviewCallbackImpl(HNIrisScanner hScanner, HNImage hImage, NBiometricStatus * pStatus, const HNEAttributes * arhObjects, NInt objectCount, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			::std::auto_ptr< ::Neurotec::Images::N_CLASS(NImage)> image(FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hImage, false, false));
			N_CLASS(NObjectArray)< ::Neurotec::Biometrics::N_CLASS(NEAttributes)> objects(const_cast<HNEAttributes *>(arhObjects), objectCount, false, false, false);
			auto_ptr_array< ::Neurotec::Biometrics::N_CLASS(NEAttributes)> pObjects(objects.ToArray(), objectCount);
			reinterpret_cast<PreviewCallback>(p->pCallback)(FromHandle<N_CLASS(NIrisScanner)>(hScanner, false, true), image.get(), pStatus, pObjects.get(), objectCount, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	N_CLASS(NIrisScanner)(HNObject handle, bool claimHandle)
		: N_CLASS(NBiometricDevice)(handle, claimHandle)
	{
	}

public:
	typedef void (* PreviewCallback)(N_CLASS(NIrisScanner) * pDevice, ::Neurotec::Images::N_CLASS(NImage) * pImage, NBiometricStatus * pStatus, Neurotec::Biometrics::N_CLASS(NEAttributes) * * arpObjects, NInt objectCount, void * pParam);

	NInt GetSupportedPositions(NEPosition * arValues, NInt valuesLength) const
	{
		return NCheck(NIrisScannerGetSupportedPositions(GetHandle(), arValues, valuesLength));
	}

	NEPosition * GetSupportedPositions(NInt * pCount) const
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		NInt count = GetSupportedPositions(NULL, 0);
		auto_array<NEPosition> values(count);
		*pCount = GetSupportedPositions(values.get(), count);
		return values.release();
	}

	::Neurotec::Images::N_CLASS(NImage) * Capture(NEPosition position, NInt timeoutMilliseconds = -1)
	{
		HNImage hImage = NULL;
		NCheck(NIrisScannerCapture(GetHandle(), position, timeoutMilliseconds, &hImage));
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

	::Neurotec::Images::N_CLASS(NImage) * Capture(NEPosition position, const NEPosition * arMissingPositions, NInt missingPositionCount,
		NBool automatic, NInt timeoutMilliseconds, NBiometricStatus * pStatus = NULL, ::Neurotec::Biometrics::N_CLASS(NEAttributes) * * * parpObjects = NULL, NInt * pObjectCount = 0)
	{
		HNImage hImage = NULL;
		HNEAttributes * arhObjects = NULL;
		NInt objectCount = 0;
		NCheck(NIrisScannerCaptureEx(GetHandle(), position, arMissingPositions, missingPositionCount,
			automatic, timeoutMilliseconds, pStatus, parpObjects ? &arhObjects : NULL, parpObjects || pObjectCount ? &objectCount : 0, &hImage));
		::Neurotec::Images::N_CLASS(NImage) * pImage = NULL;
		try
		{
			pImage = FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hImage);
			N_CLASS(NObjectArray)< ::Neurotec::Biometrics::N_CLASS(NEAttributes)> objects(arhObjects, objectCount);
			arhObjects = NULL; objectCount = 0;
			if (parpObjects) *parpObjects = objects.ToArray(pObjectCount);
			else if (pObjectCount) *pObjectCount = objectCount;
			return pImage;
		}
		catch (...)
		{
			UnrefOrDelete(hImage, pImage);
			UnrefArray(arhObjects, objectCount);
			throw;
		}
	}

	void AddPreviewCallback(PreviewCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(PreviewCallbackImpl, pCallback, pParam);
		NCheck(NIrisScannerAddPreview(GetHandle(), callback.GetHandle()));
	}

	void RemovePreviewCallback(PreviewCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(PreviewCallbackImpl, pCallback, pParam);
		NCheck(NIrisScannerRemovePreview(GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_IRIS_SCANNER_HPP_INCLUDED
