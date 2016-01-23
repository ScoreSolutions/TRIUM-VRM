unit NDevices;

interface
uses Windows, NCore, NMedia, Classes, SysUtils;

	procedure NDevicesGetInfo(var info: TNLibraryInfo);

type
	TCameraVideoFormat = record
		FrameWidth: NInt;
		FrameHeight: NInt;
		FrameRate: NFloat;
	end;

	TArrayOfTCameraVideoFormat = array of TCameraVideoFormat;

	TFPScannerMan = class;
	TFPScanner = class;

	TScannerManCallback = procedure(scannerId: string) of object;
	TScannerImageCallback = procedure(scanner: TFPScanner; image: TNImage) of object;
	TScannerStatusCallback = procedure(scanner: TFPScanner) of object;

	TCamera = class(TObject)
	private
		_handle: NHandle;
		_cameraId: string;

		constructor Create(hCamera: NHandle); overload;
	public
		property Id: string read _cameraId;
		property Handle: NHandle read _handle;
		function IsCapturing: NBoolean;

		procedure StartCapturing;
		procedure StopCapturing;

		function GetCurrentFrame: TNImage;

		function  GetCurrentVideoFormat: TCameraVideoFormat;
		procedure SetVideoFormat(var format: TCameraVideoFormat);
		function  GetVideoFormats: TArrayOfTCameraVideoFormat;

		procedure SetAutomaticSettings(value: NBoolean);
		function  AutomaticSettings: NBoolean;
		procedure SetMirrorHorizontal(value: NBoolean);
		function  MirrorHorizontal: NBoolean;
		procedure SetMirrorVertical(value: NBoolean);
		function  MirrorVertical: NBoolean;
	end;

	TCameraMan = class(TObject)
	public
		constructor Create; overload;
		destructor Destroy; override;

		function CameraCount: NInt;
		function GetCamera(index: Integer): TCamera; overload;
		function GetCamera(Id: String): TCamera; overload;
	end;

	TFPScanner = class(TObject)
	private
		_handle: NHandle;
		_scannerId: string;

		_scannerImageCallback: array of TScannerImageCallback;
		_scannerFingerPlacedCallback: array of TScannerStatusCallback;
		_scannerFingerRemovedCallback: array of TScannerStatusCallback;

		constructor Create(hScanner: NHandle);
	public
		destructor Destroy(); override;

		property Handle: NHandle read _handle;
		property Id: string read _scannerId;

		function IsCapturing: NBoolean;

		procedure StopCapturing;
		procedure StartCapturing(oneImage: NBoolean = False);

		procedure SetScannedImageCallback(callback: TScannerImageCallback);
		procedure SetFingerRemovedCallback(callback: TScannerStatusCallback);
		procedure SetFingerPlacedCallback(callback: TScannerStatusCallback);
	end;

	TFPScannerMan = class(TObject)
	private
		_scannerAddedCallbacks: array of TScannerManCallback;
		_scannerRemovedCallbacks: array of TScannerManCallback;
	public
		class function GetAvailableScannerModules(): String;

		constructor Create; overload;
		constructor Create(scannerModules: String); overload;
		destructor Destroy; override;

		function ScannerCount: NInt;

		function GetScanner(index: NInt): TFPScanner; overload;
		function GetScanner(id: String): TFPScanner; overload;

		procedure SetAddedScannerCallback(callback: TScannerManCallback);
		procedure SetRemovedScannerCallback(callback: TScannerManCallback);
	end;

implementation
const
	DllName = 'NDevices.dll';

	CAMERAP_MIRROR_HORIZONTAL = 10200;
	CAMERAP_MIRROR_VERTICAL = 10201;
	CAMERAP_AUTOMATIC_SETTINGS = 10301;

type
	TCallBackScannerMan = procedure(scannerId: PNChar; Param: Pointer); stdcall;
	TCallBackScannerStatus = procedure(hScanner: NHandle; Param: Pointer); stdcall;
	TCallBackImageScanned = procedure(hScanner: NHandle; hImage: NHandle; Param: Pointer); stdcall;

