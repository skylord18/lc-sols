#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
 int start =0;
 int ans=0;
 int end =nums.size()-1;
 if(target>nums[nums.size()-1])
 {
     return nums.size();
 }
 else{
      while(start<=end)
 {
     int mid=(start+end)/2;
     if(nums[mid]==target)
     {
         ans=mid;
         break;
     }
     else if(nums[mid]<target)
     {
         if(nums[mid]<target && target<nums[mid+1])
         {
             ans=mid+1;
             break;
         }
         else{
             start=mid+1;
         }
     }
     else{
         if(nums[mid]<target && target<nums[mid+1])
         {
             ans=mid+1;
             break;
         }
         else{
             end=mid-1;
         }
     }
     
 }
 return ans;
     
 }
}
};