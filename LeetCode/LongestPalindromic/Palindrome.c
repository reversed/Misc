bool IsPalindrome(char* s, int st, int ed)
{
    while (st <= ed)
    {
        if (s[st] != s[ed]) return false;
        ++st;
        --ed;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int st, ed;
    int len = strlen(s);
    int max = 0;
    int maxi = 0, maxj = 0;
    int idx, idx_res;
    char* res;
    
    if (len == 0) return "";
    
    st = 0;
    ed = len - 1;
    while (st < len)
    {
        int i = 0;
        for (int i = ed; i >= st; --i)
        {
            if (max > i - st + 1) break;

            bool b = IsPalindrome(s, st, i);
            if (b)
            {
                max = i - st + 1;
                maxi = st;
                maxj = i;
                break;
            }
        }
        
        if (max > len - st) break;
        
        ++st;
        ed = len - 1;
    }
    
    res = (char*)calloc(max + 1, sizeof(char));
    idx_res = 0;
    for (idx = maxi; idx <= maxj; ++idx)
    {
        res[idx_res] = s[idx];
        ++idx_res;
    }
    // printf("%d, %d, %d, %s", max, maxi, maxj, res);
    
    return res;
}






