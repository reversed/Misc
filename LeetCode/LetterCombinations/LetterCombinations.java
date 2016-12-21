public class Solution {
    String[] arr = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0)
        {
            return new LinkedList<String>();
        }
        return letterCombinations_(digits);
    }
    
    private List<String> letterCombinations_(String digits) {
        List<String> res = new LinkedList<String>();
        if (digits.length() == 0)
        {
            res.add("");
            return res;
        }
        List<String> tmp = letterCombinations_(digits.substring(1, digits.length()));
        
        char c = digits.charAt(0);
        int idx = Integer.parseInt(String.valueOf(c));
        int len = arr[idx].length();
        for (int i = 0; i < len; ++i)
        {
            String newstr = arr[idx].substring(i, i + 1);
            for (String s : tmp)
            {
                s = newstr + s;
                res.add(s);
            }
        }
        return res;
    }
}