#include<stdio.h>

namespace basic{

struct size_node{
	int a;
	int c;
	double e;
	double b;
};

int run_sizeof_test()
{
	printf("sizeof node:%ld\n",sizeof(size_node));
	return 0;
}

}