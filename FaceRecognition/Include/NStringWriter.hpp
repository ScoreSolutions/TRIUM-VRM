#ifndef N_STRING_WRITER_HPP_INCLUDED
#define N_STRING_WRITER_HPP_INCLUDED

#include <NTextWriter.hpp>
#include <NStringBuilder.hpp>
namespace Neurotec { namespace IO
{
#include <NStringWriter.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NStringWriter) : public N_CLASS(NTextWriter)
{
	N_DECLARE_OBJECT_CLASS(NStringWriter, NTextWriter)

private:
	static HNStringWriter Create()
	{
		HNStringWriter handle;
		NCheck(NStringWriterCreate(&handle));
		return handle;
	}

	static HNStringWriter Create(NInt capacity)
	{
		HNStringWriter handle;
		NCheck(NStringWriterCreateWithCapacity(capacity, &handle));
		return handle;
	}

	static HNStringWriter Create(NInt capacity, NInt maxCapacity, NInt growthDelta)
	{
		HNStringWriter handle;
		NCheck(NStringWriterCreateEx(capacity, maxCapacity, growthDelta, &handle));
		return handle;
	}

	N_CLASS(NStringWriter)(HNObject handle, bool claimHandle)
		: N_CLASS(NTextWriter)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NStringWriter)()
		: N_CLASS(NTextWriter)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStringWriter);
	}

	explicit N_CLASS(NStringWriter)(NInt capacity)
		: N_CLASS(NTextWriter)(Create(capacity), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStringWriter);
	}

	N_CLASS(NStringWriter)(NInt capacity, NInt maxCapacity, NInt growthDelta)
		: N_CLASS(NTextWriter)(Create(capacity, maxCapacity, growthDelta), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NStringWriter);
	}

	N_CLASS(NString) DetachString()
	{
		HNString hValue;
		NCheck(NStringWriterDetachString(GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};

}}

#endif // !N_STRING_WRITER_HPP_INCLUDED
