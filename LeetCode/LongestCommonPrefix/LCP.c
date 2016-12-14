char* longestCommonPrefix(char** strs, int strsSize) {
    int len = 0;
    char* res = NULL;
    
    if (strsSize == 0) return "";
    
    len = strlen(strs[0]);
    res = (char*)calloc(len + 1, sizeof(char));
    strcpy(res, strs[0]);
    
    for (int i = 1; i < strsSize; ++i)
    {
        int idx_res = 0;
        int len_res = strlen(res);
        for (idx_res = 0; idx_res < len_res; ++idx_res)
        {
            if (res[idx_res] != strs[i][idx_res])
            {
                break;
            }
        }
        res[idx_res] = '\0';
    }
    return res;
}