class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        for (int i=1; i<=nums.size(); i++) if (!numSet.count(i)) return i;
        return 1+nums.size();
    }
};