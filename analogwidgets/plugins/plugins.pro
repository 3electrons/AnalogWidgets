# Plik utworzony przez mened?era projekt�w kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?�wnego katalogu projektu: ./analogwidgets/plugins
# Cel to biblioteka analogwidgets_plugin

#include(../../Flags.pri)

HEADERS += analogwidgets_plugin.h \
           chart_plugin.h \
           defines.h \
           led_plugin.h \
           manometer_plugin.h \
           thermometer_plugin.h \
           wallclock_plugin.h \
           bitmapbutton_plugin.h \
	   counter_plugin.h \
	   svgfile_taskmenu.h \
	   scriptwidget_plugin.h 


SOURCES += analogwidgets_plugin.cpp \
           chart_plugin.cpp \
           led_plugin.cpp \
           manometer_plugin.cpp \
           thermometer_plugin.cpp \
           wallclock_plugin.cpp \
	   bitmapbutton_plugin.cpp \
	   counter_plugin.cpp \
	   svgfile_taskmenu.cpp \
	   scriptwidget_plugin.cpp 


unix,win32-g++:{             
TARGETDEPS += ../libanalogwidgets.a 
LIBS += ../libanalogwidgets.a  
}

wince*:{
 TARGETDEPS += ../analogwidgets.lib
 LIBS += ../analogwidgets.lib
}

QT += xml svg script 

INCLUDEPATH += ../analogwidgets \
               ..
	       
MOC_DIR =     ..\objects
OBJECTS_DIR = ..\objects
TARGET =       analogwidgets_plugin
DESTDIR =      ../
CONFIG += release \
          warn_on \
	  designer \ 
          plugin
TEMPLATE = lib
