unit NCore;

interface

const
	CRLF = #13#10;

type
	NByte = Byte;
	NSByte = ShortInt;
	NUShort = Word;
	NShort = SmallInt;
	NUInt = LongWord;
	NInt = Integer;
	NULong = UInt64;
	NLong = Int64;

{$IF CompilerVersion >= 21} // Delphi 2010
	NSizeType = NativeUInt;
{$ELSE}
	NSizeType = NUInt;
{$IFEND} 
	NSSizeType = NativeInt;

	NSingle = Single;
	NDouble = Double;

	NFloat = NSingle;

	NBoolean = LongBool;

	NAChar = AnsiChar;
	NWChar = WideChar;

	NChar = Char;
	PNChar = PChar;

	NResult = NInt;

	NHandle = Pointer;

	TArrayOfNHandle = array of NHandle;
	TArrayOfNUInt = array of NUInt;
	TArrayOfNInt = array of NInt;
	TArrayOfNByte = array of NByte;
	TArrayOfArrayOfNByte = array of TArrayOfNByte;
	TArrayOfString = array of string;
	TArrayOfPointer = array of Pointer;


	TNIndexPair = record
		Index1: NInt;
		Index2: NInt;
	end;

	TNPoint = record
		X: NInt;
		Y: NInt;
	end;

	TNRect = record
		X: NInt;
		Y: NInt;
		Width: NInt;
		Height: NInt;
	end;

	TNLibraryInfo = record
		Title: array [0 .. 127] of NChar;
		Product: array [0 .. 127] of NChar;
		Company: array [0 .. 63] of NChar;
		Copyright: array [0 .. 191] of NChar;
		VersionMajor: NInt;
		VersionMinor: NInt;
		VersionBuild: NInt;
		VersionRevision: NInt;
		Activated: array [0 .. 255] of NChar;
	end;

	procedure NCoreGetInfo(var info: TNLibraryInfo);
	function  NErrorGetDefaultMessage(code: NResult): String;
	procedure NFree(pointer: Pointer);
	procedure NObjectFree(hObject: NHandle);
	procedure NObjectReset(hObject: NHandle);
	procedure NObjectClone(hObject: NHandle; var hDstObject: NHandle);

	procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NByte); overload;
	procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NSByte); overload;
	procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NInt); overload;
	procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NShort); overload;
	procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NDouble); overload;
	procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NBoolean); overload;
	procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NByte); overload;
	procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NSByte); overload;
	procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NInt); overload;
	procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NShort); overload;
	procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NDouble); overload;
	procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NBoolean); overload;

	procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NByte); overload;
	procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NDouble); overload;
	procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NUInt); overload;
	procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NInt); overload;
	procedure SetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; value: NDouble); overload;
	procedure SetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; value: NUInt); overload;
  procedure SetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; value: NInt); overload;

	function  NSucceeded(code: NResult): NBoolean;
	function  NFailed(code: NResult): NBoolean;
	procedure NRaiseError(code: NResult);
	procedure NCheck(code: NResult);

implementation
	uses Types, SysUtils;

const
	DllName = 'NCore.dll';

{$ifdef UNICODE}
	function NCoreGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NCoreGetInfoW';

	function NErrorGetDefaultMessageInternalEx(code: NResult; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NErrorGetDefaultMessageExW';
{$else}
	function NCoreGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NCoreGetInfoA';

	function NErrorGetDefaultMessageInternalEx(code: NResult; value: PNChar; valueSize: NInt): NResult stdcall; external dllName name 'NErrorGetDefaultMessageExA';
{$endif}

	function NObjectGetParameterWithPartEx(hObject: NHandle; partId: NUShort; parameterId: NUInt; typeId: NInt; pValue: Pointer; valueSize: NSizeType): NResult stdcall; external dllName;
	function NObjectSetParameterWithPartEx(hObject: NHandle; partId: NUShort; parameterId: NUInt; typeId: NInt; pValue: Pointer; valueSize: NSizeType): NResult stdcall; external dllName;

	procedure NFreeInternal(buffer: Pointer); stdcall; external dllName name 'NFree';
	procedure NObjectFreeInternal(hObject: NHandle); stdcall; external dllName name 'NObjectFree';
	function  NObjectResetInternal(hObject: NHandle): NResult stdcall; external dllName name 'NObjectReset';
	function  NObjectCloneInternal(hObject: NHandle; var hDstObject: NHandle): NResult stdcall; external dllName name 'NObjectClone';

procedure GetParameter(hObject: NHandle; parameterId: NUInt; pValue: Pointer; valueSize: NSizeType); overload;
begin
	NCheck(NObjectGetParameterWithPartEx(hObject, 0, parameterId, -1, pValue, valueSize));
end;

procedure SetParameter(hObject: NHandle; parameterId: NUInt; pValue: Pointer; valueSize: NSizeType); overload;
begin
	NCheck(NObjectSetParameterWithPartEx(hObject, 0, parameterId, -1, pValue, valueSize));
end;

procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NSByte); overload;
	var tmp: NSByte;
