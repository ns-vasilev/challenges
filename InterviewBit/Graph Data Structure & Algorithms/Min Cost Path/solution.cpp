/*

Min Cost Path

Problem Description

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.

Problem Constraints
- 1 <= A,B <= 10^3
- C[i][j] can be either U,R,L or D.

Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.

Output Format
Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.

*/

int Solution::solve(int A, int B, vector<string> &C) {
    std::vector<std::vector<int>> dist(A, std::vector<int>(B, INT_MAX));
    std::deque<std::pair<int, int>> q;
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    char dir_chars[] = {'R', 'L', 'D', 'U'};
    
    dist[0][0] = 0;
    q.push_front({0, 0});
    
    while (!q.empty()) {
        std::pair<int, int> curr = q.front();
        q.pop_front();
        
        int x = curr.first;
        int y = curr.second; 
        
        if (x == A - 1 && y == B - 1) {
            return dist[x][y];
        }
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < A && ny >= 0 && ny < B) {
                int w = (C[x][y] == dir_chars[i]) ? 0 : 1;
                
                if (dist[x][y] + w < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + w;
                    
                    if (w == 0) {
                        q.push_front({nx, ny});
                    } else {
                        q.push_back({nx, ny});
                    }
                }
            }
        }
    }
    
    return dist[A - 1][B - 1];
}
