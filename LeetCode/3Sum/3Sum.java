public class Solution {
    private List<List<Integer>> twoSum(int[] nums, int low, int high, int target)
    {
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        
        for (int i = low; i <= high; ++i)
        {
            for (int j = i + 1; j <= high; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    List<Integer> lst = new LinkedList<Integer>();
                    
                    lst.add(target * (-1));
                    lst.add(nums[i]);
                    lst.add(nums[j]);
                    Collections.sort(lst);
                    res.remove(lst);
                    res.add(lst);
                }
            }
        }
        return res;
    }
    
    public List<List<Integer>> threeSum(int[] nums)
    {
        int len = nums.length;
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        HashMap<Integer, Boolean> hs = new HashMap<Integer, Boolean>();

        for (int i = 0; i <= len - 3; ++i)
        {
            int low = i + 1;
            int high = len - 1;
            int target = nums[i] * (-1);
            
            if (!hs.containsKey(target)) {
                hs.put(target, true);
                List<List<Integer>> tmp = twoSum(nums, low, high, target);
                res.removeAll(tmp);
                res.addAll(tmp);
            }
        }
        
        return res;
    }
}


