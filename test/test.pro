# Plik utworzony przez menad?era projekt�w kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?�wnego katalogu projektu: ./test
# Cel to program:  



include (../Flags.pri)  

TARGETDEPS += ../analogwidgets/libanalogwidgets.a 

LIBS += ../analogwidgets/libanalogwidgets.a  
              


INCLUDEPATH += ../analogwidgets/analogwidgets
MOC_DIR = objects 
UI_DIR = . 
OBJECTS_DIR = ../objects 

CONFIG += release \
          warn_on 
TEMPLATE = app 

FORMS += testform.ui
DESTDIR=../test 
HEADERS += test.h \
           widgettester.h 

SOURCES += main.cpp \
           test.cpp \
           widgettester.cpp 

