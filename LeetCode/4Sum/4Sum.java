public class Solution {
    public List<List<Integer>> threeSum(int[] nums, int start, int end, int target, int pre)
    {
        List<List<Integer>> res = new LinkedList<>();
        
        for (int i = start + 1; i < end - 1; ++i)
        {
            // remove duplicates
            if (i != start + 1 && nums[i - 2] == nums[i - 1]) continue;
            
            int target2 = target - nums[i - 1];
            int lo = i;
            int hi = nums.length - 1;
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == target2)
                {
                    res.add(Arrays.asList(pre, nums[i - 1], nums[lo], nums[hi]));
                    //System.out.println(pre + " " + nums[i - 1] + " " + nums[lo] + " " + nums[hi]);
                    ++lo;
                    while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
                    --hi;
                    while (lo < hi && nums[hi] == nums[hi + 1]) --hi;
                }
                else if (nums[lo] + nums[hi] < target2)
                {
                    ++lo;
                }
                else
                {
                    --hi;
                }
            }
        }
        return res;
    }
    
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new LinkedList<>();
        
        Arrays.sort(nums);
        
        for (int i = 1; i < nums.length - 2; ++i)
        {
            // remove duplicates
            if (i != 1 && nums[i - 2] == nums[i - 1]) continue;
            
            int target2 = target - nums[i - 1];
            int start = i;
            int end = nums.length;
            List<List<Integer>> lst = threeSum(nums, start, end, target2, nums[i - 1]);
            res.addAll(lst);
        }
        return res;
    }
}

