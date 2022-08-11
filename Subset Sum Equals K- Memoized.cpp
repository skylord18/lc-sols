#include<bits/stdc++.h>
using namespace std;
bool f(int idx, int target, vector<int>&arr, vector<vector<int>>&dp) {
	if (target == 0)return true;
	if (idx == 0)return (arr[0] == target);
	if (dp[idx][target] != -1)return dp[idx][target];
	bool nonPick = f(idx - 1, target, arr, dp);
	bool Pick = false;
	if (arr[idx] <= target)Pick = f(idx - 1, target - arr[idx], arr, dp);
	return dp[idx][target] = Pick || nonPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(k, -1));
	return f(n - 1, k, arr, dp);
}
