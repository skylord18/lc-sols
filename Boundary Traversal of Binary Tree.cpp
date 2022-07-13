#include<bits/stdc++.h>
using namespace std;
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
	bool isLeaf(Node *root) {
		if (root->left == NULL && root->right == NULL)
			return true;
		return false;
	}
public:
	void addLeftBoundry(Node *root, vector<int>&res) {
		Node *curr = root->left;
		while (curr) {
			if (!isLeaf(curr))
				res.push_back(curr->data);
			if (curr->left)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
public:
	void addLeaf(Node *root, vector<int>&res) {
		if (isLeaf(root)) {
			res.push_back(root->data);
			return;
		}
		if (root->left)
			addLeaf(root->left, res);
		if (root->right)
			addLeaf(root->right, res);
	}
public:
	void addRightBoundry(Node *root, vector<int>&res) {
		Node *curr = root->right;
		vector<int> temp;
		while (curr) {
			if (!isLeaf(curr))
				temp.push_back(curr->data);
			if (curr->right)
				curr = curr->right;
			else
				curr = curr->left;
		}
		for (int i = temp.size() - 1; i >= 0; i--)
			res.push_back(temp[i]);
	}
public:
	vector <int> boundary(Node *root) {
		vector<int> res;
		if (!root)
			return res;
		if (!isLeaf(root))
			res.push_back(root->data);
		addLeftBoundry(root, res);
		addLeaf(root, res);
		addRightBoundry(root, res);
		return res;

	}
};

