class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int mask = 0, res = 0;
        for (int i=31; i>=0; i--)
        {
            mask |= (1<<i);
            unordered_set<int> available;
            for (int num: nums) available.insert(num & mask);

            int resPossible = res | (1<<i);
            for (int n: available) if (available.count(n ^ resPossible))
            {
                res = resPossible;
                break;
            }
        }
        return res;
    }
};