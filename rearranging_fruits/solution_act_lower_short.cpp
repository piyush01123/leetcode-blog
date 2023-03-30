class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        unordered_map<int,int> H;
        for (int cost: basket1) H[cost]++;
        for (int cost: basket2) H[cost]--;
        vector<int> diffCosts;
        for (auto &[k,v]: H)
        {
            if (v%2==1) return -1;
            for (int i=0; i<abs(v)/2; i++) diffCosts.push_back(k);
        }
        int minCost1 = *min_element(basket1.begin(), basket1.end());
        int minCost2 = *min_element(basket2.begin(), basket2.end());
        int minCost = min(minCost1, minCost2);
        sort(diffCosts.begin(), diffCosts.end());
        long long res = 0;
        for (int i=0; i<diffCosts.size()/2; i++)
            res += min(diffCosts[i], 2*minCost);
        return res;
    }
};