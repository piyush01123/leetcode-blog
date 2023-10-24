class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) 
    {
        if (nums2.length>nums1.length) return maxUncrossedLines(nums2,nums1);
        int[] dpPrev = new int[nums2.length+1];
        int[] dpCurr = new int[nums2.length+1];        
        for (int i=1; i<=nums1.length; i++)
        {
            for (int j=1; j<=nums2.length; j++)
            {
                if (nums1[i-1]==nums2[j-1]) dpCurr[j] = 1 + dpPrev[j-1];
                else dpCurr[j] = Math.max(dpPrev[j], dpCurr[j-1]);
            }
            dpPrev = dpCurr.clone();
        }
        return dpCurr[nums2.length];
    }
}