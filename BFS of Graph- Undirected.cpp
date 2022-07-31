#include<bits/stdc++.h>
using namespace std;
class Solution {
	void bfs(vector<int> ans, vector<int> vis, int i, vector<int> adj[]) {
		queue<int> todo;
		todo.push(i);
		vis[i] = true;
		while (!todo.empty()) {
			int node = todo.front();
			ans.push_back(node);
			todo.pop();
			for (auto it : adj[i]) {
				if (!vis[it]) {
					vis[it] = true;
					todo.push(it);
				}
			}
		}
	}
public:
	// Function to return Breadth First Traversal of given graph.
	vector<int> bfsOfGraph(int V, vector<int> adj[]) {
		// Code here
		vector<int> res;
		vector<bool> vis(V, false);
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				vis[i] = true;
				bfs(ans, vis, i, adj);
			}
		}
		return ans;
	}
};