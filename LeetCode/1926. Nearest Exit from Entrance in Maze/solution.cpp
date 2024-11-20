/*

1926. Nearest Exit from Entrance in Maze

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

*/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        std::queue<std::pair<int, int>> q;

        int n = maze.size();
        int m = maze[0].size();

        std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));

        int res = 0;

        q.push({ entrance[0], entrance[1] });

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                std::pair<int, int> u = q.front();
                q.pop();

                if (u.first == 0 || u.second == 0 || u.first == n - 1 || u.second == m - 1) {
                    if (u.first != entrance[0] || u.second != entrance[1]) {
                        return res;
                    }
                }

                int row = u.first;
                int col = u.second;

                if (row - 1 >= 0 && col >= 0 && row - 1 < n && col < m) {
                    if (maze[row - 1][col] == '.' && !visited[row - 1][col]) {
                        q.push({ row - 1, col });
                        visited[row - 1][col] = 1;
                    }
                }

                if (row >= 0 && col - 1 >= 0 && row < n && col - 1 < m) {
                    if (maze[row][col - 1] == '.' && !visited[row][col - 1]) {
                        q.push({ row, col - 1 });
                        visited[row][col - 1] = 1;
                    }
                }

                if (row + 1 >= 0 && col >= 0 && row + 1 < n && col < m) {
                    if (maze[row + 1][col] == '.' && !visited[row + 1][col]) {
                        q.push({ row + 1, col });
                        visited[row + 1][col] = 1;
                    }
                }

                if (row >= 0 && col + 1 >= 0 && row < n && col + 1 < m) {
                    if (maze[row][col + 1] == '.' && !visited[row][col + 1]) {
                        q.push({ row, col + 1 });
                        visited[row][col + 1] = 1;
                    }
                }
            }

            res += 1;
        }

        return -1;
    }
};