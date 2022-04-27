#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fibo(vector<int> & dp, int n){
        if(n<2)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = fibo(dp,n-1)+fibo(dp,n-2); 
    }
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = fibo(dp,n);
        return ans;
    }
};