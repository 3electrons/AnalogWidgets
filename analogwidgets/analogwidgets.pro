
  CONFIG      += designer plugin
  TEMPLATE    = lib
  DESTDIR     = plugins
  INCLUDEPATH += common 
  HEADERS     = common\qmywidgetwithbackground.h \ 
                wallclock\wallclock.h wallclock\wallclock_plugin.h \
                barmeter\barmeter.h  barmeter\barmeter_plugin.h \
		analogwidgets_plugin.h

  SOURCES     = defines.h \
                common\qmywidgetwithbackground.cpp \
		wallclock\wallclock.cpp wallclock\wallclock_plugin.cpp \
                barmeter\barmeter.cpp barmeter\barmeter_plugin.cpp \
		analogwidgets_plugin.cpp

