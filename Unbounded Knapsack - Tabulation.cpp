#include<bits/stdc++.h>
using namespace std;
int f(int idx, int W, vector<int>&val, vector<int>& wt, vector<vector<int>>&dp) {
	if (idx == 0)return ((int)W / wt[0]) * val[0];
	if (dp[idx][W] != -1)return dp[idx][W];
	int notTake  = f(idx - 1, W , val, wt, dp);
	int take = INT_MIN;
	if (wt[idx] <= W) take = val[idx] + f(idx, W - wt[idx] , val, wt, dp);
	return dp[idx][W] =  max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
	vector<vector<int>> t(n + 1, vector<int>(w + 1));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (j >= weight[i - 1])
				t[i][j] = max(t[i - 1][j], profit[i - 1] + t[i][j - weight[i - 1]]);
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][w];
}