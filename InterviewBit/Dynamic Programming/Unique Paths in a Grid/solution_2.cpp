/*

Unique Paths in a Grid

Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/

int dfs(int r, int c, int n, int m, std::vector<std::vector<int>> &A, std::vector<std::vector<int>> memo) {
    if (r >= n || c >= m || A[r][c] == 1) {
        return 0;
    }
    
    if (r == n - 1 && c == m - 1) {
        return 1;
    }
    
    if (memo[r][c] != -1) {
        return memo[r][c];
    }
    
    memo[r][c] = dfs(r + 1, c, n, m, A, memo) + dfs(r, c + 1, n, m, A, memo);
    
    return memo[r][c];
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    if (A[0][0] == 1 || A[n-1][m-1] == 1) {
        return 0;
    }
    
    std::vector<std::vector<int>> memo(n, std::vector<int>(m, -1));

    return dfs(0, 0, n, m, A, memo);
}
