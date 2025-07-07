/*

Connected Components

Given a graph with A nodes.
The edges in graph are given in a 2D array B.
There is an undirected edge between B[i][0] and B[i][1].
Find the number of connected components in the given graph.

Problem Constraints
1 <= A <= 10^5
1 <= |B| <= 10^5
1 <= B[i][0], B[i][1] <= A

*/

void dfs(std::vector<std::vector<int>> &g, std::vector<bool> &visited, int v) {
    visited[v] = true;
    
    for (auto u: g[v]) {
        if (visited[u] == false) {
            dfs(g, visited, u);
        }
    }
}

int count(std::vector<std::vector<int>> &B, int n) {
    std::vector<std::vector<int>> adj(n);
    
    for (int i = 0; i < B.size(); ++i) {
        adj[B[i][0] - 1].push_back(B[i][1] - 1);
        adj[B[i][1] - 1].push_back(B[i][0] - 1);
    }
    
    std::vector<bool> visited(n, false);
    
    int cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        if (visited[i] == false) {
            cnt++;
            dfs(adj, visited, i);
        }
    }
    
    return cnt;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    return count(B, A);
}
