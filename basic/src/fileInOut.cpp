#include <stdio.h>
#include <cstring>

int runFgets()
{
	char* ptr = "Linux";
	printf("size of ptr: %d", sizeof(ptr));
	char a[10] = { 0 };
	printf("Test fgets function, input a string(longest length 9): ");
	fgets(a, 10, stdin);
	printf("length: %d\n", strlen(a));
	for (int i = 0; i < strlen(a); i++)
	{
		printf("%c", a[i]);
	}
	return 0;
}

void runFileInOut()
{
	runFgets();
}