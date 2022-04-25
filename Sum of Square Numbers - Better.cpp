#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
     for (long i = 0; i*i <= c; ++i)
        {
            double p = sqrt(c-(i*i));
            if(p==(int) p )
                return true;
        }   
        return false;
    }
};