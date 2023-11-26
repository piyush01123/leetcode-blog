class Solution {
public:
    int res = 0;
    int util(int node, vector<int>&cost)
    {
        if(node>=cost.size()) return 0;
        int L = util(2*node+1, cost);
        int R = util(2*node+2, cost);
        res += abs(R-L);
        return cost[node]+max(L,R);
    }
    int minIncrements(int n, vector<int>& cost) 
    {
        util(0, cost);
        return res;
    }
};