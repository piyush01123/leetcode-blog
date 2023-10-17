class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_set<int> numSet;
        int pops = 0;
        while (numSet.size()<k)
        {
            int num = nums.back();
            nums.pop_back();
            if (!numSet.count(num) && num>=1 && num<=k) numSet.insert(num);
            pops++; 
        }
        return pops;
    }
};