#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int index,int sum,vector<int>&ans,vector<int>arr,int N){
        if(index==N){
            ans.push_back(sum);
            return;
        }
        sum+=arr[index];
        func(index+1,sum,ans,arr,N);
        sum-=arr[index];
        func(index+1,sum,ans,arr,N);
        
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        func(0,0,ans,arr,N);
        return ans;
    }
};