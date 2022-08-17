#include <bits/stdc++.h>
using namespace std;
int f(int idx, int N, vector<int>&price, vector<vector<int>>&dp) {
	if (idx == 0)return N * price[0];
	if (dp[idx][N] != -1)return dp[idx][N];
	int notTake = f(idx - 1, N, price, dp);
	int take = INT_MIN;
	int rodLength = idx + 1;
	if (rodLength <= N)take = price[idx] + f(idx, N - rodLength, price, dp);
	return dp[idx][N] = max(take, notTake);
}
int cutRod(vector<int> &price, int n) {
	// Write your code here.
	int sz = price.size();
	vector<vector<int>>dp(sz, vector<int>(n + 1, 0));
	for (int j = 0; j <= n; j++)dp[0][j] = price[0] * j;
	for (int idx = 1; idx < n; idx++) {
		for (int N = 0; N <= n; N++) {
			int notTake = dp[idx - 1][N];
			int take = INT_MIN;
			int rodLength = idx + 1;
			if (rodLength <= N)take = price[idx] + dp[idx][N - rodLength];
			dp[idx][N] = max(take, notTake);
		}
	}
	return dp[sz - 1][n];
}
