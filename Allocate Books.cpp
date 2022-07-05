#include<bits/stdc++.h>
using namespace std;
int isPossible(vector < int > & A, int pages, int students) {
	int cnt = 0;
	int sumAllocated = 0;
	for (int i = 0; i < A.size(); i++) {
		if (sumAllocated + A[i] > pages) {
			cnt++;
			sumAllocated = A[i];
			if (sumAllocated > pages) return false;
		} else {
			sumAllocated += A[i];
		}
	}
	if (cnt < students) return true;
	return false;
}
int Solution::books(vector<int> &A, int B) {
	if (B > A.size()) return -1;
	int low = *min_element(A.begin(), A.end());
	int sum = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		/* code */
		sum += A[i];
	}
	int high = sum, res = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(A, mid, B) == true) {
			res = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return low;
}
