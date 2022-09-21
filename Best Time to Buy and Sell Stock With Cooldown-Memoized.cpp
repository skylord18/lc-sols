#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx, int buy, int n, vector<int>&prices, vector<vector<int>>&dp) {
		if (idx == n)return 0;
		if (dp[idx][buy] != -1)return dp[idx][buy];
		if (buy == 1)
			return dp[idx][buy] = max(-1 * prices[idx] + f(idx + 1, 0, n, prices, dp) , f(idx + 1, 1, n, prices, dp));
		else
			return dp[idx][buy] = max(prices[idx] + f(idx + 2, 1, n, prices, dp), f(idx + 1, 0, n, prices, dp));
	}
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>>dp(n + 1, vector<int>(2, -1));
		return f(0, 1, n, prices, dp);
	}
};