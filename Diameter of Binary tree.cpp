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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height (root);
        return dia;
    }
public:
    int height(TreeNode *root) {
        if (root == NULL)
            return 0;
        int lh = height(root->left);
        int rh  = height(root->right);
        dia = max(dia, lh + rh);
        return 1 + max(lh, rh);
    }
};