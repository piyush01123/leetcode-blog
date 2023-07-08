class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long dp[] = new long[n];
        for(int i=n-1; i>=0; i--)
        {
            int points = questions[i][0], skips = questions[i][1];
            long a = (i+skips+1<n)?dp[i+skips+1]:0;
            long b = (i+1<n)?dp[i+1]:0;
            dp[i] = Math.max(a+(long)points, b);
        }
        return dp[0];
    }
}