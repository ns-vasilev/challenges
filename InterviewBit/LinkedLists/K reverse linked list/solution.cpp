/*

K reverse linked list

Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

*/

ListNode* Solution::reverseList(ListNode* A, int k) {
    if (!A || k == 1) return A;
    
    ListNode dummy(0);
    dummy.next = A;

    ListNode *end = A;
    ListNode *prev_group = &dummy;
    
    while (true) {
        int cnt = 0;
        while (end && cnt < k) {
            end = end->next;
            cnt++;
        }
        if (cnt < k) break;
        
        ListNode *prev = end;
        ListNode *curr = prev_group->next;
        
        for (int i = 0; i < k; ++i) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        ListNode *tmp = prev_group->next;
        prev_group->next = prev;
        prev_group = tmp;
    }
    
    return dummy.next;
}
