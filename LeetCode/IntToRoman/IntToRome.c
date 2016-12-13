// I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000

char* arr[4][10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                    "", "M", "MM", "MMM", ""  , "" , ""  , ""   , ""    , ""  ,
};

void strcat_before(char* dest, char* src)
{
    int lens = strlen(src);
    int lend = strlen(dest);
    
    for (int i = lend - 1; i >= 0; --i)
    {
        dest[i + lens] = dest[i];
    }
    
    for (int i = 0; i < lens; ++i)
    {
        dest[i] = src[i];
    }
}

char* intToRoman(int num) {
    int idx = 0;
    char* res = (char*)calloc(32, sizeof(char));
    
    if (num >= 4000) return "";
    
    while (num != 0)
    {
        int cur = num % 10;
        
        strcat_before(res, arr[idx][cur]);
        
        ++idx;
        num = num / 10;
    }
    
    return res;
}