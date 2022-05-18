#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> res(k);
        priority_queue<vector<int>> maxHeap;

        for (auto& it : points)
        {
            int x = it[0];
            int y = it[1];


            int z = x * x + y * y;


            maxHeap.push({z, x, y});

            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        for (int i = 0; i < k; i++)
        {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            res[i] = {top[1], top[2]};
        }

        return res;
    }
};