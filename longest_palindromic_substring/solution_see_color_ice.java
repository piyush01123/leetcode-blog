class Solution {
    public String longestPalindrome(String s) 
    {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=false;
        String res="";
        for (int len=1; len<=n; len++)
        {
            for (int i=0; i<=n-len; i++)
            {
                int j = i+len-1;
                dp[i][j] = s.charAt(i)==s.charAt(j) && ((len<=2) || dp[i+1][j-1]);
                if (dp[i][j]) res = s.substring(i,j+1);
            }
        }
        return res;        
    }
}