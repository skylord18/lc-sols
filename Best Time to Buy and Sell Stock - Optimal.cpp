#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPri = INT_MAX, maxProfit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            /* code */
            minPri= min(prices[i],minPri);
            maxProfit = max(maxProfit,prices[i]-minPri);
        }
        return maxProfit;
    }
};