public class Solution {
    public String countAndSay(int n) {
        if (n <= 1)
        {
            return new String("1");
        }
        
        String res = new String();
        String str = countAndSay(n - 1);
        char pre = str.charAt(0);
        int count = 1;
        for (int i = 1; i < str.length(); ++i)
        {
            char c = str.charAt(i);
            if (c == pre)
            {
                ++count;
                continue;
            }

            res = res + String.valueOf(count) + String.valueOf(pre);
            pre = c;
            count = 1;
        }
        res = res + String.valueOf(count) + String.valueOf(pre);

        return res;
    }
}

