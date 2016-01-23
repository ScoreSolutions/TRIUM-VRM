#ifndef N_PARAMETER_DESCRIPTOR_HPP_INCLUDED
#define N_PARAMETER_DESCRIPTOR_HPP_INCLUDED

#include <NDescriptor.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NParameterDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NParameterDescriptor) : public N_CLASS(NDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NParameterDescriptor, NDescriptor)

public:
	class StdValueCollection : public ::Neurotec::Collections::N_CLASS(NStructReadOnlyCollection)<N_CLASS(NNameValuePair), N_CLASS(NParameterDescriptor), true>
	{
		StdValueCollection(N_CLASS(NParameterDescriptor) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructReadOnlyCollection)<N_CLASS(NNameValuePair), N_CLASS(NParameterDescriptor), true>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNParameterDescriptor handle, NInt * pValue) const
		{
			return NParameterDescriptorGetStdValueCount(handle, pValue);
		}

		virtual NResult GetNative(HNParameterDescriptor handle, NInt index, N_CLASS(NNameValuePair) * pValue) const
		{
			return NParameterDescriptorGetStdValue(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNParameterDescriptor, N_CLASS(NNameValuePair) *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NParameterDescriptor);
	};

private:
	::std::auto_ptr<StdValueCollection> stdValues;

protected:
	N_CLASS(NParameterDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NDescriptor)(handle, claimHandle)
	{
		stdValues.reset(new StdValueCollection(this));
	}

public:
	N_CLASS(NType) * GetParameterType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NParameterDescriptorGetParameterType, true, true);
	}

	N_CLASS(NString) GetFormat() const
	{
		return GetString<HandleType>(NParameterDescriptorGetFormat);
	}

	N_CLASS(NValue) * GetDefaultValue() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NParameterDescriptorGetDefaultValue);
	}

	N_CLASS(NValue) * GetMinValue() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NParameterDescriptorGetMinValue);
	}

	N_CLASS(NValue) * GetMaxValue() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NParameterDescriptorGetMaxValue);
	}

	StdValueCollection * GetStdValues()
	{
		return stdValues.get();
	}
};

}}

#endif // !N_PARAMETER_DESCRIPTOR_HPP_INCLUDED
