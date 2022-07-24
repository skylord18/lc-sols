#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	TreeNode * prev, *first, *mid, *last;
public:
	void inorder(TreeNode *root) {
		if (!root)
			return;
		inorder(root->left);
		if (prev != NULL && (root->val < prev->val)) {
			if (first == NULL) {
				first = prev;
				mid = root;
			} else
				last = root;
		}
		prev = root;
		inorder(root->right);
	}
	void recoverTree(TreeNode* root) {
		if (!root)
			return;
		prev = first = mid = last = NULL;
		prev = new TreeNode(INT_MIN);
		inorder(root);
		if (first && last)
			swap(first->val, last->val);
		else if (first && mid)
			swap(first->val, mid->val);
	}
};