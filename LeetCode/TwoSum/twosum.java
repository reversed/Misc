public int[] twoSum(int[] sums, int target)
{
    Map<Integer, Integer> map = nwe HashMap<>();
    for (int i = 0; i < nums.length; ++i)
    {
        map.put(nums[i], i);
    }
    for (int i = 0; i < nums.length; ++i)
    {
        int complement = target - nums[i];
        if (map.containsKey(complement) && map.get(complement) != i)
        {
            return new int[] {i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}

public int[] twoSum2(int[] nums, int target)
{
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; ++i)
    {
        int complement = target - nums[i];
        if (map.containsKey(complement))
        {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}







