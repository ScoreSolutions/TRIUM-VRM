#ifndef NSED_MATCH_H_INCLUDED
#define NSED_MATCH_H_INCLUDED

#include <NCore.h>
#include <NValue.h>

#ifdef N_CPP
extern "C"
{
#endif

struct NsedMatch_
{
	NInt Score;
	const void * TemplateId;
};
#ifndef NSED_MATCH_HPP_INCLUDED
typedef struct NsedMatch_ NsedMatch;
#endif

struct NsedMatchEx_
{
	NInt score;
	HNValue hTemplateId;
};
#ifndef NSED_MATCH_HPP_INCLUDED
typedef struct NsedMatchEx_ NsedMatchEx;
#endif

N_DECLARE_TYPE(NsedMatchEx)

NResult N_API NsedMatchExCreate(NInt score, HNValue hTemplateId, struct NsedMatchEx_ * pValue);
NResult N_API NsedMatchExCreateFromNsedMatch(const struct NsedMatch_ * pSrcValue, struct NsedMatchEx_ * pValue);
NResult N_API NsedMatchExDispose(struct NsedMatchEx_ * pValue);
NResult N_API NsedMatchExCopy(const struct NsedMatchEx_ * pSrcValue, struct NsedMatchEx_ * pDstValue);
NResult N_API NsedMatchExSet(const struct NsedMatchEx_ * pSrcValue, struct NsedMatchEx_ * pDstValue);
NResult N_API NsedMatchExToNsedMatch(const struct NsedMatchEx_ * pSrcValue, struct NsedMatch_ * pDstValue);

#ifdef N_CPP
}
#endif

#endif // !NSED_MATCH_H_INCLUDED
