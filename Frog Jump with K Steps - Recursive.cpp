#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int f(int index, int k, vector<int>&heights) {
	if (index == 0)
		return 0;
	int minSteps = INT_MAX;
	for (int j = 0; j <= k; j++) {
		if (index - j >= 0)
			minSteps = min(minSteps, f(index - j, k, heights) + abs(heights[index] - heights[index - j]));
	}
	return minSteps;
}