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
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int i = 0;
		return generateBST(preorder, i , INT_MAX);
	}
	TreeNode *generateBST(vector<int>&preorder , int i , int ub) {
		if (i == preorder.size() || A[i] > ub)
			return;
		TreeNode *node = new TreeNode(preorder[i++]);
		node->left = generateBST(preorder, i, node->val);
		node->right = generateBST(preorder, i, ub);
		return node;
	}
};