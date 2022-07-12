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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsw;
        vector<vector<int>> ans;
        if (root == NULL)
            return rsw;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode * node = q.front();
                q.pop();
                if (node->left )
                    q.push(node->left);
                if (node->right )
                    q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        for (int i = 0; i < ans.size(); i++) {
            int n = ans[i].size();
            //rsw.push_back(ans[n-1][i]);
            rsw.push_back(ans[i][n - 1]);
        }
        return rsw;
    }
};