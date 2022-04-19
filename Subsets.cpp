#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int index, vector<vector<int>>&ans,vector<int>&ds, vector<int>&nums, int n){
        if(index == n){
            if(count(ans.begin(),ans.end(),ds)>0){
                return;
            }else{
                ans.push_back(ds);
                return;
            }
        }
        ds.push_back(nums[index]);
        func(index+1,ans,ds,nums,n);
        ds.pop_back();
        func(index+1,ans,ds, nums,n);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int>ds;
       int n = nums.size();
       func(0,ans,ds,nums,n);
       return ans;
    }
};