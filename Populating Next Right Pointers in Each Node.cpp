#include<bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
			return NULL;
		queue<Node*> todo;
		todo.push(root);
		while (!todo.empty()) {
			int sz = todo.size();
			vector<Node*> col;
			for (int i = 0; i < sz; i++) {
				Node* temp = todo.front();
				todo.pop();
				if (temp->left)
					todo.push(temp->left);
				if (temp->right)
					todo.push(temp->right);
				col.push_back(temp);
			}
			for (int i = 0; i < col.size() - 1; i++) {
				col[i]->next = col[i + 1];
			}
			col.erase(col.begin(), col.end());
		}
		return root;
	}
};