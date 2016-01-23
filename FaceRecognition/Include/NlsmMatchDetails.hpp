#ifndef NLSM_MATCH_DETAILS_HPP_INCLUDED
#define NLSM_MATCH_DETAILS_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NlsmMatchDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NStream) * pStream, NlsmMatchDetails * * ppMatchDetails)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NlsmMatchDetailsDeserializeFromStream(pStream->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NlsmMatchDetails * * ppMatchDetails)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	NCheck(NlsmMatchDetailsDeserializeN(pBuffer->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NlsmMatchDetails ** ppMatchDetails)
{
	NCheck(NlsmMatchDetailsDeserialize(pBuffer, bufferSize, ppMatchDetails));
}

inline void MatchDetailsSerialize(NlsmMatchDetails * pMatchDetails, ::Neurotec::IO::N_CLASS(NStream) * pStream)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NlsmMatchDetailsSerializeToStream(pMatchDetails, pStream->GetHandle()));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * MatchDetailsSerialize(NlsmMatchDetails * pMatchDetails)
{
	HNBuffer hBuffer;
	NCheck(NlsmMatchDetailsSerializeN(pMatchDetails, &hBuffer));
	try
	{
		return N_CLASS(NObject)::FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
	}
	catch (...)
	{
		N_CLASS(NObject)::Unref(hBuffer);
		throw;
	}
}

#include <NNoDeprecate.h>
N_DEPRECATED("function is deprecated, use MatchDetailsSerialize(NlsmMatchDetails *) instead")
inline void * MatchDetailsSerialize(NlsmMatchDetails * pMatchDetails, NSizeType * pBufferSize)
{
	void * pBuffer;
	NCheck(NlsmMatchDetailsSerialize(pMatchDetails, &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

}}

#endif // !NLSM_MATCH_DETAILS_HPP_INCLUDED
