#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int getSum(int n ) {
		int r = 0;
		while (n) {
			int d = n % 10;
			n /= 10;
			r += (d * d);
		}
		return r;
	}
public:
	bool isHappy(int n) {
		int slow = n;
		int fast = getSum(n);
		while (fast != 1 && slow != fast) {
			slow = getSum(slow);
			fast = getSum(getSum(fast));
		}
		if (fast == 1)
			return true;
		return false;
	}
};