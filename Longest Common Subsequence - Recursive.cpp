#include <bits/stdc++.h>
using namespace std;
class Solution {
	int f(int idx1, int idx2, string s1, string s2) {
		if (idx1 < 0 || idx2 < 0)return 0;
		if (s1[idx1] == s2[idx2])return 1 + f(idx1 - 1, idx2 - 1, s1, s2);
		return max(f(idx1 - 1, idx2, s1, s2), f(idx1, idx2 - 1, s1, s2));
	}
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n1 = text1.length(), n2 = text2.length();
		return f(n1 - 1, n2 - 1, text1, text2);
	}
};