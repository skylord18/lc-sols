#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		int num = 0;
		int n = s.length();
		map<char, int> mpp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
		num = mpp[s[n - 1]];
		for (int i = n - 2; n >= 0; n--) {
			if (mpp[s[i]] > mpp[s[i + 1]])
				num -= mpp[s[i]];
			else
				num += mpp[s[i]];
		}
		return num;
	}
};
