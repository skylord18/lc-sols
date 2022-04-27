#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int, int> map;
        int sum = 0;
        int maxi =0;
        for (int i = 0; i < A.size(); ++i)
        {
            /* code */
            sum+=A[i];
            if(sum==0)
                maxi = i+1;
            if(map.find(sum)!=map.end()){
                maxi = max(maxi,i-map[sum]);
            }else{
                map[sum]=i;
            }
        }
        return maxi;
    }
};
