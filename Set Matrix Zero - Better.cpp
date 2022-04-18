#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row[m];
        int cols[n];
        fill(row,row+m,1);
        fill(cols,cols+n,1);
        for (int i = 0; i < m; ++i)
        {
            /* code */
            for (int j = 0; j < n; ++j)
            {
                /* code */
                if(matrix[i][j]==0){
                    row[i] = 0;
                    cols[j] = 0;
                }
                
            }
        }
       
       
        for (int i = 0; i < m; ++i)
        {
            /* code */
            for (int j = 0; j < n; ++j)
            {
                /* code */
                if(row[i]==0 || cols[j]==0){
                    matrix[i][j]=0;
                }
                
            }
        } 
    }
};