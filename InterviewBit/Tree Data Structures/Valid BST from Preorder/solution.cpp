/*

Valid BST from Preorder

Problem Description

You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.

Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.

Problem Constraints
1 <= A[i] <= 10^6
1 <= |A| <= 10^5

Input Format
First and only argument is an integer array A denoting the pre-order traversal.

Output Format

Return an integer:
- 0 : Impossible preorder traversal of a BST
- 1 : Possible preorder traversal of a BST

*/

int Solution::solve(vector<int> &A) {
    std::stack<int> s;
    
    int low_bound = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        if (low_bound >= A[i]) {
            return 0;
        }
        
        while (!s.empty() && s.top() < A[i]) {
            low_bound = s.top();
            s.pop();
        }
        
        if (!s.empty() && s.top() == A[i]) {
            return 0;
        }
        
        s.push(A[i]);
    }
    
    return 1;
}
