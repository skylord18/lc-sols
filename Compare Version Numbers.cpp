#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int v1 = 0, v2 = 0, i = 0, j = 0, n1 = version1.length(), n2 = version2.length();

		for (; i < n1 || j < n2;) {
			while (i < n1 && version1[i] != '.') {
				v1 = v1 * 10 + (version1[i] - '0');
				i++;
			}
			while (j < n2 && version2[j] != '.') {
				v2 = v2 * 10 + (version2[j] - '0');
				j++;
			}
			if (v1 > v2)
				return 1;
			else if (v1 < v2)
				return -1;
			v1  = 0, v2 = 0;
			i++;
			j++;
		}
		return 0;
	}
};