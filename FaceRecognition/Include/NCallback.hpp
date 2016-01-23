#ifndef N_CALLBACK_HPP_INCLUDED
#define N_CALLBACK_HPP_INCLUDED

#include <NTypes.hpp>
namespace Neurotec
{
#include <NCallback.h>
}

namespace Neurotec
{

class N_CLASS(NCallback)
{
private:
	HNCallback handle;

	void Set(HNCallback hValue)
	{
		if (handle != NULL)
		{
			NCheck(NCallbackFree(handle));
		}
		handle = hValue;
	}

public:
	static bool Equals(const N_CLASS(NCallback) & value, const N_CLASS(NCallback) & otherValue)
	{
		NBool r;
		NCheck(NCallbackEquals(value.handle, otherValue.handle, &r));
		return r != 0;
	}

	N_CLASS(NCallback)()
		: handle(NULL)
	{
	}

	N_CLASS(NCallback)(const N_CLASS(NCallback) & other)
		: handle(NULL)
	{
		*this = other;
	}

	N_CLASS(NCallback)(HNCallback hValue, bool ownsHandle)
		: handle(ownsHandle ? hValue : NULL)
	{
		if (!ownsHandle) NCheck(NCallbackClone(hValue, &handle));
	}

	N_CLASS(NCallback)(void * pProc, void * pParam)
		: handle(NULL)
	{
		NCheck(NCallbackCreateRaw(pProc, pParam, &handle));
	}

	template<typename T> N_CLASS(NCallback)(T pProc, void * pParam)
		: handle(NULL)
	{
		NCheck(NCallbackCreate(pProc, pParam, &handle));
	}

	N_CLASS(NCallback)(void * pProc, void * pParam, NPointerFreeProc pFree, NPointerGetHashCodeProc pGetHashCode, NPointerEqualsProc pEquals)
		: handle(NULL)
	{
		NCheck(NCallbackCreateCustomRaw(pProc, pParam, pFree, pGetHashCode, pEquals, &handle));
	}

	template<typename T> N_CLASS(NCallback)(T pProc, void * pParam, NPointerFreeProc pFree, NPointerGetHashCodeProc pGetHashCode, NPointerEqualsProc pEquals)
		: handle(NULL)
	{
		NCheck(NCallbackCreateCustom(pProc, pParam, pFree, pGetHashCode, pEquals, &handle));
	}

	~N_CLASS(NCallback)()
	{
		Set(NULL);
	}

	HNCallback GetHandle() const
	{
		return handle;
	}

	HNCallback CloneHandle() const
	{
		HNCallback hValue;
		NCheck(NCallbackClone(handle, &hValue));
		return hValue;
	}

	bool IsNull() const
	{
		return handle == NULL;
	}

	NInt GetHashCode() const
	{
		NInt value;
		NCheck(NCallbackGetHashCode(handle, &value));
		return value;
	}

	bool Equals(const N_CLASS(NCallback) & value) const
	{
		NBool r;
		NCheck(NCallbackEquals(handle, value.handle, &r));
		return r != 0;
	}

	void * GetProcRaw() const
	{
		return NCallbackGetProcRaw(handle);
	}

	template<typename T> T GetProc() const
	{
		return NCallbackGetProc(T, handle);
	}

	void * GetParam() const
	{
		return NCallbackGetParam(handle);
	}

	N_CLASS(NCallback) & operator=(const N_CLASS(NCallback) & other)
	{
		return *this = other.handle;
	}

	N_CLASS(NCallback) & operator=(HNCallback hOtherValue)
	{
		if (handle != hOtherValue)
		{
			HNCallback hValue = NULL;
			if (hOtherValue)
			{
				NCheck(NCallbackClone(hOtherValue, &hValue));
			}
			Set(hValue);
		}
		return *this;
	}
};

inline bool operator==(const N_CLASS(NCallback) & value1, const N_CLASS(NCallback) & value2)
{
	return N_CLASS(NCallback)::Equals(value1, value2);
}

inline bool operator!=(const N_CLASS(NCallback) & value1, const N_CLASS(NCallback) & value2)
{
	return !N_CLASS(NCallback)::Equals(value1, value2);
}

} // namespace Neurotec

#endif // !N_CALLBACK_HPP_INCLUDED
