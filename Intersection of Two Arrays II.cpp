#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int,int> map;
    vector<int> res;
    for(auto num: nums1) map[num]++;
    for(auto num: nums2){
        if(map.find(num)!= map.end() && map[num]!=0){
        res.push_back(num);
        map[num]--; 
        }
    }
    return res;
    }
};