#ifndef NSED_MATCH_HPP_INCLUDED
#define NSED_MATCH_HPP_INCLUDED

#include <NCore.hpp>
#include <NValue.hpp>
namespace Neurotec { namespace Surveillance
{
#include <NsedMatch.h>
}}

namespace Neurotec { namespace Surveillance
{

class N_CLASS(NsedMatch) : public NsedMatch_
{
public:
	N_CLASS(NsedMatch)()
	{
	}

	N_CLASS(NsedMatch)(NInt score, const void * templateId)
	{
		Score = score;
		TemplateId = templateId;
	}
};
N_TYPEDEF_TYPE(NsedMatch)

class N_CLASS(NsedMatchEx) : public NsedMatchEx_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NsedMatchEx)

public:
	N_CLASS(NsedMatchEx)(const N_CLASS(NsedMatch) & other)
	{
		NCheck(NsedMatchExCreateFromNsedMatch(&other, this));
	}

	N_CLASS(NsedMatchEx)(NInt score, N_CLASS(NValue) * pTemplateId)
	{
		NCheck(NsedMatchExCreate(score, N_CLASS(NObject)::ToHandle(pTemplateId), this));
	}

	N_CLASS(NsedMatchEx) & operator=(const N_CLASS(NsedMatch) & other)
	{
		return operator=(N_CLASS(NsedMatchEx)(other));
	}

	operator N_CLASS(NsedMatch)() const
	{
		N_CLASS(NsedMatch) value;
		NCheck(NsedMatchExToNsedMatch(this, &value));
		return value;
	}

	N_CLASS(NValue) * GetTemplateId() const
	{
		return N_CLASS(NObject)::FromHandle<N_CLASS(NValue)>(hTemplateId, false, true);
	}

	void SetTemplateId(N_CLASS(NValue) * pValue)
	{
		NCheck(NObjectSet(N_CLASS(NObject)::ToHandle(pValue), reinterpret_cast<HNObject *>(&hTemplateId)));
	}
};
N_TYPEDEF_TYPE(NsedMatchEx)

}}

#endif // !NSED_MATCH_HPP_INCLUDED
