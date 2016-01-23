#ifndef N_MATCHERS_H_INCLUDED
#define N_MATCHERS_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NMatchersGetInfoA NBiometricsGetInfoA
#define NMatchersGetInfoW NBiometricsGetInfoW
#define NMatchersGetInfo NBiometricsGetInfo

#ifdef N_MSVC
	#pragma deprecated("NMatchersGetInfoA", "NMatchersGetInfoW", "NMatchersGetInfo")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_MATCHERS_H_INCLUDED
