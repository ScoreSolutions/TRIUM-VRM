#ifndef N_IMAGE_FILE_HPP_INCLUDED
#define N_IMAGE_FILE_HPP_INCLUDED

#include <NCore.hpp>
#include <NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::HNStream;
using ::Neurotec::IO::NFileAccess;
#include <NImageFile.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NImage);
class N_CLASS(NImageFormat);

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImageReader)) " instead")
	N_CLASS(NImageFile) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NImageFile, NObject)

private:
	N_CLASS(NImageFile)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NImageFile) * FromFile(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NImageFormat) * pImageFormat = NULL);

	void Close()
	{
		NCheck(NImageFileClose(GetHandle()));
	}

	N_CLASS(NImage) * ReadImage();

	bool IsOpened() const
	{
		NBool value;
		NCheck(NImageFileIsOpened(GetHandle(), &value));
		return value != 0;
	}

	N_CLASS(NImageFormat) * GetFormat() const;
};
#include <NReDeprecate.h>

}}

#include <NImage.hpp>
#include <NImageFormat.hpp>

namespace Neurotec { namespace Images
{

#include <NNoDeprecate.h>
inline N_CLASS(NImageFile) * N_CLASS(NImageFile)::FromFile(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NImageFormat) * pImageFormat)
{
	HNImageFile handle;
	NCheck(NImageFileCreateN(fileName.GetHandle(), ToHandle(pImageFormat), &handle));
	return FromHandle<N_CLASS(NImageFile)>(handle);
}

inline N_CLASS(NImageFormat) * N_CLASS(NImageFile)::GetFormat() const
{
	return GetObject<HandleType, N_CLASS(NImageFormat)>(NImageFileGetFormatEx, true, true);
}

inline N_CLASS(NImage)* N_CLASS(NImageFile)::ReadImage()
{
	HNImage handle;
	NCheck(NImageFileReadImage(GetHandle(), &handle));
	try
	{
		return FromHandle<N_CLASS(NImage)>(handle);
	}
	catch (...)
	{
		Unref(handle);
		throw;
	}
}
#include <NReDeprecate.h>

}}

#endif // !N_IMAGE_FILE_HPP_INCLUDED
