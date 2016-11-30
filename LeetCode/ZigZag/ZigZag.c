char* convert(char* s, int numRows) {
    int i;
    int pos, dir;
    int len = strlen(s);
    char* res = (char*)calloc(len + 1, sizeof(char));
    char** rows = (char**)malloc(sizeof(char*) * numRows);
    for (i = 0; i < numRows; ++i)
    {
        rows[i] = (char*)calloc(len + 1, sizeof(char));
    }
    
    i = 0;
    pos = 0;
    dir = 1;
    while (s[i] != 0)
    {
        int rowlen = strlen(rows[pos]);
        rows[pos][rowlen] = s[i];
        
        if (numRows == 1)
        {
            dir = 0;
        }
        else if (dir == 1 && pos + 1 >= numRows)
        {
            dir = -1;
        }
        else if (dir == -1 && pos == 0)
        {
            dir = 1;
        }
        
        pos += dir;
        i += 1;
    }
    
    for (i = 0; i < numRows; ++i)
    {
        strcat(res, rows[i]);
    }
    
    // free
    for (i = 0; i < numRows; ++i)
    {
        free(rows[i]);
    }
    free(rows);
    return res;
}