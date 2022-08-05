#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int f(int i, int j, vector<vector<int>>&grid) {
		if (i == 0 && j == 0)
			return grid[0][0];
		if (i < 0 || j < 0)
			return 1e9;
		int up = grid[i][j] + f(i - 1, j, grid);
		int left = grid[i][j] + f(i, j - 1, grid);
		return min(up, left);
	}
public:
	int minPathSum(vector<vector<int>>& grid) {
		return f(grid.size() - 1, grid[0].size() - 1, grid);
	}
};