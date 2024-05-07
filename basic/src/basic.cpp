#include <iostream>
#include "explicitTest.hpp"
#include "mapTest.hpp"
#include "person.hpp"
#include "sizeofTest.hpp"
#include "multiArray.hpp"
#include "unixPid.hpp"


void RUN_BASIC()
{
	//unordered_map_test();

	//runMultiArray();

#ifdef __linux__
	runFork();
#endif
	
	return;
}