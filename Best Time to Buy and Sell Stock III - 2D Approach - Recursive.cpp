#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx, int buy, int cap, vector<int>&prices , int n, vector<vector<vector<int>>> &dp) {
		if (cap == 0)return 0;
		if (idx == n)return 0;
		if (dp[idx][buy][cap] != -1)return dp[idx][buy][cap];
		int take = 0, notTake = 0;
		if (buy) {
			take = ((-1) * prices[idx] + f(idx + 1, 0, cap, prices, n, dp));
			notTake = (0 + f(idx + 1, 1, cap , prices, n, dp));
			return dp[idx][buy][cap] = max(take, notTake);
		} else {
			take = (prices[idx] + f(idx + 1, 1, cap - 1, prices, n, dp));
			notTake = (0 + f(idx + 1 , 0, cap, prices , n, dp));
			return dp[idx][buy][cap] = max(take, notTake);
		}
	}
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
		vector<vector<int>>after(2, vector<int>(3, 0));
		vector<vector<int>>curr(2, vector<int>(3, 0));
		for (int idx = n - 1; idx >= 0; idx--) {
			for (int buy = 0; buy <= 1; buy++) {
				for (int cap = 1; cap <= 2; cap++) {
					int take = 0, notTake = 0;
					if (buy) {
						take = ((-1) * prices[idx] + after[0][cap]);
						notTake = (0 + after[1][cap]);
						curr[buy][cap] = max(take, notTake);
					} else {
						take = (prices[idx] + after[1][cap - 1] );
						notTake = (0 + after[0][cap]);
						curr[buy][cap] = max(take, notTake);
					}
				}
			}
			after = curr;
		}
		return after[1][2];
	}
};