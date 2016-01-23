#include <NTypes.hpp>

#ifndef N_MEMORY_HPP_INCLUDED
#define N_MEMORY_HPP_INCLUDED

#include <memory.h>
#include <string.h>
namespace Neurotec
{
#include <NMemory.h>
}
#include <NNoDeprecate.h>
#include <NReDeprecate.h>

namespace Neurotec
{

#undef NClear
#undef NAlignedAlloc
#undef NAlignedCAlloc
#undef NAlignedReAlloc

inline NResult NClear(void * pBlock, NSizeType size)
{
	return NFill(pBlock, 0, size);
}

inline NResult NAlignedAlloc(NSizeType size, NSizeType alignment, void * * ppBlock)
{
	return NAlignedOffsetAlloc(size, alignment, 0, ppBlock);
}

inline NResult NAlignedCAlloc(NSizeType size, NSizeType alignment, void * * ppBlock)
{
	return NAlignedOffsetCAlloc(size, alignment, 0, ppBlock);
}

inline NResult NAlignedReAlloc(void * * ppBlock, NSizeType size, NSizeType alignment)
{
	return NAlignedOffsetReAlloc(ppBlock, size, alignment, 0);
}

inline void * NAlloc(NSizeType size)
{
	void * pBlock;
	NCheck(NAlloc(size, &pBlock));
	return pBlock;
}

inline void * NCAlloc(NSizeType size)
{
	void * pBlock;
	NCheck(NCAlloc(size, &pBlock));
	return pBlock;
}

inline void * NReAlloc(void * pBlock, NSizeType size)
{
	NCheck(NReAlloc(&pBlock, size));
	return pBlock;
}

inline void NCopyMemory(void * pDstBlock, const void * pSrcBlock, NSizeType size)
{
	NCheck(NCopy(pDstBlock, pSrcBlock, size));
}

inline void NMoveMemory(void * pDstBlock, const void * pSrcBlock, NSizeType size)
{
	NCheck(NMove(pDstBlock, pSrcBlock, size));
}

inline void NFillMemory(void * pBlock, NByte value, NSizeType size)
{
	NCheck(NFill(pBlock, value, size));
}

inline void NClearMemory(void * pBlock, NSizeType size)
{
	NCheck(NClear(pBlock, size));
}

inline NInt NCompare(const void * pBlock1, const void * pBlock2, NSizeType size)
{
	NInt result;
	NCheck(NCompare(pBlock1, pBlock2, size, &result));
	return result;
}

inline void * NAlignedAlloc(NSizeType size, NSizeType alignment, NSizeType offset = 0)
{
	void * pBlock;
	NCheck(NAlignedOffsetAlloc(size, alignment, offset, &pBlock));
	return pBlock;
}

inline void * NAlignedCAlloc(NSizeType size, NSizeType alignment, NSizeType offset = 0)
{
	void * pBlock;
	NCheck(NAlignedOffsetCAlloc(size, alignment, offset, &pBlock));
	return pBlock;
}

inline void * NAlignedReAlloc(void * pBlock, NSizeType size, NSizeType alignment, NSizeType offset = 0)
{
	NCheck(NAlignedOffsetReAlloc(&pBlock, size, alignment, offset));
	return pBlock;
}

class NAutoFree
{
private:
	void * ptr;

public:
	explicit NAutoFree(void * ptr = NULL)
		: ptr(ptr)
	{
	}

	NAutoFree(NAutoFree & value)
		: ptr(value.Release())
	{
	}

	~NAutoFree()
	{
		Reset();
	}

	NAutoFree & operator=(NAutoFree & value)
	{
		Reset(value.Release());
		return (*this);
	}

	void * Get() const
	{
		return ptr;
	}

	void * Release()
	{
		void * ptr = this->ptr;
		this->ptr = NULL;
		return ptr;
	}

