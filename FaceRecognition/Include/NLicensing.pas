unit NLicensing;

interface

uses Windows, NCore;

	procedure NLicensingGetInfo(var info: TNLibraryInfo);

	function NLicenseObtain(address: String; port: String; products: String): NBoolean;
	procedure NLicenseRelease(products: String);
	function NLicenseObtainComponents(address: String; port: String; components: String): NBoolean;
	procedure NLicenseReleaseComponents(components: String);

implementation

const
	DllName = 'NLicensing.dll';

{$IFDEF UNICODE}
	function NLicensingGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NLicensingGetInfoW';
	function NLicenseObtainInternal(address: PNChar; port: PNChar; products: PNChar; var abailable: NBoolean): NResult stdcall; external dllName name 'NLicenseObtainW';
	function NLicenseReleaseInternal(products: PNChar): NResult stdcall; external dllName name 'NLicenseReleaseW';
	function NLicenseObtainComponentsInternal(address: PNChar; port: PNChar; components: PNChar; var abailable: NBoolean): NResult stdcall; external dllName name 'NLicenseObtainComponentsW';
	function NLicenseReleaseComponentsInternal(components: PNChar): NResult stdcall; external dllName name 'NLicenseReleaseComponentsW';
{$ELSE}
	function NLicensingGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NLicensingGetInfoA';
	function NLicenseObtainInternal(address: PNChar; port: PNChar; products: PNChar; var abailable: NBoolean): NResult stdcall; external dllName name 'NLicenseObtainA';
	function NLicenseReleaseInternal(products: PNChar): NResult stdcall; external dllName name 'NLicenseReleaseA';
	function NLicenseObtainComponentsInternal(address: PNChar; port: PNChar; components: PNChar; var abailable: NBoolean): NResult stdcall; external dllName name 'NLicenseObtainComponentsA';
	function NLicenseReleaseComponentsInternal(components: PNChar): NResult stdcall; external dllName name 'NLicenseReleaseComponentsA';
{$ENDIF}

procedure NLicensingGetInfo(var info: TNLibraryInfo);
begin
	NCheck(NLicensingGetInfoInternal(info));
end;

function NLicenseObtain(address: String; port: String; products: String): NBoolean;
var
	tmpAddress, tmpPort, tmpProducts: PNChar;
	available: NBoolean;
begin
	tmpAddress := PChar(address);
	tmpPort := PChar(port);
	tmpProducts := PChar(products);
	NCheck(NLicenseObtainInternal(tmpAddress, tmpPort, tmpProducts, available));
	Result := available;
end;

procedure NLicenseRelease(products: String);
var
	tmpProducts: PChar;
begin
	tmpProducts := PChar(products);
	NCheck(NLicenseReleaseInternal(tmpProducts));
end;

function NLicenseObtainComponents(address: String; port: String; components: String): NBoolean;
var
	tmpAddress, tmpPort, tmpProducts: PChar;
	available: NBoolean;
begin
	tmpAddress := PChar(address);
	tmpPort := PChar(port);
	tmpProducts := PChar(components);
	NCheck(NLicenseObtainComponentsInternal(tmpAddress, tmpPort, tmpProducts, available));
	Result := available;
end;

procedure NLicenseReleaseComponents(components: String);
var
	tmpProducts: PChar;
begin
	tmpProducts := PChar(components);
	NCheck(NLicenseReleaseComponentsInternal(tmpProducts));
end;

end.
