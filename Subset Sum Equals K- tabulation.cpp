#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
	// Write your code here.
	vector<vector<bool>>dp(n, vector<bool>(k + 1));
	for (int i = 0; i < n; i++)dp[i][0] = true;
	dp[0][arr[0]] = true;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			bool take = false;
			if (arr[i] <= j)take = dp[i - 1][j - arr[i]];
			bool notTake = dp[i - 1][j];
			dp[i][j] = take | notTake;
		}
	}
	return dp[n - 1][k];
}