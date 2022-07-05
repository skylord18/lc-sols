#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
		vector<vector<int>> mat(m, vector<int>(n, -1));
		ListNode *temp = head;
		vector<int> ll;
		int cnt = 0;
		while (temp) {
			ll.push_back(temp->val);
			temp = temp->next;
			cnt++;
		}
		if (cnt < m * n) {
			for (int i = 0; i < m * n - cnt; i++) {
				ll.push_back(-1);
			}
		}
		int i, k = 0, l = 0;
		int it = 0;
		while (k < m && l < n) {
			/* Print the first row from
			       the remaining rows */
			for (i = l; i < n; ++i, ++it) {
				mat[k][i] = ll[it];
				//cout << mat[k][i] << " ";

			}
			k++;
			/* Print the last column
			 from the remaining columns */
			for (i = k; i < m; ++i, ++it) {
				mat[i][n - 1] = ll[it];
				//cout << mat[i][n - 1] << " ";

			}
			n--;
			/* Print the last row from
			        the remaining rows */
			if (k < m) {
				for (i = n - 1; i >= l; --i, ++it) {
					mat[m - 1][i] = ll[it];
					//cout << mat[m - 1][i] << " ";

				}
				m--;
			}
			/* Print the first column from
			           the remaining columns */
			if (l < n) {
				for (i = m - 1; i >= k; --i, ++it) {
					mat[i][l] = ll[it];
					//cout << mat[i][l] << " ";

				}
				l++;
			}
		}
		return mat;
	}
};

