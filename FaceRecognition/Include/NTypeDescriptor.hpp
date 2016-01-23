#ifndef N_TYPE_DESCRIPTOR_HPP_INCLUDED
#define N_TYPE_DESCRIPTOR_HPP_INCLUDED

#include <NPropertyDescriptor.hpp>

namespace Neurotec { namespace ComponentModel
{
#include <NTypeDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NTypeDescriptor)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NTypeDescriptor)

public:
	static N_CLASS(NPropertyDescriptor) * * GetProperties(N_CLASS(NObject) * pObject, NInt * pCount)
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		HNPropertyDescriptor * arhProperties;
		NInt propertyCount;
		NCheck(NTypeDescriptorGetProperties(N_CLASS(NObject)::ToHandle(pObject), &arhProperties, &propertyCount));
		try
		{
			N_CLASS(NObjectArray)<N_CLASS(NPropertyDescriptor)> propertyDescriptors(arhProperties, propertyCount);
			arhProperties = NULL; propertyCount = 0;
			return propertyDescriptors.ToArray(pCount);
		}
		catch (...)
		{
			N_CLASS(NObject)::UnrefArray(arhProperties, propertyCount);
			throw;
		}
	}

	static N_CLASS(NPropertyDescriptor) * * GetProperties(N_CLASS(NType) * pType, NInt * pCount)
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		HNPropertyDescriptor * arhProperties;
		NInt propertyCount;
		NCheck(NTypeDescriptorGetPropertiesForType(N_CLASS(NObject)::ToHandle(pType), &arhProperties, &propertyCount));
		try
		{
			N_CLASS(NObjectArray)<N_CLASS(NPropertyDescriptor)> propertyDescriptors(arhProperties, propertyCount);
			arhProperties = NULL; propertyCount = 0;
			return propertyDescriptors.ToArray(pCount);
		}
		catch (...)
		{
			N_CLASS(NObject)::UnrefArray(arhProperties, propertyCount);
			throw;
		}
	}

	static N_CLASS(NString) GetDefaultPropertyName(N_CLASS(NObject) * pObject)
	{
		HNString hValue;
		NCheck(NTypeDescriptorGetDefaultPropertyName(N_CLASS(NObject)::ToHandle(pObject), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GetDefaultPropertyName(N_CLASS(NType) * pType)
	{
		HNString hValue;
		NCheck(NTypeDescriptorGetDefaultPropertyNameForType(N_CLASS(NObject)::ToHandle(pType), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};

}}

#endif // !N_TYPE_DESCRIPTOR_HPP_INCLUDED
