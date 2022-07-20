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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        if (root->val == key)
            return deleteAndMakeConnections(root);
        TreeNode *dummy = root;
        while (dummy != NULL) {
            if (dummy->val > key) {
                if (dummy->left != NULL && dummy->left->val == key) {
                    dummy ->left = deleteAndMakeConnections(dummy->left);
                    break;
                } else {
                    dummy = dummy->left;
                }
            } else {
                if (dummy->right != NULL && dummy->right->val == key) {
                    dummy->right = deleteAndMakeConnections(dummy->right);
                    break;
                } else {
                    dummy = dummy -> right;
                }
            }
        }
        return root;
    }
    TreeNode* deleteAndMakeConnections(TreeNode *root) {
        if (root->left == NULL)
            return root->right;
        else if (root ->right == NULL)
            return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* rightMost = gettheRightMostGuy(root->left);
        rightMost->right = rightChild;
        return root->left;
    }
    TreeNode* gettheRightMostGuy(TreeNode *root) {
        while (root->right != NULL)
            root = root->right;
        return root;
    }
};