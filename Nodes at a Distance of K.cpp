#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	void markParents(map<TreeNode*, TreeNode*> &mpp, TreeNode *root, TreeNode *target) {
		queue<TreeNode *> todo;
		todo.push(root);
		while (!todo.empty()) {
			TreeNode * curr = todo.front();
			todo.pop();
			if (curr->left) {
				mpp[curr->left] = curr;
				todo.push(curr->left);
			}
			if (curr->right) {
				mpp[curr->right] = curr;
				todo.push(curr->right);
			}
		}
	}
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		map<TreeNode*, TreeNode*> mpp;
		markParents(mpp, root, target);

		map<TreeNode*, bool> vis;
		queue<TreeNode*> todo;
		todo.push(target);
		vis[target] = true;
		int curr_level = 0;
		while (!todo.empty()) {
			int size = todo.size();
			if (curr_level++ == k)
				break;
			for (int i = 0; i < size; i++) {
				TreeNode *curr = todo.front();
				todo.pop();
				if (curr->left && !vis[curr->left]) {
					vis[curr->left] = true;
					todo.push(curr->left);
				}
				if (curr->right && !vis[curr->right]) {
					vis[curr->right] = true;
					todo.push(curr->right);
				}
				if (mpp[curr] && !vis[mpp[curr]]) {
					todo.push(mpp[curr]);
					vis[mpp[curr]] = true;
				}
			}
		}
		vector<int> ans;
		while (!todo.empty()) {
			TreeNode * vall = todo.front();
			todo.pop();
			ans.push_back(vall->val);
		}
	}
};