/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *n1, *n2, *n3;
    
    if (head == NULL) return NULL;
    else n1 = head;
    
    if (head->next == NULL) return head;
    else n2 = head->next;
    
    n3 = swapPairs(n2->next);
    n2->next = n1;
    n1->next = n3;
    return n2;
}
