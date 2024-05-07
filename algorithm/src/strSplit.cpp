#include <iostream>
#include <string.h>
#include <vector>
using std::string;

namespace algorithm{
/*
void strcpy_s_test()
{
	char str1[20];
	char str2[20];
	std::cout << "please enter str2: ";
	std::cin.get(str2, 20);
	strcpy_s(str1, str2);
	std::cout << "str1 is " << str1 << "\n";

	char* str;
	str = new char[20];
	strcpy_s(str, strlen(str1)+1, str1);
	std::cout << "str is " << str << "\n";

	return;
}

*/

void strtok_test()
{
	std::string s = "Golden Global View, disk";
	std::cout << "string to be splitted is:\n"<<s<<"\n";

	const char* d = " ";
	printf("delim is:\n%s\n", d);

	//convert string to char*
	size_t Size = s.size();
	char* ss = new char[Size + 1];
	//strcpy(ss, Size+1, s.c_str());
	strcpy(ss, s.c_str());
	
	std::cout << (ss[Size] == '\0' ? "true" : "false") << "\n";

	char* p;
	p = strtok(ss, d);
	std::vector<string> inputs;
	while (p)
	{
		inputs.push_back(string(p));
		p = strtok(NULL, d);
	}
	std::vector<string>::iterator it;
	for (it = inputs.begin(); it < inputs.end(); it++)
	{
		std::cout << *it << "\n";
	}
	return;
}

}