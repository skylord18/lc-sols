#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		map<char, int> mpp;
		vector<string> ans;
		for (int i = 0; i < s.length(); i++)
			mpp[s[i]]++;
		for (string it : words) {
			vector<int> freq(26, 0);
			for (int i = 0; i < it.length(); i++)
				freq[it[i] - 'a']++;
			bool doesExist = true;
			for (int i = 0; i < freq.size(); i++) {
				char c = freq[i] + 'a';
				if (freq[i] > mpp[c]) {
					doesExist = false;
					break;
				}
			}
			if (doesExist == true)
				ans.push_back(it);
		}
		return ans.size();
	}
};