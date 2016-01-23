#ifndef N_VIDEO_H_INCLUDED
#define N_VIDEO_H_INCLUDED

#include <NMedia.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NVideoGetInfo NMediaGetInfo
#define NVideoGetInfoA NMediaGetInfoA
#define NVideoGetInfoW NMediaGetInfoW

#ifdef N_CPP
}
#endif

#endif // !N_VIDEO_H_INCLUDED
