#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int index, vector<char>&s){
        
        swap(s[index],s[s.size()-index-1]);
    }
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size()/2; ++i)
        {
            /* code */
            func(i,s);
        }
        
    }
};