/*

Right view of Binary tree

Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.

Problem Constraints
1 <= Number of nodes in binary tree <= 10^5
0 <= node values <= 10^9 

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    std::vector<int> res;

    if (A == nullptr) { return res; }

    std::queue<TreeNode*> q;
    
    q.push(A);
    
    while (!q.empty()) {
        TreeNode *current = nullptr;
        int size = q.size();
        
        while (size--) {
            current = q.front();
            q.pop();
            
            if (current->left) {
                q.push(current->left);
            }
            
            if (current->right) {
                q.push(current->right);
            }
        }
        
        if (current) { res.push_back(current->val); }
    }

    return res;
}
