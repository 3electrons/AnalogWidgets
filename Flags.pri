# http://gentoo-wiki.com/SECURITY_Debugging_with_Hardened_Gentoo
# General nonhardened debug config  

QMAKE_CXX = distcc
#QMAKE_MOC = distcc $(QTDIR)/bin/moc 
#QMAKE_UIC = distcc $(QTDIR)/bin/uic 



#QMAKE_CXXFLAGS_RELEASE = -g3 
#QMAKE_CFLGAGS_RELEASE  = 


# Release flags :) 
 QMAKE_CXXFLAGS_RELEASE= -Os -mfpmath=sse
# QMAKE_LFLAGS_RELEASE   = 

win32 {
 # Target platform - Windows 
 # Pentium-Pro -- becouse of Intel and AMD fork 
 
 QMAKE_CXXFLAGS_RELEASE += -march=i686 
}


linux-g++ {
 # Development machine 
 
 QMAKE_CXXFLAGS_RELEASE += -march=pentium-m 

}