{$IFDEF UNICODE}
	function NDevicesGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NDevicesGetInfoW';
{$ELSE}
	function NDevicesGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NDevicesGetInfoW';
{$ENDIF}

	function CameraManInitialize(): NResult stdcall; external dllName;
	procedure CameraManUninitialize(); stdcall; external dllName;
	function CameraManGetCameraCount(var value: NInt): NResult stdcall; external dllName;
	function CameraManGetCamera(index: NInt; var hCamera: NHandle): NResult stdcall; external dllName;
{$IFDEF UNICODE}
	function CameraManGetCameraById(id: PNChar; var hCamera: NHandle): NResult stdcall; external dllName name 'CameraManGetCameraByIdW';
	function CameraGetId(hCamera: NHandle; id: PNChar): NResult stdcall; external dllName name 'CameraGetIdW';
{$ELSE}
	function CameraManGetCameraById(id: PNChar; var hCamera: NHandle): NResult stdcall; external dllName name 'CameraManGetCameraByIdA';
	function CameraGetId(hCamera: NHandle; id: PNChar): NResult stdcall; external dllName name 'CameraGetIdA';
{$ENDIF}
	function CameraIsCapturing(hCamera: NHandle; var pValue: NBoolean): NResult stdcall; external dllName;
	function CameraStartCapturing(hCamera: NHandle): NResult stdcall; external dllName;
	function CameraStopCapturing(hCamera: NHandle): NResult stdcall; external dllName;
	function CameraGetCurrentFrame(hCamera: NHandle; var hImage: NHandle): NResult stdcall; external dllName;
	function CameraGetVideoFormats(hCamera: NHandle; arVideoFormats: Pointer): NResult stdcall; external dllName;
	function CameraGetVideoFormat(hCamera: NHandle; var videoFormat: TCameraVideoFormat): NResult stdcall; external dllName;
	function CameraSetVideoFormat(hCamera: NHandle; var videoFormat: TCameraVideoFormat): NResult stdcall; external dllName;

{$IFDEF UNICODE}
	function FPScannerGetId(hScanner: NHandle; id: PNChar): NResult stdcall; external dllName name 'FPScannerGetIdW';
{$ELSE}
	function FPScannerGetId(hScanner: NHandle; id: PNChar): NResult stdcall; external dllName name 'FPScannerGetIdA';
{$ENDIF}
	function FPScannerIsCapturing(hScanner: NHandle; var pValue: NBoolean): NResult stdcall; external dllName;
	function FPScannerStopCapturing(hScanner: NHandle): NResult stdcall; external dllName;
	function FPScannerStartCapturingForOneImage(hScanner: NHandle): NResult stdcall; external dllName;
	function FPScannerStartCapturing(hScanner: NHandle): NResult stdcall; external dllName;
	function FPScannerSetFingerPlacedCallback(hScanner: NHandle; pCallback: TCallBackScannerStatus; pParam: Pointer): NResult stdcall; external dllName;
	function FPScannerSetFingerRemovedCallback(hScanner: NHandle; pCallback: TCallBackScannerStatus; pParam: Pointer): NResult stdcall; external dllName;
	function FPScannerSetImageScannedCallback(hScanner: NHandle; pCallback: TCallBackImageScanned; pParam: Pointer): NResult stdcall; external dllName;

	function FPScannerManInitialize: NResult stdcall; external dllName;
{$IFDEF UNICODE}
	function FPScannerManInitializeWithModules(scannerModules: AnsiString): NResult stdcall; external dllName name 'FPScannerManInitializeWithModulesA';
	function FPScannerManInitializeWithModulesEmpty(scannerModules: NInt): NResult stdcall; external dllName name 'FPScannerManInitializeWithModulesW';
	function FPScannerManGetAvailableModules(var scannerModules: PNChar): NResult stdcall; external dllName name 'FPScannerManGetAvailableModulesW';
{$ELSE}
	function FPScannerManInitializeWithModules(scannerModules: AnsiString): NResult stdcall; external dllName name 'FPScannerManInitializeWithModulesA';
	function FPScannerManInitializeWithModulesEmpty(scannerModules: NInt): NResult stdcall; external dllName name 'FPScannerManInitializeWithModulesA';
	function FPScannerManGetAvailableModules(var scannerModules: PNChar): NResult stdcall; external dllName name 'FPScannerManGetAvailableModulesA';
{$ENDIF}
	procedure FPScannerManUninitialize; stdcall; external dllName;
{$IFDEF UNICODE}
	function FPScannerManSetScannerAddedCallback(pCallback: TCallBackScannerMan; pParam: Pointer): NResult stdcall; external dllName name 'FPScannerManSetScannerAddedCallbackW';
	function FPScannerManSetScannerRemovedCallback(pCallback: TCallBackScannerMan; pParam: Pointer): NResult stdcall; external dllName name 'FPScannerManSetScannerRemovedCallbackW';
	function FPScannerManGetScannerById(id: PNChar; var pValue: Pointer) : NResult stdcall; external dllName name 'FPScannerManGetScannerByIdW';
{$ELSE}
	function FPScannerManSetScannerAddedCallback(pCallback: TCallBackScannerMan; pParam: Pointer): NResult stdcall; external dllName name 'FPScannerManSetScannerAddedCallbackA';
	function FPScannerManSetScannerRemovedCallback(pCallback: TCallBackScannerMan; pParam: Pointer): NResult stdcall; external dllName name 'FPScannerManSetScannerRemovedCallbackA';
	function FPScannerManGetScannerById(szId: Pchar; var pValue: Pointer): NResult stdcall; external dllName name 'FPScannerManGetScannerByIdA';
{$ENDIF}
	function FPScannerManGetScannerCount(var value: NInt): NResult stdcall; external dllName;
	function FPScannerManGetScanner(index: NInt; var hScanner: NHandle): NResult stdcall; external dllName;

