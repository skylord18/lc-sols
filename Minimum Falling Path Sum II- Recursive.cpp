#include<bits/stdc++.h>
using namespace std;
class Solution {
	int dp[202][202];

	int func(vector<vector<int>> &grid , int i , int j , int sum , int m , int n)
	{
		if (i >= m)
		{
			return 0;
		}

		if (dp[i][j] != -1)
		{
			return dp[i][j];
		}

		int ans = INT_MAX;

		for (int k = 0; k < n  ; k++)
		{
			if (k != j)
				ans = min(ans , grid[i][k] + func(grid , i + 1 , k , sum + grid[i][k] , m , n) );
		}

		return dp[i][j] = ans;


	}

	int minFallingPathSum(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		if (n == 1 && m >= 2)
		{
			return 0;
		}

		memset(dp , -1 , sizeof(dp));

		int ans = INT_MAX;

		for (int i = 0; i < n; i++)
		{
			// it will start from next row that is 1
			// take care of these things always
			ans = min(ans , grid[0][i] + func(grid , 1 , i , grid[0][i] , m , n));
		}

		return ans;

	}
};