#ifndef N_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_PROPERTY_DESCRIPTOR_HPP_INCLUDED

#include <NMemberDescriptor.hpp>
#include <NValue.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NPropertyDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NPropertyDescriptor) : public N_CLASS(NMemberDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NPropertyDescriptor, NMemberDescriptor)

public:
	class StdValueCollection : public ::Neurotec::Collections::N_CLASS(NStructReadOnlyCollection)<N_CLASS(NNameValuePair), N_CLASS(NPropertyDescriptor), true>
	{
		StdValueCollection(N_CLASS(NPropertyDescriptor) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructReadOnlyCollection)<N_CLASS(NNameValuePair), N_CLASS(NPropertyDescriptor), true>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNPropertyDescriptor handle, NInt * pValue) const
		{
			return NPropertyDescriptorGetStdValueCount(handle, pValue);
		}

		virtual NResult GetNative(HNPropertyDescriptor handle, NInt index, N_CLASS(NNameValuePair) * pValue) const
		{
			return NPropertyDescriptorGetStdValue(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNPropertyDescriptor, N_CLASS(NNameValuePair) *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NPropertyDescriptor);
	};

private:
	::std::auto_ptr<StdValueCollection> stdValues;

protected:
	N_CLASS(NPropertyDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NMemberDescriptor)(handle, claimHandle)
	{
		stdValues.reset(new StdValueCollection(this));
	}

public:
	N_CLASS(NType) * GetPropertyType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NPropertyDescriptorGetPropertyType, true, true);
	}

	N_CLASS(NString) GetFormat() const
	{
		return GetString<HandleType>(NPropertyDescriptorGetFormat);
	}

	N_CLASS(NValue) * GetDefaultValue() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NPropertyDescriptorGetDefaultValue);
	}

	N_CLASS(NValue) * GetMinValue() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NPropertyDescriptorGetMinValue);
	}

	N_CLASS(NValue) * GetMaxValue() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NPropertyDescriptorGetMaxValue);
	}

	StdValueCollection * GetStdValues()
	{
		return stdValues.get();
	}

	N_CLASS(NValue) * GetValue(N_CLASS(NObject) * pComponent) const
	{
		HNValue hValue;
		NCheck(NPropertyDescriptorGetValueN(GetHandle(), ToHandle(pComponent), &hValue));
		try
		{
			return FromHandle<N_CLASS(NValue)>(hValue);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	bool GetValue(N_CLASS(NObject) * pComponent, N_CLASS(NType) * pValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		if (!pValueType) NThrowArgumentNullException(N_T("pValueType"));
		NBool hasValue;
		NCheck(NPropertyDescriptorGetValue(GetHandle(), ToHandle(pComponent), pValueType->GetHandle(), attributes, arValues, valuesSize, valuesLength, &hasValue));
		return hasValue != 0;
	}

	template<typename T> T GetValue(N_CLASS(NObject) * pComponent, NAttributes attributes = naNone, bool * pHasValue = NULL) const
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NBool hasValue;
		NCheck(NPropertyDescriptorGetValue(GetHandle(), ToHandle(pComponent), N_CLASS(NTypeTraits)<T>::GetNativeType()->GetHandle(), attributes, &value, sizeof(value), 1, pHasValue ? &hasValue : NULL));
		try
		{
			T v = N_CLASS(NTypeTraits)<T>::FromNative(value);
			if (pHasValue) *pHasValue = hasValue != 0;
			return v;
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNative(value);
			throw;
		}
	}

	void SetValue(N_CLASS(NObject) * pComponent, N_CLASS(NValue) * pValue) const
	{
		NCheck(NPropertyDescriptorSetValueN(GetHandle(), ToHandle(pComponent), ToHandle(pValue)));
	}

	void SetValue(N_CLASS(NObject) * pComponent, N_CLASS(NType) * pValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue = true) const
	{
		if (!pValueType) NThrowArgumentNullException(N_T("pValueType"));
		NCheck(NPropertyDescriptorSetValue(GetHandle(), ToHandle(pComponent), pValueType->GetHandle(), attributes, arValues, valuesSize, valuesLength, hasValue ? NTrue : NFalse));
	}

	template<typename T> void SetValue(N_CLASS(NObject) * pComponent, const T & value, NAttributes attributes = naNone, bool hasValue = true) const
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(NPropertyDescriptorSetValue(GetHandle(), ToHandle(pComponent), N_CLASS(NTypeTraits)<T>::GetNativeType()->GetHandle(), attributes, &value, sizeof(value), 1, hasValue ? NTrue : NFalse));
	}

	bool CanResetValue(N_CLASS(NObject) * pComponent) const
	{
		NBool value;
		NCheck(NPropertyDescriptorCanResetValue(GetHandle(), ToHandle(pComponent), &value));
		return value != 0;
	}

	void ResetValue(N_CLASS(NObject) * pComponent) const
	{
		NCheck(NPropertyDescriptorResetValue(GetHandle(), ToHandle(pComponent)));
	}

	void AddValueChangedCallback(N_CLASS(NObject) * pComponent, Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPropertyDescriptorAddValueChanged(GetHandle(), ToHandle(pComponent), callback.GetHandle()));
	}

	void RemoveValueChangedCallback(N_CLASS(NObject) * pComponent, Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NPropertyDescriptorRemoveValueChanged(GetHandle(), ToHandle(pComponent), callback.GetHandle()));
	}
};

}}

#endif // !N_PROPERTY_DESCRIPTOR_HPP_INCLUDED
