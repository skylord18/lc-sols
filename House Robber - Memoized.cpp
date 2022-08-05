#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int house(int index, vector<int>&nums, vector<int>&dp) {
		if (index == 0)
			return nums[index];
		if (index < 0)
			return 0;
		if (dp[index] != -1)
			return dp[index];
		int pick = nums[index] + house(index - 2, nums, dp);
		int nonpick = house(index - 1, nums, dp);
		return max(pick, nonpick);
	}
public:
	int rob(vector<int>& nums) {
		vector<int> dp(nums.size() + 1, -1);
		return house(nums.size() - 1, nums, dp);
	}
};