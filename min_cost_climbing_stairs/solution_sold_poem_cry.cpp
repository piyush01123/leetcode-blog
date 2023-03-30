class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=cost[0], b=cost[1], b_old;
        for (int i=2; i<cost.size(); i++)
        {
            b_old=b;
            b = min(a,b)+cost[i];
            a = b_old;
        }
        return min(a,b);
    }
};