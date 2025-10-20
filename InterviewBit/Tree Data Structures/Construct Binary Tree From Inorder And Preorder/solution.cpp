/*

Construct Binary Tree From Inorder And Preorder

Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

*/

TreeNode* build(
    std::vector<int> &pre, int preStart, int preEnd,
    std::vector<int> &in, int inStart, int inEnd,
    std::unordered_map<int,int> &inMap
) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    
    int rootVal = pre[preStart];
    TreeNode* root = new TreeNode(rootVal);
    int inRoot = inMap[rootVal];
    int leftSize = inRoot - inStart;
        
    root->left = build(pre, preStart + 1, preStart + leftSize, in, inStart, inRoot - 1, inMap);
    root->right = build(pre, preStart + leftSize + 1, preEnd, in, inRoot + 1, inEnd, inMap);
        
    return root;
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
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    std::unordered_map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}
