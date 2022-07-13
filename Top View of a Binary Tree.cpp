
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
class Solution
{
public:
	//Function to return a list of nodes visible from the top view
	//from left to right in Binary Tree.
	vector<int> topView(Node *root) {
		//Your code here
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
			if (mpp.find(level) == mpp.end())
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