procedure ScannerAdded(scannerId: PNChar; Param: Pointer); stdcall;
var
	scannerMan: TFPScannerMan;
	i: NInt;
begin
	scannerMan := TFPScannerMan(Param);
	if ((scannerMan <> nil) and (Length(scannerMan._scannerAddedCallbacks) <> 0)) then
	begin
		for i := 0 to Length(scannerMan._scannerAddedCallbacks) - 1 do
		begin
			scannerMan._scannerAddedCallbacks[i](string(scannerId));
		end;
	end;
end;

procedure ScannerRemoved(scannerId: PNChar; Param: Pointer); stdcall;
var
	scannerMan: TFPScannerMan;
	i: NInt;
begin
	scannerMan := TFPScannerMan(Param);
	if ((scannerMan <> nil) and (Length(scannerMan._scannerRemovedCallbacks) <> 0)) then
	begin
		for i := 0 to Length(scannerMan._scannerRemovedCallbacks) - 1 do
		begin
			scannerMan._scannerRemovedCallbacks[i](string(scannerId));
		end;
	end;
end;

procedure FingerPlaced(hScanner: NHandle; Param: Pointer); stdcall;
var
	scanner: TFPScanner;
	i: NInt;
begin
	scanner := TFPScanner(Param);
	if (scanner <> nil) then
	begin
		for i := 0 to Length(scanner._scannerFingerPlacedCallback) - 1 do
		begin
			scanner._scannerFingerPlacedCallback[i](scanner);
		end;
	end;
end;

procedure FingerRemoved(hScanner: NHandle; Param: Pointer); stdcall;
var
	scanner: TFPScanner;
	i: NInt;
begin
	scanner := TFPScanner(Param);
	if (scanner <> nil) then
	begin
		for i := 0 to Length(scanner._scannerFingerRemovedCallback) - 1 do
		begin
			scanner._scannerFingerRemovedCallback[i](scanner);
		end;
	end;
end;

procedure FingerScanned(hScanner: NHandle; hImage: NHandle; Param: Pointer);
	stdcall;
var
	imagePtr: TNImage;
	imageCloned: TNImage;
	scanner: TFPScanner;
	i: NInt;
begin
	scanner := TFPScanner(Param);
	if (scanner <> nil) then
	begin
		imagePtr := TNImage.Create(hImage);
		imageCloned := imagePtr.Clone;
		for i := 0 to Length(scanner._scannerImageCallback) - 1 do
		begin
			scanner._scannerImageCallback[i](scanner, imageCloned);
		end;
		FreeAndNil(imageCloned);
	end;
end;

procedure NDevicesGetInfo(var info: TNLibraryInfo);
begin
	NCheck(NDevicesGetInfoInternal(info));
end;

constructor TCameraMan.Create;
begin
	inherited Create;
	NCheck(CameraManInitialize);
end;

destructor TCameraMan.Destroy;
begin
	CameraManUninitialize;
end;

function TCameraMan.CameraCount: NInt;
var
	value: NInt;
begin
	NCheck(CameraManGetCameraCount(value));
	Result := value;
end;

function TCameraMan.GetCamera(index: NInt): TCamera;
var
	hCamera: NHandle;
