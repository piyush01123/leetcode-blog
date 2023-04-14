class Solution {
    public int minimizeArrayValue(int[] nums) 
    {
        Long res = 0L, sum = 0L;
        for (int i=0; i<nums.length; i++)
        {
            sum += nums[i];
            res = Math.max(res, (sum+i)/(i+1));
        }
        return res.intValue();
    }
}