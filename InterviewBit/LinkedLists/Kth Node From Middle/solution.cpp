/*

Kth Node From Middle

Given a linked list A of length N and an integer B.

You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

If no such element exists, then return -1.

NOTE:

Position of middle node is: (N/2)+1, where N is the total number of nodes in the list.

Problem Constraints
1 <= N <= 10^5
1<= Value in Each Link List Node <= 10^3
1 <= B <= 10^5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    if (A == nullptr || A->next == nullptr) {
        return -1;
    }

    int len = 0;
    
    ListNode *tmp = A;
    
    while (tmp != nullptr) {
        tmp = tmp->next;
        len++;
    }
    
    int mid = len / 2;
    
    if (B > mid) {
        return -1;
    }
    
    int index = mid - B;
    
    tmp = A;
    
    for (int i = 0; i < index; ++i) {
        tmp = tmp->next;
    }
    
    return tmp->val;
}
