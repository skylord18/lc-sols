#include<bits/stdc++.h>
using namespace std;
class Solution {
	bool isPowerOfTwo(int x)
	{
		return x && (!(x & (x - 1)));
	}

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
public:
	bool reorderedPowerOf2(int n) {
		if (n == 10)return false;

		string num = to_string(n);

		sort(num.begin(), num.end());
		do {
			long long int i, c = -1;
			for (int i = 0; i < num.length(); i++) {
				if (num[i] != '0') { // check the first index where 0 doesnt occur
					c = i;
					break;
				}
			}
			// for (i = c; i < num.length(); i++) {
			// 	cout << s[i]; // print the rest of the string
			// }
			cout << num << endl;
			if (isPowerOfTwo(myAtoi(num)))return true;
		} while (next_permutation(num.begin(), num.end()));
		return false;
	}
};