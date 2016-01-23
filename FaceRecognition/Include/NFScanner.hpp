#include <NDevice.hpp>

#ifndef N_F_SCANNER_HPP_INCLUDED
#define N_F_SCANNER_HPP_INCLUDED

#include <NBiometricDevice.hpp>
#include <NGeometry.hpp>
#include <NImage.hpp>
#include <NFAttributes.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Biometrics::NFImpressionType;
using ::Neurotec::Biometrics::NFPosition;
using ::Neurotec::Biometrics::HNFAttributes;
using ::Neurotec::Biometrics::NBiometricType;
using ::Neurotec::Biometrics::NBiometricStatus;
#include <NFScanner.h>
}}

namespace Neurotec { namespace Devices
{
class N_CLASS(NFScanner) : public N_CLASS(NBiometricDevice)
{
	N_DECLARE_OBJECT_CLASS(NFScanner, NBiometricDevice)

private:
	static NResult N_API PreviewCallbackImpl(HNFScanner hScanner, HNImage hImage, NBiometricStatus * pStatus, const HNFAttributes * arhObjects, NInt objectCount, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			::std::auto_ptr< ::Neurotec::Images::N_CLASS(NImage)> image(FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hImage, false, false));
			N_CLASS(NObjectArray)< ::Neurotec::Biometrics::N_CLASS(NFAttributes)> objects(const_cast<HNFAttributes *>(arhObjects), objectCount, false, false, false);
			auto_ptr_array< ::Neurotec::Biometrics::N_CLASS(NFAttributes)> pObjects(objects.ToArray(), objectCount);
			reinterpret_cast<PreviewCallback>(p->pCallback)(FromHandle<N_CLASS(NFScanner)>(hScanner, false, true), image.get(), pStatus, pObjects.get(), objectCount, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

protected:
	N_CLASS(NFScanner)(HNObject handle, bool claimHandle)
		: N_CLASS(NBiometricDevice)(handle, claimHandle)
	{
	}

public:
	typedef void (* PreviewCallback)(N_CLASS(NFScanner) * pDevice, ::Neurotec::Images::N_CLASS(NImage) * pImage, NBiometricStatus * pStatus, Neurotec::Biometrics::N_CLASS(NFAttributes) * * arpObjects, NInt objectCount, void * pParam);

	NInt GetSupportedImpressionTypes(NFImpressionType * arValues, NInt valuesLength) const
	{
		return NCheck(NFScannerGetSupportedImpressionTypes(GetHandle(), arValues, valuesLength));
	}

	NFImpressionType * GetSupportedImpressionTypes(NInt * pCount) const
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		NInt count = GetSupportedImpressionTypes(NULL, 0);
		auto_array<NFImpressionType> values(count);
		*pCount = GetSupportedImpressionTypes(values.get(), count);
		return values.release();
	}

	NInt GetSupportedPositions(NFPosition * arValues, NInt valuesLength) const
	{
		return NCheck(NFScannerGetSupportedPositions(GetHandle(), arValues, valuesLength));
	}

	NFPosition * GetSupportedPositions(NInt * pCount) const
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		NInt count = GetSupportedPositions(NULL, 0);
		auto_array<NFPosition> values(count);
		*pCount = GetSupportedPositions(values.get(), count);
		return values.release();
	}

	::Neurotec::Images::N_CLASS(NImage) * Capture(NInt timeoutMilliseconds = -1)
	{
		HNImage hImage;
		NCheck(NFScannerCapture(GetHandle(), timeoutMilliseconds, &hImage));
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

	::Neurotec::Images::N_CLASS(NImage) * Capture(NFImpressionType impressionType, NFPosition position, NInt timeoutMilliseconds = -1)
	{
		return Capture(impressionType, position, NULL, 0, true, timeoutMilliseconds, NULL);
	}

	::Neurotec::Images::N_CLASS(NImage) * Capture(NFImpressionType impressionType, NFPosition position, const NFPosition * arMissingPositions, NInt missingPositionCount,
		NBool automatic, NInt timeoutMilliseconds, NBiometricStatus * pStatus = NULL, ::Neurotec::Biometrics::N_CLASS(NFAttributes) * * * parpObjects = NULL, NInt * pObjectCount = 0)
	{
		HNImage hImage = NULL;
		HNFAttributes * arhObjects = NULL;
		NInt objectCount = 0;
		NCheck(NFScannerCaptureEx(GetHandle(), impressionType, position, arMissingPositions, missingPositionCount,
			automatic, timeoutMilliseconds, pStatus, parpObjects ? &arhObjects : NULL, parpObjects || pObjectCount ? &objectCount : 0, &hImage));
		::Neurotec::Images::N_CLASS(NImage) * pImage = NULL;
		try
		{
			pImage = FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hImage);
			N_CLASS(NObjectArray)< ::Neurotec::Biometrics::N_CLASS(NFAttributes)> objects(arhObjects, objectCount);
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
		NCheck(NFScannerAddPreview(GetHandle(), callback.GetHandle()));
	}

	void RemovePreviewCallback(PreviewCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(PreviewCallbackImpl, pCallback, pParam);
		NCheck(NFScannerRemovePreview(GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_F_SCANNER_HPP_INCLUDED
