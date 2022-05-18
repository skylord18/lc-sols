#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (int i = 0; i < operations.size(); ++i)
        {
            /* code */
            if (operations[i] == "++X" || operations[i] == "X++")
                x++;
            else
                x--;
        }
        return x;

    }
};