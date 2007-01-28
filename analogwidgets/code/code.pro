# Plik utworzony przez mened?era projekt�w kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?�wnego katalogu projektu: ./analogwidgets/code
# Cel to biblioteka analogwidgets

HEADERS += ../analogwidgets/chart/chartdecorator.h \
           ../analogwidgets/chart/channeldata.h \
           ../analogwidgets/chart/channel.h \
           ../analogwidgets/chart/datacontainers.h \
           ../analogwidgets/chart/standard/labelsdecorator.h \
           ../analogwidgets/chart/standard/legenddecorator.h \
           ../analogwidgets/chart/standard/scalegriddecorator.h \
           ../analogwidgets/chart/standard/glassdecorator.h \
           ../analogwidgets/chart/standard/channeldecorator.h \
           ../analogwidgets/chart/scalegrid.h \
           ../analogwidgets/led.h \
           ../analogwidgets/functions.h \
           ../analogwidgets/manometer.h \
           ../analogwidgets/chart.h \
           ../analogwidgets/thermometer.h \
           defines.h \
           ../analogwidgets/abstractmeter.h \
           ../analogwidgets/wallclock.h \
           ../analogwidgets/widgetwithbackground.h 
SOURCES += chart/scalegrid.cpp \
           chart/standard/labelsdecorator.cpp \
           chart/standard/glassdecorator.cpp \
           chart/standard/channeldecorator.cpp \
           chart/standard/legenddecorator.cpp \
           chart/standard/scalegriddecorator.cpp \
           chart/channel.cpp \
           chart.cpp \
           functions.cpp \
           led.cpp \
           manometer.cpp \
           thermometer.cpp \
           wallclock.cpp \
           chart/chartdecorator.cpp \
           abstractmeter.cpp \
           widgetwithbackground.cpp 
\# Plik utworzony przez menad?era projekt�w kdevelopa
QT += xml
INCLUDEPATH += ../analogwidgets
include (../../Flags.pri )
OBJECTS_DIR = ../objects
TARGET = analogwidgets
DESTDIR = ../
CONFIG += release \
warn_on \
staticlib
TEMPLATE = lib
WIN32{
  DEFINES+= WIN32
}
