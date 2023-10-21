class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int> numSet;
        for (int num: nums)
        {
            if (numSet.count(num)) return num;
            numSet.insert(num);
        }
        return -1;
    }
};