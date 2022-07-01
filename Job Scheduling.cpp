#include<bits/stdc++.h>
using namespace std;
static bool comparator(vector<int> j1, vector<int> j2) {
	if (j1[1] > j2[1])
		return true;

	return false;
}
int jobScheduling(vector<vector<int>> &jobs)
{
	// Write your code here
	sort(jobs.begin(), jobs.end(), comparator);
	int maxi = jobs[0][1];
	for (int i = 0; i < jobs.size(); i++) {
		maxi = max(maxi, jobs[i][1]);
	}
	int slots [maxi + 1];
	for (int i = 0; i <= maxi; ++i)
	{
		/* code */
		slots[i] = -1;
	}
	int totalJobsDone = 0;

	for (int i = 0; i < jobs.size(); ++i)
	{
		/* code */
		for (int j = jobs[i][1]; j > 0; j--) {
			if (slots[j] != -1) {
				totalJobsDone++;
				slots[i] = jobs[i][1];
			}
		}
	}
	return totalJobsDone;
}
