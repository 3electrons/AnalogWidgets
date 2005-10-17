# Plik utworzony przez menad?era projektów kdevelopa
# -------------------------------------------
# Podkatalog wzgl?dem g?ównego katalogu projektu: .
# Cel to program:

INCLUDEPATH += widgets
UI_DIR = ui
QMAKE_CXXFLAGS_RELEASE += -g3
CONFIG += release \
          warn_on
TEMPLATE = app
FORMS += testform.ui
HEADERS += test.h \
           widgettester.h \
	   ui_testform.h \
	   widgets\functions.h \
           widgets\qmywidgetwithbackground.h \
	   widgets\qmyabstractmeter.h \
           widgets\wallclock.h \
           widgets\manometer.h \
	   widgets\thermometer.h \
	   widgets\chart.h \
	widgets\standard\channeldecorator.h \
	widgets\standard\glassdecorator.h \
	widgets\standard\labelsdecorator.h \
	widgets\standard\legenddecorator.h \
	widgets\standard\scalesgriddecorator.h

SOURCES += main.cpp \
           test.cpp \
	   widgettester.cpp \
           widgets\qmywidgetwithbackground.cpp \
	   widgets\qmyabstractmeter.cpp \
           widgets\wallclock.cpp \
           widgets\manometer.cpp \
	   widgets\thermometer.cpp \
	   widgets\chart.cpp \
	widgets\standard\channeldecorator.cpp \
	widgets\standard\glassdecorator.cpp \
	widgets\standard\labelsdecorator.cpp \
	widgets\standard\legenddecorator.cpp \
	widgets\standard\scalesgriddecorator.cpp

=======


