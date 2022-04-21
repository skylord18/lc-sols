#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int> ());
        int count=1;
        int temp=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=temp){
                temp=nums[i];
                count++;
            }
            if(count==3){
                return nums[i];
            }
        }
        return nums[0];
    }
};