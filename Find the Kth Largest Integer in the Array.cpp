#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// sort nums in decreasing order
	static bool sort_string_nums(const string& a, const string& b) {
		if (a.length() == b.length()) return a > b;
		else return a.length() > b.length();
	}

	// return k-th largest value at index k - 1
	string kthLargestNumber(vector<string>& nums, int k) {
		sort(nums.begin(), nums.end(), sort_string_nums);
		return nums[k - 1];
	}
};