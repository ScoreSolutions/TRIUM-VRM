#ifndef NE_MATCHER_PARAMS_H_INCLUDED
#define NE_MATCHER_PARAMS_H_INCLUDED

#include <NParameters.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NEMP_MATCHING_THRESHOLD  10000
#define NEMP_MATCHING_SPEED      10001
#define NEMP_MAXIMAL_ROTATION    10002

typedef enum NemSpeed_
{
	nemsLow    =   0,
	nemsMedium = 128,
	nemsHigh   = 256
} NemSpeed;

N_DECLARE_TYPE(NemSpeed)

#ifdef N_CPP
}
#endif

#endif // !NE_MATCHER_PARAMS_H_INCLUDED
