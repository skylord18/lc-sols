#include<bits/stdc++.h>
using namespace std;
int f(int idx, int W, vector<int>&val, vector<int>& wt) {
	if (idx == 0)return ((int)W / wt[0]) * val[0];
	int notTake  = f(idx - 1, W , val, wt);
	int take = INT_MIN;
	if (wt[idx] <= W) take = val[idx] + f(idx, W - wt[idx] , val, wt);
	return max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
	// Write Your Code Here.
	return f(n - 1, w, profit, weight);
}
