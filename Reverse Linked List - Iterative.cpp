#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int maxProfit = 0,profit;
        for (int i = 0; i < size; ++i)
        {
            /* code */
            for (int  j=i+1 ; j < size; ++j)
            {
                /* code */
                if(prices[j]>prices[i]){
                    profit = abs(prices[j]-prices[i]);
                }
                if(profit>maxProfit)
                    maxProfit = profit;
            }
        }
        return maxProfit;
    }
};