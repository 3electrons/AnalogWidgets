# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./test
# Cel to program:  

FORMS += testform.ui 
HEADERS += test.h \
           widgettester.h \
           ../analogwidgets/functions.h \
           ../analogwidgets/common/qmywidgetwithbackground.h \
           ../analogwidgets/common/qmyabstractmeter.h \
           ../analogwidgets/wallclock/wallclock.h \
           ../analogwidgets/manometer/manometer.h \
           ../analogwidgets/thermometer/thermometer.h \
           ../analogwidgets/chart/channel.h \
           ../analogwidgets/chart/chartdecorator.h \
           ../analogwidgets/chart/chart.h \
           ../analogwidgets/chart/scalegrid.h \
           ../analogwidgets/chart/standard/channeldecorator.h \
           ../analogwidgets/chart/standard/glassdecorator.h \
           ../analogwidgets/chart/standard/labelsdecorator.h \
           ../analogwidgets/chart/standard/legenddecorator.h \
           ../analogwidgets/chart/standard/scalegriddecorator.h \
           ../analogwidgets/chart/channeldata.h \
           ../analogwidgets/chart/datacontainers.h \
           ../analogwidgets/mnemonics/mnemonicbox.h 
SOURCES += main.cpp \
           test.cpp \
           widgettester.cpp \
           ../analogwidgets/common/qmywidgetwithbackground.cpp \
           ../analogwidgets/common/qmyabstractmeter.cpp \
           ../analogwidgets/wallclock/wallclock.cpp \
           ../analogwidgets/manometer/manometer.cpp \
           ../analogwidgets/thermometer/thermometer.cpp \
           ../analogwidgets/chart/channel.cpp \
           ../analogwidgets/chart/chart.cpp \
           ../analogwidgets/chart/scalegrid.cpp \
           ../analogwidgets/chart/standard/channeldecorator.cpp \
           ../analogwidgets/chart/standard/glassdecorator.cpp \
           ../analogwidgets/chart/standard/labelsdecorator.cpp \
           ../analogwidgets/chart/standard/legenddecorator.cpp \
           ../analogwidgets/chart/standard/scalegriddecorator.cpp \
           ../analogwidgets/mnemonics/mnemonicbox.cpp \
           ../analogwidgets/functions.cpp 
LINK = g++
CXXFLAGS = -g3
INCLUDEPATH += ../analogwidgets \
../analogwidgets/chart \
../analogwidgets/common
MOC_DIR = ../output
UI_DIR = .
OBJECTS_DIR = ../output
QMAKE_LFLAGS_RELEASE = -pg \
-ftest-coverage
CONFIG += release \
warn_on
TEMPLATE = app
=======
