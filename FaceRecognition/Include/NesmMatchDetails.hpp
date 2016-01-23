#ifndef NESM_MATCH_DETAILS_HPP_INCLUDED
#define NESM_MATCH_DETAILS_HPP_INCLUDED

#include <NemMatchDetails.hpp>
#include <NCore.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NesmMatchDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NStream) * pStream, NesmMatchDetails * * ppMatchDetails)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NesmMatchDetailsDeserializeFromStream(pStream->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NesmMatchDetails * * ppMatchDetails)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	NCheck(NesmMatchDetailsDeserializeN(pBuffer->GetHandle(), ppMatchDetails));
}

inline void MatchDetailsDeserialize(const void * pBuffer, NSizeType bufferSize, NesmMatchDetails ** ppMatchDetails)
{
	NCheck(NesmMatchDetailsDeserialize(pBuffer, bufferSize, ppMatchDetails));
}

inline void MatchDetailsSerialize(NesmMatchDetails * pMatchDetails, ::Neurotec::IO::N_CLASS(NStream) * pStream)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NesmMatchDetailsSerializeToStream(pMatchDetails, pStream->GetHandle()));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * MatchDetailsSerialize(NesmMatchDetails * pMatchDetails)
{
	HNBuffer hBuffer;
	NCheck(NesmMatchDetailsSerializeN(pMatchDetails, &hBuffer));
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
N_DEPRECATED("function is deprecated, use MatchDetailsSerialize(NesmMatchDetails *) instead")
inline void * MatchDetailsSerialize(NesmMatchDetails * pMatchDetails, NSizeType * pBufferSize)
{
	void * pBuffer;
	NCheck(NesmMatchDetailsSerialize(pMatchDetails, &pBuffer, pBufferSize));
	return pBuffer;
}
#include <NReDeprecate.h>

}}

#endif // !NESM_MATCH_DETAILS_HPP_INCLUDED
