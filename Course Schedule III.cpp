#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		vector<int> indegree(courses.size(), 0);
		int numCourses = courses.size();
		vector<int> adj[numCourses];
		for (auto it : courses) {
			adj[it[1]].push_back(it[0]);
			indegree[it[0]]++;
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}


		vector<int>ans;
		while (!q.empty()) {
			ans.push_back(q.front());
			int node = q.front();
			q.pop();

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0)
					q.push(it);
			}
		}

		return ans.size();

	}
};