begin
	GetParameter(hObject, parameterId, @tmp, SizeOf(tmp));
	value := tmp;
end;

procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NInt); overload;
	var tmp: Integer;
begin
	GetParameter(hObject, parameterId, @tmp, SizeOf(tmp));
	value := tmp;
end;

procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NBoolean); overload;
	var tmp: NBoolean;
begin
	GetParameter(hObject, parameterId, @tmp, SizeOf(tmp));
	value := tmp;
end;

procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NDouble); overload;
	var tmp: Double;
begin
	GetParameter(hObject, parameterId, @tmp, SizeOf(tmp));
	value := tmp;
end;

procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NShort); overload;
	var tmp: SmallInt;
begin
	GetParameter(hObject, parameterId, @tmp, SizeOf(tmp));
	value := tmp;
end;

procedure GetParameter(hObject: NHandle; parameterId: NUInt; var value: NByte); overload;
	var tmp: Byte;
begin
	GetParameter(hObject, parameterId, @tmp, SizeOf(tmp));
	value := tmp;
end;

procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: Byte); overload;
begin
	SetParameter(hObject, parameterId, @(value), SizeOf(value));
end;

procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NSByte); overload;
begin
	SetParameter(hObject, parameterId, @(value), SizeOf(value));
end;

procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NShort); overload;
begin
	SetParameter(hObject, parameterId, @(value), SizeOf(value));
end;

procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NInt); overload;
begin
	SetParameter(hObject, parameterId, @(value), SizeOf(value));
end;

procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NBoolean); overload;
begin
	SetParameter(hObject, parameterId, @(value), SizeOf(value));
end;

procedure SetParameter(hObject: NHandle; parameterId: NUInt; value: NDouble); overload;
begin
	SetParameter(hObject, parameterId, @(value), SizeOf(value));
end;

procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NByte); overload;
begin
	NCheck(NObjectGetParameterWithPartEx(hObject, partId, parameterId, -1, @(value), SizeOf(value)));
end;

procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NUInt); overload;
begin
	NCheck(NObjectGetParameterWithPartEx(hObject, partId, parameterId, -1, @(value), SizeOf(value)));
end;

procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NDouble); overload;
begin
	NCheck(NObjectGetParameterWithPartEx(hObject, partId, parameterId, -1, @(value), SizeOf(value)));
end;

procedure GetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; var value: NInt); overload;
begin
	NCheck(NObjectGetParameterWithPartEx(hObject, partId, parameterId, -1, @(value), SizeOf(value)));
end;

procedure SetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; value: Double); overload;
begin
	NCheck(NObjectSetParameterWithPartEx(hObject, partId, parameterId, -1, @(value), SizeOf(value)));
end;

procedure SetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; value: NUInt); overload;
begin
	NCheck(NObjectSetParameterWithPartEx(hObject, partId, parameterId, -1, @(value), SizeOf(value)));
end;

procedure SetParameter(hObject: NHandle; partId: NUShort; parameterId: NUInt; value: NInt); overload;
begin
	NCheck(NObjectSetParameterWithPartEx(hObject, partId, parameterId, -1, @(value), SizeOf(value)));
end;

procedure NCoreGetInfo(var info: TNLibraryInfo);
begin
	NCheck(NCoreGetInfoInternal(info));
end;

procedure NFree(pointer: Pointer);
begin
	NFreeInternal(pointer);
end;

procedure NObjectReset(hObject: NHandle);
begin
	NCheck(NObjectResetInternal(hObject));
end;

procedure NObjectFree(hObject: NHandle);
begin
	NObjectFreeInternal(hObject);
end;

procedure NObjectClone(hObject: NHandle; var hDstObject: NHandle);
begin
	NCheck(NObjectCloneInternal(hObject, hDstObject));
end;

function NErrorGetDefaultMessage(code: NResult): String;
var res: NResult;
	str: String;
	point: PNChar;
begin
	str := '';
	res := NErrorGetDefaultMessageInternalEx(code, nil, 0);
	if (NFailed(res)) then
		NCheck(res)
	else
	begin
		res := res + 1;
		point := GetMemory(res);
		NCheck(NErrorGetDefaultMessageInternalEx(code, point, res));
		str := string(point);
		FreeMem(point);
	end;
	Result := str;
end;

function NSucceeded(code: NResult): NBoolean;
begin
	Result := code >= 0;
end;

function NFailed(code: NResult): NBoolean;
begin
	Result := code < 0;
end;

procedure NRaiseError(code: NResult);
	var str: string;
begin
	str := NErrorGetDefaultMessage(code);
	raise Exception.CreateFmt('Error:'#13#10' Code = %d'#13#10' ' + str, [code]);
end;

procedure NCheck(code: NResult);
begin
	if NFailed(code) then NRaiseError(code);
end;

end.
