
QT+= xml svg script 

linux-g++ {
 # Development machine 
 
 #QMAKE_CXX = distcc  
 QMAKE_CXXFLAGS_RELEASE  = -g3 -Wall -pg 
 #QMAKE_CXXFLAGS_RELEASE = -march=core2 -O3 -pipe -mfpmath=sse -Wall
 QMAKE_LFLAGS_RELEASE    =
 
 INSTALL_INCLUDEDIR = /usr/include
 INSTALL_LIBDIR     = /usr/lib 
 
}

win32-g++ {
 # Target platform - Windows 
 # Pentium-Pro -- becouse of Intel and AMD fork 
 
 #QMAKE_CXXFLAGS_RELEASE  = -g3 -Wall
 QMAKE_CXXFLAGS_RELEASE  = -march=pentium3 -Os -Wall -pipe -mfpmath=sse 
 #QMAKE_LFLAGS_RELEASE    =
 
 INSTALL_DIR        = C:/analogwidgets 
 INSTALL_INCLUDEDIR = $$INSTALL_DIR/include 
 INSTALL_LIBDIR     = $$INSTALL_DIR/lib
}


win32-msvc.net {
 # Target platform - Windows VISUAL STUDIO 2003 .NET
 # Pentium-Pro / PII / PIII - Windows Application optimalization
 QMAKE_CXXFLAGS_RELEASE  += /G6 /GA /arch:SSE 
 QMAKE_LFLAGS_RELEASE    += /LIBPATH:"C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\lib"  \
                            /LIBPATH:"C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\PlatformSDK\Lib"
 INCLUDEPATH+= "C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\include" 
}


win32-cross-g++ {
  QMAKE_CXXFLAGS_RELEASE = -march=i686 -Os -Wall
}


win32-wine-g++ {
  QMAKE_CXXFLAGS_RELEASE = -march=i686 -Os -Wall 
}
