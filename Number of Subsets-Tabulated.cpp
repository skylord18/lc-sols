#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int tar) {
	// Write your code here.
	int n = num.size();
	vector<vector<int>>dp(n, vector<int>(tar + 1, 0));
	for (int i = 0; i < n; ++i)dp[i][0] = 1;
	if (num[0] <= tar)dp[0][num[0]] = 1;
	for (int idx = 1; idx < n; idx++) {
		for (int sum = 0; sum <= tar; sum++) {
			int nonpick = dp[idx - 1][sum];
			int pick = 0;
			if (num[idx] <= sum)pick = dp[idx - 1][ sum - num[idx]];
			dp[idx][sum] = nonpick + pick;
		}
	}
	return dp[n - 1][tar];
}