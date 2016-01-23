#ifndef IRIS_CAMERA_HPP_INCLUDED
#define IRIS_CAMERA_HPP_INCLUDED

#include <NGrayscaleImage.hpp>
#include <IrisCameraParams.hpp>
#include <NIrisScanner.hpp>
namespace Neurotec { namespace DeviceManager
{
using ::Neurotec::Images::HNGrayscaleImage;
using ::Neurotec::Devices::HNIrisScanner;
#include <IrisCamera.h>
}}
#include <NEvent.hpp>

namespace Neurotec { namespace DeviceManager
{

class N_CLASS(IrisCameraMan);

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Devices::" N_STRINGIZEA(N_CLASS(NIrisScanner)) " instead")
N_CLASS(IrisCamera) : public N_CLASS(NObject)
{
private:
	N_CLASS(NEvent3)<N_CLASS(IrisCamera) *, Neurotec::Images::N_CLASS(NGrayscaleImage) *, ::Neurotec::Images::N_CLASS(NGrayscaleImage) *> irisesAcquired;

	static void N_API OnIrisesAcquired(HIrisCamera, HNGrayscaleImage hLeftIris, HNGrayscaleImage hRightIris, void * pParam)
	{
		N_CLASS(IrisCamera) * pCamera = (N_CLASS(IrisCamera) *)pParam;
		if (pCamera->irisesAcquired)
		{
			::std::auto_ptr< ::Neurotec::Images::N_CLASS(NGrayscaleImage)> leftImage(FromHandle< ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(hLeftIris, false, false));
			::std::auto_ptr< ::Neurotec::Images::N_CLASS(NGrayscaleImage)> rightImage(FromHandle< ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(hRightIris, false, false));
			pCamera->irisesAcquired(pCamera, leftImage.get(), rightImage.get());
		}
	}

	N_CLASS(IrisCamera)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		try
		{
			NCheck(IrisCameraSetIrisesAcquiredCallback(GetHandle(), OnIrisesAcquired, this));
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
				NCheck(IrisCameraSetIrisesAcquiredCallback(GetHandle(), NULL, NULL));
			}
			N_EXCEPTION_CATCH_AND_SUPPRESS(res)
		}
	}

public:
	typedef void (* IrisesAcquiredCallback)(N_CLASS(IrisCamera) *pIrisCamera, ::Neurotec::Images::N_CLASS(NGrayscaleImage) *pLeftIris, Neurotec::Images::N_CLASS(NGrayscaleImage) *pRightIris, void *pParam);

	virtual ~N_CLASS(IrisCamera)()
	{
		Uninit();
	}

	::Neurotec::Devices::N_CLASS(NIrisScanner) * GetDevice() const
	{
		return GetObject<HandleType, ::Neurotec::Devices::N_CLASS(NIrisScanner)>(IrisCameraGetDevice, true, true);
	}

	N_CLASS(NString) GetId() const
	{
		return GetString(IrisCameraGetIdN);
	}

	bool IsCapturing()
	{
		NBool value;
		NCheck(IrisCameraIsCapturing(GetHandle(), &value));
		return value != 0;
	}

	void StartCapturing()
	{
		NCheck(IrisCameraStartCapturing(GetHandle()));
	}

	void StopCapturing()
	{
		NCheck(IrisCameraStopCapturing(GetHandle()));
	}

	void GetImages(::Neurotec::Images::N_CLASS(NGrayscaleImage) * * ppLeftIris, ::Neurotec::Images::N_CLASS(NGrayscaleImage) * * ppRightIris)
	{
		if (!ppLeftIris) NThrowArgumentNullException(N_T("ppLeftIris"));
		if (!ppRightIris) NThrowArgumentNullException(N_T("ppRightIris"));
		HNGrayscaleImage hLeftIris, hRightIris;
		NCheck(IrisCameraGetImages(GetHandle(), &hLeftIris, &hRightIris));
		::Neurotec::Images::N_CLASS(NGrayscaleImage) * pLeftIris = NULL;
		::Neurotec::Images::N_CLASS(NGrayscaleImage) * pRightIris = NULL;
		try
		{
			pLeftIris = FromHandle< ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(hLeftIris);
			pRightIris = FromHandle< ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(hRightIris);
			*ppLeftIris = pLeftIris;
			*ppRightIris = pRightIris;
		}
		catch (...)
		{
			UnrefOrDelete(hLeftIris, pLeftIris);
			UnrefOrDelete(hRightIris, pRightIris);
			throw;
		}
	}

	void AddIrisesAcquiredCallback(IrisesAcquiredCallback pCallback, void * pParam)
	{
		irisesAcquired.Add(pCallback, pParam);
	}

	void RemoveIrisesAcquiredCallback(IrisesAcquiredCallback pCallback, void * pParam)
	{
		irisesAcquired.Remove(pCallback, pParam);
	}

	N_DECLARE_OBJECT_CLASS(IrisCamera, NObject)

	friend class N_CLASS(IrisCameraMan);
};
#include <NReDeprecate.h>

}}

#endif // !IRIS_CAMERA_HPP_INCLUDED
