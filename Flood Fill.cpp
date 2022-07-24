#include<bits/stdc++.h>
using namespace std;
class Solution {
    void floodFillHelper(vector<vector<int>> &image, int i, int j , int oldColor, int newColor, int n, int m) {
        if (i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor)
            return;
        image[i][j] = newColor;
        floodFillHelper(image, i + 1, j, oldColor, newColor, n, m);
        floodFillHelper(image, i - 1, j, oldColor, newColor, n, m);
        floodFillHelper(image, i, j + 1, oldColor, newColor, n, m);
        floodFillHelper(image, i, j - 1, oldColor, newColor, n, m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        int n = image.size(), m = image[0].size();
        if (oldColor == color)
            return image;
        floodFillHelper(image, sr, sc, oldColor, color, n, m);
        return image;
    }
};