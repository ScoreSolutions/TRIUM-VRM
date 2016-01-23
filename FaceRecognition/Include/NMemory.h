#ifndef N_MEMORY_H_INCLUDED
#define N_MEMORY_H_INCLUDED

#include <NTypes.h>
#include <memory.h>
#include <string.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NMemoryType_
{
	nmmtNone = 0,
	nmmtDefault = 1,
	nmmtAligned = 2,
	nmmtStandard = 3,
	nmmtWin32Local = 4,
	nmmtWin32Global = 5,
	nmmtCustom = 15
} NMemoryType;

N_DECLARE_TYPE(NMemoryType)

NBool N_API NMemoryTypeIsValid(NMemoryType value);
NBool N_API NMemoryTypeIsValidForFree(NMemoryType value);

NResult N_API NAlloc(NSizeType size, void * * ppBlock);
NResult N_API NCAlloc(NSizeType size, void * * ppBlock);
NResult N_API NReAlloc(void * * ppBlock, NSizeType size);
void N_API NFree(void * pBlock);
void N_API NFreeEx(void * pBlock, NMemoryType memoryType);

NResult N_API NCopy(void * pDstBlock, const void * pSrcBlock, NSizeType size);
NResult N_API NMove(void * pDstBlock, const void * pSrcBlock, NSizeType size);
NResult N_API NFill(void * pBlock, NByte value, NSizeType size);
#define NClear(pBlock, size) NFill(pBlock, 0, size)
NResult N_API NCompare(const void * pBlock1, const void * pBlock2, NSizeType size, NInt * pResult);

NResult N_API NAlignedOffsetAlloc(NSizeType size, NSizeType alignment, NSizeType offset, void * * ppBlock);
NResult N_API NAlignedOffsetCAlloc(NSizeType size, NSizeType alignment, NSizeType offset, void * * ppBlock);
NResult N_API NAlignedOffsetReAlloc(void * * ppBlock, NSizeType size, NSizeType alignment, NSizeType offset);
void N_API NAlignedFree(void * pBlock);
#define NAlignedAlloc(size, alignment, ppBlock) NAlignedOffsetAlloc(size, alignment, 0, ppBlock)
#define NAlignedCAlloc(size, alignment, ppBlock) NAlignedOffsetCAlloc(size, alignment, 0, ppBlock)
#define NAlignedReAlloc(ppBlock, size, alignment) NAlignedOffsetReAlloc(ppBlock, size, alignment, 0)

#ifdef N_CPP
}
#endif

#endif // !N_MEMORY_H_INCLUDED
