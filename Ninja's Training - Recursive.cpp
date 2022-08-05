#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int f(int day, int task, vector<vector<int>>&points) {
	if (day == 0) {
		int maxi = 0;
		for (int i = 0; i < 3; i++) {
			if (i != task) {
				maxi = max(maxi, points[0][i]);
			}
		}
		return maxi;
	}
	int maxi = 0;
	for (int i = 0; i < 3; i++) {
		if (i != task) {
			int p = points[day][i] + f(day - 1, i, points);
			maxi = max(maxi, p);
		}
	}
	return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
	// Write your code here.
	return f(n - 1, 3, points);
}