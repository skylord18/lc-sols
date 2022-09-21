#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx, int buy, vector<int>&prices) {
		if (idx == prices.size())return 0;
		int profit;
		if (buy) {
			profit = max(-1 * prices[idx] + f(idx + 1, 0, prices), f(idx + 1, 1, prices));
		} else {
			profit = max(prices[idx] + f(idx + 1, 1, prices), f(idx + 1, 0, prices));
		}
		return profit;
	}
public:
	int maxProfit(vector<int>& prices) {
		return f(0, 1, prices);
	}
};