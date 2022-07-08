#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
	stack<pair<int, int>> st;
	//{index,price}
	int index ;

	StockSpanner() {
		index = -1;
	}

	int next(int price) {
		index++;
		while (!st.empty() && st.top().second <= price)
			st.pop();
		if (st.empty()) {
			st.push({index, price});
			return index + 1;
		}
		int r = st.top().first;
		st.push({index, price});
		return index - r;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */