#ifndef N_CUSTOM_PARAMETER_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_PARAMETER_DESCRIPTOR_HPP_INCLUDED

#include <NParameterDescriptor.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NCustomParameterDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NCustomParameterDescriptor) : public N_CLASS(NParameterDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NCustomParameterDescriptor, NParameterDescriptor)

private:
	static HNCustomParameterDescriptor Create(const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pParameterType, NAttributes attributes, const N_CLASS(NStringWrapper) & format,
		N_CLASS(NValue) * pDefaultValue, N_CLASS(NValue) * pMinValue, N_CLASS(NValue) * pMaxValue, N_CLASS(NNameValuePair) * arStdValues, NInt stdValueCount, N_CLASS(NValue) * pData)
	{
		if (!pParameterType) NThrowArgumentNullException(N_T("pParameterType"));
		HNCustomParameterDescriptor handle;
		NCheck(NCustomParameterDescriptorCreate(name.GetHandle(), pParameterType->GetHandle(), attributes, format.GetHandle(),
			ToHandle(pDefaultValue), ToHandle(pMinValue), ToHandle(pMaxValue), arStdValues, stdValueCount, ToHandle(pData),
			&handle));
		return handle;
	}

	N_CLASS(NCustomParameterDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NParameterDescriptor)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NCustomParameterDescriptor)(const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pParameterType, NAttributes attributes, const N_CLASS(NStringWrapper) & format,
		N_CLASS(NValue) * pDefaultValue, N_CLASS(NValue) * pMinValue, N_CLASS(NValue) * pMaxValue, N_CLASS(NNameValuePair) * arStdValues, NInt stdValueCount, N_CLASS(NValue) * pData)
		: N_CLASS(NParameterDescriptor)(Create(name, pParameterType, attributes, format, pDefaultValue, pMinValue, pMaxValue, arStdValues, stdValueCount, pData), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NCustomParameterDescriptor);
	}

	N_CLASS(NValue) * GetData() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NCustomParameterDescriptorGetData);
	}

};

}}


#endif // !N_CUSTOM_PARAMETER_DESCRIPTOR_HPP_INCLUDED
