# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./analogwidgets/plugins
# Cel to biblioteka analogwidgets_plugin
include (../../Flags.pri ) 
QT += xml 
TARGETDEPS += ../libanalogwidgets.a 

LIBS += ../libanalogwidgets.a 

INCLUDEPATH += ../analogwidgets 
MOC_DIR = ..\objects 
OBJECTS_DIR = ..\objects 

#QMAKE_CXXFLAGS_RELEASE += -g3 
TARGET = analogwidgets_plugin 
DESTDIR = ../ 
CONFIG += release \
          warn_on \
          plugin 
TEMPLATE = lib 
HEADERS += analogwidgets_plugin.h \
           chart_plugin.h \
           defines.h \
           led_plugin.h \
           manometer_plugin.h \
           thermometer_plugin.h \
           wallclock_plugin.h 
SOURCES += analogwidgets_plugin.cpp \
           chart_plugin.cpp \
           led_plugin.cpp \
           manometer_plugin.cpp \
           thermometer_plugin.cpp \
           wallclock_plugin.cpp 
