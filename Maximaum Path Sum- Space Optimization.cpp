#include<bits/stdc++.h>
using namespace std;
int f(int i , int j , vector<vector<int>>&matrix, vector<vector<int>>&dp) {
	if (j < 0 || j >= matrix[0].size())
		return -1e9;
	if (i == 0)
		return matrix[0][j];
	if (dp[i][j] != -1)
		return dp[i][j];
	int up = matrix[i][j] + f(i - 1, j, matrix, dp);
	int leftDiag = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
	int rightDiag = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

	return dp[i][j] = max(up, max(leftDiag, rightDiag));

}
int getMaxPathSum(vector<vector<int>> &matrix) {
	//  Write your code here.
	int n = matrix.size(), m  = matrix[0].size();
	int ans = -1e8;
	//vector<vector<int>> dp(n, vector<int>(m, 0));
	vector<int> prev(m, 0), curr(m, 0);
	for (int j = 0; j < m; j++)
		prev[j] = matrix[0][j];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int up = matrix[i][j] + prev[j];
			int leftDiag = matrix[i][j] , rightDiag = matrix[i][j];
			if (j - 1 >= 0)leftDiag += prev[j - 1];
			else leftDiag += -1e9;
			if (j + 1 < m)rightDiag += prev[j + 1];
			else rightDiag += -1e9;

			curr[j] = max(up, max(leftDiag, rightDiag));
		}
		prev = curr;
	}
	for (int j = 0; j < m; j++)
		ans = max(ans, prev[j]);
	return ans;
}