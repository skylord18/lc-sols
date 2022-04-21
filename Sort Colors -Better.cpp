#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
      int zero=0, one=0 ,two=0;
      for (int i = 0; i < nums.size(); ++i)
        {
            /* code */
            if(nums[i]==0)
                zero++;
            else if(nums[i]==1)
                one++;
            else if(nums[i]==2)
                two++;
        }  
        nums.clear();
        for (int i = 0; i < zero; ++i)
        {
            /* code */
            nums.push_back(0);
        }
        for (int i = 0; i < one; ++i)
        {
            /* code */
            nums.push_back(1);
        }
        for (int i = 0; i < two; ++i)
        {
            /* code */
            nums.push_back(2);
        }
        
    }
};