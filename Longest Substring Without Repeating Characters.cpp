#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = INT_MIN;
        int l=0,r=0;
        unordered_set<int> set;
        if(s.length()==0)
            return 0;
        for (int r = 0; r < s.length(); ++r)
        {
            /* code */
            if(set.find(s[r])!=set.end()){
                while(l<r && set.find(s[r])!=set.end()){
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
    
};
