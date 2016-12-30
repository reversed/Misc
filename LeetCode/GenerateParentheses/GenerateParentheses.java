public class Solution {
    private List<String> worker(int cur, int left, int right)
    {
        List<String> res = new LinkedList<String>();
        
        if (right == 0 && left == 0)
        {
            res.add("");
            return res;
        }
        
        if (left > 0)
        {
            // add left paren
            List<String> tmp = worker(cur + 1, left - 1, right);
            for (String s : tmp)
            {
                s = '(' + s;
                res.add(s);
            }
        }
        if (right > 0)
        {
            // add right paren
            if (cur > 0)
            {
                List<String> tmp = worker(cur - 1, left, right - 1);
                for (String s : tmp)
                {
                    s = ')' + s;
                    res.add(s);
                }
            }
        }
        return res;
    }
    
    public List<String> generateParenthesis(int n) {
        return worker(0, n, n);
    }
}
