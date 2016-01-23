#ifndef FP_SCANNER_HPP_INCLUDED
#define FP_SCANNER_HPP_INCLUDED

#include <NGrayscaleImage.hpp>
#include <NFScanner.hpp>
namespace Neurotec { namespace DeviceManager
{
using ::Neurotec::Images::HNGrayscaleImage;
using ::Neurotec::Devices::HNFScanner;
using ::Neurotec::Biometrics::NFImpressionType;
#include <FPScanner.h>
}}
#include <NEvent.hpp>

namespace Neurotec { namespace DeviceManager
{

class N_CLASS(FPScannerMan);

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Devices::" N_STRINGIZEA(N_CLASS(NFScanner)) " instead")
N_CLASS(FPScanner) : public N_CLASS(NObject)
{
private:
	N_CLASS(NEvent1)<N_CLASS(FPScanner) *> isCapturingChanged;
	N_CLASS(NEvent1)<N_CLASS(FPScanner) *> fingerPlaced;
	N_CLASS(NEvent1)<N_CLASS(FPScanner) *> fingerRemoved;
	N_CLASS(NEvent2)<N_CLASS(FPScanner) *, ::Neurotec::Images::N_CLASS(NGrayscaleImage) *> imageScanned;

	static void N_API OnIsCapturingChanged(HFPScanner, void * pParam)
	{
		N_CLASS(FPScanner) * pScanner = (N_CLASS(FPScanner) *)pParam;
		pScanner->isCapturingChanged(pScanner);
	}

	static void N_API OnFingerPlaced(HFPScanner, void * pParam)
	{
		N_CLASS(FPScanner) * pScanner = (N_CLASS(FPScanner) *)pParam;
		pScanner->fingerPlaced(pScanner);
	}

	static void N_API OnFingerRemoved(HFPScanner, void * pParam)
	{
		N_CLASS(FPScanner) * pScanner = (N_CLASS(FPScanner) *)pParam;
		pScanner->fingerRemoved(pScanner);
	}

	static void N_API OnImageScanned(HFPScanner, HNGrayscaleImage hImage, void * pParam)
	{
		N_CLASS(FPScanner) * pScanner = (N_CLASS(FPScanner) *)pParam;
		if (pScanner->imageScanned)
		{
			::std::auto_ptr< ::Neurotec::Images::N_CLASS(NGrayscaleImage)> image(FromHandle< ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(hImage, false, false));
			pScanner->imageScanned(pScanner, image.get());
		}
	}

	N_CLASS(FPScanner)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		try
		{
			NCheck(FPScannerSetIsCapturingChangedCallback(GetHandle(), OnIsCapturingChanged, this));
			NCheck(FPScannerSetFingerPlacedCallback(GetHandle(), OnFingerPlaced, this));
			NCheck(FPScannerSetFingerRemovedCallback(GetHandle(), OnFingerRemoved, this));
			NCheck(FPScannerSetImageScannedCallback(GetHandle(), OnImageScanned, this));
		}
		catch (...)
		{
			Uninit();
			throw;
		}
	}

	void Uninit()
	{
		if (!IsDisposed())
		{
			NResult res = N_OK;
			try
			{
				NCheck(FPScannerSetIsCapturingChangedCallback(GetHandle(), NULL, NULL));
			}
			N_EXCEPTION_CATCH_AND_SUPPRESS(res)
			try
			{
				NCheck(FPScannerSetFingerPlacedCallback(GetHandle(), NULL, NULL));
			}
			N_EXCEPTION_CATCH_AND_SUPPRESS(res)
			try
			{
				NCheck(FPScannerSetFingerRemovedCallback(GetHandle(), NULL, NULL));
			}
			N_EXCEPTION_CATCH_AND_SUPPRESS(res)
			try
			{
				NCheck(FPScannerSetImageScannedCallback(GetHandle(), NULL, NULL));
			}
			N_EXCEPTION_CATCH_AND_SUPPRESS(res)
		}
	}

public:
	typedef void (* Callback)(N_CLASS(FPScanner) * pScanner, void * pParam);
	typedef void (* ImageScannedCallback)(N_CLASS(FPScanner) * pScanner, ::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, void * pParam);

	virtual ~N_CLASS(FPScanner)()
	{
		Uninit();
	}

	::Neurotec::Devices::N_CLASS(NFScanner) * GetDevice() const
	{
		return GetObject<HandleType, ::Neurotec::Devices::N_CLASS(NFScanner)>(FPScannerGetDevice, true, true);
	}

	N_CLASS(NString) GetId() const
	{
		return GetString(FPScannerGetIdN);
	}

	bool IsCapturing()
	{
		NBool value;
		NCheck(FPScannerIsCapturing(GetHandle(), &value));
		return value != 0;
	}

	void StartCapturing()
	{
		NCheck(FPScannerStartCapturing(GetHandle()));
	}

	void StartCapturing(NFImpressionType impressionType)
	{
		NCheck(FPScannerStartCapturingEx(GetHandle(), impressionType));
	}

	void StartCapturingForOneImage()
	{
		NCheck(FPScannerStartCapturingForOneImage(GetHandle()));
	}

	void StartCapturingForOneImage(NFImpressionType impressionType)
	{
		NCheck(FPScannerStartCapturingForOneImageEx(GetHandle(), impressionType));
	}

	void StopCapturing()
	{
		NCheck(FPScannerStopCapturing(GetHandle()));
	}

	void AddIsCapturingChangedCallback(Callback pCallback, void * pParam)
	{
		isCapturingChanged.Add(pCallback, pParam);
	}

	void RemoveIsCapturingChangedCallback(Callback pCallback, void * pParam)
	{
		isCapturingChanged.Remove(pCallback, pParam);
	}

	void AddFingerPlacedCallback(Callback pCallback, void * pParam)
	{
		fingerPlaced.Add(pCallback, pParam);
	}

	void RemoveFingerPlacedCallback(Callback pCallback, void * pParam)
	{
		fingerPlaced.Remove(pCallback, pParam);
	}

	void AddFingerRemovedCallback(Callback pCallback, void * pParam)
	{
		fingerRemoved.Add(pCallback, pParam);
	}

	void RemoveFingerRemovedCallback(Callback pCallback, void * pParam)
	{
		fingerRemoved.Remove(pCallback, pParam);
	}

	void AddImageScannedCallback(ImageScannedCallback pCallback, void * pParam)
	{
		imageScanned.Add(pCallback, pParam);
	}

	void RemoveImageScannedCallback(ImageScannedCallback pCallback, void * pParam)
	{
		imageScanned.Remove(pCallback, pParam);
	}

	N_DECLARE_OBJECT_CLASS(FPScanner, NObject)
};
#include <NReDeprecate.h>

}}

#endif // !FP_SCANNER_HPP_INCLUDED
