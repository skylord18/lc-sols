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
	int countNodes(TreeNode* root) {
		if (!root )return 0;
		int lh = getLeftHeight(root);
		int rh = getRightHeight(root);
		if (lh == rh)
			return pow(2, lh) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
	int getLeftHeight(TreeNode *root) {
		int ht = 0;
		while (root) {
			cnt++;
			root = root->left;
		}
		return ht;
	}
	int getRightHeight(TreeNode *root) {
		int ht = 0;
		while (root) {
			cnt++;
			root = root->right;
		}
		return ht;
	}
};