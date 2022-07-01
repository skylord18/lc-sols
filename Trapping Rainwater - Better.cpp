#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefixMaximum[n], suffixMaximum[n];
        prefixMaximum[0] = height[0];

        for (int i = 1; i < n; ++i)
        {
            /* code */
            prefixMaximum[i] = max(prefixMaximum[i - 1], height[i]);
        }
        suffixMaximum[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            /* code */
            suffixMaximum[i] = max(suffixMaximum[i + 1], height[i]);
        }
        int trappedWater = 0;
        for (int i = 0; i < n; ++i)
        {
            /* code */
            trappedWater += (min(prefixMaximum[i], suffixMaximum[i]) - height[i]);
        }
        return trappedWater;
    }
};