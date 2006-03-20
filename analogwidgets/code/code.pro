# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./analogwidgets/code
# Cel to biblioteka analogwidgets

INCLUDEPATH += ../analogwidgets \
               ../../../Bartkom/src/comm 
OBJECTS_DIR = ../objects 
QMAKE_CXXFLAGS_RELEASE += -g3 
QMAKE_CXXFLAGS_DEBUG += -g3 
TARGET = analogwidgets 
WIN32:DEFINES+= WIN32
DESTDIR = ../ 
QT+= xml 
CONFIG += release \
          warn_on \
          staticlib 
TEMPLATE = lib 
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
           ../analogwidgets/wallclock.h \
           ../analogwidgets/manometer.h \
           ../analogwidgets/qmyabstractmeter.h \
           ../analogwidgets/mnemonicbox.h \
           ../analogwidgets/qmywidgetwithbackground.h \
           ../analogwidgets/chart.h \
           ../analogwidgets/thermometer.h \
           defines.h 
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
           mnemonicbox.cpp \
           qmyabstractmeter.cpp \
           qmywidgetwithbackground.cpp \
           thermometer.cpp \
           wallclock.cpp 
