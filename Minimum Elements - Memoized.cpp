#include<bits/stdc++.h>
using namespace std;
int f(int idx, int target, vector<int>&coin, vector<vector<int>>&dp) {
	if (idx == 0) {
		if (target % coin[0] == 0)return target / coin[0];
		else return 1e9;
	}
	if (dp[idx][target] != -1)return dp[idx][target];
	int notTake = f(idx - 1, target, coin);
	int take = 1e9;
	if (coin[idx] <= target)
		take = 1 + f(idx, target - coin[idx], coin);
	return dp[idx][target] =  min(take, notTake);
}
int minimumElements(vector<int> &nums, int x) {
	// Write your code here.
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(target + 1, -1));
	int ans = f(n - 1, x, nums, dp);
	if (ans >= 1e9)return -1;
	else return ans;
}