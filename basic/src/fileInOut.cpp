#include <stdio.h>
#include <cstring>

int runFgets()
{
	const char* ptr = "Linux";
	printf("size of ptr: %ld\n", sizeof(ptr));

	//About fgets buffer leak problem
	//see https://zhuanlan.zhihu.com/p/522935497
	char a[10] = { 0 };
	printf("Test fgets function, input a string(longest length 9): ");
	fgets(a, 10, stdin);
	printf("length: %ld\n", strlen(a));
	for (int i = 0; i < strlen(a); i++)
	{
		printf("%c", a[i]);
	}
	return 0;
}

int var_ele(long n, int A[][10], long i, long j)
{
	return A[i][j];
}

int runScanf()
{
	const int wordCount = 10;
	char myChar[wordCount];
	return 0;
}

void runFileInOut()
{
	printf("=======>runFetgs()\n");
	//runFgets();
}