#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(int index, vector<vector<int>>&ans, vector<int>&nums){
        if(index == nums.size()){
           if (count(ans.begin(), ans.end(), nums)>0)
                return;
            else{
                ans.push_back(nums);
                return;
            }   
        }
        for (int i = index; i < nums.size(); ++i)
        {
                swap(nums[index],nums[i]);
                func(index+1,ans,nums);
                swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        func(0,ans,nums);
         ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};