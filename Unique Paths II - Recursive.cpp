#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int f(int i, int j , vector<vector<int>>obstacleGrid, int m, int n) {
		if (i >= 0 && j >= 0 && obstacleGrid[i][j] == -1)
			return 0;
		if (i == 0 && j == 0)
			return 1;
		if (i < 0 || j < 0)
			return 0;
		int up = f(i - 1, j, obstacleGrid, m, n);
		int left = f(i, j - 1, obstacleGrid, m, n);
		return up + left;
	}
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
		return f(n - 1, m - 1, obstacleGrid, n, m);
	}
};