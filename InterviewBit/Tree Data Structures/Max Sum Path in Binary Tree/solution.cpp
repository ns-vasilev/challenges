/*

Max Sum Path in Binary Tree

Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Problem Constraints

1 <= Number of Nodes <= 7e4

-1000 <= Value of Node in T <= 1000

*/

int res = INT_MIN;

int sum(TreeNode *root) {
    if (root == nullptr) { return 0; }
    
    int l = std::max(sum(root->left), 0);
    int r = std::max(sum(root->right), 0);

    res = std::max(res, root->val + l + r);

    return std::max(0, root->val + std::max(l, r));
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
int Solution::maxPathSum(TreeNode* A) {
    res = INT_MIN;

    sum(A);
    return res;
}
