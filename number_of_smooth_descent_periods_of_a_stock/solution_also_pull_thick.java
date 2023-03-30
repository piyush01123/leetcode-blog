class Solution {
    public long getDescentPeriods(int[] prices) {
        long res = 1;
        int ctr = 1;
        for (int i=1; i<prices.length; i++)
        {
            if (prices[i]==prices[i-1]-1) ctr++;
            else ctr = 1;
            res += ctr;
        }
        return res;
    }
}