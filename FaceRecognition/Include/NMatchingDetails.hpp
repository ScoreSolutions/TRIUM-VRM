#ifndef N_MATCHING_DETAILS_HPP_INCLUDED
#define N_MATCHING_DETAILS_HPP_INCLUDED

#include <NFMatchingDetails.hpp>
#include <NLMatchingDetails.hpp>
#include <NEMatchingDetails.hpp>
#include <NSMatchingDetails.hpp>
#include <NObject.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NMatchingDetails) : public N_CLASS(NMatchingDetailsBase)
{
	N_DECLARE_OBJECT_CLASS(NMatchingDetails, NMatchingDetailsBase)

private:

public:
	class FingerCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NFMatchingDetails), N_CLASS(NMatchingDetails)>
	{
		FingerCollection(N_CLASS(NMatchingDetails) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NFMatchingDetails), N_CLASS(NMatchingDetails)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNMatchingDetails handle, NInt * pValue) const
		{
			return NMatchingDetailsGetFingerCount(handle, pValue);
		}

		virtual NResult GetNative(HNMatchingDetails handle, NInt index, HNFMatchingDetails * phValue) const
		{
			return NMatchingDetailsGetFingerEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNMatchingDetails, HNFMatchingDetails *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NMatchingDetails);
	};

	class FaceCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NLMatchingDetails), N_CLASS(NMatchingDetails)>
	{
		FaceCollection(N_CLASS(NMatchingDetails) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NLMatchingDetails), N_CLASS(NMatchingDetails)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNMatchingDetails handle, NInt * pValue) const
		{
			return NMatchingDetailsGetFaceCount(handle, pValue);
		}

		virtual NResult GetNative(HNMatchingDetails handle, NInt index, HNLMatchingDetails * phValue) const
		{
			return NMatchingDetailsGetFaceEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNMatchingDetails, HNLMatchingDetails *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NMatchingDetails);
	};

	class IrisCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NEMatchingDetails), N_CLASS(NMatchingDetails)>
	{
		IrisCollection(N_CLASS(NMatchingDetails) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NEMatchingDetails), N_CLASS(NMatchingDetails)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNMatchingDetails handle, NInt * pValue) const
		{
			return NMatchingDetailsGetIrisCount(handle, pValue);
		}

		virtual NResult GetNative(HNMatchingDetails handle, NInt index, HNEMatchingDetails * phValue) const
		{
			return NMatchingDetailsGetIrisEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNMatchingDetails, HNEMatchingDetails *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NMatchingDetails);
	};

	class PalmCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NFMatchingDetails), N_CLASS(NMatchingDetails)>
	{
		PalmCollection(N_CLASS(NMatchingDetails) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NFMatchingDetails), N_CLASS(NMatchingDetails)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNMatchingDetails handle, NInt * pValue) const
		{
			return NMatchingDetailsGetPalmCount(handle, pValue);
		}

		virtual NResult GetNative(HNMatchingDetails handle, NInt index, HNFMatchingDetails * phValue) const
		{
			return NMatchingDetailsGetPalmEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNMatchingDetails, HNFMatchingDetails *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NMatchingDetails);
	};

	class VoiceCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NSMatchingDetails), N_CLASS(NMatchingDetails)>
	{
		VoiceCollection(N_CLASS(NMatchingDetails) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(NSMatchingDetails), N_CLASS(NMatchingDetails)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNMatchingDetails handle, NInt * pValue) const
		{
			return NMatchingDetailsGetVoiceCount(handle, pValue);
		}

		virtual NResult GetNative(HNMatchingDetails handle, NInt index, HNSMatchingDetails * phValue) const
		{
			return NMatchingDetailsGetVoiceEx(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNMatchingDetails, HNSMatchingDetails *, NInt) const
		{
			NThrowNotImplementedException();
		}

		friend class N_CLASS(NMatchingDetails);
	};

private:
	static HNMatchingDetails Create(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNMatchingDetails handle;
		NCheck(NMatchingDetailsCreateFromStream(pStream->GetHandle(), flags, &handle));
		return handle;
	}

	static HNMatchingDetails Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNMatchingDetails handle;
		NCheck(NMatchingDetailsCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNMatchingDetails Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNMatchingDetails handle;
		NCheck(NMatchingDetailsCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	::std::auto_ptr<FingerCollection> fingers;
	::std::auto_ptr<FaceCollection> faces;
	::std::auto_ptr<IrisCollection> irises;
	::std::auto_ptr<PalmCollection> palms;
	::std::auto_ptr<VoiceCollection> voices;

	N_CLASS(NMatchingDetails)(HNObject handle, bool claimHandle)
		: N_CLASS(NMatchingDetailsBase)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		fingers.reset(new FingerCollection(this));
		faces.reset(new FaceCollection(this));
		irises.reset(new IrisCollection(this));
		palms.reset(new PalmCollection(this));
		voices.reset(new VoiceCollection(this));
	}

public:
	explicit N_CLASS(NMatchingDetails)(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0)
		: N_CLASS(NMatchingDetailsBase)(Create(pStream, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMatchingDetails);
		Init();
	}

	explicit N_CLASS(NMatchingDetails)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NMatchingDetailsBase)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMatchingDetails);
		Init();
	}

	N_CLASS(NMatchingDetails)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NMatchingDetailsBase)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMatchingDetails);
		Init();
	}

	using N_CLASS(NObject)::Save;

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use Save(NUInt) instead")
	void * Save(NSizeType * pBufferSize, NUInt flags = 0) const
	{
		void * pBuffer;
		NCheck(NMatchingDetailsSaveToMemory(GetHandle(), flags, &pBuffer, pBufferSize));
		return pBuffer;
	}
#include <NReDeprecate.h>

	NInt GetFingersScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetFingersScore(GetHandle(), &value));
		return value;
	}

	FingerCollection * GetFingers() const
	{
		return fingers.get();
	}

	NInt GetFacesScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetFacesScore(GetHandle(), &value));
		return value;
	}

	NInt GetFacesMatchedIndex() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetFacesMatchedIndex(GetHandle(), &value));
		return value;
	}

	FaceCollection * GetFaces() const
	{
		return faces.get();
	}

	NInt GetIrisesScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetIrisesScore(GetHandle(), &value));
		return value;
	}

	IrisCollection * GetIrises() const
	{
		return irises.get();
	}

	NInt GetPalmsScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetPalmsScore(GetHandle(), &value));
		return value;
	}

	PalmCollection * GetPalms() const
	{
		return palms.get();
	}

	NInt GetVoicesScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetVoicesScore(GetHandle(), &value));
		return value;
	}

	VoiceCollection * GetVoices() const
	{
		return voices.get();
	}
};

}}

#endif // !N_MATCHING_DETAILS_HPP_INCLUDED
