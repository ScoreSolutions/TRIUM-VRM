#ifndef N_RW_LOCK_HPP_INCLUDED
#define N_RW_LOCK_HPP_INCLUDED

#include <NTypes.hpp>
namespace Neurotec { namespace Threading { namespace Internal
{
#include <NRWLock.h>
}}}

namespace Neurotec { namespace Threading
{

class N_CLASS(NRWLock) : private Internal::NRWLock
{
	N_DECLARE_PRIMITIVE_CLASS(NRWLock)

public:
	N_CLASS(NRWLock)()
	{
		Internal::NRWLockInit(this);
	}

	~N_CLASS(NRWLock)()
	{
		Internal::NRWLockDispose(this);
	}

	void EnterRead()
	{
		Internal::NRWLockEnterRead(this);
	}

	bool TryEnterRead()
	{
		return Internal::NRWLockTryEnterRead(this) != 0;
	}

	void ExitRead()
	{
		Internal::NRWLockExitRead(this);
	}

	void EnterWrite()
	{
		Internal::NRWLockEnterWrite(this);
	}

	bool TryEnterWrite()
	{
		return Internal::NRWLockTryEnterWrite(this) != 0;
	}

	void ExitWrite()
	{
		Internal::NRWLockExitWrite(this);
	}
};

class N_CLASS(NRWLockReadLocker)
{
	N_DECLARE_NON_COPYABLE(NRWLockReadLocker)

private:
	N_CLASS(NRWLock) & rwLock;

public:
	N_CLASS(NRWLockReadLocker)(N_CLASS(NRWLock) & rwLock)
		: rwLock(rwLock)
	{
		rwLock.EnterRead();
	}

	~N_CLASS(NRWLockReadLocker)()
	{
		rwLock.ExitRead();
	}
};

class N_CLASS(NRWLockWriteLocker)
{
private:
	N_CLASS(NRWLock) & rwLock;

	N_CLASS(NRWLockWriteLocker)(const N_CLASS(NRWLockWriteLocker) &);
	N_CLASS(NRWLockWriteLocker) & operator=(const N_CLASS(NRWLockWriteLocker) &);

public:
	N_CLASS(NRWLockWriteLocker)(N_CLASS(NRWLock) & rwLock)
		: rwLock(rwLock)
	{
		rwLock.EnterWrite();
	}

	~N_CLASS(NRWLockWriteLocker)()
	{
		rwLock.ExitWrite();
	}
};

}}

#endif // !N_RW_LOCK_HPP_INCLUDED
