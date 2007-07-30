# Taki kiepski hack na Bartkom po to by sie skompilowala statyczna bibloteka
# najpierw - prawdopodobnie z czasem bedzie dodawana jako dynamiczna bibloteka 
#

TEMPLATE    = subdirs
CONFIG     += ordered 
SUBDIRS     = \
	analogwidgets 
#	install

unix{
 SUBDIRS+= test
}	

win32-g++{
  SUBDIRS+= test 
}


