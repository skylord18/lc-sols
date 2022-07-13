#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> mpp;
		for (int i = 0; i < words.size(); i++) {
			map[words[i]]++;
		}
		priority_queue<pair<string, int>>pq;
		for (auto it : mpp) {
			pq.push(it);
		}
		vector<string> ans;
		while (k--) {
			ans.push_back(pq.top().first);
			pq.pop();
		}
		return ans;
	}
};