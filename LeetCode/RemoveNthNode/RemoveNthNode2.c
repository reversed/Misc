// Using pointer to pointer to do the remove without maintaining a prev.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode** t1 = &head, *t2 = head, *tmp = NULL;

    for (int i = 1; i < n; ++i)
    {
        t2 = t2->next;
    }
    
    while (t2->next != NULL)
    {
        t1 = &((*t1)->next);
        t2 = t2->next;
    }
    
    tmp = *t1;
    *t1 = (*t1)->next;
    return head;
}

