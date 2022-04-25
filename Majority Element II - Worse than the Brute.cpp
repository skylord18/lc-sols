#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}
public:
    vector<int> majorityElement(vector<int>& nums) {
     vector<int>ans;
     int freq = floor(nums.size()/3);
     vector<int> rej;
     for (int i = 0; i < nums.size(); ++i)
        {
            /* code */
            if(count(ans.begin(), ans.end(), nums[i])>1)
                continue;
            if(count(rej.begin(), rej.end(),nums[i])>0){
                continue;
            }
            if(count(nums.begin(), nums.end(),nums[i])<freq)
                rej.push_back(nums[i]);
            if(count(nums.begin(), nums.end(),nums[i])>freq)
                ans.push_back(nums[i]);
        }   
        remove(ans);
        return ans;
    }
};