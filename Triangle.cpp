#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int f(int i, int j , vector<vector<int>>&triangle, int n) {
		if (i == n - 1)
			return triangle[i][j];

		int down = triangle[i + 1][j] + f(i + 1, j, triangle, dp, n);
		int diag = triangle[i + 1][j + 1] + f(i + 1, j + 1, triangle, dp, n);
		return min(down, diag);
	}
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		return f(0, 0, triangle, n);
	}
};