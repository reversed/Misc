bool isPalindrome(int x) {
    int up = 1, dn = 1;
    int upv = 1, dnv = 1;
    
    if (x < 0) return false;
    
    while (x / (up * 10) != 0)
    {
        up = up * 10;
        if (INT_MAX / 10 < up)
        {
            break;
        }
    }
    
    while (up > dn)
    {
        upv = (x / up) % 10;
        dnv = (x / dn) % 10;
        if (upv != dnv) return false;
        
        up = up / 10;
        dn = dn * 10;
    }
    return true;
}