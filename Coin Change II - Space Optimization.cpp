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
		return dp[idx][target] = take + notTake;
	}
public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		//vector<vector<int>>dp(n, vector<int>(amount + 1, 0));
		vector<int>prev(amount + 1, 0), curr(amount + 1, 0);
		for (int T = 0; T <= amount; T++) {
			if (T % coins[0] == 0)prev[T] = 1;
		}
		for (int idx = 1; idx < n; idx++) {
			for (int tgt  = 0; tgt <= amount; tgt++) {
				int notTake = prev[tgt];
				int take = 0;
				if (coins[idx] <= tgt)take =  curr[tgt - coins[idx]];
				curr[tgt] = take + notTake;
			}
			prev = curr;
		}
		return prev[amount];
	}
};