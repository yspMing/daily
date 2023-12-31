#pragma once
#include <iostream>

struct func {
	int& _i;
	func(int &i):_i(i){}
	void operator()(int t)
	{
		_i = t;
		std::cout << "_i is : " << _i << "\n";
	}
};