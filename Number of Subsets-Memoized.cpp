#include<bits/stdc++.h>
using namespace std;
int f(int idx, int sum, vector<int>&num, vector<vector<int>>&dp) {
	if (sum == 0)return 1;
	if (idx == 0)return (num[0] == sum);
	if (dp[idx][sum] != -1)return dp[idx][sum];
	int nonpick = f(idx - 1, sum, num, dp);
	int pick = 0;
	if (num[idx] <= sum)pick = f(idx - 1, sum - num[idx], num, dp);
	return dp[idx][sum] = nonpick + pick;
}
int findWays(vector<int> &num, int tar) {
	// Write your code here.
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
	return f(n - 1, tar, num, dp);
}