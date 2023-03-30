class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int i = 1;
        while (i <= nums.size()){
            if (!numSet.count(i)) return i;
            i++;
        }
        return i;
    }
};