#include<bits/stdc++.h>
using namespace std;
class Solution {
	long long int findPathsHelper(long long int m, long long int n , long long int N, long long int i , long long int j, vector<vector<vector<long long int>>>& dp) {
		if (i == m || j == n || i < 0 || j < 0) return 1;
		if (N == 0) return 0;
		if (dp[N][i][j] != -1)
			return dp[N][i][j] % 1000000007;

		return dp[N][i][j] = findPathsHelper(m, n, N - 1, i - 1, j, dp) % 1000000007 + findPathsHelper(m, n, N - 1, i + 1, j, dp) % 1000000007 + findPathsHelper(m, n, N - 1, i, j - 1, dp) % 1000000007 + findPathsHelper(m, n, N - 1, i, j + 1, dp) % 1000000007;
	}
public:
	int findPaths(long long int m, long long int n, long long int N, long long int i, long long int j) {
		vector<vector<vector<long long int>>> dp(N + 1, vector<vector<long long int>> (m + 1, vector<long long int> (n + 1, -1)));
		long long int ans = findPathsHelper(m, n, N, i, j, dp);
		return ans % 1000000007;
	}
};