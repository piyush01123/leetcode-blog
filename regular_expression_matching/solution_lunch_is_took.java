class Solution {
    int[][] dp;
    public boolean isMatch(String s, String p) 
    {
        int slen=s.length(), plen=p.length();
        if (plen==0) return (slen==0);
        if (dp==null)
        {
            dp = new int[slen+1][plen+1];
            for (int[] row: dp) Arrays.fill(row, 2);
        }
        if (dp[slen][plen]!=2) return (dp[slen][plen]==1);
        boolean fm = (slen>0) && (s.charAt(0)==p.charAt(0) || p.charAt(0)=='.');
        boolean ret;
        if (plen>=2 && p.charAt(1)=='*') 
            ret = (fm && isMatch(s.substring(1), p)) || isMatch(s, p.substring(2));
        else
            ret = fm && isMatch(s.substring(1), p.substring(1));
        dp[slen][plen] = (ret)?1:0;
        return ret;
    }
};