#ifndef N_STRING_READER_HPP_INCLUDED
#define N_STRING_READER_HPP_INCLUDED

#include <NTextReader.hpp>
namespace Neurotec { namespace IO
{
#include <NStringReader.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NStringReader) : public N_CLASS(NTextReader)
{
	N_DECLARE_OBJECT_CLASS(NStringReader, NTextReader)

private:
	static HNStringReader Create(const N_CLASS(NStringWrapper) & value)
	{
		HNStringReader handle;
		NCheck(NStringReaderCreateN(value.GetHandle(), &handle));
		return handle;
	}

	static HNStringReader Create(const NChar * arValue, NInt valueLength)
	{
		HNStringReader handle;
		NCheck(NStringReaderCreateFromChars(arValue, valueLength, &handle));
		return handle;
	}

	N_CLASS(NStringReader)(HNObject handle, bool claimHandle)
		: N_CLASS(NTextReader)(handle, claimHandle)
	{
	}

public:
	explicit N_CLASS(NStringReader)(const N_CLASS(NStringWrapper) & value)
		: N_CLASS(NTextReader)(Create(value), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStringReader);
	}

	N_CLASS(NStringReader)(const NChar * arValue, NInt valueLength)
		: N_CLASS(NTextReader)(Create(arValue, valueLength), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStringReader);
	}
};

}}

#endif // !N_STRING_READER_HPP_INCLUDED
