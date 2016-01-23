#ifndef N_SURVEILLANCE_LIBRARY_CPP_INCLUDED
#define N_SURVEILLANCE_LIBRARY_CPP_INCLUDED

#include <NCoreLibrary.cpp>
#include <NMediaLibrary.cpp>
#include <NBiometricsLibrary.cpp>
#include <NDevicesLibrary.cpp>

#include <NSurveillanceEventDetails.hpp>
#include <NSurveillance.hpp>

namespace Neurotec { namespace Surveillance
{

N_IMPLEMENT_OBJECT_CLASS_1(NSurveillanceEventDetails, NObject, NSurveillance)
N_IMPLEMENT_OBJECT_CLASS_1(NSurveillance, NObject, NSurveillanceEventDetails)

}}

#endif // !N_SURVEILLANCE_LIBRARY_CPP_INCLUDED
