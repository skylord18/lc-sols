
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        if(len%2==1)
            return false;
        
        for (int i = 0; i < len; ++i)
        {
            /* code */
            if(s[i]=='(' || s[i] == '[' || s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty()==true){
                    return false;
                }else{
                    char top = st.top();
                    if((s[i]==')' && top == '(') || (s[i]==']' && top == '[') || (s[i]=='}' && top == '{'))
                        st.pop();
                    else if (s[i]==')' || s[i]==']' || s[i]=='}'){
                        return false;
                        
                    }
                }
            }
            
        }
        if(st.empty()==true){
            return true;
        }
        return false;
    }
};