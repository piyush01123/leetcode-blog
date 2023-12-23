class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int mask = 0, res = 0;
        for (int i=31; i>=0; i--)
        {
            mask |= (1<<i);
            unordered_set<int> prefixes;
            for (int num: nums) prefixes.insert(num & mask);

            int resPossible = res | (1<<i);
            for (int n: prefixes) if (prefixes.count(n ^ resPossible))
            {
                res = resPossible;
                break;
            }
        }
        return res;
    }
};