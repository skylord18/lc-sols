class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ds;
        bool combinationFound = false;
        
        for(int i =0;i<len;i++){
            for(int j = 0;j<len;j++){
                if(i==j)
                    continue;
                if(nums[i]+nums[j]==target && combinationFound ==false){
                    combinationFound = true;
                    ds.push_back(i);
                    ds.push_back(j);
                    break;
                    
                }
            }
        }
        return ds;
    }
};