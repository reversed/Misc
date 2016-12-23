/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* start = head;
    struct ListNode* end = head;
    struct ListNode* tmp;
    
    for (int i = 0; i < n - 1; ++i)
    {
        end = end->next;
    }
    
    struct ListNode* pre = NULL;
    while (end->next != NULL)
    {
        pre = start;
        start = start->next;
        end = end->next;
    }
    
    if (pre == NULL)
    {
        tmp = start;
        start = start->next;
        free(tmp);
        return start;
    }
    else
    {
        tmp = start;
        pre->next = start->next;
        free(tmp);
        return head;
    }
}

