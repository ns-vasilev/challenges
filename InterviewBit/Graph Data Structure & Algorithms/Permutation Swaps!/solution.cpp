/*

Permutation Swaps!

Problem Description

Rishabh has a permutation A of N integers 1, 2, ... N but he doesn't like it. Rishabh wants to get a permutation B.

Also, Rishabh has some M good pairs given in a form of 2D matrix C of size M x 2  where (C[i][0], C[i][1]) denotes that two indexes of the permutation A.

In one operation he can swap Ax and Ay only if (x, y) is a good pair.

You have to tell whether Rishabh can obtain permutation B by performing the above operation any number of times on permutation A.

If the permutation B can be obtained return 1 else return 0.

Problem Constraints:
- 2 <= N <= 10^5
- 1 <= M <= 10^5
- 1 <= A[i], B[i] <= N
- A[i] and B[i] are all distinct.
- 1 <= C[i][0] < C[i][1] <= N

*/

#include <numeric>

class dsu {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    dsu(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        std::iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void union_sets(int x, int y) {
        int a = find(x);
        int b = find(y);
        
        if (a != b) {
            if (rank[a] < rank[b]) {
                std::swap(a, b);
            }
            
            parent[b] = a;
            
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
};

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    if (A == B) return 1;
    
    int N = A.size();

    dsu d(N);
    
    for (int i = 0; i < C.size(); ++i) {
        d.union_sets(C[i][0] - 1, C[i][1] - 1);
    }
    
    map<int, vector<int>> vals_a, vals_b;
    for (int i = 0; i < N; ++i) {
        int root = d.find(i);
        vals_a[root].push_back(A[i]);
        vals_b[root].push_back(B[i]);
    }
    
    for (auto const& [root, values] : vals_a) {
        vector<int> a = values;
        vector<int> b = vals_b[root];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    
        if (a != b) return 0;
    }
    
    return 1;
}
