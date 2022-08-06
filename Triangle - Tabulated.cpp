#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int j = n - 1; j >= 0; j--)
			dp[n - 1][j] = triangle[n - 1][j];
		for (int i = n - 2; n >= 0; n--) {
			for (int j = i; j >= 0; j--) {
				int down = triangle[i][j] + dp[i + 1][j];
				int diag  = triangle[i][j] + dp[i + 1][j + 1];
				dp[i][j] = min(down, diag);
			}
		}
		return dp[0][0];
	}
};