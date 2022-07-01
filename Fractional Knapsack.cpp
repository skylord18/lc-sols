#include<bits/stdc++.h>
using namespace std;
struct Item {
	int value ;
	int weight ;
};


class Solution
{
public:

	bool static comp (Item a, Item b) {
		double r1 = (double)a.value / (double)a.weight;
		double r2 = (double)b.value / (double)b.weight;
		if (r1 > r2)
			return true;
		return false;
	}
	//Function to get the maximum total value in the knapsack.
public:
	double fractionalKnapsack(int W, Item arr[], int n)
	{
		// Your code here
		sort(arr, arr + n, comp);

		int currWeight = 0;
		double totalValue = 0;

		for (int i = 0; i < n; i++) {
			if (currWeight + arr[i].weight <= W) {
				currWeight += (arr[i].weight);
				totalValue += (arr[i].value);
			} else {
				int remainingWt = W - currWeight;
				totalValue += ((double)arr[i].value / (double)arr[i].weight) * (double)remainingWt;
			}
		}
		return totalValue;
	}
};