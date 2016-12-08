bool matchstar(char c, char* s, char* p);
bool matchhere(char* s, char* p);

bool matchstar(char c, char* s, char* p)
{
    do
    {
        if (matchhere(s, p))
            return true;
    } while (*s != '\0' && (*s++ == c || c == '.'));
    return false;
}

bool matchhere(char* s, char* p)
{
    if (p[0] == '\0' && s[0] == '\0')
    {
        return true;
    }
    else if (p[0] == '\0' && s[0] != '\0')
    {
        return false;
    }
    else if (p[1] == '*')
    {
        return matchstar(p[0], s, p+2);
    }
    else if ((p[0] == '.' && s[0] != '\0') || p[0] == s[0])
    {
        return matchhere(s+1, p+1);
    }
    return false;
}

bool isMatch(char* s, char* p) {
    return matchhere(s, p);
}