begin
	NCheck(CameraManGetCamera(index, hCamera));
	Result := TCamera.Create(hCamera);
end;

function TCameraMan.GetCamera(id: String): TCamera;
var
	hCamera: NHandle;
begin
	NCheck(CameraManGetCameraById(PChar(id), hCamera));
	Result := TCamera.Create(hCamera);
end;

constructor TCamera.Create(hCamera: NHandle);
var
	tmp: PNChar;
	res: NResult;
begin
	inherited Create;
	_handle := hCamera;

	_cameraId := '';
	res := CameraGetId(Handle, nil);
	NCheck(res);
	GetMem(tmp, (res + 1) * SizeOf(NChar));
	NCheck(CameraGetId(Handle, tmp));
	_cameraId := String(tmp);
	FreeMem(tmp);
end;

function TCamera.IsCapturing: NBoolean;
var
	value: NBoolean;
begin
	NCheck(CameraIsCapturing(Handle, value));
	Result := value;
end;

procedure TCamera.StartCapturing;
begin
	NCheck(CameraStartCapturing(Handle));
end;

procedure TCamera.StopCapturing;
begin
	NCheck(CameraStopCapturing(Handle));
end;

function TCamera.GetCurrentFrame: TNImage;
var
	image: NHandle;
begin
	NCheck(CameraGetCurrentFrame(Handle, image));
	Result := TNImage.Create(image);
end;

function TCamera.MirrorVertical: NBoolean;
	var value: NBoolean;
begin
	GetParameter(Handle, CAMERAP_MIRROR_VERTICAL, value);
	Result := value;
end;

function TCamera.MirrorHorizontal: NBoolean;
var value: NBoolean;
begin
	GetParameter(Handle, CAMERAP_MIRROR_HORIZONTAL, value);
	Result := value;
end;

function TCamera.AutomaticSettings: NBoolean;
var value: NBoolean;
begin
	GetParameter(Handle, CAMERAP_AUTOMATIC_SETTINGS, value);
	Result := value;
end;

procedure TCamera.SetAutomaticSettings(value: NBoolean);
begin
	SetParameter(Handle, CAMERAP_AUTOMATIC_SETTINGS, value);
end;

procedure TCamera.SetMirrorHorizontal(value: NBoolean);
begin
	SetParameter(Handle, CAMERAP_MIRROR_HORIZONTAL, value);
end;

procedure TCamera.SetMirrorVertical(value: NBoolean);
begin
	SetParameter(Handle, CAMERAP_MIRROR_VERTICAL, value);
end;

function TCamera.GetCurrentVideoFormat: TCameraVideoFormat;
var
	output: TCameraVideoFormat;
begin
	NCheck(CameraGetVideoFormat(Handle, output));
	Result := output;
end;

procedure TCamera.SetVideoFormat(var format: TCameraVideoFormat);
begin
	NCheck(CameraSetVideoFormat(Handle, format));
end;

function TCamera.GetVideoFormats: TArrayOfTCameraVideoFormat;
var
	res: NResult;
	formats: TArrayOfTCameraVideoFormat;
begin
	res := CameraGetVideoFormats(Handle, nil);
	NCheck(res);
	SetLength(formats, res);
	if (res > 0) then
	begin
		res := CameraGetVideoFormats(Handle, @(formats[0]));
		NCheck(res);
	end;
	Result := formats;
end;

constructor TFPScanner.Create(hScanner: NHandle);
var
	res: NResult;
	tmp: PNChar;
begin
	inherited Create;
	_handle := hScanner;

	_scannerId := '';
	res := FPScannerGetId(Handle, nil);
	NCheck(res);
	GetMem(tmp, (res + 1) * SizeOf(PNChar));
	NCheck(FPScannerGetId(Handle, tmp));
	_scannerId := String(tmp);
	FreeMem(tmp);

	SetLength(_scannerImageCallback, 0);
	SetLength(_scannerFingerPlacedCallback, 0);
	SetLength(_scannerFingerRemovedCallback, 0);

	NCheck(FPScannerSetImageScannedCallback(Handle, FingerScanned, self));
	NCheck(FPScannerSetFingerPlacedCallback(Handle, FingerPlaced, self));
	NCheck(FPScannerSetFingerRemovedCallback(Handle, FingerRemoved, self));
end;

