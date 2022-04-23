#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size; ++i)
        {
            /* code */
            for (int j = 0; j < i; ++j)
            {
                /* code */
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i = 0; i < size; ++i)
        {
            /* code */
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};