/*

1483. Kth Ancestor of a Tree Node

You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.

*/

class TreeAncestor {
private:
    int LOG;
    std::vector<std::vector<int>> up;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = std::ceil(std::log2(n));
        up.assign(n, std::vector<int>(LOG + 1, -1));

        for (int v = 0; v < n; ++v) {
            up[v][0] = parent[v];
        }

        for (int i = 1; i <= LOG; ++i) {
            for (int v = 0; v < n; ++v) {
                if (up[v][i - 1] != -1) {
                     up[v][i] = up[up[v][i - 1]][i - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= LOG; ++i) {
            if (k & (1 << i)) {
                node = up[node][i];

                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */