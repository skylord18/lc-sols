#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &stack, int temp) {
	if (stack.empty() || stack.top() < temp) {
		stack.push(temp);
		return;
	}
	int tempo = stack.top();
	insert(stack, tempo);
	stack.push(temp);

}
void sortStack(stack<int> &stack) {
	// Write your code here
	if (stack.size() == 1)
		return ;
	int temp = stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack, temp);
	return;
}
