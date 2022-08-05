#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int f(int i, int j, vector<vector<int>>&dp) {
		if (i == 0 && j == 0)
			return 1;
		if (i < 0 || j < 0)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		int up = f(i - 1, j, dp);
		int down = f(i, j - 1, dp);
		return dp[i][j] = up + down;
	}
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, -1));
		return f(m - 1, n - 1, dp);
	}
};