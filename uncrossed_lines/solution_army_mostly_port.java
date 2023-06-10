class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) 
    {
        int n1=nums1.length, n2=nums2.length;
        if (n2>n1) return maxUncrossedLines(nums2,nums1);
        int[] dpPrev = new int[n2+1];
        int[] dpCurr = new int[n2+1];        
        for (int i=1; i<=n1; i++)
        {
            for (int j=1; j<=n2; j++)
            {
                if (nums1[i-1]==nums2[j-1]) dpCurr[j] = 1 + dpPrev[j-1];
                else dpCurr[j] = Math.max(dpPrev[j], dpCurr[j-1]);
            }
            dpPrev = dpCurr.clone();
        }
        return dpCurr[n2];
    }
}