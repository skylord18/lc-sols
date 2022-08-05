#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> prev (n, 0);
		for (int i = 0; i < m; i++) {
			vector<int>cur(n, 0);
			for (int j = 0; j < n; j++) {
				int up = 0, left = 0;
				if (i == 0 && j == 0) {
					cur[j] = 1;
				}
				else {
					if (i > 0)
						up = prev[j];
					if (j > 0)
						left = cur[j - 1];
					prev[j] = up + left;
				}
			}
			prev = cur;
		}
		return prev[n - 1];
	}
};