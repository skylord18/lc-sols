#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int robH(vector<int>& nums) {
		int prev2 = 0, prev = nums[0], curi = 0, n = nums.size();
		for (int i = 1; i < nums.size(); i++) {
			int pick = nums[i];
			if (i > 1)
				pick += prev2;
			int notpick = prev;
			int curi = max(pick, notpick);
			prev2 = prev, prev  = curi;

		}
		return prev;
	}
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		vector<int> temp1, temp2;
		for (int i = 0; i < nums.size(); i++) {
			if (i != 0)
				temp1.push_back(nums[i]);
			if (i != nums.size() - 1)
				temp2.push_back(nums[i]);
		}
		return max(robH(temp1), robH(temp2));
	}
};