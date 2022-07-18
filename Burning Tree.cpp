#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
	Node* markParents(map<Node*, Node*> &parents, Node *root, int target) {
		queue<Node*> todo;
		todo.push(root);
		Node * res;
		while (!todo.empty()) {
			Node *curr = todo.front();
			if (curr->val == target)res = curr;
			todo.pop();
			if (curr->left) {
				parents[curr->left] = curr;
				todo.push(curr->left);
			}
			if (curr->right) {
				parents[curr->right] = curr;
				todo.push(curr->right);
			}
		}
		return res;
	}
public:
	int minTime(Node* root, int target) {

		map<Node*, Node*> parents;
		Node *t = markParents(parents, root, target);

		map<Node*, bool> burnt;
		queue<Node*> todo;
		todo.push(t);
		burnt[t] = true;
		int curr_time = 0;

		while (!todo.empty()) {
			int size = todo.size();

			int fl = 0;
			for (int i = 0; i < size; i++) {
				Node *currNode = todo.front();
				todo.pop();
				if (currNode->left && !burnt[currNode->left]) {
					fl = 1;
					burnt[currNode->left] = true;
					todo.push(currNode->left);
				}
				if (currNode->right && !burnt[currNode->right]) {
					fl = 1;
					burnt[currNode->right] = true;
					todo.push(currNode->right);
				}
				if (parents[currNode] && !burnt[parents[currNode]]) {
					fl = 1;
					burnt[parents[currNode]] = true;
					todo.push(parents[currNode]);
				}
			}
			if (fl == 1)
				curr_time++;
		}
		return curr_time;
	}
};