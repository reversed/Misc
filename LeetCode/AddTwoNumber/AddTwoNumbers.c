struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int hasCarry = 0;
    
    struct ListNode* res = NULL;
    struct ListNode* cur = NULL;
    
    while (l1 != NULL && l2 != NULL)
    {
        if (cur == NULL)
        {
            res = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = res;
        }
        else
        {
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
        }
        cur->val = (l1->val + l2->val + hasCarry) % 10;
        cur->next = NULL;
        hasCarry = (l1->val + l2->val + hasCarry) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        if (cur == NULL)
        {
            res = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = res;
        }
        else
        {
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
        }
        cur->val = (l1->val + hasCarry) % 10;
        cur->next = NULL;
        hasCarry = (l1->val + hasCarry) / 10;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        if (res == NULL)
        {
            res = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = res;
        }
        else
        {
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
        }
        cur->val = (l2->val + hasCarry) % 10;
        cur->next = NULL;
        hasCarry = (l2->val + hasCarry) / 10;
        l2 = l2->next;
    }
    if (hasCarry)
    {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = hasCarry;
        cur->next = NULL;
    }
    
    return res;
}