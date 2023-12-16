class Solution 
{
    boolean util(int candidate, int target)
    {
        if (target<0) return false;
        if (candidate==0) return false;
        boolean a = (candidate==target);
        boolean b = util(candidate/10, target-candidate%10);
        boolean c = util(candidate/100, target-candidate%100);
        boolean d = util(candidate/1000, target-candidate%1000);
        return (a|b|c|d);
    }
    public int punishmentNumber(int n)
    {
        int res=0;
        for (int i=1; i<=n; i++) if (util(i*i, i)) res += i*i;
        return res;
    }
}