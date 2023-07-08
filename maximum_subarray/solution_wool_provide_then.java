class Solution {
    public int maxSubArray(int[] nums) 
    {
        int meh=0, res=Integer.MIN_VALUE;
        for (int n: nums)
        {
            meh = Math.max(meh, 0) + n;
            res = Math.max(res, meh);
        }
        return res;
    }
}