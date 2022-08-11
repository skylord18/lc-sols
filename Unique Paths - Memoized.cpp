#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
	int f(int i, int j) {
		if (i == 0 && j == 0)
			return 1;
		if (i < 0 || j < 0)
			return 0;
		int up = f(i - 1, j);
		int down = f(i, j - 1);
		return up + down;
	}
public:
	int uniquePaths(int m, int n) {
		return f(m - 1, n - 1);
	}
};