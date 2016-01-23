#ifndef FP_SCANNER_MAN_HPP_INCLUDED
#define FP_SCANNER_MAN_HPP_INCLUDED

#include <FPScanner.hpp>
#include <NDeviceManager.hpp>
namespace Neurotec { namespace DeviceManager
{
using ::Neurotec::Devices::HNDeviceManager;
#include <FPScannerMan.h>
}}
#include <NEvent.hpp>

namespace Neurotec { namespace DeviceManager
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Devices::" N_STRINGIZEA(N_CLASS(NDeviceManager)) " instead")
N_CLASS(FPScannerMan)
{
	N_DECLARE_STATIC_OBJECT_CLASS(FPScannerMan)

public:
	typedef void (* ScannerCallback)(N_CLASS(FPScanner) * pScanner, void * pParam);

	class FPScannerCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(FPScanner), N_CLASS(NObject), true, true>
	{
	private:
		FPScannerCollection()
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(FPScanner), N_CLASS(NObject), true, true>(NULL)
		{
		}

	protected:
		virtual NResult GetCountNative(HNObject, NInt * pValue) const
		{
			return FPScannerManGetScannerCount(pValue);
		}

		virtual NResult GetNative(HNObject, NInt index, HFPScanner * phValue) const
		{
			return FPScannerManGetScanner(index, phValue);
		}

		virtual NResult GetAllNative(HNObject, HFPScanner *, NInt) const
		{
			NThrowNotImplementedException();
		}

	public:
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(FPScanner), N_CLASS(NObject), true, true>::Get;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(FPScanner), N_CLASS(NObject), true, true>::operator[];

		N_CLASS(FPScanner) * Get(const N_CLASS(NStringWrapper) & id) const
		{
			HFPScanner handle;
			NCheck(FPScannerManGetScannerByIdN(id.GetHandle(), &handle));
			return N_CLASS(NObject)::FromHandle<N_CLASS(FPScanner)>(handle, false, true);
		}

		N_CLASS(FPScanner) * operator[](const N_CLASS(NStringWrapper) & id) const
		{
			return Get(id);
		}

		friend class N_CLASS(FPScannerMan);
	};

private:
	static ::std::auto_ptr<FPScannerCollection> scanners;
	static N_CLASS(NEvent1)<N_CLASS(FPScanner) *> scannerAdded;
	static N_CLASS(NEvent1)<N_CLASS(FPScanner) *> scannerRemoved;

	static struct Initializer
	{
		Initializer()
		{
			NCheck(FPScannerManSetScannerAddedCallbackEx(OnScannerAdded, NULL));
			NCheck(FPScannerManSetScannerRemovedCallbackEx(OnScannerRemoved, NULL));
		}

		~Initializer()
		{
			NResult res = N_OK;
			try
			{
				NCheck(FPScannerManSetScannerAddedCallbackEx(NULL, NULL));
			}
			N_EXCEPTION_CATCH_AND_SUPPRESS(res)
			try
			{
				NCheck(FPScannerManSetScannerRemovedCallbackEx(NULL, NULL));
			}
			N_EXCEPTION_CATCH_AND_SUPPRESS(res)
		}
	} initializer;

	static void N_API OnScannerAdded(HFPScanner hScanner, void *)
	{
		scannerAdded(N_CLASS(NObject)::FromHandle<N_CLASS(FPScanner)>(hScanner, false, true));
	}

	static void N_API OnScannerRemoved(HFPScanner hScanner, void *)
	{
		scannerRemoved(N_CLASS(NObject)::FromHandle<N_CLASS(FPScanner)>(hScanner, false, true));
	}

public:
	static N_CLASS(NString) GetAvailableModules()
	{
		HNString hValue;
		NCheck(FPScannerManGetAvailableModulesN(&hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static void Initialize()
	{
		NCheck(FPScannerManInitialize());
	}

	static void Initialize(const N_CLASS(NStringWrapper) & modules)
	{
		NCheck(FPScannerManInitializeWithModulesN(modules.GetHandle()));
	}

	static void Uninitialize()
	{
		FPScannerManUninitialize();
	}

	::Neurotec::Devices::N_CLASS(NDeviceManager) * GetDeviceManager()
	{
		return N_CLASS(NObject)::GetObject< ::Neurotec::Devices::N_CLASS(NDeviceManager)>(FPScannerManGetDeviceManager, true, true);
	}

	N_CLASS(FPScanner) * GetScannerFromDevice(::Neurotec::Devices::N_CLASS(NFScanner) * pDevice)
	{
		HFPScanner hScanner;
		NCheck(FPScannerManGetScannerFromDevice(N_CLASS(NObject)::ToHandle(pDevice), &hScanner));
		return N_CLASS(NObject)::FromHandle<N_CLASS(FPScanner)>(hScanner, false, true);
	}

	static FPScannerCollection * GetScanners()
	{
		return scanners.get();
	}

	static void AddScannerAddedCallback(ScannerCallback pCallback, void * pParam)
	{
		scannerAdded.Add(pCallback, pParam);
	}

	static void RemoveScannerAddedCallback(ScannerCallback pCallback, void * pParam)
	{
		scannerAdded.Remove(pCallback, pParam);
	}

	static void AddScannerRemovedCallback(ScannerCallback pCallback, void * pParam)
	{
		scannerRemoved.Add(pCallback, pParam);
	}

	static void RemoveScannerRemovedCallback(ScannerCallback pCallback, void * pParam)
	{
		scannerRemoved.Remove(pCallback, pParam);
	}

};
#include <NReDeprecate.h>

}}

#endif // !FP_SCANNER_MAN_HPP_INCLUDED
