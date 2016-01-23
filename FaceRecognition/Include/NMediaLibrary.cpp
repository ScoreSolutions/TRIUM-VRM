#ifndef N_MEDIA_LIBRARY_CPP_INCLUDED
#define N_MEDIA_LIBRARY_CPP_INCLUDED

#include <NCoreLibrary.cpp>

#include <NGeometry.hpp>
#include <NImage.hpp>
#include <NGrayscaleImage.hpp>
#include <NMonochromeImage.hpp>
#include <NRgbImage.hpp>
#include <NImageFormat.hpp>
#include <NImageInfo.hpp>
#include <NImageReader.hpp>
#include <NImageWriter.hpp>
#include <NImageFile.hpp>
#include <NImages.hpp>
#include <Bmp.hpp>
#include <Tiff.hpp>
#include <Jpeg.hpp>
#include <Png.hpp>
#include <Wsq.hpp>
#include <IHead.hpp>
#include <Jpeg2K.hpp>
#include <NMedia.hpp>
#include <NSoundBuffer.hpp>
#include <NMediaFormat.hpp>
#include <NAudioFormat.hpp>
#include <NVideoFormat.hpp>
#include <NMediaSource.hpp>
#include <NMediaReader.hpp>
#include <NVideoReader.hpp>
#include <NVideoWriter.hpp>

namespace Neurotec { namespace Images
{

::std::auto_ptr<N_CLASS(NImageFormat)::ImageFormatCollection> N_CLASS(NImageFormat)::formats(new N_CLASS(NImageFormat)::ImageFormatCollection());

N_IMPLEMENT_OBJECT_CLASS_4(NImageFormat, NObject, NImage, NImageInfo, NImageReader, NImageWriter)
N_IMPLEMENT_OBJECT_CLASS_5(NImage, NObject, NMonochromeImage, NGrayscaleImage, NRgbImage, NImageFormat, NImageInfo)
N_IMPLEMENT_OBJECT_CLASS_9(NImageInfo, NExpandableObject, BmpInfo, IHeadInfo, JpegInfo, Jpeg2KInfo, PngInfo, TiffInfo, WsqInfo, NImage, NPropertyBag)
N_IMPLEMENT_OBJECT_CLASS(TiffInfo, NImageInfo)
N_IMPLEMENT_OBJECT_CLASS(JpegInfo, NImageInfo)
N_IMPLEMENT_OBJECT_CLASS(PngInfo, NImageInfo)
N_IMPLEMENT_OBJECT_CLASS_1(WsqInfo, NImageInfo, NistCom)
N_IMPLEMENT_OBJECT_CLASS(Jpeg2KInfo, NImageInfo)
N_IMPLEMENT_OBJECT_CLASS(BmpInfo, NImageInfo)
N_IMPLEMENT_OBJECT_CLASS(IHeadInfo, NImageInfo)
N_IMPLEMENT_OBJECT_CLASS_2(NImageReader, NObject, NImageInfo, NImage)
N_IMPLEMENT_OBJECT_CLASS_2(NImageWriter, NObject, NImageInfo, NImage)
#include <NNoDeprecate.h>
N_IMPLEMENT_OBJECT_CLASS(NImageFile, NObject)
#include <NReDeprecate.h>
N_IMPLEMENT_OBJECT_CLASS(NMonochromeImage, NImage)
N_IMPLEMENT_OBJECT_CLASS(NGrayscaleImage, NImage)
N_IMPLEMENT_OBJECT_CLASS(NRgbImage, NImage)
N_IMPLEMENT_OBJECT_CLASS(NistCom, NObject)

}}

namespace Neurotec { namespace Sound
{

N_IMPLEMENT_OBJECT_CLASS(NSoundBuffer, NObject)

}}

namespace Neurotec { namespace Media
{

using namespace ::Neurotec::Sound;
using namespace ::Neurotec::Images;
N_IMPLEMENT_OBJECT_CLASS_2(NMediaFormat, NExpandableObject, NAudioFormat, NVideoFormat)
N_IMPLEMENT_OBJECT_CLASS(NAudioFormat, NMediaFormat)
N_IMPLEMENT_OBJECT_CLASS(NVideoFormat, NMediaFormat)
N_IMPLEMENT_OBJECT_CLASS_1(NMediaSource, NObject, NMediaFormat)
N_IMPLEMENT_OBJECT_CLASS_4(NMediaReader, NObject, NMediaSource, NMediaFormat, NSoundBuffer, NImage)

}}

namespace Neurotec { namespace Video
{

#include <NNoDeprecate.h>
N_IMPLEMENT_OBJECT_CLASS(NVideoReader, NObject)
N_IMPLEMENT_OBJECT_CLASS(NVideoWriter, NObject)
N_IMPLEMENT_OBJECT_CLASS(NVideoWriterOptions, NObject)
#include <NReDeprecate.h>

}}

#endif // !N_MEDIA_LIBRARY_CPP_INCLUDED
