int reverse(int x) {
    int res = 0;
    int t = x > 0 ? x : (-1 * x);
    int r = t % 10;
    int q = t / 10;
    while (q != 0 || r != 0)
    {                         
        if (res > (INT_MAX - r) / 10)
        {
            // overflow, res = 0
            res = 0;
            break;
        }
        res = res * 10 + r;
        r = q % 10;
        q = q / 10;
    }
    
    return x > 0 ? res : (-1 * res);
}