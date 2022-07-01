#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		int fact = 1;
		vector<int> numbers;
		for (int i = 1; i < n; ++i)
		{
			/* code */
			fact = fact * i;
			numbers.push_back(i);
		}
		numbers.push_back(n);
		string s = "";
		k = k - 1;
		while (true) {
			s += numbers[k / fact];
			numbers.erase(numbers.begin() + k / fact);
			if (numbers.size() == 0)
				break;
			k = k % fact;
			fact = fact / numbers.size();
		}
		return s;
	}
};