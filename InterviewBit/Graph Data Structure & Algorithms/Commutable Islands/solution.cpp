/*

Commutable Islands

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

*/

class dsu {
private:
    std::vector<int> rank;
    std::vector<int> parent;
public:
    dsu(int n ) {
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int a, int b) {
        int set_a = find(a);
        int set_b = find(b);
        
        if (set_a != set_b) {
            if (rank[set_a] < rank[set_b]) {
                std::swap(set_a, set_b);
            } 
            
            parent[set_b] = set_a;
            
            if (rank[set_a] == rank[set_b]) {
                rank[set_a]++;
            }
            
            return true;
        }
        
        return false;
    }
};

struct Edge {
    int a, b, w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int Solution::solve(int A, vector<vector<int>> &B) {
    std::vector<Edge> edges;

    for (int i = 0; i < B.size(); ++i) {
        edges.push_back({ B[i][0] - 1, B[i][1] - 1, B[i][2] });
    }
    
    std::sort(edges.begin(), edges.end());
    
    dsu d(A);
    
    int res = 0;
    
    for (auto e: edges) {
        if (d.unite(e.a, e.b)) {
            res += e.w;
        }
    }
    
    return res;
}
