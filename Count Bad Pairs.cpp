// A C/C++ Program to generate OTP (One Time Password)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	long long countBadPairs(vector<int>& nums) {
		unordered_map<long long, int>mp;
		for (int i = 0; i < nums.size(); i++) {
			mp[i - nums[i]]++;
		}

		long long pair = 0;
		for (int i = 0; i < nums.size(); i++) {
			long long diff = i - nums[i];
			mp[diff]--;
			pair += nums.size() - i - 1 - mp[diff];
		}
		return pair;
	}
};