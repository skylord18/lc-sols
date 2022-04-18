#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void func(int index, int sum, vector<vector<int>> &ans,vector<int> &ds , vector<int> &candidates ,int n , int target){
        if(sum==target)
            ans.push_back(ds);
        if(index == n)
            return;
        if(sum+ candidates[index]<=target){
           sum+= candidates[index];
            ds.push_back(candidates[index]);
            func(index,sum, ans, ds, candidates, n , target); 
            sum-=candidates[index];
            ds.pop_back();
        }
        
        
        func(index+1, sum,ans,ds ,candidates,n, target);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        func(0,0,ans,ds,candidates,n,target);
         ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};