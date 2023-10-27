class Solution {
    vector<vector<int>> dp;
public:
    int util(int i, int remain, vector<int>&cost, vector<int>&time)
    {
        if (remain<=0) return 0;
        if (i==cost.size()) return INT_MAX/2;
        if (dp[i][remain] != -1) return dp[i][remain];
        int paint = util(i+1, remain-1-time[i], cost, time) + cost[i];
        int skip  = util(i+1, remain, cost, time);
        return dp[i][remain] = min(paint,skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        dp = vector<vector<int>>(cost.size(),vector<int>(cost.size()+1,-1));
        return util(0, cost.size(), cost, time);
    }
};