// 1. check stack empty when pop, case '))))'
// 2. check stack empty in the end, case '((()'
// 3. true when the stack is empty in the end.

public class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        Deque<Character> lst = new LinkedList<Character>();
        
        for (int i = 0; i < len; ++i)
        {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[')
            {
                lst.addFirst(c);
            }
            else if (c == ')' || c == '}' || c == ']')
            {
                if (lst.size() == 0) return false;

                char pre = lst.remove();
                if ((pre == '(' && c == ')') || (pre == '{' && c == '}') || (pre == '[' && c == ']'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (lst.size() == 0)
            return true;
        else
            return false;
    }
}
