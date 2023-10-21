class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long> dp(n);
        for (int i=n-1; i>=0; i--)
        {
            int points = questions[i][0], skips = questions[i][1];
            long long a = (i+skips+1<n)?dp[i+skips+1]:0;
            long long b = (i+1<n)?dp[i+1]:0;
            dp[i] = max(a+points, b);
        }
        return dp[0];
    }
};