/*

Symmetric Binary Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Problem Constraints

1 <= number of nodes <= 10^5

*/

bool helper(TreeNode *left, TreeNode *right) {
    if (left == nullptr || right == nullptr) {
        return left == right;
    }
    
    if (left->val != right->val) {
        return false;
    }
    
    return helper(left->right, right->left) && helper(left->left, right->right);
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
int Solution::isSymmetric(TreeNode* A) {
    return helper(A->left, A->right);
}
