#include <bits/stdc++.h>
using namespace std;
int f(int idx, int Wt, vector<int>&weight, vector<int>&value, int n, vector<vector<int>>&dp) {
	if (idx == 0) {
		if (weight[0] <= Wt)return value[0];
		else return 0;
	}
	if (dp[idx][Wt] != -1)return dp[idx][Wt];
	int notTake = f(idx - 1, Wt, weight, value, n, dp);
	int take = INT_MIN;
	if (weight[idx] <= Wt)
		take = value[idx] + f(idx - 1, Wt - weight[idx], weight, value, n, dp);
	return dp[idx][Wt] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	return f(n - 1, maxWeight, weight, value, n, dp);
}