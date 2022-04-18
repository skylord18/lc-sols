#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       vector<int> v;
       while(x>0){
        int las = x%10;
        v.push_back(las);
        x/=10;
       }
       int size = v.size();
       bool isPalindrome = true;
       if(x<0)
        isPalindrome = false;
    
       for (int i = 0; i < v.size(); ++i)
       {
           /* code */
        if(v[i]==v[size-i-1]){
            continue;
        }else{
            isPalindrome = false;
            break;
            
        }
       }
       return isPalindrome;
    }
};