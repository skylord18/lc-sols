#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int j,int m,int n){
        if(j == m || i==n)
            return 0;
        if(i==n-1 && j == m-1){
            return 1;
        }
        return f(i+1,j,m,n) + f(i,j+1,m,n);
        
    }
public:
    int uniquePaths(int m, int n) {
        int ans = f(0,0,m,n);
        return ans;
    }
};