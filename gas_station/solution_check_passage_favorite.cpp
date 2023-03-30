class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total = 0, n=gas.size(), tank=0, index=0;
        for (int i=0; i<n; i++)
        {
            total += gas[i]-cost[i];
            tank += gas[i]-cost[i];
            if (tank<0)
            {
                tank = 0;
                index = i+1;
            }
        }
        if (total<0) return -1;
        return index;
    }
};