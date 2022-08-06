// A C/C++ Program to generate OTP (One Time Password)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
		map<int, int> mpp;
		for (auto it : items1) {
			mpp[it[0]] = it[1];
		}
		for (auto it : items2) {
			if (mpp.find(it[0]) != mpp.end()) {
				mpp[it[0]] += it[1];
			} else {
				mpp[it[0]] = it[1];
			}
		}
		vector<vector<int>> v;
		for (auto it : mpp) {
			vector<int> col;
			col.push_back(it.first);
			col.push_back(it.second);
			v.push_back(col);
		}
		return v;

	}
};