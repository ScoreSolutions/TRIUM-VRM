#ifndef N_WEAK_REFERENCE_HPP_INCLUDED
#define N_WEAK_REFERENCE_HPP_INCLUDED

#include <NObject.hpp>
namespace Neurotec { namespace Internal
{
#include <NWeakReference.h>
}}

namespace Neurotec
{

class N_CLASS(NWeakReference) : private Internal::NWeakReference
{
	N_DECLARE_PRIMITIVE_CLASS(NWeakReference)

public:
	N_CLASS(NWeakReference)()
	{
		NCheck(Internal::NWeakReferenceInit(this));
	}

	N_CLASS(NWeakReference)(N_CLASS(NObject) * pValue)
	{
		memset(this, 0, sizeof(N_CLASS(NWeakReference)));
		NCheck(Internal::NWeakReferenceInitWith(this, N_CLASS(NObject)::ToHandle(pValue)));
	}

	~N_CLASS(NWeakReference)()
	{
		NCheck(Internal::NWeakReferenceDispose(this));
	}

	N_CLASS(NObject) * Get()
	{
		HNObject hValue;
		NCheck(Internal::NWeakReferenceGet(this, &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NObject)>(hValue, true, false);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}

	void Set(N_CLASS(NObject) * pValue)
	{
		NCheck(Internal::NWeakReferenceSet(this, N_CLASS(NObject)::ToHandle(pValue)));
	}
};

}

#endif // !N_WEAK_REFERENCE_HPP_INCLUDED
