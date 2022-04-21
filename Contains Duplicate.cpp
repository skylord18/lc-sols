#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i)
            {
                /* code */
                s.insert(nums[i]);
            }    
        if(s.size()==nums.size())
            return false;
        else
            return true;
        
    }
};