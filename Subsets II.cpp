#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int index, vector<vector<int>>&ans,vector<int>&ds,vector<int>&nums){
        if(index == nums.size()){
            if(count(ans.begin(), ans.end(),ds)>0){
                return;
            }else{
                ans.push_back(ds);
                return;
            }
        }
        ds.push_back(nums[index]);
        func(index+1,ans,ds,nums);
        ds.pop_back();
        func(index+1,ans,ds,nums);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        func(0,ans,ds,nums);
        return ans;
    }
};