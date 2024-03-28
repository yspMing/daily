#pragma once
#include<stdlib.h>

char* countAndSayCore(int n)
{
	char* res = (char*)malloc(5000 * sizeof(char));
	if (n == 1)
	{
		res[0] = '1';
		res[1] = '\0';
		return res;
	}
	else
	{
		char* preRes = countAndSayCore(n - 1);

		int numbit = 0;
		res[numbit] = '1';
		res[numbit + 1] = preRes[0];
		for (int i = 1; preRes[i] != '\0'; i++)
		{
			if (preRes[i] == preRes[i - 1])
			{
				res[numbit] += 1;
			}
			else
			{
				numbit += 2;
				res[numbit] = '1';
				res[numbit + 1] = preRes[i];
			}
		}
		res[numbit + 2] = '\0';
	}
	return res;
}

char* API_countAndSay(int n)
{
	return countAndSayCore(n);
}