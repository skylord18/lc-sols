#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int freq = floor(nums.size()/2);
     vector<int> vis;
     
     for (int i = 0; i < nums.size(); ++i)
        {
            if(count(vis.begin(), vis.end(),nums[i])==0){
                if(count(nums.begin(), nums.end(), nums[i])<=freq){
                    vis.push_back(nums[i]);
                    continue;
                }else
                    return nums[i];
            }
        }   
        return 0;
    }
};