#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findSumafterDivision(int mid, vector<int> &nums, int threshold){
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum+= nums[i] / mid;
            if(nums[i]%mid!=0){
                sum+=1;
            } 
        }
        if(sum <=threshold)
            return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low + high)/2;
            if(findSumafterDivision(mid,nums,threshold)== true){
                ans = mid;    
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};