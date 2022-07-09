#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isDigit(char ch) {
		if (ch >= '0' && ch <= '9')
			return true;
		return false;
	}
public:
	int myAtoi(string s) {
		int len = s.length();
		int i = 0, result = 0;
		bool isNeg = false;
		while (i < len && s[i] == ' ')
			++i;
		if (s[i] == '-') {
			isNeg = true;
			++i;
		} else if (s[i] == '+')
			++i;
		while (i < len && isDigit(s[i])) {
			int dig = s[i] - '0';
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && dig > 7)) {
				if (isNeg == true)
					return INT_MIN;
				else
					return INT_MAX;
			}
			result = result * 10 + dig;
			++i;
		}
		if (isNeg == true)
			result = result * (-1);
		return result;
	}
};