#include<bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx, int prev, vector<int>&nums, int n) {
		if (idx == n)return 0;
		int len = 0 + f(idx + 1, prev, nums, n);
		if (prev == -1 || nums[idx] > nums[prev])len = max(len, 1 + f(idx + 1, idx, nums, n));
		return len;
	}
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		return f(0, -1, nums, n);
	}
};