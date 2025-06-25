/*

Symmetric Binary Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Problem Constraints

1 <= number of nodes <= 10^5

*/

void inorder(TreeNode *root, std::vector<int> &p) {
    if (root == nullptr) {
        return;
    }
    
    inorder(root->left, p);
    p.push_back(root->val);
    inorder(root->right, p);
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
    std::vector<int> d;
    
    inorder(A, d);
    
    if (d.size() % 2 != 0) {
        for (int i = 0; i < d.size() / 2; ++i) {
            if (d[i] != d[d.size() - i - 1]) {
                return 0;
            }
        }
        return 1;
    }
    
    return 0;
}
