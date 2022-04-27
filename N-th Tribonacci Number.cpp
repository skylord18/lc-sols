#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int  nthTribo(int n,vector<int>&dp){
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return  1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = nthTribo(n-1,dp) + nthTribo(n-2,dp)+nthTribo(n-3,dp);
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        int ans = nthTribo(n,dp);
        return ans;
    }
};