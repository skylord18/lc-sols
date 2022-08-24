#include<bits/stdc++.h>
using namespace std;
bool f(int i, int j, string s, string p, vector<vector<int>>&dp) {
	if (i == 0 && j == 0)return true;
	if (i == 0 && j > 0)return false;
	if (j == 0 && i > 0) {
		for (int ii = 1; ii <= i; ii++) {
			if (s[ii - 1] != '*')return false;
		}
		return true;
	}
	if (dp[i][j] != -1)return dp[i][j];
	if (s[i - 1] == p[j - 1] || s[i - 1] == '?')return dp[i][j] = f(i - 1, j - 1, s, p, dp);
	if (s[i - 1] == '*')return dp[i][j] = f(i - 1, j, s, p, dp) | f(i, j - 1, s, p, dp);
	return false;
}
bool wildcardMatching(string s, string p) {
	int n = s.length(), m = p.length();
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	//vector<bool> prev(m+1,false), curr(m+1,false);
	dp[0][0] = true;
	for (int j = 1; j <= m; j++)dp[0][j] = false;
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int ii = 1; ii <= i; ii++) {
			if (s[ii - 1] != '*') {
				flag = false;
				break;
			}
		}
		dp[i][0] = flag;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == p[j - 1] || s[i - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else if (s[i - 1] == '*')
				dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
			else
				dp[i][j] = false;
		}
	}
	return dp[n][m];
}