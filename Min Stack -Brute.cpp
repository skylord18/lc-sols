#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
	stack<pair<int, int>> st;
	int mini;
	MinStack() {

	}

	void push(int x) {
		int mini;
		if (st.empty()) {
			mini = x;
		} else {
			mini = min(st.top().second, x);
		}
		st.push({x, mini});
	}

	void pop() {
		st.pop();
	}

	int top() {
		return st.top().first;
	}

	int getMin() {
		return st.top().second;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */