#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int house(int index, vector<int>&nums) {
		if (index == 0)
			return nums[index];
		if (index < 0)
			return 0;
		int pick = nums[index] + house(index - 2, nums);
		int nonpick = house(index - 1, nums);
		return max(pick, nonpick);
	}
public:
	int rob(vector<int>& nums) {
		return house(nums.size() - 1, nums);
	}
};