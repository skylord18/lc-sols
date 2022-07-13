#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool getPath(TreeNode *root, vector<int>&ans, int x) {
	if (!root)
		return false;
	ans.push_back(root->val);
	if (root->val == x)
		return true;
	if (getPath(root->left, ans, x) || getPath(root->right, ans, x))
		return true;
	ans.pop_back();
	return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
	vector<int>ans;
	getPath(A, ans, B);
	return ans;
}
