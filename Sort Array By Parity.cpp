#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
     int low = 0,mid= 0, high = nums.size()-1;
     while(low<high){
        if(nums[mid]%2==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }else if(nums[mid]%2!=0){
            swap(nums[high],nums[mid]);
            high--;
        }
        
     }   
     return nums;
    }
};