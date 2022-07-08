#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> mpp;

		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < nums.size(); ++i)
		{
			/* code */
			mpp[nums[i]]++;
		}
		for (auto it : mpp) {
			pq.push({it.second, it.first});
		}
		vector<int> vv;
		while (k--) {
			auto top = pq.top();
			pq.pop();
			vv.push_back(top.second);
		}
		return vv;
	}
};