#ifndef N_TEMPLATE_HPP_INCLUDED
#define N_TEMPLATE_HPP_INCLUDED

#include <NFTemplate.hpp>
#include <NLTemplate.hpp>
#include <NETemplate.hpp>
#include <NSTemplate.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NTemplate) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NTemplate, NObject)

private:
	static HNTemplate Create(NUInt flags)
	{
		HNTemplate handle;
		NCheck(NTemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNTemplate Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNTemplate handle;
		NCheck(NTemplateCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNTemplate handle;
		NCheck(NTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	N_CLASS(NTemplate)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static NSizeType CalculateSize(NSizeType fingersTemplateSize, NSizeType facesTemplateSize, NSizeType irisesTemplateSize, NSizeType palmsTemplateSize, NSizeType voicesTemplateSize)
	{
		NSizeType value;
		NCheck(NTemplateCalculateSize(fingersTemplateSize, facesTemplateSize, irisesTemplateSize, palmsTemplateSize, voicesTemplateSize, &value));
		return value;
	}

	static NSizeType Pack(const void * pFingersTemplate, NSizeType fingersTemplateSize,
		const void * pFacesTemplate, NSizeType facesTemplateSize,
		const void * pIrisesTemplate, NSizeType irisesTemplateSize,
		const void * pPalmsTemplate, NSizeType palmsTemplateSize,
		const void * pVoicesTemplate, NSizeType voicesTemplateSize,
		void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NTemplatePack(pFingersTemplate, fingersTemplateSize,
			pFacesTemplate, facesTemplateSize,
			pIrisesTemplate, irisesTemplateSize,
			pPalmsTemplate, palmsTemplateSize,
			pVoicesTemplate, voicesTemplateSize,
			pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		N_CLASS(NVersion) * pVersion, NUInt * pSize, NByte * pHeaderSize,
		const void * * ppFingersTemplate, NSizeType * pFingersTemplateSize,
		const void * * ppFacesTemplate, NSizeType * pFacesTemplateSize,
		const void * * ppIrisesTemplate, NSizeType * pIrisesTemplateSize,
		const void * * ppPalmsTemplate, NSizeType * pPalmsTemplateSize,
		const void * * ppVoicesTemplate, NSizeType * pVoicesTemplateSize)
	{
		NVersion_ v = 0;
		NCheck(NTemplateUnpack(pBuffer, bufferSize,
			pVersion ? &v : NULL, pSize, pHeaderSize,
			ppFingersTemplate, pFingersTemplateSize,
			ppFacesTemplate, pFacesTemplateSize,
			ppIrisesTemplate, pIrisesTemplateSize,
			ppPalmsTemplate, pPalmsTemplateSize,
			ppVoicesTemplate, pVoicesTemplateSize));
		if (pVersion) *pVersion = N_CLASS(NVersion)(v);
	}

#ifdef N_DEBUG
	using N_CLASS(NObject)::Check;
#endif

	static void Check(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NTemplateCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NTemplateCheck(pBuffer, bufferSize));
	}

	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NTemplateGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit N_CLASS(NTemplate)(NUInt flags = 0)
		: N_CLASS(NObject)(Create(flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NTemplate);
	}

	explicit N_CLASS(NTemplate)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NTemplate);
	}

	N_CLASS(NTemplate)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NTemplate);
	}

	N_CLASS(NFTemplate) * GetFingers()
	{
		return GetObject<HandleType, N_CLASS(NFTemplate)>(NTemplateGetFingersEx, true, true);
	}

	void SetFingers(N_CLASS(NFTemplate) * pValue)
	{
		return SetObject(NTemplateSetFingers, pValue);
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFTemplate)) " constructor and SetFingers instead")
	N_CLASS(NFTemplate) * AddFingers(NUInt flags = 0)
	{
		HNFTemplate hFingers;
		NCheck(NTemplateAddFingersEx(GetHandle(), flags | N_OBJECT_REF_RET, &hFingers));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hFingers, true, true);
		}
		catch (...)
		{
			Unref(hFingers);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFTemplate)) " constructor and SetFingers instead")
	N_CLASS(NFTemplate) * AddFingers(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNFTemplate hFingers;
		NCheck(NTemplateAddFingersFromMemoryN(GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hFingers));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hFingers, true, true);
		}
		catch (...)
		{
			Unref(hFingers);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFTemplate)) " constructor and SetFingers instead")
	N_CLASS(NFTemplate) * AddFingers(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNFTemplate hFingers;
		NCheck(NTemplateAddFingersFromMemoryEx(GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hFingers));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hFingers, true, true);
		}
		catch (...)
		{
			Unref(hFingers);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and SetFingers instead")
	N_CLASS(NFTemplate) * AddFingersCopy(N_CLASS(NFTemplate) * pSrcFingers, NUInt flags = 0)
	{
		if (!pSrcFingers) NThrowArgumentNullException(N_T("pSrcFingers"));
		HNFTemplate hFingers;
		NCheck(NTemplateAddFingersCopyEx(GetHandle(), pSrcFingers->GetHandle(), flags | N_OBJECT_REF_RET, &hFingers));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hFingers, true, true);
		}
		catch (...)
		{
			Unref(hFingers);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use SetFingers instead")
	void RemoveFingers()
	{
		NCheck(NTemplateRemoveFingers(GetHandle()));
	}
#include <NReDeprecate.h>

	N_CLASS(NLTemplate) * GetFaces()
	{
		return GetObject<HandleType, N_CLASS(NLTemplate)>(NTemplateGetFacesEx, true, true);
	}

	void SetFaces(N_CLASS(NLTemplate) * pValue)
	{
		return SetObject(NTemplateSetFaces, pValue);
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NLTemplate)) " constructor and SetFaces instead")
	N_CLASS(NLTemplate) * AddFaces(NUInt flags = 0)
	{
		HNLTemplate hFaces;
		NCheck(NTemplateAddFacesEx(GetHandle(), flags | N_OBJECT_REF_RET, &hFaces));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hFaces, true, true);
		}
		catch (...)
		{
			Unref(hFaces);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NLTemplate)) " constructor and SetFaces instead")
	N_CLASS(NLTemplate) * AddFaces(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNLTemplate hFaces;
		NCheck(NTemplateAddFacesFromMemoryN(GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hFaces));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hFaces, true, true);
		}
		catch (...)
		{
			Unref(hFaces);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NLTemplate)) " constructor and SetFaces instead")
	N_CLASS(NLTemplate) * AddFaces(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNLTemplate hFaces;
		NCheck(NTemplateAddFacesFromMemoryEx(GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hFaces));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hFaces, true, true);
		}
		catch (...)
		{
			Unref(hFaces);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and SetFaces instead")
	N_CLASS(NLTemplate) * AddFacesCopy(N_CLASS(NLTemplate) * pSrcFaces, NUInt flags = 0)
	{
		if (!pSrcFaces) NThrowArgumentNullException(N_T("pSrcFaces"));
		HNLTemplate hFaces;
		NCheck(NTemplateAddFacesCopyEx(GetHandle(), pSrcFaces->GetHandle(), flags | N_OBJECT_REF_RET, &hFaces));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hFaces, true, true);
		}
		catch (...)
		{
			Unref(hFaces);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use SetFaces instead")
	void RemoveFaces()
	{
		NCheck(NTemplateRemoveFaces(GetHandle()));
	}
#include <NReDeprecate.h>

	N_CLASS(NETemplate) * GetIrises()
	{
		return GetObject<HandleType, N_CLASS(NETemplate)>(NTemplateGetIrisesEx, true, true);
	}

	void SetIrises(N_CLASS(NETemplate) * pValue)
	{
		return SetObject(NTemplateSetIrises, pValue);
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NETemplate)) " constructor and SetIrises instead")
	N_CLASS(NETemplate) * AddIrises(NUInt flags = 0)
	{
		HNETemplate hIrises;
		NCheck(NTemplateAddIrisesEx(GetHandle(), flags | N_OBJECT_REF_RET, &hIrises));
		try
		{
			return FromHandle<N_CLASS(NETemplate)>(hIrises, true, true);
		}
		catch (...)
		{
			Unref(hIrises);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NETemplate)) " constructor and SetIrises instead")
	N_CLASS(NETemplate) * AddIrises(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNETemplate hIrises;
		NCheck(NTemplateAddIrisesFromMemoryN(GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hIrises));
		try
		{
			return FromHandle<N_CLASS(NETemplate)>(hIrises, true, true);
		}
		catch (...)
		{
			Unref(hIrises);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NETemplate)) " constructor and SetIrises instead")
	N_CLASS(NETemplate) * AddIrises(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNETemplate hIrises;
		NCheck(NTemplateAddIrisesFromMemoryEx(GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hIrises));
		try
		{
			return FromHandle<N_CLASS(NETemplate)>(hIrises, true, true);
		}
		catch (...)
		{
			Unref(hIrises);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and SetIrises instead")
	N_CLASS(NETemplate) * AddIrisesCopy(N_CLASS(NETemplate) * pSrcIrises, NUInt flags = 0)
	{
		if (!pSrcIrises) NThrowArgumentNullException(N_T("pSrcIrises"));
		HNETemplate hIrises;
		NCheck(NTemplateAddIrisesCopyEx(GetHandle(), pSrcIrises->GetHandle(), flags | N_OBJECT_REF_RET, &hIrises));
		try
		{
			return FromHandle<N_CLASS(NETemplate)>(hIrises, true, true);
		}
		catch (...)
		{
			Unref(hIrises);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use SetIrises instead")
	void RemoveIrises()
	{
		NCheck(NTemplateRemoveIrises(GetHandle()));
	}
#include <NReDeprecate.h>

	N_CLASS(NFTemplate) * GetPalms()
	{
		return GetObject<HandleType, N_CLASS(NFTemplate)>(NTemplateGetPalmsEx, true, true);
	}

	void SetPalms(N_CLASS(NFTemplate) * pValue)
	{
		return SetObject(NTemplateSetPalms, pValue);
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFTemplate)) " constructor and SetPalms instead")
	N_CLASS(NFTemplate) * AddPalms(NUInt flags = 0)
	{
		HNFTemplate hPalms;
		NCheck(NTemplateAddPalmsEx(GetHandle(), flags | N_OBJECT_REF_RET, &hPalms));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hPalms, true, true);
		}
		catch (...)
		{
			Unref(hPalms);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFTemplate)) " constructor and SetPalms instead")
	N_CLASS(NFTemplate) * AddPalms(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNFTemplate hPalms;
		NCheck(NTemplateAddPalmsFromMemoryN(GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hPalms));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hPalms, true, true);
		}
		catch (...)
		{
			Unref(hPalms);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NFTemplate)) " constructor and SetPalms instead")
	N_CLASS(NFTemplate) * AddPalms(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNFTemplate hPalms;
		NCheck(NTemplateAddPalmsFromMemoryEx(GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hPalms));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hPalms, true, true);
		}
		catch (...)
		{
			Unref(hPalms);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and SetPalms instead")
	N_CLASS(NFTemplate) * AddPalmsCopy(N_CLASS(NFTemplate) * pSrcPalms, NUInt flags = 0)
	{
		if (!pSrcPalms) NThrowArgumentNullException(N_T("pSrcPalms"));
		HNFTemplate hPalms;
		NCheck(NTemplateAddPalmsCopyEx(GetHandle(), pSrcPalms->GetHandle(), flags | N_OBJECT_REF_RET, &hPalms));
		try
		{
			return FromHandle<N_CLASS(NFTemplate)>(hPalms, true, true);
		}
		catch (...)
		{
			Unref(hPalms);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use SetPalms instead")
	void RemovePalms()
	{
		NCheck(NTemplateRemovePalms(GetHandle()));
	}
#include <NReDeprecate.h>

	N_CLASS(NSTemplate) * GetVoices()
	{
		return GetObject<HandleType, N_CLASS(NSTemplate)>(NTemplateGetVoicesEx, true, true);
	}

	void SetVoices(N_CLASS(NSTemplate) * pValue)
	{
		return SetObject(NTemplateSetVoices, pValue);
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NSTemplate)) " constructor and SetVoices instead")
	N_CLASS(NSTemplate) * AddVoices(NUInt flags = 0)
	{
		HNSTemplate hVoices;
		NCheck(NTemplateAddVoices(GetHandle(), flags | N_OBJECT_REF_RET, &hVoices));
		try
		{
			return FromHandle<N_CLASS(NSTemplate)>(hVoices, true, true);
		}
		catch (...)
		{
			Unref(hVoices);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NSTemplate)) " constructor and SetVoices instead")
	N_CLASS(NSTemplate) * AddVoices(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNSTemplate hVoices;
		NCheck(NTemplateAddVoicesFromMemoryN(GetHandle(), pBuffer->GetHandle(), flags | N_OBJECT_REF_RET, pSize, &hVoices));
		try
		{
			return FromHandle<N_CLASS(NSTemplate)>(hVoices, true, true);
		}
		catch (...)
		{
			Unref(hVoices);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use appropriate " N_STRINGIZEA(N_CLASS(NSTemplate)) " constructor and SetVoices instead")
	N_CLASS(NSTemplate) * AddVoices(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSTemplate hVoices;
		NCheck(NTemplateAddVoicesFromMemory(GetHandle(), pBuffer, bufferSize, flags | N_OBJECT_REF_RET, pSize, &hVoices));
		try
		{
			return FromHandle<N_CLASS(NSTemplate)>(hVoices, true, true);
		}
		catch (...)
		{
			Unref(hVoices);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use " N_STRINGIZEA(N_CLASS(NObject)) "::Clone and SetVoices instead")
	N_CLASS(NSTemplate) * AddVoicesCopy(N_CLASS(NSTemplate) * pSrcVoices, NUInt flags = 0)
	{
		if (!pSrcVoices) NThrowArgumentNullException(N_T("pSrcVoices"));
		HNSTemplate hVoices;
		NCheck(NTemplateAddVoicesCopyEx(GetHandle(), pSrcVoices->GetHandle(), flags | N_OBJECT_REF_RET, &hVoices));
		try
		{
			return FromHandle<N_CLASS(NSTemplate)>(hVoices, true, true);
		}
		catch (...)
		{
			Unref(hVoices);
			throw;
		}
	}

	N_DEPRECATED("method is deprecated, use SetVoices instead")
	void RemoveVoices()
	{
		NCheck(NTemplateRemoveVoices(GetHandle()));
	}
#include <NReDeprecate.h>

	void Clear()
	{
		NCheck(NTemplateClear(GetHandle()));
	}
};

}}

#endif // !N_TEMPLATE_HPP_INCLUDED
