#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<int> getRow(int r) {
    if(r==0) return {1};
    vector<int> prev,curr;
    prev = {1,1};
    int i,j;
    for(i=2;i<=r;++i){
        curr.push_back(1);
        for(j=1;j<prev.size();++j)
            curr.push_back(prev[j]+prev[j-1]);
        curr.push_back(1);
        prev = curr;
        curr.clear();
    }
    return prev;
}
};