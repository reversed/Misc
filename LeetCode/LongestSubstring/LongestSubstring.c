int lengthOfLongestSubstring(char* s)
{
    int arr[256];
    int st = 0, ed = 0;
    int max = 0;

    memset(arr, -1, sizeof(arr));
    while (s[ed] != 0)
    {
        char ch = s[ed];
        if (arr[ch] != -1)
        {
            // repeated found
            if (ed - st > max)
            {
                max = ed - st;
            }
            st = arr[ch] + 1;
            ed = st;
            memset(arr, -1, sizeof(arr));
        }
        else
        {
            // save the index
            arr[ch] = ed;
            ++ed;
        }
    }
    
    // check the end of the string
    if (ed - st > max)
    {
        max = ed - st;
    }
    return max;
}
