class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        vector<long long> dp(1e6, 0);
        for (int i=questions.size()-1; i>=0; i--)
        {
            int points = questions[i][0], skips = questions[i][1];
            dp[i] = max((long long)points + dp[i+skips+1],  dp[i+1]);
        }
        return dp[0];
    }
};