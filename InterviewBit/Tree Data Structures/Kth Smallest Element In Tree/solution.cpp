/*

Kth Smallest Element In Tree

Given a binary search tree, write a function to find the kth smallest element in the tree.
NOTE: You may assume 1 <= k <= Total number of nodes in BST

Input Format
The first argument is the root node of the binary tree.
The second argument B is an integer equal to the value of k.

Output Format
Return the value of the kth smallest node.

*/

std::vector<int> in_order;

void traversal(TreeNode *A) {
    if (A == nullptr) {
         return;
    }
    
    traversal(A->left);
    in_order.push_back(A->val);
    traversal(A->right);
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
int Solution::kthsmallest(TreeNode* A, int B) {
    in_order.clear();
    traversal(A);
    
    return in_order[B - 1];
}
