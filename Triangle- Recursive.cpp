#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int f(vector<vector<int>>&triangle, int i , int j) {
		if (i == triangle.size())
			return 0;
		int remaining = min(f(triangle, i + 1, j), f(triangle, i + 1, j + 1));
		return triangle[i][j] + remaining;
	}
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		return f(triangle, 0, 0);
	}
};