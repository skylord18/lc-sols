#include<bits/stdc++.h>
using namespace std;
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
	// Write your code here.
	vector<vector<int>> ans;
	vector<int> inorder, preorder, postorder;
	if (root == NULL) {
		ans = {inorder, preorder, postorder};
		return ans;
	}
	stack<pair<BinaryTreeNode*, int>>st;
	st.push({root, 1});
	while (!st.empty()) {
		auto it = st.top();
		st.pop();
		if (it.second == 1) {
			preorder.push_back(it.first->data);
			it.second = it.second + 1;
			st.push({it.first, it.second});
			if (it->left) {
				st.push({it->left, 1});
			}
		}
		if (it.second == 2) {
			inorder.push_back(it.first->data);
			it.second = it.second + 1;
			st.push({it.first, it.second});
			if (it->right) {
				st.push({it->right, 1});
			}
		}
		if (it.second == 3) {
			postorder.push_back(it.first->data);
		}
	}
	ans.push_back(inorder);
	ans.push_back(preorder);
	ans.push_back(postorder);
}