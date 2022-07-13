
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector <int> bottomView(Node *root) {
		// Your Code Here
		vector<int> ans;
		if (root == NULL)
			return ans;
		queue<pair<Node*, int>> todo;
		map<int, int> mpp;
		todo.push({root, 0});
		while (!todo.empty()) {
			auto it = todo.front();
			todo.pop();
			Node * node = it.first;
			int level = it.second;

			mpp[level] = node->data;
			if (node->left)
				todo.push({node->left, level - 1});
			if (node->right)
				todo.push({node->right, level + 1});
		}
		for (auto it : mpp)
			ans.push_back(it.second);
		return ans;
	}
};
