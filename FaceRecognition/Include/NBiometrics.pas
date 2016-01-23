unit NBiometrics;

interface

uses Windows, SysUtils, NCore, NMedia;

const
	N_MODE_GENERAL = 0;
	N_MODE_DIGITALPERSONA_UAREU = 100;
	N_MODE_BIOMETRIKA_FX2000 = 200;
	N_MODE_BIOMETRIKA_FX3000 = 201;
	N_MODE_KEYTRONIC_SECUREDESKTOP = 300;
	N_MODE_IDENTIX_TOUCHVIEW = 400;
	N_MODE_IDENTIX_DFR2090 = 401;
	N_MODE_PRECISEBIOMETRICS_100CS = 500;
	N_MODE_UPEK_TOUCHCHIP = 600;
	N_MODE_IDENTICATORTECHNOLOGY_DF90 = 700;
	N_MODE_ATMEL_FINGERCHIP = 900;
	N_MODE_BMF_BLP100 = 1000;
	N_MODE_SECUGEN_HAMSTER = 1100;
	N_MODE_CROSSMATCH_VERIFIER300 = 1300;
	N_MODE_NITGEN_FINGKEY_HAMSTER = 1400;
	N_MODE_TESTECH_BIOI = 1500;
	N_MODE_DIGENT_IZZIX = 1600;
	N_MODE_STARTEK_FM200 = 1700;
	N_MODE_FUJITSU_MBF200 = 1800;
	N_MODE_FUTRONIC_FS80 = 1900;
	N_MODE_LIGHTUNING_LTTC500 = 2000;
	N_MODE_TACOMA_CMOS = 2100;

	procedure NBiometricsGetInfo(var info: TNLibraryInfo);

