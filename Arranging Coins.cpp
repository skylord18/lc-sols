#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canIArrangeMidCoins(long long int  n ,long long int  mid){     
        long long int midSum = (mid*(mid+1))/2;
        if(midSum<=n)
            return true;
        return false;
    }
public:
    int arrangeCoins(int n) {
        long long int  low = 0, high = n/2+1;
        long long int  ans = low;
        while(low<=high){
            long long int  mid = low +(high -low)/2;
            if(canIArrangeMidCoins(n,mid)==true){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }       
        }
        return ans;
    }
};