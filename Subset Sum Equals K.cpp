#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(int i, vector<int>&nums, int prev, vector<vector<int>>&dp) {
		if (i >= nums.size())
			return 0;
		if (dp[i][prev + 1] != -1)
			return dp[i][prev + 1];
		int Pick = 0;
		if (prev == -1 || nums[i] > nums[prev]) {
			Pick = 1 + f(i + 1, nums, i, dp);
		}
		int nonPick = 0;
		nonPick = f(i + 1, nums, prev, dp);
		return dp[i][prev + 1] = max(Pick, nonPick);
	}

	int lengthOfLIS(vector<int>& nums) {
		vector<vector<int>>dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
		return f(0, nums, -1, dp);
	}
};