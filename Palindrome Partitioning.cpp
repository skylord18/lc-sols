#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}
		return  true;
	}
public:
	void generatePartitions(string s, int idx, vector<vector<string>>&ans, vector<string>&ds) {
		if (idx == s.length())
		{
			ans.push_back(ds);
			return;
		}
		for (int i = idx; i < s.length(); i++) {
			if (isPalindrome(s, idx, i)) {
				ds.push_back(s.substr(idx, i - idx + 1));
				generatePartitions(s, i + 1, ans, ds);
				ds.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> ds;
		generatePartitions(s, 0, ans, ds);
		return ans;
	}
};