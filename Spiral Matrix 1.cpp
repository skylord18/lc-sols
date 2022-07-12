#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();

        int k = 0, l = 0, i = 0;
        while (k < m && l < n) {
            /* Print the first row from
                   the remaining rows */
            for (i = l; i < n; ++i) {
                ans.push_back(matrix[k][i]);
                //cout << mat[k][i] << " ";

            }
            k++;
            /* Print the last column
             from the remaining columns */
            for (i = k; i < m; ++i) {
                ans.push_back(matrix[i][n - 1]);
                //cout << mat[i][n - 1] << " ";

            }
            n--;
            /* Print the last row from
                    the remaining rows */
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    ans.push_back(matrix[m - 1][i]);
                    //cout << mat[m - 1][i] << " ";

                }
                m--;
            }
            /* Print the first column from
                       the remaining columns */
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    ans.push_back(matrix[i][l]);
                    //cout << mat[i][l] << " ";

                }
                l++;
            }
        }
        return ans;
    }
};