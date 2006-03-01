# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./analogwidgets
# Cel to biblioteka 


TARGETDEPS += ../libanalogwidgets.a \
              ../../../Bartkom/src/lib/libcomm.a
	      
LIBS +=       ../libanalogwidgets.a \
              ../../../Bartkom/src/lib/libcomm.a
	      



INCLUDEPATH +=  ../analogwidgets 
               

TARGET = analogwidgets_plugin 
MOC_DIR = ..\objects
OBJECTS_DIR = ..\objects
QMAKE_CXXFLAGS_RELEASE += -g3
DESTDIR = ../
CONFIG += release \
warn_on \
plugin
TEMPLATE = lib

SOURCES += analogwidgets_plugin.cpp \
           chart_plugin.cpp \
	   led_plugin.cpp \
	   manometer_plugin.cpp \
	   mnemonicbox_plugin.cpp \
	   thermometer_plugin.cpp \	   
	   wallclock_plugin.cpp 
	   
HEADERS += analogwidgets_plugin.h \
           chart_plugin.h \
	   defines.h \
	   led_plugin.h \
	   manometer_plugin.h \
	   mnemonicbox_plugin.h \
	   thermometer_plugin.h \ 
	   wallclock_plugin.h