	void Reset(void * ptr = NULL)
	{
		if (ptr != this->ptr)
		{
			NFree(this->ptr);
			this->ptr = ptr;
		}
	}
};

template<typename T> class NAutoArray
{
private:
	T * ptr;
	NInt count;

public:
	NAutoArray()
		: ptr(NULL), count(0)
	{
	}

	NAutoArray(T * ptr, NInt count)
		: ptr(ptr), count(count)
	{
	}

	NAutoArray(NInt count)
		: ptr((T *)NCAlloc(sizeof(T) * count)), count(count)
	{
	}

	NAutoArray(NAutoArray & value)
		: ptr(value.ptr), count(value.count)
	{
		value.Release();
	}

	~NAutoArray()
	{
		Reset();
	}

	NAutoArray & operator=(NAutoArray & value)
	{
		NInt count = value.count;
		Reset(value.Release(), count);
		return (*this);
	}

	T * operator->() const
	{
		return Get();
	}

	T & operator*() const
	{
		return *Get();
	}

	T & operator[](int index) const
	{
		return Get()[index];
	}

	T * Get() const
	{
		return ptr;
	}

	T & Get(int index) const
	{
		return ptr[index];
	}

	int GetCount() const
	{
		return count;
	}

	T * Release()
	{
		T * ptr = this->ptr;
		this->ptr = NULL;
		count = 0;
		return ptr;
	}

	void Reset()
	{
		Reset(NULL, 0);
	}

	void Reset(T * ptr, NInt count)
	{
		if (ptr != this->ptr)
		{
			if (this->ptr)
			{
				NFree(this->ptr);
			}
			this->ptr = ptr;
		}
		this->count = count;
	}
};

#include <NNoDeprecate.h>
template<typename T> class auto_array
{
private:
	T * ptr;
	int count;

public:
	auto_array()
		: ptr(NULL), count(0)
	{
	}

	auto_array(T * ptr, int count)
		: ptr(ptr), count(count)
	{
	}

	auto_array(int count)
		: ptr(new T[count]), count(count)
	{
	}

	auto_array(auto_array<T> & value)
		: ptr(value.ptr), count(value.count)
	{
		value.release();
	}

	~auto_array()
	{
		reset();
	}

	auto_array & operator=(auto_array & value)
	{
		int count = value.count;
		reset(value.release(), count);
		return (*this);
	}

	T * operator->() const
	{
		return get();
	}

	T & operator*() const
	{
		return *get();
	}

	T & operator[](int index) const
	{
		return get()[index];
	}

	T * get() const
	{
		return ptr;
	}

	T & get(int index) const
	{
		return ptr[index];
	}

	int size() const
	{
		return count;
	}

	T * release()
	{
		T * ptr = this->ptr;
		this->ptr = NULL;
		count = 0;
		return ptr;
	}

	void reset()
	{
		reset(NULL, 0);
	}

	void reset(T * ptr, int count)
	{
		if (ptr != this->ptr)
		{
			if (this->ptr)
			{
				delete[] this->ptr;
			}
			this->ptr = ptr;
		}
		this->count = count;
	}
};

template<typename T> class auto_ptr_array
{
private:
	T * * ptrs;
	int count;

public:
	auto_ptr_array()
		: ptrs(NULL), count(0)
	{
	}

	auto_ptr_array(T * * ptrs, int count)
		: ptrs(ptrs), count(count)
	{
	}

	auto_ptr_array(auto_ptr_array<T> & value)
		: ptrs(value.get()), count(value.size())
	{
		value.release();
	}

	~auto_ptr_array()
	{
		reset();
	}

	auto_ptr_array & operator=(auto_ptr_array & value)
	{
		reset(value.get(), value.size());
		value.release();
		return (*this);
	}

	T * * operator->() const
	{
		return get();
	}

	T * & operator*() const
	{
		return *get();
	}

	T * & operator[](int index) const
	{
		return get()[index];
	}

	T * * get() const
	{
		return ptrs;
	}

	T * & get(int index) const
	{
		return ptrs[index];
	}

	int size() const
	{
		return count;
	}

	T * * release()
	{
		T * * ptrs = this->ptrs;
		this->ptrs = NULL;
		this->count = 0;
		return ptrs;
	}

	void reset()
	{
		reset(NULL, 0);
	}

	void reset(T * * ptrs, int count)
	{
		if (ptrs != this->ptrs)
		{
			if (this->ptrs)
			{
				for (int i = 0; i < this->count; i++)
				{
					delete this->ptrs[i];
				}
				delete[] this->ptrs;
			}
			this->ptrs = ptrs;
		}
		this->count = count;
	}
};
#include <NReDeprecate.h>

}

#endif // !N_MEMORY_HPP_INCLUDED
