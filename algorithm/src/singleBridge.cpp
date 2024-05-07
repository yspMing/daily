#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using std::cout;

namespace algorithm{

/*
  A frog is goning to jump across the bridge, and there is some stones on the bridge,
  The jump length of the frog is in range [minStep, maxStep]
  Output the minimum number of stones the frog will step at if it crosses the bridge.
  https://blog.csdn.net/weixin_45541762/article/details/130674444
*/
static int singleBridge(
	int bridgeLength,
	int minStep,
	int maxStep,
	int stoneNumber,
	int* stoneLoc
)
{
	int* dp = (int*)malloc((bridgeLength + 1 + maxStep) * sizeof(int));
	memset(dp, 0, (bridgeLength + 1 + maxStep) * sizeof(int));
	for (int i = 0; i < stoneNumber; i++)
	{
		dp[stoneLoc[i]] = 1;
	}
	int m;
	for (int i = bridgeLength - minStep; i >= 0; i--)
	{
		m = stoneNumber;
		for (int j = minStep; j <= maxStep; j++)
		{
			m = std::min(dp[i + j], m);
		}
		dp[i] += m;
	}
	return dp[0];
}

void runSingleBridge()
{
	int L, S, T;
	L = 10;
	S = 2;
	T = 3;
	const int M = 5;
	int stones[M] = { 2,3,5,6,7};
	std::cout << "=======>runSingleBridge: ";
	int ans = singleBridge(L, S, T, M, stones);
	std::cout << ans;
}

}