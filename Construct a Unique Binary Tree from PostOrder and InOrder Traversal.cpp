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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		map<int, int> inMap;
		for (int i = 0; i < postorder.size(); i++)
			inMap[inorder[i]] = i;
		return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
	}
	TreeNode *buildTreePostIn(vector<int>&inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, map<int, int> inMap) {
		if (inStart > inEnd || postStart > postEnd)
			return NULL;
		TreeNode *root = new TreeNode(postorder[postEnd]);
		int inRoot = inMap[postorder[postEnd]];
		int numsLeft = inRoot - inStart;

		root->left = buildTreePostIn(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
		root->right = buildTreePostIn(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);

		return root;
	}
};