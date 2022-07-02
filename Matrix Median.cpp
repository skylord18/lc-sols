#include<bits/stdc++.h>
using namespace std;
int func(vector<int>&arr, int val) {
	int lo = 0, hi  = arr.size() - 1, ans = 0;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;

		if (arr[mid] < val) {
			ans = mid + 1;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}
int getMedian(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size();
	int lo = 0, hi = 1e5;
	int ans  = -1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int len = 0;
		for (int i = 0; i < n; ++i)
			len += (func(matrix[i], mid));
		if (len <= (m * n) / 2) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi  = mid - 1;
		}
	}
	return ans;
}