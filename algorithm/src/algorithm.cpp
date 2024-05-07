#include <iostream>
#include "inner.h"


void RUN_ALGORITHM()
{
	using namespace algorithm;
	/*
	Solution solver;
	int ans = solver.findPaths(2, 2, 2, 0, 0);
	cout << ans;
	*/

	//test_sorted_array();

    //std::cout << "****************runDequeThread********************" << std::endl;
	//runDequeThread();

    std::cout << "****************mainThreadCycleFun********************" << std::endl;
	mainThreadCycleFun();

	//runSingleBridge();

	//runMaxBitString();

	//runMiniFishSpan();

	std::cout << "****************runNumIslands************************" << std::endl;
	runNumIslands();

	return;
}