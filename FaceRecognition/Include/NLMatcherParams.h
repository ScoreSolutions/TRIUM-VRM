#ifndef NL_MATCHER_PARAMS_H_INCLUDED
#define NL_MATCHER_PARAMS_H_INCLUDED

#include <NParameters.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NLMP_MATCHING_THRESHOLD  10000
#define NLMP_MATCHING_SPEED      10001

typedef enum NlmSpeed_
{
	nlmsLow    =   0,
	nlmsHigh   = 256
} NlmSpeed;

N_DECLARE_TYPE(NlmSpeed)

#ifdef N_CPP
}
#endif

#endif // !NL_MATCHER_PARAMS_H_INCLUDED
