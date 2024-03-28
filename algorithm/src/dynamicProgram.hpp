#pragma once
#include <math.h>

class Solution {
public:
	int solution = 0;
	int findPaths(int m, int n, int N, int i, int j) {
		int ans = 0;
		int** dp = new int* [m];
		for (int row = 0; row < m; row++) {
			dp[row] = new int[n] {0};
		}
		int** temp = new int* [m + 2];
		for (int row = 0; row < m + 2; row++) {
			temp[row] = new int[n + 2]{ 0 };
		}
		dp[i][j] = 1;
		for (int k = 0; k < N; k++) {
			ans += count(dp, m, n);
			ans = ans % (int(pow(10, 9) + 7));
			update(dp, temp, m, n);
		}
		return ans;

	}
	int count(int** dp, int m, int n) {
		int ans = 0;
		for (int i = 0; i < m; i++) {
			ans += dp[i][0];
			ans += dp[i][n - 1];
		}
		for (int j = 0; j < n; j++) {
			ans += dp[0][j];
			ans += dp[m - 1][j];
		}
		return ans;
	}
	void update(int** dp, int** temp, int m, int n) {
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				temp[i][j] = dp[i - 1][j - 1];
			}
		}
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				dp[i - 1][j - 1] = temp[i - 1][j] + temp[i + 1][j] + temp[i][j - 1] + temp[i][j + 1];
			}
		}
	}
};