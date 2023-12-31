#include <iostream>
#include "countAndSay.hpp"
#include "dynamicProgram.hpp"
#include "explicitTest.hpp"
#include "func.hpp"
#include "gamePlayer.hpp"
#include "mapTest.hpp"
#include "person.hpp"
#include "sizeofTest.hpp"
#include "sortedArray.hpp"
#include "stringAndChar.hpp"
#include "threadCycle.hpp"


void RUN_BASIC()
{
	/*
	Solution solver;
	int ans = solver.findPaths(2, 2, 2, 0, 0);
	cout << ans;
	*/

	/*
	int arr[6] = { 5,7,7,8,8,10};
	int ret = find_in_left(arr, 8, 0, 4);
	printf("ret,%d", ret);
	*/

	/*
	int val = 10;
	int& rv = val;
	struct func myFunc(val);
	myFunc(100);
	std::cout << "val: " << val << "\n";
	std::cout << "rv: " << rv << "\n";

	GamePalyer g;
	cout<<"addr: "<<g.getNumTurnsAddress();
	*/

	//testKMergedLists();

	//testReverseKlist();

	//mainGPT();

	mainThreadCycleFun();
	
	return;
}