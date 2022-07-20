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
	bool isValidBST(TreeNode* root) {
		vector<int> inorder;
		TreeNode *cur = root;
		while (cur) {
			if (cur->left == NULL) {
				inorder.push_back(cur->val);
				cur = cur->right;
			} else {
				TreeNode *prev = cur->left;
				while (prev->right && prev->right != cur)
					prev = prev->right;
				if (prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				} else {
					prev->right = NULL;
					inorder.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		bool isSorted = true;
		for (int i = 1; i < inorder.size(); i++) {
			if (!inorder[i - 1] < inorder[i]) {
				isSorted = false;
				break;
			}
		}
		return isSorted;
	}
};