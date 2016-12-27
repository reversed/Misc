/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
     struct ListNode** l1a = &l1;
     struct ListNode** ha = l1a;
     
     while ((*l1a) != NULL && l2 != NULL)
     {
        struct ListNode* cur = *l1a;
        
        if (cur->val < l2->val)
        {
            // move l1 forward
            l1a = &((*l1a)->next);
        }
        else
        {
            // insert l2 first node to l1
            // and move l2 one step forward
            struct ListNode* tmp = *l1a;
            *l1a = l2;
            l2 = l2->next;
            (*l1a)->next = tmp;
        }
     }
     
     if (l2 != NULL)
     {
         // append l2 to the end;
         *l1a = l2;
     }
     
     return *ha;
}
