File VeriLookSurveillanceSDKTrialRedistributable.exe contains components needed for VeriLook Surveillance 2.3 SDK Client to function

Following parameters can be specified:
  /DOTNET - copies .NET components for product and installs .NET framework if not available.
  /GAC - installs .NET components to Global Assembly Cache.

Following parameters can be specified to install appropriate modules:
  /Canon - Canon camera module
  /Cisco - Cisco camera module
  /Mobotix - Mobotix camera module
  /Nikon - Nikon camera module
  /Prosillica - Prosillica camera module

  /TRIALACTIVATION - Neurotechnology trial activation files




Installer adds install directory to path variable.
Default install directory is: 
  $PROGRAMFILES\Neurotechnology\VeriLook Surveillance 2.3\bin\
It can be changed with /D parameter (* must be the last parameter on the command line):
  /D=path

Example:
  VeriLookSurveillanceSDKTrialRedistributable.exe /DOTNET /ACTIVATION  /D=c:\program files\MyProduct\Bin


Note:

 * If you want redistributables uninstaller to run in silent mode use parameter /S
   For example: uninst.exe /S

 * If you use the /D option it is important to note that it must be the last parameter on the command line and 
   must not contain any quotes, even if the path contains spaces. Only absolute paths are supported. 
   Use an equal sign to separate the option and the path.

