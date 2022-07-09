#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		int n1 = s.length(), n2 = t.length();
		if (n1 != n2)
			return false;
		map<char, int> mp1, mp2;
		for (int i = 0; i < n1; ++i) {
			mp1[s[i]]++;
		}
		for (int i = 0; i < n2; ++i) {
			mp2[t[i]]++;
		}
		if (mp1 == mp2)
			return true;
		return false;
	}
};