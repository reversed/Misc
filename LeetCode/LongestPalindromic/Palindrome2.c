bool arr[1000][1000];

char* longestPalindrome(char* s) {
    int len = strlen(s);
    memset(arr, 0, sizeof(arr));
    int max = 1, maxs = 0;
    char* res;
    
    if (len == 0) return "";
    
    for (int i = 0; i < len; ++i)
    {
        arr[i][i] = true;
    }
    for (int i = 0; i < len - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            arr[i][i + 1] = true;
            max = 2;
            maxs = i;
        }
    }
    
    // process
    for (int indent = 1; indent < len; ++indent)
    {
        for (int st = 0; st < len - indent - 1; ++st)
        {
            if (s[st] == s[st + indent + 1] && arr[st + 1][st + indent] == true)
            {
                arr[st][st + indent + 1] = true;
                if (indent + 2 > max)
                {
                    max = indent + 2;
                    maxs = st;
                }
            }
        }
    }
    
    res = (char*)calloc((max + 1), sizeof(char));
    for (int i = 0; i < max; ++i)
    {
        res[i] = s[maxs + i];
    }
    return res;
}