#include <iostream>
#include "inner.h"

void RUN_BASIC()
{
	using namespace basic;
	//unordered_map_test();

	//runMultiArray();

#ifdef __linux__
	//runFork();
#endif

    std::cout << "****************runClassHeir****************************\n";
	runClassHeir();

	std::cout << "****************runFileInOut****************************\n";
	runFileInOut();

	std::cout << "****************runSmartPointer****************************\n";
	runSmartPointer();

	std::cout << "****************personTest****************************\n";
	personTest();
	
	std::cout << "****************unordered_map_test****************************\n";
	unordered_map_test();
	return;
}