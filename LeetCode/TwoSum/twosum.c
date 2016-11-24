/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    bool found = false;
    int i, j;
    int* res = (int*)malloc(2 * sizeof(int));
    for (i = 0; i < numsSize; ++i)
    {
        for (j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    res[0] = i;
    res[1] = j;
    return res;
}