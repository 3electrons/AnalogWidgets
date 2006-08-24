# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./test
# Cel to program:  

QMAKE_LIBDIR += /usr/lib/qt4/plugins/designer 

include (../Flags.pri)  

#TARGETDEPS += ../communication/Bartkom/src/lib/libcomm.a \
#              ../analogwidgets/libanalogwidgets.a 
#LIBS += ../communication/Bartkom/src/lib/libcomm.a \
#        ../analogwidgets/libanalogwidgets.a

#unix:LIBS  += ../analogwidgets/libanalogwidgets_plugin.so 
LIBS += ../analogwidgets/libanalogwidgets.a  
#              ../../Bartkom/src/lib/libcomm.a 
              
QMAKE_CXXFLAGS_RELEASE += -fPIC 

INCLUDEPATH += ../analogwidgets/analogwidgets
MOC_DIR = objects 
UI_DIR = . 
OBJECTS_DIR = ../objects 

CONFIG += release \
          warn_on 
TEMPLATE = app 
FORMS += testform.ui 
HEADERS += test.h \
           widgettester.h 
SOURCES += main.cpp \
           test.cpp \
           widgettester.cpp 
=======
