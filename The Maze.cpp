#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        int n = maze.size();
        int m = maze[0].size();

        bool vis[n][m];
        for (int i  = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                vis[i][j] = false;
        }

        queue<pair<int, int>> todo;
        todo.push({start[0], start[1]});
        while (!todo.empty()) {
            int x = todo.front().first;
            int y = todo.front().second;
            todo.pop();

            if (x == destination[0] && y == destination[1])
                return true;

            const int dx[4] = { -1, 1, 0, 0};
            const int dy[4] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int newX = x;
                int newY = y;

                while (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] == 0) {
                    newX += dx[i];
                    newY += dy[i];
                }

                newX -= dx[i];
                newY -= dy[i];

                if (vis[newX][newY] == false) {
                    vis[newX][newY] = true;
                    todo.push({newX, newY});
                }
            }

        }
        return false;
    }
};