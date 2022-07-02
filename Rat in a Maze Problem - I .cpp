#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void solve(int i, int j, vector<vector<int>> & m, int n, vector<string> & ans, string moves, vector<vector<int>> & vis) {
		if (i == n - 1 && j == n - 1) {
			ans.push_back(moves);
			return;
		}
		//DLRU
		if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1) {
			vis[i][j] = 1;
			solve(i + 1, j, m, n, ans, moves + 'D', vis);
			vis[i][j] = 0;
		}
		if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1) {
			vis[i][j] = 1;
			solve(i, j - 1, m, n, ans, moves + 'L', vis);
			vis[i][j] = 0;
		}
		if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1) {
			vis[i][j] = 1;
			solve(i, j + 1, m, n, ans, moves + 'R', vis);
			vis[i][j] = 0;
		}
		if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1) {
			vis[i][j] = 1;
			solve(i - 1, j, m, n, ans, moves + 'U', vis);
			vis[i][j] = 0;
		}

	}
public:
	vector<string> findPath(vector<vector<int>> &m, int n) {
		// Your code goes here
		vector<string> ans;
		vector<vector<int>> vis(n, vector<int>(n, 0));
		if (m[0][0] == 1)
			solve(0, 0, m, n, ans, "", vis);
		return ans;
	}
};