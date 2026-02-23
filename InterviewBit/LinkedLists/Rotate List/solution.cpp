/*

Rotate List

Problem Description

Given a list, rotate the list to the right by k places, where k is non-negative.

Problem Constraints
1 <= B <= 10^9

Input Format
- The first argument is ListNode A, pointing to the head of the list.
- The second argument is an integer B, representing the value of k.

Output Format
- Return the rotated list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (!A || !A->next || B == 0) {
        return A;
    }

    ListNode* tail = A;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    B = B % length;
    if (B == 0)  {
        return A;
    }

    tail->next = A;

    int stepsToNewTail = length - B;
    ListNode* newTail = A;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
