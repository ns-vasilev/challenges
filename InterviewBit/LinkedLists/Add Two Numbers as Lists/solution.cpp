/*

Add Two Numbers as Lists

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head = new ListNode(0);
    ListNode *p = A;
    ListNode *q = B;
    ListNode *res = head;
    
    int c = 0;
    
    while (p || q) {
        int p_val = (p == nullptr) ? 0 : p->val;
        int q_val = (q == nullptr) ? 0 : q->val;
        
        int sum = p_val + q_val + c;
        
        c = sum / 10;
        
        res->next = new ListNode(sum % 10);
        res = res->next;
        
        if (p != nullptr) {
            p = p->next;
        }
        
        if (q != nullptr) {
            q = q->next;
        }
    }
    
    if (c > 0) {
        res->next = new ListNode(c);
    }
    
    return head->next;
}
