#ifndef NFSM_MATCH_DETAILS_HPP_INCLUDED
#define NFSM_MATCH_DETAILS_HPP_INCLUDED

#include <NfmMatchDetails.hpp>
#include <NCore.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NfsmMatchDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NStream) * pStream, NfsmMatchDetails * * ppMatchDetails)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NfsmMatchDetailsDeserializeFromStream(pStream->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NfsmMatchDetails * * ppMatchDetails)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	NCheck(NfsmMatchDetailsDeserializeN(pBuffer->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NfsmMatchDetails ** ppMatchDetails)
{
	NCheck(NfsmMatchDetailsDeserialize(pBuffer, bufferSize, ppMatchDetails));
}

inline void MatchDetailsSerialize(NfsmMatchDetails * pMatchDetails, ::Neurotec::IO::N_CLASS(NStream) * pStream)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NfsmMatchDetailsSerializeToStream(pMatchDetails, pStream->GetHandle()));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * MatchDetailsSerialize(NfsmMatchDetails * pMatchDetails)
{
	HNBuffer hBuffer;
	NCheck(NfsmMatchDetailsSerializeN(pMatchDetails, &hBuffer));
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
N_DEPRECATED("function is deprecated, use MatchDetailsSerialize(NfsmMatchDetails *) instead")
inline void * MatchDetailsSerialize(NfsmMatchDetails * pMatchDetails, NSizeType * pBufferSize)
{
	void * pBuffer;
	NCheck(NfsmMatchDetailsSerialize(pMatchDetails, &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

}}

#endif // !NFSM_MATCH_DETAILS_HPP_INCLUDED
