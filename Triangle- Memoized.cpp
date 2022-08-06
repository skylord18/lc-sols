#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int f(vector<vector<int>>&triangle, int i , int j, vector<vector<int>>&dp) {
		if (i == triangle.size())
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		int remaining = min(f(triangle, i + 1, j, dp), f(triangle, i + 1, j + 1, dp));
		return dp[i][j] = triangle[i][j] + remaining;
	}
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>> dp (n, vector<int>(0, 0));
		for (int i = 0; i < n; i++) {
			dp[i].resize(triangle[i].size());
			for (int j = 0; j < triangle[i].size(); j++) {
				dp[i][j] = -1;
			}
		}
		return f(triangle, 0, 0, dp);
	}
};