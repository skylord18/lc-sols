#include<bits/stdc++.h>
using namespace std;
#define MOD (int) 1e9+7
#define mod (int) 1000000007
class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		horizontalCuts.push_back(h);
		sort(horizontalCuts.begin(), horizontalCuts.end());
		int maxH = horizontalCuts[0];
		for (int i = 1; i < horizontalCuts.size(); ++i) {
			maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
		}
		verticalCuts.push_back(w);
		sort(verticalCuts.begin(), verticalCuts.end());
		int maxV = verticalCuts[0];
		for (int i = 1; i < verticalCuts.size(); i++) {
			maxV = max(maxV, verticalCuts[i] - verticalCuts[i - 1]);
		}
		return (maxH * maxV) % mod;
	}
};