type
	TNBiometricType = (nbtFacialFeatures = $00000002,
		nbtFingerprint = $00000008, nbtIris = $00000010,
		nbtPalmPrint = $00020000, nbtUnused = MaxInt);

	TNMPosition = (Unknown = 0, RightThumb = 1, RightIndex = 2,
		RightMiddle = 3, RightRing = 4, RightLittle = 5, LeftThumb = 6,
		LeftIndex = 7, LeftMiddle = 8, LeftRing = 9, LeftLittle = 10,
		nmpUnused = MaxInt);

	TNMImpressionType = (LiveScanPlain = 0, LiveScanRolled = 1,
		NonliveScanPlain = 2, NonliveScanRolled = 3, LatentImpression = 4,
		LatentTracing = 5, LatentPhoto = 6, LatentLift = 7, Swipe = 8,
		LiveScanContactless = 9, nmiUnused = MaxInt);

	TNMMinutiaType = (nmmtUnknown = 0, nmmtEnd = 1, nmvfmtBifurcation = 2,
		nmmUnused = MaxInt);

	TNMMinutia = record
		X: NUShort;
		Y: NUShort;
		T: TNMMinutiaType;
		Angle: NByte;
		Quality: NByte;
		Curvature: NByte;
		G: NByte;
	end;

	TNMMinutiaNeighbour = record
		index: NInt;
		RidgeCount: NByte;
	end;

	TNfeExtractionStatus = (nfeesTemplateCreated = 1, nfeesTooFewMinutiae = 90,
		nfeesQualityCheckFailed = 100, nfeesMatchingFailed = 200,
		nfeesUnused = MaxInt);

	TNleExtractionStatus = (nleesNone = 0, nleesTemplateCreated = 1,
		nleesFaceNotDetected = 2, nleesEyesNotDetected = 3,
		nleesFaceTooCloseToImageBorder = 4,
		nleesQualityCheckGrayscaleDensityFailed = 100,
		nleesQualityCheckExposureFailed = 101,
		nleesQualityCheckSharpnessFailed = 102, nleesLivenessCheckFailed = 200,
		nleesGeneralizationFailed = 300, nleesUnused = MaxInt);

	TNfeReturnedImage = (nferiNone = 0, nferiBinarized = 1,
		nferiSkeletonized = 2, nferiUnused = MaxInt);

	TNfeTemplateSize = (nfetsLarge = 256, nfetsSmall = 0, nfetsUnused = MaxInt);

	TNleTemplateSize = (nletsSmall = 0, nletsCompact = 1, nletsMedium = 64,
		nletsLarge = 128, nletsUnused = MaxInt);

	TNMSpeed = (nmsLow = 0, nmsMedium = 128, nmsHigh = 256);

	TNleRotation = record
		Yaw: NShort;
		Pitch: NShort;
		Roll: NShort;
	end;

	TNleFace = record
		Rectangle: TNRect;
		Rotation: TNleRotation;
		Confidence: NDouble;
	end;

	TNleEyes = record
		First: TNPoint;
		FirstConfidence: NDouble;
		Second: TNPoint;
		SecondConfidence: NDouble;
	end;

	TNLFeaturePoint = record
		Code: NUShort;
		X: NUShort;
		Y: NUShort;
		Confidence: NByte;
	end;

	TNleDetectionDetails = record
		FaceAvailable: NBoolean;
		Padding1: NInt;
		Face: TNleFace;
		EyesAvailable: NBoolean;
		Padding2: NInt;
		Eyes: TNleEyes;
		Gender: NInt;
		Expression: NInt;
		Properties: NInt;
		GenderConfidence: NByte;
		ExpressionConfidence: NByte;
		PropertiesConfidence: NByte;
		ReservedConfidence: array [0 .. 8] of NByte;
		RightEyeCenter: TNLFeaturePoint;
		LeftEyeCenter: TNLFeaturePoint;
		NoseTip: TNLFeaturePoint;
		MouthCenter: TNLFeaturePoint;
		Reserved: array [0 .. 3] of TNLFeaturePoint;
		Points: array [0 .. 67] of TNLFeaturePoint;
	end;

	// Extend this type according to "NMMatchDetails.h" if additional information required
	// i.e. MatedMinutia
	TNMMatchDetails = record
		Score: NInt;
		FingerDetails: NHandle;
		FaceDetails: NHandle;
	end;

	TArrayOfTNleFace = array of TNleFace;

	TNFRecord = class(TObject)
	private
		_handle: NHandle;
		constructor Create(hNFRecord: NHandle); overload;
	public
		destructor Destroy; override;

		property Handle: NHandle read _handle;

		function MinutiaCount: NInt;
		function Minutia(index: NInt): TNMMinutia;

		function G: NByte;

		function Save: TArrayOfNByte; overload;
		function Save(flags: NUInt): TArrayOfNByte; overload;

		class function CreateFromMemory(arr: TArrayOfNByte): TNFRecord;
		class procedure Check(arr: TArrayOfNByte);
	end;

	TNLRecord = class(TObject)
	private
		_handle: NHandle;
		constructor Create(hNLRecord: NHandle); overload;
		constructor Create(flags: NUInt); overload;
	public
		destructor Destroy(); override;

		property Handle: NHandle read _handle;

		function Clone(): TNLRecord;

		function Quality: NByte;

		function Size: NSizeType; overload;
		function Size(flags: NUInt): NSizeType; overload;
	end;

	TNLTemplate = class(TObject)
	private
		_handle: Pointer;
		constructor Create(hNLTemplate: NHandle); overload;
	public
		destructor Destroy(); override;
		property Handle: NHandle read _handle;

		function Clone(): TNLTemplate;

		function RecordCount: NInt;
		function Size: NSizeType; overload;
		function Size(flags: NUInt): NSizeType; overload;

		function Save: TArrayOfNByte; overload;
		function Save(flags: NUInt): TArrayOfNByte; overload;

		class function CreateFromMemory(arr: TArrayOfNByte): TNLTemplate;
		class procedure Check(arr: TArrayOfNByte);
	end;

	TArrayOfTNFRecord = array of TNFRecord;
	TArrayOfTNLRecord = array of TNLRecord;
	TArrayOfTNLTemplate = array of TNLTemplate;

	TNLExtractor = class
	private
		_handle: NHandle;

		_minIod: NInt;
		_maxIod: NInt;

		_faceConfidenceThreshold: NDouble;
		_faceQualityThreshold: NByte;
		_maxRecordsInTemplate: NInt;

		_useLiveliness: NBoolean;
		_livelinessThreshold: NDouble;

		_favorLargestFace: NBoolean;
		_templateSize: TNleTemplateSize;
		_maxRollAngleDeviation: NShort;

		function GetMinIOD: NInt;
		function GetMaxIOD: NInt;
		function GetFaceConfidenceThreshold: NDouble;
		function GetUseLiveness: NBoolean;
		function GetLivenessThreshold: NDouble;
		function GetFaceQualityThreshold: NByte;
		function GetFavorLargestFace: NBoolean;
		function GetTemplateSize: TNleTemplateSize;
		function GetMaxRollAngleDeviation: NShort;
		function GetMaxRecords: NInt;

		procedure Initialize;
	public
		constructor Create(); overload;
		destructor Destroy(); override;
		procedure Reset();

		property Handle: NHandle read _handle;

		property MinIOD: NInt read _minIod;
		property MaxIOD: NInt read _maxIod;
		property FaceConfidenceThreshold: NDouble read _faceConfidenceThreshold;
		property UseLiveness: NBoolean read _useLiveliness;
		property LivenessThreshold: NDouble read _livelinessThreshold;
		property MaxRecordsInTemplate: NInt read _maxRecordsInTemplate;
		property FaceQualityThreshold: NByte read _faceQualityThreshold;
		property FavorLargestFace: NBoolean read _favorLargestFace;
		property TemplateSize: TNleTemplateSize read _templateSize;
		property MaxRollAngleDeviation: NShort read _maxRollAngleDeviation;

		procedure SetMinIOD(value: NInt);
		procedure SetMaxIOD(value: NInt);
		procedure SetFaceConfidenceThreshold(value: NDouble);
		procedure SetUseLiveness(value: NBoolean);
		procedure SetLivenessThreshold(value: NDouble);
		procedure SetFaceQualityThreshold(value: NByte);
		procedure SetMaxRecords(value: NInt);
		procedure SetFavorLargestFace(value: NBoolean);
		procedure SetTemplateSize(value: TNleTemplateSize);
		procedure SetMaxRollAngleDeviation(value: NShort);

		function DetectFaces(image: TNImage): TArrayOfTNleFace;
		function DetectFacialFeatures(image: TNImage; var face: TNleFace): TNleDetectionDetails;
		function DetectFace(image: TNImage; var face: TNleFace): NBoolean;

		procedure ExtractStart(numberOfFrames: NInt);
		function ExtractNext(image: TNImage; var detectionDetails: TNleDetectionDetails; var baseIndex: NInt; var template: TNLTemplate): TNleExtractionStatus;
		function Extract(image: TNImage; var template: TNLTemplate; var detectionDetails: TNleDetectionDetails): TNleExtractionStatus;
		function ExtractUsingDetails(image: TNImage; var detectionDetails: TNleDetectionDetails; var template: TNLTemplate): TNleExtractionStatus;
		function Generalize(templates: TArrayOfTNLTemplate; var baseIndex: NInt; var generalizedTemplate: TNLTemplate): TNleExtractionStatus;

		class function Compress(templateSrc: TNLTemplate; dstTemplateSize: TNleTemplateSize): TNLTemplate;
	end;

	TNFExtractor = class
	private
		_handle: Pointer;

		_returnedImage: TNfeReturnedImage;
		_useQuality: NBoolean;
		_qualityThreshold: NByte;
		_scannerMode: NInt;
		_templateSize: TNfeTemplateSize;
		_generalizationThreshold: NInt;
		_generalizationMaximalRotation: NByte;

		function GetScannerMode: NInt;
		function GetUseQuality: NBoolean;
		function GetReturnedImage: TNfeReturnedImage;
		function GetTemplateSize: TNfeTemplateSize;
		function GetQualityThreshold: NByte;
		function GetGeneralizationMaximalRotation: NByte;
		function GetGeneralizationThreshold: NInt;

		procedure Initialize;
	public
		Constructor Create;
		Destructor Destroy; override;
		procedure  Reset();

		property Handle: NHandle read _handle;

		property ReturnedImage: TNfeReturnedImage read _returnedImage;
		property UseQuality: NBoolean read _useQuality;
		property QualityThreshold: NByte read _qualityThreshold;
		property ScannerMode: NInt read _scannerMode;
		property TemplateSize: TNfeTemplateSize read _templateSize;
		property GeneralizationThreshold: NInt read _generalizationThreshold;
		property GeneralizationMaximalRotation: NByte read _generalizationMaximalRotation;

		procedure SetScannerMode(mode: NInt);
		procedure SetUseQuality(value: NBoolean);
		procedure SetReturnedImage(value: TNfeReturnedImage);
		procedure SetTemplateSize(value: TNfeTemplateSize);
		procedure SetQualityThreshold(value: NByte);
		procedure SetGeneralizationMaximalRotation(value: NByte);
		procedure SetGeneralizationThreshold(value: NInt);

		function Extract(image: TNImage; position: TNMPosition; impression: TNMImpressionType; var template: TNFRecord): TNfeExtractionStatus;
		function Generalize(templates: TArrayOfTNFRecord; var baseTemplateIndex: NInt; var extractionStatus: TNfeExtractionStatus): TNFRecord;
	end;

	TNMatcher = class(TObject)
	private
		_handle: Pointer;

		_matchingThreshold: NInt;

		_fingersMode: NInt;
		_fingersMaximalRotation: NByte;
		_fingersMatchingSpeed: TNMSpeed;

		_facesMatchingSpeed: TNMSpeed;

		function GetMatchingThreshold(): NInt;
		function GetFingersMode: NInt;
		function GetFingersMaximalRotation: NByte;
		function GetFingersMatchingSpeed: TNMSpeed;
		function GetFacesMatchingSpeed: TNMSpeed;

		procedure Initialize;
	public
		Constructor Create(); overload;
		Destructor Destroy; override;
		procedure Reset();

		property Handle: NHandle read _handle;

		property MatchingThreshold: NInt read _matchingThreshold;

		property FingersMaximalRotation: NByte read _fingersMaximalRotation;
		property FingersMode: NInt read _fingersMode;
		property FingersMatchingSpeed: TNMSpeed read _fingersMatchingSpeed;

		property FacesMatchingSpeed: TNMSpeed read _facesMatchingSpeed;

		procedure SetMatchingThreshold(value: NInt);

		procedure SetFingersMaximalRotation(value: NByte);
		procedure SetFingersMode(value: NInt);
		procedure SetFingersMatchingSpeed(value: TNMSpeed);

		procedure SetFacesMatchingSpeed(value: TNMSpeed);

		procedure IdentifyStart(template: TArrayOfNByte);
		function  IdentifyNext(template: TArrayOfNByte): NInt;
		procedure IdentifyEnd;

		function Verify(template1: TArrayOfNByte; template2: TArrayOfNByte): NInt;
	end;

