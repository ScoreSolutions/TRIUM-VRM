unit NMedia;

interface

uses Windows, Graphics, SysUtils, NCore;

	procedure NMediaGetInfo(var info: TNLibraryInfo);

const
	DefaultCompressionLevel = 6;

type
	TNPixelFormat = (npfMonochrome = $00001001, npfGrayscale = $00301001,
		npfRgb = $00303003, npfUnused = MaxInt);

	TNRgb = record
		Red: NByte;
		Green: NByte;
		Blue: NByte;
	end;

	TNImageFormat = class(TObject)
	private
		_handle: NHandle;
		constructor Create(hImageFormat: NHandle); overload;
	public
		class function GetFormatCount: NInt;

		class function CreateFormat(index: NInt): TNImageFormat;
		class function CreateBmpFormat: TNImageFormat;

		class procedure GetImageFormats(var openFileFormats: string; var saveImageFormats: string);

		function CanWrite: NBoolean;
		function CanRead: NBoolean;
		function FormatName: string;
		function FormatFileFilter: string;
		function DefaultExtension: string;
	end;

	TNImage = class(TObject)
	private
		_handle: NHandle;
	public
		constructor Create(image: NHandle); overload;
		destructor Destroy(); override;

		property Handle: Pointer read _handle;

		class function CreateFromFile(fileName: string; imageFormat: TNImageFormat): TNImage;
		class function CreateFromImage(pixelFormat: TNPixelFormat; stride: NSizeType; srcImage: TNImage): TNImage; overload;
		class function CreateFromImage(pixelFormat: TNPixelFormat; stride: NSizeType; horzResolution: NFloat; vertResolution: NFloat; srcImage: TNImage): TNImage; overload;
		class function CreateFromHBitmap(image: HBitmap): TNImage;

		function CreateColorWrapper(min, max: TNRgb): TNImage;

		function HorizontalResolution: NFloat;
		function VerticalResolution: NFloat;
		function Stride: NSizeType;
		function Height: NUInt;
		function Width: NUInt;

		function Clone: TNImage;

		function SaveToHBitmap: HBitmap;
		procedure SaveToFile(fileName: string; hImageFormat: TNImageFormat);

		function Crop(left, top, Width, Height: NUInt): TNImage;
	end;

	TNPng = class(TObject)
	private

	public

		class function LoadImage(fileName: string): TNImage; overload;
		class function LoadImage(arr: TArrayOfNByte): TNImage; overload;
		class procedure SaveImage(image: TNImage; fileName: string); overload;
		class procedure SaveImage(image: TNImage; compressionLevel: Integer;
			fileName: string); overload;
		class function SaveImage(image: TNImage): TArrayOfNByte; overload;
		class function SaveImage(image: TNImage; compressionLevel: Integer)
			: TArrayOfNByte; overload;
	end;

	TArrayOfTNImage = array of TNImage;

implementation

const
	DllName = 'NMedia.dll';

{$IFDEF UNICODE}
	function NMediaGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NMediaGetInfoW';
{$ELSE}
	function NMediaGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NMediaGetInfoA';
{$ENDIF}
	function NImagesGetGrayscaleColorWrapperEx(hImage: NHandle; var minColor: TNRgb; var maxColor: TNRgb; var hDstImage: NHandle): NResult stdcall; external dllName;

