/*

Maximum level sum

Problem Description

Given a Binary Tree denoted by root node A having integer value on nodes. You need to find maximum sum level in it.

Problem Constraints
- 1 <= number of nodes <= 10^5
- 1 <= value on nodes <= 10^5

Input Format
First and only argument is a root node of Binary Tree A.

Output Format
Return an integer denoting the maximum sum level in the tree.

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
int Solution::solve(TreeNode* A) {
    std::queue<TreeNode*> q;
    int max_sum = 0;

    q.push(A);
    
    while (!q.empty()) {
        int size = q.size();
        int level_max_sum = 0;
        
        for (int i = 0; i < size; ++i) {
            TreeNode *n = q.front();
            q.pop();
            
            level_max_sum += n->val;
            
            if (n->left != nullptr) {
                q.push(n->left);
            }
            
            if (n->right != nullptr) {
                q.push(n->right);
            }
        }
        
        max_sum = std::max(max_sum, level_max_sum);
    }
    
    return max_sum;
}
