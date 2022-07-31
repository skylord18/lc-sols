#include<bits/stdc++.h>
using namespace std;
int f(int n, vector<int>&heights, vector<int>&dp) {
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int l = f(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int r = 2147483647;
    if (n > 1)
        r = f(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    return dp[n] = min(l, r);
}


int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n + 1, -1);
    return f(n - 1, heights, dp);
}
