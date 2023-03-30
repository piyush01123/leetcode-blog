class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int res=1, curr=1, n = nums.length;
        for(int i=1; i<n; i++)
        {
            if (nums[i]>nums[i-1]) curr++;
            else
            {
                if (curr>res) res = curr;
                curr = 1;
            }
        }
        if (curr>res) res=curr;
        return res;
    }
}