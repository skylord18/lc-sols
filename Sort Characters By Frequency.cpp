#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string frequencySort(string s) {
		map<char, int> mpp;
		for (char ch : s) {
			mpp[ch]++;
		}
		priority_queue<pair<int, char>> pq;
		for (auto it : mpp) {
			pq.push({it.second, it.first});
		}
		string ss = "";
		while (!pq.empty()) {
			auto ii = pq.top();
			pq.pop();
			char ch = ii.second;
			int freq = ii.first;
			while (freq--) {
				ss += ch;
			}
		}
		return ss;

	}
};