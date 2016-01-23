#ifndef N_STOPWATCH_HPP_INCLUDED
#define N_STOPWATCH_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Diagnostics
{
#include <NStopwatch.h>
}}

namespace Neurotec { namespace Diagnostics
{

class N_CLASS(NStopwatch) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NStopwatch, NObject)

private:
	static HNStopwatch Create()
	{
		HNStopwatch hStopwatch;
		NCheck(NStopwatchCreate(&hStopwatch));
		return hStopwatch;
	}

	N_CLASS(NStopwatch)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static NLong GetTimestamp()
	{
		NLong value;
		NCheck(NStopwatchGetTimestamp(&value));
		return value;
	}

	static N_CLASS(NStopwatch) * StartNew()
	{
		HNStopwatch hStopwatch;
		NCheck(NStopwatchStartNew(&hStopwatch));
		try
		{
			return FromHandle<N_CLASS(NStopwatch)>(hStopwatch);
		}
		catch (...)
		{
			Unref(hStopwatch);
			throw;
		}
	}

	static bool IsHighResolution()
	{
		NBool value;
		NCheck(NStopwatchIsHighResolution(&value));
		return value != 0;
	}

	static NLong GetFrequency()
	{
		NLong value;
		NCheck(NStopwatchGetFrequency(&value));
		return value;
	}

	N_CLASS(NStopwatch)()
		: N_CLASS(NObject)(Create(), true)
	{
	}

	void Start()
	{
		NCheck(NStopwatchStart(GetHandle()));
	}

	void Stop()
	{
		NCheck(NStopwatchStop(GetHandle()));
	}

	void Reset()
	{
		NCheck(NStopwatchReset(GetHandle()));
	}

	void Restart()
	{
		NCheck(NStopwatchRestart(GetHandle()));
	}

	NLong GetElapsedTicks() const
	{
		NLong value;
		NCheck(NStopwatchGetElapsedTicks(GetHandle(), &value));
		return value;
	}

	N_CLASS(NTimeSpan) GetElapsed() const
	{
		NTimeSpan_ value;
		NCheck(NStopwatchGetElapsed(GetHandle(), &value));
		return N_CLASS(NTimeSpan)(value);
	}

	NLong GetElapsedMilliseconds() const
	{
		NLong value;
		NCheck(NStopwatchGetElapsedMilliseconds(GetHandle(), &value));
		return value;
	}

	bool IsRunning() const
	{
		NBool value;
		NCheck(NStopwatchIsRunning(GetHandle(), &value));
		return value != 0;
	}
};

}}

#endif // !N_STOPWATCH_HPP_INCLUDED
