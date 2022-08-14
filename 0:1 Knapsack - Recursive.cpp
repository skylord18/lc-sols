#include <bits/stdc++.h>
using namespace std;
int f(int idx, int Wt, vector<int>&weight, vector<int>&value, int n) {
	if (idx == 0) {
		if (weight[0] <= Wt)return value[0];
		else return 0;
	}
	int notTake = f(idx - 1, Wt, weight, value, n);
	int take = INT_MIN;
	if (weight[idx] <= Wt)
		take = value[idx] + f(idx - 1, Wt - weight[idx], weight, value, n);
	return max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
	return f(n - 1, maxWeight, weight, value, n);
}