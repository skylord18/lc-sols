#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int f(int idx1, int idx2, string s1, string s2, vector<vector<int>>&dp) {
    if (idx1 < 0 || idx2 < 0)return 0;
    if (dp[idx1][idx2] != -1)return dp[idx1][idx2];
    if (s1[idx1] == s2[idx2])return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, s1, s2, dp);
    return dp[idx1][idx2] = max(f(idx1 - 1, idx2, s1, s2, dp), f(idx1, idx2 - 1, s1, s2, dp));
  }
public:
  int longestCommonSubsequence(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    vector<int> prev(n2 + 1), cur(n2 + 1, 0);
    for (int i = 0; i <= n1; i++)prev[0] = 0;
    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
        else cur[j] = max(prev[j], cur[j - 1]);
      }
      prev = cur;
    }
    return prev[n2];
  }
public:
  int longestPalindromeSubseq(string s) {
    string s1 = s;
    reverse(s.begin(), s.end());
    return longestCommonSubsequence(s1, s);
  }
public:
  int minInsertions(string str) {
    int l = str.length();
    int s = longestPalindromeSubseq(str);
    return l - s;
  }
};