/*

Remove Nth Node from List End

Given a linked list A, remove the B-th node from the end of the list and return its head.

For example, Given linked list: 1->2->3->4->5, and B = 2. After removing the second node from the end, the linked list becomes 1->2->3->5.

NOTE: If B is greater than the size of the list, remove the first node of the list.

NOTE: Try doing it using constant additional space.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    
    ListNode *f1 = dummy;
    ListNode *f2 = dummy;
    
    for (int i = 0; i < B + 1; ++i) {
        if (f1->next == nullptr) {
            return A->next;
        }
        f1 = f1->next;
    }
    
    while (f1 != nullptr) {
        f1 = f1->next;
        f2 = f2->next;
    }
    
    ListNode *del = f2->next;
    f2->next = f2->next->next;
    
    delete del;
    
    return dummy->next;
}
