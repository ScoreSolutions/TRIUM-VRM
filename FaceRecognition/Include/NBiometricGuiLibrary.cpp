#ifndef N_BIOMETRIC_GUI_LIBRARY_CPP_INCLUDED
#define N_BIOMETRIC_GUI_LIBRARY_CPP_INCLUDED

#include <NCoreLibrary.cpp>
#include <NMediaLibrary.cpp>
#include <NBiometricsLibrary.cpp>

#ifdef N_FRAMEWORK_WX
#include <wxNLView.hpp>
#include <wxNFView.hpp>

namespace Neurotec { namespace Biometrics { namespace Gui
{

DEFINE_EVENT_TYPE(wxEVT_MINUTIA_SELECTION_CHANGED)

}}}

#endif

#endif // !N_BIOMETRIC_GUI_LIBRARY_CPP_INCLUDED
