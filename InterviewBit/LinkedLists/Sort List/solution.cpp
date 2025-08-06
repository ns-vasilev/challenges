/*

Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

*/

ListNode *get_middle(ListNode *A) {
    ListNode *slow = A;
    ListNode *fast = A->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (left && right) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        
        tail = tail->next;
    }
    
    tail->next = left ? left : right;
    
    return dummy->next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) {
    if (A == nullptr || A->next == nullptr) {
        return A;
    }
    
    ListNode* mid_node = get_middle(A);
    
    ListNode* left = A;
    ListNode* right = mid_node->next;
    
    mid_node->next = nullptr;
    
    left = sortList(left);
    right = sortList(right);
    
    return merge(left, right);
}
