// I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
int arr[256] = {0};

int romanToInt(char* s) {
    int res = 0;
    int idx = 0;
    int cur = 0;
    
    arr['I'] = 1; arr['V'] = 5; arr['X'] = 10; arr['L'] = 50; arr['C'] = 100; arr['D'] = 500; arr['M'] = 1000;
    
    if (s == NULL) return 0;
    cur = arr[s[0]];
    
    while (s[idx] != 0)
    {
        int tmp = 0;
        while (s[idx] != 0 && cur == arr[s[idx]])
        {
            tmp += arr[s[idx]];
            ++idx;
        }
        if (s[idx] != 0 && arr[s[idx]] < cur)
        {
            cur = arr[s[idx]];
        }
        if (s[idx] != 0 && arr[s[idx]] > cur)
        {
            tmp = arr[s[idx]] - tmp;
            ++idx;
        }
        res += tmp;
    }
    return res;
}