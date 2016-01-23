#ifndef N_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_EVENT_DESCRIPTOR_HPP_INCLUDED

#include <NMemberDescriptor.hpp>
#include <NValue.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NEventDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NEventDescriptor) : public N_CLASS(NMemberDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NEventDescriptor, NMemberDescriptor)

protected:
	N_CLASS(NEventDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NMemberDescriptor)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NType) * GetEventType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NEventDescriptorGetEventType, true, true);
	}

	void AddHandler(N_CLASS(NObject) * pObject, N_CLASS(NValue) * pCallback) const
	{
		NCheck(NEventDescriptorAddHandlerN(GetHandle(), ToHandle(pObject), ToHandle(pCallback)));
	}

	void AddHandler(N_CLASS(NObject) * pObject, N_CLASS(NType) * pCallbackType, const N_CLASS(NCallback) & callback) const
	{
		if (!pCallbackType) NThrowArgumentNullException(N_T("pCallbackType"));
		NCheck(NEventDescriptorAddHandler(GetHandle(), ToHandle(pObject), pCallbackType->GetHandle(), callback.GetHandle()));
	}

	void RemoveHandler(N_CLASS(NObject) * pObject, N_CLASS(NValue) * pCallback) const
	{
		NCheck(NEventDescriptorRemoveHandlerN(GetHandle(), ToHandle(pObject), ToHandle(pCallback)));
	}

	void RemoveHandler(N_CLASS(NObject) * pObject, N_CLASS(NType) * pCallbackType, const N_CLASS(NCallback) & callback) const
	{
		if (!pCallbackType) NThrowArgumentNullException(N_T("pCallbackType"));
		NCheck(NEventDescriptorRemoveHandler(GetHandle(), ToHandle(pObject), pCallbackType->GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_EVENT_DESCRIPTOR_HPP_INCLUDED
