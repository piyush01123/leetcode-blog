class Solution {
    int res = Integer.MAX_VALUE;
    void distribute(int[] cookies, int[] distribution, int cur, int k)
    {
        if(cur==cookies.length) 
        {
            int maxVal=Integer.MIN_VALUE;
            for(int val: distribution) maxVal = Math.max(maxVal, val);
            res = Math.min(res, maxVal);
            return;
        }
        for(int i=0; i<k; i++)
        {
            distribution[i] += cookies[cur];
            distribute(cookies, distribution, cur+1, k);
            distribution[i] -= cookies[cur];
        }
    }
    public int distributeCookies(int[] cookies, int k) 
    {
        int[] distribution = new int[cookies.length];
        distribute(cookies, distribution, 0, k);
        return res;
    }
}