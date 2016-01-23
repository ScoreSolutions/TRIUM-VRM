#ifndef N_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_METHOD_DESCRIPTOR_HPP_INCLUDED

#include <NMemberDescriptor.hpp>
#include <NParameterDescriptor.hpp>
#include <NValue.hpp>
#include <NPropertyBag.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NMethodDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NMethodDescriptor) : public N_CLASS(NMemberDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NMethodDescriptor, NMemberDescriptor)

public:
	class ParameterCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NParameterDescriptor), N_CLASS(NMethodDescriptor), false>
	{
		ParameterCollection(N_CLASS(NMethodDescriptor) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NParameterDescriptor), N_CLASS(NMethodDescriptor), false>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNMethodDescriptor handle, NInt * pValue) const
		{
			return NMethodDescriptorGetParameterCount(handle, pValue);
		}

		virtual NResult GetNative(HNMethodDescriptor handle, NInt index, HNParameterDescriptor * phValue) const
		{
			return NMethodDescriptorGetParameter(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNMethodDescriptor, HNParameterDescriptor *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NMethodDescriptor);
	};

private:
	::std::auto_ptr<ParameterCollection> parameters;

	void Init()
	{
		parameters.reset(new ParameterCollection(this));
	}

protected:
	N_CLASS(NMethodDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NMemberDescriptor)(handle, claimHandle)
	{
		Init();
	}

public:
	N_CLASS(NParameterDescriptor) * GetReturnParameter() const
	{
		return GetObject<HandleType, N_CLASS(NParameterDescriptor)>(NMethodDescriptorGetReturnParameter);
	}

	N_CLASS(NValue) * Invoke(N_CLASS(NObject) * pObject, N_CLASS(NValue) * * arpParameters, NInt parameterCount) const
	{
		N_CLASS(NObjectArray)<N_CLASS(NValue)> parameters(arpParameters, parameterCount);
		HNValue hResult;
		NCheck(NMethodDescriptorInvoke(GetHandle(), ToHandle(pObject), parameters.GetPtr(), parameters.GetCount(), &hResult));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hResult);
		}
		catch (...)
		{
			Unref(hResult);
			throw;
		}
	}

	N_CLASS(NValue) * Invoke(N_CLASS(NObject) * pObject, N_CLASS(NPropertyBag) * pParameters) const
	{
		if (!pParameters) NThrowArgumentNullException(N_T("pParameters"));
		HNValue hResult;
		NCheck(NMethodDescriptorInvokeWithPropertyBag(GetHandle(), ToHandle(pObject), pParameters->GetHandle(), &hResult));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hResult);
		}
		catch (...)
		{
			Unref(hResult);
			throw;
		}
	}

	N_CLASS(NValue) * Invoke(N_CLASS(NObject) * pObject, const N_CLASS(NStringWrapper) parameters) const
	{
		HNValue hResult;
		NCheck(NMethodDescriptorInvokeWithStringN(GetHandle(), ToHandle(pObject), parameters.GetHandle(), &hResult));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hResult);
		}
		catch (...)
		{
			Unref(hResult);
			throw;
		}
	}

	ParameterCollection * GetParameters() const
	{
		return parameters.get();
	}
};

}}

#endif // !N_METHOD_DESCRIPTOR_HPP_INCLUDED
