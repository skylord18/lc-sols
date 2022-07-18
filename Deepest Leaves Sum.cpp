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
	int deepestLeavesSum(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)
			return 0;
		queue<TreeNode*> todo;
		todo.push(root);
		while (!todo.empty()) {
			vector<int> col;
			int s = todo.size();
			for (int i = 0; i < s; ++i) {
				TreeNode *node = todo.front();
				todo.pop();
				col.push_back(node->val);
				if (node->left)
					todo.push(node->left);
				if (node->right)
					todo.push(node->right);
			}
			ans.push_back(col);
		}
		vector<int> lst = ans[ans.size() - 1];
		int ret = accumulate(lst.begin(), lst.end(), 0);
		return ret;
	}

};