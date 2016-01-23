#ifndef N_EXTRACTORS_H_INCLUDED
#define N_EXTRACTORS_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NExtractorsGetInfoA NBiometricsGetInfoA
#define NExtractorsGetInfoW NBiometricsGetInfoW
#define NExtractorsGetInfo NBiometricsGetInfo

#ifdef N_MSVC
	#pragma deprecated("NExtractorsGetInfoA", "NExtractorsGetInfoW", "NExtractorsGetInfo")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_EXTRACTORS_H_INCLUDED
