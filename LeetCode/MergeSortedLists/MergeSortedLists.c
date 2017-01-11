/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct hnode {
    int val;
    struct ListNode *p;
};

void minify(struct hnode *arr, int cur, int end)
{
    int left = cur * 2 + 1;
    int right = cur * 2 + 2;
    int min = cur;
    struct hnode tmp;
    
    if (left <= end && arr[left].val < arr[min].val)
    {
        min = left;
    }
    if (right <= end && arr[right].val < arr[min].val)
    {
        min = right;
    }

    if (min == cur)
    {
        return;
    }

    tmp = arr[min];
    arr[min] = arr[cur];
    arr[cur] = tmp;
    
    minify(arr, min, end);
    return;
}

void create(struct hnode *arr, int end)
{
    for (int i = end / 2; i >= 0; --i)
    {
        minify(arr, i, end);
    }
}

struct ListNode* remov(struct hnode *arr, int end)
{
    if (arr[0].p != NULL)
    {
        struct ListNode *res = (struct ListNode*)malloc(sizeof(struct ListNode));
        res->val = arr[0].val;
        res->next = NULL;

        arr[0].p = arr[0].p->next;
        if (arr[0].p == NULL)
        {
            arr[0].val = INT_MAX;
        }
        else
        {
            arr[0].val = arr[0].p->val;
        }
        minify(arr, 0, end);
        
        return res;
    }
    else
    {
        return NULL;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct hnode *arr = (struct hnode*)malloc(listsSize * sizeof(struct hnode));
    struct ListNode *ln = NULL;
    struct ListNode *res = NULL, *cur = NULL;
    
    for (int i = 0; i < listsSize; ++i)
    {
        if (lists[i] != NULL)
        {
            arr[i].p = lists[i];
            arr[i].val = lists[i]->val;
        }
        else
        {
            arr[i].p = NULL;
            arr[i].val = INT_MAX;
        }
    }
    
    create(arr, listsSize - 1);
    ln = remov(arr, listsSize - 1);
    res = cur = ln;
    while (cur != NULL)
    {
        ln = remov(arr, listsSize - 1);
        cur->next = ln;
        cur = cur->next;
    }

    return res;
}
