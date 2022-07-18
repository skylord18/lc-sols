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
	int widthOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		int ans = 0;
		queue<pair<TreeNode*, int>> todo;
		todo.push({root, 0});
		while (!todo.empty()) {
			int first, last, size  = todo.size(), minn = todo.front().second;
			for (int i = 0; i < size; i++) {
				TreeNode *node = todo.front().first;
				long long prev = todo.front().second - minn;
				todo.pop();
				if (i == 0)
					first = prev;
				if (i == size - 1)
					last = prev;
				if (node->left)
					todo.push({node->left, prev * 2 + 1});
				if (node->right)
					todo.push({node->right, prev * 2 + 2});
			}
			ans = max(ans, last - first + 1);
		}
		return ans;
	}
};