#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        auto lb=lower_bound(nums.begin(),nums.end(),target);
        auto ub=upper_bound(nums.begin(),nums.end(),target);
        if(lb!=nums.end() && *lb==target){ 
            ans.push_back((lb-nums.begin()));
            ans.push_back((ub-nums.begin())-1); 
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
