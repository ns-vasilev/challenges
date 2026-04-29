/*

ZigZag Level Order Traversal BT

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    std::queue<TreeNode *> q;
    std::vector<std::vector<int>> result;
    
    if (A == nullptr) {
        return result;
    }
    
    bool is_left_to_right = true;
    
    q.push(A);
    
    while (!q.empty()) {
        int size = q.size();
        
        std::vector<int> level(size);
        
        for (int i = 0; i < size; ++i) {
            TreeNode *u = q.front();
            q.pop();
            
            if (u->left != nullptr) {
                q.push(u->left);
            }
            
            if (u->right != nullptr) {
                q.push(u->right);
            }
            
            int index = is_left_to_right ? i : size - i - 1;
            
            level[index] = u->val;
        }

        is_left_to_right = !is_left_to_right;
        
        result.push_back(level);
    }
    
    return result;
}
