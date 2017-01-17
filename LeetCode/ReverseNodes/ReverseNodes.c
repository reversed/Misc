/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* reverseK(struct ListNode* head, int k)
{
    struct ListNode *one, *two, *nxt;

    if (head == NULL || k == 0) return NULL;

    //printf("reverseK head: %d\n", head->val);

    struct ListNode* cur = head;
    int i = 1;
    for (i = 1; i <= k; ++i)
    {
        if (cur != NULL)
        {
            cur = cur->next;
        }
        else
        {
            return NULL;
        }
    }
    one = cur;
    two = head;
    nxt = head->next;
    
    for (int i = 1; i <= k; ++i)
    {
        two->next = one;
        one = two;
        two = nxt;
        if (nxt != NULL) nxt = nxt->next;
    }
    return one;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* nh;
    
    if (head == NULL) return NULL;
    
    nh = reverseK(head, k);
    if (nh == NULL) return head;
    
    //printf("reverseKGroup nh: %d", nh->val);
    
    head->next = reverseKGroup(head->next, k);
    return nh;
}








