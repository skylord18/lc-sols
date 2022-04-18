#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isPerfectSquare(int num) {
        long long int l = 0 ;
        long long int r = num;
        while(l<=r)
        {
            long long int mid = l + (r-l)/2;
            if(mid * mid == num)
                return true;
            else if(mid * mid > num)
            {
                r = mid -1;
            }
            else l = mid + 1;
        }
        return false;
    }
};