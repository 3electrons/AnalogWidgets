# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./test
# Cel to program:  

QMAKE_LIBDIR += /usr/lib/qt4/plugins/designer 

LINK = g++ 
QMAKE_LDFLAGS_RELEASE= -pg
CXXFLAGS = -g3 
#TARGETDEPS += ../communication/Bartkom/src/lib/libcomm.a \
#              ../analogwidgets/libanalogwidgets.a 
#LIBS += ../communication/Bartkom/src/lib/libcomm.a \
#        ../analogwidgets/libanalogwidgets.a

unix:LIBS  += ../analogwidgets/libanalogwidgets_plugin.so 
win32:LIBS += ../analogwidgets/libanalogwidgets.a  \
              ../../Bartkom/src/lib/libcomm.a 
              


INCLUDEPATH += ../analogwidgets/analogwidgets
MOC_DIR = objects 
UI_DIR = . 
OBJECTS_DIR = ../objects 
QMAKE_LFLAGS_RELEASE = -pg \
                       -ftest-coverage 
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
