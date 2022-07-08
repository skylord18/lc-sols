vector<int> Solution::prevSmaller(vector<int> &A) {
	stack<int> st;
	vector<int>nse(A.size(), -1);
	for (int i = 0; i < A.size(); i++) {
		while (!st.empty() && st.top() >= A[i]) {
			st.pop();
		}
		if (st.empty())
			nse[i] = -1;
		else
			nse[i] = st.top();
		st.push(A[i]);
	}
	return nse;

}
