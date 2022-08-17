#include<bits/stdc++.h>
using namespace std;
int f(int idx, int target, vector<int>&coin) {
	if (idx == 0) {
		if (target % coin[0] == 0)return target / coin[0];
		else return 1e9;
	}
	int notTake = f(idx - 1, target, coin);
	int take = 1e9;
	if (coin[idx] <= target)
		take = 1 + f(idx, target - coin[idx], coin);
	return min(take, notTake);
}
int minimumElements(vector<int> &nums, int x) {
	// Write your code here.
	int n = nums.size();
	int ans = f(n - 1, x, nums);
	if (ans >= 1e9)return -1;
	else return ans;
}