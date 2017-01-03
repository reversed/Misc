public class Solution {
    private List<List<Integer>> worker(ArrayList<Integer> arr, int n)
    {
        List<List<Integer>> res = new ArrayList<>();
        
        if (n == 0)
        {
            List<Integer> tmp = new ArrayList<>();
            tmp.add(arr.get(0));
            res.add(tmp);
            return res;
        }
        else if (n < 0)
        {
            List<Integer> tmp = new ArrayList<>();
            res.add(tmp);
            return res;   
        }
        
        int cur = arr.get(n);
        List<List<Integer>> tmp = worker(arr, n-1);
        for (int i = 0; i <= n; ++i)
        {
            for (List<Integer> l : tmp)
            {
                List<Integer> nl = new ArrayList<>(l); 
                nl.add(i, cur);
                res.add(nl);
            }
        }
        return res;
    }
    
    public List<List<Integer>> permute(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for (Integer i : nums)
        {
            arr.add(i);
        }
        return worker(arr, nums.length - 1);
    }
}
