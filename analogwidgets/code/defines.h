#ifndef DEFINES_H
#define DEFINES_H

// Numer portu do testow

#define ASSERT 		CPPUNIT_ASSERT
#define ASSERT_EQUAL 	CPPUNIT_ASSERT_EQUAL
#define ASSERT_DEQUAL	CPPUNIT_ASSERT_DOUBLES_EQUAL

#ifdef WIN32

#include <windows.h>
#define usleep(x) Sleep(0) 
// (DWORD)(x/1000)) 
#define PORT_NUMBER 3 
#else 
#define PORT_NUMBER 1 

#endif 



#endif // DEFINES_H
