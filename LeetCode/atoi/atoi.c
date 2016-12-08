// 1. minus sign / plus sign
// 2. illegal alpha like alphabet
// 3. overflow string number "99999999999999999999"
// 4. "-2147483648"
// 5. handle leading space

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int myAtoi(char* str) {
    int len = strlen(str);
    int res = 0;
    int st = 0;
    int sign = 1;
    
    // handle space
    while (str[st] == ' ') ++st;

    if (str[st] == '-')
    {
        sign = -1;
        ++st;
    }
    else if (str[st] == '+')
    {
        ++st;
    }

    
    for (int i = st; i < len; ++i)
    {
        if (!isNumber(str[i]))
        {
            break;
        }
        int n = str[i] - '0';
        
        if (sign == 1)
        {
            if ((INT_MAX - n) / 10 < res)
            {
                res = INT_MAX;
                break;
            }
            res = res * 10 + n;
        }
        else
        {
            if ((INT_MIN + n) / 10 > res)
            {
                res = INT_MIN;
                break;
            }
            res = res * 10 - n;
        }
    }
    
    return res;
}