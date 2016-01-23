#ifndef N_DEVICE_MANAGER_LIBRARY_CPP_INCLUDED
#define N_DEVICE_MANAGER_LIBRARY_CPP_INCLUDED

#include <NCoreLibrary.cpp>
#include <NMediaLibrary.cpp>
#include <NBiometricsLibrary.cpp>

#include <NDeviceManager.hpp>
#include <NDevices.hpp>
#include <FPScannerMan.hpp>
#include <FPScanner.hpp>
#include <CameraMan.hpp>
#include <Camera.hpp>
#include <IrisCameraMan.hpp>
#include <IrisCamera.hpp>
#include <NCaptureDevice.hpp>
#include <NCamera.hpp>
#include <NMicrophone.hpp>
#include <NBiometricDevice.hpp>
#include <NFScanner.hpp>
#include <NFingerScanner.hpp>
#include <NPalmScanner.hpp>
#include <NIrisScanner.hpp>
#include <NDeviceMethodDescriptor.hpp>
#include <NDevicePropertyDescriptor.hpp>
#include <NDeviceEventDescriptor.hpp>

using namespace ::Neurotec::ComponentModel;
using namespace ::Neurotec::Media;
using namespace ::Neurotec::Images;
using namespace ::Neurotec::Sound;
using namespace ::Neurotec::Plugins;

namespace Neurotec { namespace Devices
{

N_IMPLEMENT_OBJECT_CLASS_2(NDeviceManager, NObject, NDevice, NPluginManager)
N_IMPLEMENT_OBJECT_CLASS_4(NDevice, NObject, NCaptureDevice, NBiometricDevice, NDeviceManager, NPlugin)
N_IMPLEMENT_OBJECT_CLASS_3(NCaptureDevice, NDevice, NCamera, NMicrophone, NMediaSource)
N_IMPLEMENT_OBJECT_CLASS_1(NCamera, NCaptureDevice, NImage)
N_IMPLEMENT_OBJECT_CLASS_1(NMicrophone, NCaptureDevice, NSoundBuffer)
N_IMPLEMENT_OBJECT_CLASS_2(NBiometricDevice, NDevice, NFScanner, NIrisScanner)
N_IMPLEMENT_OBJECT_CLASS_3(NFScanner, NBiometricDevice, NFingerScanner, NPalmScanner, NImage)
N_IMPLEMENT_OBJECT_CLASS(NFingerScanner, NFScanner)
N_IMPLEMENT_OBJECT_CLASS(NPalmScanner, NFScanner)
N_IMPLEMENT_OBJECT_CLASS_1(NIrisScanner, NBiometricDevice, NImage)
namespace ComponentModel
{
N_IMPLEMENT_OBJECT_CLASS(NDeviceMethodDescriptor, NCustomMethodDescriptor)
N_IMPLEMENT_OBJECT_CLASS(NDevicePropertyDescriptor, NCustomPropertyDescriptor)
N_IMPLEMENT_OBJECT_CLASS(NDeviceEventDescriptor, NCustomEventDescriptor)
}

}}

namespace Neurotec { namespace DeviceManager
{

#include <NNoDeprecate.h>
::std::auto_ptr<N_CLASS(FPScannerMan)::FPScannerCollection> N_CLASS(FPScannerMan)::scanners(new N_CLASS(FPScannerMan)::FPScannerCollection());
N_CLASS(NEvent1)<N_CLASS(FPScanner) *> N_CLASS(FPScannerMan)::scannerAdded;
N_CLASS(NEvent1)<N_CLASS(FPScanner) *> N_CLASS(FPScannerMan)::scannerRemoved;
N_CLASS(FPScannerMan)::Initializer N_CLASS(FPScannerMan)::initializer;
::std::auto_ptr<N_CLASS(CameraMan)::CameraCollection> N_CLASS(CameraMan)::cameras(new N_CLASS(CameraMan)::CameraCollection());
::std::auto_ptr<N_CLASS(IrisCameraMan)::IrisCameraCollection> N_CLASS(IrisCameraMan)::cameras(new N_CLASS(IrisCameraMan)::IrisCameraCollection());
N_IMPLEMENT_OBJECT_CLASS(FPScanner, NObject)
N_IMPLEMENT_OBJECT_CLASS(Camera, NObject)
N_IMPLEMENT_OBJECT_CLASS(IrisCamera, NObject)
#include <NReDeprecate.h>

}}

#endif // !N_DEVICE_MANAGER_LIBRARY_CPP_INCLUDED
