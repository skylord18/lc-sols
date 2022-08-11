#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int i , int j , vector<vector<int>>&matrix) {
		if (j < 0 || j == matrix[0].size())
			return 1e9;
		if (i == 0)
			return matrix[i][j];
		int up = matrix[i][j] + f(i - 1, j, matrix);
		int leftDiag = matrix[i][j], rightDiag = matrix[i][j];
		if (j - 1 >= 0)leftDiag += f(i - 1, j - 1, matrix);
		else leftDiag += 1e9;
		if (j + 1 < matrix[0].size())rightDiag += f(i - 1, j + 1, matrix);
		else rightDiag += 1e9;
		return (min(up, min(leftDiag, rightDiag)));
	}
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		int mini = INT_MAX;
		for (int j = 0; j < m; j++) {
			mini = min(mini, f(n - 1, j, matrix));
		}
		return mini;
	}
};