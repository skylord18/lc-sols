#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int i = 0, j = 0;
        long long n1 = 0, n2 = 0;
        while (i < num1.length()) {
            n1 = n1 * 10 + (num1[i] - '0');
            i++;
        }
        while (j < num2.length()) {
            n2 = n2 * 10 + (num2[i] - '0');
            j++;
        }
        long long ans = n1 * n2;
        string s;
        while (ans) {
            s += (ans) % 10;
            ans / 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};