#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nnn;
        if (n == 0) {
            return;
        } else {
            for (int i = 0; i < nums1.size(); ++i)
            {
                /* code */
                if (nums1[i] == 0)
                    continue;
                else
                    nnn.push_back(nums1[i]);
            }
            for (int i = 0; i < nums2.size(); ++i)
            {
                /* code */
                if (nums2[i] == 0)
                    continue;
                else
                    nnn.push_back(nums2[i]);
            }
            sort(nnn.begin(), nnn.end());
            for (int i = 0; i < nnn.size(); ++i)
            {
                /* code */
                nums1[i] = nnn[i];
            }
            sort(nums1.begin(), nums1.end());
        }

    }
};