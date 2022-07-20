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
	long long int mini = INT_MIN, maxi = INT_MAX;

public:
	bool isValidBST(TreeNode* root) {
		return validateBST(root, mini, maxi);
	}
	bool validateBST(TreeNode *root, long long int mini, long long int maxi) {
		if (!root)
			return true;
		if (root->val >= maxi || root->val < mini)
			return false;
		return validateBST(root->left, mini, (long long int)root->val - 1) && validateBST(root->right, (long long int)root->val + 1, maxi);
	}
};