implementation

// -------------------------------------
// Constants
// -------------------------------------

const
	dllNameCore = 'NCore.dll';
	dllName = 'NBiometrics.dll';

	NLEP_MIN_IOD = 10101;
	NLEP_MAX_IOD = 10102;
	NLEP_FACE_CONFIDENCE_THRESHOLD = 10103;
	NLEP_FAVOR_LARGEST_FACE = 10104;
	NLEP_MAX_ROLL_ANGLE_DEVIATION = 10105;
	NLEP_FACE_QUALITY_THRESHOLD = 10350;
	NLEP_TEMPLATE_SIZE = 10360;
	NLEP_USE_LIVENESS_CHECK = 10402;
	NLEP_LIVENESS_THRESHOLD = 10403;
	NLEP_MAX_RECORDS_PER_TEMPLATE = 10408;

	NFEP_TEMPLATE_SIZE = 100;
	NFEP_RETURNED_IMAGE = 190;
	NFEP_GENERALIZATION_THRESHOLD = 300;
	NFEP_GENERALIZATION_MAXIMAL_ROTATION = 301;
	NFEP_MODE = 1000;
	NFEP_USE_QUALITY = 900;
	NFEP_QUALITY_THRESHOLD = 910;

	NMP_MATCHING_THRESHOLD = 100;

	NMP_FINGERS_MATCHER_BASE = 3536;
	NMP_FINGERS_MAXIMAL_ROTATION = NMP_FINGERS_MATCHER_BASE + 201;
	NMP_FINGERS_MATCHING_SPEED = NMP_FINGERS_MATCHER_BASE + 220;
	NMP_FINGERS_MODE = NMP_FINGERS_MATCHER_BASE + 1000;

	NMP_FACES_MATCHER_BASE = 11536;
	NMP_FACES_MATCHING_SPEED = NMP_FACES_MATCHER_BASE + 1;

	function NObjectGetSize(hRecord: NHandle; flags: NUInt; var size: NSizeType): NResult stdcall; external dllNameCore;
	function NObjectSaveToMemoryDst(hTemplate: NHandle; buffer: Pointer; bufferSize: NSizeType; flags: NUInt; var size: NSizeType): NResult stdcall; external dllNameCore;

