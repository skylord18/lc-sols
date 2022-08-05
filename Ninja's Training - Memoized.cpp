#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int f(int day, int task, vector<vector<int>>&points, vector<vector<int>> &dp) {
	if (day == 0) {
		int maxi = 0;
		for (int i = 0; i < 3; i++) {
			if (i != task) {
				maxi = max(maxi, points[0][i]);
			}
		}
		return maxi;
	}
	if (dp[day][task] != -1)
		return dp[day][task];
	int maxi = 0;
	for (int i = 0; i < 3; i++) {
		if (i != task) {
			int p = points[day][i] + f(day - 1, i, points, dp);
			maxi = max(maxi, p);
		}
	}
	return dp[day][task] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
	// Write your code here.
	vector<vector<int>> dp(n + 1, vector<int>(4, -1));
	return f(n - 1, 3, points, dp);
}