#include<map>
#include<unordered_map>
#include<iostream>

namespace basic{

int map_test()
{
	std::map<char, int> mymap;
	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	std::map<char, int>::iterator it = mymap.find('b');
	if (it != mymap.end())
	{
		std::cout << it->first<<":"<<it->second<<"\n";
	}
	mymap.insert(std::pair<char, int>('e', 300));

	it = mymap.find('e');
	if (it != mymap.end())
	{
		std::cout << it->first << ":" << it->second << "\n";
	}
	return 0;
}

int unordered_map_test()
{
	std::unordered_map<char, int> mymap;
	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	std::unordered_map<char, int>::iterator it = mymap.find('b');
	if (it != mymap.end())
	{
		std::cout << it->first << ":" << it->second << "\n";
	}

	mymap.insert(std::pair<char, int>('e', 300));
	it = mymap.find('e');
	if (it != mymap.end())
	{
		std::cout << it->first << ":" << it->second << "\n";
	}

	auto ret = mymap.insert(std::pair<char, int>('f', 300));

	auto _size = mymap.size();
	std::cout << "mymap size: " << _size << "\n";

	auto count_e = mymap.count('e');
	std::cout << "mymap count e: " << count_e << "\n";

	return 0;
}

}