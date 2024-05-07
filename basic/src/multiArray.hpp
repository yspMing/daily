#pragma once

#include <stdio.h>
typedef enum {
	N_LEAF, 
	N_INTERNAL
} nodetype_t;

typedef struct {
	int a;
	char ch;
}multiArrayStruct;

struct node_t{
	nodetype_t type;
	union 
	{
		struct {
			struct node_t* left;
			struct node_t* right;
		}internal;
		double data[2];
	}info;
};

void multiArrayFunc1(int n, char str[][5])
{
	for (int i = 0; i < n; i++)
	{
		printf("str[%d] = %s\n", i, str[i]);
	}
	printf("str[1][0] is %c\n", str[1][0]);
}


void multiArrayFunc2(int n, char (*str)[5])
{
	//str is a pointer which points to an array of 5
	for (int i = 0; i < n; i++)
	{
		printf("str[%d] = %s\n", i, str[i]);
	}
	printf("str[1][0] is %c\n", (*(str+1))[0]);
}


char visitMultiArray3(char** str, int i, int j, int cols)
{
	//return str[i][j];
	return *((char*)str + i * cols + j);
}

/* Visit the str like visitting a one-dimensional array.
   The array in constant memory /str[0]-str[1]-../
*/
void multiArrayFunc3(int n, char** str, int cols)
{
	for (int i = 0; i < n; i++)
	{
		printf("str[%d] = %s\n", i, (char*)str+i * cols);
	}
	printf("str[1][0] is %c\n", visitMultiArray3(str,1,0,cols));
}


void multiArrayFunc4(int n, char* str[], int cols)
{
	for (int i = 0; i < n; i++)
	{
		printf("str[%d] = %s\n", i, str[i]);
	}
	printf("str[1][0] is %c\n", str[1][0]);
}


void multiArrayStructFunc(multiArrayStruct** arr, int n)
{
	printf("multiArrayStructFunc: arr[0]->a: %d\n", arr[0]->a);
	printf("multiArrayStructFunc: arr[0]->ch: %c\n", arr[0]->ch);
	printf("multiArrayStructFunc: arr[1]->a: %d\n", arr[1]->a);
	printf("multiArrayStructFunc: arr[1]->ch: %c\n", arr[1]->ch);
}


void runMultiArray()
{
	printf("=======>runMultiArray()\n");
	char str[3][5] = { "abc","def","ghij" };

	//multiArrayFunc1(3, str);

	//multiArrayFunc2(3, str);

	multiArrayFunc3(3, (char**)str, 5);

	char* p[3];
	p[0] = &str[0][0];
	p[1] = &str[1][0];
	p[2] = &str[2][0];
	multiArrayFunc4(3, p, 5);

	multiArrayStruct aa[2];
	aa[0].a = 1;
	aa[0].ch = 'a';

	aa[1].a = 3;
	aa[1].ch = 'b';

	multiArrayStruct* paa[2];
	paa[0] = &aa[0];
	paa[1] = &aa[1];

	multiArrayStructFunc(paa, 2);

	struct node_t node;
	node.info.internal.left = 0;
	node.info.internal.right = 0;

}