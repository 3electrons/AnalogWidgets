QMAKE_CXXFLAGS_RELEASE =  -Os -mfpmath=sse
QMAKE_LFLAGS_RELEASE   = 


win32 {
 # Target platform - Windows 
 # Pentium-Pro -- becouse of Intel and AMD fork 
 
 QMAKE_CXXFLAGS_RELEASE += -march=i686 
}


linux-g++ {
 # Development machine 
 
# QMAKE_CXXFLAGS_RELEASE += -march=k8 

}

