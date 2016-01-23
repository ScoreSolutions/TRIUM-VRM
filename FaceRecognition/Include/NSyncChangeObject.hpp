#ifndef N_SYNC_CHANGE_OBJECT_HPP_INCLUDED
#define N_SYNC_CHANGE_OBJECT_HPP_INCLUDED

#include <NMonitor.hpp>

namespace Neurotec { namespace Threading
{

class N_CLASS(NSyncChangeObject)
{
private:
	NMonitorType & syncMonitor;
	NMonitorType lockMonitor;
	bool isChanging;

	N_CLASS(NSyncChangeObject)(const N_CLASS(NSyncChangeObject) &);
	N_CLASS(NSyncChangeObject) & operator=(const N_CLASS(NSyncChangeObject) &);

public:
	N_CLASS(NSyncChangeObject)(NMonitorType & syncMonitor)
		: syncMonitor(syncMonitor), lockMonitor(N_MONITOR_ARGS), isChanging(false)
	{
	}

	~N_CLASS(NSyncChangeObject)()
	{
		OnChanged();
	}

	void OnChanging()
	{
		NMonitorLockerType lockLocker(N_MONITOR_LOCKER_ARGS(lockMonitor));
		if (isChanging) NThrowInvalidOperationException(N_T("Already changing"));
		NEnterMonitor(syncMonitor);
		isChanging = true;
	}

	void OnChanged()
	{
		NMonitorLockerType lockLocker(N_MONITOR_LOCKER_ARGS(lockMonitor));
		if (isChanging)
		{
			isChanging = false;
			NExitMonitor(syncMonitor);
		}
	}

	bool IsChanging()
	{
		return isChanging;
	}
};

}}

#endif // !N_SYNC_CHANGE_OBJECT_HPP_INCLUDED
