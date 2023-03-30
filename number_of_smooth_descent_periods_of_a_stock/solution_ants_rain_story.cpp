class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 1;
        int ctr = 1;
        for (int i=1; i<prices.size(); i++)
        {
            if(prices[i]==prices[i-1]-1) ctr++;
            else ctr=1;
            res += ctr;
        }
        return res;
    }
};