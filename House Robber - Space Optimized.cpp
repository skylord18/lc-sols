#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
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
};