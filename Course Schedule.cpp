#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfsCycle(int node, vector<int>&vis, vector<int>&pathVis, vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (dfsCycle(it, vis, pathVis, adj) == true)
                    return true;
            } else if (pathVis[it] == 1) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0), pathVis(numCourses, 0);
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfsCycle(i, vis, pathVis, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};