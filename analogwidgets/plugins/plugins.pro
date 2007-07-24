# Plik utworzony przez mened?era projekt�w kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?�wnego katalogu projektu: ./analogwidgets/plugins
# Cel to biblioteka analogwidgets_plugin

HEADERS += analogwidgets_plugin.h \
           chart_plugin.h \
           defines.h \
           led_plugin.h \
           manometer_plugin.h \
           thermometer_plugin.h \
           wallclock_plugin.h \
           bitmapbutton_plugin.h 
SOURCES += analogwidgets_plugin.cpp \
           chart_plugin.cpp \
           led_plugin.cpp \
           manometer_plugin.cpp \
           thermometer_plugin.cpp \
           wallclock_plugin.cpp \
	   bitmapbutton_plugin.cpp
	   
include (../../Flags.pri )
QT += xml designer
TARGETDEPS += ../libanalogwidgets.a
LIBS += ../libanalogwidgets.a
INCLUDEPATH += ../analogwidgets
MOC_DIR = ..\objects
OBJECTS_DIR = ..\objects
TARGET = analogwidgets_plugin
DESTDIR = ../
CONFIG += release \
warn_on \
plugin
TEMPLATE = lib
