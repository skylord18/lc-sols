#include<bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &coin, int target) {
	// Write your code here.
	int n = coins.size();
	vector<vector<int>> dp(n, vector<int>(target + 1, 0));
	for (int T = 0; T <= target; T++) {
		if (T % coin[0] == 0)dp[0][T] = T / coin[0];
		else dp[0][T] = 1e9;
	}
	for (int ind = 1; ind < n; ind++) {
		for (int T = 0; T <= target; T++) {
			int notTake = dp[ind - 1][T];
			int take = 1e9;
			if (coin[idx] <= target)take = 1 + dp[ind][T - coin[idx]];
			dp[ind][T] = min(take, notTake);
		}
	}
	if (dp[n - 1][target] >= 1e9)return -1;
	return dp[n - 1][target];
}