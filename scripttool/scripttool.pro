# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./test
# Cel to program:  



include (../Flags.pri)  

TARGETDEPS += ../analogwidgets/libanalogwidgets.a 

LIBS += ../analogwidgets/libanalogwidgets.a  
             


INCLUDEPATH += ../analogwidgets/
MOC_DIR = objects 
UI_DIR = . 
OBJECTS_DIR = objects 

CONFIG += release \
          warn_on 
TEMPLATE = app 

FORMS += scripttool.ui
DESTDIR=../scripttool

HEADERS += scripttool.h

SOURCES += scripttool.cpp \
           main.cpp 


