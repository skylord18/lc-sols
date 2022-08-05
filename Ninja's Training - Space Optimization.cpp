#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points) {
	// Write your code here.
	vector<int> prev(4, -1);
	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
	for (int day = 1; day < n; day++) {
		vector<int> temp(4, -1);
		for (int last = 0; last < 4; last++) {
			for (int task = 0; task < 3; task++) {
				if (task != last) {
					temp[last] = max(temp[last], points[day][task] + prev[task]);
				}
			}
		}
		prev = temp;
	}
	return prev[3];
}