#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        auto x= upper_bound(letters.begin(),letters.end(),target);
        int ans = x-letters.begin();
        return (ans<n)? letters[ans]:letters[0];
    }
};