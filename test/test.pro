# Plik utworzony przez menad?era projekt�w kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?�wnego katalogu projektu: .
# Cel to program:  

INCLUDEPATH += widgets 
QMAKE_CXXFLAGS_RELEASE += -g3 
CONFIG += release \
          warn_on 
TEMPLATE = app 
FORMS += testform.ui 
HEADERS += test.h \
           widgets\qmywidgetwithbackground.h \
           widgets\wallclock.h \
           widgets\barmeter.h 
SOURCES += main.cpp \
           test.cpp \
           widgets\qmywidgetwithbackground.cpp \
           widgets\wallclock.cpp \
           widgets\barmeter.cpp 
