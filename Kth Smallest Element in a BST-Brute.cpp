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
public:
	vector<int> el;
	int kthSmallest(TreeNode* root, int k) {
		preorder(root);
		sort(el.begin(), el.end());
		return el[k - 1];
	}
	void preorder(TreeNode *root) {
		if (!root)
			return;
		el.push_back(root->val);
		preorder(root->left);
		preorder(root->right);
	}
};