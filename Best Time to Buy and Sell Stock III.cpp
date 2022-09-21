#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx, int buy, int cap, vector<int>&prices , int n ) {
		if (cap == 0)return 0;
		if (idx == n)return 0;
		int take = 0, notTake = 0;
		if (buy) {
			take = ((-1) * prices[idx] + f(idx + 1, 0, cap, prices, n));
			notTake = (0 + f(idx + 1, 1, cap , prices, n));
			return max(take, notTake);
		} else {
			take = (prices[idx] + f(idx + 1, 1, cap - 1, prices, n));
			notTake = (0 + f(idx + 1 , 0, cap, prices , n));
			return max(take, notTake);
		}
	}
public:
	int maxProfit(vector<int>& prices) {
		return f(0, 1, 2, prices , prices.size());
	}
};