{$IFDEF UNICODE}
	function NBiometricsGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NBiometricsGetInfoW';
{$ELSE}
	function NBiometricsGetInfoInternal(var info: TNLibraryInfo): NResult stdcall; external dllName name 'NBiometricsGetInfoA';
{$ENDIF}

	function NleCreate(var hExtractor: NHandle): NResult; stdcall; external dllName;
	function NleDetectFace(hExtractor: NHandle; hImage: NHandle; var detected: NBoolean; var face: TNleFace): NResult stdcall; external dllName;
	function NleDetectFaces(hExtractor: NHandle; hImage: NHandle; var faceCount: NInt; var arrFaces: Pointer): NResult stdcall; external dllName;
	function NleDetectFacialFeatures(hExtractor: NHandle; hImage: NHandle; var face: TNleFace; var detectionDetails: TNleDetectionDetails): NResult stdcall; external dllName;
	function NleExtract(hExtractor: NHandle; hImage: NHandle; var detectionDetails: TNleDetectionDetails; var extractionStatus: TNleExtractionStatus; var template: NHandle): NResult stdcall; external dllName;
	function NleExtractUsingDetails(hExtractor: NHandle; hImage: NHandle; var detectionDetails: TNleDetectionDetails; var extractionStatus: TNleExtractionStatus; var template: Pointer): NResult stdcall; external dllName;
	function NleExtractStart(hExtractor: NHandle; durationInFrames: NInt): NResult stdcall; external dllName;
	function NleExtractNextEx(hExtractor: NHandle; hImage: NHandle; var detectionDetails: TNleDetectionDetails; var baseFrameIndex: NInt; var template: NHandle; var extractionStatus: TNleExtractionStatus): NResult stdcall; external dllName;
	function NleGeneralizeEx(hExtractor: NHandle; templateCount: NInt; arTemplates: NHandle; var extractionStatus: TNleExtractionStatus; var baseTemplateIndex: NInt; var resultTemplate: NHandle): NResult stdcall; external dllName;
	function NleCompress(hExtractor: NHandle; firstTemplate: NHandle; var secondTemplate: NHandle): NResult stdcall; external dllName;
	function NleCompressEx(firstTemplate: NHandle; TemplateSize: TNleTemplateSize; var secondTemplate: NHandle): NResult stdcall; external dllName;

	function NfeCreate(var hExtractor: NHandle): NResult stdcall; external dllName;
	function NfeExtract(hExtractor: NHandle; hImage: NHandle; position: TNMPosition; impressionType: TNMImpressionType; var extractionStatus: TNfeExtractionStatus; var hRecord: NHandle): NResult stdcall; external dllName;
	function NfeGeneralizeEx(hExtractor: NHandle; recordCount: NInt; records: Pointer; var extractionStatus: TNfeExtractionStatus; var baseTemplateIndex: NInt; var hRecord: NHandle): NResult stdcall; external dllName;

	function NLRecordCreate(flags: NUInt; var hRecord: NHandle): NResult stdcall; external dllName;
	function NLRecordGetQuality(hRecord: NHandle; var value: NByte): NResult stdcall; external dllName;

	function NLTemplateGetRecordCount(hTemplate: NHandle; var value: NInt): NResult stdcall; external dllName;
	function NLTemplateCreateFromMemory(pBuffer: Pointer; bufferSize: NSizeType; flags: NUInt; var size: NSizeType; var hTemplate: NHandle): NResult stdcall; external dllName;
	function NLTemplateCheck(pBuffer: Pointer; bufferSize: NSizeType): NResult stdcall; external dllName;

	function NFRecordGetMinutiaCount(hRecord: NHandle; var value: NInt): NResult stdcall; external dllName;
	function NFRecordGetMinutia(hRecord: NHandle; index: NInt; var value: TNMMinutia): NResult stdcall; external dllName;
	function NFRecordGetG(hRecord: NHandle; var balue: NByte): NResult stdcall; external dllName;
	function NFRecordCreateFromMemory(buffer: Pointer; bufferSize: NSizeType; flags: NUInt; recordInfo: Pointer; var hRecord: NHandle): NResult stdcall; external dllName;
	function NFRecordCheck(buffer: NHandle; bufferSize: NSizeType): NResult stdcall; external dllName;

	function NMCreate(var hMatcher: NHandle): NResult stdcall; external dllName;
	function NMIdentifyStart(hMatcher: NHandle; pTempate: Pointer; templateSize: NSizeType; ppMatchDetails: Pointer): NResult stdcall; external dllName;
	function NMIdentifyNext(hMatcher: NHandle; pTemplate: Pointer; templateSize: NSizeType; ppMatchDetails: Pointer; var score: NInt): NResult stdcall; external dllName;
	function NMIdentifyEnd(hMatcher: NHandle): NResult stdcall; external dllName;
	function NMVerify(hMatcher: NHandle; template1: Pointer; template1Size: NSizeType; tempalte2: Pointer; template2Size: NSizeType; ppMatchDetails: NHandle; var score: NInt): NResult stdcall; external dllName;

	function NMMatchDetailsFree(hMatchDetails: NHandle): NResult stdcall; external dllName;

procedure NBiometricsGetInfo(var info: TNLibraryInfo);
begin
	NCheck(NBiometricsGetInfoInternal(info));
end;

constructor TNLExtractor.Create();
begin
	inherited Create;
	NCheck(NleCreate(_handle));
	Initialize;
end;

destructor TNLExtractor.Destroy();
begin
	NObjectFree(_handle);
	inherited;
end;

