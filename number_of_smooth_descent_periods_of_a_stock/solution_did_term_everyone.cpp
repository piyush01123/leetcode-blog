class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size(), i = 0;
        long long ctr = 0;
        while (i<n)
        {
            int j = i+1;
            while (j<n && prices[j]==prices[j-1]-1) j++;
            long long c = j-i;
            ctr += c*(c+1)/2;
            i = j;
        }
        return ctr;
    }
};