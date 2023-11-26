class Solution {
public:
    long long minCost(vector<int>& nums, int x) 
    {
        int n = nums.size();
        vector<int> curCosts(n, INT_MAX);
        long long res = LONG_MAX;
        for (int rot=0; rot<n; rot++)
        {
            for (int i=0; i<n; i++) curCosts[i] = min(curCosts[i], nums[(i+rot)%n]);
            long long sum = 0;
            for(int cost: curCosts) sum += (long long)cost;
            sum += (long long)rot*(long long)x;
            res = min(res, sum);
        }
        return res;
    }
};


/*
cnum = [20,1,15,20,1,15]

20,1,15
1,1,15
1,1,1
*/