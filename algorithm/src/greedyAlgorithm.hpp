#pragma once

#include<vector>
#include<algorithm>

using std::vector;

int findContentChildren(vector<int>& children, vector<int>& cookies)
{
	std::sort(children.begin(), children.end());
	std::sort(cookies.begin(), cookies.end());
	int child = 0, cookie = 0;
	while (child < children.size() && cookie < cookies.size())
	{
		if (children[child] <= cookies[cookie]) ++child;
		++cookie;
	}
	return child;
}