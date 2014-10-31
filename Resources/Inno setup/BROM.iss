; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "BROM"
#define MyAppVersion "1.0.0.1"
#define MyAppPublisher "pi-null-mezon"
#define MyAppURL "https://github.com/pi-null-mezon/QPULSECAPTURE"
#define MyAppExeName "BROM.exe"
#define QtVersion "5.2.1"
#define QtCompiler "msvc2010"
#define OpencvCompiler "vc10"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{A27EB6C5-A92A-46BE-A27D-C3DEE06A45FF}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
LicenseFile=C:\Programing\QPULSECAPTURE\LICENSE
InfoBeforeFile=C:\Programing\QPULSECAPTURE\BROM_README.md
OutputDir=C:\Programing\QPULSECAPTURE\Install
OutputBaseFilename=BROM_setup_Win_32bit
SetupIconFile=C:\Programing\QPULSECAPTURE\Resources\Images\BROM.ico
Compression=lzma
SolidCompression=yes
VersionInfoVersion = {#MyAppVersion}

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Programing\QPULSECAPTURE\Install\build-Sources-Desktop_Qt_5_2_1_MSVC2010_32bit-Release\release\BROM.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Programing\QPULSECAPTURE\Resources\WVCF_utility.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Programing\QPULSECAPTURE\Resources\FFTW\fftw3-32\libfftw3-3.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\opencv\build\x86\{#OpencvCompiler}\bin\opencv_core248.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\opencv\build\x86\{#OpencvCompiler}\bin\opencv_ffmpeg248.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\opencv\build\x86\{#OpencvCompiler}\bin\opencv_highgui248.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\opencv\build\x86\{#OpencvCompiler}\bin\opencv_imgproc248.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\plugins\platforms\qwindows.dll"; DestDir: "{app}\platforms"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\icudt51.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\icuin51.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\icuuc51.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\libEGL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\libGLESv2.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Bluetooth.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5CLucene.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Concurrent.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Declarative.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Designer.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5DesignerComponents.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Help.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Multimedia.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5MultimediaQuick_p.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5MultimediaWidgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Network.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Nfc.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5OpenGL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Positioning.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5PrintSupport.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Qml.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Quick.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5QuickParticles.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5QuickTest.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Script.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5ScriptTools.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Sensors.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5SerialPort.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Sql.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5Test.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5WebKit.dll"; DestDir: "{app}"; Flags: ignoreversion
;Source: "C:\Qt\5.2.1\msvc2010\bin\Qt5WebKitWidgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5WinExtras.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5Xml.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Qt\{#QtVersion}\{#QtCompiler}\bin\Qt5XmlPatterns.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

