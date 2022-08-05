#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//vector<int> dp(heights.size(),-1);
int f(int index, int k, vector<int>&heights, vector<int>&dp) {
	if (index == 0)
		return 0;
	if (dp[index] != -1)
		return dp[index];
	for (int j = 0; j <= k; j++) {
		if (index - j >= 0)
			dp[index]  = min(dp[index], f(index - j, k, heights, dp) + abs(heights[index] - heights[index - j]));
	}
	return dp[index];
}