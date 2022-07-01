#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void findSubsets(int idx, vector<vector<int>> ans, vector<int>ds, vector<int>nums) {
		ans.push_back(ds);
		for (int i = idx; i < nums.size(); ++i)
		{
			/* code */
			if (idx != 0 && nums[i - 1] == nums[i])
				continue;
			ds.push_back(nums[i]);
			findSubsets(i + 1, ans, ds, nums);
			ds.pop_back();
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>>ans;
		vector<int>ds;
		sort(nums.begin(), nums.end());
		findSubsets(0, ans, ds, nums);
		return ans;
	}
};