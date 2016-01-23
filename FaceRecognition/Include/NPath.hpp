#ifndef N_PATH_HPP_INCLUDED
#define N_PATH_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace IO
{
#include <NPath.h>
}}

namespace Neurotec { namespace IO
{

#undef N_PATH_DIRECTORY_SEPARATORA
#undef N_PATH_ALT_DIRECTORY_SEPARATORA
#undef N_PATH_VOLUME_SEPARATORA
#undef N_PATH_PATH_SEPARATORA
#ifndef N_NO_UNICODE
	#undef N_PATH_DIRECTORY_SEPARATORW
	#undef N_PATH_ALT_DIRECTORY_SEPARATORW
	#undef N_PATH_VOLUME_SEPARATORW
	#undef N_PATH_PATH_SEPARATORW
#endif
#undef N_PATH_IS_CASE_SENSITIVE
#undef N_PATH_DIRECTORY_SEPARATOR
#undef N_PATH_ALT_DIRECTORY_SEPARATOR
#undef N_PATH_VOLUME_SEPARATOR
#undef N_PATH_PATH_SEPARATOR
#undef N_MAX_FILE_NAME

#ifdef N_WINDOWS
	const NAChar N_PATH_DIRECTORY_SEPARATORA = '\\';
	const NAChar N_PATH_ALT_DIRECTORY_SEPARATORA = '/';
	const NAChar N_PATH_VOLUME_SEPARATORA = ':';
	const NAChar N_PATH_PATH_SEPARATORA = ';';
	#ifndef N_NO_UNICODE
		const NWChar N_PATH_DIRECTORY_SEPARATORW = L'\\';
		const NWChar N_PATH_ALT_DIRECTORY_SEPARATORW = L'/';
		const NWChar N_PATH_VOLUME_SEPARATORW = L':';
		const NWChar N_PATH_PATH_SEPARATORW = L';';
	#endif
	const bool N_PATH_IS_CASE_SENSITIVE = false;
#else
	const NAChar N_PATH_DIRECTORY_SEPARATORA = '/';
	const NAChar N_PATH_ALT_DIRECTORY_SEPARATORA = N_PATH_DIRECTORY_SEPARATORA;
	const NAChar N_PATH_VOLUME_SEPARATORA = N_PATH_DIRECTORY_SEPARATORA;
	const NAChar N_PATH_PATH_SEPARATORA = ';';
	#ifndef N_NO_UNICODE
		const NWChar N_PATH_DIRECTORY_SEPARATORW = L'/';
		const NWChar N_PATH_ALT_DIRECTORY_SEPARATORW = N_PATH_DIRECTORY_SEPARATORW;
		const NWChar N_PATH_VOLUME_SEPARATORW = N_PATH_DIRECTORY_SEPARATORW;
		const NWChar N_PATH_PATH_SEPARATORW = ';';
	#endif
	const bool N_PATH_IS_CASE_SENSITIVE = true;
#endif

const NChar N_PATH_DIRECTORY_SEPARATOR = N_VAR_AW(N_PATH_DIRECTORY_SEPARATOR);
const NChar N_PATH_ALT_DIRECTORY_SEPARATOR = N_VAR_AW(N_PATH_ALT_DIRECTORY_SEPARATOR);
const NChar N_PATH_VOLUME_SEPARATOR = N_VAR_AW(N_PATH_VOLUME_SEPARATOR);
const NChar N_PATH_PATH_SEPARATOR = N_VAR_AW(N_PATH_PATH_SEPARATOR);

const NInt N_MAX_FILE_NAME = 256;

class N_CLASS(NPath)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NPath)

public:
	static void Check(const N_CLASS(NStringWrapper) & path)
	{
		NCheck(NPathCheckN(path.GetHandle()));
	}

	static bool IsRooted(const N_CLASS(NStringWrapper) & path)
	{
		NBool value;
		NCheck(NPathIsRootedN(path.GetHandle(), &value));
		return value != 0;
	}

	static N_CLASS(NString) GetTempPath()
	{
		HNString hPath;
		NCheck(NPathGetTempPath(&hPath));
		return N_CLASS(NString)(hPath, true);
	}

	static N_CLASS(NString) GetTempFileName()
	{
		HNString hFileName;
		NCheck(NPathGetTempFileName(&hFileName));
		return N_CLASS(NString)(hFileName, true);
	}

	static N_CLASS(NString) Combine(const N_CLASS(NStringWrapper) & path1, const N_CLASS(NStringWrapper) & path2)
	{
		HNString hValue;
		NCheck(NPathCombineN(path1.GetHandle(), path2.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GetDirectoryName(const N_CLASS(NStringWrapper) & path)
	{
		HNString hValue;
		NCheck(NPathGetDirectoryNameN(path.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GetFileName(const N_CLASS(NStringWrapper) & path)
	{
		HNString hValue;
		NCheck(NPathGetFileNameN(path.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GetFileNameWithoutExtension(const N_CLASS(NStringWrapper) & path)
	{
		HNString hValue;
		NCheck(NPathGetFileNameWithoutExtensionN(path.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GetExtension(const N_CLASS(NStringWrapper) & path)
	{
		HNString hValue;
		NCheck(NPathGetExtensionN(path.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static bool HasExtension(const N_CLASS(NStringWrapper) & path)
	{
		NBool value;
		NCheck(NPathHasExtensionN(path.GetHandle(), &value));
		return value != 0;
	}

	static N_CLASS(NString) ChangeExtension(const N_CLASS(NStringWrapper) & path, const N_CLASS(NStringWrapper) & extension)
	{
		HNString hValue;
		NCheck(NPathChangeExtensionN(path.GetHandle(),extension.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};

}}

#endif // !N_PATH_HPP_INCLUDED
