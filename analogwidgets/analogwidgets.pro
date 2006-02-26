# Plik utworzony przez menad?era projektów kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?ównego katalogu projektu: ./analogwidgets
# Cel to biblioteka 

HEADERS += defines.h \
           common/qmywidgetwithbackground.h \
           common/qmyabstractmeter.h \
           wallclock/wallclock.h \
           wallclock/wallclock_plugin.h \
           manometer/manometer.h \
           manometer/manometer_plugin.h \
           thermometer/thermometer.h \
           thermometer/thermometer_plugin.h \
           chart/channel.h \
           chart/chartdecorator.h \
           chart/chart.h \
           chart/chart_plugin.h \
           chart/scalegrid.h \
           chart/standard/channeldecorator.h \
           chart/standard/glassdecorator.h \
           chart/standard/labelsdecorator.h \
           chart/standard/legenddecorator.h \
           chart/standard/scalegriddecorator.h \
           chart/channeldata.h \
           chart/datacontainers.h \
           analogwidgets_plugin.h \
           defines.h \
           functions.h \
           mnemonics/mnemonicbox_plugin.h \
           mnemonics/mnemonicbox.h \
           led/led.h \
           led/led_plugin.h 
SOURCES += common/qmywidgetwithbackground.cpp \
           common/qmyabstractmeter.cpp \
           wallclock/wallclock.cpp \
           wallclock/wallclock_plugin.cpp \
           manometer/manometer.cpp \
           manometer/manometer_plugin.cpp \
           thermometer/thermometer.cpp \
           thermometer/thermometer_plugin.cpp \
           chart/channel.cpp \
           chart/scalegrid.cpp \
           chart/chart.cpp \
           chart/chart_plugin.cpp \
           chart/standard/channeldecorator.cpp \
           chart/standard/glassdecorator.cpp \
           chart/standard/labelsdecorator.cpp \
           chart/standard/legenddecorator.cpp \
           chart/standard/scalegriddecorator.cpp \
           analogwidgets_plugin.cpp \
           mnemonics/mnemonicbox_plugin.cpp \
           mnemonics/mnemonicbox.cpp \
           functions.cpp \
           led/led.cpp \
           led/led_plugin.cpp 
TARGETDEPS += ../communication/Bartkom/src/lib/libcomm.a
LIBS += ../communication/Bartkom/src/lib/libcomm.a
INCLUDEPATH += ../communication/Bartkom/src/comm \
common \
chart
MOC_DIR = ..\objects
OBJECTS_DIR = ..\objects
QMAKE_CXXFLAGS_RELEASE += -g3
DESTDIR = plugins
CONFIG += release \
warn_on \
plugin
TEMPLATE = lib