{$IFDEF UNICODE}
	function NImageCreateFromFileEx(const fileName: string; hImageFormat: NHandle; flags: NUInt; var hImageInfo: NHandle; var hImage: NHandle): NResult stdcall; external dllName name 'NImageCreateFromFileExW';
	function NImageSaveToFileEx(hImage: NHandle; fileName: string; hImageFormat: NHandle; hImageInfo: NHandle; flags: NUInt): NResult stdcall; external dllName name 'NImageSaveToFileExW';
{$ELSE}
	function NImageCreateFromFileEx(const fileName: string; hImageFormat: NHandle; flags: NUInt; var hImageInfo: NHandle; var hImage: NHandle): NResult stdcall; external dllName name 'NImageCreateFromFileExA';
	function NImageSaveToFileEx(hImage: NHandle; fileName: string; hImageFormat: NHandle; hImageInfo: NHandle; flags: NUInt): NResult stdcall; external dllName name 'NImageSaveToFileExA';
{$ENDIF}

	function NImageCreateFromHBitmap(handle: HBitmap; flags: NUInt; var hImage: NHandle): NResult stdcall; external dllName;
	function NImageToHBitmap(hImage: NHandle; var handle: HBitmap): NResult stdcall; external dllName;

	function NImageCreateFromImageEx(pixelFormat: TNPixelFormat; stride: NSizeType; horzResolution: NFloat; vertResolution: NFloat; hSrcImage: NHandle; var hImage: NHandle): NResult stdcall; external dllName;
	function NImageCreateFromImageEx2(pixelFormat: TNPixelFormat; stride: NSizeType; hSrcImage: NHandle; flags: NUInt; var hImage: NHandle): NResult; stdcall; external dllName;

	function NImageGetHorzResolution(hImage: NHandle; var value: NFloat): NResult stdcall; external dllName;
	function NImageGetVertResolution(hImage: NHandle; var value: NFloat): NResult stdcall; external dllName;
	function NImageGetWidth(hImage: NHandle; var value: NUInt): NResult stdcall; external dllName;
	function NImageGetHeight(hImage: NHandle; var value: NUInt): NResult stdcall; external dllName;
	function NImageGetStride(hImage: NHandle; var value: NSizeType): NResult stdcall; external dllName;
	function NImageCrop(hImage: NHandle; left: NUInt; top: NUInt; width: NUInt; height: NUInt; var hHandle: NHandle): NResult stdcall; external dllName;

