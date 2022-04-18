#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int index, int target, vector<vector<int>>&ans, vector<int>&ds, vector<int>&arr){
        if(target == 0){
            ans.push_back(ds);
            return;
        }          
        for (int i = index; i < arr.size(); ++i)
          {
              /* code */
            if (i>index && arr[i]==arr[i-1])
            {
                /* code */
                continue;
            }
            if (arr[i]>target)
            {
                /* code */
                break;
                
            }
            ds.push_back(arr[i]);
            func(i+1,target-arr[i], ans, ds, arr);
            ds.pop_back();        
          }  
    }
        
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        func(0,target,ans,ds,candidates);
        return ans;
    }
};