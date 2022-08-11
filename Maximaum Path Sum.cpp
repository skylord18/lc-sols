#include<bits/stdc++.h>
using namespace std;
int f(int i , int j , vector<vector<int>>&matrix) {
	if (j < 0 || j >= matrix[0].size())
		return -1e9;
	if (i == 0)
		return matrix[0][j];

	int up = matrix[i][j] + f(i - 1, j, matrix);
	int leftDiag = matrix[i][j] + f(i - 1, j - 1, matrix);
	int rightDiag = matrix[i][j] + f(i - 1, j + 1, matrix);

	return max(up, max(leftDiag, rightDiag));

}
int getMaxPathSum(vector<vector<int>> &matrix) {
	//  Write your code here.
	int n = matrix.size(), m  = matrix[0].size();
	int ans = -1e8;
	for (int j = 0; j < m; j++) {
		ans = max(ans, f(n - 1, j, matrix));
	}
	return ans;
}