procedure TNLExtractor.Initialize;
begin
	_minIod := GetMinIOD;
	_maxIod := GetMaxIOD;
	_faceConfidenceThreshold := GetFaceConfidenceThreshold;
	_livelinessThreshold := GetLivenessThreshold;
	_useLiveliness := GetUseLiveness;
	_faceQualityThreshold := GetFaceQualityThreshold;
	_templateSize := GetTemplateSize;
	_maxRecordsInTemplate := GetMaxRecords;
	_maxRollAngleDeviation := GetMaxRollAngleDeviation;
	_favorLargestFace := GetFavorLargestFace;
end;

procedure TNLExtractor.Reset();
begin
	NObjectReset(_handle);
	Initialize;
end;

function TNLExtractor.DetectFaces(image: TNImage): TArrayOfTNleFace;
var
	addressOfArray: Pointer;
	faceCount: Integer;
	pArFaces: TArrayOfTNleFace;
begin
	NCheck(NleDetectFaces(Handle, image.Handle, faceCount, addressOfArray));
	if (faceCount > 0) then
	begin
		SetLength(pArFaces, faceCount);
		CopyMemory(@(pArFaces[0]), addressOfArray, SizeOf(TNleFace)
				* faceCount);
		NFree(addressOfArray);
	end;
	Result := pArFaces;
end;

function TNLExtractor.DetectFace(image: TNImage; var face: TNleFace): NBoolean;
var
	detected: NBoolean;
begin
	NCheck(NleDetectFace(Handle, image.Handle, detected, face));
	Result := detected;
end;

function TNLExtractor.DetectFacialFeatures(image: TNImage; var face: TNleFace): TNleDetectionDetails;
var
	details: TNleDetectionDetails;
begin
	NCheck(NleDetectFacialFeatures(Handle, image.Handle, face, details));
	Result := details;
end;

function TNLExtractor.Extract(image: TNImage; var template: TNLTemplate;
	var detectionDetails: TNleDetectionDetails): TNleExtractionStatus;
var
	tmpTemplate: NHandle;
	extrStatus: TNleExtractionStatus;
	vDetectionDetails: TNleDetectionDetails;
begin
	NCheck(NleExtract(_handle, image.handle, vDetectionDetails, extrStatus, tmpTemplate));
	detectionDetails := vDetectionDetails;
	if (extrStatus = nleesTemplateCreated) Then
	Begin
		template := TNLTemplate.Create(tmpTemplate);
	End;
	Result := extrStatus;
end;

function TNLExtractor.ExtractUsingDetails(image: TNImage;
	var detectionDetails: TNleDetectionDetails; var template: TNLTemplate)
	: TNleExtractionStatus;
var
	tmpTemplate: NHandle;
	extrStatus: TNleExtractionStatus;
begin
	NCheck(NleExtractUsingDetails(Handle, image.Handle, detectionDetails, extrStatus, tmpTemplate));
	if (extrStatus = nleesTemplateCreated) Then
	Begin
		template := TNLTemplate.Create(tmpTemplate);
	End;
	Result := extrStatus;
end;

function TNLExtractor.Generalize(templates: TArrayOfTNLTemplate; var baseIndex: NInt; var generalizedTemplate: TNLTemplate): TNleExtractionStatus;
var
	i: NInt;
	tmpPointer: NHandle;
	arrayOfPointers: TArrayOfNHandle;
	extractionStatus: TNleExtractionStatus;
begin
	SetLength(arrayOfPointers, Length(templates));
	for i := 0 to Length(templates) - 1 do
	begin
		arrayOfPointers[i] := templates[i].Handle;
	end;

	NCheck(NleGeneralizeEx(Handle, Length(arrayOfPointers), @(arrayOfPointers[0]), extractionStatus, baseIndex, tmpPointer));
	if (tmpPointer <> nil) then
		generalizedTemplate := TNLTemplate.Create(tmpPointer)
	else
		generalizedTemplate := nil;
	Result := extractionStatus;
end;

class function TNLExtractor.Compress(templateSrc: TNLTemplate; dstTemplateSize: TNleTemplateSize): TNLTemplate;
var
	tmpPointer: Nhandle;
begin
	NCheck(NleCompressEx(templateSrc.Handle, dstTemplateSize, tmpPointer));
	if (tmpPointer <> nil) then
		Result := TNLTemplate.Create(tmpPointer)
	else
		Result := nil;
end;

procedure TNLExtractor.ExtractStart(numberOfFrames: NInt);
begin
	NCheck(NleExtractStart(Handle, numberOfFrames));
end;

function TNLExtractor.ExtractNext(image: TNImage;
	var detectionDetails: TNleDetectionDetails; var baseIndex: NInt;
	var template: TNLTemplate): TNleExtractionStatus;
var
	tmpTemplate: NHandle;
	extrStatus: TNleExtractionStatus;
begin
	NCheck(NleExtractNextEx(_handle, image.handle, detectionDetails, baseIndex,
		tmpTemplate, extrStatus));
	if (extrStatus = nleesTemplateCreated) then
		template := TNLTemplate.Create(tmpTemplate);
	Result := extrStatus;
end;

function TNLExtractor.GetTemplateSize: TNleTemplateSize;
var
	tmp: NInt;
begin
	GetParameter(_handle, NLEP_TEMPLATE_SIZE, tmp);
	Result := TNleTemplateSize(tmp);
end;

procedure TNLExtractor.SetTemplateSize(value: TNleTemplateSize);
begin
	SetParameter(_handle, NLEP_TEMPLATE_SIZE, Integer(value));
	_templateSize := value;
end;

procedure TNLExtractor.SetMaxRollAngleDeviation(value: NShort);
begin
	SetParameter(_handle, NLEP_MAX_ROLL_ANGLE_DEVIATION, value);
	_maxRollAngleDeviation := value;
end;

function TNLExtractor.GetMaxRollAngleDeviation: NShort;
var
	tmp: NShort;
begin
	GetParameter(_handle, NLEP_MAX_ROLL_ANGLE_DEVIATION, tmp);
	Result := tmp;
end;

