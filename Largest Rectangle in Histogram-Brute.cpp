#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int maxArea = 0;
		int n = heights.size();
		for (int i = 0; i < n; ++i) {
			int minH = INT_MAX;
			for (int j = i; j < n; j++) {
				minH = min(minH, heights[j]);
				maxArea = max(maxArea, minH * (j - i + 1));
			}
		}
		return maxArea;
	}
};
