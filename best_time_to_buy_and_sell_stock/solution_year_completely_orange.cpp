class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), minPrice = INT_MAX, res=INT_MIN;
        for (int p: prices)
        {
            minPrice = min(minPrice, p);
            res = max(res, p-minPrice);
        }
        return res;
    }
};