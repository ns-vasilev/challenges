/*

Clone Graph

Problem Description

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

Note: The test cases are generated in the following format (use the following format to use See Expected Output option):

First integer N is the number of nodes.

Then, N intgers follow denoting the label (or hash) of the N nodes.

Then, N2 integers following denoting the adjacency matrix of a graph, where Adj[i][j] = 1 denotes presence of an undirected edge between the ith and jth node, O otherwise.

Problem Constraints
1 <= Number of nodes <= 10^5

*/

std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;

UndirectedGraphNode* dfs(UndirectedGraphNode* node) {
    if (node == nullptr) { return nullptr; }
    if (m.count(node) > 0) { return m[node]; }
    
    UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
    m[node] = new_node;
    
    for (auto it: node->neighbors) {
        UndirectedGraphNode* curr = dfs(it);
        new_node->neighbors.push_back(curr);
    }
    
    return new_node;
}

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) { return nullptr; }
    
    if (node->neighbors.size() == 0) {
        return new UndirectedGraphNode(node->label);
    }
    
    return dfs(node);
}
