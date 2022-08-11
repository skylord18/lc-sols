#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int i , int j , vector<vector<int>>&matrix, vector<vector<int>>&dp) {
		if (j < 0 || j == matrix[0].size())
			return 1e9;
		if (i == 0)
			return matrix[i][j];
		if (dp[i][j] != -1)
			return dp[i][j];
		int up = matrix[i][j] + f(i - 1, j, matrix, dp);
		int leftDiag = matrix[i][j], rightDiag = matrix[i][j];
		if (j - 1 >= 0)leftDiag += f(i - 1, j - 1, matrix, dp);
		else leftDiag += 1e9;
		if (j + 1 < matrix[0].size())rightDiag += f(i - 1, j + 1, matrix, dp);
		else rightDiag += 1e9;
		return dp[i][j] = (min(up, min(leftDiag, rightDiag)));
	}
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m, -1));
		int mini = INT_MAX;
		for (int j = 0; j < m; j++) {
			mini = min(mini, f(n - 1, j, matrix, dp));
		}
		return mini;
	}
};