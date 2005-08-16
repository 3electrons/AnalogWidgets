
  CONFIG      += designer plugin
  TEMPLATE    = lib
  DESTDIR     = plugins
  INCLUDEPATH += common 
  HEADERS     = defines.h \
                common\qmywidgetwithbackground.h common\qmyabstractmeter.h \ 
                wallclock\wallclock.h wallclock\wallclock_plugin.h \
                manometer\manometer.h  manometer\manometer_plugin.h \
		thermometer\thermometer.h thermometer\thermometer_plugin.h \
		analogwidgets_plugin.h

  SOURCES     = common\qmywidgetwithbackground.cpp common\qmyabstractmeter.cpp \
		wallclock\wallclock.cpp wallclock\wallclock_plugin.cpp \
                manometer\manometer.cpp manometer\manometer_plugin.cpp \
		thermometer\thermometer.cpp thermometer\thermometer_plugin.cpp \
		analogwidgets_plugin.cpp
		
