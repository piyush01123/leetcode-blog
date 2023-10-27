class Solution {
    public long mostPoints(int[][] questions) {
        long dp[] = new long[1000000];
        Arrays.fill(dp,0);
        for(int i=questions.length-1; i>=0; i--)
        {
            int points = questions[i][0], skips = questions[i][1];
            dp[i] = Math.max((long)points+dp[i+skips+1], dp[i+1]);
        }
        return dp[0];
    }
}