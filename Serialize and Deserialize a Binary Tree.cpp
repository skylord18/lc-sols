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
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root)
			return "";
		string s = "";
		queue<TreeNode*> todo;
		todo.push(root);
		while (!todo.empty()) {
			TreeNode *cur = todo.front();
			todo.pop();
			if (cur == NULL)
				s.append("#,");
			else {
				s.append(to_string(cur->val));
				s.append(",");
			}


			if (cur != NULL) {
				todo.push(cur->left);
				todo.push(cur->right);
			}
		}
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.size() == 0)
			return NULL;
		stringstream s(data);
		string str;
		getline(s, str, ',');
		TreeNode *root = new TreeNode(stoi(str));
		queue<TreeNode*> todo;
		todo.push(root);

		while (!todo.empty()) {
			TreeNode* node = todo.front();
			todo.pop();

			getline(s, str, ',');
			if (str == "#") {
				node->left = NULL;
			} else {
				node->left =  new TreeNode(stoi(str));
				todo.push(node->left);
			}

			getline(s, str, ',');
			if (str == "#") {
				node->right = NULL;
			} else {
				node->right =  new TreeNode(stoi(str));
				todo.push(node->right);
			}
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;