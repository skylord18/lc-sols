#include<bits/stdc++.h>
using namespace std;
bool f(int idx, int target, vector<int>&arr) {
	if (target == 0)return true;
	if (idx == 0)return (arr[0] == target);
	bool nonPick = f(idx - 1, target, arr);
	bool Pick = false;
	if (arr[idx] <= target)Pick = f(idx - 1, target - arr[idx], arr);
	return Pick || nonPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
	// Write your code here.
	return f(n - 1, k, arr);
}