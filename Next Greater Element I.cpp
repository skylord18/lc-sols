#include<bits/stdc++.h>
using namespace std;
class Solution {
	int getIndex(vector<int> v, int K)
	{
		auto it = find(v.begin(), v.end(), K);

		int index = it - v.begin();
		return index;
	}
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nge(nums1.size(), -1);
		for (int i = 0; i < nge.size(); ++i) {
			int idx = getIndex(nums2, nums1[i]);
			for (int j = idx + 1; j < nums2.size(); j++) {
				if (nums2[j] > nums1[i]) {
					nge[i] = nums2[j];
					break;
				}
			}
		}
		return nge;
	}
};