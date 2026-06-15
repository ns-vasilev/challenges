/*

Flatten Binary Tree to Linked List

Given a binary tree A, flatten it to a linked list in-place.

The left child of all nodes should be NULL.

Problem Constraints
1 <= size of tree <= 100000

Input Format
First and only argument is the head of tree A.

Output Format
Return the linked-list after flattening.

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
TreeNode* Solution::flatten(TreeNode* A) {
    TreeNode *curr = A;
    
    while (curr != nullptr) {
        if (curr->left != nullptr) {
            TreeNode *prev = curr->left;
            
            while (prev->right != nullptr) {
                prev = prev->right;
            } 
            
            prev->right = curr->right;
            
            curr->right = curr->left;
            curr->left = nullptr;
        }
        
        curr = curr->right;
    }
    
    return A;
}
