# http://gentoo-wiki.com/SECURITY_Debugging_with_Hardened_Gentoo
# General nonhardened debug config  

QMAKE_CXXFLAGS_RELEASE = -g3 -fno-pie -fno-stack-protector-all -nonow -norelro
QMAKE_CFLGAGS_RELEASE  = -ggdb 


# Release flags :) 
# QMAKE_CXXFLAGS_RELEASE= -Os -mfpmath=sse
# QMAKE_LFLAGS_RELEASE   = 

win32 {
 # Target platform - Windows 
 # Pentium-Pro -- becouse of Intel and AMD fork 
 
 QMAKE_CXXFLAGS_RELEASE += -march=i686 
}


linux-g++ {
 # Development machine 
 
# QMAKE_CXXFLAGS_RELEASE += -march=k8 

}

