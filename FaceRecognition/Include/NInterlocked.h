#ifndef N_INTERLOCKED_H_INCLUDED
#define N_INTERLOCKED_H_INCLUDED

#include <NWindows.h>

#ifdef N_CPP
extern "C"
{
#endif

#if defined(N_WINDOWS)

#ifdef N_WINDOWS_CE
	#define N_INTERLOCKED_VOLATILE
#else
	#define N_INTERLOCKED_VOLATILE volatile
#endif

#define NInterlockedCompareExchange(pDst, exch, comp) (NInt)InterlockedCompareExchange((long N_INTERLOCKED_VOLATILE *)pDst, (long)(exch), (long)(comp))
#define NInterlockedCompareExchangePointer(pDst, exch, comp) InterlockedCompareExchangePointer(pDst, exch, comp)
#define NInterlockedIncrement(pDst) (NInt)InterlockedIncrement((long N_INTERLOCKED_VOLATILE *)pDst)
#define NInterlockedDecrement(pDst) (NInt)InterlockedDecrement((long N_INTERLOCKED_VOLATILE *)pDst)
#define NInterlockedAdd(pDst, val) ((NInt)InterlockedExchangeAdd((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val)) + (NInt)val)
#define NInterlockedAnd(pDst, val) (NInt)InterlockedAnd((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))
#define NInterlockedOr(pDst, val) (NInt)InterlockedOr((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))
#define NInterlockedXor(pDst, val) (NInt)InterlockedXor((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))
#define NInterlockedExchange(pDst, exch) (NInt)InterlockedExchange((long N_INTERLOCKED_VOLATILE *)pDst, (long)(exch))
#define NInterlockedExchangePointer(pDst, exch) InterlockedExchangePointer(pDst, exch)
#define NInterlockedExchangeAdd(pDst, val) (NInt)InterlockedExchangeAdd((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))

#elif defined(N_GCC) && (!defined(N_ARM) || N_GCC_VERSION >= 40400)

#define NInterlockedCompareExchange(pDst, exch, comp) __sync_val_compare_and_swap(pDst, comp, exch)
#define NInterlockedCompareExchangePointer(pDst, exch, comp) __sync_val_compare_and_swap(pDst, comp, exch)
#define NInterlockedIncrement(pDst) __sync_add_and_fetch(pDst, 1)
#define NInterlockedDecrement(pDst) __sync_sub_and_fetch(pDst, 1)
#define NInterlockedAdd(pDst, val) __sync_add_and_fetch(pDst, val)
#define NInterlockedAnd(pDst, val) __sync_fetch_and_and(pDst, val)
#define NInterlockedOr(pDst, val) __sync_fetch_and_or(pDst, val)
#define NInterlockedXor(pDst, val) __sync_fetch_and_xor(pDst, val)
#define NInterlockedExchange(pDst, exch) __sync_lock_test_and_set(pDst, exch)
#define NInterlockedExchangePointer(pDst, exch) __sync_lock_test_and_set(pDst, exch)
#define NInterlockedExchangeAdd(pDst, val) __sync_fetch_and_add(pDst, val)

#else

#define N_SLOW_INTERLOCKED

#include <NTypes.h>

NInt NInterlockedCompareExchange(NInt volatile * pDst, NInt exch, NInt comp);
void * NInterlockedCompareExchangePointer(void * volatile * pDst, void * exch, void * comp);
NInt NInterlockedIncrement(NInt volatile * pDst);
NInt NInterlockedDecrement(NInt volatile * pDst);
NInt NInterlockedAdd(NInt volatile * pDst, NInt val);
NInt NInterlockedAnd(NInt volatile * pDst, NInt val);
NInt NInterlockedOr(NInt volatile * pDst, NInt val);
NInt NInterlockedXor(NInt volatile * pDst, NInt val);
NInt NInterlockedExchange(NInt volatile * pDst, NInt exch);
void * NInterlockedExchangePointer(void * volatile * pDst, void * exch);
NInt NInterlockedExchangeAdd(NInt volatile * pDst, NInt val);

#endif

#ifdef N_CPP
}
#endif

#endif // !N_INTERLOCKED_H_INCLUDED