procedure TNLExtractor.SetFavorLargestFace(value: NBoolean);
begin
	SetParameter(_handle, NLEP_FAVOR_LARGEST_FACE, value);
	_favorLargestFace := value;
end;

function TNLExtractor.GetFavorLargestFace: NBoolean;
var
	tmp: NBoolean;
begin
	GetParameter(_handle, NLEP_FAVOR_LARGEST_FACE, tmp);
	Result := tmp;
end;

function TNLExtractor.GetMaxRecords: NInt;
var
	tmp: NInt;
begin
	GetParameter(_handle, NLEP_MAX_RECORDS_PER_TEMPLATE, tmp);
	Result := tmp;
end;

procedure TNLExtractor.SetMaxRecords(value: NInt);
begin
	SetParameter(_handle, NLEP_MAX_RECORDS_PER_TEMPLATE, value);
	_maxRecordsInTemplate := value;
end;

function TNLExtractor.GetFaceQualityThreshold: NByte;
var
	tmp: NByte;
begin
	GetParameter(_handle, NLEP_FACE_QUALITY_THRESHOLD, tmp);
	Result := tmp;
end;

procedure TNLExtractor.SetFaceQualityThreshold(value: NByte);
begin
	SetParameter(_handle, NLEP_FACE_QUALITY_THRESHOLD, value);
	_faceQualityThreshold := value;
end;

procedure TNLExtractor.SetMinIOD(value: NInt);
begin
	SetParameter(_handle, NLEP_MIN_IOD, value);
	_minIod := value;
end;

function TNLExtractor.GetMinIOD: NInt;
var
	tmp: NInt;
begin
	GetParameter(_handle, NLEP_MIN_IOD, tmp);
	Result := tmp;
end;

procedure TNLExtractor.SetUseLiveness(value: NBoolean);
begin
	SetParameter(_handle, NLEP_USE_LIVENESS_CHECK, value);
	_useLiveliness := value;
end;

function TNLExtractor.GetUseLiveness: NBoolean;
var
	tmp: NBoolean;
begin
	GetParameter(_handle, NLEP_USE_LIVENESS_CHECK, tmp);
	Result := tmp;
end;

procedure TNLExtractor.SetMaxIOD(value: NInt);
begin
	SetParameter(_handle, NLEP_MAX_IOD, value);
	_maxIod := value;
end;

function TNLExtractor.GetMaxIOD: NInt;
var
	tmp: Integer;
begin
	GetParameter(_handle, NLEP_MAX_IOD, tmp);
	Result := tmp;
end;

procedure TNLExtractor.SetFaceConfidenceThreshold(value: NDouble);
begin
	SetParameter(_handle, NLEP_FACE_CONFIDENCE_THRESHOLD, value);
	_faceConfidenceThreshold := value;
end;

function TNLExtractor.GetFaceConfidenceThreshold: NDouble;
var
	tmp: Double;
begin
	GetParameter(_handle, NLEP_FACE_CONFIDENCE_THRESHOLD, tmp);
	Result := tmp;
end;

procedure TNLExtractor.SetLivenessThreshold(value: NDouble);
begin
	SetParameter(_handle, NLEP_LIVENESS_THRESHOLD, value);
	_livelinessThreshold := value;
end;

function TNLExtractor.GetLivenessThreshold: NDouble;
var
	tmp: Double;
begin
	GetParameter(_handle, NLEP_LIVENESS_THRESHOLD, tmp);
	Result := tmp;
end;

constructor TNFExtractor.Create();
begin
	NCheck(NfeCreate(_handle));
	Initialize;
end;

destructor TNFExtractor.Destroy();
begin
	NObjectFree(_handle);
	inherited;
end;

procedure TNFExtractor.Initialize;
begin
	_returnedImage := TNfeReturnedImage(GetReturnedImage);
	_useQuality := GetUseQuality;
	_qualityThreshold := GetQualityThreshold;
	_scannerMode := GetScannerMode;
	_templateSize := GetTemplateSize;
	_generalizationThreshold := GetGeneralizationThreshold;
	_generalizationMaximalRotation := GetGeneralizationMaximalRotation;
end;

procedure TNFExtractor.Reset();
begin
	NObjectReset(Handle);
	Initialize;
end;

function TNFExtractor.Extract(image: TNImage; position: TNMPosition; impression: TNMImpressionType; var template: TNFRecord): TNfeExtractionStatus;
var
	nfRecord: NHandle;
	extractionStatus: TNfeExtractionStatus;
begin
	template := nil;
	NCheck(NfeExtract(_handle, image.handle, position, impression, extractionStatus, nfRecord));
	if (nfRecord <> nil) Then
	Begin
		template := TNFRecord.Create(nfRecord);
	End;
	Result := extractionStatus;
end;

function TNFExtractor.Generalize(templates: TArrayOfTNFRecord; var baseTemplateIndex: NInt; var extractionStatus: TNfeExtractionStatus): TNFRecord;
var
	i: NInt;
	nfRecord: NHandle;
	arrayOfPointers: TArrayOfNHandle;
begin
	SetLength(arrayOfPointers, Length(templates));
	for i := 0 to Length(templates) - 1 do
	begin
		arrayOfPointers[i] := templates[i].handle;
	end;

	NCheck(NfeGeneralizeEx(_handle, Length(arrayOfPointers), arrayOfPointers, extractionStatus, baseTemplateIndex, nfRecord));
	if (nfRecord <> nil) then
		Result := TNFRecord.Create(nfRecord)
	Else
		Result := nil;
end;

function TNFExtractor.GetScannerMode: NInt;
var
	res: NInt;
begin
	GetParameter(_handle, NFEP_MODE, res);
	Result := res;
end;

procedure TNFExtractor.SetScannerMode(mode: NInt);
begin
	SetParameter(_handle, NFEP_MODE, mode);
	_scannerMode := mode;
