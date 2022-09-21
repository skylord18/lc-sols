#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx, int trx, int n, vector<int>&prices, vector<vector<int>>&dp) {
		if (idx == n || trx == 4)return 0;
		if (dp[idx][trx] != -1)return dp[idx][trx];
		if (trx % 2 == 0)return dp[idx][trx] = max(-1 * prices[idx] + f(idx + 1, trx + 1 , n, prices, dp) , 0 + f(idx + 1, trx, n, prices, dp));
		else return dp[idx][trx] = max(prices[idx] + f(idx + 1, trx + 1, n, prices, dp) , 0 + f(idx + 1 , trx , n , prices, dp));
	}
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		//vector<vector<int>>dp(n + 1, vector<int>(2 * k + 1, 0));
		vector<int> after(2 * k + 1, 0);
		vector<int> curr(2 * k + 1, 0);
		for (int idx = n - 1; idx >= 0; idx--) {
			for (int trx = 2 * k - 1; trx >= 0; trx--) {
				if (trx % 2 == 0) curr[trx] = max(-1 * prices[idx] + after[trx + 1] , 0 + after[trx]);
				else curr[trx] = max(prices[idx] + after[trx + 1] , 0 + after[trx]);
			}
			after = curr;
		}
		return after[0];
	}
};