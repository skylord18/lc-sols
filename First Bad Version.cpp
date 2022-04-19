#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0, high =n;
        int ans = high;
        while(low<=high){
            int mid = low +( high - low)/2;
            if(isBadVersion(mid)==true){
                 ans= mid;
                high = mid-1;
            }else{
                 low = mid+1;
            }      
        }
        return ans;
    }
};