#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		vector<int> vv;
		int m = matrix.size();
		int n = maxtrix[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0j < n; j++) {
				vv.push_back(matrix[i][j]);
			}
		}
		sort(vv.begin(), vv.end());
		return vv[k - 1];
	}
};