end;

function TNFExtractor.GetUseQuality: NBoolean;
var
	res: NBoolean;
begin
	GetParameter(_handle, NFEP_USE_QUALITY, res);
	Result := res;
end;

procedure TNFExtractor.SetUseQuality(value: NBoolean);
begin
	SetParameter(_handle, NFEP_USE_QUALITY, value);
	_useQuality := value;
end;

function TNFExtractor.GetReturnedImage: TNfeReturnedImage;
var
	res: NInt;
begin
	GetParameter(_handle, NFEP_RETURNED_IMAGE, res);
	Result := TNfeReturnedImage(res);
end;

procedure TNFExtractor.SetReturnedImage(value: TNfeReturnedImage);
begin
	SetParameter(_handle, NFEP_RETURNED_IMAGE, Integer(value));
	_returnedImage := value;
end;

function TNFExtractor.GetTemplateSize: TNfeTemplateSize;
var
	res: NInt;
begin
	GetParameter(_handle, NFEP_TEMPLATE_SIZE, res);
	Result := TNfeTemplateSize(res);
end;

procedure TNFExtractor.SetTemplateSize(value: TNfeTemplateSize);
begin
	SetParameter(_handle, NFEP_TEMPLATE_SIZE, Integer(value));
	_templateSize := value;
end;

function TNFExtractor.GetQualityThreshold: NByte;
var
	res: NByte;
begin
	GetParameter(_handle, NFEP_QUALITY_THRESHOLD, res);
	Result := res;
end;

procedure TNFExtractor.SetQualityThreshold(value: NByte);
begin
	SetParameter(_handle, NFEP_QUALITY_THRESHOLD, value);
	_qualityThreshold := value;
end;

function TNFExtractor.GetGeneralizationMaximalRotation: NByte;
var
	res: NByte;
begin
	GetParameter(_handle, NFEP_GENERALIZATION_MAXIMAL_ROTATION, res);
	Result := res;
end;

procedure TNFExtractor.SetGeneralizationMaximalRotation(value: NByte);
begin
	SetParameter(_handle, NFEP_GENERALIZATION_MAXIMAL_ROTATION, value);
	_generalizationMaximalRotation := value;
end;

function TNFExtractor.GetGeneralizationThreshold: NInt;
var
	res: NInt;
begin
	GetParameter(_handle, NFEP_GENERALIZATION_THRESHOLD, res);
	Result := res;
end;

procedure TNFExtractor.SetGeneralizationThreshold(value: NInt);
begin
	SetParameter(_handle, NFEP_GENERALIZATION_THRESHOLD, value);
	_generalizationThreshold := value;
end;

constructor TNFRecord.Create(hNFRecord: NHandle);
begin
	inherited Create;
	_handle := hNFRecord;
end;

class function TNFRecord.CreateFromMemory(arr: TArrayOfNByte): TNFRecord;
var
	ptr: NHandle;
begin
	NCheck(NFRecordCreateFromMemory(@(arr[0]), Length(arr), 0, nil, ptr));
	if (ptr <> nil) then
	begin
		Result := TNFRecord.Create(ptr);
	end
	else
		Result := nil;
end;

class procedure TNFRecord.Check(arr: TArrayOfNByte);
begin
	NCheck(NFRecordCheck(@(arr[0]), Length(arr)));
end;

destructor TNFRecord.Destroy;
begin
	NObjectFree(_handle);
	inherited;
end;

function TNFRecord.MinutiaCount: NInt;
var
	minutiaesCount: NInt;
begin
	NCheck(NFRecordGetMinutiaCount(Handle, minutiaesCount));
	Result := minutiaesCount;
end;

function TNFRecord.Minutia(index: NInt): TNMMinutia;
var
	minutiae: TNMMinutia;
begin
	NCheck(NFRecordGetMinutia(Handle, index, minutiae));
	Result := minutiae;
end;

function TNFRecord.Save: TArrayOfNByte;
begin
	Result := Save(0);
end;

function TNFRecord.Save(flags: NUInt): TArrayOfNByte;
var
	res: NResult;
	Size, retSize: NSizeType;
	recordArray: TArrayOfNByte;
begin
	res := NObjectGetSize(_handle, flags, Size);
	NCheck(res);
	SetLength(recordArray, Size);
	NCheck(NObjectSaveToMemoryDst(_handle, @(recordArray[0]), Size, flags, retSize));
	Result := recordArray;
end;

function TNFRecord.G: Byte;
var
	val: Byte;
begin
	NCheck(NFRecordGetG(_handle, val));
	Result := val;
end;

constructor TNLRecord.Create(flags: NUInt);
begin
	inherited Create;
	NCheck(NLRecordCreate(flags, _handle));
end;

constructor TNLRecord.Create(hNLRecord: NHandle);
begin
	inherited Create;
	_handle := hNLRecord;
end;

destructor TNLRecord.Destroy();
begin
	NObjectFree(_handle);
	inherited;
end;

function TNLRecord.Clone(): TNLRecord;
var
	tmpPointer: NHandle;
begin
	NObjectClone(Handle, tmpPointer);
	Result := TNLRecord.Create(tmpPointer);
end;

function TNLRecord.Size: NSizeType;
begin
	Result := Size(0);
end;

function TNLRecord.Size(flags: NUInt): NSizeType;
var
	sz: NSizeType;
begin
	NCheck(NObjectGetSize(_handle, flags, sz));
	Result := sz;
end;

function TNLRecord.Quality: Byte;
var
	b: NByte;
begin
	NCheck(NLRecordGetQuality(_handle, b));
	Result := b;
end;

class function TNLTemplate.CreateFromMemory(arr: TArrayOfNByte): TNLTemplate;
var
	tmpPointer: NHandle;
	tmpSize: NSizeType;
