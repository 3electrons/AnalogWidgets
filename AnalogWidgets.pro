# Taki kiepski hack na Bartkom po to by sie skompilowala statyczna bibloteka
# najpierw - prawdopodobnie z czasem bedzie dodawana jako dynamiczna bibloteka 
#

TEMPLATE    = subdirs
SUBDIRS     = \
        depend \
	analogwidgets \
	test 
#	install
	

QMAKE_CXXFLAGS_RELEASE = -pg 
QMAKE_LDFLAGS_RELEASE  = -pg 
