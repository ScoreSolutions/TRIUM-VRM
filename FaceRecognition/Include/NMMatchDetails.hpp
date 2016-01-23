#ifndef NM_MATCH_DETAILS_HPP_INCLUDED
#define NM_MATCH_DETAILS_HPP_INCLUDED

#include <NfsmMatchDetails.hpp>
#include <NlsmMatchDetails.hpp>
#include <NesmMatchDetails.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::IO::HNBuffer;
using ::Neurotec::IO::HNStream;
#include <NMMatchDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NStream) * pStream, NMMatchDetails * * ppMatchDetails)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NMMatchDetailsDeserializeFromStream(pStream->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NMMatchDetails * * ppMatchDetails)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	NCheck(NMMatchDetailsDeserializeN(pBuffer->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NMMatchDetails * * ppMatchDetails)
{
	NCheck(NMMatchDetailsDeserialize(pBuffer, bufferSize, ppMatchDetails));
}

inline void MatchDetailsSerialize(NMMatchDetails * pMatchDetails, ::Neurotec::IO::N_CLASS(NStream) * pStream)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NMMatchDetailsSerializeToStream(pMatchDetails, pStream->GetHandle()));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * MatchDetailsSerialize(NMMatchDetails * pMatchDetails)
{
	HNBuffer hBuffer;
	NCheck(NMMatchDetailsSerializeN(pMatchDetails, &hBuffer));
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
N_DEPRECATED("function is deprecated, use MatchDetailsSerialize(NMMatchDetails *) instead")
inline void * MatchDetailsSerialize(NMMatchDetails * pMatchDetails, NSizeType * pBufferSize)
{
	void * pBuffer;
	NCheck(NMMatchDetailsSerialize(pMatchDetails, &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

}}

#endif // !NM_MATCH_DETAILS_HPP_INCLUDED
