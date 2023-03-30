class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int S=0, n=gas.size(), tank=0, start=0;
        for (int i=0; i<n; i++) S+=gas[i]-cost[i];
        if (S<0) return -1;
        for (int i=0; i<n; i++)
        {
            tank += gas[i]-cost[i];
            if (tank<0)
            {
                tank=0;
                start=i+1;
            }
        }
        if (tank<0) return -1;
        return start;
    }
};