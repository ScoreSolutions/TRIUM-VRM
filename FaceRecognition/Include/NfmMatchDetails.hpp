#ifndef NFM_MATCH_DETAILS_HPP_INCLUDED
#define NFM_MATCH_DETAILS_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NfmMatchDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NStream) * pStream, NfmMatchDetails * * ppMatchDetails)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NfmMatchDetailsDeserializeFromStream(pStream->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NfmMatchDetails * * ppMatchDetails)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	NCheck(NfmMatchDetailsDeserializeN(pBuffer->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NfmMatchDetails ** ppMatchDetails)
{
	NCheck(NfmMatchDetailsDeserialize(pBuffer, bufferSize, ppMatchDetails));
}

inline void MatchDetailsSerialize(NfmMatchDetails * pMatchDetails, ::Neurotec::IO::N_CLASS(NStream) * pStream)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NfmMatchDetailsSerializeToStream(pMatchDetails, pStream->GetHandle()));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * MatchDetailsSerialize(NfmMatchDetails * pMatchDetails)
{
	HNBuffer hBuffer;
	NCheck(NfmMatchDetailsSerializeN(pMatchDetails, &hBuffer));
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
N_DEPRECATED("function is deprecated, use MatchDetailsSerialize(NfmMatchDetails *) instead")
inline void * MatchDetailsSerialize(NfmMatchDetails * pMatchDetails, NSizeType * pBufferSize)
{
	void * pBuffer;
	NCheck(NfmMatchDetailsSerialize(pMatchDetails, &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

}}

#endif // !NFM_MATCH_DETAILS_HPP_INCLUDED
