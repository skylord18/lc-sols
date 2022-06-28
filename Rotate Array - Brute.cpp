#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> v(n, 0);
		k = k % n;
		int i = n - k;
		int kk = 0;
		for (i ; i < n; i++) {
			v[kk] = nums[i];
			kk++;
		}
		int j = 0;
		for (kk; kk < n; kk++) {
			v[kk] = nums[j];
			j++;
		}
		for (int i = 0; i < n; i++) {
			nums[i] = v[i];
		}

	}
};