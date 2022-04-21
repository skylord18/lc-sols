#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            /* code */
            for (int j = 0; j < n; ++j)
            {
                /* code */
                if(grid[i][j]<0)
                    cnt++;
            }
        }
        return cnt;
        
    }
};