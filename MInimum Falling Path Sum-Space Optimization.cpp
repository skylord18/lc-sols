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
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>>dp(n, vector<int>(m, 0));
		vector<int>prev(m, 0), curr(m, 0);
		for (int i = 0; i < m; i++) {
			prev[i] = matrix[0][i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int l = INT_MAX, r = INT_MAX, u = INT_MAX;
				if (j > 0)
					l = matrix[i][j] + prev[j - 1];
				if (j < m - 1)
					r = matrix[i][j] + prev[j + 1];
				u = matrix[i][j] + prev[j];

				curr[j] = min(u, min(l, r));
			}
			prev = curr;
		}
		int mi = INT_MAX;

		for (int i = 0; i < m; i++) {
			mi = min(mi, prev[i]);
		}
		return mi;
	}
};