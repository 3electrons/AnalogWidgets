  CONFIG      += designer plugin
  TEMPLATE    = lib
  DESTDIR     = plugins
  HEADERS     = wallclock\wallclock.h wallclock\wallclock_plugin.h \
                barmeter\barmeter.h  barmeter\barmeter_plugin.h \
		analogwidgets_plugin.h

  SOURCES     = defines.h \
		wallclock\wallclock.cpp wallclock\wallclock_plugin.cpp \
                barmeter\barmeter.cpp barmeter\barmeter_plugin.cpp \
		analogwidgets_plugin.cpp

