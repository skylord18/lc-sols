#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		set<int> s;
		for (auto it : nums)
			s.insert(it);
		int cnt = 0;
		for (auto it : s)
			if (it != 0)
				cnt++;
		return cnt;
	}
};