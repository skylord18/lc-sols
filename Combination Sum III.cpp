#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int index, int n,int k, vector<vector<int>> & ans, vector<int>&ds){
        if(n<0)
            return;
        if(n==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }else{
            for (int i = index; i < 10; ++i)
            {
                if(count(ds.begin(),ds.end(),i)){
                    break;
                }else{
                ds.push_back(i);
                func(index+1,n-i,k,ans,ds);
                ds.pop_back();   
                }

            }
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        func(1,n,k,ans,ds);
        return ans;
    }
};