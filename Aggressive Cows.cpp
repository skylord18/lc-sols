#include<bits/stdc++.h>
using namespace std;
bool isPlacingCowsPossible(vector<int>&stalls, int cows, int minDist) {
	int cntCows = 1;
	int lastPlacedCow = stalls[0];
	for (int i = 1; i < stalls.size(); i++) {
		if (stalls[i] - lastPlacedCow >= minDist) {

			cntCows++;
			lastPlacedCow = stalls[i];
		}
	}
	if (cntCows >= cows)
		return true;
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		vector<int> stalls(n);
		for (int i = 0; i < n; ++i) {
			cin >> stalls[i];
		}
		sort(stalls.begin(), stalls.end());
		int low = 1, high = stalls[n - 1] - stalls[0];
		int ans = 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (isPlacingCowsPossible(stalls, c, mid) == true) {
				ans = low;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}