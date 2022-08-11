#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int minimumDifference(vector<int>& arr) {
		int totalSum = accumulate(arr.begin(), arr.end(), 0);
		int sz = arr.size();
		vector<vector<bool>>dp(sz, vector<bool>(totalSum + 1, 0));
		for (int i = 0; i < sz; i++)dp[i][0] = true;
		if (arr[0] <= totalSum)dp[0][arr[0]] = true;
		for (int i = 1; i < sz; i++) {
			for (int target = 1; target <= totalSum; target++) {
				bool nonPick = dp[i - 1][target];
				bool pick = false;
				if (arr[i] <= target) {
					pick = dp[i - 1][target - arr[i]];
				}
				dp[i][target] = nonPick | pick;
			}
		}
		int mini  = 1e9;
		for (int i = 1; i < totalSum / 2; i++) {
			if (dp[sz - 1][i] == true) {
				int s1 = i;
				int s2 = totalSum - i;
				mini = min(mini, abs(s2 - s1));
			}
		}
		return mini;
	}
};