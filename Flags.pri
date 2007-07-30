
linux-g++ {
 # Development machine 
 
 #QMAKE_CXX = distcc  
 QMAKE_CXXFLAGS_RELEASE  = -g3 -Wall -pg 
 #QMAKE_CXXFLAGS_RELEASE = -march=k8 -Os -mfpmath=sse -Wall
 QMAKE_LFLAGS_RELEASE    = 
}

win32-g++ {
 # Target platform - Windows 
 # Pentium-Pro -- becouse of Intel and AMD fork 
 
 #QMAKE_CXXFLAGS_RELEASE  = -g3 -Wall
 #QMAKE_CXXFLAGS_RELEASE  = -march=i686 -Os -Wall 
 #QMAKE_LFLAGS_RELEASE    = 
}


win32-msvc.net {
 # Target platform - Windows VISUAL STUDIO 2003 .NET
 # Pentium-Pro -- becouse of Intel and AMD fork 

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
