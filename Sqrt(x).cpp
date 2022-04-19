#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 ){
            return 0;
        }else if(x==1){
            return 1;
        }else{
            long long int low = 1, high = x/2;
            int ans = 0;
            while(low<=high){
                long long int mid = (low+high)/2;
                if(mid*mid<=x){
                    ans = mid;
                    low = mid+1; 
                }else{
                    high = mid-1;
                }
              }
            return ans;
        }
        return 0;
    }
};