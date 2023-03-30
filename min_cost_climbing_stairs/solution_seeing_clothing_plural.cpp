class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>price(n,0); //price to put foot on index i. 
        // Answer is min(price[n-2],price[n-1])
        price[0]=cost[0]; price[1]=cost[1];
        for (int i=2; i<n; i++) price[i]=min(price[i-2],price[i-1])+cost[i];
        return min(price[n-1], price[n-2]);
    }
};