destructor TFPScanner.Destroy;
begin
	inherited Destroy;
	SetLength(_scannerImageCallback, 0);
	SetLength(_scannerFingerPlacedCallback, 0);
	SetLength(_scannerFingerRemovedCallback, 0);
end;

procedure TFPScanner.SetFingerPlacedCallback(callback: TScannerStatusCallback);
var
	i: Integer;
begin
	i := Length(_scannerFingerPlacedCallback);
	SetLength(_scannerFingerPlacedCallback, i + 1);
	_scannerFingerPlacedCallback[i] := callback;
end;

procedure TFPScanner.SetFingerRemovedCallback(callback: TScannerStatusCallback);
var
	i: Integer;
begin
	i := Length(_scannerFingerRemovedCallback);
	SetLength(_scannerFingerRemovedCallback, i + 1);
	_scannerFingerRemovedCallback[i] := callback;
end;

procedure TFPScanner.SetScannedImageCallback(callback: TScannerImageCallback);
var
	i: Integer;
begin
	i := Length(_scannerImageCallback);
	SetLength(_scannerImageCallback, i + 1);
	_scannerImageCallback[i] := callback;
end;

procedure TFPScanner.StopCapturing;
begin
	NCheck(FPScannerStopCapturing(Handle));
end;

function TFPScanner.IsCapturing: NBoolean;
var
	value: NBoolean;
begin
	NCheck(FPScannerIsCapturing(Handle, value));
	Result := value;
end;

procedure TFPScanner.StartCapturing(oneImage: NBoolean = False);
begin
	if (oneImage) then
		NCheck(FPScannerStartCapturingForOneImage(Handle))
	else
		NCheck(FPScannerStartCapturing(Handle));
end;

class function TFPScannerMan.GetAvailableScannerModules: String;
var
	str: PNChar;
begin
	NCheck(FPScannerManGetAvailableModules(str));
	Result := String(str);
	NFree(str);
end;

constructor TFPScannerMan.Create;
begin
	inherited Create;
	SetLength(_scannerAddedCallbacks, 0);
	SetLength(_scannerRemovedCallbacks, 0);
	NCheck(FPScannerManInitializeWithModules(AnsiString(GetAvailableScannerModules)));
	NCheck(FPScannerManSetScannerAddedCallback(ScannerAdded, self));
	NCheck(FPScannerManSetScannerRemovedCallback(ScannerRemoved, self));
end;

constructor TFPScannerMan.Create(scannerModules: String);
begin
	inherited Create;
	SetLength(_scannerAddedCallbacks, 0);
	SetLength(_scannerRemovedCallbacks, 0);
	if (Length(scannerModules) = 0) then
		NCheck(FPScannerManInitializeWithModulesEmpty(0))
	else
		NCheck(FPScannerManInitializeWithModules(AnsiString(scannerModules)));
	NCheck(FPScannerManSetScannerAddedCallback(ScannerAdded, self));
	NCheck(FPScannerManSetScannerRemovedCallback(ScannerRemoved, self));
end;

destructor TFPScannerMan.Destroy;
begin
	FPScannerManUninitialize;
	SetLength(_scannerAddedCallbacks, 0);
	SetLength(_scannerRemovedCallbacks, 0);
end;

function TFPScannerMan.ScannerCount: Nint;
var
	value: NInt;
begin
	NCheck(FPScannerManGetScannerCount(value));
	Result := value;
end;

function TFPScannerMan.GetScanner(index: NInt): TFPScanner;
var
	handle: NHandle;
begin
	NCheck(FPScannerManGetScanner(index, handle));
	Result := TFPScanner.Create(Handle);
end;

function TFPScannerMan.GetScanner(id: string): TFPScanner;
var
	handle: NHandle;
begin
	NCheck(FPScannerManGetScannerById(PChar(id), handle));
	Result := TFPScanner.Create(handle);
end;

procedure TFPScannerMan.SetAddedScannerCallback(callback: TScannerManCallback);
var
	i: Integer;
begin
	i := Length(_scannerAddedCallbacks);
	SetLength(_scannerAddedCallbacks, i + 1);
	_scannerAddedCallbacks[i] := callback;
end;

procedure TFPScannerMan.SetRemovedScannerCallback
	(callback: TScannerManCallback);
var
	i: Integer;
begin
	i := Length(_scannerRemovedCallbacks);
	SetLength(_scannerRemovedCallbacks, i + 1);
	_scannerRemovedCallbacks[i] := callback;
end;

end.
