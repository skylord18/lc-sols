#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int numberofSubarraysbyKeepingLimitK(vector<int>& nums, int sum) {
        int add = 0;
        int div = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (add + nums[i] <= sum) {
                add += nums[i];
            } else {
                add = nums[i];
                div++;
            }
        }
        return div;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int low = *max_element(nums.begin(), nums.end());
        int high = sum;
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (numberofSubarraysbyKeepingLimitK(nums, mid) <= m) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};