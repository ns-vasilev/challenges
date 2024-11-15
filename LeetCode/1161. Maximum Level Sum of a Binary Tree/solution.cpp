/*

1161. Maximum Level Sum of a Binary Tree

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int level = 0;

    void bfs(TreeNode *root) {
        int curr_level = 0;
        int max_sum = INT_MIN;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int curr = 0;

            curr_level += 1;

            for (int i = 0; i < size; ++i) {
                TreeNode* u = q.front();
                q.pop();

                curr += u->val;

                if (u->left) {
                    q.push(u->left);
                }

                if (u->right) {
                    q.push(u->right);
                }
            }

            if (max_sum < curr) {
                max_sum = curr;
                level = curr_level;
            }
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        bfs(root);
        return level;
    }
};