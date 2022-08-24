#include<bits/stdc++.h>
using namespace std;
class Solution {
  int f(int i, int j, string s1, string s2) {
    if (j < 0)return 1;
    if (i < 0)return 0;
    if (s1[i] == s2[j])return f(i - 1, j - 1, s1, s2) + f(i - 1, j, s1, s2);
    else return f(i - 1, j , s1, s2);
  }
public:
  int numDistinct(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    return f(n - 1, m - 1, s1, s2);
  }
};