#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int count=0, el = 0;
     for (int i = 0; i < nums.size(); ++i)
     {
         /* code */
        if(count==0){
            el = nums[i];
        }
        if(nums[i]==el)
            count++;
        else
            count--;
     }
     return el;
    }
};