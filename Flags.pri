
linux-g++ {
 # Development machine 
 
 #QMAKE_CXX = distcc  
 QMAKE_CXXFLAGS_RELEASE  = -g3 -Wall 
 #QMAKE_CXXFLAGS_RELEASE = -march=k8 -Os -mfpmath=sse -Wall
 QMAKE_LFLAGS_RELEASE    = 

}

win32 {
 # Target platform - Windows 
 # Pentium-Pro -- becouse of Intel and AMD fork 
 
 #QMAKE_CXXFLAGS_RELEASE  = -g3 -Wall
  QMAKE_CXXFLAGS_RELEASE  = -march=i686 -Os -Wall 
  QMAKE_LFLAGS_RELEASE    = 
 
}


win32-cross-g++ {
  QMAKE_CXXFLAGS_RELEASE = -march=i686 -Os -Wall
}


win32-wine-g++ {
  QMAKE_CXXFLAGS_RELEASE = -march=i686 -Os -Wall 
}
