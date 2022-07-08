#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		//pair<int,pair<int,int>>
		priority_queue<pair<int, pair<int, int>>> pq;
		for (int i = 0; i < arr.size(); i++) {
			//pair<int,int> p1 = {arr[i],i};
			pair<int, pair<int, int>> p = {abs(arr[i] - x), {arr[i], i}};
			pq.push(p);
		}
		int tp = (k - arr.size());
		if (tp < 0)
			tp = abs(tp);
		while (tp--)
			pq.pop();
		vector<int>ans;
		while (!pq.empty()) {
			auto it = pq.top();
			int n = it.second.first;
			ans.push_back(n);
			pq.pop();
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};