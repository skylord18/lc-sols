#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx, int target, vector<int>&coins, vector<vector<int>>&dp) {
		if (idx == 0) {
			if (target % coins[idx] == 0)return 1;
			else return 0;
		}
		if (dp[idx][target] != -1)return dp[idx][target];
		int notTake = f(idx - 1, target, coins, dp);
		int take = 0;
		if (coins[idx] <= target)take = f(idx, target - coins[idx], coins, dp);
		return take + notTake;
	}
public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
		return f(n - 1, amount, coins, dp);
	}
};