class Solution 
{
    int mod = 1000000007;
    int[] memo;
    int util(int len, int zr, int on)
    {
        if (len<0) return 0;
        if (memo[len]!=-1) return memo[len];
        if (len==0) return memo[len]=1;
        return memo[len] = (util(len-zr,zr,on) + util(len-on,zr,on))%mod;
    }
    public int countGoodStrings(int low, int high, int zero, int one) 
    {
        int res=0;
        memo = new int[high+1];
        Arrays.fill(memo,-1);
        for(int i=low; i<=high; i++){res+=util(i, zero, one); res%=mod;}
        return res;
    }
}