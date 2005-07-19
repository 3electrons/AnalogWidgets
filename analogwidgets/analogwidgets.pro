
  CONFIG      += designer plugin
  TEMPLATE    = lib
  DESTDIR     = plugins
  INCLUDEPATH += common 
  HEADERS     = common\qmywidgetwithbackground.h \ 
                wallclock\wallclock.h wallclock\wallclock_plugin.h \
                manometer\manometer.h  manometer\manometer_plugin.h \
		analogwidgets_plugin.h

  SOURCES     = defines.h \
                common\qmywidgetwithbackground.cpp \
		wallclock\wallclock.cpp wallclock\wallclock_plugin.cpp \
                manometer\manometer.cpp manometer\manometer_plugin.cpp \
		analogwidgets_plugin.cpp

