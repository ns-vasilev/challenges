/*

Burn a Tree

Problem Description

Given a binary tree denoted by root node A and a leaf node B from this tree.

It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.

Problem Constraints
- 2 <= number of nodes <= 10^5
- 1 <= node value, B <= 10^5
- node value will be distinct

Input Format
- First argument is a root node of the binary tree, A.
- Second argument is an integer B denoting the node value of leaf node.

Output Format
- Return an integer denoting the minimum time required to burn the complete binary tree.

*/

void map_parents(TreeNode* root, TreeNode *& target, int B, std::unordered_map<TreeNode*, TreeNode*> &parents) {
    if (root == nullptr) { return; }
    if (root->val == B) { target = root; }
    
    if (root->left) {
        parents[root->left] = root;
        map_parents(root->left, target, B, parents);
    }
    
    if (root->right) {
        parents[root->right] = root;
        map_parents(root->right, target, B, parents);
    }
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A, int B) {
    std::unordered_map<TreeNode*, TreeNode*> map;
    std::unordered_set<TreeNode*> visited;
    TreeNode *target_node = nullptr;
    
    map_parents(A, target_node, B, map);
    
    if (!target_node) {
        return 0;
    }

    std::queue<TreeNode*> q;
    q.push(target_node);
    visited.insert(target_node);
    
    int res = 0;
    
    while (!q.empty()) {
        int size = q.size();
        bool is_burnt_this_step = false;

        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();

            if (node->left && visited.find(node->left) == visited.end()) {
                is_burnt_this_step = true;
                q.push(node->left);
                visited.insert(node->left);
            }

            if (node->right && visited.find(node->right) == visited.end()) {
                is_burnt_this_step = true;
                q.push(node->right);
                visited.insert(node->right);
            }
            
            if (map.count(node) && visited.find(map[node]) == visited.end()) {
                is_burnt_this_step = true;
                q.push(map[node]);
                visited.insert(map[node]);
            }
        }

        if (is_burnt_this_step) {
            res++;
        }
    }
    
    return res;
}