#include<bits/stdc++.h>
using namespace std;
class Solution {
    //Return an Element at a Particluar Row & Column Number
public:
    int fact(int n){
        int ans = 1;
        while(n--){
            ans = ans*n;
        }
        return ans;
    }
public:
    int particluarElementinPascalTriangle(int r,int c){
        int ans;
        int top = fact(r-1);
        int bot = fact(c-r)*fact(r);
        ans= top/bot;
        return ans;
    }
//Return a Particular Row
public:
    vector<int> particularRowinPascalTriangle(int n){
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            ans[i] = particluarElementinPascalTriangle(n,i);
        }
        return ans; 
    }
// The Obvios Question Given on Leetcode
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            r[i].resize(i+1);
            r[i][0] = r[i][i] =1;
            for (int j = 1; j < i; ++j)
            {
                /* code */
                r[i][j] = r[i-1][j-1]+r[i-1][j];
            }
        }
        return r;
    }
};