Begin
	NCheck(NLTemplateCreateFromMemory(@(arr[0]), Length(arr), 0, tmpSize, tmpPointer));
	if (tmpPointer <> nil) then
		Result := TNLTemplate.Create(tmpPointer)
	else
		Result := nil;
End;

class procedure TNLTemplate.Check(arr: TArrayOfNByte);
begin
	NCheck(NLTemplateCheck(@(arr[0]), Length(arr)));
end;

constructor TNLTemplate.Create(hNLTemplate: NHandle);
begin
	inherited Create;
	_handle := hNLTemplate;
end;

destructor TNLTemplate.Destroy();
begin
	NObjectFree(_handle);
	inherited;
end;

function TNLTemplate.Clone(): TNLTemplate;
var
	tmpPointer: NHandle;
begin
	NObjectClone(Handle, tmpPointer);
	Result := TNLTemplate.Create(tmpPointer);
end;

function TNLTemplate.Size: NSizeType;
begin
	Result := Size(0);
end;

function TNLTemplate.Size(flags: NUInt): NSizeType;
var
	sz: NSizeType;
begin
	NCheck(NObjectGetSize(Handle, flags, sz));
	Result := sz;
end;

function TNLTemplate.RecordCount: NInt;
var
	rc: NInt;
begin
	NCheck(NLTemplateGetRecordCount(_handle, rc));
	Result := rc;
end;

function TNLTemplate.Save: TArrayOfNByte;
begin
	Result := Save(0);
end;

function TNLTemplate.Save(flags: NUInt): TArrayOfNByte;
var
	size: NSizeType;
	arr: TArrayOfNByte;
begin
	size := Self.Size(0);
	SetLength(arr, size);
	NCheck(NObjectSaveToMemoryDst(Self._handle, @(arr[0]), Length(arr), flags,
		size));
	SetLength(arr, size);
	Result := arr;
end;

// -----------------------------------------
// TNMatcher class methods
// -----------------------------------------

procedure TNMatcher.Initialize;
begin
	_matchingThreshold := GetMatchingThreshold;

	_fingersMaximalRotation := GetFingersMaximalRotation;
	_fingersMode := GetFingersMode;
	_fingersMatchingSpeed := GetFingersMatchingSpeed;

	_facesMatchingSpeed := GetFacesMatchingSpeed;
end;

constructor TNMatcher.Create();
begin
	inherited;
	NCheck(NMCreate(_handle));
	Initialize;
end;

destructor TNMatcher.Destroy;
begin
	NObjectFree(_handle);
	inherited;
end;

procedure TNMatcher.Reset();
begin
	NObjectReset(_handle);
	Initialize;
end;

procedure TNMatcher.IdentifyStart(template: TArrayOfNByte);
begin
	NCheck(NMIdentifyStart(Handle, @(template[0]), Length(template), nil));
	// _identifyMatchingDetailsPointer));
end;

function TNMatcher.IdentifyNext(template: TArrayOfNByte): NInt;
var
	tmp: NInt;
begin
	NCheck(NMIdentifyNext(_handle, @(template[0]), Length(template), nil, tmp));
	Result := tmp;
end;

procedure TNMatcher.IdentifyEnd;
begin
	NCheck(NMIdentifyEnd(_handle));
end;

function TNMatcher.Verify(template1: TArrayOfNByte; template2: TArrayOfNByte): NInt;
var
	tmp: NInt;
begin
	NCheck(NMVerify(_handle, @(template1[0]), Length(template1), @(template2[0])
			, Length(template2), nil, tmp));
	Result := tmp;
end;

function TNMatcher.GetFingersMaximalRotation: NByte;
var
	res: NByte;
begin
	GetParameter(_handle, NMP_FINGERS_MAXIMAL_ROTATION, res);
	Result := res;
end;

procedure TNMatcher.SetFingersMaximalRotation(value: NByte);
begin
	SetParameter(_handle, NMP_FINGERS_MAXIMAL_ROTATION, value);
	_fingersMaximalRotation := value;
end;

function TNMatcher.GetFingersMatchingSpeed: TNMSpeed;
var
	res: NInt;
begin
	GetParameter(_handle, 0, NMP_FINGERS_MATCHING_SPEED, res);
	Result := TNMSpeed(res);
end;

procedure TNMatcher.SetFingersMatchingSpeed(value: TNMSpeed);
begin
	SetParameter(_handle, NMP_FINGERS_MATCHING_SPEED, Integer(value));
	_fingersMatchingSpeed := value;
end;

function TNMatcher.GetFingersMode: NInt;
var
	res: NInt;
begin
	GetParameter(_handle, NMP_FINGERS_MODE, res);
	Result := res;
end;

procedure TNMatcher.SetFingersMode(value: NInt);
begin
	SetParameter(_handle, NMP_FINGERS_MODE, value);
	_fingersMode := value;
end;

function TNMatcher.GetFacesMatchingSpeed: TNMSpeed;
var
	res: NInt;
begin
	GetParameter(_handle, 0, NMP_FACES_MATCHING_SPEED, res);
	Result := TNMSpeed(res);
end;

procedure TNMatcher.SetFacesMatchingSpeed(value: TNMSpeed);
begin
	SetParameter(_handle, NMP_FACES_MATCHING_SPEED, Integer(value));
	_facesMatchingSpeed := value;
end;

function TNMatcher.GetMatchingThreshold: NInt;
var
	res: NInt;
begin
	GetParameter(_handle, NMP_MATCHING_THRESHOLD, res);
	Result := res;
end;

procedure TNMatcher.SetMatchingThreshold(value: NInt);
begin
	SetParameter(_handle, NMP_MATCHING_THRESHOLD, value);
	_matchingThreshold := value;
end;

end.
