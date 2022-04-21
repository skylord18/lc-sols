#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN, currSum= 0;
        for (int i = 0; i < nums.size(); ++i)
        {   
            /* code */
            currSum +=nums[i];
            maxSum = max(maxSum,currSum);
            if(currSum<0)
                currSum = 0;

        }
        return maxSum;
    }
};