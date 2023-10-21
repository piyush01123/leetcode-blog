class Solution {
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int> dp(n+1, n+2);
        dp[0] = 0;
        for (int i=0; i<=n; i++)
        {
            int left = max(0, i-ranges[i]);
            for (int j=max(0,i-ranges[i]+1); j<=min(n,i+ranges[i]); j++)
                dp[j] = min(dp[j], dp[left]+1);
            // for(int k:dp)cout<<k<<',';cout<<endl;
        }
        return (dp[n]<n+2) ? dp[n] : -1;
    }
};