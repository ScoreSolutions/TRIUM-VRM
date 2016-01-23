#include <NObject.hpp>

#ifndef N_MODULE_HPP_INCLUDED
#define N_MODULE_HPP_INCLUDED

namespace Neurotec
{
#include <NModule.h>
}

namespace Neurotec
{
#define N_NATIVE_MODULE_OF(name) (N_CLASS(name)::NativeModuleOf())
#define N_DECLARE_MODULE_CLASS(name) \
	public:\
		static ::Neurotec::N_CLASS(NModule) * NativeModuleOf()\
		{\
			return ::Neurotec::N_CLASS(NObject)::GetObject<N_CLASS(NModule)>(N_MODULE_OF(name), true, true);\
		}

class N_CLASS(NModule) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NModule, NObject)

private:
	static HNModule Create()
	{
		HNModule handle;
		NCheck(NModuleCreate(&handle));
		return handle;
	}

protected:
	N_CLASS(NModule)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NModuleOptionsNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NModuleOptions), true, true);
	}

	static N_CLASS(NModule) * * GetLoadedModules(NInt * pCount)
	{
		return GetObjects<N_CLASS(NModule)>(NModuleGetLoadedModules, pCount, true, true);
	}

	static void CheckInit(NModuleOfProc pTypeOf, bool lazy)
	{
		NCheck(NModuleCheckInitP(pTypeOf, lazy ? NTrue : NFalse));
	}

	N_CLASS(NModule)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NModule);
	}

	void CheckInit(bool lazy) const
	{
		NCheck(NModuleCheckInit(GetHandle(), lazy ? NTrue : NFalse));
	}

	NModuleOptions GetOptions() const
	{
		NModuleOptions value;
		NCheck(NModuleGetOptions(GetHandle(), &value));
		return value;
	}

	void SetOptions(NModuleOptions value)
	{
		NCheck(NModuleSetOptions(GetHandle(), value));
	}

	NInt GetDependences(N_CLASS(NModule) * * arpValues, NInt valuesLength) const
	{
		return GetObjects<HandleType, N_CLASS(NModule)>(NModuleGetDependences, arpValues, valuesLength, true, true);
	}

	N_CLASS(NModule) * * GetDependences(NInt * pCount) const
	{
		return GetObjects<HandleType, N_CLASS(NModule)>(NModuleGetDependences, pCount, true, true);
	}

	N_CLASS(NString) GetName() const
	{
		return GetString(NModuleGetNameN);
	}

	void SetName(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NModuleSetNameN, value);
	}

	N_CLASS(NString) GetTitle() const
	{
		return GetString(NModuleGetTitleN);
	}

	void SetTitle(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NModuleSetTitleN, value);
	}

	N_CLASS(NString) GetProduct() const
	{
		return GetString(NModuleGetProductN);
	}

	void SetProduct(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NModuleSetProductN, value);
	}

	N_CLASS(NString) GetCompany() const
	{
		return GetString(NModuleGetCompanyN);
	}

	void SetCompany(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NModuleSetCompanyN, value);
	}

	N_CLASS(NString) GetCopyright() const
	{
		return GetString(NModuleGetCopyrightN);
	}

	void SetCopyright(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NModuleSetCopyrightN, value);
	}

	NInt GetVersionMajor() const
	{
		NInt value;
		NCheck(NModuleGetVersionMajor(GetHandle(), &value));
		return value;
	}

	void SetVersionMajor(NInt value)
	{
		NCheck(NModuleSetVersionMajor(GetHandle(), value));
	}

	NInt GetVersionMinor() const
	{
		NInt value;
		NCheck(NModuleGetVersionMinor(GetHandle(), &value));
		return value;
	}

	void SetVersionMinor(NInt value)
	{
		NCheck(NModuleSetVersionMinor(GetHandle(), value));
	}

	NInt GetVersionBuild() const
	{
		NInt value;
		NCheck(NModuleGetVersionBuild(GetHandle(), &value));
		return value;
	}

	void SetVersionBuild(NInt value)
	{
		NCheck(NModuleSetVersionBuild(GetHandle(), value));
	}

	NInt GetVersionRevision() const
	{
		NInt value;
		NCheck(NModuleGetVersionRevision(GetHandle(), &value));
		return value;
	}

	void SetVersionRevision(NInt value)
	{
		NCheck(NModuleSetVersionRevision(GetHandle(), value));
	}

	N_CLASS(NString) GetActivated() const
	{
		return GetString(NModuleGetActivatedN);
	}
};

}

#endif // !N_MODULE_HPP_INCLUDED