{$IFDEF UNICODE}
	function NImageFormatGetFileFilterEx(hImageFormat: NHandle; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NImageFormatGetFileFilterExW';
	function NImageFormatGetNameEx(hImageFormat: NHandle; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NImageFormatGetNameExW';
	function NImageFormatGetDefaultFileExtensionEx(hImageFormat: NHandle; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NImageFormatGetDefaultFileExtensionExW';
{$ELSE}
	function NImageFormatGetFileFilterEx(hImageFormat: NHandle; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NImageFormatGetFileFilterExA';
	function NImageFormatGetNameEx(hImageFormat: NHandle; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NImageFormatGetNameExA';
	function NImageFormatGetDefaultFileExtensionEx(hImageFormat: NHandle; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NImageFormatGetDefaultFileExtensionExA';
{$ENDIF}

	function NImageFormatGetFormatCount(var value: NInt): NResult stdcall; external dllName;
	function NImageFormatCanRead(hImageFormat: NHandle; var value: NBoolean): NResult stdcall; external dllName;
	function NImageFormatCanWrite(hImageFormat: NHandle; var value: NBoolean): NResult stdcall; external dllName;
	function NImageFormatGetFormat(index: NInt; var hImageFormat: NHandle): NResult stdcall; external dllName;
	function NImageFormatGetBmp(var hImageFormat: NHandle): NResult stdcall; external dllName;

{$IFDEF UNICODE}
	function PngLoadImageFromFile(const fileName: string; var hImage: NHandle) : NResult stdcall; external dllName name 'PngLoadImageFromFileW';
	function PngSaveImageToFile(hImage: NHandle; compressionLevel: NInt; szFileName: string): NResult stdcall; external dllName name 'PngSaveImageToFileW';
{$ELSE}
	function PngLoadImageFromFile(const fileName: string; var hImage: NHandle): NResult stdcall; external dllName name 'PngLoadImageFromFileA';
	function PngSaveImageToFile(hImage: Pointer; compressionLevel: NInt; szFileName: string): NResult stdcall; external dllName name 'PngSaveImageToFileA';
{$ENDIF}
	function PngLoadImageFromMemory(buffer: Pointer; size: NSizeType; var hImage: NHandle): NResult stdcall; external dllName;
	function PngSaveImageToMemory(hImage: NHandle; compressionLevel: NInt; var buffer: Pointer; var size: NSizeType): NResult stdcall; external dllName;

procedure NMediaGetInfo(var info: TNLibraryInfo);
begin
	NCheck(NMediaGetInfoInternal(info));
end;

// -------------------------------------
// Realization of TNImage functions
// -------------------------------------

constructor TNImage.Create(image: NHandle);
begin
	inherited Create;
	_handle := image;
end;

function TNImage.CreateColorWrapper(min, max: TNRgb): TNImage;
var
	imagePtr: NHandle;
begin
	NCheck(NImagesGetGrayscaleColorWrapperEx(Handle, min, max, imagePtr));
	Result := TNImage.Create(imagePtr);
end;

class function TNImage.CreateFromFile(fileName: string; imageFormat: TNImageFormat): TNImage;
var
	handle: NHandle;
	tmpHandle, tmpImageInfo: NHandle;
begin
	tmpHandle := nil;
	if (imageFormat <> nil) then
		tmpHandle := imageFormat._handle;

	NCheck(NImageCreateFromFileEx(fileName, tmpHandle, 0, tmpImageInfo, handle));
	Result := TNImage.Create(handle);
end;

class function TNImage.CreateFromImage(pixelFormat: TNPixelFormat; stride: NSizeType; horzResolution: NFloat; vertResolution: NFloat; srcImage: TNImage): TNImage;
var
	hImage: NHandle;
begin
	NCheck(NImageCreateFromImageEx(pixelFormat, stride, horzResolution, vertResolution, srcImage.Handle, hImage));
	Result := TNImage.Create(hImage);
end;

class function TNImage.CreateFromImage(pixelFormat: TNPixelFormat; stride: NSizeType; srcImage: TNImage): TNImage;
var
	output: Pointer;
begin
	NCheck(NImageCreateFromImageEx2(pixelFormat, stride, srcImage.Handle, 0,
		output));
	Result := TNImage.Create(output);
end;

class function TNImage.CreateFromHBitmap(image: HBitmap): TNImage;
var
	handle: Pointer;
begin
	NCheck(NImageCreateFromHBitmap(image, 0, handle));
	Result := TNImage.Create(handle);
end;

function TNImage.SaveToHBitmap: HBitmap;
var
	handle: HBitmap;
begin
	NCheck(NImageToHBitmap(self.Handle, handle));
	Result := handle;
end;

destructor TNImage.Destroy();
begin
	NObjectFree(Handle);
end;

function TNImage.Clone: TNImage;
var
	image: NHandle;
begin
	NObjectClone(Handle, image);
	Result := TNImage.Create(image);
end;

function TNImage.HorizontalResolution: NFloat;
var
	horzRes: NFloat;
begin
	NCheck(NImageGetHorzResolution(Handle, horzRes));
	Result := horzRes;
end;

function TNImage.VerticalResolution: NFloat;
var
	vertRes: NFloat;
begin
	NCheck(NImageGetVertResolution(Handle, vertRes));
	Result := vertRes;
end;

function TNImage.Width: NUInt;
var
	wdth: NUInt;
begin
	NCheck(NImageGetWidth(Handle, wdth));
	Result := wdth;
end;

function TNImage.Height: NUInt;
var
	hght: NUInt;
begin
	NCheck(NImageGetHeight(Handle, hght));
	Result := hght;
end;

function TNImage.stride: NSizeType;
var
	strd: NSizeType;
begin
	NCheck(NImageGetStride(Handle, strd));
	Result := strd;
end;

procedure TNImage.SaveToFile(fileName: string; hImageFormat: TNImageFormat);
var
	imageFormat: NHandle;
begin
	imageFormat := nil;
	if (hImageFormat <> nil) then
		imageFormat := hImageFormat._handle;
	NCheck(NImageSaveToFileEx(Handle, fileName, imageFormat, nil, 0));
end;

function TNImage.Crop(left: NUInt; top: NUInt; width: NUInt;
	height: NUInt): TNImage;
var
	image: NHandle;
begin
	NCheck(NImageCrop(Handle, left, top, width, height, image));
	Result := TNImage.Create(image);
end;

constructor TNImageFormat.Create(hImageFormat: NHandle);
begin
	inherited Create;
	_handle := hImageFormat;
end;

class function TNImageFormat.CreateFormat(index: NInt): TNImageFormat;
var
	tmp: NHandle;
begin
	NCheck(NImageFormatGetFormat(index, tmp));
	Result := TNImageFormat.Create(tmp);
end;

class function TNImageFormat.CreateBmpFormat: TNImageFormat;
var
	tmpPointer: NHandle;
begin
	NCheck(NImageFormatGetBmp(tmpPointer));
	Result := TNImageFormat.Create(tmpPointer);
end;

class function TNImageFormat.GetFormatCount: NInt;
var
	value: NInt;
begin
	NCheck(NImageFormatGetFormatCount(value));
	Result := value;
end;

function TNImageFormat.CanRead: NBoolean;
var
	value: NBoolean;
begin
	NCheck(NImageFormatCanRead(_handle, value));
	Result := value;
end;

function TNImageFormat.CanWrite: NBoolean;
var
	value: NBoolean;
begin
	NCheck(NImageFormatCanWrite(_handle, value));
	Result := value;
end;

function TNImageFormat.FormatName: string;
var
	res: NResult;
	tmp: PChar;
begin
	Result := '';
	res := NImageFormatGetNameEx(_handle, nil, 0);
	NCheck(res);
	GetMem(tmp, (res + 1) * SizeOf(PChar));
	NCheck(NImageFormatGetNameEx(_handle, tmp, res + 1));
	Result := String(tmp);
	FreeMem(tmp);
end;

function TNImageFormat.FormatFileFilter: string;
var
	res: NResult;
	tmp: PChar;
begin
	Result := '';
	res := NImageFormatGetFileFilterEx(_handle, nil, 0);
	NCheck(res);
	GetMem(tmp, (res + 1) * SizeOf(PChar));
	NCheck(NImageFormatGetFileFilterEx(_handle, tmp, res + 1));
	Result := String(tmp);
	FreeMem(tmp);
end;

function TNImageFormat.DefaultExtension: string;
var
	res: NResult;
	tmp: PChar;
begin
	Result := '';
	res := NImageFormatGetDefaultFileExtensionEx(_handle, nil, 0);
	NCheck(res);
	GetMem(tmp, (res + 1) * SizeOf(PChar));
	NCheck(NImageFormatGetDefaultFileExtensionEx(_handle, tmp, res + 1));
	Result := String(tmp);
	FreeMem(tmp);
end;

class procedure TNImageFormat.GetImageFormats(var openFileFormats: string;
	var saveImageFormats: string);
var
	i, count: Integer;
	imageFormat: TNImageFormat;
	openAllImageFormats: string;
begin
	openAllImageFormats := '';
	count := TNImageFormat.GetFormatCount - 1;
	for i := 0 to count do
	begin
		imageFormat := TNImageFormat.CreateFormat(i);
		if (imageFormat.CanRead) then
		begin
			openFileFormats := openFileFormats + '|';
			openFileFormats := openFileFormats + Format
				('%s files (%s)|%s', [imageFormat.FormatName,
				imageFormat.FormatFileFilter, imageFormat.FormatFileFilter]);
			if (Length(openAllImageFormats) <> 0) then
				openAllImageFormats := openAllImageFormats + ';';
			openAllImageFormats :=
				openAllImageFormats + imageFormat.FormatFileFilter;
		end;
		if (imageFormat.CanWrite) then
		begin
			if (Length(saveImageFormats) <> 0) then
				saveImageFormats := saveImageFormats + '|';
			saveImageFormats := saveImageFormats + Format
				('%s files (%s)|%s', [imageFormat.FormatName,
				imageFormat.FormatFileFilter, imageFormat.FormatFileFilter]);
		end;
	end;
	openFileFormats := Format('All supported images (%s)|%s',
		[openAllImageFormats, openAllImageFormats]) + openFileFormats;
	openFileFormats := openFileFormats + '|All files (*.*)|*.*';
end;

class function TNPng.LoadImage(fileName: string): TNImage;
var
	image: NHandle;
begin
	NCheck(PngLoadImageFromFile(fileName, image));
	Result := TNImage.Create(image);
end;

class function TNPng.LoadImage(arr: TArrayOfNByte): TNImage;
var
	image: NHandle;
begin
	NCheck(PngLoadImageFromMemory(@(arr[0]), Length(arr), image));
	Result := TNImage.Create(image);
end;

class procedure TNPng.SaveImage(image: TNImage; fileName: string);
begin
	SaveImage(image, DefaultCompressionLevel, fileName);
end;

class procedure TNPng.SaveImage(image: TNImage; compressionLevel: NInt; fileName: string);
var
	res: Integer;
begin
	res := PngSaveImageToFile(image.Handle, compressionLevel, fileName);
	NCheck(res);
end;

class function TNPng.SaveImage(image: TNImage): TArrayOfNByte;
begin
	Result := SaveImage(image, DefaultCompressionLevel);
end;

class function TNPng.SaveImage(image: TNImage; compressionLevel: NInt): TArrayOfNByte;
var
	img: Pointer;
	arr: TArrayOfNByte;
	size: NSizeType;
begin
	NCheck(PngSaveImageToMemory(image.Handle, compressionLevel, img, size));
	SetLength(arr, size);
	CopyMemory(@(arr[0]), img, size);
	NFree(img);
	Result := arr;
end;

end.
