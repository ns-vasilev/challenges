/*

Palindrome List

Given a singly linked list A, determine if it's a palindrome. Return 1 or 0, denoting if it's a palindrome or not, respectively.

Problem Constraints
1 <= |A| <= 10^5 

Input Format
The first and the only argument of input contains a pointer to the head of the given linked list. 

Output Format
 Return 0, if the linked list is not a palindrome. 
 Return 1, if the linked list is a palindrome. 
 
*/

ListNode* reverse(ListNode *n) {
    if (n == nullptr || n->next == nullptr) {
        return n;
    }
    
    ListNode *r = reverse(n->next);
    
    n->next->next = n;
    n->next = nullptr;
    
    return r;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if (A == nullptr || A->next == nullptr) return 1;
    
    ListNode *slow = A, *fast = A;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* half = reverse(slow->next);
    
    ListNode* p1 = A;
    ListNode* p2 = half;
    bool is_palin = true;
    
    while (p2 != nullptr) {
        if (p1->val != p2->val) {
            is_palin = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return is_palin ? 1 : 0;
}
