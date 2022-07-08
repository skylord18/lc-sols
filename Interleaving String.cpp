#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool help(string s1, int i, string s2, int j, string res, string s3) {
		if (res == s3 && i == s1.length() && j == s2.length())
			return true;
		bool ans = false;
		if (i < s1.length())
			ans |= help(s1, i + 1, s2, j, res + s1[i], s3);
		if (j < s2.length())
			ans |= help(s1, i, s2, j + 1, res += s2[j], s3);
		return false;
	}
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return  false;
		return (help(s1, 0, s2, 0, "", s3));
	}
};