#ifndef N_TEMPLATES_H_INCLUDED
#define N_TEMPLATES_H_INCLUDED

#include <NBiometrics.h>
#include <NBiometricTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NTemplatesGetInfoA NBiometricsGetInfoA
#define NTemplatesGetInfoW NBiometricsGetInfoW
#define NTemplatesGetInfo NBiometricsGetInfo

#ifdef N_MSVC
	#pragma deprecated("NTemplatesGetInfoA", "NTemplatesGetInfoW", "NTemplatesGetInfo")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_TEMPLATES_H_INCLUDED
