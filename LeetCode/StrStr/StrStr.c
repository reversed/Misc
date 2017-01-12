int strStr(char* haystack, char* needle) {
    int lenh = strlen(haystack);
    int lenn = strlen(needle);
    
    if (*needle == '\0') return 0;
    
    for (int i = 0; i < lenh; ++i)
    {
        if (lenh - i < lenn)
        {
            break;
        }
        
        char *h = haystack + i;
        char *n = needle;
        while (*h != '\0' && *h == *n)
        {
            ++h;
            ++n;
        }
        
        // Found
        if (*n == '\0') return i;
    }
    return -1;
}
