#ifndef NDM_VIRTUAL_LIBRARY_CPP_INCLUDED
#define NDM_VIRTUAL_LIBRARY_CPP_INCLUDED

#include <NCoreLibrary.cpp>
#include <NMediaLibrary.cpp>
#include <NBiometricsLibrary.cpp>

#include <NVirtualDevice.hpp>

using namespace ::Neurotec::Media;

namespace Neurotec { namespace Devices { namespace Virtual
{

N_IMPLEMENT_OBJECT_CLASS_1(NVirtualDevice, NObject, NMediaFormat)

}}}

#endif //!NDM_VIRTUAL_LIBRARY_CPP_INCLUDED
