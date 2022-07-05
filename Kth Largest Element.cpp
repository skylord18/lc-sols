#include<bits/stdc++.h>
using namespace std;
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
	int n = A.size();
	priority_queue<int>pq;
	for (int  i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pq.push(A[i] + B[j]);
		}
	}
	vector<int> ss;
	while (c--) {
		ss.push_back(pq.top());
		pq.pop();
	}
	sort(ss.begin(), ss.end(), greater<int>);
	return ss;
}
