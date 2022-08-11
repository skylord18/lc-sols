#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int tar) {
	// Write your code here.
	int n = num.size();
	//vector<vector<int>>dp(n, vector<int>(tar + 1, 0));
	vector<int> prev (tar + 1, 0), curr(tar + 1, 0);
	prev[0] = curr[0] = 1;
	if (num[0] <= tar)prev[num[0]] = 1;
	for (int idx = 1; idx < n; idx++) {
		for (int sum = 0; sum <= tar; sum++) {
			int nonpick = prev[sum];
			int pick = 0;
			if (num[idx] <= sum)pick = prev[ sum - num[idx]];
			curr[sum] = nonpick + pick;
		}
		prev = curr;
	}
	return prev[tar];
}