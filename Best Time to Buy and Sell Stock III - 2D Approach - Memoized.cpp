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
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>>dp(n + 1, vector<int>(4, -1));
		return f(0, 0, n, prices, dp);
	}
};