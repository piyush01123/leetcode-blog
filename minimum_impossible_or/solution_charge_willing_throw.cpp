class Solution {
public:
    int minImpossibleOR(vector<int>& nums) 
    {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int cur = 1;
        while (cur<INT_MAX)
        {
            if (!numSet.count(cur)) return cur;
            cur <<= 1;
        }
        return INT_MAX;
    }
};