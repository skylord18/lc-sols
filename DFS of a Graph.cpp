#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void dfs(int node, vector<int>adj[], vector<int> &vis, vector<int>&res) {
		vis[node] = true;
		res.push_back(node);
		for (auto it : adj[node]) {
			if (!vis[it]) {
				dfs(it, adj, vis, res);
			}
		}

	}
public:
	// Function to return a list containing the DFS traversal of the graph.
	vector<int> dfsOfGraph(int V, vector<int> adj[]) {
		// Code here
		vector<int> res;
		vector<int> vis(V, false);
		dfs(0, adj, vis, res);
		return res;
	}
};