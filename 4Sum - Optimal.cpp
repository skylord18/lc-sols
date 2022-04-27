#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n= nums.size();
        for (int i = 0; i < n; ++i)
         {
            int t3 = target - nums[i]; 
             /* code */
            for (int j = i+1; j < n; ++j)
            {
                /* code */
                int t2 = t3-nums[j];
                int front = j+1, rear = n-1;
                while(front<rear){
                    if(nums[front]+ nums[rear]>t2)
                    rear--;
                else if(nums[front]+nums[rear]<t2)
                    front++;
                else{
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[front]);
                    v.push_back(nums[rear]);
                    ans.push_back(v);
                    while(front<n && nums[front]== v[2])
                        front++;
                    while(front<n && nums[rear]== v[3])
                        rear--;
                }
            }
              while(j<n && nums[j+1]== nums[j])
              j++;  
            }
            while(i<n && nums[i+1]== nums[i])
                i++;
         } 
       return ans;
         
    }
};