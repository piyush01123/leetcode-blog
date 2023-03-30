class Solution {
public:
    int rob_v1(vector<int> money)
    {
        int n=money.size();
        if (n==1) return money[0];
        vector<int> dp(n,0);
        dp[0] = money[0]; dp[1] = max(money[0], money[1]);
        for (int i=2; i<n; i++) dp[i] = max(dp[i-2]+money[i], dp[i-1]);
        return dp[n-1];
    }
    
    int rob_v2(vector<int>  money)
    {
        int n=money.size();
        if (n==1) return money[0];
        int a=money[0], b=max(money[0], money[1]), b_old;
        for (int i=2; i<n; i++)
        {
            b_old = b;
            b = max(a+money[i], b);
            a = b_old;
        }
        return b;
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 10000;
        vector<int> points(maxNum, 0);
        for (int n: nums) points[n-1]+=n;
        return rob_v1(points);
    }
};